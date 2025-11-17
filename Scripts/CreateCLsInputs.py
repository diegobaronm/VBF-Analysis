from histogramHelpers import biner, HistogramInfo, INFO
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

    # Gather the samples
    samples_path = '../VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/BDTZprimeOS'
    Data = "Data.root"
    EWKjj = 'Signal_truth_MG.root'
    QCDjj = 'Ztautau_SherpaNLO_RWParabolicCutoffClosure.root'
    Background = [EWKjj, QCDjj, "VV.root","VV_EWK.root","W_EWK_Sherpa.root","Zjets.root","ttbar.root","singletop.root","MJ.root","Higgs.root"]
    if "MG" not in EWKjj:
        Background.append("Higgs_EWK.root")
    Zprime_Pack = [ i for i in os.listdir(samples_path) if "Zprime_" in i and i.endswith('.root')]
    # Sort the Zprime samples by mass
    Zprime_Pack.sort(key=lambda x: int(x.replace('Zprime_','').replace('.root','')))


    # Get the histogram template
    from histogramHelpers import templatesDict, get_histogram_from_collection
    histogram_template = get_histogram_from_collection('reco_mass_',templatesDict['tautauHighMassHistograms'])
    # Get the SFs
    from Plot import get_norm_factors
    norm_factors, sfs_found = get_norm_factors(QCDjj, EWKjj, channel='Ztautau', sfs_dict='Zll')
    if not sfs_found:
        ERROR.log('Normalization factors not found. Exiting.')
        exit(1)
    qcd_scale, vbf_scale = norm_factors[0], norm_factors[1]
    INFO.log(f'Using VBF scale factor: {vbf_scale}, QCD scale factor: {qcd_scale}')        

    # Build the background
    bkg, bkg_error = build_background(path=samples_path,
                                    samples=Background,
                                    QCDjjSF=qcd_scale,EWKjjSF=vbf_scale,
                                    selection_fn=greater_than_160,
                                    histogram_object=histogram_template)
    INFO.log('Background: %s' % bkg)
    INFO.log('Total background: %s' % np.sum(bkg))
    INFO.log('Background errors: %s' % bkg_error)
    INFO.log('Total background errors: %s' % np.sqrt((bkg_error**2).sum()))

    # Build the signal
    Signal, Signal_error = build_sample(path=samples_path,
                                    sample=Zprime_Pack[0],
                                    QCDjjSF=qcd_scale,EWKjjSF=vbf_scale,
                                    selection_fn=greater_than_160,
                                    histogram_object=histogram_template)
    INFO.log('Signal: %s' % Signal)


    # Create a DataFrame and save it to a csv file
    data_dict = {'Background': bkg, 'BackgroundError': bkg_error}
    for i in Zprime_Pack:
        signal, signal_error = build_sample(path=samples_path,
                                    sample=i,
                                    QCDjjSF=qcd_scale,EWKjjSF=vbf_scale,
                                    selection_fn=greater_than_160,
                                    histogram_object=histogram_template)
        data_dict['Signal'+i.replace('.root','').replace('Zprime_','')] = signal
    df = pd.DataFrame(data_dict)
    df.to_csv('results/CLsInputs_test.csv',index=False)
