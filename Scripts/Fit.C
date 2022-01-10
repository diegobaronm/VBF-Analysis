#include "Fit.h"
#include "RooStats/HistFactory/Measurement.h"

//========================================================================================================================================================================================================================================================

Fit::Fit(std::string name, std::string folderName, std::string histo) {

	// fit name
	fitName = name;

	histo_name = histo;
	t_histo_name = TString(histo_name);


	// histograms paths and file name
	s_folderName = folderName;
	t_folderName = TString(folderName);

	s_fileName_data = "Data.root";
	t_fileName_data = TString(s_fileName_data);

	s_fileName_qcd_z = "Zee_Sherpa.root";
	t_fileName_qcd_z = TString(s_fileName_qcd_z);

	s_fileName_vbf_z = "Signal.root";
	t_fileName_vbf_z = TString(s_fileName_vbf_z);

	s_fileName_ttbar = "ttbar.root";
	t_fileName_ttbar = TString(s_fileName_ttbar);

	s_fileName_wjets = "Wjets.root";
	t_fileName_wjets = TString(s_fileName_wjets);

	s_fileName_vv = "VV.root";
	t_fileName_vv = TString(s_fileName_vv);

	s_fileName_st = "singletop.root";
	t_fileName_st = TString(s_fileName_st);


	data = new TFile(TString(t_folderName+'/'+t_fileName_data));
	qcd_z = new TFile(TString(t_folderName+'/'+t_fileName_qcd_z));
	vbf_z = new TFile(TString(t_folderName+'/'+t_fileName_vbf_z));
	ttbar = new TFile(TString(t_folderName+'/'+t_fileName_ttbar));
	wjets = new TFile(TString(t_folderName+'/'+t_fileName_wjets));
	vv = new TFile(TString(t_folderName+'/'+t_fileName_vv));
	st = new TFile(TString(t_folderName+'/'+t_fileName_st));

	//m_minX = t_folderName.Contains("3Prong") ? 0.25 : 0.15;

	// set up histograms
	h_data     = (TH1F*)data->Get(t_histo_name);
	h_qcd_z     = (TH1F*)qcd_z->Get(t_histo_name);
	h_vbf_z     = (TH1F*)vbf_z->Get(t_histo_name);
	h_ttbar    = (TH1F*)ttbar->Get(t_histo_name);
	h_wjets    = (TH1F*)wjets->Get(t_histo_name);
	h_vv    = (TH1F*)vv->Get(t_histo_name);
	h_st   = (TH1F*)st->Get(t_histo_name);

	// Subtract BGs from data
	h_data->Add(h_ttbar,-1);
	h_data->Add(h_wjets,-1);
	h_data->Add(h_vv,-1);
	h_data->Add(h_st,-1);

	TFile* rebin_histos = new TFile(t_folderName+'/'+"Rebin_histos.root","RECREATE");
	
	Double_t xbins[10] = {0.0,250.0,500.0,750.0,1000.0,1250.0,1500.0,2000.0,2500.0,3000.0};
	TH1* h_data_for_fit=h_data->Rebin(10);//9,"mass_jj",xbins);
	TH1* h_qcd_z_for_fit=h_qcd_z->Rebin(10);//9,"mass_jj",xbins);
	TH1* h_vbf_z_for_fit=h_vbf_z->Rebin(10);//9,"mass_jj",xbins);

	rebin_histos->WriteTObject(h_data_for_fit,t_histo_name+"_data");
	rebin_histos->WriteTObject(h_qcd_z_for_fit,t_histo_name+"_QCD");
	rebin_histos->WriteTObject(h_vbf_z_for_fit,t_histo_name+"_VBF");

	rebin_histos->Close();

	/*h_data->GetXaxis()->SetRangeUser(m_minX, 1);
	h_tauTruth->GetXaxis()->SetRangeUser(m_minX, 1);
	h_tauFake->GetXaxis()->SetRangeUser(m_minX, 1);*/

}

//========================================================================================================================================================================================================================================================

