#!/usr/bin/env python3

# ----------------------------------------------------------------
#
#	The shebang above is MANDATORY for Condor execution!
#
# ----------------------------------------------------------------

# script which the user launches to ask which data sets to analyse, handle weighting and launch the
# analysis

import sys
import os
sys.path.append('../../') # allow code to be imported from main directory

from AnalysisCommons.Metadata.infofileZmumu import infos
from AnalysisCommons.Metadata.datasetsZmumu import dataSets, realList, dataCombos, dirs
from AnalysisCommons.Run import getInput, luminosity, isRunningRemote, getEventWeight, DrawC, getZllSampleKey, INFO, DEBUG, ERROR

def runAnalysis(key, remote):
    """
    Function to run the analysis for a given decay chain labelled 'key'
    """

    # get the Z boson process
    z_sample= getZllSampleKey(key)

    # get filename
    filename = dataSets[key]

    totRealLum=luminosity(key)
    INFO.log("Luminosity for this year: "+str(totRealLum))

    # get luminosity weight if data is MC
    lumStr = getEventWeight(key,realList,infos,totRealLum)

    # launch the analysis script for the given data set
    tree_name = sys.argv[3]
    region = sys.argv[4]

    DrawC(filename,lumStr,z_sample,key,tree_name, region, dirs)

    # move the output to a different directory
    if remote:
        output=os.system("mv "+key+tree_name+".root "+"/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zmm/"+tree_name+"/"+key+tree_name+".root")
        if (output!=0):
            os.system("echo "+key+" yes "+tree_name+"   >> "+"/afs/cern.ch/work/d/dbaronmo/private/Outputs/FAILED_Zmm.txt")
    else :
        output=os.system("mv "+key+tree_name+".root "+"out/"+tree_name+"/"+key+tree_name+".root")
        if (output!=0):
            os.system("echo "+key+" yes "+tree_name+" >> "+"FAILED.txt")

def main():
    # get input from user
    chains = getInput(dataCombos)

    # see if the code is executed in remote mode
    remote_mode = isRunningRemote(sys.argv[2])

    # iterate over chains from user input
    for sample in chains:
        INFO.log("Running analysis for: "+sample)
        runAnalysis(sample,remote_mode)

if __name__ == "__main__":
    main()