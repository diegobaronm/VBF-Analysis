import ROOT as r
from histogramHelpers import normalization, biner, HistogramInfo, templatesDict
MAX_Y_VALUE = 0.0

def getMaxYValue(fileName, histogramName, histogramTemplate,prefix, postfix, compareDensity):
    # Get hisogram from file
    f1 = r.TFile(fileName)
    h1 = f1.Get(prefix + histogramName + postfix)
    if not h1:
        print("Histogram ", histogramName+postfix, " not found in file ", fileName)
        return
    
    # Check if the histograms belongs to the region
    found = False
    histogramInfo = None
    for i in REGION:
        if i.m_name == histogramTemplate:
            found = True
            histogramInfo = i
            break
    if not found:
        print("Histogram ", histogramName, " does not belong to the passed region!")
        return
    
    # Set histogram directory
    h1.SetDirectory(0)

    # Rebin the histogram and normalise depending on the desired output
    if histogramInfo.needsRebin():
        rebining=biner(histogramInfo.m_binEdges,histogramInfo.m_binSteps,h1)
        print("Using following bins... ",rebining)
        nb=len(rebining)-1
        h1=h1.Rebin(nb,histogramName,rebining)
        normalization([h1],histogramInfo.m_binNorm)
    # Plot the histogram density if requested
    if (compareDensity):
        h1.Scale(1.0/h1.Integral(1,-1));

    # Get the maximum value of the histogram
    max_value = h1.GetMaximum();
    return max_value


### Plot one histogram given:
#  A Canvas
#  File path
#  Histogram name
#  Compare density
#  Title
#  Colour
#  Drawing options
#  Region with the histogram parameters.
def plot(canvas, fileName, histogramName, histogramTemplate,prefix, postfix, compareDensity, title, colour, drawingOptions, region : list[HistogramInfo]):
    # Get hisogram from file
    f1 = r.TFile(fileName)
    h1 = f1.Get(prefix + histogramName + postfix)
    if not h1:
        print("Histogram ", histogramName+postfix, " not found in file ", fileName)
        return
    
    # Check if the histograms belongs to the region
    found = False
    histogramInfo = None
    for i in region:
        if i.m_name == histogramTemplate:
            found = True
            histogramInfo = i
            break
    if not found:
        print("Histogram ", histogramName, " does not belong to the passed region!")
        return
    
    # Set histogram directory
    h1.SetDirectory(0)

    # Rebin the histogram and normalise depending on the desired output
    if histogramInfo.needsRebin():
        rebining=biner(histogramInfo.m_binEdges,histogramInfo.m_binSteps,h1)
        print("Using following bins... ",rebining)
        nb=len(rebining)-1
        h1=h1.Rebin(nb,histogramName,rebining)
        normalization([h1],histogramInfo.m_binNorm)
    # Plot the histogram density if requested
    if (compareDensity):
        h1.Scale(1.0/h1.Integral(1,-1));


    # Set the histogram style
    h1.SetTitle(title);
    canvas.cd();
    h1.GetXaxis().SetRange(1,h1.GetNbinsX()+1);
    h1.GetYaxis().SetRangeUser(0.0,MAX_Y_VALUE*1.2);

    if (histogramInfo.m_logScale):
        canvas.SetLogy();
        h1.GetXaxis().SetRange(1,h1.GetNbinsX()+1);
        h1.GetYaxis().SetRangeUser(0.0001,MAX_Y_VALUE*1.2);
    h1.Draw(drawingOptions);

    h1.GetXaxis().SetTitle(histogramInfo.m_xTitle);
    ytitle = "Events/"+str(histogramInfo.m_binNorm)+str(histogramInfo.m_units);
    h1.GetYaxis().SetTitle(ytitle);
    h1.GetXaxis().SetTitleSize(0.056);
    h1.GetYaxis().SetTitleSize(0.056);
    h1.GetXaxis().SetLabelSize(0.056);
    h1.GetYaxis().SetLabelSize(0.056);
    h1.GetYaxis().SetTitleOffset(1.45);
    h1.GetXaxis().SetTitleOffset(1.00);

    h1.SetMarkerStyle(20);
    h1.SetMarkerColor(colour);
    h1.SetLineColor(colour);
    r.gStyle.SetOptStat(0);

    # Close the file
    f1.Close();

