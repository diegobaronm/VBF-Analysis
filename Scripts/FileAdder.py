from ast import arg
import os
import sys
def AddRootFiles(path,destination):
    os.chdir(path)
    samples = [i for i in os.listdir('SR') if '.root' in i]
    folders = ['SR/','CR/']#'CRa/','CRb/','CRc/']
    for sample in samples:
        addCommand = 'hadd '+destination+sample
        for folder in folders:
            addCommand+=' '+folder+sample
        os.system(addCommand)
if __name__=="__main__":
    AddRootFiles(sys.argv[1],sys.argv[2])