import sys
import ROOT as r
import os
import sys
import argparse
from multiprocessing import Pool

# Define  colours for the output
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Logger:
    # Static variable
    LOGLEVEL = 4
    def __init__(self,level, colour):
        self.m_level = level
        self.m_colour = colour
        self.s_LOG_LEVELS = {"ERROR":1,"WARNING":2, "INFO":3, "DEBUG":4}
    def log(self,message, variable = ""):
        if self.s_LOG_LEVELS[self.m_level] <= Logger.LOGLEVEL:
            message = self.m_colour+self.m_level+': '+bcolors.ENDC+message
            print(message, variable)
    def setLogLevel(level):
        if level > 4 or level < 1:
            raise ValueError("Log level must be between 1 and 4.")
        Logger.LOGLEVEL = level

INFO = Logger("INFO",bcolors.OKGREEN)
WARNING = Logger("WARNING",bcolors.WARNING)
ERROR = Logger("ERROR",bcolors.FAIL)
DEBUG = Logger("DEBUG",bcolors.OKBLUE)

def getInput(dataCombo):
    """
    Function to validate the input from the user.
    Returns an array of keys to analyse.
    """

    # get list of decay chains from user
    userInput = sys.argv[1] # get input
    chain = []
    # Check if the input is a chain:
    try:
        chain = dataCombo[userInput]
        DEBUG.log("Key is a chain.")
        return chain
    except KeyError:
        DEBUG.log("Key is not a chain, trying to analyse it as a single file.")
        comboName = userInput.split("_")
        # Drop the last element since this should be just a file indicator
        comboName = "_".join(comboName[:-1])
        try :
            chain = dataCombo[comboName]
            for i in dataCombo[comboName]:
                if i == userInput:
                    return [userInput]
            ERROR.log("Key: "+userInput+" is not a single file of combo: "+comboName)
            exit(1)
        except KeyError:
            ERROR.log("Key is not a single file either.")
            exit(1)

def luminosity(key):
    """
    Function to get the luminosity for a given data set.
    """
    if "2018" in key:
        return 58.4501
    elif "2017" in key:
        return 43.5873
    else :
        return 36.2369
    
def getEventWeight(key,realList,infos,totRealLum):
    # Modification needed for systematics
    if "_sys" in key or "_thsys" in key:
        key = key+"_NOMINAL"
        DEBUG.log("Key modified for systematics...")

    if key in realList:
        lumStr = "1"
    else:
        # calculate luminosity weight
        lumWeight = (totRealLum * 1000 * infos[key]["xsec"] * infos[key]["fil_eff"] * infos[key]["kfac"])/infos[key]["sumw"]
        lumStr = "%.5E" % (lumWeight)
    DEBUG.log("Luminosity weight = "+lumStr)
    return lumStr

def getEventWeightForSys(key, infos, totRealLum):
    # calculate luminosity weight
    lumWeight = (totRealLum * 1000 * infos[key]["xsec"] * infos[key]["fil_eff"] * infos[key]["kfac"])/infos[key]["sumw"]
    lumStr = "%.5E" % (lumWeight)
    INFO.log("Luminosity weight for systematics = "+lumStr)
    return lumStr
    
def getZllSampleKey(key):
    """
    Function to know the type of Z boson process.
    """
    z_sample=0
    if ("Zee" in key) or ("Zmumu" in key) or ("Ztautau" in key):
        z_sample=1 # Powheg
        if "sherpa" in key or "Sherpa" in key:
            z_sample=2
            if "NLO" in key:
                z_sample=4
        if "MG" in key:
            z_sample=3
            if "NLO" in key:
                z_sample=5
        if "VBF" in key:
            z_sample=0
    if z_sample!=0:
        INFO.log("This sample CAN be reweighted.")
    else:
        INFO.log("This sample CANNOT be reweighted.")

    return z_sample

def isRunningRemote(Remote):
    """
    Function to see if the code is executed in remote mode.
    """
    if Remote == "yes":
        remote_mode = True
        DEBUG.log("Remote mode enabled.")
    elif Remote == "no":
        remote_mode = False
        DEBUG.log("Remote mode disabled.")
    else:
        ERROR.log("Remote mode not recognised.")
        exit(1)
    return remote_mode

