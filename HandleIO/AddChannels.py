import os
from CreateListToRun import menu
from AnalysisCommons.Run import INFO, WARNING, DEBUG, ERROR
from AnalysisCommons.Constants import DEFAULT_MJJ_REWEIGHTING
from HandleIO.OutputsMerger import Z_PRIME_MASS_LIST

def copy_root_files_from_to(from_path,to_path):
    # Copy the root files from the from_path to the to_path
    for root_file in os.listdir(from_path):
        if root_file.endswith(".root"):
            output = os.system("cp "+from_path+root_file+" "+to_path)
            if output:
                WARNING.log("Error copying file %s to %s" % (root_file, to_path))
            else:
                INFO.log("Copied file %s to %s" % (root_file, to_path))

def validate_input(dir_name):
        message = "Invalid directory name. Please enter a valid directory name. It must be something of the form A/B or A."
        user_input = dir_name.split('/')

        if len(user_input) != 2 and len(user_input) != 1:
            ERROR.log(message)
            exit(1)
        if '' in user_input:
            ERROR.log(message)
            exit(1)

    
def create_if_not_exists(directory):
    # Recursively create the directory structure if it does not exist
    path = ''
    INFO.log("Creating directory structure from %s" % os.getcwd())
    for  part in directory.split('/'):
        if part == '':
            continue
        else:
            path = os.path.join(path, part)
            try:
                os.mkdir(path)
                INFO.log("Creating directory %s " % path)
            except FileExistsError:
                WARNING.log("Directory %s already exists!" % path)
                pass
            except Exception as e:
                ERROR.log("Error creating directory: ",directory)
                exit(1)

def add_potential_rw_samples(pairs_dict,list_of_samples, rw_tag = None, channel=None):

    for sample in list_of_samples:

        # For Zll samples, we need to create two pairs: one for Zee and one for Zmumu
        sample1 = None
        sample2 = None
        if channel is None: # Not for the tau channels
            sample1 = sample
            sample2 = sample
        elif channel == "Zll":
            sample1 = sample.replace("Zll","Zee")
            sample2 = sample.replace("Zll","Zmumu")

        # Create the pairs in the dictionary
        if rw_tag is not None:
            pairs_dict[sample+"_"+rw_tag] = (sample1+"_"+rw_tag, sample2+"_"+rw_tag)
        else:
            pairs_dict[sample] = (sample1, sample2)



