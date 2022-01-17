import Condor_Lister
import sys
import os

def tag_checker(dir,request,avoid,branches):
    os.chdir(dir)
    sys.path.append('backend')
    from dataSets import dataCombos
    samples=[]
    for i in dataCombos:
        include=True
        for j in request:
            if j not in i:
                include=False
                break
        if include :
            for j in avoid:
                if j in i:
                    include=False
                    break
        if include and ".txt" not in branches:
            samples=samples+dataCombos[i]
        elif include and ".txt" in branches :
            samples=samples+[i]

    sys.path.pop() # CLEAN PATH
    sys.modules.pop("dataSets") # MODULE
    os.chdir('..')

    return samples

def sample_list_generator(type_of_ntuples):
    # NOMINAL
    list_to_be_checked=[]
    if type_of_ntuples==1 :
        list_to_be_checked+=tag_checker("DATA",[],["sys"],"NOMINAL")
        list_to_be_checked+=tag_checker("MC",[],["sys"],"NOMINAL")
    elif type_of_ntuples==2 :
        list_to_be_checked+=tag_checker("MC",["sys"],["jet"],"sys_trees.txt")
    elif type_of_ntuples==3 :
        list_to_be_checked+=tag_checker("MC",["sys","jet"],[],"sys_jet_trees.txt")
    
    return list_to_be_checked

if __name__=="__main__":
    # Welcome Message
    print("\n")
    out_path="/afs/cern.ch/work/d/dbaronmo/private/Outputs/"
    print("This script is checking for outputs at "+out_path+"\n")
    # Checking for script argument
    try :
        path_to_check=sys.argv[1]
    except IndexError:
        path_to_check="ERROR---///////"
    while path_to_check not in os.listdir(out_path):
            path_to_check=input("Please type a valid path to look for samples...\n")

    # Asking for ntuple type
    ntuples_type = Condor_Lister.menu("Nominal or systematics?",["Nominal","Systematics NO JET","Systematics JET"])
    # Obtaining the list of samples to look for
    sample_list = sample_list_generator(ntuples_type)

    launch_dir = os.getcwd()
    os.chdir(out_path+path_to_check)

    output_file_name = "Failed_"+path_to_check+".txt"
    output_file = open(output_file_name,"w+")

    ############### THIS HAS TO BE ADAPTED IN THE FUTURE ######################
    directories=['NOMINAL']

    for i in directories:
            root_files=os.listdir(i)
            print(len(sample_list))
            if len(root_files)!=len(sample_list):
                    for s in sample_list:
                            flag=True
                            for r in root_files:
                                    flag=True
                                    if s==r[:-(len(i)+5)]:
                                            flag=False
                                            break

                            if flag:
                                    output_file.write(s+" yes "+i+"\n")

    print("cat "+out_path+path_to_check+"/"+output_file_name+" | awk '/data/' > "+launch_dir+"/"+"DATA/Input_Failed.txt")                                    
    print("cat "+out_path+path_to_check+"/"+output_file_name+" | awk '!/data/' > "+launch_dir+"/"+"MC/Input_Failed.txt")
    




