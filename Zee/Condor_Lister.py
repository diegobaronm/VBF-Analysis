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

    with open("Input_Condor.txt","w") as file:
        if ".txt" not in branches:
            for j in samples:
                file.write(j+" yes "+branches)
                file.write('\n')
        else :
            with open(branches) as f:
                lines = f.readlines()
            for l in lines:
                for j in samples:
                    file.write(j+" yes "+l.strip("\n"))
                    file.write('\n')

    sys.path.pop() # CLEAN PATH
    sys.modules.pop("dataSets") # MODULE
    os.chdir('..')

def sample_file_generator(type_of_ntuples):
    # NOMINAL
    if type_of_ntuples==1 :
        tag_checker("DATA",[],["sys"],"NOMINAL")
        tag_checker("MC",[],["sys"],"NOMINAL")
    elif type_of_ntuples==2 :
        tag_checker("MC",["sys"],["jet"],"sys_trees.txt")
    elif type_of_ntuples==3 :
        tag_checker("MC",["sys","jet"],[],"sys_jet_trees.txt")


if __name__ == "__main__":

    ntuples_type=menu("Nominal or systematics?",["Nominal","Systematics NO JET","Systematics JET"])
    sample_file_generator(ntuples_type)


