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
    if key in realList:
        lumStr = "1"
    else:
        # calculate luminosity weight
        lumWeight = (totRealLum * 1000 * infos[key]["xsec"] * infos[key]["fil_eff"] * infos[key]["kfac"])/infos[key]["sumw"]
        lumStr = "%.5E" % (lumWeight)
    DEBUG.log("Luminosity weight = "+lumStr)
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
    
def DrawC(filename,lumStr,z_sample,key_pop,tree,region, dirs):
    """
    Function to load in the C++ code and run it for a given data set
    """

    # search through several directories to find where the input file is located
    for path in dirs:
        if filename in os.listdir(path):
            correctPath = path
            break

    # reset environment and get path to file
    r.gROOT.Reset()
    fullPath = correctPath + filename

    # load in CLoop.C
    r.gSystem.Load("backend/CLoop_C")

    # load in tree from file
    r.gROOT.ProcessLine('TFile* f = new TFile("%s")' % (fullPath))
    r.gROOT.ProcessLine("TTree * minTree = new TTree")
    r.gROOT.ProcessLine('f->GetObject("%s", minTree)' % (tree))

    # create new instance of CLoop and loop over events
    r.gROOT.ProcessLine('CLoop* t = new CLoop(minTree, "%s", "%s")' % (key_pop, region))
    r.gROOT.ProcessLine('t->Loop(%s, %s, "%s")' % (lumStr, z_sample, key_pop+tree))
    r.gROOT.ProcessLine("f->Close("R")")

def createParser():
    # Create parser
    parser = argparse.ArgumentParser(description="Run VBF Analysis!")

    # Add positional arguments
    parser.add_argument("sample", help="The name of the sample from the ones on the metadata. It can also be a file in which case the code will check that the path exists and will do parallel processing according to the optional --j parameter.", type=str)
    parser.add_argument("remote", help="Is the code running remotely? (yes/no)", type=str, choices=["yes", "no"])
    parser.add_argument("tree", help="Tree to run over. Usually NOMINAL.", type=str,)
    parser.add_argument("region", help="Region to run over. Should contain OS or SS in the name.", type=str)
    parser.add_argument("--j", help="Number of jobs to run in parallel. Default is 1.", type=int, default=1)

    # Parse arguments
    args = parser.parse_args()

    # Check a couple of things...
    if args.region.find("OS") == -1 and args.region.find("SS") == -1:
        ERROR.log("Region should contain OS or SS in the name.")
        exit(1)

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

def RunAnalysis(analysis_function, dataCombos):
    # create parser
    parser = createParser()

    # check if the user wants to run from a set of samples defined in a text file.
    running_from_txt = parser.sample.endswith(".txt")
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
    r.gROOT.ProcessLine(".L backend/CLoop.C+")
    INFO.log("C++ code compiled successfully.")

    # iterate over chains from user input
    if running_from_txt:
        with Pool(processes=parser.j) as pool:
            pool.starmap(analysis_function, [(sample, remote_mode, parser) for sample in chains])
    else:
        for sample in chains:
            INFO.log("Running analysis for: " + sample)
            analysis_function(sample, remote_mode, parser)

if __name__ == "__main__":
    print("This script is not meant to be run directly.")