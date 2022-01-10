// roofit
#include "RooStats/HistFactory/Measurement.h"

// ATLAS style
/*#include "style/AtlasUtils.h"
#include "style/AtlasStyle.h"
#include "style/AtlasUtils.C"
#include "style/AtlasStyle.C"*/

class Fit {
	private:

		// name of this fit
		std::string fitName;

		std::string histo_name;
		TString t_histo_name;

		// file with histograms in
		std::string s_fileName_data;
		std::string s_fileName_qcd_z;
		std::string s_fileName_vbf_z;
		std::string s_fileName_ttbar;
		std::string s_fileName_wjets;
		std::string s_fileName_vv;
		std::string s_fileName_st;

		// file with histograms in
		TString t_fileName_data;
		TString t_fileName_qcd_z;
		TString t_fileName_vbf_z;
		TString t_fileName_ttbar;
		TString t_fileName_wjets;
		TString t_fileName_vv;
		TString t_fileName_st;

		// folderName
		std::string s_folderName;
		TString t_folderName;

		// pointer to TFiles
		TFile* data;
		TFile* qcd_z;
		TFile* vbf_z;
		TFile* ttbar;
		TFile* wjets;
		TFile* vv;
		TFile* st;

		// histograms
		TH1F* h_data;
		TH1F* h_qcd_z;
		TH1F* h_vbf_z;
		TH1F* h_ttbar;
		TH1F* h_wjets;
		TH1F* h_vv;
		TH1F* h_st;

		// fit workspace
		RooWorkspace* m_workspace;

		double m_minX = 0.;

		// fit normalisations
		double m_QCDNorm;
		double m_QCDNormErr;

		double m_VBFNorm;
		double m_VBFNormErr;

	public:

		// constructor, set up histograms
		Fit(std::string name, std::string folderName, std::string histo);

		// destructor
		~Fit() {
			// ownership of all objects is handled by file pointer
			//f->Close();
		}

		TH1F* getDataHist() {
			return h_data;
		}

		TH1F* getQCDHist() {
			return h_qcd_z;
		}

		TH1F* getVBFHist() {
			return h_vbf_z;
		}

		double getQCDNorm() {
			return m_QCDNorm;
		}

		double geQCDNormErr() {
			return m_QCDNormErr;
		}

		double getVBFNorm() {
			return m_VBFNorm;
		}

		double getVBFNormErr() {
			return m_VBFNormErr;
		}

		// do fit
		void performFit(const TString resultsDir);

		// make plots
		//void makePlot(TString prefix, const bool scaleHists, TString channelName, const TString saveDir);

		/*void makePrefitPlot(TString channelName, const TString saveDir = "plots/") {
			// wrapper to makePlot with scaleHists set to false
			makePlot("prefit", false, channelName, saveDir);
		}

		void makePostfitPlot(TString channelName, const TString saveDir = "plots/") {
			// wrapper to makePlot with scaleHists set to true
			makePlot("postfit", true, channelName, saveDir);
		}*/
};