def show_list_of_not_found_systematics(list_of_expected_systematics, output_file):
    for expected_sys in list_of_expected_systematics:
        found_sys = [k.GetName() for k in output_file.GetListOfKeys()]
        good = False
        for hist_name in found_sys:
            if expected_sys.histogram_name in hist_name:
                good = True
                break
        if not good:
            ERROR.log("Expected systematic histogram %s not found in output file %s." % (expected_sys.histogram_name, output_file.GetName()))
    
def DrawC(filename,lumStr,z_sample,key_pop,tree,region, dirs, CLI_args, logLevel = 3, sum_of_weight_metadata = None, luminosity=1):
    """
    Function to load in the C++ code and run it for a given data set
    """

    # search through several directories to find where the input file is located
    correctPath = None
    for path in dirs:
        if filename in os.listdir(path):
            correctPath = path
            break
    if correctPath is None:
        ERROR.log("File %s not found in any of the specified directories:" % filename)
        for path in dirs:
            ERROR.log(" - " + path)
        exit(1)

    # reset environment and get path to file
    fullPath = correctPath + filename
    DEBUG.log("Full path to file: " + fullPath)

    # For the nominal analysis do this ...
    do_sys = CLI_args.sys
    if not do_sys:
        # load in CLoop.C
        r.gSystem.Load("backend/CLoop_C")

        # load in tree from file
        r.gROOT.ProcessLine('TFile* f = new TFile("%s")' % (fullPath))
        r.gROOT.ProcessLine("TTree * minTree = new TTree")
        r.gROOT.ProcessLine('f->GetObject("%s", minTree)' % (tree))

        # create new instance of CLoop and loop over events
        r.gROOT.ProcessLine('CLoop* t = new CLoop(minTree, "%s", "%s")' % (key_pop, region))
        r.gROOT.ProcessLine('t->Loop(%s, %s, "%s", %d)' % (lumStr, z_sample, key_pop+tree, logLevel))
        r.gROOT.ProcessLine("f->Close("R")")
    else:
        # Figure out the relevant systematics
        from .Systematics import LIST_OF_SYSTEMATICS, filter_systematics_by_channel, filter_systematics_by_type
        LIST_OF_SYSTEMATICS = filter_systematics_by_channel(LIST_OF_SYSTEMATICS, CLI_args.sys_channel)
        LIST_OF_SYSTEMATICS = filter_systematics_by_type(LIST_OF_SYSTEMATICS, CLI_args.sys_type.split(","))

        # State variables for the systematic loop
        number_of_systematics = len(LIST_OF_SYSTEMATICS)
        number_of_sf_systematics = sum(1 for s in LIST_OF_SYSTEMATICS if s.type == "sf")
        sys_counter = 0
        sf_systematics_done = False
        sys_tree_name = "NOMINAL"
        sys_histogram_postfix = "NOMINAL"
        systematic_identifier = ""
        sys_lumStr = lumStr
        if sum_of_weight_metadata is None:
            ERROR.log("Sum of weights metadata is required for systematics.")
            exit(1)
        if luminosity == 1:
            ERROR.log("Luminosity is 1, which is not expected for systematics.")
            exit(1)

        # Loop over systematics
        INFO.log("Running the analysis for %d systematic variations." % number_of_systematics)
        for systematic in LIST_OF_SYSTEMATICS:
            # SF systematics logic
            if systematic.type == "nominal":
                sys_tree_name = "NOMINAL"
                sys_histogram_postfix = "NOMINAL"
                systematic_identifier = ""
                sys_lumStr = lumStr
                sys_counter += 1
            elif systematic.type == "sf":
                sys_tree_name = "NOMINAL"
                sys_histogram_postfix = "NOMINAL"
                systematic_identifier = ""
                sys_lumStr = lumStr
                if sf_systematics_done:
                    DEBUG.log("SF systematics already done, skipping %s" % systematic.identifier)
                    continue
                else:
                    sf_systematics_done = True
                    sys_counter += number_of_sf_systematics
                    DEBUG.log("Doing all SF systematics together, counting %d systematics." % number_of_sf_systematics)
            elif systematic.type == "kinematic":
                sys_tree_name = systematic.identifier
                sys_histogram_postfix = systematic.histogram_name
                systematic_identifier = systematic.identifier
                sys_lumStr = lumStr
                sys_counter += 1
            elif systematic.type == "theory":
                sys_tree_name = "NOMINAL"
                sys_histogram_postfix = systematic.histogram_name
                systematic_identifier = systematic.identifier
                sys_counter += 1
                # Only in this case we need to modify the lumiStr
                sys_key = "%s_%s" % (key_pop, systematic.identifier)
                if not ('pdf_ztt_weight' in systematic.identifier):
                    sys_key = key_pop + systematic.identifier.replace('theory_weights_', '_')
                sys_lumStr = str(getEventWeightForSys(sys_key, sum_of_weight_metadata, luminosity))
                DEBUG.log("Original lumStr: %s, new lumStr for theory systematic: %s" % (lumStr, sys_lumStr))
            else:
                ERROR.log("Systematic type %s not recognised." % systematic.type)
                exit(1)
            
            INFO.log("Running systematic %d/%d: %s" % (sys_counter, number_of_systematics, systematic.identifier if systematic.type != "sf" else "SF variations"))

            # load in CLoopSYS.C
            r.gSystem.Load("backend/CLoopSYS_C")

            # load in tree from file
            r.gROOT.ProcessLine('TFile* f = new TFile("%s")' % (fullPath))
            r.gROOT.ProcessLine("TTree * minTree = new TTree")
            r.gROOT.ProcessLine('f->GetObject("%s", minTree)' % (sys_tree_name))

            # create new instance of CLoopSYS and loop over events
            r.gROOT.ProcessLine('CLoopSYS* t = new CLoopSYS(minTree, "%s", "%s", "%s", "%s")' % (region, systematic.type, sys_histogram_postfix, systematic_identifier))
            r.gROOT.ProcessLine('t->Loop(%s, %s, "%s", %d)' % (sys_lumStr, z_sample, key_pop+tree, logLevel))
            r.gROOT.ProcessLine("f->Close("R")")

            # Clean for the next iteration
            r.gROOT.Reset()

        # Check that the number of histograms you expect are created in each file.
        expected_number_of_histograms = number_of_systematics # Count the NOMINAL
        output_file_name = key_pop + tree + ".root"
        output_file = r.TFile(output_file_name, "READ")
        actual_number_of_histograms = len(output_file.GetListOfKeys())
        # Inform the user the results
        if actual_number_of_histograms != expected_number_of_histograms:
            ERROR.log("Number of histograms in output file %s is %d, but expected %d." % (output_file_name, actual_number_of_histograms, expected_number_of_histograms))
            show_list_of_not_found_systematics(LIST_OF_SYSTEMATICS, output_file)
            exit(1)
        else:
            INFO.log("Number of histograms in output file %s is correct: %d." % (output_file_name, actual_number_of_histograms))


