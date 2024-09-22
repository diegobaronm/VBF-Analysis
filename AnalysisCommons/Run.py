import sys
import ROOT as r
from os import listdir
import sys

# Define  colours for the output
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Logger:
    def __init__(self,level, colour):
        self.m_level = level
        self.m_colour = colour
        self.s_LOG_LEVELS = {"ERROR":1,"INFO":2,"DEBUG":3}
    def log(self,message):
        if  self.s_LOG_LEVELS[self.m_level] <= LOGLEVEL:
            message = self.m_colour+self.m_level+': '+bcolors.ENDC+message
            print(message)

INFO = Logger("INFO",bcolors.OKGREEN)
ERROR = Logger("ERROR",bcolors.FAIL)
DEBUG = Logger("DEBUG",bcolors.OKBLUE)

LOGLEVEL = 3

def getInput(dataCombo):
    """
    Function to validate the input from the user.
    Returns an array of keys to analyse.
    """

    # get list of decay chains from user
    userInput = sys.argv[1] # get input
    chain = []
    # Check if the input is a chain:
    try:
        chain = dataCombo[userInput]
        DEBUG.log("Key is a chain.")
        return chain
    except KeyError:
        DEBUG.log("Key is not a chain, trying to analyse it as a single file.")
        comboName = userInput.split("_")
        # Drop the last element since this should be just a file indicator
        comboName = "_".join(comboName[:-1])
        try :
            chain = dataCombo[comboName]
            for i in dataCombo[comboName]:
                if i == userInput:
                    return [userInput]
            ERROR.log("Key: "+userInput+" is not a single file of combo: "+comboName)
            exit(1)
        except KeyError:
            ERROR.log("Key is not a single file either.")
            exit(1)

def luminosity(key):
    """
    Function to get the luminosity for a given data set.
    """
    if "2018" in key:
        return 58.4501
    elif "2017" in key:
        return 43.5873
    else :
        return 36.2369
    
def getEventWeight(key,realList,infos,totRealLum):
    if key in realList:
        lumStr = "1"
    else:
        # calculate luminosity weight
        lumWeight = (totRealLum * 1000 * infos[key]["xsec"] * infos[key]["fil_eff"] * infos[key]["kfac"])/infos[key]["sumw"]
        lumStr = "%.5E" % (lumWeight)
    DEBUG.log("Luminosity weight = "+lumStr)
    return lumStr
    
def getZllSampleKey(key):
    """
    Function to know the type of Z boson process.
    """
    z_sample=0
    if ("Zee" in key) or ("Zmumu" in key) or ("Ztautau" in key):
        z_sample=1 # Powheg
        if "sherpa" in key or "Sherpa" in key:
            z_sample=2
            if "NLO" in key:
                z_sample=4
        if "MG" in key:
            z_sample=3
            if "NLO" in key:
                z_sample=5
        if "VBF" in key:
            z_sample=0
    if z_sample!=0:
        INFO.log("This sample is eligible for reweighting.")
    else:
        INFO.log("This sample is not eligible for reweighting.")

    return z_sample

def isRunningRemote(Remote):
    """
    Function to see if the code is executed in remote mode.
    """
    if Remote == "yes":
        remote_mode = True
        DEBUG.log("Remote mode enabled.")
    elif Remote == "no":
        remote_mode = False
        DEBUG.log("Remote mode disabled.")
    else:
        ERROR.log("Remote mode not recognised.")
        exit(1)
    return remote_mode
    
def DrawC(filename,lumStr,remote,z_sample,key_pop,tree,region, dirs):
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
    if sys.argv[0]=="condor_exec.exe":
        r.gSystem.Load("CLoop_C")
    else :
        r.gSystem.Load("backend/CLoop_C")

    # load in tree from file
    r.gROOT.ProcessLine("TFile* f = new TFile(\""+fullPath+"\")")
    r.gROOT.ProcessLine("TTree * minTree = new TTree")
    r.gROOT.ProcessLine("f->GetObject(\""+tree+"\",minTree)")

    # create new instance of CLoop and loop over events
    r.gROOT.ProcessLine('CLoop* t = new CLoop(minTree, "%s", "%s")' % (key_pop, region))
    r.gROOT.ProcessLine("t->Loop("+lumStr+","+str(z_sample)+","+'"'+key_pop+tree+'"'+")")
    r.gROOT.ProcessLine("f->Close("R")")

if __name__ == "__main__":
    print("This script is not meant to be run directly.")