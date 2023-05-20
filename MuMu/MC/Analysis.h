#ifndef Header
#define Header

double pi=TMath::Pi();
std::vector<std::string> cutNames{"basic","dphi","drap","btag","iso","pt1","pt2","j1pt","j2pt","ptbal","mjj","nji","zcen","mass","ptl"};
std::vector<std::string> notFull{"basic","all"};

// declare histograms here
// jet pT
#define NOMINAL // WEIGHTSYSTEMATICS, SHAPESYSTEMATICS , NOMINAL
#ifdef NOMINAL
histogramContainer lep1_etaContainer{"lep1_eta","Lep1 eta",50,-2.5,2.5,cutNames};
histogramContainer lep2_etaContainer{"lep2_eta","Lep2 eta",50,-2.5,2.5,cutNames};
histogramContainer delta_R_leplepContainer{"delta_R_leplep","Delta R lep-lep",60,0,6,cutNames};
histogramContainer delta_R_lep1jetContainer{"delta_R_lep1jet","Delta R lep1-jet",60,0,6,cutNames};
histogramContainer delta_R_lep2jetContainer{"delta_R_lep2jet","Delta R lep2-jet",60,0,6,cutNames};
histogramContainer sum_ptContainer{"sum_pt","Sum of leptons pT",800,0,800,cutNames};
histogramContainer metContainer{"met","Missing Transverse momentum",500,0,500,cutNames};
histogramContainer moreCentralJetContainer{"moreCentralJet","More central tagging jet",140,-7.0,7.0,notFull};
histogramContainer lessCentralJetContainer{"lessCentralJet","Less central tagging jet",140,-7.0,7.0,notFull};
histogramContainer delta_phijjContainer{"delta_phijj","Delta phi between tagging jets",32,0,3.2,notFull};

histogramContainer lep1_phiContainer{"lep1_phi","Lep1 phi angle",64,-3.2,3.2,notFull};
histogramContainer lep2_phiContainer{"lep2_phi","Lep2 phi angle",64,-3.2,3.2,notFull};
histogramContainer jet_nContainer{"jet_n","Number of jets",10,0,10,notFull};
histogramContainer Z_pt_recoContainer{"Z_pt_reco","ZpT",1000,0,1000,notFull};
histogramContainer ljet2_ptContainer{"ljet2_pt","Light jet2 pT",1000,0,1000,notFull};
histogramContainer gap_jet_ptContainer{"gap_jet_pt","Gap jet pT",1000,0,1000,notFull};
histogramContainer ljet0_etaContainer{"ljet0_eta","Light jet0 eta",140,-7.0,7.0,notFull};
histogramContainer ljet1_etaContainer{"ljet1_eta","Light jet1 eta",140,-7.0,7.0,notFull};
histogramContainer ljet2_etaContainer{"ljet2_eta","Light jet2 eta",140,-7.0,7.0,notFull};
histogramContainer gap_jet_etaContainer{"gap_jet_eta","Gap jet eta",140,-7.0,7.0,notFull};
histogramContainer vec_sum_pt_jetsContainer{"vec_sum_pt_jets","Vector sum pT tagging jets",2000,0,2000,notFull};
histogramContainer ratio_zpt_sumjetptContainer{"ratio_zpt_sumjetpt","Ratio ZpT over vector sum pT tagging jets",500,0,5,notFull};
histogramContainer Z_pt_truthContainer{"Z_pt_truth","Truth ZpT",1000,0,1000,notFull};

#endif

histogramContainer delta_phiContainer{"delta_phi","Delta phi between leptons",32,0,3.2,cutNames,"dphi"};
histogramContainer delta_yContainer{"delta_y","Delta Rapidity",100,0,10,cutNames,"drap"};
histogramContainer n_bjetsContainer{"n_bjets","Number of b_jets",5,0,5,cutNames,"btag"};
histogramContainer lepisoContainer{"lepiso","Leptons isolation",2,0,2,cutNames,"iso"};
histogramContainer lep1_ptContainer{"lep1_pt","Lep 1 pT",500,0,500,cutNames,"pt1"};
histogramContainer lep2_ptContainer{"lep2_pt","Lep 2 pT",500,0,500,cutNames,"pt2"};
histogramContainer ljet0_ptContainer{"ljet0_pt","Light jet0 pT",1000,0,1000,cutNames,"j1pt"};
histogramContainer ljet1_ptContainer{"ljet1_pt","Light jet1 pT",1000,0,1000,cutNames,"j2pt"};
histogramContainer pt_balContainer{"pt_bal","pT Balance",100,0,1,cutNames,"ptbal"};
histogramContainer mass_jjContainer{"mass_jj","Invariant mass di_jet system",5000,0,5000,cutNames,"mjj"};
histogramContainer n_jets_intervalContainer{"n_jets_interval","N jets between rapidity interval",5,0,5,cutNames,"nji"};
histogramContainer Z_centralityContainer{"Z_centrality","Z boson centrality",350,0,3.5,cutNames,"zcen"};
histogramContainer inv_massContainer{"inv_mass","Invariant mass di-lepton system",1000,0,1000,cutNames,"mass"};

#ifdef WEIGHTSYSTEMATICS 
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
TH1F* h_mass_jj_muon_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
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
#endif 

#endif
