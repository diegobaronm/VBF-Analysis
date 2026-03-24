import array
import ROOT as r
from histogramHelpers import normalization, biner, HistogramInfo, get_histogram_from_collection
from histogramHelpers import templatesDict

# ============================================================================
# Configuration
# ============================================================================

# Histogram template definitions for observables of interest.
# HistogramInfo(name, binEdges, binSteps, binNorm, xTitle, units)
reco_mass_observable = get_histogram_from_collection("reco_mass_", templatesDict["tautauZpeakHistograms"])
reco_mass_observable.m_xTitle = "m_{#tau#tau} (true)"
reco_mass_observable.m_name = "true_mass"
# reco_mass_observable.m_binEdges = [160,190,210,240,260,290, 310,340, 360,390, 410,440, 460,490, 510,540, 560,590, 610,640, 660,690, 710,740, 760,790, 810,840, 860, 890, 910, 940, 960, 990]
# reco_mass_observable.m_binSteps = [160,30,20,30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 20, 30, 10]
reco_mass_observable.m_binNorm = 1

OBSERVABLES = [
    reco_mass_observable,
]

# Each entry defines one efficiency curve:
#   "baseline_file"  : path to ROOT file containing the baseline histogram
#   "baseline_hist"  : name of the baseline histogram inside the file
#   "cuts_file"      : path to ROOT file containing the post-cut histogram
#   "cuts_hist"      : name of the post-cut histogram inside the file
#   "label"          : legend label for this efficiency curve

EFFICIENCY_PAIRS_Zprime= [
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_NoBDT/Zprime_200.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_BDT/Zprime_200.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Z' (m=200 GeV)",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_NoBDT/Zprime_300.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_BDT/Zprime_300.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Z' (m=300 GeV)",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_NoBDT/Zprime_400.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_BDT/Zprime_400.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Z' (m=400 GeV)",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_NoBDT/Zprime_500.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_BDT/Zprime_500.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Z' (m=500 GeV)",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_NoBDT/Zprime_750.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_BDT/Zprime_750.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Z' (m=750 GeV)",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_NoBDT/Zprime_900.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/BDTTraining/NewQCDSamples/Zprime_NewQCDSamples_BDT/Zprime_900.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Z' (m=900 GeV)",
    },
    # Add more pairs as needed:
    # {
    #     "baseline_file" : "/path/to/another_baseline.root",
    #     "baseline_hist" : "mass_jj",
    #     "cuts_file"     : "/path/to/another_cuts.root",
    #     "cuts_hist"     : "mass_jj",
    #     "label"         : "Selection B",
    # },
]

EFFICIENCY_PAIRS_EWjj = [
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/NoBDTOS/Signal_truth_Sherpa.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/BDTOS/Signal_truth_Sherpa.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "Sherpa2.2.11",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/NoBDTOS/Signal_truth_PoPy.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/BDTOS/Signal_truth_PoPy.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "PoPy",
    },
    {
        "baseline_file" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/NoBDTOS/Signal_truth_MG.root",
        "baseline_hist" : "true_mass_basic_all",
        "cuts_file"     : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/HighMass/BDTOS/Signal_truth_MG.root",
        "cuts_hist"     : "true_mass_basic_all",
        "label"         : "MadGraph",
    },
    # Add more pairs as needed:
    # {
    #     "baseline_file" : "/path/to/another_baseline.root",
    #     "baseline_hist" : "mass_jj",
    #     "cuts_file"     : "/path/to/another_cuts.root",
    #     "cuts_hist"     : "mass_jj",
    #     "label"         : "Selection B",
    # },
]

EFFICIENCY_PAIRS = EFFICIENCY_PAIRS_EWjj

