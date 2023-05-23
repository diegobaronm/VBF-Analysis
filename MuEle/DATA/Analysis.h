#ifndef Header
#define Header

double pi=TMath::Pi();
std::vector<std::string> cutNames{"basic","dphi","drap","btag","iso","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mreco","tpt"};
std::vector<std::string> notFull{"basic","all"};

#define NOMINAL // NOMINAL , SHAPESYSTEMATICS, WEIGHTSYSTEMATICS
#ifdef NOMINAL
histogramContainer elecnu_ptContainer{"elecnu_pt","Lep + Neutrino pT",500,0,500,cutNames};
histogramContainer muonnu_ptContainer{"muonnu_pt","Tau pT",500,0,500,cutNames};
histogramContainer elec_etaContainer{"elec_eta","Lep eta",50,-2.5,2.5,cutNames};
histogramContainer muon_etaContainer{"muon_eta","Tau eta",50,-2.5,2.5,cutNames};
histogramContainer delta_R_muonelecContainer{"delta_R_muonelec","Delta R muon-elec",60,0,6,cutNames};
histogramContainer delta_R_elecjetContainer{"delta_R_elecjet","Delta R elec-jet",60,0,6,cutNames};
histogramContainer delta_R_muonjetContainer{"delta_R_muonjet","Delta R muon-jet",60,0,6,cutNames};
histogramContainer sum_ptContainer{"sum_pt","Sum of electon and muon pT",800,0,800,cutNames};
histogramContainer metContainer{"met","Missing Transverse momentum",500,0,500,cutNames};
histogramContainer moreCentralJetContainer{"moreCentralJet","More central tagging jet",140,-7.0,7.0,notFull};
histogramContainer lessCentralJetContainer{"lessCentralJet","Less central tagging jet",140,-7.0,7.0,notFull};
histogramContainer normPtDifferenceContainer{"normPtDifference"," (mu-e)/(mu+e) pT ",200,-1.0,1.0,notFull};
histogramContainer metToDilepnuRatioContainer{"metToDilepnuRatio","MET/(mu+e+neutrinos) pT",50,0,5.0,notFull};
histogramContainer metToDilepRatioContainer{"metToDilepRatio","MET/(mu+e) pT",50,0,5.0,notFull};
histogramContainer delta_phijjContainer{"delta_phijj","Delta phi between tagging jets",32,0,3.2,notFull};
histogramContainer nuElecPtContainer{"nuElecPt","Neutrino electron side pT",200,0,200,notFull};
histogramContainer nuMuonPtContainer{"nuMuonPt","Neutrino muon side pT",200,0,200,notFull};
histogramContainer nuPtAssummetryContainer{"nuPtAssummetry","Neutrinos pT difference over sum",60,0,3,notFull};

histogramContainer elec_phiNotFullContainer{"elec_phi","Lep phi angle",64,-3.2,3.2,notFull};
histogramContainer muon_phiNotFullContainer{"muon_phi","Tau phi angle",64,-3.2,3.2,notFull};
histogramContainer jet_nNotFullContainer{"jet_n","Number of jets",10,0,10,notFull};
histogramContainer Z_pt_reco_iNotFullContainer{"Z_pt_reco_i","ZpT in between events",1000,0,1000,notFull};
histogramContainer Z_pt_reco_oNotFullContainer{"Z_pt_reco_o","ZpT outside events",1000,0,1000,notFull};
histogramContainer ljet2_ptNotFullContainer{"ljet2_pt","Light jet2 pT",1000,0,1000,notFull};
histogramContainer ljet3_ptNotFullContainer{"ljet3_pt","Light jet3 pT",1000,0,1000,notFull};
histogramContainer gap_jet_ptNotFullContainer{"gap_jet_pt","Gap jet pT",1000,0,1000,notFull};
histogramContainer ljet0_etaNotFullContainer{"ljet0_eta","Light jet0 eta",140,-7.0,7.0,notFull};
histogramContainer ljet1_etaNotFullContainer{"ljet1_eta","Light jet1 eta",140,-7.0,7.0,notFull};
histogramContainer ljet2_etaNotFullContainer{"ljet2_eta","Light jet2 eta",140,-7.0,7.0,notFull};
histogramContainer gap_jet_etaNotFullContainer{"gap_jet_eta","Gap jet eta",140,-7.0,7.0,notFull};
histogramContainer trans_mass_elecNotFullContainer{"trans_mass_elec","Transverse mass electon",150,0,150,notFull};
histogramContainer trans_mass_muonNotFullContainer{"trans_mass_muon","Transverse mass muon",150,0,150,notFull};
histogramContainer vec_sum_pt_jetsNotFullContainer{"vec_sum_pt_jets","Vector sum pT tagging jets",2000,0,2000,notFull};
histogramContainer ratio_zpt_sumjetptNotFullContainer{"ratio_zpt_sumjetpt","Ratio ZpT over vector sum pT tagging jets",500,0,5,notFull};
histogramContainer Z_pt_truth_iNotFullContainer{"Z_pt_truth_i","Truth ZpT in between events",1000,0,1000,notFull};
histogramContainer Z_pt_truth_oNotFullContainer{"Z_pt_truth_o","Truth ZpT outside events",1000,0,1000,notFull};

#endif

histogramContainer delta_phiContainer{"delta_phi","Delta phi between elec and muon",32,0,3.2,cutNames,"dphi"};
histogramContainer delta_yContainer{"delta_y","Delta Rapidity",100,0,10,cutNames,"drap"};
histogramContainer n_bjetsContainer{"n_bjets","Number of b_jets",5,0,5,cutNames,"btag"};
histogramContainer isoContainer{"iso","Lep Isolation",2,0,2,cutNames,"iso"};
histogramContainer elec_ptContainer{"elec_pt","Lep pT",500,0,500,cutNames,"ptl"};
histogramContainer muon_ptContainer{"muon_pt","Tau pT",500,0,500,cutNames,"tpt"};
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

#ifdef WEIGHTSYSTEMATICS

TH1F* h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13;
TH1F* h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13;
TH1F* h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight;
TH1F* h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight;
TH1F* h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk;
TH1F* h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk;
TH1F* h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
TH1F* h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
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

#endif

#endif
