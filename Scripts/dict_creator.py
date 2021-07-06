# DICTIONARY CREATOR FOR NEW SAMPLES

# THIS SCRIPT MUST BE USED IN THE FOLLOWING WAY

# python3 dict_creator.py <Path to folder containing samttples>  <name_to_be_assigned> <string to identify sample, for instance: Zmumu_PoPy each word separated by "_" will be used to identify dataset>


# IMPORTANT LIBRARIES
import os
import sys
import csv

# ARGUMENTS GIVEN TO THE SCRIPT

folders=os.listdir(sys.argv[1]) # PATH TO LOOK FOR THE SAMPLES

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
        with open("LepUniv_xsec.csv","r") as csv_file:
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
        print("'"+key+"'", ' : ', value,",")

dict_of_samples={"Ztautau":"361108_PoPy","Zmumu":"mumu_PoPy","Zee":"Zee_PoPy","Wplustaunu":"Wplustaunu_PoPy","Wminustaunu":"Wminustaunu_PoPy",
"Wplusmunu":"Wplusmunu_PoPy","Wminusmunu":"Wminusmunu_PoPy","Wminusenu":"Wminusenu_PoPy","Wplusenu":"Wplusenu_PoPy","ttbar":"ttb",
"ZqqZvv":"ZqqZvv","ZqqZll":"ZqqZll","WqqZvv":"WqqZvv","WqqZll":"WqqZll","WlvZqq":"WlvZqq","llll":"llll","lllv":"lllv",
"llvv":"llvv","lvvv":"lvvv","st_schan_top":"410644","st_schan_atop":"410645","st_wt_top":"410646","st_wt_atop":"410647",
"st_tchan_top":"410658","st_tchan_atop":"410659","Ztautau_sherpa":"364_MV_tt_Sh221","Zmumu_sherpa":"364_MV_mumu_Sh221",
"Zee_sherpa":"364_MV_Zee_Sh221","VBF_Ztautau":"Ztt_Sh221_2jets","VBF_Zmumu":"Zmm_Sh221_2jets",
"VBF_Zee":"Zee_Sh221_2jets","WpH":"345212","WmH":"345211","ZHllbb":"345055","ZHlltautau":"346329"}


for i in dict_of_samples:
    create_dict(i,dict_of_samples[i])

