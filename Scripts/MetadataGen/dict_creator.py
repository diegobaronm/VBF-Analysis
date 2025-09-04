# DICTIONARY CREATOR FOR NEW SAMPLES

# THIS SCRIPT MUST BE USED IN THE FOLLOWING WAY

# python3 dict_creator.py <Path to folder containing samttples>  <name_to_be_assigned> <string to identify sample, for instance: Zmumu_PoPy each word separated by "_" will be used to identify dataset>


# IMPORTANT LIBRARIES
import os
import sys
import csv

# ARGUMENTS GIVEN TO THE SCRIPT

folders=os.listdir(sys.argv[1]) # PATH TO LOOK FOR THE SAMPLES
sys_key=""
if(len(sys.argv)>2):
    sys_key="_sys"

def create_dict(sample_name,sample_match_strings):

    # KEYWORDS TO LOOK FOR THE SAMPLES
    keywords=sample_match_strings.split("_")

    #FILL A LIST WITH ALL THE DIRECTORIES THAT CONTAIN THE KEYWORDS
    matching_folders=[]
    for sample in folders:
        match=False
        for keyword in keywords:
            if keyword in sample:
                match=True
            else :
                match=False
                break
        if match:
            matching_folders.append(sample)

    # FILLS A LIST WITH ALL THE MC IDs
    MC_Ids_no_unique=[i.split(".")[4] for i in matching_folders] # NON-UNIQUE LIST
    MC_Ids=[]
    for ids in MC_Ids_no_unique:
        if ids not in MC_Ids:
            MC_Ids.append(ids)

    # CREATE A DICTIONARY WITH THE NAME OF THE DIRECTORIES CONTAINING THE SAMPLES AND PROPERTIES OF THE SAMPLE
    dict={}

    id_counter=1 # EACH DIFFERENT ID HAS A DIFFERENT VALUE
    for IDs in MC_Ids:
        xsec=0
        kfactor=0
        filteref=0
        # LOOK FOR THE PROPERTIES OF SAMPLE BASED ON THE ID
        with open("Xsec.csv","r") as csv_file:
            csv_reader=csv.reader(csv_file,delimiter=',')
            for row in csv_reader:
                if IDs in row:
                    xsec=float(row[2])
                    kfactor=float(row[3])
                    filteref=float(row[4])
                    break

        # CREATE THE DICTIONARY DIVIDING EACH SAMPLE PER DATA TAKING PERIOD
        for sample in matching_folders:
            if(len(matching_folders)>3):
                if IDs in sample:
                    if "r9364" in sample:
                        dict[sample_name+str(id_counter)+"_2015"]=[sample,IDs,xsec,kfactor,filteref]
                    elif "r10201" in sample:
                        dict[sample_name+str(id_counter)+"_2017"]=[sample,IDs,xsec,kfactor,filteref]
                    elif "r10724" in sample:
                        dict[sample_name+str(id_counter)+"_2018"]=[sample,IDs,xsec,kfactor,filteref]
            else :
                if IDs in sample:
                    if "r9364" in sample:
                        dict[sample_name+"_2015"]=[sample,IDs,xsec,kfactor,filteref]
                    elif "r10201" in sample:
                        dict[sample_name+"_2017"]=[sample,IDs,xsec,kfactor,filteref]
                    elif "r10724" in sample:
                        dict[sample_name+"_2018"]=[sample,IDs,xsec,kfactor,filteref]
        id_counter+=1

    # PRINT THE DICTIONARY IN THE CORRECT FORMAT TO PUT IT ON THE lister_mc.py SCRIPT
    for key, value in dict.items():
        print("'%s'  :  ['%s','%s',%e,%f,%f] ," % (key, value[0], value[1], value[2], value[3], value[4]))

