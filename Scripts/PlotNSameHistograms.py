import argparse
import ROOT
import numpy as np
from pathlib import Path

#!/usr/bin/env python3
"""
Script to extract and plot histograms from ROOT files using matplotlib.
"""

import matplotlib.pyplot as plt


def extract_histogram(root_file_path, hist_name, rebin_edges = None):
    """Extract histogram from ROOT file and return bin edges, contents, and per-bin errors."""
    root_file = ROOT.TFile.Open(str(root_file_path))
    if not root_file or root_file.IsZombie():
        raise IOError(f"Cannot open ROOT file: {root_file_path}")
    
    hist = root_file.Get(hist_name)
    if not hist:
        raise ValueError(f"Histogram '{hist_name}' not found in {root_file_path}")
    
    if rebin_edges is not None:
        rebin_array = np.array(rebin_edges, dtype='d')
        hist = hist.Rebin(len(rebin_edges)-1, hist.GetName(), rebin_array)

    print("Hello")

    # Extract histogram data
    nbins = hist.GetNbinsX()
    bin_edges = np.array([hist.GetBinLowEdge(i) for i in range(1, nbins + 2)])
    bin_contents = np.array([hist.GetBinContent(i) for i in range(1, nbins + 1)])
    # New: extract per-bin statistical uncertainties from ROOT
    bin_errors = np.array([hist.GetBinError(i) for i in range(1, nbins + 1)])
    
    root_file.Close()

    return bin_edges, bin_contents, bin_errors

def plot_histograms(files, hist_name, labels, density=False, rebin=1, rebin_edges=None, norm_factor=1.0,
                   xlabel='X axis', ylabel='Y axis', title='Histogram Comparison',
                   output='plot.pdf', cut_min=None, cut_max=None):
    """Plot histograms from multiple ROOT files with per-bin uncertainties."""
    fig, ax = plt.subplots(figsize=(10, 7))

    pass_lines = []
    for file_path, label in zip(files, labels):
        # Rebin done inside extract_histogram
        bin_edges, bin_contents, bin_errors = extract_histogram(
            file_path, hist_name,
            rebin_edges=rebin_edges
        )

        # Compute passing fraction BEFORE any normalization/density scaling
        if (cut_min is not None) or (cut_max is not None):
            cmin = -np.inf if cut_min is None else float(cut_min)
            cmax = np.inf if cut_max is None else float(cut_max)
            total = float(np.sum(bin_contents))
            passed = float(np.sum(bin_contents[(bin_edges[:-1] >= cmin) & (bin_edges[1:] <= cmax)]))
            passing_fraction = passed / total if total > 0 else 0.0
            pass_lines.append(f"{label.replace("Signal_truth_", "EWjj-")}: {100*passing_fraction:.1f}%")

        # Normalisation
        if norm_factor != 1.0:
            widths = np.diff(bin_edges)
            bin_contents = norm_factor * bin_contents / widths
            bin_errors   = norm_factor * bin_errors / widths
    

        # Density (area = 1)
        if density:
            widths = np.diff(bin_edges)
            total_area = np.sum(bin_contents * widths)
            if total_area > 0:
                scale = 1.0 / total_area
                bin_contents *= scale
                bin_errors   *= scale

        
        # Plot everytime with a different color
        line, = ax.step(bin_edges[:], np.concatenate([bin_contents, np.array([0])]), where='post', label=label, linewidth=2)
        centers = 0.5 * (bin_edges[:-1] + bin_edges[1:])
        ax.errorbar(centers, bin_contents, yerr=bin_errors, xerr=0.5*np.diff(bin_edges), fmt='none',
                    elinewidth=1, capsize=0, alpha=1.0, color=line.get_color())
        
        # Set plot xrange between lower bin and upper bin
        ax.set_xlim(bin_edges[0], bin_edges[-1])


    if pass_lines:
        ax.text(0.98, 0.98, 'm(tau,lep) > 130 GeV\n' + "\n".join(pass_lines),
                transform=ax.transAxes, ha='right', va='top', fontsize=16,
                bbox=dict(boxstyle='round', facecolor='white', alpha=0.8, edgecolor='gray'))
        
    # make axis labels larger
    ax.tick_params(axis='both', which='major', labelsize=14)


    ax.set_xlabel(xlabel, fontsize=14)
    ax.set_ylabel(ylabel, fontsize=14)
    ax.set_title(title, fontsize=18)
    ax.legend(fontsize=16)
    ax.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(output, dpi=300, bbox_inches='tight')
    print(f"Plot saved to {output}")
    plt.show()


def main():
    parser = argparse.ArgumentParser(
        description='Extract and plot histograms from ROOT files using matplotlib'
    )
    parser.add_argument('files', nargs='+', help='ROOT file paths')
    parser.add_argument('--hist-name', '-n', required=True,
                       help='Name of histogram to extract')
    parser.add_argument('--labels', '-l', nargs='+',
                       help='Labels for each file (default: filenames)')
    parser.add_argument('--density', '-d', action='store_true',
                       help='Plot as density instead of counts')
    parser.add_argument('--rebin-edges', type=str,
                       help='Comma-separated new bin edges (e.g. "0,10,20,30"); overrides --rebin.')
    parser.add_argument('--normalisation', type=float, default=1.0,
                       help='Normalization factor to apply to histograms')
    parser.add_argument('--cut-min', type=float, default=None,
                       help='Minimum x for passing cut (inclusive). Omit for no lower bound.')
    parser.add_argument('--cut-max', type=float, default=None,
                       help='Maximum x for passing cut (inclusive). Omit for no upper bound.')
    parser.add_argument('--xlabel', '-x', default='X axis',
                       help='X-axis label')
    parser.add_argument('--ylabel', '-y', default='Counts',
                       help='Y-axis label')
    parser.add_argument('--title', '-t', default='Histogram Comparison',
                       help='Plot title')
    parser.add_argument('--output', '-o', default='plot.png',
                       help='Output file name (default: plot.png)')
    
    args = parser.parse_args()

    # New: parse comma-separated rebin edges into a list of floats
    if args.rebin_edges is not None:
        try:
            args.rebin_edges = [float(tok.strip()) for tok in args.rebin_edges.split(',') if tok.strip() != '']
        except ValueError:
            raise ValueError("--rebin-edges must be a comma-separated list of numbers")
        if len(args.rebin_edges) < 2:
            raise ValueError("--rebin-edges must contain at least two edges")

    # Generate default labels if not provided
    if args.labels is None:
        args.labels = [Path(f).stem for f in args.files]
    elif len(args.labels) != len(args.files):
        raise ValueError("Number of labels must match number of files")
    
    # Adjust ylabel if density mode
    if args.density and args.ylabel == 'Counts':
        args.ylabel = 'Density'
    
    plot_histograms(
        files=args.files,
        hist_name=args.hist_name,
        labels=args.labels,
        density=args.density,
        rebin_edges=args.rebin_edges,
        norm_factor=args.normalisation,
        xlabel=args.xlabel,
        ylabel=args.ylabel,
        title=args.title,
        output=args.output,
        cut_min=args.cut_min,
        cut_max=args.cut_max
    )


if __name__ == '__main__':
    main()