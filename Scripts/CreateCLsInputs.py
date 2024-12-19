from histogramHelpers import biner,HistogramInfo, INFO
import ROOT as r
import os
import numpy as np
import pandas as pd

HISTOGRAM_NAME = 'reco_mass_'

def build_sample(path, sample, QCDjjSF, EWKjjSF, selection_fn, histogram_object):

    INFO.log('Processing sample: %s' % sample)
    file = r.TFile.Open(os.path.join(path,sample),"R")
    histogram = file.Get(HISTOGRAM_NAME)

    if "Signal" in sample:
        histogram.Scale(EWKjjSF)
    if "Ztautau_" in sample:
        histogram.Scale(QCDjjSF)

    if histogram_object.needsRebin():
        rebining = biner(histogram_object.m_binEdges,histogram_object.m_binSteps,histogram)
        nb = len(rebining)-1
        histogram = histogram.Rebin(nb,sample,rebining)

    bin_content = []
    bin_content_uncer = []
    for i in range(1,histogram.GetNbinsX()+1):
        if selection_fn(histogram.GetBinCenter(i)):
            bin_content.append(histogram.GetBinContent(i))
            bin_content_uncer.append(histogram.GetBinError(i))

    return np.array(bin_content), np.array(bin_content_uncer)


def build_background(path, samples, QCDjjSF, EWKjjSF, selection_fn, histogram_object):
    bkg_values, bkg_errors = build_sample(path, samples[0], QCDjjSF, EWKjjSF, selection_fn, histogram_object)
    
    for sample in samples[1:]:
        value, error = build_sample(path, sample, QCDjjSF, EWKjjSF, selection_fn, histogram_object)

        bkg_values += value
        bkg_errors = np.sqrt(bkg_errors**2 + error**2)

    return bkg_values, bkg_errors

def greater_than_160(bin_center):
    return bin_center > 160
    
if __name__ == '__main__':
    Data = "Data.root"
    EWKjj = 'Signal_Sherpa.root'
    QCDjj = 'Ztautau_SherpaRW.root'

    Background = [EWKjj, QCDjj, "VV.root","VV_EWK.root","W_EWK_Sherpa.root","Zjets.root","ttbar.root","singletop.root","MJ.root","Higgs.root"]
    Zprime_Pack = ["Zprime_200.root","Zprime_250.root","Zprime_300.root","Zprime_350.root","Zprime_400.root","Zprime_450.root","Zprime_500.root"]

    bkg, bkg_error = build_background(path='/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/NewBDTTightTauOS',
                                    samples=Background,
                                    QCDjjSF=0.92,EWKjjSF=1.121,
                                    selection_fn=greater_than_160,
                                    histogram_object=HistogramInfo('reco_mass_', [66, 81, 101, 116, 160, 250, 500], [66, 15, 10, 15, 11, 30, 125, 250], 10, 'm_{#tau,l}',160,1000,'GeV',True))

    INFO.log('Background: %s' % bkg)
    INFO.log('Total background: %s' % np.sum(bkg))
    INFO.log('Background errors: %s' % bkg_error)
    INFO.log('Total background errors: %s' % np.sqrt((bkg_error**2).sum()))

    Signal, Signal_error = build_sample(path='/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/NewBDTTightTauOS',
                                    sample=Zprime_Pack[0],
                                    QCDjjSF=0.92,EWKjjSF=1.121,
                                    selection_fn=greater_than_160,
                                    histogram_object=HistogramInfo('reco_mass_', [66, 81, 101, 116, 160, 250, 500], [66, 15, 10, 15, 11, 30, 125, 250], 10, 'm_{#tau,l}',160,1000,'GeV',True))
    
    INFO.log('Signal: %s' % Signal)


    # Create a DataFrame and save it to a csv file
    data_dict = {'Background': bkg, 'BackgroundError': bkg_error}
    for i in Zprime_Pack:
        signal, signal_error = build_sample(path='/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/NewBDTTightTauOS',
                                    sample=i,
                                    QCDjjSF=0.92,EWKjjSF=1.121,
                                    selection_fn=greater_than_160,
                                    histogram_object=HistogramInfo('reco_mass_', [66, 81, 101, 116, 160, 250, 500], [66, 15, 10, 15, 11, 30, 125, 250], 10, 'm_{#tau,l}',160,1000,'GeV',True))
        data_dict['Signal'+i.replace('.root','').replace('Zprime_','')] = signal
    df = pd.DataFrame(data_dict)
    df.to_csv('CLsInputs.csv',index=False)
