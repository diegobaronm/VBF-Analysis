import ROOT as r
from os import listdir
from dataSets import dirs

def DrawC(filename,lumStr,remote,z_sample,key_pop,tree):
    """
    Function to load in the C++ code and run it for a given data set
    """

    # search through several directories to find where the input file is located
    for path in dirs:
        if filename in listdir(path):
            correctPath = path
            break

    # reset environment and get path to file
    r.gROOT.Reset()
    fullPath = correctPath + filename

    # load in CLoop.C
    if remote:
        r.gSystem.Load("CLoop_C")
    else :
        r.gSystem.Load("backend/CLoop_C")

    # load in tree from file
    r.gROOT.ProcessLine("TFile* f = new TFile(\""+fullPath+"\")")
    r.gROOT.ProcessLine("TTree * minTree = new TTree")
    r.gROOT.ProcessLine("f->GetObject(\""+tree+"\",minTree)")

    # create new instance of CLoop and loop over events
    r.gROOT.ProcessLine("CLoop* t = new CLoop(minTree)")
    r.gROOT.ProcessLine("t->Loop("+lumStr+","+str(z_sample)+","+'"'+key_pop+tree+'"'+")")
    r.gROOT.ProcessLine("f->Close("R")")
