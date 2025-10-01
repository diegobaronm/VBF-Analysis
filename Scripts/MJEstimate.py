import ROOT as r
from ROOT import gStyle
import numpy as np
import ctypes
import os
from histogramHelpers import dataSubtract, makeNegativeBinsZero, mcAdd, makeSRBinsConsistentWithNOMJ, scaleUncertainty, templatesDict
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger
from HandleIO.CreateListToRun import menu
from AnalysisCommons.Constants import RQCD_VALUE, RQCD_UNCERTAINTY_VALUE, DEFAULT_MJJ_REWEIGHTING
import argparse
Logger.LOGLEVEL = 3

def errorAoverB (histoA,histoB):
    A = histoA.GetBinContent(1)
    B = histoB.GetBinContent(1)
    AError = histoA.GetBinError(1)
    BError = histoB.GetBinError(1)
    return (A/B)*np.sqrt((AError/A)**2+(BError/B)**2)

def errorAoverB (histoA,histoB,binRange):
    AErrorD = ctypes.c_double()
    BErrorD = ctypes.c_double()
    A = histoA.IntegralAndError(binRange[0],binRange[1],AErrorD)
    B = histoB.IntegralAndError(binRange[0],binRange[1],BErrorD)
    AError = AErrorD.value
    BError = BErrorD.value
    
    return (A/B)*np.sqrt((AError/A)**2+(BError/B)**2)

def check_histograms_exist(histogram_name : str, samples : list[str], path_to_check : str) -> str:
    """
    Function to check if the histograms exist in the path.
    Returns histogram_name if histogram is found by the original name in all samples.
    Returns histogram_name+"_basic_all" if the histogram is found by this name in all samples.
    Returns "" if no histogram is found in any of the samples.
    """
    found_in_all = True
    found_in_all_basic = True
    for sample in samples:
        file = r.TFile.Open(path_to_check + sample + ".root")
        histo = file.Get(histogram_name)
        if histo == None:
            found_in_all = False
            histo = file.Get(histogram_name + "_basic_all")
            if histo == None:
                found_in_all_basic = False

    if found_in_all:
        DEBUG.log("Histogram " + histogram_name + " found in all samples.")
        return histogram_name
    elif found_in_all_basic:
        DEBUG.log("Histogram " + histogram_name + "_basic_all found in all samples.")
        return histogram_name + "_basic_all"
    else:
        WARNING.log("Histogram " + histogram_name + " not found in any sample.")
        return ""