# Plot appearance
OUTPUT_DIR          = "results/"
OUTPUT_FORMAT       = "pdf"
Y_AXIS_TITLE        = "Efficiency"
Y_RANGE             = (0.0, 1.25)
COLOURS             = [r.kBlack, r.kRed, r.kBlue, r.kGreen+2, r.kOrange+1, r.kViolet]
MARKER_STYLES       = [20, 21, 22, 23, 34, 33]
CANVAS_WIDTH        = 1200
CANVAS_HEIGHT       = 600
EQUAL_BIN_WIDTH     = True   # Display variable-width bins as visually equal-width
PLOT_AVERAGE        = True   # Overlay the average efficiency across all curves
SEPARATE_PLOTS      = False  # If True, produce one plot per efficiency pair; if False, overlay all on one plot

# ============================================================================
# Core functions
# ============================================================================

def get_histogram(file_path, hist_name):
    """Open a ROOT file and retrieve a histogram by name."""
    f = r.TFile.Open(file_path, "READ")
    if not f or f.IsZombie():
        print("ERROR: Cannot open file", file_path)
        return None, None
    h = f.Get(hist_name)
    if not h:
        print("ERROR: Histogram '%s' not found in %s" % (hist_name, file_path))
        return None, None
    h.SetDirectory(0)
    f.Close()
    return h, None


def find_observable_info(obs_name):
    """Find the HistogramInfo entry matching the given observable name."""
    for info in OBSERVABLES:
        if info.m_name == obs_name:
            return info
    return None


def compute_efficiency(h_cuts, h_baseline):
    """Compute the bin-by-bin efficiency ratio = cuts / baseline.

    Uses TGraphAsymmErrors with Clopper-Pearson intervals for proper
    binomial efficiency uncertainties.
    """
    eff = r.TGraphAsymmErrors()
    eff.Divide(h_cuts, h_baseline, "cl=0.683 b(1,1) mode")
    return eff


def rebin_histogram(hist, obs_info, suffix=""):
    """Rebin a histogram according to the observable's HistogramInfo."""
    if obs_info.needsRebin():
        rebinning = biner(obs_info.m_binEdges, obs_info.m_binSteps, hist)
        nb = len(rebinning) - 1
        hist = hist.Rebin(nb, hist.GetName() + suffix, rebinning)
        normalization([hist], obs_info.m_binNorm)
    return hist


def get_bin_edges(histogram):
    """Extract the array of bin edges from a TH1."""
    axis = histogram.GetXaxis()
    n = axis.GetNbins()
    return [axis.GetBinLowEdge(i) for i in range(1, n + 1)] + [axis.GetBinUpEdge(n)]


def remap_graph_to_equal_bins(graph, bin_edges):
    """Remap a TGraphAsymmErrors so each point sits at equal-width bin-index
    coordinates (0.5, 1.5, 2.5, ...) instead of actual x values.

    Uses the point's x-position to look up the correct bin index, so that
    graphs with missing bins (e.g. zero-entry bins skipped by Divide) are
    placed at the right position.
    """
    n = graph.GetN()
    for i in range(n):
        x = graph.GetPointX(i)
        # Find which bin this x-value falls in
        bin_idx = 0
        for b in range(len(bin_edges) - 1):
            if bin_edges[b] <= x < bin_edges[b + 1]:
                bin_idx = b
                break
        else:
            # x equals the upper edge of the last bin
            bin_idx = len(bin_edges) - 2
        graph.SetPoint(i, bin_idx + 0.5, graph.GetPointY(i))
        graph.SetPointEXlow(i,  0.5)
        graph.SetPointEXhigh(i, 0.5)


def format_edge(val):
    """Format a bin-edge value: drop the decimal if it is an integer."""
    return str(int(val)) if val == int(val) else "%.1f" % val


import math

