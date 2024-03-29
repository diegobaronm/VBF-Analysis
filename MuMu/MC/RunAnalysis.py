#!/usr/bin/env python3

# ----------------------------------------------------------------
#
#	The shebang above is MANDATORY for Condor execution!
#
# ----------------------------------------------------------------

# script which the user launches to ask which data sets to analyse, handle weighting and launch the
# analysis

import sys
sys.path.insert(0, "backend") # allow code to be imported from subdirectory
sys.path.insert(1,'../../AnalysisCommons/')

import ROOT as r
import os
from DrawC import DrawC
from getInput import getInput
from infofile import infos
from dataSets import dataSets, totRealLum, realList, dataCombos

def luminosity(key):
    if "2018" in key:
        #print("Working with less data")
        return 58.4501
    elif "2017" in key:
        return 43.5873
    else :
        return 36.2369

def runAnalysis(key):
    """
    Function to know if Z boson process
    """
    z_sample=0
    if ("Zee" in key) or ("Zmumu" in key) or ("Ztautau" in key):
        z_sample=1
        if "sherpa" in key or "Sherpa" in key:
            z_sample=2
            if "NLO" in key:
                z_sample=4
        if "VBF" in key:
            z_sample=0
        if "MG" in key:
            z_sample=3
            if "NLO" in key:
                z_sample=5
    """
    Function to run the analysis for a given decay chain labelled 'key'
    """
    # get filename
    filename = dataSets[key]

    totRealLum=luminosity(key)

    # get luminosity weight if data is MC
    if key in realList:
        lumStr = "1"
    else:
        # calculate luminosity weight
        # if it does not work try again without "_1lep" or "_2lep" suffix for key
        try:
            lumWeight = (totRealLum * 1000 * infos[key]["xsec"] * infos[key]["fil_eff"] * infos[key]["kfac"])/infos[key]["sumw"]
            print(lumWeight)
        except KeyError:
            shortKey = key[:-5]
            lumWeight = (totRealLum * 1000 * infos[shortKey]["xsec"] * infos[shortKey]["fil_eff"] * infos[shortKey]["kfac"])/infos[shortKey]["sumw"]
            print(lumWeight)
        lumStr = "%.5E" % (lumWeight)

    # launch the analysis script for the given data set
    tree_name=sys.argv[2]

    DrawC(filename,lumStr,z_sample,key,tree_name)

    # move the output to a different directory
    if sys.argv[0]=="condor_exec.exe":
        output=os.system("mv "+key+tree_name+".root "+"/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zmm/"+tree_name+"/"+key+tree_name+".root")
        if (output!=0):
            os.system("echo "+key+" yes "+tree_name+"   >> "+"/afs/cern.ch/work/d/dbaronmo/private/Outputs/FAILED_Zmm.txt")
    else :
        output=os.system("mv "+key+tree_name+".root "+"out/"+tree_name+"/"+key+tree_name+".root")
        if (output!=0):
            os.system("echo "+key+" yes "+tree_name+" >> "+"FAILED.txt")


# get input from user
# keep asking until answered
chainsValid = False
while (not chainsValid):
    #print("Please enter a comma-seperated list of decay chains.")
    #print("Use '+' to add data sets together.")
    #print("Write 'text' if you would prefer to read a list from 'input.txt':")
    chains, chainsValid = getInput()
    print()


# iterate over sums of chains from user input
for i in range(len(chains)):
    # loop over chains in the series and run the analysis
    for j in range(len(chains[i])):
        chain = chains[i][j]

        # print a message so the user knows what's up
        print("Analysing "+chain+"...")

        # if the decay chain corresponds to data in more than one file then
        # analyse all the files and add them
        if (chain in dataCombos.keys()):
            for subChain in dataCombos[chain]:
                print(subChain)
                runAnalysis(subChain)

        # otherwise run the analysis for the single file
        else:
            runAnalysis(chain)