void Fit::performFit(const TString resultsDir = "results/") {

	// configure model
	RooStats::HistFactory::Measurement meas(fitName.c_str(), fitName.c_str());
	meas.SetOutputFilePrefix("results/results_from_file_" + fitName);

	// norm factors
	meas.SetPOI("VBFNorm");
	meas.SetLumi(1.);
	meas.SetLumiRelErr(0.000001);
	meas.SetExportOnly(true);

	// channels
	RooStats::HistFactory::Channel chan(fitName);
	chan.SetData(histo_name+"_data", s_folderName+'/'+"Rebin_histos.root");
	chan.SetStatErrorConfig(0.01, "Poisson");

	// samples
	// truth Tau
	RooStats::HistFactory::Sample QCD("QCD",histo_name+"_QCD", s_folderName+'/'+"Rebin_histos.root");
	QCD.ActivateStatError();
	QCD.AddNormFactor("QCDNorm", 1., 0.0, 3.);
	chan.AddSample(QCD);

	// fake tau
	RooStats::HistFactory::Sample VBF("VBF",histo_name+"_VBF", s_folderName+'/'+"Rebin_histos.root");
	VBF.ActivateStatError();
	VBF.AddNormFactor("VBFNorm", 1., 0.0, 6.);
	chan.AddSample(VBF);

	// add channel to measurement
	meas.AddChannel(chan);

	// collect histograms and do fit
	meas.CollectHistograms();
	RooWorkspace* results = RooStats::HistFactory::MakeModelAndMeasurementFast(meas);

	// get results
	RooStats::ModelConfig* mc = (RooStats::ModelConfig*)results->obj("ModelConfig");
	RooAbsData* data = results->data("obsData");
	RooFitResult* fitResult = mc->GetPdf()->fitTo(*data, RooFit::PrintLevel(-1));

	// set normalisations and errors
	m_QCDNorm     = results->var("QCDNorm")->getVal();
	m_QCDNormErr  = results->var("QCDNorm")->getError();

	m_VBFNorm     = results->var("VBFNorm")->getVal();
	m_VBFNormErr  = results->var("VBFNorm")->getError();

	// compute chi2
	double chi2 = 0.;
	int unusedBins = 0;
	for (int i = 0; i < h_data->GetNbinsX(); ++i) {
		const double chi2Num   = pow(h_data->GetBinContent(i + 1) - m_QCDNorm * h_qcd_z->GetBinContent(i + 1) - m_VBFNorm * h_vbf_z->GetBinContent(i + 1), 2);
		const double chi2Denom = pow(h_data->GetBinError(i + 1), 2) + pow(m_QCDNorm * h_qcd_z->GetBinError(i + 1), 2) +  pow(m_VBFNorm * h_vbf_z->GetBinError(i + 1), 2);
		const double tempChi2 = chi2Num / chi2Denom;
		if (tempChi2 == tempChi2 && tempChi2 < 500) {
			//std::cout << "h_data: " << h_data->GetBinContent(i+1) << std::endl;
			//std::cout << "h_tauFake: " << m_jetNorm*h_tauFake->GetBinContent(i+1) << std::endl;
			//std::cout << "h_tauTruth: " << m_tauNorm*h_tauTruth->GetBinContent(i+1) << std::endl;
			chi2 += tempChi2;
		}
		else {
			unusedBins += 1;
		}
	}

	const double redChi2 = chi2 / (h_data->GetNbinsX() - 2 - unusedBins);

	// save results
	ofstream outFile(resultsDir + "results_" + TString(fitName) + ".txt");
	//ofstream outFile("results/results_" + fitName + ".txt");
	outFile << "QCDNorm," << m_QCDNorm << "," << m_QCDNormErr << endl;
	outFile << "VBFNorm," << m_VBFNorm << "," << m_VBFNormErr << endl;
	outFile << "chi2 / ndof," << chi2 << " / " << h_data->GetNbinsX() - 2 - unusedBins << " = " << redChi2 << "," << endl;

	outFile.close();

	m_workspace = results;
}

//========================================================================================================================================================================================================================================================

