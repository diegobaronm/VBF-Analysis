
std::vector<double> g_binEdges = {0, 66, 76, 86, 96, 106, 116, 127, 138, 149, 160, 180, 200, 250, 300, 400, 500, 750, 1000};

TCanvas *g_canvas = new TCanvas("c1", "c1", 600, 600);
bool g_rebin = true;
bool g_plotDensity = false;
int g_nbins = 65;
std::string g_units = " GeV";
const char* g_title = "m_{true}(#tau,#tau) GeV";

void plot(TCanvas *canvas, const char* fileName, const char* histogramName, const char* title,EColor color, const char* drawingOptions){
    TFile *f1 = new TFile(fileName);
    TH1F* h1 = (TH1F*)f1->Get(histogramName);

    if (g_rebin) h1 = (TH1F*)h1->Rebin(g_nbins);
    if (g_plotDensity) h1->Scale(1.0/h1->Integral(1,-1));

    h1->SetTitle(title);

    canvas->cd();

    h1->GetXaxis()->SetRange(1,h1->GetNbinsX()+1); //Draw overflow bin
    h1->GetYaxis()->SetRangeUser(0,1.4);
    h1->Draw(drawingOptions);

    h1->GetXaxis()->SetTitle(g_title);
    std::string ytitle = std::string("Events/")+std::to_string(g_nbins)+g_units;
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
    gStyle->SetOptStat(0);
}

void compareShapes(){
    // Comparing different BDTs
    plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/TauTau/TauhadTaulep/High-Mass/TruthSignalNewBDT/Signal_PoPy.root", "true_mass_basic_all", "New BDT",kBlue, "SAME L HIST P");
    plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/TauTau/TauhadTaulep/High-Mass/TruthSignalNewBDT/Signal_PoPy.root", "true_mass_basic_all", "New BDT",kBlue, "SAME L E1 X0");
    plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/TauTau/TauhadTaulep/High-Mass/TruthSignalOriginalBDT/Signal_PoPy.root", "true_mass_basic_all", "Original BDT",kRed, "SAME L HIST P");
    //plot(g_canvas, std::string("SignalPow0.3"), kGreen, "SAME L E1 X0");
    //plot(g_canvas, std::string("SignalPow0.3"), kGreen, "SAME L HIST");
    

    // Just one BDT
    //plotRatio(c1, std::string("SignalNOmT"),kBlue, "SAME E1 X0");

    g_canvas->BuildLegend();
}
