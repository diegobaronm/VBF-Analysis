#ifndef Header
#define Header

double pi=TMath::Pi();
std::vector<std::string> cutNames{"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mreco","tpt"};
std::vector<std::string> notFull{"basic","all"};

#define WEIGHTSYSTEMATICS // NOMINAL , SHAPESYSTEMATICS, WEIGHTSYSTEMATICS
#ifdef NOMINAL
histogramContainer lepnu_ptContainer{"lepnu_pt","Lep + Neutrino pT",500,0,500,cutNames};
histogramContainer taunu_ptContainer{"taunu_pt","Tau pT",500,0,500,cutNames};
histogramContainer lep_etaContainer{"lep_eta","Lep eta",50,-2.5,2.5,cutNames};
histogramContainer tau_etaContainer{"tau_eta","Tau eta",50,-2.5,2.5,cutNames};
histogramContainer delta_R_taulepContainer{"delta_R_taulep","Delta R tau-lep",60,0,6,cutNames};
histogramContainer delta_R_lepjetContainer{"delta_R_lepjet","Delta R lep-jet",60,0,6,cutNames};
histogramContainer delta_R_taujetContainer{"delta_R_taujet","Delta R tau-jet",60,0,6,cutNames};
histogramContainer sum_ptContainer{"sum_pt","Sum of lepton and tau pT",800,0,800,cutNames};
histogramContainer metContainer{"met","Missing Transverse momentum",500,0,500,cutNames};
histogramContainer moreCentralJetContainer{"moreCentralJet","More central tagging jet",140,-7.0,7.0,notFull};
histogramContainer lessCentralJetContainer{"lessCentralJet","Less central tagging jet",140,-7.0,7.0,notFull};
histogramContainer normPtDifferenceContainer{"normPtDifference"," (tau-mu)/(tau+mu) pT ",200,-1.0,1.0,notFull};
histogramContainer metToDilepnuRatioContainer{"metToDilepnuRatio","MET/(tau+mu+neutrinos) pT",50,0,5.0,notFull};
histogramContainer metToDilepRatioContainer{"metToDilepRatio","MET/(tau+mu) pT",50,0,5.0,notFull};
histogramContainer delta_phijjContainer{"delta_phijj","Delta phi between tagging jets",32,0,3.2,notFull};
histogramContainer massTauClosestJetContainer{"massTauClosestJet","Mass of tau and closest jet",2000,0,2000,notFull};
histogramContainer massTauFurthestJetContainer{"massTauFurthestJet","Mass of tau and furthest jet",2000,0,2000,notFull};
histogramContainer nuLepPtContainer{"nuLepPt","Neutrino lepton side pT",200,0,200,notFull};
histogramContainer nuTauPtContainer{"nuTauPt","Neutrino tau side pT",200,0,200,notFull};
histogramContainer nuPtAssummetryContainer{"nuPtAssummetry","Neutrinos pT difference over sumn",40,-1,1,notFull};
histogramContainer massLepClosestJetContainer{"massLepClosestJet","Mass of lep and closest jet",2000,0,2000,notFull};
histogramContainer flavourJet1Container{"flavourJet1","Jet1 truth flavour",50,-25,25,notFull};
histogramContainer flavourJet2Container{"flavourJet2","Jet2 truth flavour",50,-25,25,notFull};

histogramContainer lep_phiNotFullContainer{"lep_phi","Lep phi angle",64,-3.2,3.2,notFull};
histogramContainer tau_phiNotFullContainer{"tau_phi","Tau phi angle",64,-3.2,3.2,notFull};
histogramContainer tau_nprongsNotFullContainer{"tau_nprongs","Tau prongness",4,0,4,notFull};
histogramContainer trans_lep_massNotFullContainer{"trans_lep_mass","Lepton transverse mass",200,0,200,notFull};
histogramContainer jet_nNotFullContainer{"jet_n","Number of jets",10,0,10,notFull};
histogramContainer Z_pt_reco_iNotFullContainer{"Z_pt_reco_i","ZpT in between events",1000,0,1000,notFull};
histogramContainer Z_pt_reco_oNotFullContainer{"Z_pt_reco_o","ZpT outside events",1000,0,1000,notFull};
histogramContainer n_fake_tracksNotFullContainer{"n_fake_tracks","Number of fake tracks",40,0,40,notFull};
histogramContainer n_core_tracksNotFullContainer{"n_core_tracks","Number of core tracks",40,0,40,notFull};
histogramContainer n_iso_tracksNotFullContainer{"n_iso_tracks","Number of isolation tracks",40,0,40,notFull};
histogramContainer n_tracksNotFullContainer{"n_tracks","Number of all tracks",40,0,40,notFull};
histogramContainer ljet2_ptNotFullContainer{"ljet2_pt","Light jet2 pT",1000,0,1000,notFull};
histogramContainer ljet3_ptNotFullContainer{"ljet3_pt","Light jet3 pT",1000,0,1000,notFull};
histogramContainer gap_jet_ptNotFullContainer{"gap_jet_pt","Gap jet pT",1000,0,1000,notFull};
histogramContainer ljet0_etaNotFullContainer{"ljet0_eta","Light jet0 eta",140,-7.0,7.0,notFull};
histogramContainer ljet1_etaNotFullContainer{"ljet1_eta","Light jet1 eta",140,-7.0,7.0,notFull};
histogramContainer ljet2_etaNotFullContainer{"ljet2_eta","Light jet2 eta",140,-7.0,7.0,notFull};
histogramContainer gap_jet_etaNotFullContainer{"gap_jet_eta","Gap jet eta",140,-7.0,7.0,notFull};
histogramContainer trans_mass_lepNotFullContainer{"trans_mass_lep","Transverse mass lepton",150,0,150,notFull};
histogramContainer vec_sum_pt_jetsNotFullContainer{"vec_sum_pt_jets","Vector sum pT tagging jets",2000,0,2000,notFull};
histogramContainer ratio_zpt_sumjetptNotFullContainer{"ratio_zpt_sumjetpt","Ratio ZpT over vector sum pT tagging jets",500,0,5,notFull};
histogramContainer tau_matched_1pNotFullContainer{"tau_matched_1p","Tau truth matched 1 prong",2,0,2,notFull};
histogramContainer tau_matched_3pNotFullContainer{"tau_matched_3p","Tau truth matched 3 prong",2,0,2,notFull};
histogramContainer Z_pt_truth_iNotFullContainer{"Z_pt_truth_i","Truth ZpT in between events",1000,0,1000,notFull};
histogramContainer Z_pt_truth_oNotFullContainer{"Z_pt_truth_o","Truth ZpT outside events",1000,0,1000,notFull};

