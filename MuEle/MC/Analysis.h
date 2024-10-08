#ifndef Header
#define Header

#define NOMINAL // NOMINAL , SHAPESYSTEMATICS, WEIGHTSYSTEMATICS
#ifdef NOMINAL
histogramContainer elecnu_ptContainer;
histogramContainer muonnu_ptContainer;
histogramContainer elec_etaContainer;
histogramContainer muon_etaContainer;
histogramContainer delta_R_muonelecContainer;
histogramContainer delta_R_elecjetContainer;
histogramContainer delta_R_muonjetContainer;
histogramContainer sum_ptContainer;
histogramContainer metContainer;
histogramContainer moreCentralJetContainer;
histogramContainer lessCentralJetContainer;
histogramContainer normPtDifferenceContainer;
histogramContainer metToDilepnuRatioContainer;
histogramContainer metToDilepRatioContainer;
histogramContainer delta_phijjContainer;
histogramContainer nuElecPtContainer;
histogramContainer nuMuonPtContainer;
histogramContainer nuPtAssummetryContainer;
histogramContainer massElecClosestJetContainer;
histogramContainer massMuonClosestJetContainer;
histogramContainer massElecFurthestJetContainer;
histogramContainer massMuonFurthestJetContainer;
histogramContainer flavourJet1Container;
histogramContainer flavourJet2Container;
histogramContainer nLightJetsContainer;

histogramContainer elec_phiNotFullContainer;
histogramContainer muon_phiNotFullContainer;
histogramContainer jet_nNotFullContainer;
histogramContainer Z_pt_reco_iNotFullContainer;
histogramContainer Z_pt_reco_oNotFullContainer;
histogramContainer ljet2_ptNotFullContainer;
histogramContainer ljet3_ptNotFullContainer;
histogramContainer gap_jet_ptNotFullContainer;
histogramContainer ljet0_etaNotFullContainer;
histogramContainer ljet1_etaNotFullContainer;
histogramContainer ljet2_etaNotFullContainer;
histogramContainer gap_jet_etaNotFullContainer;
histogramContainer trans_mass_elecNotFullContainer;
histogramContainer trans_mass_muonNotFullContainer;
histogramContainer vec_sum_pt_jetsNotFullContainer;
histogramContainer ratio_zpt_sumjetptNotFullContainer;
histogramContainer Z_pt_truth_iNotFullContainer;
histogramContainer Z_pt_truth_oNotFullContainer;

histogramContainer delta_phiContainer;
histogramContainer delta_yContainer;
histogramContainer n_bjetsContainer;
histogramContainer isoContainer;
histogramContainer elec_ptContainer;
histogramContainer muon_ptContainer;
histogramContainer ljet0_ptContainer;
histogramContainer ljet1_ptContainer;
histogramContainer pt_balContainer;
histogramContainer mass_jjContainer;
histogramContainer n_jets_intervalContainer;
histogramContainer Z_centralityContainer;
histogramContainer omegaContainer;
histogramContainer reco_mass_iContainer;
histogramContainer reco_mass_oContainer;
histogramContainer reco_massContainer;
histogramContainer recoVisibleMassRatioContainer;


#endif

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

#if defined(WEIGHTSYSTEMATICS) || defined(SHAPESYSTEMATICS)

TH1F* h_delta_phi;
TH1F* h_delta_y;
TH1F* h_n_bjets;
TH1F* h_iso;
TH1F* h_elec_pt;
TH1F* h_muon_pt;
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
