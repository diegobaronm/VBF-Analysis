std::vector<double> g_binEdgesTrueMass = {0,66,130, 200, 300, 400, 500, 750, 1000};
const char* g_titleTrueMass = "m_{true}(#tau,#tau) GeV";

std::vector<double> g_binEdgesMassJJ = {0, 250, 500, 750, 1000, 1250, 1500, 2000, 3000, 4000, 5000};
const char* g_titleMassJJ = "m_{jj} GeV";

std::vector<double> g_binEdges = g_binEdgesTrueMass;

TCanvas *g_canvas = new TCanvas("c1", "c1", 600, 600);
bool g_rebin = false;
bool g_plotDensity = true;
bool g_simpleBinning = false;
int g_nbins = g_binEdges.size()-1;
float g_binNormalisation = 70.0;
std::string g_units = " GeV";
const char* g_title = g_titleTrueMass;
std::map<std::string,double> g_SampleNormalisation = {
    {"EWjj Sherpa",1.121},
    {"EWjj PowHeg+Pythia8",0.908}
};
bool g_normalise = false;

void plot(TCanvas *canvas, const char* fileName, const char* histogramName, const char* title,EColor color, const char* drawingOptions){
    TFile *f1 = new TFile(fileName);
    TH1F* h1 = (TH1F*)f1->Get(histogramName);
    if (!h1) {
        std::cout << "Histogram " << histogramName << " not found in file " << fileName << std::endl;
        return;
    }

    h1->SetDirectory(0);
    
    // Rebin the histogram
    if (g_rebin) {
        if (g_simpleBinning) h1 = (TH1F*)h1->Rebin(g_nbins);
        else h1 = (TH1F*)h1->Rebin(g_nbins, "h1", g_binEdges.data());
    }

    // Normalize the histogram to the scaling factor if needed.
    if (g_normalise) h1->Scale(g_SampleNormalisation[title]);
    std::cout<< "Integral before 130 = "<<h1->Integral(1,2)<<std::endl;

    if (g_plotDensity) h1->Scale(1.0/h1->Integral(1,-1));

    // Normalize the histogram if variable binning has been applied.

    if (g_rebin && !g_simpleBinning) h1->Scale(g_binNormalisation, "width");

    h1->SetTitle(title);
    
    canvas->cd();

    h1->GetXaxis()->SetRange(1,h1->GetNbinsX()+1); //Draw overflow bin
    h1->GetYaxis()->SetRangeUser(0.01,1.0);
    //Plot log scale
    canvas->SetLogy();   
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
    gStyle->SetOptStat(0);
    f1->Close();
}

void compareShapesName(const std::string& histoTitle){
    // Comparing different BDTs
    //plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/MuMu/Plots/Z-peak/SR/Zmumu_SherpaRW-Alternative.root", "mass_jj", "Alternative RW - EWjj PoPy + SF",kBlue, "SAME L HIST P");
    //plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/MuMu/Plots/Z-peak/SR/Zmumu_SherpaRW-Alternative.root", "mass_jj", "Alternative RW - EWjj PoPy + SF",kBlue, "SAME L E1 X0");
    //plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/NewBDTTruthTightTau/Signal_Sherpa.root", "true_mass_basic_all", "EWjj Sherpa",kBlue, "SAME HIST E1");
    //plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/NewBDTTruthTightTau/Signal_PoPy.root", "true_mass_basic_all", "EWjj PowHeg+Pythia8",kRed, "SAME HIST E1");
    //plot(g_canvas, "/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/TauhadTaulep/High-Mass/NewBDTTruthTightTau/Signal_Sherpa.root", "mass_jj", "Alternative RW - EWjj PoPy + SF",kBlue, "SAME HIST P E1");
    //plot(g_canvas, std::string("SignalPow0.3"), kGreen, "SAME L E1 X0");
    //plot(g_canvas, std::string("SignalPow0.3"), kGreen, "SAME L HIST"); 
    std::string prefix = "rec_";
    std::string postfix = "_SR_VBFZ_OSs2thh";
    std::string title_str = (prefix+histoTitle+postfix);
    const char* title = title_str.c_str();
    // Comparing different samples
    //plot(g_canvas, "/Users/user/Downloads/EWjj.root", title, "EWjj Sherpa",kBlue, "HIST E1");
    plot(g_canvas, "/Users/user/Downloads/QCDjj.root", title, "QCDjj Sherpa",kRed, "HIST E1 same");

    g_canvas->BuildLegend();
    // Save plot to file
    //std::string fileName_str = ("hadhadplots/"+histoTitle+".pdf");
    //const char* fileName = fileName_str.c_str();
    //g_canvas->SaveAs(fileName);
    g_canvas->Print();
    //g_canvas->Clear();
}



void compareShapes(){
    std::vector<std::string> histoTitles = {"mass_jj","pt_jet1","pt_jet2","pt_tau1","pt_tau2","omega",
                                            "n_bjets","delta_y","pt_bal","delta_phi","Z_centrality","n_jets_interval","dilepton_mass"};
    compareShapesName("dilepton_mass");   
    //for (const auto& histoTitle : histoTitles) compareShapesName(histoTitle);
    
}