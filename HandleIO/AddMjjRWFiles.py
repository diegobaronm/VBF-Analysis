import os
from argparse import ArgumentParser

from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger
Logger.LOGLEVEL = 3

BASE_PATH = '/data/dbaronmo/Chicago_VBF_Outputs/'
DICT_PATH_SUFFIX = {
    BASE_PATH + '/Zee/CRa_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zee/CRb_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zee/CRc_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zee/SR_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zmm/CRa_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zmm/CRb_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zmm/CRc_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    BASE_PATH + '/Zmm/SR_ParabolicCutoffClosure/NOMINAL/': 'RWParabolicCutoffClosure',
    
    BASE_PATH + '/Zee/CRa_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zee/CRb_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zee/CRc_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zee/SR_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zmm/CRa_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zmm/CRb_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zmm/CRc_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',
    BASE_PATH + '/Zmm/SR_ParabolicCutoff/NOMINAL/': 'RWParabolicCutoff',

    BASE_PATH + '/Zee/CRa_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zee/CRb_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zee/CRc_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zee/SR_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zmm/CRa_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zmm/CRb_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zmm/CRc_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
    BASE_PATH + '/Zmm/SR_ExponentialClosure/NOMINAL/': 'RWExponentialClosure',
}

DICT_OUTPUT_INPUT_STRINGS = {
    'channel_Sherpa' : 'channel_sherpa*',
    'channel_MGNLO' : 'channel_MGNLO*',
    'channel_MG' : 'channel_MG[!NLO]*',
    'channel_SherpaNLO' : 'channel_SherpaNLO*',
}

DICT_CHECK_SAMPLE_EXISTS = {
    'channel_Sherpa' : 'channel_sherpa1_2018_0NOMINAL.root',
    'channel_MGNLO' : 'channel_MGNLO1_2018_0NOMINAL.root',
    'channel_MG' : 'channel_MG1_2018_0NOMINAL.root',
    'channel_SherpaNLO' : 'channel_SherpaNLO1_2018_0NOMINAL.root',
}

def create_parser():
    parser = ArgumentParser(description="Add Mjj RW files located in the specified directories.")
    parser.add_argument('output', type=str, help='Path where the results will be saved.')

    args = parser.parse_args()
    return args

def hadd_sample(input_path, output_path, input_string, output_string):
    if not os.path.exists(input_path):
        WARNING.log(f"Input path {input_path} does not exist. Skipping hadd operation.")
        return

    if not os.path.exists(output_path):
        INFO.log(f"Creating output directory {output_path}.")
        DEBUG.log(f"Command to create directory: mkdir -p {output_path}")
        os.system(f"mkdir -p {output_path}")

    INFO.log(f"Hadding files from {input_path} to {output_path}. Using input pattern: {input_string} and output pattern: {output_string}.")
    cmd = f"hadd -f {output_path}/{output_string} {input_path}/{input_string}"
    output = os.system(cmd)
    DEBUG.log(f"Command executed: {cmd}")
    if output != 0:
        ERROR.log(f"Error while hadding files.")
    else:
        INFO.log(f"Successfully hadded files!")

def get_channel_prefix(input_path):
    if 'Zee' in input_path:
        return 'Zee'
    elif 'Zmm' in input_path:
        return 'Zmumu'
    else:
        ERROR.log(f"Unknown channel in input path: {input_path}. Please check the path.")
        exit(1)
    
def get_region(input_path):
    if 'CRa' in input_path:
        return 'CRa'
    elif 'CRb' in input_path:
        return 'CRb'
    elif 'CRc' in input_path:
        return 'CRc'
    elif 'SR' in input_path:
        return 'SR'
    else:
        ERROR.log(f"Unknown region in input path: {input_path}. Please check the path.")
        exit(1)

def main():
    # Get CLI arguments
    args = create_parser()

    for input_path, rw_suffix in DICT_PATH_SUFFIX.items():
        base_output_path = args.output
        channel = get_channel_prefix(input_path)
        region = get_region(input_path)
        
        for output_string, input_string in DICT_OUTPUT_INPUT_STRINGS.items():
            output_path_directory = os.path.join(base_output_path, channel, region)
            output_name = output_string.replace('channel', channel) + f'_{rw_suffix}.root'

            input_path_directory = input_path
            input_name = input_string.replace('channel', channel) + '.root'

            # Before hadding, check if the sample exists and if not skip it
            check_sample = DICT_CHECK_SAMPLE_EXISTS[output_string].replace('channel', channel)
            if not os.path.exists(os.path.join(input_path_directory, check_sample)):
                WARNING.log(f"Sample {check_sample} does not exist in {input_path_directory}. Skipping hadd operation.")
                continue
            
            hadd_sample(input_path_directory, output_path_directory, input_name, output_name)

if __name__ == "__main__":
    main()