# Function to move the output file to the correct directory and track any failed samples.
def MoveOutput(output_name, tree_name, remote, output_dict, cli_path=None):

    output_path = None

    if cli_path is None and not remote:  # If running locally, we assume the output will go to the current directory under out/
        output_path = "out/"
    elif (cli_path is None and remote): # Look for the output directory in the dictionary
        username = os.environ['USER']
        output_paths = output_dict[username]
        if len(output_paths) == 0:
            ERROR.log("No output paths found for this machine. Neither they were specified by the CLI.")
            exit(1)
        if len(output_paths) == 1:
            output_path = output_paths[0]
        else:
            INFO.log("Multiple output paths found. Finding the first one that exists in this machine.")
            for path in output_paths:
                if os.path.exists(path):
                    output_path = path
                    INFO.log("Using output path: " + output_path)
                    break
            if output_path is None:
                ERROR.log("No output path found that exists in this machine.")
                exit(1)
    elif cli_path is not None: # Use the path specified by the CLI
        output_path = cli_path

    if output_path is None:
        ERROR.log("Output path is None. Cannot move output file.")
        exit(1)

    # We assume the output will folder is already created. For local jobs it is created when launching the analysis.
    # For remote, it is created by the submission script.
    # The creator function is CreateOutputsDir().
    cmd = 'mv %s %s/%s/%s' % (output_name, output_path, tree_name, output_name)
    INFO.log("Moving output with command: " + cmd)
    output = os.system(cmd)
    if (output!=0):
        cmd = 'echo %s %s >> %s/%s/Failed.txt' % (output_name.replace(tree_name, '').replace('.root',''), tree_name, output_path, tree_name)
        WARNING.log('Job for %s sample failed. Creating log with command: %s' % (output_name, cmd))
        os.system(cmd)

