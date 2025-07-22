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

def add_potential_rw_samples(pairs_dict,list_of_samples, used_rw_samples):
    for sample in list_of_samples:
        if used_rw_samples == True:
            pairs_dict[sample+"RW"] = (sample+"RW", sample+"RW")
        else:
            pairs_dict[sample] = (sample, sample)



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
            status = os.system("hadd -f %s.root %s.root %s.root" % (ztt_path+result_sample, zte_path+sample_pair[0], ztm_path+sample_pair[1]))
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
            status = os.system("hadd -f %s.root %s.root %s.root" % (ztt_path+result_sample, zthtl_path+sample_pair[0], zemu_path+sample_pair[1]))
            if status:
                ERROR.log("Error merging these samples!")
            else:
                INFO.log("Sucess!!")

    elif menu_option==3: # Merge MuMu and Zee
        # TODO

    else:
        ERROR.log("Invalid option selected. Please choose a valid option.")
        exit(1)


if __name__ == "__main__":
    option = menu("Which channels do you want to merge?",["TauMu + EleTau","TauLep + MuEle (TauLep need to be already in the correct path)"," MuMu + Zee"])
    used_rw_samples = menu("Did you use RW samples?",["No","Yes"]) == 2
    main(option, used_rw_samples)
    