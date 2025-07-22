from argparse import ArgumentParser
import os

from AnalysisCommons.Run import DEBUG, INFO, ERROR, WARNING, Logger
Logger.LOGLEVEL = 3


def create_cli_args():
    parser = ArgumentParser(description="Check the output files in a directory against a list of input files in txt.")
    parser.add_argument("--inputs", type=str, required=True, help="Path to the input txt file.")
    parser.add_argument("--tree", type=str, default="NOMINAL", help="Name of the tree to check in the output files.")
    parser.add_argument("--outputs", type=str, required=True, default=None, help="Path to the output files.")
    args = parser.parse_args()

    return args


def collect_output_files(outputs, tree_name):
    INFO.log(f"Collecting output files from {outputs} with tree name {tree_name}")
    output_files = []
    if not os.path.exists(outputs):
        ERROR.log(f"Path {outputs} does not exist.")
        exit(1)
    
    for file in os.listdir(outputs):
        if file.endswith('.root') and tree_name in file:
            output_files.append(file.replace('.root', '').replace(tree_name, ''))  # Remove the .root extension and the tree name
            DEBUG.log(f"Found output file: {file}")
    
    return output_files

def collect_input_files(input_file_path):
    INFO.log(f"Collecting input files from {input_file_path}")
    input_files = []
    if not os.path.exists(input_file_path):
        ERROR.log(f"Input file {input_file_path} does not exist.")
        exit(1)
    
    with open(input_file_path, 'r') as f:
        for line in f:
            line = line.replace('\n', '').strip()  # Remove newline and whitespace
            if line:  # Ignore empty lines
                input_files.append(line)
                DEBUG.log(f"Found input file: {line}")
    
    return input_files

def find_missing_files(output_files, input_files):
    missing_files = []
    for input_file in input_files:
        if input_file not in output_files:
            missing_files.append(input_file)
            WARNING.log(f"Missing file: {input_file}")
    
    return missing_files

def create_missing_files_txt(path, missing_files):
    # Get the base path for the input files
    base_path = os.path.dirname(path)
    missing_file_path = os.path.join(base_path, 'Missing_files.txt')
    INFO.log(f"Creating missing files list at {missing_file_path}")
    with open(missing_file_path, 'w') as f:
        for file in missing_files:
            f.write(file + '\n')
    INFO.log("Missing files list created successfully.")

if __name__ == "__main__":
    # Create the CLI arguments
    args = create_cli_args()

    # Collect the output files
    output_files = collect_output_files(args.outputs, args.tree)

    # Collect the input files
    input_files = collect_input_files(args.inputs)

    # Compare the output files with the input files
    missing_files = find_missing_files(output_files, input_files)

    if missing_files: # Create a txt file with the missing files for re-submission
        create_missing_files_txt(args.inputs, missing_files)
    else:
        INFO.log("All input files were found in the output directory!")