def compute_average_graph(graphs):
    """Compute the bin-by-bin mean of several TGraphAsymmErrors.

    Returns a new TGraphAsymmErrors whose y-values are the arithmetic mean
    and whose y-errors are the standard deviation of the inputs divided by
    sqrt(N) (i.e. the standard error of the mean).
    """
    n_points = graphs[0].GetN()
    n_graphs = len(graphs)
    avg = r.TGraphAsymmErrors(n_points)

    for i in range(n_points):
        x   = graphs[0].GetPointX(i)
        exl = graphs[0].GetErrorXlow(i)
        exh = graphs[0].GetErrorXhigh(i)

        values = [g.GetPointY(i) for g in graphs]
        mean = sum(values) / n_graphs
        if n_graphs > 1:
            variance = sum((v - mean) ** 2 for v in values) / (n_graphs - 1)
            sem = math.sqrt(variance / n_graphs)
        else:
            sem = 0.0

        avg.SetPoint(i, x, mean)
        avg.SetPointEXlow(i, exl)
        avg.SetPointEXhigh(i, exh)
        avg.SetPointEYlow(i, sem)
        avg.SetPointEYhigh(i, sem)

    return avg


def apply_equal_bin_labels(graph, bin_edges, obs_info):
    """Replace the numeric x-axis with labelled bins showing the real ranges."""
    n_bins = len(bin_edges) - 1
    axis = graph.GetXaxis()
    axis.Set(n_bins, 0, n_bins)
    for i in range(n_bins):
        label = "%s-%s" % (format_edge(bin_edges[i]), format_edge(bin_edges[i + 1]))
        axis.SetBinLabel(i + 1, label)
    axis.SetLabelSize(0.035)
    axis.LabelsOption("h")
    # Put the observable name (with units) as the axis title instead
    x_title = obs_info.m_xTitle
    if obs_info.m_units:
        x_title += " [%s]" % obs_info.m_units
    axis.SetTitle(x_title)


