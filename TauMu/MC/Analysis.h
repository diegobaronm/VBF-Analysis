#ifndef Header
#define Header

#define NOMINAL // NOMINAL , SHAPESYSTEMATICS, WEIGHTSYSTEMATICS
#ifdef NOMINAL
TH2F* trueMass_2D_lepTransMass_basic_all;
TH2F* trueMass_2D_transverseRecoMassRatio_basic_all;
histogramContainer lepnu_ptContainer;
histogramContainer taunu_ptContainer;
histogramContainer lep_etaContainer;
histogramContainer tau_etaContainer;
histogramContainer delta_R_taulepContainer;
histogramContainer delta_R_lepjetContainer;
histogramContainer delta_R_taujetContainer;
histogramContainer sum_ptContainer;
histogramContainer moreCentralJetContainer;
histogramContainer lessCentralJetContainer;
histogramContainer normPtDifferenceContainer;
histogramContainer metToDilepnuRatioContainer;
histogramContainer metToDilepRatioContainer;
histogramContainer delta_phijjContainer;
histogramContainer massTauClosestJetContainer;
histogramContainer massTauFurthestJetContainer;
histogramContainer nuPtAssummetryContainer;
histogramContainer massLepClosestJetContainer;
histogramContainer flavourJet1Container;
histogramContainer flavourJet2Container;
histogramContainer nLightJetsContainer;
histogramContainer muonPdgIDContainer;
histogramContainer tauPdgIDContainer;
histogramContainer signedCentralityContainer;

histogramContainer lep_phiNotFullContainer;
histogramContainer tau_phiNotFullContainer;
histogramContainer tau_nprongsNotFullContainer;
histogramContainer jet_nNotFullContainer;
histogramContainer Z_pt_reco_iNotFullContainer;
histogramContainer Z_pt_reco_oNotFullContainer;
histogramContainer n_fake_tracksNotFullContainer;
histogramContainer n_core_tracksNotFullContainer;
histogramContainer n_iso_tracksNotFullContainer;
histogramContainer n_tracksNotFullContainer;
histogramContainer ljet2_ptNotFullContainer;
histogramContainer ljet3_ptNotFullContainer;
histogramContainer gap_jet_ptNotFullContainer;
histogramContainer ljet0_etaNotFullContainer;
histogramContainer ljet1_etaNotFullContainer;
histogramContainer ljet2_etaNotFullContainer;
histogramContainer gap_jet_etaNotFullContainer;
histogramContainer vec_sum_pt_jetsNotFullContainer;
histogramContainer ratio_zpt_sumjetptNotFullContainer;
histogramContainer tau_matched_1pNotFullContainer;
histogramContainer tau_matched_3pNotFullContainer;
histogramContainer Z_pt_truth_iNotFullContainer;
histogramContainer Z_pt_truth_oNotFullContainer;

histogramContainer trueMassContainer;
histogramContainer recoTrueMassRatioContainer;
histogramContainer recoVisibleMassRatioContainer;
histogramContainer visibleMassContainer;
histogramContainer taunuptContainer;
histogramContainer lepnuptContainer;
histogramContainer ptsymContainer;  
histogramContainer bdtContainer;
histogramContainer delta_phiContainer;
histogramContainer delta_yContainer;
histogramContainer n_bjetsContainer;
histogramContainer lepisoContainer;
histogramContainer rnn_score_1pContainer;
histogramContainer rnn_score_3pContainer;
histogramContainer lep_ptContainer;
histogramContainer tau_ptContainer;
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
histogramContainer metContainer;
histogramContainer lepTransMassContainer;
histogramContainer tauTransMassContainer;
histogramContainer transMassSumContainer;
histogramContainer transMassRatioContainer;
histogramContainer transMassRecoMassRatioContainer;
histogramContainer transMassRecoMassRatio66to116Container;
histogramContainer transMassRecoMassRatio116to160Container;
histogramContainer transMassRecoMassRatio160to400Container;
histogramContainer transMassRecoMassRatio400toContainer;

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
