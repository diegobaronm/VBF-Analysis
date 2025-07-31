import os
from CreateListToRun import menu
from AnalysisCommons.Run import INFO, WARNING, DEBUG, ERROR

def copy_root_files_from_to(from_path,to_path, list_of_potential_rw_samples=[], used_rw_samples=False):
    # Copy the root files from the from_path to the to_path
    for root_file in os.listdir(from_path):
        if root_file.endswith(".root"):
            if 'RW' in root_file:
                ERROR.log("RW files should never be given to this function!")
                exit(1)
            if root_file.strip('.root') in list_of_potential_rw_samples and used_rw_samples:
                os.system("cp "+from_path+root_file+" "+to_path+'/'+root_file.strip('.root')+"RW.root")
            else:
                os.system("cp "+from_path+root_file+" "+to_path)

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

def add_potential_rw_samples(pairs_dict,list_of_samples, used_rw_samples, channel=None):

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
        if used_rw_samples == True:
            pairs_dict[sample+"RW"] = (sample1+"RW", sample2+"RW")
        else:
            pairs_dict[sample] = (sample1, sample2)



def main(menu_option, used_rw_samples):
    # Change to the directory where the files are
    os.chdir("/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/")

    if menu_option==1: # Merge TauMu and EleTau
        
        Zp_samples = ["Zprime_200","Zprime_250","Zprime_300","Zprime_350","Zprime_400","Zprime_450","Zprime_500"]
        Zp_tuples = [(i,i) for i in Zp_samples]
        hadd_dictionary = {}
        # Fill with all the relevant pairings
        hadd_dictionary["Data"] = ("Data","Data")
        hadd_dictionary["MC"] = ("MC","MC")
        hadd_dictionary["Signal_Sherpa"] = ("Signal_Sherpa","Signal_Sherpa")
        hadd_dictionary["Signal_PoPy"] = ("Signal_PoPy","Signal_PoPy")
        hadd_dictionary["singletop"] = ("singletop","singletop")
        hadd_dictionary["ttbar"] = ("ttbar","ttbar")
        hadd_dictionary["VV"] = ("VV","VV")
        hadd_dictionary["Wjets"] = ("Wjets","Wjets")
        hadd_dictionary["Higgs"] = ("Higgs","Higgs")
        hadd_dictionary["Higgs_EWK"] = ("Higgs_EWK","Higgs_EWK")
        hadd_dictionary["Zjets"] = ("Zjets","Zjets")
        hadd_dictionary["W_EWK_Sherpa"] = ("W_EWK_Sherpa","W_EWK_Sherpa")
        hadd_dictionary["W_EWK_PoPy"] = ("W_EWK_PoPy","W_EWK_PoPy")
        hadd_dictionary["VV_EWK"] = ("VV_EWK","VV_EWK")
        for Zp_sample in Zp_samples:
            hadd_dictionary[Zp_sample] = (Zp_sample,Zp_sample)
        potential_rw_samples = ["Ztautau_Sherpa","Ztautau_MG","Ztautau_SherpaNLO","Ztautau_MGNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, used_rw_samples)
        
        

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
        copy_root_files_from_to("../EleTau/MC/out/",zte_path, list_of_potential_rw_samples = potential_rw_samples, used_rw_samples = used_rw_samples) # Relative to the current directory
        copy_root_files_from_to("../TauMu/MC/out/",ztm_path, list_of_potential_rw_samples = potential_rw_samples, used_rw_samples = used_rw_samples)

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
        hadd_dictionary["singletop"] = ("singletop","singletop")
        hadd_dictionary["ttbar"] = ("ttbar","ttbar")
        hadd_dictionary["VV"] = ("VV","VV")
        hadd_dictionary["Wjets"] = ("Wjets","Wjets")
        hadd_dictionary["Higgs"] = ("Higgs","Higgs")
        hadd_dictionary["Higgs_EWK"] = ("Higgs_EWK","Higgs_EWK")
        hadd_dictionary["Zjets"] = ("Zjets","Zjets")
        hadd_dictionary["W_EWK_Sherpa"] = ("W_EWK_Sherpa","W_EWK_Sherpa")
        hadd_dictionary["W_EWK_PoPy"] = ("W_EWK_PoPy","W_EWK_PoPy")
        hadd_dictionary["VV_EWK"] = ("VV_EWK","VV_EWK")
        potential_rw_samples = ["Ztautau_Sherpa","Ztautau_MG","Ztautau_SherpaNLO","Ztautau_MGNLO"]
        add_potential_rw_samples(hadd_dictionary, potential_rw_samples, used_rw_samples)

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
        copy_root_files_from_to("../MuEle/MC/out/",zemu_path, list_of_potential_rw_samples = potential_rw_samples, used_rw_samples = used_rw_samples)

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
        if not used_rw_samples:
            INFO.log("When not using RW samples, all the not RW samples will be added.")
            add_potential_rw_samples(hadd_dictionary, potential_rw_samples, used_rw_samples = False, channel="Zll")
        else:
            INFO.log("When using RW samples, only the RW samples will be added.")
            hadd_dictionary = {} # Clean the dictionary and fill it later.
            hadd_dictionary["Zll_Sherpa_RWParabolicCutoff"] = ("Zee_Sherpa_RWParabolicCutoff","Zmumu_Sherpa_RWParabolicCutoff")
            hadd_dictionary["Zll_MG_RWParabolicCutoff"] = ("Zee_MG_RWParabolicCutoff","Zmumu_MG_RWParabolicCutoff")
            hadd_dictionary["Zll_SherpaNLO_RWParabolicCutoff"] = ("Zee_SherpaNLO_RWParabolicCutoff","Zmumu_SherpaNLO_RWParabolicCutoff")
            hadd_dictionary["Zll_MGNLO_RWParabolicCutoff"] = ("Zee_MGNLO_RWParabolicCutoff","Zmumu_MGNLO_RWParabolicCutoff")
            hadd_dictionary["Zll_Sherpa_RWExponential"] = ("Zee_Sherpa_RWExponential","Zmumu_Sherpa_RWExponential")
            hadd_dictionary["Zll_MG_RWExponential"] = ("Zee_MG_RWExponential","Zmumu_MG_RWExponential")
            hadd_dictionary["Zll_SherpaNLO_RWExponential"] = ("Zee_SherpaNLO_RWExponential","Zmumu_SherpaNLO_RWExponential")

        # Ask the name of the directory where files are stored
        dir_name = input("Enter the name of the directory where the files will be stored: ")
        validate_input(dir_name)

        if 'SR' in dir_name:
            INFO.log("You are merging the SR samples. Adding the Parabolic RW samples for the Zll channel.")
            hadd_dictionary["Zll_Sherpa_RWParabolic"] = ("Zee_Sherpa_RWParabolic","Zmumu_Sherpa_RWParabolic")
            hadd_dictionary["Zll_MG_RWParabolic"] = ("Zee_MG_RWParabolic","Zmumu_MG_RWParabolic")

        # First the final directory
        zll_path = os.path.join("Zll", dir_name)
        create_if_not_exists(zll_path)

        # Define the input paths
        zee_path= os.path.join("Zee", dir_name)
        create_if_not_exists(zee_path)
        zmm_path= os.path.join("MuMu", dir_name)
        create_if_not_exists(zmm_path)

        # Copy the root files from the channels to the output directory
        # Obtain the source paths relative to the current directory
        INFO.log('Enter the path to the Zee samples (relative to the current directory):')
        source_zee_path = input().strip()
        if not os.path.exists(source_zee_path):
            ERROR.log("The path %s does not exist. Please check the path and try again." % source_zee_path)
            exit(1)
        
        INFO.log('Enter the path to the MuMu samples (relative to the current directory):')
        source_mumu_path = input().strip()
        if not os.path.exists(source_mumu_path):
            ERROR.log("The path %s does not exist. Please check the path and try again." % source_mumu_path)
            exit(1)

        if not used_rw_samples:
            copy_root_files_from_to(source_zee_path, zee_path, list_of_potential_rw_samples = potential_rw_samples, used_rw_samples = used_rw_samples) # Relative to the current directory
            copy_root_files_from_to(source_mumu_path, zmm_path, list_of_potential_rw_samples = potential_rw_samples, used_rw_samples = used_rw_samples)
        else:
            INFO.log("When using RW samples, the RW samples are assumed to exist in their paths.")


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
    used_rw_samples = menu("Did you use RW samples?",["No","Yes"]) == 2
    main(option, used_rw_samples)
    