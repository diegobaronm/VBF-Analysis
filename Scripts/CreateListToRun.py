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

def tag_checker(channel,include_tags,exclude_tags,branches,remote):
    
    # Got to the channel directory and add the relevant things to the path
    channelPath = '../'+channel
    os.chdir(channelPath)
    sys.path.append(channelPath+'/MC/backend')
    sys.path.append('../AnalysisCommons')

    # Now import all the combos
    from dataSets import dataCombos_Data, dataCombos_MC
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
                    file.write(j+" yes "+branches)
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

def sample_file_generator(type_of_ntuples,rem):
    # Ask one more question to the user
    valid_channels = ["TauMu","EleTau","Zee","MuMu"]
    channelIndex = menu("Select a channel:",valid_channels)
    channel = valid_channels[channelIndex-1]

    # NOMINAL
    if type_of_ntuples==1 :
        tag_checker(channel,[],["sys"],"NOMINAL",rem)
    elif type_of_ntuples==2 :
        tag_checker(channel,["sys"],[],"sysTrees.txt",rem)

if __name__ == "__main__":
    # Ask questions to the user
    ntuples_type = menu("Nominal or systematics?",["Nominal","Systematics"])
    running_machine = menu("Wher are you running?",["Local","Lxplus"])

    sample_file_generator(ntuples_type, running_machine==2)