dict_of_samples={"Ztautau":"361108_PoPy","Zmumu":"mumu_PoPy","Zee":"Zee_PoPy","Wplustaunu":"Wplustaunu_PoPy","Wminustaunu":"Wminustaunu_PoPy",
"Wplusmunu":"Wplusmunu_PoPy","Wminusmunu":"Wminusmunu_PoPy","Wminusenu":"Wminusenu_PoPy","Wplusenu":"Wplusenu_PoPy","ttbar":"ttb",
"ZqqZvv":"ZqqZvv","ZqqZll":"ZqqZll","WqqZvv":"WqqZvv","WqqZll":"WqqZll","WlvZqq":"WlvZqq","llll":"llll_Sh222","lllv":"lllv_Sh222",
"llvv":"llvv_Sh222","lvvv":"lvvv_Sh222","st_schan_top":"410644","st_schan_atop":"410645","st_wt_top":"410646","st_wt_atop":"410647",
"st_tchan_top":"410658","st_tchan_atop":"410659","Ztautau_sherpa":"364_MV_tt_Sh221","Zmumu_sherpa":"364_MV_mumu_Sh221",
"Zee_sherpa":"364_MV_Zee_Sh221","VBF_Ztautau_old":"Ztt_Sh221_2jets","VBF_Zmumu_old":"Zmm_Sh221_2jets",
"VBF_Zee_old":"Zee_Sh221_2jets","VBF_Ztautau":"600939","VBF_Zmumu":"600938","VBF_Zee":"600937","VBF_Ztautau_sherpa":"700360","VBF_Zmumu_sherpa":"700359",
"VBF_Zee_sherpa":"700358",
"WpH":"345212","WmH":"345211","ZHllbb":"345055","ZHlltautau":"346329","ggHttlm15hp20":"345121","ggHttlp15hm20":"345122",
"VBFHttlm15hp20":"346191","VBFHttlp15hm20":"346192","VBFHttl13l7":"346190","VBFHtth30h20":"346193",
"Zee_MG":"MGPy8_Zee","Zmumu_MG":"MGPy8_Zmumu","Ztautau_MG":"MadPy_Ztt",
"Zee_MGNLO":"MGPy8_Zee_3jets","Zmumu_MGNLO":"MGPy8_Zmumu_3jets","Ztautau_MGNLO":"MGPy8_Ztt_3jets",
"Zee_SherpaNLO":"Sh_2211_Zee_maxHTpTV2","Zmumu_SherpaNLO":"Sh_2211_Zmumu_maxHTpTV2","Ztautau_SherpaNLO":"Sh_2214_Ztt_maxHTpTV2",
"W_EWK_PoPy":"PhPy8_VBF_W","W_EWK_sherpa":"Sh_2211_W_2jets",
"VV_EWK":"Sh_2212_jj","VV_EWK_SemiLep":"MGPy8EvtGen_jj_qq",
"VBF_Zee_MG_bug_LM":"545882", "VBF_Zee_MG_bug_HM":"545883", 
"VBF_Zmumu_MG_bug_LM":"545884", "VBF_Zmumu_MG_bug_HM":"545885", 
"VBF_Ztautau_MG_bug_LM":"545886", "VBF_Ztautau_MG_bug_HM":"545887",
"VBF_Zee_MG_LM":"558309", "VBF_Zee_MG_HM":"558310", 
"VBF_Zmumu_MG_LM":"558311", "VBF_Zmumu_MG_HM":"558312", 
"VBF_Ztautau_MG_LM":"558313", "VBF_Ztautau_MG_HM":"558314", 
"VBF_Zprime_200": "545888", "VBF_Zprime_250": "545889", "VBF_Zprime_300": "545890", "VBF_Zprime_350": "545891", "VBF_Zprime_400": "545892",  "VBF_Zprime_450": "545893",  "VBF_Zprime_500": "545894",
"VBF_Zprime_550":"567845",
"VBF_Zprime_600":"567846",
"VBF_Zprime_650":"567847",
"VBF_Zprime_700":"567848",
"VBF_Zprime_750":"567849",
"VBF_Zprime_800":"567850",
"VBF_Zprime_850":"567851",
"VBF_Zprime_900":"567852",
"VBF_Zprime_950":"567853",
"VBF_Zprime_1000":"567854",
"VBF_Zprime_1200":"567855",
"VBF_Zprime_1400":"567856",
"VBF_Zprime_1600":"567857",
"VBF_Zprime_1800":"567858",
"VBF_Zprime_2000":"567859",
"VBF_Zprime_2500":"567860",
"VBF_Zprime_3000":"567861" 
}

for i in dict_of_samples:
    create_dict(i,dict_of_samples[i])