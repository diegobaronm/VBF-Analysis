import os
import sys

def menu(question,options):
    incorrect_answer=True
    while incorrect_answer:
        print(question)
        c=0
        for i in options:
            c+=1
            print(str(c)+")"+" "+i)
        answer=input()
        if int(answer)<=len(options):
            incorrect_answer=False
        else :
            print("Select a correct option!")
    return int(answer)

def tag_checker(channel,include_tags,exclude_tags,branches,remote,region):
    # Got to the channel directory and add the relevant things to the path
    channelPath = '../'+channel
    os.chdir(channelPath)

    # Now import the relevant combinations
    valid_channels = ["TauMu","EleTau","MuEle","Zee","MuMu"]
    if channel in valid_channels[:3]: # Tau channels
        from AnalysisCommons.Metadata.datasetsTauTau import dataCombos_Data, dataCombos_MC
    elif channel in valid_channels[3]: # Zee
        from AnalysisCommons.Metadata.datasetsZee import dataCombos_Data, dataCombos_MC
    elif channel in valid_channels[4]: # Zmumu
        from AnalysisCommons.Metadata.datasetsZmumu import dataCombos_Data, dataCombos_MC
    else :
        print("Channel not found")
        exit(1)

    # Add the two dictionaries together
    dataCombos = dataCombos_MC.copy()
    dataCombos.update(dataCombos_Data)

    samples=[]
    for i in dataCombos:
        include=True
        for j in include_tags:
            if j not in i:
                include=False
                break
        if include :
            for j in exclude_tags:
                if j in i:
                    include=False
                    break
        if include and ".txt" not in branches:
            samples=samples+dataCombos[i]
        elif include and ".txt" in branches :
            samples=samples+[i]

    file_name_string=""
    if remote:
        file_name_string="_Condor"
    
    with open("Input"+file_name_string+".txt","w") as file:
        if ".txt" not in branches:
            for j in samples:
                if remote:
                    file.write("%s yes %s %s" % (j,branches,region))
                    file.write('\n')
                else :
                    file.write(j)
                    file.write('\n')
        else :
            with open(branches) as f:
                lines = f.readlines()
            for l in lines:
                for j in samples:
                    if remote:
                        file.write(j+" yes "+l.strip("\n"))
                        file.write('\n')
                    else :
                        file.write(j)
                        file.write('\n')

def sample_file_generator(type_of_ntuples, rem, region):
    # Ask one more question to the user
    valid_channels = ["TauMu","EleTau","MuEle","Zee","MuMu"]
    channelIndex = menu("Select a channel:",valid_channels)
    channel = valid_channels[channelIndex-1]

    # NOMINAL
    if type_of_ntuples==1 :
        tag_checker(channel,[],["sys"],"NOMINAL",rem, region)
    elif type_of_ntuples==2 :
        tag_checker(channel,["sys"],[],"sysTrees.txt",rem, region)

if __name__ == "__main__":
    # Ask questions to the user
    ntuples_type = menu("Nominal or systematics?",["Nominal","Systematics"])
    running_machine = menu("Wher are you running?",["Local","Lxplus"])
    region = input("Which region are you running? ")

    sample_file_generator(ntuples_type, running_machine==2, region)
    