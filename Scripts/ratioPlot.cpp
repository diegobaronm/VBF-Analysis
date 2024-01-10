
std::vector<double> g_binEdgesTrueMass = {0, 66, 76, 86, 96, 106, 116, 127, 138, 149, 160, 180, 200, 250, 300, 400, 500, 750, 1000};
const char* g_titleTrueMass = "m_{true}(#tau,#tau) GeV";

std::vector<double> g_binEdgesMassJJ = {0, 250, 500, 750, 1000, 1250, 1500, 2000, 3000, 5000};
const char* g_titleMassJJ = "m_{jj} GeV";

std::vector<double> g_binEdges = g_binEdgesMassJJ;

TCanvas *g_canvas = new TCanvas("c1", "c1", 600, 600);
bool g_rebin = true;
bool g_plotDensity = true;
bool g_simpleBinning = false;
int g_nbins = g_binEdges.size()-1;
float g_binNormalisation = 250.0;
std::string g_units = " GeV";
const char* g_title = g_titleMassJJ;

TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

// Plots ratio h1/h2
void plotRatio(TCanvas *canvas, const char* fileName1, const char* histogramName1, const char* fileName2, const char* histogramName2,
                 const char* title,EColor color, const char* drawingOptions){

    TFile *f1 = new TFile(fileName1);
    TH1F* h1 = (TH1F*)f1->Get(histogramName1);

    TFile *f2 = new TFile(fileName2);
    TH1F* h2 = (TH1F*)f2->Get(histogramName2);

    // Rebin the histograms
    if (g_rebin) {
        if (g_simpleBinning){
            h1 = (TH1F*)h1->Rebin(g_nbins);
            h2 = (TH1F*)h2->Rebin(g_nbins);
        } else {
            h1 = (TH1F*)h1->Rebin(g_nbins, "h1", g_binEdges.data());
            h2 = (TH1F*)h2->Rebin(g_nbins, "h2", g_binEdges.data());
        } 
    }

    if (g_plotDensity){
        h1->Scale(1.0/h1->Integral(1,-1));
        h2->Scale(1.0/h2->Integral(1,-1));
    } 

    // Normalize the histogram if variable binning has been applied.
    if (g_rebin && !g_simpleBinning){
        h1->Scale(g_binNormalisation, "width");
        h2->Scale(g_binNormalisation, "width");
    } 
    h1->Divide(h2);

    h1->SetTitle(title);

    canvas->cd();

    h1->GetXaxis()->SetRange(1,h1->GetNbinsX()+1); //Draw overflow bin
    h1->GetYaxis()->SetRangeUser(-0.5,4);
    h1->Draw(drawingOptions);

    h1->GetXaxis()->SetTitle(g_title);
    std::string ytitle = std::string("Events/")+std::to_string(g_binNormalisation)+g_units;
    h1->GetYaxis()->SetTitle(ytitle.c_str());
    h1->GetXaxis()->SetTitleSize(0.056);
    h1->GetYaxis()->SetTitleSize(0.056);
    h1->GetXaxis()->SetLabelSize(0.056);
    h1->GetYaxis()->SetLabelSize(0.056);
    h1->GetYaxis()->SetTitleOffset(0.8);
    h1->GetXaxis()->SetTitleOffset(0.85);

    h1->SetMarkerStyle(20);
    h1->SetMarkerColor(color);
    h1->SetLineColor(color);
    h1->SetLineWidth(4);
    if(std::string(drawingOptions).find("HIST") == std::string::npos) h1->SetFillColorAlpha(color,0.5);
    gStyle->SetOptStat(0);
}

void ratioPlot(){

    // Comparing QCDjj MGNLO Zll vs Ztautau
    const char* histogram = "mass_jj";
    const char* SherpaZll = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/Zll/Z-peak/SR/Zll_SherpaRW.root";
    const char* MGNLOZll = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/Zll/Z-peak/SR/Zll_MGNLORW2.root";
    const char* SherpaZtautau = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Ztautau_SherpaRW.root";
    const char* MGNLOZtautau = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Ztautau_MGNLORW2.root";
    
    plotRatio(c1, SherpaZtautau, histogram, SherpaZll, histogram, "SherpaRW",kBlack, "SAME E1 X0 L P");
    plotRatio(c1, SherpaZtautau, histogram, SherpaZll, histogram, "SherpaRW",kBlack, "SAME HIST C");

    plotRatio(c1, MGNLOZtautau, histogram, MGNLOZll, histogram, "SherpaRW",kBlue, "SAME E1 X0 L P");
    plotRatio(c1, MGNLOZtautau, histogram, MGNLOZll, histogram, "SherpaRW",kBlue, "SAME HIST C");
    
    gPad->BuildLegend();
    
    /*
    // Comparing different QCD shapes
    const char* histogram = "mass_jj";
    const char* referenceSample = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Ztautau_SherpaRW.root"; // Sherpa RW Flat
    const char* MGFlat = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Ztautau_MGRW.root";
    //const char* MGNLO = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/MuMu/Z-peak/SR/Zmumu_MGNLORW.root";
    const char* MGNLOFlat = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/SR/Ztautau_MGNLORW2.root";
    //const char* SherpaNLO = "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/MuMu/Z-peak/SR/Zmumu_SherpaNLORW.root";

    plotRatio(c1, referenceSample, histogram, referenceSample, histogram, "Sherpa-FlatRW",kBlack, "SAME E1 X0 L P");
    plotRatio(c1, referenceSample, histogram, referenceSample, histogram, "Sherpa-FlatRW",kBlack, "SAME HIST C");
    plotRatio(c1, MGFlat, histogram, referenceSample, histogram, "MG-FlatRW",kBlue, "SAME E1 X0 L P");
    plotRatio(c1, MGFlat, histogram, referenceSample, histogram, "MG-FlatRW",kBlue, "SAME HIST C");
    //plotRatio(c1, MGNLO, histogram, referenceSample, histogram, "MGNLO-RW",kGreen, "SAME E1 X0 L P");
    //plotRatio(c1, MGNLO, histogram, referenceSample, histogram, "MGNLO-RW",kGreen, "SAME HIST C");
    plotRatio(c1, MGNLOFlat, histogram, referenceSample, histogram, "MGNLO-FlatRW",kPink, "SAME E1 X0 L P");
    plotRatio(c1, MGNLOFlat, histogram, referenceSample, histogram, "MGNLO-FlatRW",kPink, "SAME HIST C");
    //plotRatio(c1, SherpaNLO, histogram, referenceSample, histogram, "SherpaNLORW",kYellow, "SAME E1 X0 L P");
    //plotRatio(c1, SherpaNLO, histogram, referenceSample, histogram, "SherpaNLORW",kYellow, "SAME HIST C");
    
    //plotRatio(c1, MGNLOFlat, histogram, MGNLO, histogram, "MGNLOFlat/Quadratic",kRed, "SAME E1 X0 L P");
    //plotRatio(c1, MGNLOFlat, histogram, MGNLO, histogram, "MGNLOFlat/Quadratic",kRed, "SAME HIST C");
    */
}
