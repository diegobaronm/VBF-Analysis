# This script checks that every other histogram in a systematic ROOT file is no more different than 10% from the nominal histogram.
import os
import argparse
import ROOT as r

from AnalysisCommons.Run import INFO, WARNING, ERROR

def get_cli_arguments():
    parser = argparse.ArgumentParser(description="Check systematics in ROOT files.")
    parser.add_argument("input_path", help="Path to the input ROOT files.", type=str)
    parser.add_argument("--tolerance", help="Tolerance level for histogram comparison (default: 10 for 10%%).", type=float, default=10)
    return parser.parse_args()

def compare_histograms(nominal_hist, systematic_hist, tolerance):
    # Compare entries
    nominal_entries = nominal_hist.GetEntries()
    systematic_entries = systematic_hist.GetEntries()

    if nominal_entries == 0:
        ERROR.log("Nominal histogram has zero entries, skipping comparison.")
        exit(1)

    entry_diff = abs(nominal_entries - systematic_entries) / nominal_entries * 100
    if entry_diff > tolerance:
        WARNING.log("Entries for systematic %s \n , differ by %.2f%% from NOMINAL." % (systematic_hist.GetName(), entry_diff))

    # Compare mean
    nominal_mean = nominal_hist.GetMean()
    systematic_mean = systematic_hist.GetMean()
    mean_diff = abs(nominal_mean - systematic_mean) / nominal_mean * 100
    if mean_diff > tolerance:
        WARNING.log("Mean for systematic %s \n , differ by %.2f%% from NOMINAL." % (systematic_hist.GetName(), mean_diff))

    # Compare std dev
    nominal_std = nominal_hist.GetStdDev()
    systematic_std = systematic_hist.GetStdDev()
    std_diff = abs(nominal_std - systematic_std) / nominal_std * 100
    if std_diff > tolerance:
        WARNING.log("StdDev for systematic %s \n , differ by %.2f%% from NOMINAL." % (systematic_hist.GetName(), std_diff))

def get_nominal_histogram(file):
    nominal_key = 'mass_jj_NOMINAL'
    nominal_hist = file.Get(nominal_key)
    if not nominal_hist:
        ERROR.log(f"Histogram {nominal_key} not found in file {file.GetName()}.")
        exit(1)
    return nominal_hist

def get_systematic_files(input_path):
    return [f for f in os.listdir(input_path) if f.endswith('.root') and 'SYS' in f]

def main():
    args = get_cli_arguments()
    input_path = args.input_path
    tolerance = args.tolerance

    if not os.path.isdir(input_path):
        ERROR.log(f"Input path {input_path} is not a valid directory.")
        exit(1)

    sys_files = get_systematic_files(input_path)
    if not sys_files:
        ERROR.log("No systematic ROOT files found in the input path.")
        exit(1)

    for sys_file_name in sys_files:
        sys_file_path = os.path.join(input_path, sys_file_name)
        INFO.log(f"Processing file: {sys_file_path}")

        sys_file = r.TFile.Open(sys_file_path, "READ")
        if not sys_file:
            ERROR.log(f"Could not open file {sys_file_path}.")
            continue

        nominal_hist = get_nominal_histogram(sys_file)

        for sys_hist_key in sys_file.GetListOfKeys():
            sys_hist = sys_file.Get(sys_hist_key.GetName())
            if sys_hist.GetName() == 'mass_jj_NOMINAL':
                continue
            compare_histograms(nominal_hist, sys_hist, tolerance)

        sys_file.Close()

if __name__ == "__main__":
    main()
