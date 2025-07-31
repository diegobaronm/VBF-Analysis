import ROOT as r

from RatioShapes import generate_plot_input, get_scale_factors
from histogramHelpers import templatesDict, normalization, biner, HistogramInfo

### Plot the ratio of two histogram given:
#  A Canvas
#  File path
#  Histogram name
#  Compare density
#  Title
#  Colour
#  Drawing options
#  Region with the histogram parameters.
def RatioPlot(canvas, fileAndHistogramNameDict, postfix, compareDensity, colour, drawingOptions, region : list[HistogramInfo], apply_scale_factors):

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
        h1.Scale(1.0/h1.Integral(1,2))
        h2.Scale(1.0/h2.Integral(1,2))

    h2.Divide(h1) # One is always the reference


    # Set the histogram style
    h2.SetTitle("%s/%s" % (title2, title1))

    # Get the ratio factors
    scale_factors = get_scale_factors(h2)
    print("Scale factors to take %s to %s: " % (title2, title1), scale_factors)

    # Apply the scale factors if needed
    if apply_scale_factors:
        for i in range(1, h2.GetNbinsX() + 1 + 1):
            h2.SetBinContent(i, h2.GetBinContent(i) * scale_factors[i-1])

    canvas.cd()
    canvas.SetTitle("HOLA")
    h2.GetXaxis().SetRange(1,h2.GetNbinsX()+1) 
    h2.GetYaxis().SetRangeUser(0.01,2.0)
    h2.GetXaxis().SetRangeUser(0,2.0)
    h2.Draw(drawingOptions)
    h2.GetXaxis().SetTitle(histogramInfo.m_xTitle)
    h2.GetYaxis().SetTitle("Events/"+str(histogramInfo.m_binNorm)+" "+histogramInfo.m_units)
    h2.GetXaxis().SetTitleSize(0.056)
    h2.GetYaxis().SetTitleSize(0.056)
    h2.GetXaxis().SetLabelSize(0.056)
    h2.GetYaxis().SetLabelSize(0.056)
    h2.GetYaxis().SetTitleOffset(1.45)
    h2.GetXaxis().SetTitleOffset(1.00)

    h2.SetMarkerStyle(20)
    h2.SetMarkerColor(colour)
    h2.SetLineColor(colour)
    h2.SetLineWidth(4)
    r.gStyle.SetOptStat(0)



if __name__ == "__main__":
    qcd_sample = 'Zll_PoPy'
    inputs_dictionary = generate_plot_input(
        filePath1 = '/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/Zll/NewZpeak/SR/%s.root' % qcd_sample,
        file2Path = '/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/Zll/NewZpeak/CRc/%s.root' % qcd_sample,
        histogramName1 = 'n_jets_interval',
        histogramName2 = 'n_jets_interval',
        title1 = 'SR+CRa',
        title2 = 'CRc+CRb'
    )

    # Create canvas
    c = r.TCanvas("c","c",800,800)
    c.SetMargin(0.16,0.05,0.13,0.08)

    # Make modifications to the histogram parameters
    histogram_models_list = templatesDict['llZpeakHistograms']
    # Pop the Z_centrality histogram
    histogram_to_replace = None
    for i in range(len(histogram_models_list)):
        if histogram_models_list[i].m_name == 'Z_centrality':
            histogram_to_replace = histogram_models_list[i]
            histogram_models_list.pop(i)
            break
    histogram_to_replace
    # Do the modifications
    histogram_to_replace.m_binEdges = [1.0]
    histogram_to_replace.m_binSteps = [0.5,0.5]
    histogram_to_replace.m_binNorm = 0.5
    # Put it back
    histogram_models_list.append(histogram_to_replace)


    # Plot Ratio
    RatioPlot(
        canvas = c, fileAndHistogramNameDict = inputs_dictionary,
        postfix = '',
        compareDensity = True,
        colour = r.kBlue,
        drawingOptions = "HIST E1",
        region = histogram_models_list,
        apply_scale_factors = False,
    )

    # Add legend
    c.BuildLegend(0.7,0.7,0.9,0.9)

    # Save the plot
    c.SaveAs("results/RatioPlot_%s%s_QCD%s.pdf" % ('NGapJets_SR_CRc', '', qcd_sample.replace('Zll_','')))