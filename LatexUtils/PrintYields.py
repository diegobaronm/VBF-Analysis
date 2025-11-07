import ROOT as r
import ctypes 
import pandas as pd
import sys
import os

def PrintYields(finalStateName,histogram,path,printToFile=True,latexFormat=False):
    # Create a list with the .root files excluding MC.root and BG.root files
    finalStateSamples = [os.path.abspath(os.path.join(path, i)) for i in os.listdir(path) if (('root' in i) and ('MC' not in i) and ('BG' not in i) and ('Average' not in i) )]
    # Create dictionary 
    samples = {}
    # Loop over the samples and calculate integral and error.
    for sample in finalStateSamples:
        file = r.TFile.Open(sample)
        histo = file.Get(histogram)
        error = ctypes.c_double()
        if not histo or not isinstance(histo, r.TH1):
            print(f"Warning: Histogram '{histogram}' not found or is not a TH1 in file {os.path.basename(sample)}. Setting yield to 0.")
            sampleYield = 0.0
            error.value = 0.0
        else:
            sampleYield = histo.IntegralAndError(1,-1,error)
        samples[os.path.basename(sample)]=[round(sampleYield,1),round(error.value,1)]
    # Create dataframe containing all the information from the samples.
    dataframe = pd.DataFrame.from_dict(samples,orient='index',columns=['Yield','Stat. Uncertainty'])
    if printToFile:
        # Modify dictionary to set up latex format if needed.
        if latexFormat:
            samplesLatex={}
            for key,val in samples.items():
                samplesLatex[key[:-5]] = '$'+str(round(val[0],1))+' \pm '+str(round(val[1],1))+'$'
            dataframeLatex = pd.DataFrame.from_dict(samplesLatex,orient='index',columns=['Yield + Stat. Uncertainty'])
            dataframeLatex.to_csv(finalStateName+'_latex.csv')
        else :
            dataframe.to_csv(finalStateName+'.csv')
    # Print result on screen.
    for sample in samples:
        print(os.path.basename(sample),' ---> ',samples[sample][0],samples[sample][1])

def get_args():
    import argparse
    parser = argparse.ArgumentParser(description='Print Yields from root files.')
    parser.add_argument('finalStateName', type=str, help='Name of the final state.')
    parser.add_argument('histogram', type=str, help='Name of the histogram to integrate.')
    parser.add_argument('path', type=str, help='Path to the directory containing the root files.')
    return parser.parse_args()

if __name__ == "__main__":
    # Get arguments from command line.
    args = get_args()

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
    PrintYields(args.finalStateName,args.histogram,args.path,printToFile=='y',latexFormat=='y')