#ifndef Header
#define Header

// declare histograms here
TH1F * h_RunN_topo;
TH1F * h_RunN_topo_tpt;

TH1F * h_EventN_RN358115_topo;
TH1F * h_EventN_RN358115_topo_tpt;

TH1F * h_EventN_RN359541_topo;
TH1F * h_EventN_RN359541_topo_tpt;

TH1F * h_eBDT_fail_mle;
TH1F * h_mle_fail_eBDT;

TH1F * h_inva_mass_ltau_topo;
TH1F * h_inva_mass_ltau_topo_dphi_bdte_btag_iso_rnn_pte_omega_mreco_tpt;

TH1F * h_trans_lep_mass_topo;
TH1F * h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

TH1F * h_tau_matched_1p_topo;
TH1F * h_tau_matched_1p_topo_dphi;
TH1F * h_tau_matched_1p_topo_dphi_bdte;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

TH1F * h_tau_matched_3p_topo;
TH1F * h_tau_matched_3p_topo_dphi;
TH1F * h_tau_matched_3p_topo_dphi_bdte;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

TH1F * h_Z_pt_truth_inside_topo;
TH1F * h_Z_pt_truth_cuts_inside;
TH1F * h_Z_pt_truth_cuts_tpt_inside;
TH1F * h_Z_pt_truth_outside_topo;
TH1F * h_Z_pt_truth_cuts_outside;
TH1F * h_Z_pt_truth_cuts_tpt_outside;

TH1F * h_rnn_score_1prong_topo;
TH1F * h_rnn_score_1prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt;
TH1F * h_rnn_score_3prong_topo;
TH1F * h_rnn_score_3prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt;

TH1F * h_bdt_e_score_topo;
TH1F * h_bdt_e_score_topo_dphi_btag_iso_rnn_pte_omega_mle_mreco_tpt;

// jet pT
TH1F * h_ljet1_pt_topo;
TH1F * h_ljet1_pt_topo_cuts;
TH1F * h_ljet1_pt_topo_cuts_tpt;

TH1F * h_ljet2_pt_topo;
TH1F * h_ljet2_pt_topo_cuts;
TH1F * h_ljet2_pt_topo_cuts_tpt;

TH1F * h_ljet3_pt_topo;
TH1F * h_ljet3_pt_topo_cuts;
TH1F * h_ljet3_pt_topo_cuts_tpt;

//Writing lep pT
TH1F * h_lep_pt0_topo;
TH1F * h_lep_pt0_topo_dphi;
TH1F * h_lep_pt0_topo_dphi_bdte;
TH1F * h_lep_pt0_topo_dphi_bdte_btag;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;
TH1F * h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_omega_mle_mreco_tpt;

//Writing lep pT+nu
TH1F * h_lep_pt0nu_topo;
TH1F * h_lep_pt0nu_topo_dphi;
TH1F * h_lep_pt0nu_topo_dphi_bdte;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

//Writing tau pT
TH1F * h_lep_pt1_topo;
TH1F * h_lep_pt1_topo_dphi;
TH1F * h_lep_pt1_topo_dphi_bdte;
TH1F * h_lep_pt1_topo_dphi_bdte_btag;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_inside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_inside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_inside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_inside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_outside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_outside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_outside;
TH1F * h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_outside;

//Writing tau pT+nu
TH1F * h_lep_pt1nu_topo;
TH1F * h_lep_pt1nu_topo_dphi;
TH1F * h_lep_pt1nu_topo_dphi_bdte;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

//Writing sum pT
TH1F * h_sum_pt_topo;
TH1F * h_sum_pt_topo_dphi;
TH1F * h_sum_pt_topo_dphi_bdte;
TH1F * h_sum_pt_topo_dphi_bdte_btag;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

TH1F * h_sum_pt_topo_1p_ZpTa;
TH1F * h_sum_pt_topo_1p_ZpTb;
TH1F * h_sum_pt_topo_1p_ZpTc;
TH1F * h_sum_pt_topo_3p_ZpTa;
TH1F * h_sum_pt_topo_3p_ZpTb;
TH1F * h_sum_pt_topo_3p_ZpTc;