def CreateOutputsDir(output_path, tree_name):
    # We create the output directory if needed.
    if output_path == None: # No path was passed, so use the default one
        output_path = "out"
        
    cmd = 'mkdir -p %s/%s' % (output_path, tree_name)
    DEBUG.log("Creating output directory with command: " + cmd)
    output = os.system(cmd)
    if output != 0:
        ERROR.log("Failed to create output directory with command: " + cmd)
        exit(1)

def createParser():
    # Create parser
    parser = argparse.ArgumentParser(description="Run VBF Analysis!")

    # Add positional arguments
    parser.add_argument("sample", help="The name of the sample from the ones on the metadata. It can also be a file in which case the code will check that the path exists and will do parallel processing according to the optional --j parameter.", type=str)
    parser.add_argument("remote", help="Is the code running remotely? (yes/no)", type=str, choices=["yes", "no"])
    parser.add_argument("tree", help="Tree to run over. Usually NOMINAL.", type=str,)
    parser.add_argument("region", help="Region to run over. Should contain OS or SS in the name.", type=str)
    parser.add_argument("--j", help="Number of jobs to run in parallel. Default is 1.", type=int, default=1)
    parser.add_argument("--clean", help="Clean the output directory before running the analysis. Default is False.", action='store_true')
    parser.add_argument("--output", help="Output directory for the analysis results. Default is out/<tree>/", type=str)
    parser.add_argument("--loglevel", help="Set the log level. Default is INFO.", type=int, choices=[1, 2, 3, 4], default=3)
    parser.add_argument("--sys", help="If set, the code will run the systematic variations. Default is False.", action='store_true')
    parser.add_argument("--sys-channel", help="When --sys is set, this has to be set to select the associated systematics variations for the channel. Default is None and will raise an error if --sys is set.", type=str, choices=["Zee", "Zmm", "Zem", "Ztm","Zte"], default=None)
    parser.add_argument("--sys-type", help="Comma separated list of types of systematics to run. By default only experimental ones (sf and kinematic) are run. If you want to run theory systematics too, set this to 'all'.", type=str, default="sf,kinematic")

    # Parse arguments
    args = parser.parse_args()

    # Check a couple of things...
    if args.region.find("OS") == -1 and args.region.find("SS") == -1:
        ERROR.log("Region should contain OS or SS in the name.")
        exit(1)

    if args.sys and args.sys_channel is None:
        ERROR.log("When --sys is set, --sys-channel has to be set too.")
        exit(1)

    type_sys_to_run = args.sys_type.split(",")
    valid_types_sys_to_run = ["sf", "kinematic", "theory"]
    for t in type_sys_to_run:
        if t not in valid_types_sys_to_run and t != "all":
            ERROR.log("Type of systematic %s not recognised. Valid types are: %s." % (t, ", ".join(valid_types_sys_to_run)))
            exit(1)
    if 'sf' in type_sys_to_run and 'kinematic' in type_sys_to_run and 'theory' in type_sys_to_run:
        ERROR.log("You are trying to run all types of systematics. Since theory ones are in different files this need to be done separately.")
        exit(1)
    # Always add the NOMINAL
    args.sys_type = args.sys_type + ",nominal"

    return args

def get_combos_from_txt_file(file_path):
    """
    Function to get the combos from a text file.
    The text file should contain one combo per line.
    """
    combos = []
    try:
        with open(file_path, 'r') as f:
            for line in f:
                line = line.strip()
                if line:  # Check if the line is not empty
                    combos.append(line)
    except FileNotFoundError:
        ERROR.log(f"File {file_path} not found.")
        exit(1)
    
    return combos


def AnalysisFunction(key, remote, CLI_args, dataSets, realList, infos, dirs, output_dict, log_level = 3):
    # get the Z boson process
    z_sample = getZllSampleKey(key)

    # get filename
    filename = dataSets[key]

    totRealLum = luminosity(key)
    INFO.log("Luminosity for this year: "+str(totRealLum))

    # get luminosity weight if data is MC
    lumStr = getEventWeight(key,realList,infos,totRealLum)

    # launch the analysis script for the given data set
    tree_name = CLI_args.tree
    region = CLI_args.region

    DrawC(filename,lumStr,z_sample,key,tree_name, region, dirs, CLI_args, log_level, sum_of_weight_metadata=infos, luminosity=totRealLum)

    # Move the output to a different directory
    output_name = key+tree_name+".root"
    MoveOutput(output_name, tree_name, remote, output_dict = output_dict, cli_path=CLI_args.output)


