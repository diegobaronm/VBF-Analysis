from argparse import ArgumentParser
from AnalysisCommons.Run import INFO, WARNING, ERROR
from AnalysisCommons.Systematics import LIST_OF_SYSTEMATICS
import ROOT as r
import os


DEFAULT_PATH_DICT = {
    'Ztm': '../VBFAnalysisPlots/TauMu/Zpeak/Systematics/',
    'Zte': '../VBFAnalysisPlots/EleTau/Zpeak/Systematics/',
    'Ztl': '../VBFAnalysisPlots/TauTau/TauhadTaulep/Systematics/',
    'Zem': '../VBFAnalysisPlots/MuEle/Zpeak/Systematics/',
    'Zmm': '../VBFAnalysisPlots/MuMu/Zpeak/Systematics/',
    'Zee': '../VBFAnalysisPlots/Zee/Zpeak/Systematics/'
}

def get_arguments():
    parser = ArgumentParser(description="Add systematics to a given input file.")
    parser.add_argument("channel1", help="First channel to be added.", type=str)
    parser.add_argument("channel2", help="Second channel to be added.", type=str)
    parser.add_argument("output_path", help="Path to the output ROOT files.", type=str, default=None)
    parser.add_argument("--ch1-path", help="Path to the first channel ROOT files. If not passed the script default value is used.", type=str, default=None)
    parser.add_argument("--ch2-path", help="Path to the second channel ROOT files. If not passed the script default value is used.", type=str, default=None)

    args = parser.parse_args()

    # Perform some checks
    allowed_channels = ['Ztm', 'Zte', 'Zem', 'Zmm', 'Zee', 'Ztl']
    if args.channel1 not in allowed_channels:
        ERROR.log("Channel 1 is not allowed.")
        exit(1)
    if args.channel2 not in allowed_channels:
        ERROR.log("Channel 2 is not allowed.")
        exit(1)
    if args.channel1 == args.channel2:
        ERROR.log("You must provide two different channels.")
        exit(1)

    if args.output_path is None:
        ERROR.log("You must provide an output path.")
        exit(1)

    return args

def adjust_paths(args):
    if args.ch1_path is not None:
        DEFAULT_PATH_DICT[args.channel1] = args.ch1_path
    if args.ch2_path is not None:
        DEFAULT_PATH_DICT[args.channel2] = args.ch2_path

def get_relevant_systematics(args):
    if args.channel1 == 'Ztl' or args.channel2 == 'Ztl': # We have to do some special treatment for the Ztl channel
        return [s for s in LIST_OF_SYSTEMATICS if ('Zte' in s.channels or 'Ztm' in s.channels or args.channel2 in s.channels or args.channel1 in s.channels)]
    return [s for s in LIST_OF_SYSTEMATICS if (args.channel1 in s.channels or args.channel2 in s.channels)]

def make_file_pairs(args):
    # NOTE: This is very hardcoded because in this analysis we only have two systematic samples per-channel.
    # Get systematic files for channel 1 and channel 2
    ch1_files = [file for file in os.listdir(DEFAULT_PATH_DICT[args.channel1]) if (file.endswith('.root') and 'SYS' in file)]
    ch2_files = [file for file in os.listdir(DEFAULT_PATH_DICT[args.channel2]) if (file.endswith('.root') and 'SYS' in file)]

    vbf_1 = [file for file in ch1_files if 'VBF' in file]
    vbf_2 = [file for file in ch2_files if 'VBF' in file]
    qcd_1 = [file for file in ch1_files if 'SherpaNLO' in file]
    qcd_2 = [file for file in ch2_files if 'SherpaNLO' in file]

    if len(vbf_1) != 1 or len(vbf_2) != 1 or len(qcd_1) != 1 or len(qcd_2) != 1:
        ERROR.log("Could not find the systematic files for the provided channels.")
        exit(1)
    
    return [(vbf_1[0], vbf_2[0]), (qcd_1[0], qcd_2[0])]

