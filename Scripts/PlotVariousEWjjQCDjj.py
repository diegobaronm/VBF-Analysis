import os

from Plot import Plot, get_args, load_config
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger 
Logger.LOGLEVEL = 3

from Scripts.Plot import get_norm_factors


def main():
    # Get the arguments.
    args = get_args()
    channel = 'Zll'
    yaml_file = args.config_file
    
    QCDjj_suffixes = ['Sherpa','SherpaNLO','MG','MGNLO','PoPy',
                      'Sherpa_RWParabolicCutoff', 'SherpaNLO_RWParabolicCutoff','MG_RWParabolicCutoff','MGNLO_RWParabolicCutoff',
                      'Sherpa_RWExponential', 'SherpaNLO_RWExponential','MG_RWExponential']
    
    if 'SR' in yaml_file:
        QCDjj_suffixes += ['Sherpa_RWParabolic', 'MG_RWParabolic']

    QCDjj_choices = ["%s_%s.root" % (channel, suffix) for suffix in QCDjj_suffixes]
    EWjj_choices = ['Signal_Sherpa.root']
    if 'SR' in yaml_file:
        EWjj_choices += ['Signal_PoPy.root']

    # Loop over all combinations of QCDjj and EWjj samples.
    for qcd_sample in QCDjj_choices:
        for ew_sample in EWjj_choices:

            # Change the configuration file to use the current samples.
            config = load_config(yaml_file)
            config['qcd_sample'] = qcd_sample
            config['signal_sample'] = ew_sample

            if 'SR' in yaml_file:
                norm_factors, post_fit = get_norm_factors(qcd_sample, ew_sample, channel)
                config['qcd_scale'] = norm_factors[0]
                config['vbf_scale'] = norm_factors[1]
                config['is_post_fit'] = post_fit

            INFO.log(f"Running with QCD sample: {qcd_sample} and EW sample: {ew_sample}")
            if post_fit:
                INFO.log(f"Using normalization factors: {norm_factors[0]} for QCD and {norm_factors[1]} for VBF.")
                Plot(args, config, interactive_mode=False)
                INFO.log(f"Plotting also the non-normalised version.")
                config['qcd_scale'] = 1.0
                config['vbf_scale'] = 1.0
                config['is_post_fit'] = False
                Plot(args, config, interactive_mode=False)
                

    INFO.log('All plots generated successfully!')

if __name__ == "__main__":
    main()