/*void Fit::makePlot(TString prefix, const bool scaleHists, TString channelName, const TString saveDir = "plots/") {

	bool is3Prong = saveDir.Contains("3prong") ? true : false;

	// set ATLAS style
	SetAtlasStyle();

	// scale by fit normalisations
	if (scaleHists) {
		cout << "Scaling hists by: ";
		cout << "Truth tau: " << m_tauNorm << endl;
		cout << "Fake tau: " << m_jetNorm << endl;
		h_tauTruth->Scale(m_tauNorm);
		h_tauFake->Scale(m_jetNorm);
	}

	// MC bkg sum
	TH1F* h_sum = new TH1F("", "", h_data->GetNbinsX(), h_data->GetXaxis()->GetXmin(), h_data->GetXaxis()->GetXmax());
	h_sum->Add(h_tauTruth);
	h_sum->Add(h_tauFake);

	h_sum->SetLineColor(kBlue);
	h_sum->SetFillStyle(3004);
	h_sum->SetMarkerSize(0);

	// fill colours/style
	// data
	h_data->SetMarkerStyle(20);
	h_data->SetMarkerColor(kBlack);
	h_data->SetMarkerSize(1);
	h_data->SetLineColor(kBlack);

	// MC
	h_tauTruth->SetFillColor(kBlue);
	h_tauFake->SetFillColor(kCyan);

	// stack backgrounds
	THStack* hs = new THStack("hs", "hs");
	hs->Add(h_tauFake);
	hs->Add(h_tauTruth);

	// setup canvas
	TCanvas* can = new TCanvas(TString(fitName), TString(fitName), 600, 600);
	TPad* pad1 = new TPad(TString(fitName) + "_pad1", TString(fitName) + "_pad1", 0, 0.4, 1, 1);
	pad1->SetBottomMargin(0.03);
	pad1->Draw();
	pad1->cd();

	// log scale
	//pad1->SetLogy();
	//h_data->SetMinimum(1);
	h_data->SetMinimum(0);

	// need to scale prefit plots
	if (!scaleHists) {
		if (TString(fitName).Contains("0lightjet")) {
			// fine bins
			//h_data->SetMaximum(h_data->GetMaximum() * 1.35);

			// coarse bins
			h_data->SetMaximum(h_data->GetMaximum() * 1.6);
		}

		else if (TString(fitName).Contains("Fail")) {
			// fine bins
			//h_data->SetMaximum(h_data->GetMaximum() * 1.1);

			// coarse bins
			h_data->SetMaximum(h_data->GetMaximum() * 1.6);
		}

		else {
			// fine bins
			//h_data->SetMaximum(h_data->GetMaximum() * 1.2);

			// coarse bins
			h_data->SetMaximum(h_data->GetMaximum() * 1.6);
		}
	}


	// titles
	h_data->GetXaxis()->SetTitle("#tau_{had}-jet RNN score");
	h_data->GetYaxis()->SetTitle("Events / 0.1");
	h_data->GetXaxis()->SetTitleSize(1.5 * h_data->GetXaxis()->GetTitleSize());
	h_data->GetYaxis()->SetTitleSize(1.1 * h_data->GetYaxis()->GetTitleSize());
	h_data->GetYaxis()->SetTitleOffset(1.1);
	// remove axis labels on x axis, they are shown on the ratio pad
	h_data->GetXaxis()->SetLabelSize(400.);

	// draw
	h_data->Draw("P E1");
	h_sum->Draw("same E2");
	hs->Draw("HIST same");
	h_data->Draw("P E1 same");

	// legend
	TLegend* leg;
	if (TString(fitName).Contains("0lightjet")) {
		// fine bins
		leg = is3Prong ? new TLegend(0.5, 0.6, 0.9, 0.95) : new TLegend(0.5, 0.65, 0.9, 0.95);

		// coarse bins
		leg = new TLegend(0.5, 0.7, 0.9, 0.95);
	}
	else {
		// fine bins
		//leg = is3Prong ? new TLegend(0.5, 0.55, 0.9, 0.9) : new TLegend(0.5, 0.5, 0.9, 0.92);

		// coarse bins
		leg = new TLegend(0.5, 0.7, 0.9, 0.95);
	}

	leg->AddEntry(h_data, "Data*", "LP");
	leg->AddEntry(h_tauTruth, "True #tau_{had}", "F");
	leg->AddEntry(h_tauFake, "Fake #tau_{had}", "F");

	leg->SetTextSize(1.2 * leg->GetTextSize());
	leg->SetNColumns(2);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);

	leg->Draw("same");

	gPad->Update();
	gPad->RedrawAxis();

	// drawing ATLAS label and stuff
	// fine bins
	//double xPosLogo = is3Prong ? 0.3 : 0.3;
	//double yPosLogo = is3Prong ? 0.8 : 0.8;

	// coarse bins
	double xPosLogo = 0.2;
	double yPosLogo = 0.85;

	TString lumi = "#sqrt{s} = 13 TeV, #lower[-0.2]{#scale[0.6]{#int}} Ldt = 139 fb^{-1}";
	TString prongLabel = is3Prong ? "3-prong" : "1-prong";

	ATLAS_LABEL(xPosLogo, yPosLogo, kBlack);
	myText(xPosLogo+0.1, yPosLogo, kBlack, "Internal");
	myText(xPosLogo, yPosLogo-0.19, kBlack, lumi);
	//myText(xPosLogo, yPosLogo-0.25, kBlack, prongLabel);

	// channel labels
	myText(xPosLogo, yPosLogo - 0.075, kBlack, channelName + ", " + prongLabel);


	// ratio pad
	can->cd();
	TPad* pad2 = new TPad("pad2_" + TString(fitName), "pad2_" + TString(fitName), 0, 0.05, 1, 0.4);
	pad2->SetTopMargin(0.02);
	pad2->SetBottomMargin(0.3);
	pad2->Draw();
	pad2->cd();

	TH1F* h_ratio = (TH1F*)h_data->Clone("h_ratio");
	h_ratio->SetLineColor(kBlack);
	h_ratio->GetYaxis()->SetLabelSize(h_ratio->GetYaxis()->GetLabelSize() * 1.5);
	h_ratio->GetYaxis()->SetTitle("Data* / Pred.");
	h_ratio->GetYaxis()->SetTitleSize(h_ratio->GetYaxis()->GetTitleSize() * 1.6);
	h_ratio->GetYaxis()->SetTitleOffset(0.8);

	h_ratio->GetXaxis()->SetTitle(h_data->GetXaxis()->GetTitle());
	h_ratio->GetXaxis()->SetTitleSize(0.1);
	h_ratio->GetXaxis()->SetLabelSize(0.08);
	h_ratio->SetMaximum(1.2);
	h_ratio->SetMinimum(0.8);

	for (int i = 0; i < h_ratio->GetNbinsX() + 1; ++i) {
		h_ratio->SetBinContent(i, h_ratio->GetBinContent(i) / h_sum->GetBinContent(i));
		h_ratio->SetBinError(i, h_ratio->GetBinError(i) / h_sum->GetBinContent(i));
	}

	// stat. err.
	TH1F* h_err = (TH1F*)h_sum->Clone("h_err");
	h_err->Divide(h_sum);
	for (int bin = 0; bin <= h_err->GetNbinsX(); ++bin) {
		if (h_sum->GetBinContent(bin + 1) != 0) {
			h_err->SetBinError(bin + 1, h_sum->GetBinError(bin + 1) / h_sum->GetBinContent(bin + 1));
		}
	}

	h_err->SetFillColor(kBlue);
	h_err->SetFillStyle(3004);
	h_err->SetMarkerStyle(0);
	h_err->SetLineStyle(0);
	h_err->SetLineColor(kBlack);

	h_ratio->Draw("P E1");
	h_err->Draw("same E2");
	leg->AddEntry(h_err, "Stat. Unc.", "F");

	// line at 1
	TLine* line = new TLine(m_minX, 1, h_data->GetXaxis()->GetXmax(), 1);
	line->SetLineColor(kBlack);
	line->SetLineStyle(kDashed);
	line->Draw("same");

	can->SaveAs(saveDir + prefix + "_" + TString(fitName) + ".pdf");
	//can->SaveAs("plots/" + prefix + "_" + TString(fitName) + ".pdf");
}*/
