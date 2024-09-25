import ROOT as r
from histogramHelpers import normalization, biner, HistogramInfo
from histogramHelpers import mumuZpeakHistograms as REGION

### Plot the ratio of two histogram given:
#  A Canvas
#  File path
#  Histogram name
#  Compare density
#  Title
#  Colour
#  Drawing options
#  Region with the histogram parameters.
def plotIndividualRatio(canvas, fileAndHistogramNameDict, postfix, compareDensity, colour, drawingOptions, region : list[HistogramInfo]):

    # Extract the relevant information
    file1Path = fileAndHistogramNameDict["path1"]
    file2Path = fileAndHistogramNameDict["path2"]
    histogramName1 = fileAndHistogramNameDict["histogramName1"]
    histogramName2 = fileAndHistogramNameDict["histogramName2"]
    title1 = fileAndHistogramNameDict["title1"]
    title2 = fileAndHistogramNameDict["title2"]


    # Get hisograms from file
    f1 = r.TFile(file1Path)
    h1 = f1.Get(histogramName1+postfix)
    if not h1:
        print("Histogram ", histogramName1+postfix, " not found in file ", file1Path)
        return
    
    f2 = r.TFile(file2Path)
    h2 = f2.Get(histogramName2+postfix)
    if not h2:
        print("Histogram ", histogramName2+postfix, " not found in file ", file2Path)
        return

    #  Take histogram 1 for the model
    found = False
    histogramInfo = None
    for i in region:
        if i.m_name == histogramName1:
            found = True
            histogramInfo = i
            break
    if not found:
        print("Histogram ", histogramName1, " does not belong to the passed region!")
        return
    
    # Set histogram directory
    h1.SetDirectory(0)
    h2.SetDirectory(0)

    # Rebin the histogram and normalise depending on the desired output
    if histogramInfo.needsRebin():
        rebining=biner(histogramInfo.m_binEdges,histogramInfo.m_binSteps,h1)
        print("Using following bins... ",rebining)
        nb=len(rebining)-1
        h1=h1.Rebin(nb,histogramName1,rebining)
        h2=h2.Rebin(nb,histogramName2,rebining)
        normalization([h1,h2],histogramInfo.m_binNorm)
    # Plot the histogram density if requested
    if (compareDensity):
        h1.Scale(1.0/h1.Integral(1,-1));
        h2.Scale(1.0/h2.Integral(1,-1));

    h2.Divide(h1); # One is always the reference


    # Set the histogram style
    h2.SetTitle(title2);

    canvas.cd();
    canvas.SetTitle("HOLA");
    h2.GetXaxis().SetRange(1,h2.GetNbinsX()+1); 
    h2.GetYaxis().SetRangeUser(0.5,2.0);
    h2.Draw(drawingOptions);
    h2.GetXaxis().SetTitle(histogramInfo.m_xTitle);
    h2.GetYaxis().SetTitle(title2);
    h2.GetXaxis().SetTitleSize(0.056);
    h2.GetYaxis().SetTitleSize(0.056);
    h2.GetXaxis().SetLabelSize(0.056);
    h2.GetYaxis().SetLabelSize(0.056);
    h2.GetYaxis().SetTitleOffset(0.8);
    h2.GetXaxis().SetTitleOffset(0.95);

    h2.SetMarkerStyle(20);
    h2.SetMarkerColor(colour);
    h2.SetLineColor(colour);
    h2.SetLineWidth(4);
    r.gStyle.SetOptStat(0);


def plotRatio(pairsPacket, histoName, postfix, useDensity):
    # Check input
    if (len(pairsPacket) == 0):
        print("No rations to plotompare!")
        return
    if (len(pairsPacket) == 1):
        print("Only reference ratio!")
        return
    if (len(pairsPacket) > 5):
        print("Maximum supported shapes to compare is five! This includes the reference shape.")
        return
    
    # Some default parameters to use for plotting
    colours = [r.kBlack, r.kRed, r.kBlue, r.kGreen, r.kOrange]
    
    # Create canvas
    c = r.TCanvas("c","c",800,800);
    # Plot histograms
    for i in range(0,len(pairsPacket)):
        plotIndividualRatio(c, pairsPacket[i], postfix, useDensity, colours[i], "SAME HIST", REGION)

    # Add legend
    c.BuildLegend(0.7,0.7,0.9,0.9);

    # Save the plot
    c.SaveAs("RatioPlot_%s%s.pdf" % (histoName, postfix));

def generate_plot_input(filePath1, file2Path, histogramName1, histogramName2, title1, title2):
    dic = {
        "path1" : filePath1,
        "path2" : file2Path,
        "histogramName1" : histogramName1,
        "histogramName2" : histogramName2,
        "title1" : title1,
        "title2" : title2
    }
    return dic

def main():
    # List of histograms to compare
    histoNames = ["mass_jj","ljet0_pt","ljet1_pt","lep1_pt","lep2_pt",
                  "n_bjets","delta_y","pt_bal","delta_phi","Z_centrality","n_jets_interval","inv_mass"];
    
    # List of files to compare
    commonPath = '/Users/user/Documents/HEP/VBF-Analysis/MuMu/MC/out/'
    referenceSample = commonPath+'Signal_Sherpa.root'
    samplesToComparePaths = [
        {"path" : referenceSample, "title" : "EWKjj-Sherpa"}, # Reference sample goes always first
        {"path" : commonPath+'Signal_PoPy.root', "title" : "EWKjj-PoPy"},
        {"path" : commonPath+'Signal_MG.root', "title" : "EWKjj-MadGraph"},
    ]

    POSTFIX = ''

    for histoName in histoNames:

        # First plot the reference sample vs reference sample to get the ratio 1
        pairs_packet = []
        pairs_packet.append(generate_plot_input(samplesToComparePaths[0]["path"], samplesToComparePaths[0]["path"], histoName, histoName, samplesToComparePaths[0]["title"], samplesToComparePaths[0]["title"]))

        for i in range(1, len(samplesToComparePaths)):
            pairs_packet.append(generate_plot_input(samplesToComparePaths[0]["path"], samplesToComparePaths[i]["path"], histoName, histoName, samplesToComparePaths[0]["title"], samplesToComparePaths[i]["title"]))

        plotRatio(pairs_packet, histoName, POSTFIX, True)


if __name__ == "__main__":
    main()
