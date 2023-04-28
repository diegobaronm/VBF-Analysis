from Condor_Lister import menu
import sys
import os
import subprocess,shlex

def tag_checker(dir,request,avoid):
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
        if include:
            samples=samples+dataCombos[i]

    sys.path.pop() # CLEAN PATH
    sys.modules.pop("dataSets") # MODULE
    os.chdir('..')
    return samples

def sample_list_generator(type_of_ntuples):
    # NOMINAL
    list_to_be_checked=[]
    if type_of_ntuples==1 :
        list_to_be_checked+=tag_checker("DATA",[],["sys"])
        list_to_be_checked+=tag_checker("MC",[],["sys"],)
    elif type_of_ntuples==2 :
        list_to_be_checked+=tag_checker("MC",["sys"],[])
    return list_to_be_checked

if __name__=="__main__":
    # Welcome Message
    print("\n")
    out_path="/afs/cern.ch/work/d/dbaronmo/private/Outputs/"
    print("This script is checking for outputs at "+out_path+"\n")
    # Checking for correct directory input
    try :
        path_to_check=sys.argv[1]
    except IndexError:
        print("Please enter directory to check as first argument...")
        exit()
    while path_to_check not in os.listdir(out_path):
            path_to_check=input("Please type a valid path to look for samples...\n")

    # Asking for ntuples type
    ntuples_type = menu("Nominal or systematics?",["Nominal","Systematics"])
    # Obtaining the list of samples to look for
    sample_list = sample_list_generator(ntuples_type)

    # Decide whic directories to look for depending on the type of run
    directories = ['NOMINAL']
    if ntuples_type==2:
        with open("MC/sysTrees.txt","r") as file:
            lines = file.readlines()
            directories = [directory.strip('\n') for directory in lines]

    # Moving to path where directories to look for are located and saving the path of the channel to later copy the files with samples missing.
    launch_dir = os.getcwd()
    os.chdir(out_path+path_to_check)

    # Depending on which type of run decide what files to create
    # NOMINAL data+MC run
    if ntuples_type==1:
        filedDataFileName = "FailedData_"+path_to_check+".txt"
        filedMCFileName = "FailedMC_"+path_to_check+".txt"
        outputFileData=open(filedDataFileName,"w+")
        outputFileMC=open(filedMCFileName,"w+")

        for directoryName in directories:
            root_files=os.listdir(directoryName)
            print("Looking for ",len(sample_list)," samples in ",directoryName,"...")
            if len(root_files)!=len(sample_list):
                numberSamplesFound = 0
                for s in sample_list:
                    flag=True
                    for r in root_files:
                        flag=True
                        if s==r[:-(len(directoryName)+5)]:
                            numberSamplesFound += 1
                            flag=False
                            break

                    if flag:
                        if "data" in s:
                            outputFileData.write(s+" yes "+directoryName+"\n")
                        else :
                            outputFileMC.write(s+" yes "+directoryName+"\n")
                print(numberSamplesFound,"samples found.")
            else :
                print("All found!")
    
        os.system("mv "+filedDataFileName+" "+launch_dir+"/DATA/"+filedDataFileName)
        os.system("mv "+filedMCFileName+" "+launch_dir+"/MC/"+filedMCFileName)   

    # Systematics run
    if ntuples_type==2:
        filedWeightFileName = "FailedWeightSys_"+path_to_check+".txt"
        outputFileWeight=open(filedWeightFileName,"w+")
        filedShapeFileName = "FailedShapeSys_"+path_to_check+".txt"
        outputFileShape=open(filedShapeFileName,"w+")

        for directoryName in directories:
            root_files=os.listdir(directoryName)
            print("Looking for ",len(sample_list)," samples in ",directoryName,"...")
            if len(root_files)!=len(sample_list):
                numberSamplesFound = 0
                for s in sample_list:
                    flag=True
                    for r in root_files:
                        flag=True
                        if s==r[:-(len(directoryName)+5)]:
                            numberSamplesFound += 1
                            flag=False
                            break

                    if flag:
                        if directoryName=="NOMINAL":
                            outputFileWeight.write(s+" yes "+directoryName+"\n")
                        else :
                            outputFileShape.write(s+" yes "+directoryName+"\n")

                print(numberSamplesFound,"samples found.")
            else :
                print("All found!")

        os.system("mv "+filedWeightFileName+" "+launch_dir+"/MC/"+filedWeightFileName)
        os.system("mv "+filedShapeFileName+" "+launch_dir+"/MC/"+filedShapeFileName)   
    




