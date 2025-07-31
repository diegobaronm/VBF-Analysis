import os

from Plot import Plot, get_args, load_config
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger 
Logger.LOGLEVEL = 3

NORM_FACTORS_DICT = { # Always QCDjj_EWjj : [qcd, vbf]
    'Sherpa_RWParabolicCutoff_Sherpa' : [0.942, 1.170],
    'MG_RWParabolicCutoff_Sherpa' : [0.943, 1.102],
    'SherpaNLO_RWParabolicCutoff_Sherpa' : [1.000, 0.982],
    'MGNLO_RWParabolicCutoff_Sherpa' : [0.953, 1.309],
    'Sherpa_RWExponential_Sherpa' : [0.937, 1.182],
    'MG_RWExponential_Sherpa' : [0.935, 1.130],
    'SherpaNLO_RWExponential_Sherpa' : [0.993, 1.006],
    'Sherpa_RWParabolic_Sherpa' : [0.942, 1.170],
    'MG_RWParabolic_Sherpa' : [0.943, 1.104],
    'Sherpa_RWParabolicCutoff_PoPy' : [0.962, 0.999],
    'MG_RWParabolicCutoff_PoPy' : [0.961, 0.947],
    'SherpaNLO_RWParabolicCutoff_PoPy' : [1.017, 0.843],
    'MGNLO_RWParabolicCutoff_PoPy' : [0.974, 1.127],
    'Sherpa_RWExponential_PoPy' : [0.962, 0.999],
    'MG_RWExponential_PoPy' : [0.961, 0.947],
    'SherpaNLO_RWExponential_PoPy' : [1.017, 0.843],
    'Sherpa_RWParabolic_PoPy' : [0.962, 0.999],
    'MG_RWParabolic_PoPy' : [0.961, 0.947],
}

def get_norm_factors(qcd_sample, ew_sample, channel):
    # Remove the `.root` extension from the sample names.
    qcd_sample = qcd_sample.replace('.root', '')
    ew_sample = ew_sample.replace('.root', '')
    # Remove the channel prefix for QCD samples.
    qcd_sample = qcd_sample.replace(f"{channel}_", '')
    # Remove the `Signal_` prefix for EW samples.
    ew_sample = ew_sample.replace('Signal_', '')

    # For not RW samples, return the default normalization factors.
    if 'RW' not in qcd_sample:
        return [1.0, 1.0], False  # Default normalization factors if no RW is used.

    try:
        norm_factors = NORM_FACTORS_DICT["%s_%s" % (qcd_sample, ew_sample)]
    except KeyError:
        ERROR.log(f"Normalization factors not found for {qcd_sample} and {ew_sample}.")
        exit(1)

    return norm_factors, True


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