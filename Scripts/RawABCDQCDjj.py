import ROOT as r
import os
import numpy as np

from Scripts.histogramHelpers import normalization, biner, templatesDict, get_histogram_from_collection

HISTOGRAM_TEMPLATES = templatesDict["llZpeakHistograms"]
HISTOGRAMS_DICT = {}

def main():
    base_path = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/Zll/NewZpeak"
    QCDjj_sample_name = "Zll_SherpaNLO.root"

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
    plt.figure(figsize=(8, 8))

    # Create two subplots, one for residuals and one for the main plot
    plt.subplot(2, 1, 1)
    # Plot histograms with error bars. The histograms should be bars with error bars
    plt.errorbar(sr_hist["bin_centers"], sr_hist["bin_contents"], yerr=sr_hist["bin_errors"], fmt='.', label='SR')
    plt.errorbar(abcd_hist["bin_centers"], abcd_hist["bin_contents"], yerr=abcd_hist["bin_errors"], fmt='.', label='ABCD')
    plt.yscale('log')
    plt.xlabel("M_{jj} [GeV]")

    # Create legend
    plt.legend()
    plt.title("SR vs ABCD QCDjj")

    # Add residuals plot
    plt.subplot(2, 1, 2)
    plt.errorbar(ratio_hist["bin_centers"], ratio_hist["bin_contents"], yerr=ratio_hist["bin_errors"], fmt='o', color='black', label='SR / ABCD')

    # Plot a horizontal line at y=1
    plt.axhline(y=1, color='red', linestyle='--', label='y=1')
    plt.xlabel("M_{jj} [GeV]")
    plt.ylabel("Residuals")
    # Set the y-axis limit for residuals with the max and min of the ratio
    ratio_min = np.min(ratio_hist["bin_contents"])
    ratio_max = np.max(ratio_hist["bin_contents"])
    plt.ylim(0.5 * ratio_min, 1.5 * ratio_max)


    plt.legend()

    # Save figure
    plt.savefig("Matplotlib_Raw_ABCD_%s.pdf" % QCDjj_sample_name.replace(".root", ""))



if __name__ == "__main__":
    main()