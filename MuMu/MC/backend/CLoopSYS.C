#define CLoopSYS_cxx

#include "CLoopSYS.h"
#include "../AnalysisSYS.C"
#include <cmath>
#include "../../../AnalysisCommons/reweightingTools.h"
#include"../../../AnalysisCommons/Tools.h"
#include"../../../AnalysisCommons/Kinematics.h"

void CLoopSYS::Loop(double lumFactor, int z_sample, const std::string& key, int logLevel){

  clock_t startTime = clock(); // get start time

  // Set the logging level
  g_LOG.setLogLevel(static_cast<LogLevel>(logLevel));

  if (fChain == 0) return;

  // book histograms
  Book();

  // Tell user number of events to run
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nLoop = nentries;
  Long64_t nLoop_five_percent = nentries/20;
  g_LOG(LogLevel::INFO,"Number of events to analyse = ", nLoop);
  Long64_t nbytes = 0, nb = 0;

  // Create output file for the events passing the selection
  std::string keyRoot = key + ".root";
  const char*  name_root = keyRoot.c_str();

  // open output file
  TFile outfile(name_root,"UPDATE");

  // loop over number of entries
  for (Long64_t jentry=0; jentry<nLoop;jentry++) {
    g_LOG(LogLevel::DEBUG," ");
    g_LOG(LogLevel::DEBUG,"New Event n = ", jentry);
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry,0);    nbytes += nb;

    // Print progress...
    if (nLoop >= 1000000 && jentry % nLoop_five_percent ==0 && jentry>0 ) {
        g_LOG(LogLevel::INFO, 100*double(jentry)/nLoop, "% Analysed.");
    }

    // Variables defining regions
    // DELTA RAPIDITY 2-JETS
    double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());
    // NUMBER OF JETS INTERVAL
    size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;
    int n_jets_interval{};
    if(n_ljets>2){
      n_jets_interval=n_jets_interval+Kinematics::is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4);
    }
    // Z BOSON CENTRALITY
    double lepton_xi=((*muon_0_p4)+(*muon_1_p4)).Rapidity();
    double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
    double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

    Region region = Region::DefaultNoRW;
    if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::SR;}
    else if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRa;}
    else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRb;}
    else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::CRc;}

    // Mjj reweighting
    double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
    bool do_data_driven = true;
    bool do_mc_driven = true;

    double mjj_w = calculateMjjWeight(do_data_driven, do_mc_driven, mjj, region, z_sample);

    // calculate event weight
    double eventWeight = 1;

    g_LOG(LogLevel::DEBUG,"Initial event w = ", eventWeight);
    g_LOG(LogLevel::DEBUG,"MC w = ", weight_mc);
    g_LOG(LogLevel::DEBUG,"Mjj w = ", mjj_w);
    g_LOG(LogLevel::DEBUG,"Lumfactor w = ", lumFactor);
    g_LOG(LogLevel::DEBUG,"PU w = ", NOMINAL_pileup_combined_weight);
    g_LOG(LogLevel::DEBUG,"Muon 1 SFs = ", muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium*muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium
        *muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
    g_LOG(LogLevel::DEBUG,"Muon 2 SFs = ", muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium*muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium
        *muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_1_NOMINAL_MuEffSF_Reco_QualMedium);
    g_LOG(LogLevel::DEBUG,"Jet SFs = ", jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT*
    jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
    

    // take product of all scale factors
    eventWeight = weight_mc*NOMINAL_pileup_combined_weight*lumFactor*mjj_w
    *muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium*muon_0_NOMINAL_MuEffSF_TTVA
    *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT
    *jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
    *muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_1_NOMINAL_MuEffSF_Reco_QualMedium*muon_1_NOMINAL_MuEffSF_TTVA;

    // fill histograms
    Fill(eventWeight, key);
  }
  // end style and writing
  Style();
  // write and close the output file
  outfile.Close();
  clock_t endTime = clock(); // get end time
  // calculate time taken and print it
  double time_spent = (endTime - startTime) / CLOCKS_PER_SEC;
  g_LOG(LogLevel::INFO,"Time processing == ", time_spent);
}