def _draw_efficiency_canvas(observable_name, obs_info, pairs_with_indices, suffix=""):
    """Draw one efficiency canvas for the given (subset of) pairs.

    pairs_with_indices is a list of (global_index, pair_dict) tuples so that
    colours / markers stay consistent regardless of splitting mode.
    suffix is appended to the output file name (used in separate-plots mode).
    """
    canvas_name = "c_eff_%s%s" % (observable_name, suffix)
    c = r.TCanvas(canvas_name, "", CANVAS_WIDTH, CANVAS_HEIGHT)
    c.SetMargin(0.14, 0.05, 0.13, 0.08)
    c.SetGrid()

    legend = r.TLegend(0.55, 0.78, 0.93, 0.90)
    legend.SetBorderSize(0)
    legend.SetFillStyle(0)
    legend.SetTextSize(0.035)

    graphs = []
    bin_edges = None
    for idx, pair in pairs_with_indices:
        h_baseline, _ = get_histogram(pair["baseline_file"], pair["baseline_hist"])
        h_cuts, _     = get_histogram(pair["cuts_file"],     pair["cuts_hist"])
        if h_baseline is None or h_cuts is None:
            continue

        # Rebin both histograms identically
        h_baseline = rebin_histogram(h_baseline, obs_info, "_base")
        h_cuts     = rebin_histogram(h_cuts,     obs_info, "_cuts")

        #print("INFO: Processing '%s' with %d bins after rebinning." % (pair["label"], h_baseline.GetXaxis().GetNbins()))
        #print("      Bin edges:", [h_baseline.GetXaxis().GetBinLowEdge(i) for i in range(1, h_baseline.GetXaxis().GetNbins() + 1)] + [h_baseline.GetXaxis().GetBinUpEdge(h_baseline.GetXaxis().GetNbins())])
        #print("      Bin contents (baseline):", [h_baseline.GetBinContent(i) for i in range(1, h_baseline.GetXaxis().GetNbins() + 1)])
        #print("      Bin contents (cuts):", [h_cuts.GetBinContent(i) for i in range(1, h_cuts.GetXaxis().GetNbins() + 1)])


        # Capture bin edges from the first valid pair (all pairs share the same binning)
        if bin_edges is None:
            bin_edges = get_bin_edges(h_baseline)

        eff_graph = compute_efficiency(h_cuts, h_baseline)

        if EQUAL_BIN_WIDTH:
            remap_graph_to_equal_bins(eff_graph, bin_edges)

        # Style
        colour = COLOURS[idx % len(COLOURS)]
        marker = MARKER_STYLES[idx % len(MARKER_STYLES)]
        eff_graph.SetMarkerStyle(marker)
        eff_graph.SetMarkerColor(colour)
        eff_graph.SetLineColor(colour)
        eff_graph.SetLineWidth(2)
        eff_graph.SetTitle("")

        legend.AddEntry(eff_graph, pair["label"], "lep")
        graphs.append(eff_graph)

    if len(graphs) == 0:
        print("WARNING: No valid efficiency graphs for '%s'." % observable_name)
        return

    # Draw the first graph to set the frame, then overlay the rest
    x_title = obs_info.m_xTitle
    if obs_info.m_units:
        x_title += " [%s]" % obs_info.m_units

    graphs[0].Draw("AP")
    graphs[0].GetXaxis().SetTitle(x_title)
    graphs[0].GetYaxis().SetTitle(Y_AXIS_TITLE)
    graphs[0].GetYaxis().SetRangeUser(Y_RANGE[0], Y_RANGE[1])
    graphs[0].GetXaxis().SetTitleSize(0.050)
    graphs[0].GetYaxis().SetTitleSize(0.050)
    graphs[0].GetXaxis().SetLabelSize(0.045)
    graphs[0].GetYaxis().SetLabelSize(0.045)
    graphs[0].GetYaxis().SetTitleOffset(1.30)

    if EQUAL_BIN_WIDTH and bin_edges is not None:
        apply_equal_bin_labels(graphs[0], bin_edges, obs_info)

    for g in graphs[1:]:
        g.Draw("P SAME")

    # Average efficiency
    if PLOT_AVERAGE and len(graphs) > 1:
        avg_graph = compute_average_graph(graphs)
        avg_graph.SetMarkerStyle(29)
        avg_graph.SetMarkerSize(1.8)
        avg_graph.SetMarkerColor(r.kMagenta+1)
        avg_graph.SetLineColor(r.kMagenta+1)
        avg_graph.SetLineWidth(3)
        avg_graph.SetLineStyle(2)
        avg_graph.SetFillColorAlpha(r.kMagenta-9, 0.35)
        avg_graph.SetFillStyle(3001)
        avg_graph.Draw("3 SAME")  # error band
        avg_graph.Draw("PX SAME") # markers on top
        legend.AddEntry(avg_graph, "Average", "fpel")

    legend.Draw()
    r.gStyle.SetOptStat(0)
    c.Update()
    c.SaveAs("%sEfficiency_%s%s.%s" % (OUTPUT_DIR, observable_name, suffix, OUTPUT_FORMAT))


def plot_efficiency(observable_name):
    """Plot the selection efficiency for a given observable across all pairs."""
    obs_info = find_observable_info(observable_name)
    if obs_info is None:
        print("WARNING: Observable '%s' not found in OBSERVABLES, skipping." % observable_name)
        return

    if len(EFFICIENCY_PAIRS) == 0:
        print("WARNING: No efficiency pairs defined, nothing to plot.")
        return

    if SEPARATE_PLOTS:
        for idx, pair in enumerate(EFFICIENCY_PAIRS):
            safe_label = pair["label"].replace(" ", "_").replace("'", "").replace("(", "").replace(")", "").replace("=", "")
            _draw_efficiency_canvas(observable_name, obs_info,
                                   [(idx, pair)],
                                   suffix="_%s" % safe_label)
    else:
        _draw_efficiency_canvas(observable_name, obs_info,
                                list(enumerate(EFFICIENCY_PAIRS)))


# ============================================================================
# Main
# ============================================================================
def main():
    r.gROOT.SetBatch(True)
    for obs_info in OBSERVABLES:
        plot_efficiency(obs_info.m_name)

if __name__ == "__main__":
    main()