def main(menu_option):
    # Change to the directory where the files are
    if not os.path.exists("../VBFAnalysisPlots/"):
        ERROR.log("VBFAnalysisPlots/ directory not found. Create this OR run this script from HandleIO.")
        exit(1)
    os.chdir("../VBFAnalysisPlots/")

    if menu_option==1: # Merge TauMu and EleTau

        Zp_samples = ["Zprime_%d" % mass for mass in Z_PRIME_MASS_LIST]
        Zp_tuples = [(i,i) for i in Zp_samples]
        hadd_dictionary = {}
        # Fill with all the relevant pairings
        hadd_dictionary["Data"] = ("Data","Data")
        hadd_dictionary["MC"] = ("MC","MC")
        hadd_dictionary["Signal_Sherpa"] = ("Signal_Sherpa","Signal_Sherpa")
        hadd_dictionary["Signal_PoPy"] = ("Signal_PoPy","Signal_PoPy")
        hadd_dictionary["Signal_truth_Sherpa"] = ("Signal_truth_Sherpa","Signal_truth_Sherpa")
        hadd_dictionary["Signal_truth_PoPy"] = ("Signal_truth_PoPy","Signal_truth_PoPy")
        hadd_dictionary["Signal_truth_MG"] = ("Signal_truth_MG","Signal_truth_MG")
        hadd_dictionary["singletop"] = ("singletop","singletop")
        hadd_dictionary["ttbar"] = ("ttbar","ttbar")
        hadd_dictionary["VV"] = ("VV","VV")
        hadd_dictionary["Wjets"] = ("Wjets","Wjets")
        hadd_dictionary["Higgs"] = ("Higgs","Higgs")
        hadd_dictionary["Higgs_truth_EWK"] = ("Higgs_truth_EWK","Higgs_truth_EWK")
        hadd_dictionary["Zjets"] = ("Zjets","Zjets")
        hadd_dictionary["W_EWK_Sherpa"] = ("W_EWK_Sherpa","W_EWK_Sherpa")
        hadd_dictionary["W_EWK_PoPy"] = ("W_EWK_PoPy","W_EWK_PoPy")
        hadd_dictionary["VV_EWK"] = ("VV_EWK","VV_EWK")
        for Zp_sample in Zp_samples:
            hadd_dictionary[Zp_sample] = (Zp_sample,Zp_sample)
        potential_rw_samples = ["Ztautau_Sherpa","Ztautau_MG","Ztautau_SherpaNLO","Ztautau_MGNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples+["Ztautau_PoPy"]) # Add not RW samples
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, rw_tag=DEFAULT_MJJ_REWEIGHTING)

        # Ask the name of the directory where files are stored
        dir_name = input("Enter the name of the directory where the files will be stored: ")
        validate_input(dir_name)

        # Create the output directory if it does not exist
        ztt_path="TauTau/TauhadTaulep/" + dir_name + "/"
        create_if_not_exists(ztt_path)
        
        # Define the input paths
        zte_path="EleTau/"  + dir_name + "/"
        create_if_not_exists(zte_path)
        ztm_path="TauMu/" + dir_name + "/"
        create_if_not_exists(ztm_path)

        # Copy the root files from the channels to the output directory
        copy_root_files_from_to("../EleTau/MC/out/",zte_path)
        copy_root_files_from_to("../TauMu/MC/out/",ztm_path)

        # Do the merging
        for result_sample, sample_pair in hadd_dictionary.items():
            INFO.log("Merging %s.root from %s.root and %s.root" % (result_sample, sample_pair[0], sample_pair[1]))
            status = os.system("hadd -v1 -f %s.root %s.root %s.root" % (ztt_path+result_sample, zte_path+sample_pair[0], ztm_path+sample_pair[1]))
            if status:
                ERROR.log("Error merging these samples!")
            else:
                INFO.log("Sucess!!")

    elif menu_option==2: # Merge TauLep and MuEle (We assume TauLep is alredy in the right directory)

        hadd_dictionary = {}
        # Fill with all the relevant pairings
        hadd_dictionary["Data"] = ("Data","Data")
        hadd_dictionary["MC"] = ("MC","MC")
        hadd_dictionary["Signal_Sherpa"] = ("Signal_Sherpa","Signal_Sherpa")
        hadd_dictionary["Signal_PoPy"] = ("Signal_PoPy","Signal_PoPy")
        hadd_dictionary["Signal_truth_Sherpa"] = ("Signal_truth_Sherpa","Signal_truth_Sherpa")
        hadd_dictionary["Signal_truth_PoPy"] = ("Signal_truth_PoPy","Signal_truth_PoPy")
        hadd_dictionary["Signal_truth_MG"] = ("Signal_truth_MG","Signal_truth_MG")
        hadd_dictionary["singletop"] = ("singletop","singletop")
        hadd_dictionary["ttbar"] = ("ttbar","ttbar")
        hadd_dictionary["VV"] = ("VV","VV")
        hadd_dictionary["Wjets"] = ("Wjets","Wjets")
        hadd_dictionary["Higgs"] = ("Higgs","Higgs")
        hadd_dictionary["Higgs_truth_EWK"] = ("Higgs_truth_EWK","Higgs_truth_EWK")
        hadd_dictionary["Zjets"] = ("Zjets","Zjets")
        hadd_dictionary["W_EWK_Sherpa"] = ("W_EWK_Sherpa","W_EWK_Sherpa")
        hadd_dictionary["W_EWK_PoPy"] = ("W_EWK_PoPy","W_EWK_PoPy")
        hadd_dictionary["VV_EWK"] = ("VV_EWK","VV_EWK")
        potential_rw_samples = ["Ztautau_Sherpa","Ztautau_MG","Ztautau_SherpaNLO","Ztautau_MGNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples+["Ztautau_PoPy"]) # Add not RW samples
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, rw_tag=DEFAULT_MJJ_REWEIGHTING)

        # Ask the name of the directory where files are stored
        dir_name = input("Enter the name of the directory where the files will be stored: ")
        validate_input(dir_name)

        # First the final directory
        ztt_path = "TauTau/" + dir_name + "/"
        create_if_not_exists(ztt_path)
        
        # Then the input directories
        # HadLep need to be already in the correct path
        zthtl_path="TauTau/TauhadTaulep/" + dir_name + "/"
        if not os.path.exists(zthtl_path):
            ERROR.log("Directory %s does not exist. Please run the HadLep channel addition first." % zthtl_path)
            exit(1)

        # Now the MuEle directory
        zemu_path="MuEle/" + dir_name + "/"
        create_if_not_exists(zemu_path)
        copy_root_files_from_to("../MuEle/MC/out/",zemu_path)

        # Do the merging
        for result_sample, sample_pair in hadd_dictionary.items():
            INFO.log("Merging %s.root from %s.root and %s.root" % (result_sample, sample_pair[0], sample_pair[1]))
            status = os.system("hadd -v1 -f %s.root %s.root %s.root" % (ztt_path+result_sample, zthtl_path+sample_pair[0], zemu_path+sample_pair[1]))
            if status:
                ERROR.log("Error merging these samples!")
            else:
                INFO.log("Sucess!!")

    elif menu_option==3: # Merge MuMu and Zee
        hadd_dictionary = {} # Zee in first position, MuMu in second position
        # Fill with all the relevant pairings
        hadd_dictionary["Data"] = ("Data","Data")
        hadd_dictionary["Signal_Sherpa"] = ("Signal_Sherpa","Signal_Sherpa")
        hadd_dictionary["Signal_PoPy"] = ("Signal_PoPy","Signal_PoPy")
        hadd_dictionary["Signal_old"] = ("Signal_old","Signal_old")
        hadd_dictionary["singletop"] = ("singletop","singletop")
        hadd_dictionary["ttbar"] = ("ttbar","ttbar")
        hadd_dictionary["VV"] = ("VV","VV")
        hadd_dictionary["Wjets"] = ("Wjets","Wjets")
        hadd_dictionary["Zjets"] = ("Zmumu","Zee")
        hadd_dictionary["Ztautau"] = ("Ztautau_PoPy","Ztautau_PoPy")
        hadd_dictionary["W_EWK_Sherpa"] = ("W_EWK_Sherpa","W_EWK_Sherpa")
        hadd_dictionary["W_EWK_PoPy"] = ("W_EWK_PoPy","W_EWK_PoPy")
        hadd_dictionary["VV_EWK"] = ("VV_EWK","VV_EWK")
        potential_rw_samples = ["Zll_Sherpa","Zll_MG","Zll_SherpaNLO","Zll_MGNLO","Zll_PoPy"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, channel="Zll")
        potential_rw_samples = ["Zll_Sherpa","Zll_MG","Zll_SherpaNLO","Zll_MGNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, rw_tag=DEFAULT_MJJ_REWEIGHTING, channel="Zll")
        # Now the alternative cases...
        # 1. Exponential re-weighting
        potential_rw_samples = ["Zll_Sherpa","Zll_MG","Zll_SherpaNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, rw_tag="RWExponentialClosure", channel="Zll")
        # 2. ParabolicCutoff without closure
        potential_rw_samples = ["Zll_Sherpa","Zll_MG","Zll_SherpaNLO","Zll_MGNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, rw_tag="RWParabolicCutoff", channel="Zll")
        # 3. More cases if needed go here...

        # Ask the name of the directory where files are stored
        dir_name = input("Enter the name of the directory where the files will be stored: ")
        validate_input(dir_name)

        # First the final directory
        zll_path = os.path.join("Zll", dir_name)
        create_if_not_exists(zll_path)

        # Define the input paths
        # Check if the files come from production or are already in the correct path
        files_already_in_path = menu("Are the Zee and MuMu files already in the correct path?",["Yes","No"]) == 1
        if not files_already_in_path:
            INFO.log('Enter the path to the Zee samples (relative to the current directory):')
            source_zee_path = input().strip()
            INFO.log('Enter the path to the MuMu samples (relative to the current directory):')
            source_mumu_path = input().strip()
        else:
            source_zee_path = os.path.join("Zee", dir_name)
            source_mumu_path = os.path.join("MuMu", dir_name)
        # Check the paths were set correctly
        if not os.path.exists(source_zee_path):
            ERROR.log("The path %s does not exist. Please check the path and try again." % source_zee_path)
            exit(1)
        if not os.path.exists(source_mumu_path):
            ERROR.log("The path %s does not exist. Please check the path and try again." % source_mumu_path)
            exit(1)

        # Copy the files to the correct directory if needed (depends on the previous question)
        if not files_already_in_path:
            INFO.log("Copying the files to the correct directory...")
            zee_path= os.path.join("Zee", dir_name)
            create_if_not_exists(zee_path)
            zmm_path= os.path.join("MuMu", dir_name)
            create_if_not_exists(zmm_path)
            
            copy_root_files_from_to(source_zee_path, zee_path) # Relative to the current directory
            copy_root_files_from_to(source_mumu_path, zmm_path)
        else:
            zee_path = source_zee_path
            zmm_path = source_mumu_path

        # Do the merging
        for result_sample, sample_pair in hadd_dictionary.items():
            INFO.log("Merging %s.root from %s.root and %s.root" % (result_sample, sample_pair[0], sample_pair[1]))
            status = os.system("hadd -v1 -f %s.root %s.root %s.root" % (os.path.join(zll_path, result_sample), os.path.join(zee_path, sample_pair[0]), os.path.join(zmm_path, sample_pair[1])))
            if status:
                ERROR.log("Error merging these samples!")
            else:
                INFO.log("Sucess!!")

    else:
        ERROR.log("Invalid option selected. Please choose a valid option.")
        exit(1)


if __name__ == "__main__":
    option = menu("Which channels do you want to merge?",["TauMu + EleTau","TauLep + MuEle (TauLep need to be already in the correct path)","Zee + MuMu"])
    main(option)
    