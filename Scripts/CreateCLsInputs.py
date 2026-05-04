from histogramHelpers import biner, HistogramInfo, INFO, ERROR
import argparse
import ROOT as r
import os
import numpy as np
import pandas as pd
import yaml

REQUIRED_CONFIG_KEYS = ('output_file', 'samples_path', 'EWKjj', 'QCDjj', 'Backgrounds', 'SFs_qcd_ewk', 'histogram_template')


def load_configurations(config_file):
    if not os.path.isfile(config_file):
        ERROR.log('Configuration file %s not found!' % config_file)
        exit(1)

    with open(config_file) as file:
        INFO.log('Loading configuration file ----> %s' % config_file)
        configurations = yaml.load(file, Loader=yaml.FullLoader)

    if isinstance(configurations, dict):
        configurations = [configurations]

    if not isinstance(configurations, list) or len(configurations) == 0:
        ERROR.log('Configuration file %s must contain at least one configuration entry.' % config_file)
        exit(1)

    return configurations, os.path.dirname(os.path.abspath(config_file))


def validate_configuration(configuration, index):
    missing_keys = [key for key in REQUIRED_CONFIG_KEYS if key not in configuration]
    if missing_keys:
        ERROR.log('Configuration entry %d is missing required keys: %s' % (index, ', '.join(missing_keys)))
        exit(1)

    if not isinstance(configuration['Backgrounds'], list):
        ERROR.log('Configuration entry %d has an invalid Backgrounds value. Expected a list.' % index)
        exit(1)


def resolve_config_path(config_dir, path):
    if os.path.isabs(path):
        return path
    return os.path.normpath(os.path.join(config_dir, path))


def parse_args():
    parser = argparse.ArgumentParser(description='Create CLs input CSV files from a YAML configuration.')
    parser.add_argument('config', type=str, help='Path to the YAML configuration file.')
    return parser.parse_args()

def build_sample(path, sample, QCDjjSF, EWKjjSF, selection_fn, histogram_object):
    INFO.log('Processing sample: %s' % sample)
    file_path = os.path.join(path, sample)
    file = r.TFile.Open(file_path, "R")
    if not file or file.IsZombie():
        ERROR.log('Failed to open file %s' % file_path)
        exit(1)


    HISTOGRAM_NAME = configuration['histogram_template']
    histogram = file.Get(HISTOGRAM_NAME)
    if not histogram:
        file.Close()
        ERROR.log('Histogram %s not found in file %s' % (HISTOGRAM_NAME, file_path))
        exit(1)

    histogram = histogram.Clone('%s_%s' % (histogram.GetName(), sample.replace('.root', '')))
    histogram.SetDirectory(0)
    file.Close()

    if "Signal" in sample:
        histogram.Scale(EWKjjSF)
    if "Ztautau_" in sample:
        histogram.Scale(QCDjjSF)

    if histogram_object.needsRebin():
        bin_edges = configuration.get('bin_edges', None)
        if bin_edges is None:
            rebining = biner(histogram_object.m_binEdges,histogram_object.m_binSteps,histogram)
        else:
            rebining = np.array(bin_edges)
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


def build_cls_inputs(configuration, config_dir, histogram_template):
    samples_path = resolve_config_path(config_dir, configuration['samples_path'])
    output_file = resolve_config_path(config_dir, configuration['output_file'])
    ewkjj_sample = configuration['EWKjj']
    qcdjj_sample = configuration['QCDjj']
    background_samples = [ewkjj_sample, qcdjj_sample] + list(configuration['Backgrounds'])

    if not os.path.isdir(samples_path):
        ERROR.log('Samples path %s not found!' % samples_path)
        exit(1)

    if 'MG' not in ewkjj_sample and 'Higgs_EWK.root' not in background_samples:
        background_samples.append('Higgs_EWK.root')

    zprime_pack = [sample for sample in os.listdir(samples_path) if ('Zprime_' in sample or 'Zp' in sample) and sample.endswith('.root')]
    zprime_pack.sort(key=lambda sample: int(sample.replace('Zprime_', '').replace('Zp', '').replace('.root', '')))

    if len(zprime_pack) == 0:
        ERROR.log('No Zprime samples found in %s' % samples_path)
        exit(1)

    qcd_sfs_sample = configuration['SFs_qcd_ewk'][0]
    ewk_sfs_sample = configuration['SFs_qcd_ewk'][1]
    norm_factors, sfs_found = get_norm_factors(qcd_sfs_sample, ewk_sfs_sample, channel='Ztautau', sfs_dict='Zll')
    if not sfs_found:
        ERROR.log('Normalization factors not found. Exiting.')
        exit(1)

    qcd_scale, vbf_scale = norm_factors[0], norm_factors[1]
    INFO.log('Using samples path: %s' % samples_path)
    INFO.log('Writing output to: %s' % output_file)
    INFO.log(f'Using VBF scale factor: {vbf_scale}, QCD scale factor: {qcd_scale}')

    bkg, bkg_error = build_background(path=samples_path,
                                    samples=background_samples,
                                    QCDjjSF=qcd_scale,EWKjjSF=vbf_scale,
                                    selection_fn=greater_than_160,
                                    histogram_object=histogram_template)
    INFO.log('Background: %s' % bkg)
    INFO.log('Total background: %s' % np.sum(bkg))
    INFO.log('Background errors: %s' % bkg_error)
    INFO.log('Total background errors: %s' % np.sqrt((bkg_error**2).sum()))

    data_dict = {'Background': bkg, 'BackgroundError': bkg_error}
    for sample in zprime_pack:
        signal, signal_error = build_sample(path=samples_path,
                                    sample=sample,
                                    QCDjjSF=qcd_scale,EWKjjSF=vbf_scale,
                                    selection_fn=greater_than_160,
                                    histogram_object=histogram_template)
        data_dict['Signal'+sample.replace('.root','').replace('Zprime_','')] = signal

    output_dir = os.path.dirname(output_file)
    if output_dir:
        os.makedirs(output_dir, exist_ok=True)

    df = pd.DataFrame(data_dict)
    df.to_csv(output_file, index=False)
    INFO.log('Saved CLs inputs to %s' % output_file)
    
if __name__ == '__main__':
    args = parse_args()
    configurations, config_dir = load_configurations(args.config)

    for index, configuration in enumerate(configurations, start=1):
        validate_configuration(configuration, index)

    # Get the histogram template
    from histogramHelpers import templatesDict, get_histogram_from_collection
    histogram_template = get_histogram_from_collection('reco_mass_',templatesDict['tautauHighMassHistograms'])

    # Get the SFs
    from Plot import get_norm_factors

    for configuration in configurations:
        build_cls_inputs(configuration, config_dir, histogram_template)
