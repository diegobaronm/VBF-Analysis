import os
import sys

from AnalysisCommons.Run import INFO, WARNING, ERROR

def menu(question,options):
    incorrect_answer=True
    while incorrect_answer:
        INFO.log(question)
        c=0
        for i in options:
            c+=1
            INFO.log(str(c)+")"+" "+i)
        answer=input()
        if int(answer)<=len(options):
            incorrect_answer=False
        else :
            INFO.log("Select a correct option!")
    return int(answer)

def tag_checker(channel,include_tags,exclude_tags,remote):
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
        if include:
            samples=samples+dataCombos[i]

    file_name_string=""
    if remote:
        file_name_string="_Condor"
    
    with open("Input"+file_name_string+".txt","w") as file:

        for j in samples:
            file.write(j)
            file.write('\n')

def sample_file_generator(type_of_ntuples, rem):
    # Ask one more question to the user
    valid_channels = ["TauMu","EleTau","MuEle","Zee","MuMu"]
    channelIndex = menu("Select a channel:",valid_channels)
    channel = valid_channels[channelIndex-1]

    # NOMINAL
    if type_of_ntuples==1 :
        tag_checker(channel,[],["sys"],rem)
    elif type_of_ntuples==2 :
        tag_checker(channel,["sys"],[],rem)

if __name__ == "__main__":
    # Ask questions to the user
    ntuples_type = menu("Nominal or systematics?",["Nominal","Systematics"])
    running_machine = menu("Where are you running?",["Local","Lxplus"])

    sample_file_generator(ntuples_type, running_machine==2)