TH1F * h_sum_pt_cuts_1p_ZpTa;
TH1F * h_sum_pt_cuts_1p_ZpTb;
TH1F * h_sum_pt_cuts_1p_ZpTc;
TH1F * h_sum_pt_cuts_3p_ZpTa;
TH1F * h_sum_pt_cuts_3p_ZpTb;
TH1F * h_sum_pt_cuts_3p_ZpTc;

TH1F * h_sum_pt_cuts_tpt_1p_ZpTa;
TH1F * h_sum_pt_cuts_tpt_1p_ZpTb;
TH1F * h_sum_pt_cuts_tpt_1p_ZpTc;
TH1F * h_sum_pt_cuts_tpt_3p_ZpTa;
TH1F * h_sum_pt_cuts_tpt_3p_ZpTb;
TH1F * h_sum_pt_cuts_tpt_3p_ZpTc;

//Writing MET
TH1F * h_met_topo;
TH1F * h_met_topo_dphi;
TH1F * h_met_topo_dphi_bdte;
TH1F * h_met_topo_dphi_bdte_btag;
TH1F * h_met_topo_dphi_bdte_btag_iso;
TH1F * h_met_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_met_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;

//Writing reco
TH1F * h_reco_mass_topo;
TH1F * h_reco_mass_topo_dphi;
TH1F * h_reco_mass_topo_dphi_bdte;
TH1F * h_reco_mass_topo_dphi_bdte_btag;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;
TH1F * h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt;

TH1F * h_reco_mass_met_outside_topo;
TH1F * h_reco_mass_met_outside_topo_dphi;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;
TH1F * h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt;

//Writing jet number
TH1F * h_jet_n_topo;
TH1F * h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;
//Writing b-tag
TH1F * h_b_tag_topo;
TH1F * h_b_tag_topo_dphi_bdte_iso_rnn_pte_omega_mle_mreco_tpt;

//Writing isolation variables
TH1F * h_elec_0_iso_topo;
TH1F * h_elec_0_iso_topo_dphi_bdte_btag_rnn_pte_omega_mle_mreco_tpt;

TH1F * h_omega_topo;
TH1F * h_omega_topo_dphi;
TH1F * h_omega_topo_dphi_bdte;
TH1F * h_omega_topo_dphi_bdte_btag;
TH1F * h_omega_topo_dphi_bdte_btag_iso;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn_pte;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt;
TH1F * h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt;

TH1F * h_Z_pt_reco_inside_topo;
TH1F * h_Z_pt_reco_cuts_inside;
TH1F * h_Z_pt_reco_cuts_tpt_inside;
TH1F * h_Z_pt_reco_outside_topo;
TH1F * h_Z_pt_reco_cuts_outside;
TH1F * h_Z_pt_reco_cuts_tpt_outside;

TH1F * h_lep_phi_topo;
TH1F * h_tau_phi_topo;
TH1F * h_delta_phi;
TH1F * h_delta_phi_second_stage;
TH1F * h_delta_phi_topo;
TH1F * h_tau_nprongs_topo;
TH1F * h_lep_phi_cuts;
TH1F * h_lep_phi_cuts_tpt;
TH1F * h_tau_phi_cuts;
TH1F * h_tau_phi_cuts_tpt;
TH1F * h_delta_phi_cuts;
TH1F * h_delta_phi_cuts_tpt;
TH1F * h_delta_phi_cuts_butphi;
TH1F * h_tau_nprongs_cuts;
TH1F * h_tau_nprongs_cuts_tpt;

TH1F * h_ratio_ptjet_zpt_topo;
TH1F * h_ratio_lpt_tpt_topo;
TH1F * h_ratio_ptjet_zpt_cuts;
TH1F * h_ratio_lpt_tpt_cuts;
TH1F * h_ratio_ptjet_zpt_cuts_tpt;
TH1F * h_ratio_lpt_tpt_cuts_tpt;

TH1F * h_n_fake_tracks;
TH1F * h_n_core_tracks;
TH1F * h_n_isolation_tracks;
TH1F * h_n_fake_tracks_cuts;
TH1F * h_n_core_tracks_cuts;
TH1F * h_n_isolation_tracks_cuts;
TH1F * h_n_fake_tracks_cuts_tpt;
TH1F * h_n_core_tracks_cuts_tpt;
TH1F * h_n_isolation_tracks_cuts_tpt;
TH1F * h_n_tracks;
TH1F * h_n_tracks_cuts;
TH1F * h_n_tracks_cuts_tpt;

#endif
