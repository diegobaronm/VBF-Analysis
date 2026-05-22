import _setup_project_path  #  (auto-configures sys.path)
import yaml
import os
import argparse
import numpy as np
import matplotlib.pyplot as plt
import ROOT as r

from AnalysisCommons.Logger import INFO, WARNING, ERROR, DEBUG, Logger
Logger.LOGLEVEL = 3

############################################################################################################
# Load the configuration file
def load_config(config_file : str):
    if not os.path.isfile(config_file):
        ERROR.log('Configuration file %s not found!' % config_file)
        exit(1)

    with open(config_file) as f:
        INFO.log('Loading configuration file ----> %s' % config_file)
        config = yaml.load(f, Loader=yaml.FullLoader)
    return config

############################################################################################################
# Print the configuration
def print_config(config):
    for key, value in config.items():
        INFO.log('%s ----> %s' % (key, value))

############################################################################################################
# Parse comma-separated list from config
def parse_csv_list(csv_string : str):
    return [item.strip() for item in csv_string.split(',') if item.strip()]

############################################################################################################
# Get a histogram from a ROOT file and rebin it if bin edges are provided
def get_histogram(file_path : str, histogram_name : str, bin_edges = None):
    file = r.TFile.Open(file_path, "R")
    if not file or file.IsZombie():
        ERROR.log('Failed to open file %s' % file_path)
        return None

    histogram = file.Get(histogram_name)
    if not histogram:
        ERROR.log('Histogram %s not found in file %s' % (histogram_name, file_path))
        return None

    histogram.SetDirectory(0)
    file.Close()

    # Rebin if bin edges are provided
    if bin_edges is not None:
        bin_edges_array = np.array(bin_edges, dtype=np.float64)
        n_bins = len(bin_edges_array) - 1
        histogram = histogram.Rebin(n_bins, histogram.GetName() + '_rebinned', bin_edges_array)

    return histogram

############################################################################################################
# Integrate histogram from a given cut value to the right (inclusive)
def integrate_right(histogram, cut_value):
    total = 0.0
    total_err2 = 0.0
    for i in range(1, histogram.GetNbinsX() + 1):
        low_edge = histogram.GetXaxis().GetBinLowEdge(i)
        if low_edge >= cut_value:
            total += histogram.GetBinContent(i)
            total_err2 += histogram.GetBinError(i)**2

    return total, np.sqrt(total_err2)

############################################################################################################
# Build a summed histogram from a list of files
def build_summed_histogram(path : str, file_list : list, histogram_name : str, bin_edges = None, scaling_factors : dict = None):
    summed = None
    for fname in file_list:
        file_path = os.path.join(path, fname)
        h = get_histogram(file_path, histogram_name, bin_edges)
        if h is None:
            WARNING.log('Skipping file %s' % fname)
            continue

        # Apply scaling factor if one is defined for this file
        if scaling_factors is not None:
            sample_key = fname.replace('.root', '')
            if sample_key in scaling_factors:
                sf = scaling_factors[sample_key]
                INFO.log('Scaling %s by %.4f' % (fname, sf))
                h.Scale(sf)

        if summed is None:
            summed = h.Clone('summed')
        else:
            summed.Add(h)

    return summed

############################################################################################################
# Calculate significance = S / sqrt(S + B)
def significance(s, b):
    if s + b <= 0:
        return 0.0
    return s / np.sqrt(s + b)

