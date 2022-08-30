import ROOT as r
import ctypes 
import pandas as pd
import sys
import os

def PrintYields(finalStateName,histogram,path,printToFile=True,latexFormat=False):
    os.chdir(path)
    # Create a list with the .root files excluding MC.root and BG.root files
    finalStateSamples = [i for i in os.listdir() if (('root' in i) and ('MC' not in i) and ('BG' not in i) and ('Average' not in i) )]
    # Create dictionary 
    samples = {}
    # Loop over the samples and calculate integral and error.
    for sample in finalStateSamples:
        print(sample)
        file = r.TFile.Open(sample)
        histo = file.Get(histogram)
        error = ctypes.c_double()
        sampleYield = histo.IntegralAndError(1,-1,error)
        samples[sample]=[round(sampleYield,3),round(error.value,3)]
    # Create dataframe containing all the information from the samples.
    dataframe = pd.DataFrame.from_dict(samples,orient='index',columns=['Yield','Stat. Uncertainty'])
    if printToFile:
        # Modify dictionary to set up latex format if needed.
        if latexFormat:
            samplesLatex={}
            for key,val in samples.items():
                samplesLatex[key[:-5]] = '$'+str(round(val[0],3))+' \pm '+str(round(val[1],3))+'$'
            dataframeLatex = pd.DataFrame.from_dict(samplesLatex,orient='index',columns=['Yield + Stat. Uncertainty'])
            dataframeLatex.to_csv(finalStateName+'_latex.csv')
        else :
            dataframe.to_csv(finalStateName+'.csv')
    # Print result on screen.
    for sample in samples:
        print(sample,samples[sample][0],samples[sample][1])



if __name__ == "__main__":
    # Simple menu to ask if printing to file and latex format.
    printToFile = ''
    badAnswer = True 
    while badAnswer:
        print('Print to file (y/n)?')
        printToFile = input()
        if (printToFile=='y' or printToFile=='n'):
            badAnswer = False
    latexFormat = '' # Use latex or not.
    if printToFile == 'y':
        badAnswer = True
        while badAnswer:
            print('Latex format (y/n)?')
            latexFormat = input()
            if (latexFormat=='y' or latexFormat=='n'):
                badAnswer = False
    # Call function with appropiate inputs.
    PrintYields(sys.argv[1],sys.argv[2],sys.argv[3],printToFile=='y',latexFormat=='y')