def main(base_path, SR_name, CR_name, histogram_dictionary):
    # Define the path to the channel and the directories for the regions.
    channelPath = base_path
    SR = SR_name + "OS/"
    SRSS = SR_name + "SS/"
    CR = CR_name + "OS/"
    CRSS = CR_name + "SS/"

    # Select EWjj and QCDjj samples
    EWjj = "Signal_Sherpa"
    QCDjj = "Ztautau_SherpaNLO" 
    if not os.path.exists(channelPath+SR+QCDjj+"_"+DEFAULT_MJJ_REWEIGHTING+".root"):
        INFO.log("QCDjj sample with default Mjj re-weighting not found. Try sample without re-weighting?")
        try_sample_no_reweighting = menu("Try sample without Mjj re-weighting?",["Yes","No"]) == 1
        if try_sample_no_reweighting:
            if not os.path.exists(channelPath+SR+QCDjj+".root"):
                ERROR.log("QCDjj sample without Mjj re-weighting not found. Exiting.")
                exit(1)
        else:
            ERROR.log("Exiting.")
            exit(1)
    else:
        QCDjj = QCDjj+"_"+DEFAULT_MJJ_REWEIGHTING
   

    CalculateRQCD = menu("Calculate RQCD from n_bjets histogram?",["Yes","No"]) == 1
    ProduceMJFile = menu("Produce MJ.root file?",["Yes","No"]) == 1
    if ProduceMJFile:
        RQCDwithCRs = menu("Calculate RQCD for each histogram from the CRs?",["Yes","No"]) == 1

    # Remove previous MJ.root file if it exists
    samples=[i for i in os.listdir(channelPath+SR) if ('.root' in i and 'Wjets' not in i)]
    if "MJ.root" in samples and not CalculateRQCD:
        INFO.log("Removing previous MJ.root file.")
        os.system("rm "+channelPath+SR+"MJ.root")

    # Preparing the samples that will be used in the data substraction
    histos = histogram_dictionary
    mcSamples = [EWjj,QCDjj]
    backgroundSamples = ['VV',"ttbar",'singletop']#+['Wjets',]
    if ("Tau" in channelPath) or ("MuEle" in channelPath):
        backgroundSamples += ['Higgs','Higgs_truth_EWK','Zjets','W_EWK_Sherpa','VV_EWK']
    mcSamples += backgroundSamples

    # Inform user which samples are being used for data substraction
    INFO.log("Samples being considered for data substraction: ")
    for sample in mcSamples:
        INFO.log(" - " + sample)

    # First evaluate if there is evidence for MJ BG.
    totalMJisZero = False
    nBJetsHistogram = dataSubtract("n_bjets",channelPath+SRSS,"Data",mcSamples,histos,rebin=False)
    totalMJ = nBJetsHistogram.GetBinContent(1)
    totalMJUncertainty = nBJetsHistogram.GetBinError(1)
    if (totalMJ < 0.0) or (totalMJ/totalMJUncertainty < 1.0 ):
        totalMJisZero = True
        WARNING.log("NO MJ EVIDENCE!")
    INFO.log("MJ = " + str(totalMJ) + " +- " + str(totalMJUncertainty))

    if totalMJ < 0.0:
        totalMJ = 0.0

    # Calculate RQCD in MJCRs
    histogramName = "n_bjets"
    # Find object by name
    histogramInfoObject = 0
    for i in histos:
        if i.m_name == histogramName:
            histogramInfoObject = i
            break

    rebinHisto = histogramInfoObject.needsRebin()
    binRange = [1,1]

    if CalculateRQCD:
        INFO.log("Calculating RQCD with histogram: ", histogramName)
        dataSubtractedHistoCR = dataSubtract(histogramName,CR,"Data",mcSamples,histogramInfoObject,rebin=rebinHisto)
        dataSubtractedHistoCRSS = dataSubtract(histogramName,CRSS,"Data",mcSamples,histogramInfoObject,rebin=rebinHisto)
        makeNegativeBinsZero(dataSubtractedHistoCR)
        makeNegativeBinsZero(dataSubtractedHistoCRSS)
        RQCD = dataSubtractedHistoCR.Integral(binRange[0],binRange[1])/dataSubtractedHistoCRSS.Integral(binRange[0],binRange[1])
        RQCDError = errorAoverB(dataSubtractedHistoCR,dataSubtractedHistoCRSS,binRange)
        INFO.log("RQCD = " + str(RQCD) + " +- " + str(RQCDError))


    if ProduceMJFile:
        # Open target file
        multiJetFile = r.TFile.Open(channelPath+SR+"MJ.root", "RECREATE")
        INFO.log("Creating MJ.root file in: ", channelPath+SR)
        for hist in histos:
            INFO.log("========================================================")
            INFO.log("Histogram = " + hist.m_name)
            # Determine if histogram needs to be rebined
            rebinHistogram = hist.needsRebin()
            INFO.log("Rebinning = ", rebinHistogram)
            
            histogram_name_sr = check_histograms_exist(hist.m_name, mcSamples, channelPath+SR)
            if histogram_name_sr == "":
                WARNING.log("Histogram " + hist.m_name + " not found in any sample. Skipping.")
                continue

            # Calculate RQCD in MJCRs
            if RQCDwithCRs:
                INFO.log("Calculating individual RQCD value for this histogram.")
                histogram_name_cr = check_histograms_exist(hist.m_name, mcSamples, channelPath+CR)
                if histogram_name_cr == "":
                    WARNING.log("Histogram " + hist.m_name + " not found in any sample. Skipping.")
                    continue
                dataSubtractedHistoCR = dataSubtract(histogram_name_cr,channelPath+CR,"Data",mcSamples,hist,rebin=rebinHistogram)
                dataSubtractedHistoCRSS = dataSubtract(histogram_name_cr,channelPath+CRSS,"Data",mcSamples,hist,rebin=rebinHistogram)
                makeNegativeBinsZero(dataSubtractedHistoCR)
                makeNegativeBinsZero(dataSubtractedHistoCRSS)
                RQCD = dataSubtractedHistoCR.Integral(1,-1)/dataSubtractedHistoCRSS.Integral(1,-1)
            # If not, use input value
            else:
                INFO.log("Using provided (not calculated) RQCD value.")
                RQCD = RQCD_VALUE
                UncerRQCD = RQCD_UNCERTAINTY_VALUE
                INFO.log("RQCD = " + str(RQCD) + " +- " + str(UncerRQCD))
            
            # Calculate the MJ Background shape
            dataSubtractedHistoSRSS = dataSubtract(histogram_name_sr,channelPath+SRSS,"Data",mcSamples,hist,rebin=rebinHistogram)
            dataSubtractedHistoSRSS.Scale(RQCD)
            makeNegativeBinsZero(dataSubtractedHistoSRSS)
            MJ = dataSubtractedHistoSRSS.Clone()
            
            # If no MJ Evidence fix the bins that are in the final selection
            if totalMJisZero:
                SRhisto = mcAdd(histogram_name_sr,channelPath+SR,backgroundSamples,hist,rebin=rebinHistogram)
                cutLeft = hist.m_leftCut
                cutRight = hist.m_rightCut
                makeSRBinsConsistentWithNOMJ(MJ,cutLeft,cutRight,totalMJ,totalMJUncertainty,SRhisto)
                MJ.Scale(RQCD)
                
            # Take into account the uncertainty in RQCD
            scaleUncertainty(MJ,UncerRQCD/RQCD)
            
            # Save histogram in MJ.root file
            multiJetFile.WriteObject(MJ,histogram_name_sr)
            
        multiJetFile.Close()

if __name__ == "__main__":
    argparser = argparse.ArgumentParser(description="Estimate MJ background in TauHadTauLep channel.")
    argparser.add_argument("base_path", type=str, help="Base path to the channel directory.")
    argparser.add_argument("SR", type=str, help="Name of the signal region.")
    argparser.add_argument("--histo_templates", type=str, help="Name of the histogram templates to use.", default="tautauZpeakHistograms")
    argparser.add_argument("--CR", type=str, help="Path to the control region. Optional, if not provided the code will use predetermined RQCD values.", default="ThisCRDoesNotExist")

    args = argparser.parse_args()

    main(base_path = args.base_path,
         SR_name = args.SR,
         CR_name = args.CR,
         histogram_dictionary = templatesDict[args.histo_templates] )