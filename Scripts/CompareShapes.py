import ROOT as r
from histogramHelpers import normalization, biner, HistogramInfo
from histogramHelpers import tautauZpeakHistograms as REGION

### Plot one histogram given:
#  A Canvas
#  File path
#  Histogram name
#  Compare density
#  Title
#  Colour
#  Drawing options
#  Region with the histogram parameters.
def plot(canvas, fileName, histogramName, compareDensity, title, colour, drawingOptions, region : list[HistogramInfo]):
    # Get hisogram from file
    f1 = r.TFile(fileName)
    h1 = f1.Get(histogramName)
    if not h1:
        print("Histogram ", histogramName, " not found in file ", fileName)
        return
    
    # Check if the histograms belongs to the region
    found = False
    histogramInfo = None
    for i in region:
        if i.m_name == histogramName:
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
    # Get the maximum value of the histogram
    max_value = h1.GetMaximum();
    h1.GetYaxis().SetRangeUser(0.0,max_value*1.2);
    if (histogramInfo.m_logScale):
        canvas.SetLogy();
        h1.GetYaxis().SetRangeUser(0.01,1.0);
    h1.Draw(drawingOptions);

    h1.GetXaxis().SetTitle(title);
    ytitle = "Events/"+str(histogramInfo.m_binNorm)+str(histogramInfo.m_units);
    h1.GetYaxis().SetTitle(ytitle);
    h1.GetXaxis().SetTitleSize(0.056);
    h1.GetYaxis().SetTitleSize(0.056);
    h1.GetXaxis().SetLabelSize(0.056);
    h1.GetYaxis().SetLabelSize(0.056);
    h1.GetYaxis().SetTitleOffset(0.8);
    h1.GetXaxis().SetTitleOffset(0.85);

    h1.SetMarkerStyle(20);
    h1.SetMarkerColor(colour);
    h1.SetLineColor(colour);
    r.gStyle.SetOptStat(0);

    # Close the file
    f1.Close();

def compareShapesFromDifferentFiles(histogramName, dictOfFiles, useDensity):
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
    
    # Create canvas
    c = r.TCanvas("c","c",800,800);
    # Plot histograms
    for i in range(len(dictOfFiles)):
        plot(c, dictOfFiles[i]["path"], histogramName, useDensity, dictOfFiles[i]["title"], colours[i], "HIST E1 same", REGION)

    # Add legend
    c.BuildLegend(0.7,0.7,0.9,0.9);

    # Save the plot
    c.SaveAs("ShapeComparisonAllZpeakCutsApplied_"+histogramName+".pdf");



def main():
    # List of histograms to compare
    histoNames = ["mass_jj","ljet0_pt","ljet1_pt","lep_pt","tau_pt","omega",
                                            "n_bjets","delta_y","pt_bal","delta_phi","Z_centrality","n_jets_interval","reco_mass_"];
    
    # List of files to compare
    FILE_DICT = [
        {"path" : "/Users/user/Documents/HEP/VBF-Analysis/TauMu/MC/out/Signal_Sherpa.root", "title" : "EWKjj-Sherpa"},
        {"path" : "/Users/user/Documents/HEP/VBF-Analysis/TauMu/MC/out/Signal_PoPy.root", "title" : "EWKjj-PoPy"},
        {"path" : "/Users/user/Documents/HEP/VBF-Analysis/TauMu/MC/out/Signal_MG.root", "title" : "EWKjj-MadGraph"},
    ]
    
    for histoName in histoNames:
        compareShapesFromDifferentFiles(histoName, FILE_DICT, True)
    
if __name__ == "__main__":
    main()