def process_systematics(systematics_list, args, file1, file2):
    if len(systematics_list) == 0:
        ERROR.log("No systematics to process!")
        exit(1)


    # Open output file
    output_file_name = file1.replace('.root','') + '_plus_' + file2.replace('.root','') + '.root'
    output_file = r.TFile.Open(os.path.join(args.output_path, output_file_name), "RECREATE")

    # Open the input files
    root_file1 = r.TFile.Open(os.path.join(DEFAULT_PATH_DICT[args.channel1], file1))
    root_file2 = r.TFile.Open(os.path.join(DEFAULT_PATH_DICT[args.channel2], file2))

    # First do the NOMINAL histogram
    nominal_histo1 = root_file1.Get('mass_jj_NOMINAL')
    nominal_histo2 = root_file2.Get('mass_jj_NOMINAL')
    if not nominal_histo1 or not nominal_histo2:
        ERROR.log("Could not find NOMINAL histogram in one of the files. Exiting.")
        exit(1)
    nominal_histo1 = r.TH1F(nominal_histo1)
    nominal_histo2 = r.TH1F(nominal_histo2)
    nominal_histo_sum = nominal_histo1.Clone()
    nominal_histo_sum.Add(nominal_histo2)
    nominal_histo_sum.SetName('mass_jj_NOMINAL')
    output_file.WriteTObject(nominal_histo_sum)

    # Now process the systematics
    for i_systematic in systematics_list:
        INFO.log("Processing systematic: ", i_systematic.identifier)

        # Get the histograms from both files
        histo1_name = 'mass_jj_' + i_systematic.histogram_name
        histo1 = root_file1.Get(histo1_name)
        if not histo1:
            WARNING.log("Could not find histogram %s in file %s. Falling back to NOMINAL." % (histo1_name, file1))
            histo1 = root_file1.Get('mass_jj_NOMINAL')
            if not histo1:
                ERROR.log("Could not find NOMINAL histogram in file %s. Exiting." % file1)
                exit(1)

        histo2_name = 'mass_jj_' + i_systematic.histogram_name
        histo2 = root_file2.Get(histo2_name)
        print(histo2)
        if not histo2:
            WARNING.log("Could not find histogram %s in file %s. Falling back to NOMINAL." % (histo2_name, file2))
            histo2 = root_file2.Get('mass_jj_NOMINAL')
            if not histo2:
                ERROR.log("Could not find NOMINAL histogram in file %s. Exiting." % file2)
                exit(1)

        # Convert to TH1F
        histo1 = r.TH1F(histo1)
        histo2 = r.TH1F(histo2)

        # Add the histograms
        histo_sum = histo1.Clone()
        histo_sum.Add(histo2)
        histo_sum.SetName('mass_jj_' + i_systematic.histogram_name)

        # Write the histogram to the output file
        output_file.WriteTObject(histo_sum)
    
    # Close the files
    root_file1.Close()
    root_file2.Close()
    output_file.Close()


def main():
    # Get the script arguments
    args = get_arguments()
    # Adjust the paths if needed and get the file pair
    adjust_paths(args)
    file_pairs = make_file_pairs(args)
    # Get the relevant systematics
    relevant_systematics = get_relevant_systematics(args)

    # Inform the user what will happen
    INFO.log("You are going to add the following channels: ")
    INFO.log(" - Channel 1: "+args.channel1+" from path "+DEFAULT_PATH_DICT[args.channel1])
    INFO.log(" - Channel 2: "+args.channel2+" from path "+DEFAULT_PATH_DICT[args.channel2])
    INFO.log("The following file pairs will be processed: ")
    for fp in file_pairs:
        INFO.log(" - "+fp[0]+" and "+fp[1])
    INFO.log("The output will be saved in: "+args.output_path)
    INFO.log("The following systematics will be considered: ")
    for s in relevant_systematics:
        INFO.log(" - "+s.identifier)

    # Ask for user confirmation
    user_input = input("Do you want to proceed? [y/n]: ")
    if user_input.lower() != 'y':
        INFO.log("Exiting...")
        exit(0)
    
    # Process the systematics for each file pair
    for fp in file_pairs:
        INFO.log("Processing file pair: "+fp[0]+" and "+fp[1])
        process_systematics(relevant_systematics, args, fp[0], fp[1])


if __name__ == "__main__":
    main()
