void plot2D(){
    std::vector<double> binEdges = {0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300, 325, 350, 375, 400, 425, 450, 475, 500};


    TFile *f = TFile::Open("TotalSignal.root");
    TH2F* h2d = (TH2F*)f->Get("trueMass_2D_lepTransMass_basic_all");
    TH1D* h1 = (TH1D*)h2d->ProjectionY("66to116", 66, 116);
    h1->SetTitle("66 to 116 GeV");
    h1 = (TH1D*)h1->Rebin(binEdges.size()-1, "66to116", binEdges.data());
    h1->Scale(1.0/h1->Integral(1,-1));
    h1->Draw();

    TH1D* h2 = (TH1D*)h2d->ProjectionY("116to160", 116, 160);
    h2->SetTitle("116 to 160 GeV");
    h2 = (TH1D*)h2->Rebin(binEdges.size()-1, "116to160", binEdges.data());
    h2->SetLineColor(kRed);
    h2->Scale(1.0/h2->Integral(1,-1));
    h2->Draw("same");

    TH1D* h3 = (TH1D*)h2d->ProjectionY("160to400", 160, 400);
    h3->SetTitle("160 to 400 GeV");
    h3 = (TH1D*)h3->Rebin(binEdges.size()-1, "160to400", binEdges.data());
    h3->SetLineColor(kGreen);
    h3->Scale(1.0/h3->Integral(1,-1));
    h3->Draw("same");

    TH1D* h4 = (TH1D*)h2d->ProjectionY("400to1000", 400, 1000);
    h4->SetTitle("400 to 1000 GeV");
    h4 = (TH1D*)h4->Rebin(binEdges.size()-1, "400to1000", binEdges.data());
    h4->SetLineColor(kViolet);
    h4->Scale(1.0/h4->Integral(1,-1));
    h4->Draw("same");

    h1->GetXaxis()->SetTitle("m_{T}(l)");
    h1->GetYaxis()->SetTitle("Events/25 GeV");
    h1->GetXaxis()->SetTitleSize(0.05);
    h1->GetYaxis()->SetTitleSize(0.05);
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetTitleOffset(0.8);
    h1->GetXaxis()->SetTitleOffset(0.85);
    gStyle->SetOptStat(0);

    gPad->BuildLegend();
}