import ROOT as r
from ROOT import gStyle
import numpy as np
import ctypes
import os
from histogramHelpers import tautauInclusiveHistograms,tautauHighMassHistograms,tautauHighMassMJHistograms,emuHighMassHistograms,tautauZpeakHistograms,tautauHiggsBDTHistograms,tautauHiggsHistograms, tautauHighMassCutBasedHistograms, tautauHighMassTightTauHistograms
from histogramHelpers import dataSubtract, makeNegativeBinsZero, mcAdd, makeSRBinsConsistentWithNOMJ, scaleUncertainty
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger
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

def main(base_path, SR_name, CR_name, histogram_dictionary):
    # Define the path to the channel and the directories for the regions.
    channelPath = base_path
    SR = SR_name + "OS/"
    SRSS = SR_name + "SS/"
    CR = CR_name + "OS/"
    CRSS = CR_name + "SS/"

    # Select EWjj and QCDjj samples
    EWjj = "Signal_Sherpa"
    QCDjj = "Ztautau_SherpaRW"

    RQCDwithCRs = False
    CalculateRQCD = False

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
        backgroundSamples += ['Higgs','Zjets','W_EWK_Sherpa','VV_EWK']
    mcSamples += backgroundSamples
    INFO.log("Samples being considered for data substraction: ", mcSamples)

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
        dataSubtractedHistoCR = dataSubtract(histogramName,channelPath+CR,"Data",mcSamples,histogramInfoObject,rebin=rebinHisto)
        dataSubtractedHistoCRSS = dataSubtract(histogramName,channelPath+CRSS,"Data",mcSamples,histogramInfoObject,rebin=rebinHisto)
        makeNegativeBinsZero(dataSubtractedHistoCR)
        makeNegativeBinsZero(dataSubtractedHistoCRSS)
        RQCD = dataSubtractedHistoCR.Integral(binRange[0],binRange[1])/dataSubtractedHistoCRSS.Integral(binRange[0],binRange[1])
        RQCDError = errorAoverB(dataSubtractedHistoCR,dataSubtractedHistoCRSS,binRange)
        
        INFO.log("RQCD = " + str(RQCD) + " +- " + str(RQCDError))


    # Open target file
    multiJetFile = r.TFile.Open(channelPath+SR+"MJ.root", "RECREATE")
    INFO.log("Creating MJ.root file in: ", channelPath+SR)
    for hist in histos:
        INFO.log("========================================================")
        INFO.log("Histogram = " + hist.m_name)

        # Determine if histogram needs to be rebined
        rebinHistogram = hist.needsRebin()
        INFO.log("Rebinning = ", rebinHistogram)
        
        # Calculate RQCD in MJCRs
        if RQCDwithCRs:
            # Calculate RQCD
            dataSubtractedHistoCR = dataSubtract(hist.m_name,channelPath+CR,"Data",mcSamples,hist,rebin=rebinHistogram)
            dataSubtractedHistoCRSS = dataSubtract(hist.m_name,channelPath+CRSS,"Data",mcSamples,hist,rebin=rebinHistogram)
            makeNegativeBinsZero(dataSubtractedHistoCR)
            makeNegativeBinsZero(dataSubtractedHistoCRSS)
            RQCD = dataSubtractedHistoCR.Integral(1,-1)/dataSubtractedHistoCRSS.Integral(1,-1)
        # If not, use input value
        else:
            INFO.log("Using provided (not calculated) RQCD value.")
            # RQCD =  1.26  +-  0.25 -> High mass region enhanced in MJ and loose jet cuts.
            # RQCD = 1.3 +- 0.25 -> Standard used in thesis version of the analysis.
            RQCD = 1.26#1.3*0.12
            UncerRQCD = 0.25#1.2*0.25
            INFO.log("RQCD = " + str(RQCD) + " +- " + str(UncerRQCD))
        
        # Calculate the MJ Background shape
        dataSubtractedHistoSRSS = dataSubtract(hist.m_name,channelPath+SRSS,"Data",mcSamples,hist,rebin=rebinHistogram)
        dataSubtractedHistoSRSS.Scale(RQCD)
        makeNegativeBinsZero(dataSubtractedHistoSRSS)
        MJ = dataSubtractedHistoSRSS.Clone()
        
        # If no MJ Evidence fix the bins that are in the final selection
        if totalMJisZero:
            SRhisto = mcAdd(hist.m_name,channelPath+SR,backgroundSamples,hist,rebin=rebinHistogram)
            cutLeft = hist.m_leftCut
            cutRight = hist.m_rightCut
            makeSRBinsConsistentWithNOMJ(MJ,cutLeft,cutRight,totalMJ,totalMJUncertainty,SRhisto)
            MJ.Scale(RQCD)
            
        # Take into account the uncertainty in RQCD
        scaleUncertainty(MJ,UncerRQCD/RQCD)
        
        # Save histogram in MJ.root file
        multiJetFile.WriteObject(MJ,hist.m_name)
        
    multiJetFile.Close()

if __name__ == "__main__":
    main(base_path = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/",
         SR_name = "FailedAnyHM",
         CR_name = "FailedAnyHM",
         histogram_dictionary = tautauHighMassTightTauHistograms )