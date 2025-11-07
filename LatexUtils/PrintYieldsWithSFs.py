
from ctypes import c_double
import pandas as pd
import numpy as np
import ROOT as r
from uncertainties import ufloat

def main():
    # Take parameters from outside
    global samplesPath, histogramName, samples, channel, outputFileName, sf_dict

    for sampleName in samples.keys():
        # Zero jets in the gap region BIN
        try:
            file = r.TFile.Open(samplesPath+sampleName+".root","READ")
        except OSError:
            print(f"Warning: File for sample '{sampleName}' not found at {samplesPath+sampleName+'.root'}. Setting yield to 0.")
            samples[sampleName] = {"Yield":0,"Stat":0}
            continue
        histogram = file.Get(histogramName)
        zeroGapJets = histogram.GetBinContent(1)
        zeroGapJetsE = np.sqrt(histogram.GetBinError(1)**2)
        zeroGapJetsYield = ufloat(zeroGapJets,zeroGapJetsE)
        try:
            if sampleName in sf_dict.keys():
                zeroGapJetsYield *= sf_dict[sampleName]
        except KeyError:
            pass
        file.Close()
        samples[sampleName] = {"Yield":round(zeroGapJetsYield.n,1),"Stat":round(zeroGapJetsYield.s,1)}


    

    # Calculate the total MC yield and uncertainty
    totalMC = ufloat(0,0)
    for sampleName in samples.keys():
        if "Data" in sampleName:
            continue
        if "Signal_PoPy" in sampleName:
            continue
        if "MGNLO" in sampleName:
            continue

        totalMC += ufloat(samples[sampleName]["Yield"],samples[sampleName]["Stat"])

    samples["Total MC"] = {"Yield":round(totalMC.n,1),"Stat":round(totalMC.s,1)}

    table  = pd.DataFrame.from_dict(samples,orient='index',columns=['Yield',"Stat"])

    # Create Latex format
    latex = {}
    for sampleName in samples.keys():
        latexString = "$"+str(samples[sampleName]["Yield"])+" \pm "+str(samples[sampleName]["Stat"])+"$"
        latex[sampleName] = latexString 
    latexTable  = pd.DataFrame.from_dict(latex,orient='index',columns=["LatexFormat"])
    latexTable.to_csv(outputFileName)



if __name__ == "__main__":
    # Script parameters
    samplesPath = "../VBFAnalysisPlots/TauTau/Zpeak/BDTOS/"
    channel = "Ztautau"
    samples = {"Data":0.0,"Signal_Sherpa":0.0,"Signal_PoPy":0.0,channel+"_MGNLO_RWParabolicCutoffClosure":0.0,
            channel+"_SherpaNLO_RWParabolicCutoffClosure":0.0,"Higgs":0.0,"ttbar":0.0,"singletop":0.0,"VV":0.0,
            "Wjets":0.0,"Zjets":0.0,"MJ":0.0,"VV_EWK":0.0,"W_EWK_Sherpa":0.0,"Higgs_truth_EWK":0.0}
    sf_dict = {
        #"Signal_Sherpa":ufloat(0.923,0.040),
        "Zll_SherpaNLO_RWParabolicCutoffClosure":ufloat(1.011,0.009),
        "Signal_Sherpa":ufloat(0.87,0.253), # Ztautau
        "Ztautau_SherpaNLO_RWParabolicCutoffClosure":ufloat(1.071,0.118),
    }
    histogramName = "n_bjets"
    outputFileName = "YieldsWithSFs_"+channel+".csv"

    print("Info:: Using SFs only for samples: ",list(sf_dict.keys()))

    # Run
    main()