def compareShapesFromDifferentFiles(histogramName, histogramTemplate, prefix, postfix,dictOfFiles, useDensity):
    print("Doing...", histogramName)
    # Check input
    if (len(dictOfFiles) == 0):
        print("No files to compare!")
        return
    if (len(dictOfFiles) == 1):
        print("Only one file to compare!")
        return
    if (len(dictOfFiles) > 4):
        print("Maximum supported shapes to compare is four!")
        return
    
    # Some default parameters to use for plotting
    colours = [r.kRed, r.kBlue, r.kGreen, r.kOrange]

    # Get the maximum value of the histograms
    global MAX_Y_VALUE
    for i in range(len(dictOfFiles)):
        max_value = getMaxYValue(dictOfFiles[i]["path"], histogramName, histogramTemplate, prefix, postfix, useDensity)
        if (max_value > MAX_Y_VALUE):
            MAX_Y_VALUE = max_value;
    
    print("Max value: ", MAX_Y_VALUE)

    # Create canvas
    c = r.TCanvas("c","c",800,800)
    c.SetMargin(0.16,0.05,0.13,0.08)
    # Plot histograms
    for i in range(len(dictOfFiles)):
        plot(c, dictOfFiles[i]["path"], histogramName, histogramTemplate, prefix, postfix,useDensity, dictOfFiles[i]["title"], colours[i], "HIST E1 same", REGION)

    # Add legend
    c.BuildLegend(0.7,0.7,0.9,0.9);

    # Save the plot
    c.SaveAs("ShapeComparison_%s%s.pdf" % (histogramName, postfix));
    MAX_Y_VALUE = 0.0
    print("\n")

def main():
    # List of histograms to compare
    histoNamesTemplateDic = {}
    
    histoNamesTemplateDic["tau_pt"] = "tau_pt"
    histoNamesTemplateDic["lep_pt"] = "lep_pt"
    histoNamesTemplateDic["ljet0_pt"] = "ljet0_pt"
    histoNamesTemplateDic["ljet1_pt"] = "ljet1_pt"
    histoNamesTemplateDic["delta_phi"] = "delta_phi"
    histoNamesTemplateDic["delta_y"] = "delta_y"
    histoNamesTemplateDic["mass_jj"] = "mass_jj"
    histoNamesTemplateDic["reco_mass_"] = "reco_mass_"
    histoNamesTemplateDic["Z_centrality"] = "Z_centrality"
    histoNamesTemplateDic["Z_pt_reco_i_basic_all"] = "Z_pt_reco"
    histoNamesTemplateDic["Z_pt_reco_o_basic_all"] = "Z_pt_reco"
    histoNamesTemplateDic["omega"] = "omega"
    histoNamesTemplateDic["bdtScore_basic_all"] = "bdtScore"


    # List of files to compare
    FILE_DICT = [
        {"path" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Signal_truth_MG.root", "title" : "ATLAS MG Zpeak"},
        {"path" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Signal_truth_Sherpa.root", "title" : "ATLAS Sherpa Zpeak"},
        {"path" : "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Signal_truth_PoPy.root", "title" : "ATLAS PoPy Zpeak"},
    ]
    
    PREFIX = ''
    POSTFIX = ''

    # Add missing templates if needed
    global REGION # Create a global variable to store the region dictionary.
    REGION = templatesDict["tautauZpeakHistograms"]
    REGION.append(HistogramInfo('Z_pt_reco', [300], [50, 100], 50, 'pT(Z)',0,0,'GeV'),) # Add things to this dict if needed.
    REGION.append(HistogramInfo('bdtScore', [-0.4, 0.1, 0.5], [0.2, 0.25, 0.2, 0.25], 0.2, 'VBF-BDT score',0.3,1.0,''))

    for histoName, histoTemplate in histoNamesTemplateDic.items():
        compareShapesFromDifferentFiles(histoName, histoTemplate, PREFIX, POSTFIX, FILE_DICT, False)
    
if __name__ == "__main__":
    main()