def RunAnalysis(dataCombos, dataSets, realList, infos, dirs, output_dict):
    # create parser and print job configuration
    parser = createParser()
    INFO.log("Log level: %d" % parser.loglevel)

    # Set the log level
    log_level = parser.loglevel
    Logger.setLogLevel(log_level)
    # If running in multi-core mode, or from a file we set the log level to ERROR
    running_from_txt = parser.sample.endswith(".txt")
    if parser.j > 1 or running_from_txt:
        Logger.setLogLevel(1)
        log_level = 1

    # More information about the run
    INFO.log("Running analysis with the following configuration:")
    INFO.log("Sample: %s" % parser.sample)
    INFO.log("Remote: %s" % parser.remote)
    INFO.log("Tree: %s" % parser.tree)
    INFO.log("Region: %s" % parser.region)
    INFO.log("Number of cores: %d" % parser.j)
    INFO.log("Output directory: %s" % parser.output)
    INFO.log("Clean: %s" % parser.clean)
    INFO.log("Systematics: %s" % parser.sys)
    INFO.log("Systematics channel: %s" % parser.sys_channel)
    INFO.log("Systematics types: %s" % parser.sys_type)

    # check if the user wants to run from a set of samples defined in a text file.
    if running_from_txt:
        chains = get_combos_from_txt_file(parser.sample)
        
        # check if the user wants multicore processing
        if parser.j == 1:
            WARNING.log("You are running the code in single-core mode. If you want to run in parallel, please use --j parameter.")
        else :
            INFO.log("You are running the code in multi-core mode with %d jobs." % parser.j)
    else:
        # get input from user
        chains = getInput(dataCombos)

    # see if the code is executed in remote mode
    remote_mode = isRunningRemote(parser.remote)

    # Before running, we always compile the C++ code (we assume the code is run from the Channel/MC directory).
    # The C++ code is at the same level in the backend directory.
    INFO.log("Compiling C++ code...")
    try:
        # Remove all previous compiled files
        INFO.log("Removing previously compiled files...")
        output = os.system("rm -f backend/*.so backend/*.d backend/*.pcm backend/*C_ACLiC*")
        if output != 0:
            ERROR.log("Failed to remove previous compiled files.")
            exit(1)
        
        # Compile the C++ code
        if parser.sys:
            INFO.log("Compiling for systematics...")
            r.gROOT.ProcessLine(".L backend/CLoopSYS.C+")
        else:
            INFO.log("Compiling for nominal...")
            r.gROOT.ProcessLine(".L backend/CLoop.C+")
    # Notify the user if the compilation fails
    except Exception as e:
        ERROR.log("Failed to compile C++ code: %s" % str(e))
        exit(1)

    INFO.log("C++ code compiled successfully.")

    # check if the user wants to clean the output directory
    if parser.clean and not remote_mode:
        INFO.log("Cleaning output directory...")
        output_dir = "out/"+parser.tree+"/"
        if os.path.exists(output_dir):
            os.system("rm %s*" % output_dir)
            INFO.log("Output directory cleaned.")
        else:
            ERROR.log("Output directory %s does not exist." % output_dir)
            exit(1)
        
    # Create output directory if necessary (by default it is out/<tree>/)
    if not remote_mode:
        CreateOutputsDir(parser.output, parser.tree)
    else:
        DEBUG.log("Remote mode enabled, output directory should be created by the submission script.")

    # iterate over chains from user input
    if running_from_txt:
        with Pool(processes=parser.j) as pool:
            pool.starmap(AnalysisFunction, [(sample, remote_mode, parser, dataSets, realList, infos, dirs, output_dict, log_level) for sample in chains])
    else:
        for sample in chains:
            INFO.log("Running analysis for: " + sample)
            AnalysisFunction(sample, remote_mode, parser, dataSets, realList, infos, dirs, output_dict, log_level)

if __name__ == "__main__":
    print("This script is not meant to be run directly.")