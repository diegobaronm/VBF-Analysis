import os

from Plot import Plot, get_args, load_config
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger 
Logger.LOGLEVEL = 3

from Scripts.Plot import get_norm_factors

def get_QCDjj_suffixes(yaml_file_path, channel):
    # List all the contents and extract the root files.
    base_path = os.path.dirname(yaml_file_path)
    root_files = [f for f in os.listdir(base_path) if f.endswith('.root')]

    # Filter the ones that match the channel pattern.
    qcd_files = [f for f in root_files if f.startswith(channel) and 'Signal' not in f]

    return root_files, qcd_files

def main():
    # Get the arguments.
    args = get_args()
    channel = 'Zmumu'
    yaml_file = args.config_file

    root_files, QCDjj_choices = get_QCDjj_suffixes(yaml_file, channel)

    EWjj_choices = ['Signal_Sherpa.root']
    if 'Signal_PoPy.root' in root_files:
        EWjj_choices += ['Signal_PoPy.root']

    # Infor the user the combinations to be run.
    INFO.log(f"Found {len(QCDjj_choices)} QCDjj samples: {QCDjj_choices}")
    INFO.log(f"Found {len(EWjj_choices)} EWjj samples: {EWjj_choices}")
    INFO.log(f"Will run a total of {len(QCDjj_choices) * len(EWjj_choices)} combinations.")
    # Show thenm the combinations.
    for qcd_sample in QCDjj_choices:
        for ew_sample in EWjj_choices:
            INFO.log(f"Combination: QCD: {qcd_sample}, EW: {ew_sample}")

    # Loop over all combinations of QCDjj and EWjj samples.
    config = load_config(yaml_file)
    for qcd_sample in QCDjj_choices:
        for ew_sample in EWjj_choices:

            # Change the configuration file to use the current samples.
            config['qcd_sample'] = qcd_sample
            config['signal_sample'] = ew_sample
      
            norm_factors, post_fit = get_norm_factors(qcd_sample, ew_sample, channel)
            config['qcd_scale'] = norm_factors[0]
            config['vbf_scale'] = norm_factors[1]
            config['is_post_fit'] = post_fit

            # Plot with the scaling factors.
            INFO.log(f"Using normalization factors: {norm_factors[0]} for QCD and {norm_factors[1]} for VBF.")
            Plot(args, config, interactive_mode=False)

            # Plot without the scaling factors.
            if post_fit:
                INFO.log(f"Plotting also the non-normalised version.")
                config['qcd_scale'] = 1.0
                config['vbf_scale'] = 1.0
                config['is_post_fit'] = False
                Plot(args, config, interactive_mode=False)

            # Finish the combination.
            INFO.log(f"Finished combination: QCD: {qcd_sample}, EW: {ew_sample}")
                

    INFO.log('All plots generated successfully!')

if __name__ == "__main__":
    main()