histogramContainer delta_phiContainer{"delta_phi","Delta phi between tau and lep",32,0,3.2,cutNames,"dphi"};
histogramContainer delta_yContainer{"delta_y","Delta Rapidity",100,0,10,cutNames,"drap"};
histogramContainer n_bjetsContainer{"n_bjets","Number of b_jets",5,0,5,cutNames,"btag"};
histogramContainer lepisoContainer{"lepiso","Lep Isolation",2,0,2,cutNames,"iso"};
histogramContainer rnn_score_1pContainer{"rnn_score_1p","RNN Score 1 prong taus",100,0,1,cutNames,"rnn"};
histogramContainer rnn_score_3pContainer{"rnn_score_3p","RNN Score 3 prong taus",100,0,1,cutNames,"rnn"};
histogramContainer lep_ptContainer{"lep_pt","Lep pT",500,0,500,cutNames,"ptl"};
histogramContainer tau_ptContainer{"tau_pt","Tau pT",500,0,500,cutNames,"tpt"};
histogramContainer ljet0_ptContainer{"ljet0_pt","Light jet0 pT",1000,0,1000,cutNames,"j1pt"};
histogramContainer ljet1_ptContainer{"ljet1_pt","Light jet1 pT",1000,0,1000,cutNames,"j2pt"};
histogramContainer pt_balContainer{"pt_bal","pT Balance",100,0,1,cutNames,"ptbal"};
histogramContainer mass_jjContainer{"mass_jj","Invariant mass di_jet system",5000,0,5000,cutNames,"mjj"};
histogramContainer n_jets_intervalContainer{"n_jets_interval","N jets between rapidity interval",10,0,10,cutNames,"nji"};
histogramContainer Z_centralityContainer{"Z_centrality","Z boson centrality",500,0,5,cutNames,"zcen"};
histogramContainer omegaContainer{"omega","Omega variable",60,-3.0,3.0,cutNames,"omega"};
histogramContainer reco_mass_iContainer{"reco_mass_i","Reconstructed mass in between events",1000,0,1000,cutNames,"mreco"};
histogramContainer reco_mass_oContainer{"reco_mass_o","Reconstructed mass outside events",1000,0,1000,cutNames,"mreco"};
histogramContainer reco_massContainer{"reco_mass_","Reconstructed mass all events",1000,0,1000,cutNames,"mreco"};

#endif

#ifdef WEIGHTSYSTEMATICS
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_PRW_DATASF_1down_pileup_combined_weight;
TH1F* h_mass_jj_PRW_DATASF_1up_pileup_combined_weight;
TH1F* h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT;
TH1F* h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT;
TH1F* h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT;
TH1F* h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT;
TH1F* h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT;
TH1F* h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT;
TH1F* h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT;
TH1F* h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium;
TH1F* h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium;

#endif

#if defined(WEIGHTSYSTEMATICS) || defined(SHAPESYSTEMATICS)

TH1F* h_delta_phi;
TH1F* h_delta_y;
TH1F* h_n_bjets;
TH1F* h_lepiso;
TH1F* h_rnn_score_1p;
TH1F* h_rnn_score_3p;
TH1F* h_lep_pt;
TH1F* h_tau_pt;
TH1F* h_ljet0_pt;
TH1F* h_ljet1_pt;
TH1F* h_pt_bal;
TH1F* h_mass_jj;
TH1F* h_n_jets_interval;
TH1F* h_Z_centrality;
TH1F* h_omega;
TH1F* h_reco_mass_i;
TH1F* h_reco_mass_o;
TH1F* h_reco_mass;

#endif

#endif