############################################################################################################
# Main
if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Significance scan as a function of cut value and signal sample.')
    parser.add_argument('config', type=str, help='Path to the YAML configuration file.')
    parser.add_argument('--output', type=str, default='significance_scan.pdf', help='Output plot file name.')
    parser.add_argument('--log-level', type=int, default=3, help='Log level (1=ERROR, 2=WARNING, 3=INFO, 4=DEBUG)')
    args = parser.parse_args()

    Logger.setLogLevel(args.log_level)

    # ---- Load configuration ---- #
    config = load_config(args.config)
    print_config(config)

    path            = config['path']
    background_list = parse_csv_list(config['background_files'])
    signal_list     = parse_csv_list(config['signal_files'])
    histogram_name  = config['histogram']
    cut_values      = config['cut_values']
    bin_edges       = config.get('bin_edges', None)  # Optional rebinning
    special_signal_blocks = config.get('special_signal', None)

    # Parse scaling factors: dict mapping sample name (without .root) to scale factor
    scaling_factors_raw = config.get('scaling_factors', None)
    scaling_factors = {}
    if scaling_factors_raw is not None:
        for entry in scaling_factors_raw:
            for key, value in entry.items():
                scaling_factors[key] = float(value)
        INFO.log('Scaling factors: %s' % scaling_factors)

    # Parse special signal blocks: each entry has its own signal_samples and bg_samples
    special_entries = []  # list of (signal_files_list, bg_files_list) tuples
    if special_signal_blocks is not None:
        for block in special_signal_blocks:
            sp_signals = parse_csv_list(block['signal_samples'])
            sp_backgrounds = parse_csv_list(block['bg_samples'])
            special_entries.append((sp_signals, sp_backgrounds))
            INFO.log('Special signal block: signals=%s, bg=%s' % (sp_signals, sp_backgrounds))

    if not signal_list and not special_entries:
        ERROR.log('No signal samples provided!')
        exit(1)
    if not background_list:
        ERROR.log('No background samples provided!')
        exit(1)

    # Parse bin edges if provided as a CSV string
    if bin_edges is not None:
        if isinstance(bin_edges, str):
            bin_edges = [float(x) for x in bin_edges.split(',')]
        elif isinstance(bin_edges, list):
            bin_edges = [float(x) for x in bin_edges]

    # Font size for all plot text elements (default: 16)
    font_size = config.get('font_size', 16)

    INFO.log('Path: %s' % path)
    INFO.log('Background files: %s' % background_list)
    INFO.log('Signal files: %s' % signal_list)
    INFO.log('Special signal blocks: %d' % len(special_entries))
    INFO.log('Histogram: %s' % histogram_name)
    INFO.log('Cut values: %s' % cut_values)
    INFO.log('Bin edges: %s' % str(bin_edges))
    INFO.log('Font size: %s' % font_size)

    # ---- Build default background histogram ---- #
    INFO.log('Building summed background histogram...')
    bg_histogram = build_summed_histogram(path, background_list, histogram_name, bin_edges, scaling_factors)
    if bg_histogram is None:
        ERROR.log('Failed to build background histogram!')
        exit(1)

    # ---- Collect all (signal_label, signal_histogram, bg_histogram) pairs ---- #
    signal_rows = []  # each entry: (label, sig_histogram, bg_histogram)

    # Regular signals: use the default background
    for sig_file in signal_list:
        label = sig_file.replace('.root', '')
        sig_path = os.path.join(path, sig_file)
        sig_h = get_histogram(sig_path, histogram_name, bin_edges)
        # Apply scaling factor if defined
        if sig_h is not None and label in scaling_factors:
            INFO.log('Scaling signal %s by %.4f' % (sig_file, scaling_factors[label]))
            sig_h.Scale(scaling_factors[label])
        if sig_h is None:
            WARNING.log('Signal histogram not found for %s. Setting significance to 0.' % sig_file)
        signal_rows.append((label, sig_h, bg_histogram))

    # Special signal blocks: each block merges its signal_samples into one signal histogram
    for sp_signals, sp_backgrounds in special_entries:
        INFO.log('Building special background from: %s' % sp_backgrounds)
        sp_bg_histogram = build_summed_histogram(path, sp_backgrounds, histogram_name, bin_edges, scaling_factors)
        if sp_bg_histogram is None:
            WARNING.log('Failed to build special background histogram! Skipping block.')
            continue

        INFO.log('Building merged special signal from: %s' % sp_signals)
        sp_sig_histogram = build_summed_histogram(path, sp_signals, histogram_name, bin_edges, scaling_factors)
        if sp_sig_histogram is None:
            WARNING.log('Failed to build special signal histogram! Skipping block.')
            continue

        label = ' + '.join([s.replace('.root', '') for s in sp_signals])
        signal_rows.append((label, sp_sig_histogram, sp_bg_histogram))

    # ---- Calculate significance for each signal row and cut value ---- #
    n_signals = len(signal_rows)
    n_cuts = len(cut_values)
    significance_matrix = np.zeros((n_signals, n_cuts))

    signal_labels = []
    for i_sig, (label, sig_histogram, bg_for_signal) in enumerate(signal_rows):
        signal_labels.append(label)
        INFO.log('Processing signal: %s' % label)

        if sig_histogram is None:
            continue

        for i_cut, cut_val in enumerate(cut_values):
            s, _ = integrate_right(sig_histogram, cut_val)
            b, _ = integrate_right(bg_for_signal, cut_val)
            significance_matrix[i_sig, i_cut] = significance(s, b)
            DEBUG.log('  Cut %.2f -> S=%.4f, B=%.4f, Sig=%.4f' % (cut_val, s, b, significance_matrix[i_sig, i_cut]))

    # ---- Plot the heatmap ---- #
    INFO.log('Plotting significance heatmap...')

    fig, ax = plt.subplots(figsize=(max(8, n_cuts * 2.2), max(6, n_signals * 0.8)))

    im = ax.imshow(significance_matrix, aspect='auto', cmap='YlOrRd')

    # Set tick labels
    ax.set_xticks(np.arange(n_cuts))
    ax.set_xticklabels(['%.1f' % c for c in cut_values], rotation=45, ha='right', fontsize=font_size)
    ax.set_yticks(np.arange(n_signals))
    ax.set_yticklabels(signal_labels, fontsize=font_size)

    ax.set_xlabel('Cut value', fontsize=font_size)
    ax.set_ylabel('Signal sample', fontsize=font_size)
    ax.set_title(r'Significance $S / \sqrt{S+B}$', fontsize=font_size)

    # Annotate each cell with the significance value
    for i in range(n_signals):
        for j in range(n_cuts):
            val = significance_matrix[i, j]
            text_color = 'white' if val > 0.5 * significance_matrix.max() else 'black'
            ax.text(j, i, '%.2f' % val, ha='center', va='center', color=text_color, fontsize=font_size)

    cbar = fig.colorbar(im, ax=ax)
    cbar.set_label(r'$S / \sqrt{S+B}$', fontsize=font_size)
    cbar.ax.tick_params(labelsize=font_size)

    plt.tight_layout()
    plt.savefig(args.output, dpi=350)
    INFO.log('Saved significance heatmap to %s' % args.output)
