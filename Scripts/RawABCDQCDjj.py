import _setup_project_path  #  (auto-configures sys.path)
import ROOT as r
import os
import numpy as np

from Scripts.histogramHelpers import (
    normalization, 
    biner, 
    templatesDict, 
    get_histogram_from_collection, 
    get_histogram, 
    process_histogram, 
    a_times_b_divide_c,
    convert_to_numpy_histogram
)

HISTOGRAM_TEMPLATES = templatesDict["llZpeakHistograms"]
HISTOGRAMS_DICT = {}

def main():
    base_path = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/Zll/Zpeak"
    QCDjj_sample_name = "Zll_MGNLO.root"

    HISTOGRAMS_DICT["SR"] = get_histogram(os.path.join(base_path, "SR", QCDjj_sample_name), "mass_jj")
    HISTOGRAMS_DICT["CRa"] = get_histogram(os.path.join(base_path, "CRa", QCDjj_sample_name), "mass_jj")
    HISTOGRAMS_DICT["CRb"] = get_histogram(os.path.join(base_path, "CRb", QCDjj_sample_name), "mass_jj")
    HISTOGRAMS_DICT["CRc"] = get_histogram(os.path.join(base_path, "CRc", QCDjj_sample_name), "mass_jj")

    # Get the Mjj histogram template
    mjj_template = get_histogram_from_collection("mass_jj", HISTOGRAM_TEMPLATES)

    # Define the rebinning object
    rebining_object = biner(mjj_template.m_binEdges, mjj_template.m_binSteps, HISTOGRAMS_DICT["SR"])

    # Process each histogram in the dictionary
    for region in HISTOGRAMS_DICT:
        HISTOGRAMS_DICT[region] = process_histogram(HISTOGRAMS_DICT[region], rebin = rebining_object, norm_factor= mjj_template.m_binNorm, density=True)


    # Calculate SR = CRa * CRc / CRb
    HISTOGRAMS_DICT["ABCD"] = a_times_b_divide_c(HISTOGRAMS_DICT["CRa"], HISTOGRAMS_DICT["CRc"], HISTOGRAMS_DICT["CRb"])

    HISTOGRAMS_DICT["ABCD"] = process_histogram(HISTOGRAMS_DICT["ABCD"], density=True)

    HISTOGRAMS_DICT["ratio"] = HISTOGRAMS_DICT["SR"].Clone("ratio")
    HISTOGRAMS_DICT["ratio"].Divide(HISTOGRAMS_DICT["ABCD"])

    # Convert histograms to NumPy format
    sr_hist = convert_to_numpy_histogram(HISTOGRAMS_DICT["SR"])
    abcd_hist = convert_to_numpy_histogram(HISTOGRAMS_DICT["ABCD"])
    ratio_hist = convert_to_numpy_histogram(HISTOGRAMS_DICT["ratio"])

    # Plot using matplotlib
    import matplotlib.pyplot as plt

    label_size = 22
    tick_label_size = 18
    legend_size = 18
    title_size = 24
    tick_length = 7
    tick_width = 1.4
    line_width = 1.8

    def plot_hist_with_errors(ax, hist, label, color):
        ax.stairs(
            values=hist["bin_contents"],
            edges=hist["bin_edges"],
            label=label,
            color=color,
            linewidth=line_width,
        )
        ax.errorbar(
            hist["bin_centers"],
            hist["bin_contents"],
            yerr=hist["bin_errors"],
            fmt="none",
            ecolor=color,
            elinewidth=1.2,
            capsize=2,
        )

    fig, (ax_top, ax_bottom) = plt.subplots(
        2,
        1,
        figsize=(10, 9),
        sharex=True,
        gridspec_kw={"height_ratios": [3, 2], "hspace": 0.08},
    )

    # Top panel: SR and ABCD as histogram-style plots with error bars
    plot_hist_with_errors(ax_top, sr_hist, "SR", "tab:blue")
    plot_hist_with_errors(ax_top, abcd_hist, "A*C/B", "tab:orange")
    ax_top.set_yscale("log")
    ax_top.set_ylabel("Density", fontsize=label_size)
    ax_top.set_title("QCDjj Sherpa 2.2.11 -- SR vs A*C/B", fontsize=title_size)
    ax_top.legend(fontsize=legend_size)
    ax_top.tick_params(axis="both", which="major", labelsize=tick_label_size, length=tick_length, width=tick_width)
    ax_top.tick_params(axis="both", which="minor", length=0.7 * tick_length, width=0.8 * tick_width)

    # Bottom panel: ratio as points with error bars
    ax_bottom.errorbar(
        ratio_hist["bin_centers"],
        ratio_hist["bin_contents"],
        yerr=ratio_hist["bin_errors"],
        fmt="o",
        color="black",
        markersize=4,
        capsize=2,
        elinewidth=1.2,
        label="SR / (A*C/B)",
    )
    ax_bottom.axhline(y=1.0, color="red", linestyle="--", linewidth=1.4, label="y=1")
    ax_bottom.set_xlabel("$m_{jj}$ [GeV]", fontsize=label_size)
    ax_bottom.set_ylabel("Residuals", fontsize=label_size)

    # Set the y-axis limit for residuals with the max and min of the ratio
    ratio_min = np.min(ratio_hist["bin_contents"])
    ratio_max = np.max(ratio_hist["bin_contents"])
    ax_bottom.set_ylim(0.5 * ratio_min, 1.5 * ratio_max)
    ax_bottom.legend(fontsize=legend_size)
    ax_bottom.tick_params(axis="both", which="major", labelsize=tick_label_size, length=tick_length, width=tick_width)
    ax_bottom.tick_params(axis="both", which="minor", length=0.7 * tick_length, width=0.8 * tick_width)

    # Save figure
    fig.savefig("Matplotlib_Raw_ABCD_%s.pdf" % QCDjj_sample_name.replace(".root", ""))



if __name__ == "__main__":
    main()