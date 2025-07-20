import ROOT as r
from argparse import ArgumentParser
import os

from AnalysisCommons.Run import DEBUG, INFO, ERROR, WARNING, Logger
Logger.LOGLEVEL = 3


def return_channel_metadata(channel_string):
    if channel_string == "ee":
        from AnalysisCommons.Metadata.datasetsZee import dataCombos, dirs, dataSets
        return dirs, dataCombos, dataSets
    elif channel_string == "mm":
        from AnalysisCommons.Metadata.datasetsZmumu import dataCombos, dirs, dataSets
        return dirs, dataCombos, dataSets
    elif channel_string == "tautau":
        from AnalysisCommons.Metadata.datasetsTauTau import dataCombos, dirs, dataSets
        return dirs, dataCombos, dataSets
    else:
        ERROR.log(f"Channel {channel_string} not recognized. Please choose from 'ee', 'mm', or 'tautau'.")
        exit(1)

def create_cli_args():
    parser = ArgumentParser(description="Check that the input files are present and valid.")
    parser.add_argument("--channel", type=str, default=None, choices=["ee", "mm","tautau"], help="Channel to check from the available options: ee, mm, tautau.")
    parser.add_argument("--tree", type=str, default="NOMINAL", help="Name of the tree to check in the input files.")
    parser.add_argument("--path", type=str, default=None, help="Path to the input files. If not provided, it will use the default path for the specified channel.")

    args = parser.parse_args()

    return args

def check_input_file(file_path, tree_name):
    try:
        file = r.TFile(file_path, "READ")
        if not file.IsOpen():
            ERROR.log(f"File {file_path} could not be opened.")
        tree = file.Get(tree_name)
        if not tree:
            ERROR.log(f"Tree {tree_name} not found in file {file_path}.")
        n_entries = tree.GetEntriesFast()
        DEBUG.log(f"File {file_path} has {n_entries} entries in tree {tree_name}.")
        INFO.log(f"File {file_path} and tree {tree_name} are valid.")
    except Exception as e:
        ERROR.log(f"An error occurred while checking file {file_path}: {str(e)}")
    
# This function also returns the samples not found.
def check_samples(dirs, dataCombos, dataSets, tree_name):
    combos_with_missing_samples = []  # To keep track of combos with missing samples
    missing_samples = []  # To keep track of missing samples
    # Loop through all the combos.
    for icombo in dataCombos:
        INFO.log(f"Checking combo: {icombo}")
        for isample in dataCombos[icombo]: # And the sample in each combo.
            isample_path = dataSets[isample]
            DEBUG.log("Checking path: %s" % isample_path)
            sample_found = False # Keep track if the sample is found in any directory.
            for idir in dirs: # Loop through all possible directories.
                DEBUG.log("Checking directory: %s" % idir)
                if isample_path in os.listdir(idir):
                    full_path = os.path.join(idir, isample_path)
                    check_input_file(full_path, tree_name)
                    sample_found = True
                    break
            if sample_found:
                DEBUG.log(f"Sample {isample} found and checked successfully.")
            else:
                WARNING.log(f"Sample {isample} not found!")
                if icombo not in combos_with_missing_samples:
                    combos_with_missing_samples.append(icombo)
                missing_samples.append(isample)

    return combos_with_missing_samples, missing_samples

def get_all_input_directores(path):
    if not os.path.exists(path):
        ERROR.log(f"Path {path} does not exist.")
        exit(1)
    
    dirs = [path+i+'/' for i in os.listdir(path) if ('mc' in i or 'data' in i)]
    DEBUG.log(f"Found directories: {dirs}")
    return dirs

def main():
    # Create CLI arguments
    args = create_cli_args()

    # Get channel metadata
    dirs, dataCombos, dataSets = return_channel_metadata(args.channel)

    # Change the paths to check if path is provided
    if args.path is not None:
        dirs = get_all_input_directores(args.path)

    # Check all input files
    missing_combos, missing_samples = check_samples(dirs, dataCombos, dataSets, args.tree)
    INFO.log("Input file check completed.")

    if missing_samples:
        WARNING.log("Some samples were not found in the input directories:")
        for combo in missing_combos:
            WARNING.log(f"Combo with missing samples: {combo}")
        for isample in missing_samples:
            DEBUG.log(f"Missing sample: {isample}")
    else:
        INFO.log("All samples were found and checked successfully.")

# This script will check that all the inputs declared in the metadata are present in the input directories.
if __name__ == "__main__":
    main()