import os

from Plot import Plot, get_args, load_config
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger 
Logger.LOGLEVEL = 3

def main():
    # Get the arguments.
    args = get_args()
    yaml_file = args.config_file
    
    QCDjj_suffixes = ['Sherpa','SherpaNLO','MG','MGNLO','PoPy',
                      'Sherpa_RWParabolicCutoff', 'SherpaNLO_RWParabolicCutoff','MG_RWParabolicCutoff','MGNLO_RWParabolicCutoff',
                      'Sherpa_RWExponential', 'SherpaNLO_RWExponential','MG_RWExponential']
    
    if 'SR' in yaml_file:
        QCDjj_suffixes += ['Sherpa_RWParabolic', 'MG_RWParabolic']

    channel = 'Zmumu'
    QCDjj_choices = ["%s_%s.root" % (channel, suffix) for suffix in QCDjj_suffixes]
    EWjj_choices = ['Signal_Sherpa.root']

    # Loop over all combinations of QCDjj and EWjj samples.
    for qcd_sample in QCDjj_choices:
        for ew_sample in EWjj_choices:

            # Change the configuration file to use the current samples.
            config = load_config(yaml_file)
            config['qcd_sample'] = qcd_sample
            config['signal_sample'] = ew_sample

            INFO.log(f"Running with QCD sample: {qcd_sample} and EW sample: {ew_sample}")
            Plot(args, config, interactive_mode=False)

    INFO.log('All plots generated successfully!')

if __name__ == "__main__":
    main()