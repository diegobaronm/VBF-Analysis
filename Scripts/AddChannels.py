import os
from CreateListToRun import menu

def copy_root_files_from_to(from_path,to_path):
    # Copy the root files from the from_path to the to_path
    for root_file in os.listdir(from_path):
        if root_file.endswith(".root"):
            os.system("cp "+from_path+root_file+" "+to_path)

def create_if_not_exists(directory):
    try:
        os.mkdir(directory)
        print("Creating directory: ",directory)
    except FileExistsError:
        pass


def main(menu_option):
    # Change to the directory where the files are
    os.chdir("/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/")

    if menu_option==1: # Merge TauMu and EleTau
        
        Zp_samples = ["Zprime_200.root","Zprime_250.root","Zprime_300.root","Zprime_350.root","Zprime_400.root","Zprime_450.root","Zprime_500.root"]
        Zp_tuples = [(i,i) for i in Zp_samples]
        sample_pairs=[("Data.root","Data.root"),("MC.root","MC.root"),("Signal_Sherpa.root","Signal_Sherpa.root"),
                    ("Signal_PoPy.root","Signal_PoPy.root"),("singletop.root","singletop.root"),("ttbar.root","ttbar.root"),
                    ("VV.root","VV.root"),("Wjets.root","Wjets.root"),("Higgs.root","Higgs.root"),("Higgs_EWK.root","Higgs_EWK.root"),("Zjets.root","Zjets.root"),
                    ("W_EWK_Sherpa.root","W_EWK_Sherpa.root"),("W_EWK_PoPy.root","W_EWK_PoPy.root"),("VV_EWK.root","VV_EWK.root"),
                    ("Ztautau_Sherpa.root","Ztautau_Sherpa.root"),("Ztautau_MG.root","Ztautau_MG.root"),
                    ("Ztautau_SherpaNLO.root","Ztautau_SherpaNLO.root"),("Ztautau_MGNLO.root","Ztautau_MGNLO.root"),] + Zp_tuples #+[("ttbar1bjet.root","ttbar1bjet.root"),("QCDjjOneGapJet.root","QCDjjOneGapJet.root")]
        output_names = ["Data.root","MC.root","Signal_Sherpa.root","Signal_PoPy.root","singletop.root","ttbar.root","VV.root",
                        "Wjets.root","Higgs.root","Higgs_EWK.root","Zjets.root","W_EWK_Sherpa.root","W_EWK_PoPy.root","VV_EWK.root",
                        "Ztautau_SherpaRW.root","Ztautau_MGRW.root","Ztautau_SherpaNLORW.root","Ztautau_MGNLORW.root"] + Zp_samples#+["ttbar1bjet.root","QCDjjOneGapJet.root"]
        
        # Ask the name of the directory where files are stored
        dir_name = input("Enter the name of the directory where the files will be stored: ")

        # Create the output directory if it does not exist
        ztt_path="TauTau/TauhadTaulep/High-Mass/" + dir_name + "/"
        create_if_not_exists(ztt_path)
        
        # Define the input paths
        zte_path="EleTau/High-Mass/"  + dir_name + "/"
        create_if_not_exists(zte_path)
        ztm_path="TauMu/High-Mass/" + dir_name + "/"
        create_if_not_exists(ztm_path)

        # Copy the root files from the channels to the output directory
        copy_root_files_from_to("../EleTau/MC/out/",zte_path) # Relative to the current directory
        copy_root_files_from_to("../TauMu/MC/out/",ztm_path)

        # Do the merging
        for s in range(0,len(output_names)):
            os.system("hadd -f "+ztt_path+output_names[s]+" "+zte_path+sample_pairs[s][0]+" "+ztm_path+sample_pairs[s][1])

    elif menu_option==2: # Merge TauLep and MuEle

        sample_pairs=[("Data.root","Data.root"),("MC.root","MC.root"),("Signal_Sherpa.root","Signal_Sherpa.root"),
             ("Signal_PoPy.root","Signal_PoPy.root"),("singletop.root","singletop.root"),("ttbar.root","ttbar.root"),
             ("VV.root","VV.root"),("Wjets.root","Wjets.root"),("Higgs.root","Higgs.root"),("Higgs_EWK.root","Higgs_EWK.root"),("Zjets.root","Zjets.root"),
              ("Ztautau_SherpaRW.root","Ztautau_SherpaRW.root"),
             ("Ztautau_MGRW.root","Ztautau_MGRW.root"),('W_EWK_Sherpa.root','W_EWK_Sherpa.root'),('W_EWK_PoPy.root','W_EWK_PoPy.root'),('VV_EWK.root','VV_EWK.root')]
        output_names = ["Data.root","MC.root","Signal_Sherpa.root","Signal_PoPy.root","singletop.root","ttbar.root","VV.root",
                "Wjets.root","Higgs.root","Higgs_EWK.root","Zjets.root","Ztautau_SherpaRW.root","Ztautau_MGRW.root","W_EWK_Sherpa.root","W_EWK_PoPy.root","VV_EWK.root"]

        # Define the input/output paths
        ztt_path="TauTau/Z-peak/SR/"
        zthth_path="TauTau/TauhadTaulep/Z-Peak/NoBugDeterministicBDTSR/"
        zemu_path="MuEle/Plots/Z-peak/SR/"

        # Do the merging
        for s in range(0,len(output_names)):
            os.system("hadd -f "+ztt_path+output_names[s]+" "+zthth_path+sample_pairs[s][0]+" "+zemu_path+sample_pairs[s][1])


if __name__ == "__main__":
    option = menu("Which channels do you want to merge?",["TauMu + EleTau","TauLep + MuEle"," MuMu + Zee"])
    main(option)
    