// Analysis.py
// Skeleton code in python provided for you
// In place of this comment you should write [your name] -- [the date] and update it as you go!
// Make sure to make backups and comment as you go along :)

// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#include <utility>

double del_phi(double phi_1, double phi_2){
    double pi=TMath::Pi();
    double phi_1_norm, phi_2_norm;
    if (phi_1<0.0){
        phi_1_norm=phi_1+2*pi;
    }else {
        phi_1_norm=phi_1;
    }

    if (phi_2<0.0){
        phi_2_norm=phi_2+2*pi;
    }else {
        phi_2_norm=phi_2;
    }
    double delta=std::abs(phi_1_norm-phi_2_norm);
    if (delta>pi){
        delta=2*pi-delta;
        delta=std::abs(delta);
    }
    return delta;
}

void CLoop::Book(double lumFactor) {
    double pi=TMath::Pi();
    // VARIABLES ONLY ONCE
    h_inva_mass_ltau_topo = new TH1F("inva_mass_ltau_topo","Invariant mass lepton-tau system",300,0,300);
    h_inva_mass_ltau_topo_dphi_bdte_btag_iso_rnn_pte_omega_mreco_tpt = new TH1F("inva_mass_ltau_topo_dphi_bdte_btag_iso_rnn_pte_omega_mreco_tpt","Invariant mass lepton-tau system",300,0,300);
    //VARIABLES FOLLOWED AFTER EACH CUT
    // pT light-jets
    h_ljet1_pt_topo = new TH1F("ljet1_pt_topo","Light-jet 1 pT",200,0,200);
    h_ljet1_pt_topo_cuts = new TH1F("ljet1_pt_topo_cuts","Light-jet 1 pT",200,0,200);
    h_ljet1_pt_topo_cuts_tpt = new TH1F("ljet1_pt_topo_cuts_tpt","Light-jet 1 pT",200,0,200);

    h_ljet2_pt_topo = new TH1F("ljet2_pt_topo","Light-jet 2 pT",200,0,200);
    h_ljet2_pt_topo_cuts = new TH1F("ljet2_pt_topo_cuts","Light-jet 2 pT",200,0,200);
    h_ljet2_pt_topo_cuts_tpt = new TH1F("ljet2_pt_topo_cuts_tpt","Light-jet 2 pT",200,0,200);

    h_ljet3_pt_topo = new TH1F("ljet3_pt_topo","Light-jet 3 pT",200,0,200);
    h_ljet3_pt_topo_cuts = new TH1F("ljet3_pt_topo_cuts","Light-jet 3 pT",200,0,200);
    h_ljet3_pt_topo_cuts_tpt = new TH1F("ljet3_pt_topo_cuts_tpt","Light-jet 3 pT",200,0,200);

    // Histograms for lepton
    h_lep_pt0_topo = new TH1F("lep_pt0_topo","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi = new TH1F("lep_pt0_topo_dphi","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte = new TH1F("lep_pt0_topo_dphi_bdte","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag = new TH1F("lep_pt0_topo_dphi_bdte_btag","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Transverse momentum of lep1",200,0,200);
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_omega_mle_mreco_tpt = new TH1F("lep_pt0_topo_dphi_bdte_btag_iso_rnn_omega_mle_mreco_tpt","Transverse momentum of lep1",200,0,200);

    // Histograms for lepton+nu
    h_lep_pt0nu_topo = new TH1F("lep+nu_pt_topo","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi = new TH1F("lep+nu_pt_topo_dphi","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte = new TH1F("lep+nu_pt_topo_dphi_bdte","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag = new TH1F("lep+nu_pt_topo_dphi_bdte_btag","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso_rnn","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Transverse momentum of lep1+nu",200,0,200);
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("lep+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Transverse momentum of lep1+nu",200,0,200);

    h_lep_phi_topo= new TH1F("lep_phi_topo","Lepton phi angle",64,-3.2,3.2);
    h_lep_phi_cuts= new TH1F("lep_phi_cuts","Lepton phi angle",64,-3.2,3.2);
    h_lep_phi_cuts_tpt= new TH1F("lep_phi_cuts_tpt","Lepton phi angle",64,-3.2,3.2);
    // Histograms for tau pT
    h_lep_pt1_topo = new TH1F("tau_pt_topo","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi = new TH1F("tau_pt_topo_dphi","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte = new TH1F("tau_pt_topo_dphi_bdte","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag = new TH1F("tau_pt_topo_dphi_bdte_btag","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso = new TH1F("tau_pt_topo_dphi_bdte_btag_iso","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_inside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_inside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_outside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_outside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_inside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_inside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_outside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_outside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_inside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_inside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_outside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_outside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_inside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_inside","Transverse momentum of tau",200,0,200);
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_outside = new TH1F("tau_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_outside","Transverse momentum of tau",200,0,200);

    // Histograms for tau pT+nu
    h_lep_pt1nu_topo = new TH1F("tau+nu_pt_topo","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi = new TH1F("tau+nu_pt_topo_dphi","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte = new TH1F("tau+nu_pt_topo_dphi_bdte","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag = new TH1F("tau+nu_pt_topo_dphi_bdte_btag","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso_rnn","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Transverse momentum of tau+nu",200,0,200);
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("tau+nu_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Transverse momentum of tau+nu",200,0,200);

    // Histograms for sum pT
    h_sum_pt_topo = new TH1F("sum_pt_pt_topo","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi = new TH1F("sum_pt_pt_topo_dphi","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte = new TH1F("sum_pt_pt_topo_dphi_bdte","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag = new TH1F("sum_pt_pt_topo_dphi_bdte_btag","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso_rnn","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso_rnn_pte","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Sum of pT",400,0,400);
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("sum_pt_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Sum of pT",400,0,400);

    // Histograms for sum pT leptons spliting by ZpT and number of prongs
    // a=0 t0 100, b=100 to 150, c=150 to inf
    h_sum_pt_topo_1p_ZpTa = new TH1F("sum_pt_pt_topo_1p_ZpTa","Sum of pT 1 prong",400,0,400);
    h_sum_pt_topo_1p_ZpTb = new TH1F("sum_pt_pt_topo_1p_ZpTb","Sum of pT 1 prong",400,0,400);
    h_sum_pt_topo_1p_ZpTc = new TH1F("sum_pt_pt_topo_1p_ZpTc","Sum of pT 1 prong",400,0,400);
    h_sum_pt_topo_3p_ZpTa = new TH1F("sum_pt_pt_topo_3p_ZpTa","Sum of pT 3 prong",400,0,400);
    h_sum_pt_topo_3p_ZpTb = new TH1F("sum_pt_pt_topo_3p_ZpTb","Sum of pT 3 prong",400,0,400);
    h_sum_pt_topo_3p_ZpTc = new TH1F("sum_pt_pt_topo_3p_ZpTc","Sum of pT 3 prong",400,0,400);

    h_sum_pt_cuts_1p_ZpTa = new TH1F("sum_pt_pt_cuts_1p_ZpTa","Sum of pT 1 prong",400,0,400);
    h_sum_pt_cuts_1p_ZpTb = new TH1F("sum_pt_pt_cuts_1p_ZpTb","Sum of pT 1 prong",400,0,400);
    h_sum_pt_cuts_1p_ZpTc = new TH1F("sum_pt_pt_cuts_1p_ZpTc","Sum of pT 1 prong",400,0,400);
    h_sum_pt_cuts_3p_ZpTa = new TH1F("sum_pt_pt_cuts_3p_ZpTa","Sum of pT 3 prong",400,0,400);
    h_sum_pt_cuts_3p_ZpTb = new TH1F("sum_pt_pt_cuts_3p_ZpTb","Sum of pT 3 prong",400,0,400);
    h_sum_pt_cuts_3p_ZpTc = new TH1F("sum_pt_pt_cuts_3p_ZpTc","Sum of pT 3 prong",400,0,400);

    h_sum_pt_cuts_tpt_1p_ZpTa = new TH1F("sum_pt_pt_cuts_tpt_1p_ZpTa","Sum of pT 1 prong",400,0,400);
    h_sum_pt_cuts_tpt_1p_ZpTb = new TH1F("sum_pt_pt_cuts_tpt_1p_ZpTb","Sum of pT 1 prong",400,0,400);
    h_sum_pt_cuts_tpt_1p_ZpTc = new TH1F("sum_pt_pt_cuts_tpt_1p_ZpTc","Sum of pT 1 prong",400,0,400);
    h_sum_pt_cuts_tpt_3p_ZpTa = new TH1F("sum_pt_pt_cuts_tpt_3p_ZpTa","Sum of pT 3 prong",400,0,400);
    h_sum_pt_cuts_tpt_3p_ZpTb = new TH1F("sum_pt_pt_cuts_tpt_3p_ZpTb","Sum of pT 3 prong",400,0,400);
    h_sum_pt_cuts_tpt_3p_ZpTc = new TH1F("sum_pt_pt_cuts_tpt_3p_ZpTc","Sum of pT 3 prong",400,0,400);

    h_tau_phi_topo= new TH1F("tau_phi_topo","Tau phi",64,-3.2,3.2);
    h_tau_phi_cuts= new TH1F("tau_phi_cuts","Tau phi",64,-3.2,3.2);
    h_tau_phi_cuts_tpt= new TH1F("tau_phi_cuts_tpt","Tau phi",64,-3.2,3.2);
    h_tau_nprongs_topo=new TH1F("tau_nprongs_topo","Number of charged tracks",4,0,4);
    h_tau_nprongs_cuts=new TH1F("tau_nprongs_cuts","Number of charged tracks",4,0,4);
    h_tau_nprongs_cuts_tpt=new TH1F("tau_nprongs_cuts_tpt","Number of charged tracks",4,0,4);
    // MET Histograms
    h_met_topo = new TH1F("MET_topo","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi = new TH1F("MET_topo_dphi","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte = new TH1F("MET_topo_dphi_bdte","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag = new TH1F("MET_topo_dphi_bdte_btag","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso = new TH1F("MET_topo_dphi_bdte_btag_iso","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso_rnn = new TH1F("MET_topo_dphi_bdte_btag_iso_rnn","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("MET_topo_dphi_bdte_btag_iso_rnn_pte","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("MET_topo_dphi_bdte_btag_iso_rnn_pte_omega","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("MET_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("MET_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("MET_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Missing Transverse momentum",300,0,300);

    // Invariant mass histograms
    // Non reco histos
    //Transeverse lepton mass
    h_trans_lep_mass_topo = new TH1F("transverse_lepton_mass_topo","transverse mass lepton",300,0,300);
    h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("transverse_lepton_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","transverse mass lepton",300,0,300);
    h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("transverse_lepton_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","transverse mass lepton",300,0,300);

    // reco histos
    h_reco_mass_topo = new TH1F("reco_mass_topo","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi = new TH1F("reco_mass_topo_dphi","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte = new TH1F("reco_mass_topo_dphi_bdte","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag = new TH1F("reco_mass_topo_dphi_bdte_btag","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso = new TH1F("reco_mass_topo_dphi_bdte_btag_iso","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn_pte","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","reco mass in between",300,0,300);
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt = new TH1F("reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt","reco mass in between",300,0,300);

    h_reco_mass_met_outside_topo = new TH1F("reco_mass_met_outside_topo","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi = new TH1F("reco_mass_met_outside_topo_dphi","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte = new TH1F("reco_mass_met_outside_topo_dphi_bdte","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","reco mass outside",300,0,300);
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt = new TH1F("reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt","reco mass outside",300,0,300);

    // rnn Score histograms
    h_rnn_score_1prong_topo = new TH1F("rnn_score_1prong_topo","rnn score 1 track",100,0,1);
    h_rnn_score_1prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt = new TH1F("rnn_score_1prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt","rnn score 1 track",100,0,1);
    h_rnn_score_3prong_topo = new TH1F("rnn_score_3prong_topo","rnn score 3 track",100,0,1);
    h_rnn_score_3prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt = new TH1F("rnn_score_3prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt","rnn score 3 track",100,0,1);

    h_bdt_e_score_topo = new TH1F("bdt_e_score_topo","BDT score electron",100,0,1);
    h_bdt_e_score_topo_dphi_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("bdt_e_score_topo_dphi_btag_iso_rnn_pte_omega_mle_mreco_tpt","BDT score electron",100,0,1);

    if (lumFactor!=1)
    {
      h_tau_matched_1p_topo = new TH1F("tau_matched_1p","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi = new TH1F("tau_matched_1p_dphi","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte = new TH1F("tau_matched_1p_dphi_bdte","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag = new TH1F("tau_matched_1p_dphi_bdte_btag","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso = new TH1F("tau_matched_1p_dphi_bdte_btag_iso","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte_omega","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte_omega_mle","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Tau truth matched 1 prong",2,0,2);

      h_tau_matched_3p_topo = new TH1F("tau_matched_3p","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi = new TH1F("tau_matched_3p_dphi","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte = new TH1F("tau_matched_3p_dphi_bdte","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag = new TH1F("tau_matched_3p_dphi_bdte_btag","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso = new TH1F("tau_matched_3p_dphi_bdte_btag_iso","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte_omega","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte_omega_mle","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Tau truth matched 3 prong",2,0,2);

      h_Z_pt_truth_inside_topo = new TH1F("Z_pt_truth_inside_topo","Z_truth boson transverse momentum inside",400,0,400);
      h_Z_pt_truth_cuts_inside = new TH1F("Z_pt_truth_cuts_inside","Z_truth boson transverse momentum inside",400,0,400);
      h_Z_pt_truth_cuts_tpt_inside = new TH1F("Z_pt_truth_cuts_tpt_inside","Z_truth boson transverse momentum inside",400,0,400);
      h_Z_pt_truth_outside_topo = new TH1F("Z_pt_truth_outside_topo","Z_truth boson transverse momentum outside",400,0,400);
      h_Z_pt_truth_cuts_outside = new TH1F("Z_pt_truth_cuts_outside","Z_truth boson transverse momentum outside",400,0,400);
      h_Z_pt_truth_cuts_tpt_outside = new TH1F("Z_pt_truth_cuts_tpt_outside","Z_truth boson transverse momentum outside",400,0,400);
    }
    // Jet Number Histograms
    h_jet_n_topo = new TH1F("jet_n_topo","Number of jets",10,-1,9);
    h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Number of jets",10,-1,9);
    h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Number of jets",10,-1,9);

    h_b_tag_topo = new TH1F("b_tag_topo","b taging variable",2,0,2);
    h_b_tag_topo_dphi_bdte_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("b_tag_topo_dphi_bdte_iso_rnn_pte_omega_mle_mreco_tpt","b taging variable",2,0,2);


    // Isolation variables Histograms
    h_elec_0_iso_topo = new TH1F("elec_0_iso_topo","lepton 1 isolation",2,0,2);
    h_elec_0_iso_topo_dphi_bdte_btag_rnn_pte_omega_mle_mreco_tpt = new TH1F("elec_0_iso_topo_dphi_bdte_btag_rnn_pte_omega_mle_mreco_tpt","lepton 1 isolation",2,0,2);

    // Angular variable
    h_omega_topo = new TH1F("omega_topo","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi = new TH1F("omega_topo_dphi","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte = new TH1F("omega_topo_dphi_bdte","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag = new TH1F("omega_topo_dphi_bdte_btag","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso = new TH1F("omega_topo_dphi_bdte_btag_iso","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt","omega variable",60,-3.0,3.0);

    h_Z_pt_reco_inside_topo = new TH1F("Z_pt_inside_topo","Z boson transverse momentum inside",400,0,400);
    h_Z_pt_reco_cuts_inside = new TH1F("Z_pt_cuts_inside","Z boson transverse momentum inside",400,0,400);
    h_Z_pt_reco_cuts_tpt_inside = new TH1F("Z_pt_cuts_tpt_inside","Z boson transverse momentum inside",400,0,400);
    h_Z_pt_reco_outside_topo = new TH1F("Z_pt_outside_topo","Z boson transverse momentum outside",400,0,400);
    h_Z_pt_reco_cuts_outside = new TH1F("Z_pt_cuts_outside","Z boson transverse momentum outside",400,0,400);
    h_Z_pt_reco_cuts_tpt_outside = new TH1F("Z_pt_cuts_tpt_outside","Z boson transverse momentum outside",400,0,400);

    h_delta_phi= new TH1F("delta_phi","Delta phi lepton-tau",32,0,3.2);
    h_delta_phi_second_stage= new TH1F("delta_phi_second_stage","Delta phi lepton-tau_second_stage",32,0,3.2);
    h_delta_phi_topo= new TH1F("delta_phi_topo","Delta phi lepton-tau",32,0,3.2);
    h_delta_phi_cuts_butphi= new TH1F("delta_phi_cuts_butphi","Delta phi lepton-tau",32,0,3.2);
    h_delta_phi_cuts= new TH1F("delta_phi_cuts","Delta phi lepton-tau",32,0,3.2);
    h_delta_phi_cuts_tpt= new TH1F("delta_phi_cuts_tpt","Delta phi lepton-tau",32,0,3.2);

    //MJ BG DISCRIMINATION VARIABLES
    h_ratio_ptjet_zpt_topo = new TH1F("ratio_ptjet_zpt_topo","ratio_ptjet_zpt",40,0,4);
    h_ratio_lpt_tpt_topo = new TH1F("ratio_lpt_tpt_topo","ratio_lpt_tpt",40,0,4);
    h_ratio_ptjet_zpt_cuts = new TH1F("ratio_ptjet_zpt_cuts","ratio_ptjet_zpt",40,0,4);
    h_ratio_lpt_tpt_cuts = new TH1F("ratio_lpt_tpt_cuts","ratio_lpt_tpt",40,0,4);
    h_ratio_ptjet_zpt_cuts_tpt = new TH1F("ratio_ptjet_zpt_cuts_tpt","rratio_ptjet_zpt",40,0,4);
    h_ratio_lpt_tpt_cuts_tpt = new TH1F("ratio_lpt_tpt_cuts_tpt","ratio_lpt_tpt",40,0,4);

    //n TRACKS
    h_n_fake_tracks = new TH1F("n_fake_tracks","n_fake_tracks",40,0,40);
    h_n_core_tracks = new TH1F("n_core_tracks","n_core_tracks",40,0,40);
    h_n_isolation_tracks = new TH1F("n_isolation_tracks","n_isolation_tracks",40,0,40);
    h_n_fake_tracks_cuts = new TH1F("n_fake_tracks_cuts","n_fake_tracks_cuts",40,0,40);
    h_n_core_tracks_cuts = new TH1F("n_core_tracks_cuts","n_core_tracks_cuts",40,0,40);
    h_n_isolation_tracks_cuts = new TH1F("n_isolation_tracks_cuts","n_isolation_tracks_cuts",40,0,40);
    h_n_fake_tracks_cuts_tpt = new TH1F("n_fake_tracks_cuts_tpt","n_fake_tracks_cuts_tpt",40,0,40);
    h_n_core_tracks_cuts_tpt = new TH1F("n_core_tracks_cuts_tpt","n_core_tracks_cuts_tpt",40,0,40);
    h_n_isolation_tracks_cuts_tpt = new TH1F("n_isolation_tracks_cuts_tpt","n_isolation_tracks_cuts_tpt",40,0,40);
    h_n_tracks = new TH1F("n_tracks","n_tracks",40,0,40);
    h_n_tracks_cuts = new TH1F("n_tracks_cuts","n_tracks_cuts",40,0,40);
    h_n_tracks_cuts_tpt = new TH1F("n_tracks_cuts_tpt","n_tracks_cuts_tpt",40,0,40);

    // Test
    h_eBDT_fail_mle = new TH1F("eBDT_fail_mle","eBDT events fail m(e,tau)",100,0,1);
    h_mle_fail_eBDT = new TH1F("mle_fail_eBDT","m(e,tau) events fail eBDT",300,0,300);
}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();
    if (n_electrons==1 && n_taus_rnn_loose>=1) {
      //angles
      double angle_l_MET=del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(tau_0_p4->Phi(),elec_0_p4->Phi());

      h_delta_phi->Fill(angle,weight);

      bool trigger_decision= false;
      bool trigger_match=false;
      if (run_number>= 276262 && run_number<=284484){
          trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
          trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
      } else {
          trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
          trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
      }
      bool lepton_id=elec_0_id_tight;

      float ql=elec_0_q;
      float qtau=tau_0_q;
      float pair_charge=ql*qtau;

      if (ql==qtau && angle<3*pi/4 && trigger_decision && lepton_id && trigger_match){

        h_delta_phi_second_stage->Fill(angle,weight);
        //topology
        bool inside= abs(angle-(angle_l_MET+angle_tau_MET))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
        bool outside_lep= angle_l_MET<angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_l_MET)>0;
        bool outside_tau= angle_l_MET>angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_tau_MET)>0;
        bool signal_events = inside || outside_lep || outside_tau;

        double lepmet_mass=sqrt(2*elec_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(elec_0_p4->Phi()-met_reco_p4->Phi())));

        if(signal_events){

          // RECO mass
          double cot_lep=1.0/tan(elec_0_p4->Phi());
          double cot_tau=1.0/tan(tau_0_p4->Phi());
          double pt_tau_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_lep)/(cos(tau_0_p4->Phi())-sin(tau_0_p4->Phi())*cot_lep);
          double pt_lep_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_tau)/(cos(elec_0_p4->Phi())-sin(elec_0_p4->Phi())*cot_tau);

          double reco_mass{};
          if(inside){
            reco_mass=sqrt(2*elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+2*elec_0_p4->Pt()*pt_tau_nu*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+2*tau_0_p4->Pt()*pt_lep_nu*(cosh(tau_0_p4->Eta()-elec_0_p4->Eta())-cos(tau_0_p4->Phi()-elec_0_p4->Phi()))+2*pt_lep_nu*pt_tau_nu*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi())));
          }

          double neutrino_pt=0;
          double reco_mass_outside=0;
          if (outside_lep) {
            neutrino_pt=met_reco_p4->Pt()*cos(angle_l_MET);
            reco_mass_outside=5+sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+tau_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))));
          }
          if (outside_tau) {
            neutrino_pt=met_reco_p4->Pt()*cos(angle_tau_MET);
            reco_mass_outside=5+sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+elec_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))));
          }


          double Z_pt_x=0;
          double Z_pt_y=0;
          double Z_pt=0;
          double r_jpt_zpt=0;
          double r_lpt_tpt=elec_0_p4->Pt()/tau_0_p4->Pt();
          double truth_z_pt=0.0;
          if (z_sample==1 || z_sample==2)
          {
            truth_z_pt=truth_Z_p4->Pt()/1000;
          }
          if (inside) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+pt_tau_nu*cos(tau_0_p4->Phi())+pt_lep_nu*cos(elec_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+pt_tau_nu*sin(tau_0_p4->Phi())+pt_lep_nu*sin(elec_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
            h_Z_pt_reco_inside_topo->Fill(Z_pt,weight);
            if (weight!=1){
              h_Z_pt_truth_inside_topo->Fill(truth_z_pt,weight);
            }
            r_jpt_zpt=ljet_0_p4->Pt()/Z_pt;
          }
          if (outside_tau) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(tau_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(tau_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
            h_Z_pt_reco_outside_topo->Fill(Z_pt,weight);
            if (weight!=1){
              h_Z_pt_truth_outside_topo->Fill(truth_z_pt,weight);
            }
            r_jpt_zpt=ljet_0_p4->Pt()/Z_pt;
          }
          if (outside_lep) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(elec_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(elec_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
            h_Z_pt_reco_outside_topo->Fill(Z_pt,weight);
            if (weight!=1){
              h_Z_pt_truth_outside_topo->Fill(truth_z_pt,weight);
            }
            r_jpt_zpt=ljet_0_p4->Pt()/Z_pt;
          }

          // non RECO mass
          double inv_taulep=sqrt((2*elec_0_p4->Pt()*tau_0_p4->Pt())*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi())));
          //double trans_mass=sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(1-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+elec_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(elec_0_p4->Phi()-met_reco_p4->Phi()))+tau_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(tau_0_p4->Phi()-met_reco_p4->Phi()))));
          //double visi_mass=sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+elec_0_p4->Pt()*met_reco_p4->Pt()*(cosh(elec_0_p4->Eta())-cos(elec_0_p4->Phi()-met_reco_p4->Phi()))+tau_0_p4->Pt()*met_reco_p4->Pt()*(cosh(tau_0_p4->Eta())-cos(tau_0_p4->Phi()-met_reco_p4->Phi()))));


          // ANGULAR VARIABLE DEFINITION
          double omega=0.0;
          if (inside && (angle_l_MET<angle_tau_MET)) {
            omega=1.0-(angle_l_MET)/(angle);
          }
          if (inside && (angle_l_MET>angle_tau_MET)) {
            omega=(angle_tau_MET)/(angle);
          }
          if (outside_lep) {
            omega=1.0+(angle_l_MET)/(angle);
          }
          if (outside_tau) {
            omega=-1.0*(angle_tau_MET)/(angle);
          }

          // Cuts bits
          vector<int> cuts={0,0,0,0,0,0,0,0,0,0};
          if (angle<=2*pi/3){
            cuts[0]=1;
          }
          if (tau_0_p4->Pt()>25/*tau_0_ele_bdt_score_trans_retuned>=0.05*/) {
            cuts[1]=1;
          }
          if (n_bjets_MV2c10_FixedCutBEff_85==0){
            cuts[2]=1;
          }
          if (elec_0_iso_FCLoose==0/*elec_0_iso_FCTight==0*/) {
            cuts[3]=1;
          }
          if (tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans<0.4) {
            cuts[4]=1;
          }
          if (tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans<0.55) {
            cuts[4]=1;
          }
          if (elec_0_p4->Pt()>=27) {
            cuts[5]=1;
          }
          if (omega>0 && omega <1.4) {
            cuts[6]=1;
          }
          if (inv_taulep < 80 ) {
            cuts[7]=1;
          }
          if (inside) {
            if (reco_mass<130 && reco_mass>50) {
              cuts[8]=1;
            }
          }
          if (outside_lep) {
            if (reco_mass_outside<130 && reco_mass_outside>50) {
              cuts[8]=1;
            }
          }
          if (outside_tau) {
            if (reco_mass_outside<130 && reco_mass_outside>50) {
              cuts[8]=1;
            }
          }
          if (inv_taulep < 75){
              cuts[9]=1;
          }

          // Cuts relative to otherwise
          vector<int> c_phi={0,1,1,1,1,1,1,1,1,1};
          vector<int> c_bdte={1,0,1,1,1,1,1,1,1,1};
          vector<int> c_btag={1,1,0,1,1,1,1,1,1,1};
          vector<int> c_iso={1,1,1,0,1,1,1,1,1,1};
          vector<int> c_rnn={1,1,1,1,0,1,1,1,1,1};
          vector<int> c_pte={1,1,1,1,1,0,1,1,1,1};
          vector<int> c_omega={1,1,1,1,1,1,0,1,1,1};
          vector<int> c_mle={1,1,1,1,1,1,1,0,1,1};
          vector<int> c_mreco={1,1,1,1,1,1,1,1,0,1};
          vector<int> c_tpt={1,1,1,1,1,1,1,1,1,0};
          vector<int> c_all={1,1,1,1,1,1,1,1,1,1};

          //TEST
          if (cuts==std::vector<int>{1,0,1,1,1,1,1,0,1,1} || cuts==std::vector<int>{1,1,1,1,1,1,1,0,1,1}){
            h_eBDT_fail_mle->Fill(tau_0_ele_bdt_score_trans_retuned,weight);
          }
          if (cuts==std::vector<int>{1,0,1,1,1,1,1,0,1,1} || cuts==std::vector<int>{1,0,1,1,1,1,1,1,1,1}){
            h_mle_fail_eBDT->Fill(inv_taulep,weight);
          }

          if (cuts==c_phi||cuts==c_all) {
            h_delta_phi_cuts_butphi->Fill(angle,weight);
          }
          if (cuts==c_bdte||cuts==c_all) {
            h_bdt_e_score_topo_dphi_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_ele_bdt_score_trans_retuned,weight);
          }
          if ((cuts==c_btag||cuts==c_all) && n_jets!=0) {
            h_b_tag_topo_dphi_bdte_iso_rnn_pte_omega_mle_mreco_tpt->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
          }
          if (cuts==c_iso||cuts==c_all) {
            h_elec_0_iso_topo_dphi_bdte_btag_rnn_pte_omega_mle_mreco_tpt->Fill(elec_0_iso_FCLoose,weight);
          }
          if (cuts==c_rnn||cuts==c_all) {
            if (tau_0_n_charged_tracks==1){
              h_rnn_score_1prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt->Fill(tau_0_jet_rnn_score_trans,weight);
            }
            if (tau_0_n_charged_tracks==3){
              h_rnn_score_3prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt->Fill(tau_0_jet_rnn_score_trans,weight);
            }
          }
          if (cuts==c_pte||cuts==c_all) {
            h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_omega_mle_mreco_tpt->Fill(elec_0_p4->Pt(),weight);
          }
          if (cuts==c_omega||cuts==c_all) {
            h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt->Fill(omega,weight);
          }
          if (cuts==c_mle||cuts==c_all) {
            h_inva_mass_ltau_topo_dphi_bdte_btag_iso_rnn_pte_omega_mreco_tpt->Fill(inv_taulep,weight);
          }
          if (inside) {
            if (cuts==c_mreco||cuts==c_all) {
              h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt->Fill(reco_mass,weight);
            }
            if (cuts==c_tpt||cuts==c_all){
              h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_inside->Fill(tau_0_p4->Pt(),weight);
            }
          }
          if (outside_lep) {
            if (cuts==c_mreco||cuts==c_all) {
              h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt->Fill(reco_mass_outside,weight);
            }
            if (cuts==c_tpt||cuts==c_all){
              h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_outside->Fill(tau_0_p4->Pt(),weight);
            }
          }
          if (outside_tau) {
            if (cuts==c_mreco||cuts==c_all) {
              h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt->Fill(reco_mass_outside,weight);
            }
            if (cuts==c_mreco||cuts==c_all){
              h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_outside->Fill(tau_0_p4->Pt(),weight);
            }
          }
          //  Filling histos
          h_inva_mass_ltau_topo->Fill(inv_taulep,weight);
          if (tau_0_n_charged_tracks==1){
            h_rnn_score_1prong_topo->Fill(tau_0_jet_rnn_score_trans,weight);
          }
          if (tau_0_n_charged_tracks==3){
            h_rnn_score_3prong_topo->Fill(tau_0_jet_rnn_score_trans,weight);
          }
          h_bdt_e_score_topo->Fill(tau_0_ele_bdt_score_trans_retuned,weight);
          h_jet_n_topo->Fill(n_jets, weight);
          h_elec_0_iso_topo->Fill(elec_0_iso_FCLoose,weight);
          h_omega_topo->Fill(omega,weight);
          h_met_topo->Fill(met_reco_p4->Pt(),weight);
          h_lep_pt0_topo->Fill(elec_0_p4->Pt(),weight);
          h_lep_pt1_topo->Fill(tau_0_p4->Pt(),weight);
          h_lep_phi_topo->Fill(elec_0_p4->Phi(),weight);
          h_tau_phi_topo->Fill(tau_0_p4->Phi(),weight);
          h_delta_phi_topo->Fill(angle,weight);
          h_tau_nprongs_topo->Fill(tau_0_n_charged_tracks,weight);
          h_n_fake_tracks->Fill(tau_0_n_fake_tracks,weight);
          h_n_core_tracks->Fill(tau_0_n_core_tracks,weight);
          h_n_isolation_tracks->Fill(tau_0_n_isolation_tracks,weight);
          h_n_tracks->Fill(tau_0_n_all_tracks,weight);
          h_ljet1_pt_topo->Fill(ljet_0_p4->Pt(),weight);
          h_ljet2_pt_topo->Fill(ljet_1_p4->Pt(),weight);
          h_ljet3_pt_topo->Fill(ljet_2_p4->Pt(),weight);
          h_trans_lep_mass_topo->Fill(lepmet_mass,weight);

          if (weight!=1){
            if (tau_0_n_charged_tracks==1){
              h_tau_matched_1p_topo->Fill(tau_0_truth_isHadTau,weight);
            }
            if (tau_0_n_charged_tracks==3){
              h_tau_matched_3p_topo->Fill(tau_0_truth_isHadTau,weight);
            }
          }

          if (inside) {
            h_reco_mass_topo->Fill(reco_mass,weight);
            h_lep_pt0nu_topo->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
            h_lep_pt1nu_topo->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
            h_sum_pt_topo->Fill(tau_0_p4->Pt()+pt_tau_nu+muon_0_p4->Pt()+pt_lep_nu,weight);
            if (tau_0_n_charged_tracks==1){
              if (Z_pt<100){
                h_sum_pt_topo_1p_ZpTa->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
              } if (Z_pt>100 && Z_pt<150){
                h_sum_pt_topo_1p_ZpTb->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
              } if (Z_pt>150) {
                h_sum_pt_topo_1p_ZpTc->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
              }
            }
            if (tau_0_n_charged_tracks==3){
              if (Z_pt<100){
                h_sum_pt_topo_3p_ZpTa->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
              } if (Z_pt>100 && Z_pt<150){
                h_sum_pt_topo_3p_ZpTb->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
              } if (Z_pt>150) {
                h_sum_pt_topo_3p_ZpTc->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
              }
            }
          }
          if (outside_lep) {
            h_reco_mass_met_outside_topo->Fill(reco_mass_outside,weight);
            h_lep_pt0nu_topo->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
            h_lep_pt1nu_topo->Fill(tau_0_p4->Pt(),weight);
            h_sum_pt_topo->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
            if (tau_0_n_charged_tracks==1){
              if (Z_pt<100){
                h_sum_pt_topo_1p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>100 && Z_pt<150){
                h_sum_pt_topo_1p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>150) {
                h_sum_pt_topo_1p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              }
            }
            if (tau_0_n_charged_tracks==3){
              if (Z_pt<100){
                h_sum_pt_topo_3p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>100 && Z_pt<150){
                h_sum_pt_topo_3p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>150) {
                h_sum_pt_topo_3p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              }
            }
          }
          if (outside_tau){
            h_reco_mass_met_outside_topo->Fill(reco_mass_outside,weight);
            h_lep_pt0nu_topo->Fill(elec_0_p4->Pt(),weight);
            h_lep_pt1nu_topo->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
            h_sum_pt_topo->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
            if (tau_0_n_charged_tracks==1){
              if (Z_pt<100){
                h_sum_pt_topo_1p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>100 && Z_pt<150){
                h_sum_pt_topo_1p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>150) {
                h_sum_pt_topo_1p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              }
            }
            if (tau_0_n_charged_tracks==3){
              if (Z_pt<100){
                h_sum_pt_topo_3p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>100 && Z_pt<150){
                h_sum_pt_topo_3p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              } if (Z_pt>150) {
                h_sum_pt_topo_3p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
              }
            }
          }

          h_ratio_ptjet_zpt_topo->Fill(r_jpt_zpt,weight);
          h_ratio_lpt_tpt_topo->Fill(r_lpt_tpt,weight);
            // INVA MASS LEPTON TAU CUT
          if (cuts[0]==1 && cuts[1]==1 && cuts[2]==1 && cuts[3]==1 && cuts[4]==1 && cuts[5]==1 && cuts[6]==1 && cuts[7]==1) {
            h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(met_reco_p4->Pt(),weight);
            h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(elec_0_p4->Pt(),weight);
            h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(omega,weight);

            if (inside) {
            h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(reco_mass,weight);
            h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
            h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_inside->Fill(tau_0_p4->Pt(),weight);
            h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
            h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_p4->Pt()+pt_tau_nu+muon_0_p4->Pt()+pt_lep_nu,weight);
            }
            if (outside_lep) {
            h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(reco_mass_outside,weight);
            h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
            h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_outside->Fill(tau_0_p4->Pt(),weight);
            h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_p4->Pt(),weight);
            h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
            }
            if (outside_tau){
            h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(reco_mass_outside,weight);
            h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_outside->Fill(tau_0_p4->Pt(),weight);
            h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(elec_0_p4->Pt(),weight);
            h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
            h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
            }
            if (weight!=1){
              if (tau_0_n_charged_tracks==1){
                h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_truth_isHadTau,weight);
              }
              if (tau_0_n_charged_tracks==3){
                h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(tau_0_truth_isHadTau,weight);
              }
            }

            // RECO MASS CUT
            if (cuts[8]==1) {
              h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(met_reco_p4->Pt(),weight);
              h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(n_jets, weight);
              h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(lepmet_mass,weight);
              h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(elec_0_p4->Pt(),weight);
              h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(omega,weight);
              h_lep_phi_cuts->Fill(elec_0_p4->Phi(),weight);
              h_tau_phi_cuts->Fill(tau_0_p4->Phi(),weight);
              h_delta_phi_cuts->Fill(angle,weight);
              h_tau_nprongs_cuts->Fill(tau_0_n_charged_tracks,weight);
              h_n_fake_tracks_cuts->Fill(tau_0_n_fake_tracks,weight);
              h_n_core_tracks_cuts->Fill(tau_0_n_core_tracks,weight);
              h_n_isolation_tracks_cuts->Fill(tau_0_n_isolation_tracks,weight);
              h_n_tracks_cuts->Fill(tau_0_n_all_tracks,weight);
              h_ljet1_pt_topo_cuts->Fill(ljet_0_p4->Pt(),weight);
              h_ljet2_pt_topo_cuts->Fill(ljet_1_p4->Pt(),weight);
              h_ljet3_pt_topo_cuts->Fill(ljet_2_p4->Pt(),weight);

              if (weight!=1){
                if (tau_0_n_charged_tracks==1){
                  h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_truth_isHadTau,weight);
                }
                if (tau_0_n_charged_tracks==3){
                  h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_truth_isHadTau,weight);
                }
              }

              h_ratio_ptjet_zpt_cuts->Fill(r_jpt_zpt,weight);
              h_ratio_lpt_tpt_cuts->Fill(r_lpt_tpt,weight);

              if (inside) {
                h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(reco_mass,weight);
                h_Z_pt_reco_cuts_inside->Fill(Z_pt,weight);
                h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_p4->Pt()+pt_tau_nu+muon_0_p4->Pt()+pt_lep_nu,weight);
                if (tau_0_n_charged_tracks==1){
                  if (Z_pt<100){
                    h_sum_pt_cuts_1p_ZpTa->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                  } if (Z_pt>100 && Z_pt<150){
                    h_sum_pt_cuts_1p_ZpTb->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                  } if (Z_pt>150) {
                    h_sum_pt_cuts_1p_ZpTc->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                  }
                }
                if (tau_0_n_charged_tracks==3){
                  if (Z_pt<100){
                    h_sum_pt_cuts_3p_ZpTa->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                  } if (Z_pt>100 && Z_pt<150){
                    h_sum_pt_cuts_3p_ZpTb->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                  } if (Z_pt>150) {
                    h_sum_pt_cuts_3p_ZpTc->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                  }
                }
                if (weight!=1){
                  h_Z_pt_truth_cuts_inside->Fill(truth_z_pt,weight);
                }
              }
              if (outside_lep) {
                h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(reco_mass_outside,weight);
                h_Z_pt_reco_cuts_outside->Fill(Z_pt,weight);
                h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_p4->Pt(),weight);
                h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
                if (tau_0_n_charged_tracks==1){
                  if (Z_pt<100){
                    h_sum_pt_cuts_1p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>100 && Z_pt<150){
                    h_sum_pt_cuts_1p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>150) {
                    h_sum_pt_cuts_1p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  }
                }
                if (tau_0_n_charged_tracks==3){
                  if (Z_pt<100){
                    h_sum_pt_cuts_3p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>100 && Z_pt<150){
                    h_sum_pt_cuts_3p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>150) {
                    h_sum_pt_cuts_3p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  }
                }
                if (weight!=1){
                  h_Z_pt_truth_cuts_outside->Fill(truth_z_pt,weight);
                }
              }
              if (outside_tau){
                h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(reco_mass_outside,weight);
                h_Z_pt_reco_cuts_outside->Fill(Z_pt,weight);
                h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(elec_0_p4->Pt(),weight);
                h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
                if (tau_0_n_charged_tracks==1){
                  if (Z_pt<100){
                    h_sum_pt_cuts_1p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>100 && Z_pt<150){
                    h_sum_pt_cuts_1p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>150) {
                    h_sum_pt_cuts_1p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  }
                }
                if (tau_0_n_charged_tracks==3){
                  if (Z_pt<100){
                    h_sum_pt_cuts_3p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>100 && Z_pt<150){
                    h_sum_pt_cuts_3p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  } if (Z_pt>150) {
                    h_sum_pt_cuts_3p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                  }
                }
                if (weight!=1){
                  h_Z_pt_truth_cuts_outside->Fill(truth_z_pt,weight);
                }
              }
              if (cuts[9]==1) {
                h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(met_reco_p4->Pt(),weight);
                h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(lepmet_mass,weight);
                h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(elec_0_p4->Pt(),weight);
                h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(omega,weight);
                h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(n_jets, weight);
                h_lep_phi_cuts_tpt->Fill(elec_0_p4->Phi(),weight);
                h_tau_phi_cuts_tpt->Fill(tau_0_p4->Phi(),weight);
                h_delta_phi_cuts_tpt->Fill(angle,weight);
                h_tau_nprongs_cuts_tpt->Fill(tau_0_n_charged_tracks,weight);
                h_n_fake_tracks_cuts_tpt->Fill(tau_0_n_fake_tracks,weight);
                h_n_core_tracks_cuts_tpt->Fill(tau_0_n_core_tracks,weight);
                h_n_isolation_tracks_cuts_tpt->Fill(tau_0_n_isolation_tracks,weight);
                h_n_tracks_cuts_tpt->Fill(tau_0_n_all_tracks,weight);
                h_ljet1_pt_topo_cuts_tpt->Fill(ljet_0_p4->Pt(),weight);
                h_ljet2_pt_topo_cuts_tpt->Fill(ljet_1_p4->Pt(),weight);
                h_ljet3_pt_topo_cuts_tpt->Fill(ljet_2_p4->Pt(),weight);
                h_ratio_ptjet_zpt_cuts_tpt->Fill(r_jpt_zpt,weight);
                h_ratio_lpt_tpt_cuts_tpt->Fill(r_lpt_tpt,weight);
                if (weight!=1){
                  if (tau_0_n_charged_tracks==1){
                    h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                  }
                  if (tau_0_n_charged_tracks==3){
                    h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                  }
                }
                if (inside) {
                  h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(reco_mass,weight);
                  h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_inside->Fill(tau_0_p4->Pt(),weight);
                  h_Z_pt_reco_cuts_tpt_inside->Fill(Z_pt,weight);
                  h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                  h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                  h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_p4->Pt()+pt_tau_nu+muon_0_p4->Pt()+pt_lep_nu,weight);
                  if (tau_0_n_charged_tracks==1){
                    if (Z_pt<100){
                      h_sum_pt_cuts_tpt_1p_ZpTa->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_tpt_1p_ZpTb->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_tpt_1p_ZpTc->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                    }
                  }
                  if (tau_0_n_charged_tracks==3){
                    if (Z_pt<100){
                      h_sum_pt_cuts_tpt_3p_ZpTa->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_tpt_3p_ZpTb->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_tpt_3p_ZpTc->Fill(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu,weight);
                    }
                  }
                  if (weight!=1){
                    h_Z_pt_truth_cuts_tpt_inside->Fill(truth_z_pt,weight);
                  }
                }
                if (outside_lep) {
                  h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(reco_mass_outside,weight);
                  h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_outside->Fill(tau_0_p4->Pt(),weight);
                  h_Z_pt_reco_cuts_tpt_outside->Fill(Z_pt,weight);
                  h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                  h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_p4->Pt(),weight);
                  h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
                  if (tau_0_n_charged_tracks==1){
                    if (Z_pt<100){
                      h_sum_pt_cuts_tpt_1p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_tpt_1p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_tpt_1p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    }
                  }
                  if (tau_0_n_charged_tracks==3){
                    if (Z_pt<100){
                      h_sum_pt_cuts_tpt_3p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_tpt_3p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_tpt_3p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    }
                  }
                  if (weight!=1){
                    h_Z_pt_truth_cuts_tpt_outside->Fill(truth_z_pt,weight);
                  }
                }
                if (outside_tau){
                  h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(reco_mass_outside,weight);
                  h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_outside->Fill(tau_0_p4->Pt(),weight);
                  h_Z_pt_reco_cuts_tpt_outside->Fill(Z_pt,weight);
                  h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(elec_0_p4->Pt(),weight);
                  h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                  h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt,weight);
                  if (tau_0_n_charged_tracks==1){
                    if (Z_pt<100){
                      h_sum_pt_cuts_tpt_1p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_tpt_1p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_tpt_1p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    }
                  }
                  if (tau_0_n_charged_tracks==3){
                    if (Z_pt<100){
                      h_sum_pt_cuts_tpt_3p_ZpTa->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_tpt_3p_ZpTb->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_tpt_3p_ZpTc->Fill(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight);
                    }
                  }
                  if (weight!=1){
                    h_Z_pt_truth_cuts_tpt_outside->Fill(truth_z_pt,weight);
                  }
                }
              }
            }
          }
        }
      }
    }
}

void CLoop::Style(double lumFactor) {
  // This function is where you can control the style elements of your histograms and write them to a file
    // It is called once per data set

    // For example, set some properties of the lep_n histogram
    /*h_lep_n->GetXaxis()->SetTitle("Number of leptons per event"); // label x axis
    h_lep_n->GetYaxis()->SetTitle("Number of entries/bin"); // label y axis
    h_lep_n->SetTitle("Number of leptons  per event");
    h_lep_n->SetLineColor(kRed);*/ // set the line colour to red
    // For more information see https://root.cern.ch/root/htmldoc/guides/users-guide/Histograms.html
    h_eBDT_fail_mle->Write();
    h_mle_fail_eBDT->Write();
    // Write histograms to a file
    // This needs to be done for each histogram
    h_inva_mass_ltau_topo->Write();
    h_inva_mass_ltau_topo_dphi_bdte_btag_iso_rnn_pte_omega_mreco_tpt->Write();

    h_trans_lep_mass_topo->Write();
    h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_trans_lep_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    if (lumFactor!=1){
      h_tau_matched_1p_topo->Write();
      h_tau_matched_1p_topo_dphi->Write();
      h_tau_matched_1p_topo_dphi_bdte->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

      h_tau_matched_3p_topo->Write();
      h_tau_matched_3p_topo_dphi->Write();
      h_tau_matched_3p_topo_dphi_bdte->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

      h_Z_pt_truth_inside_topo->Write();
      h_Z_pt_truth_cuts_inside->Write();
      h_Z_pt_truth_cuts_tpt_inside->Write();
      h_Z_pt_truth_outside_topo->Write();
      h_Z_pt_truth_cuts_outside->Write();
      h_Z_pt_truth_cuts_tpt_outside->Write();
    }

    h_rnn_score_1prong_topo->Write();
    h_rnn_score_1prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt->Write();
    h_rnn_score_3prong_topo->Write();
    h_rnn_score_3prong_topo_dphi_bdte_btag_iso_pte_omega_mle_mreco_tpt->Write();

    h_bdt_e_score_topo->Write();
    h_bdt_e_score_topo_dphi_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    // Writing jet pT
    h_ljet1_pt_topo->Write();
    h_ljet1_pt_topo_cuts->Write();
    h_ljet1_pt_topo_cuts_tpt->Write();

    h_ljet2_pt_topo->Write();
    h_ljet2_pt_topo_cuts->Write();
    h_ljet2_pt_topo_cuts_tpt->Write();

    h_ljet3_pt_topo->Write();
    h_ljet3_pt_topo_cuts->Write();
    h_ljet3_pt_topo_cuts_tpt->Write();

    //Writing lep pT
    h_lep_pt0_topo->Write();
    h_lep_pt0_topo_dphi->Write();
    h_lep_pt0_topo_dphi_bdte->Write();
    h_lep_pt0_topo_dphi_bdte_btag->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    h_lep_pt0_topo_dphi_bdte_btag_iso_rnn_omega_mle_mreco_tpt->Write();

    //Writing lep pT+nu
    h_lep_pt0nu_topo->Write();
    h_lep_pt0nu_topo_dphi->Write();
    h_lep_pt0nu_topo_dphi_bdte->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_lep_pt0nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    //Writing tau pT
    h_lep_pt1_topo->Write();
    h_lep_pt1_topo_dphi->Write();
    h_lep_pt1_topo_dphi_bdte->Write();
    h_lep_pt1_topo_dphi_bdte_btag->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_inside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_inside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_inside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_inside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_outside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_outside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_outside->Write();
    h_lep_pt1_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt_outside->Write();

    //Writing tau pT+nu
    h_lep_pt1nu_topo->Write();
    h_lep_pt1nu_topo_dphi->Write();
    h_lep_pt1nu_topo_dphi_bdte->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_lep_pt1nu_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    //Declaring sum pT
    h_sum_pt_topo->Write();
    h_sum_pt_topo_dphi->Write();
    h_sum_pt_topo_dphi_bdte->Write();
    h_sum_pt_topo_dphi_bdte_btag->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_sum_pt_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    h_sum_pt_topo_1p_ZpTa->Write();
    h_sum_pt_topo_1p_ZpTb->Write();
    h_sum_pt_topo_1p_ZpTc->Write();
    h_sum_pt_topo_3p_ZpTa->Write();
    h_sum_pt_topo_3p_ZpTb->Write();
    h_sum_pt_topo_3p_ZpTc->Write();

    h_sum_pt_cuts_1p_ZpTa->Write();
    h_sum_pt_cuts_1p_ZpTb->Write();
    h_sum_pt_cuts_1p_ZpTc->Write();
    h_sum_pt_cuts_3p_ZpTa->Write();
    h_sum_pt_cuts_3p_ZpTb->Write();
    h_sum_pt_cuts_3p_ZpTc->Write();

    h_sum_pt_cuts_tpt_1p_ZpTa->Write();
    h_sum_pt_cuts_tpt_1p_ZpTb->Write();
    h_sum_pt_cuts_tpt_1p_ZpTc->Write();
    h_sum_pt_cuts_tpt_3p_ZpTa->Write();
    h_sum_pt_cuts_tpt_3p_ZpTb->Write();
    h_sum_pt_cuts_tpt_3p_ZpTc->Write();

    //Writing MET
    h_met_topo->Write();
    h_met_topo_dphi->Write();
    h_met_topo_dphi_bdte->Write();
    h_met_topo_dphi_bdte_btag->Write();
    h_met_topo_dphi_bdte_btag_iso->Write();
    h_met_topo_dphi_bdte_btag_iso_rnn->Write();
    h_met_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_met_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    //Writing reco
    h_reco_mass_topo->Write();
    h_reco_mass_topo_dphi->Write();
    h_reco_mass_topo_dphi_bdte->Write();
    h_reco_mass_topo_dphi_bdte_btag->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    h_reco_mass_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt->Write();

    h_reco_mass_met_outside_topo->Write();
    h_reco_mass_met_outside_topo_dphi->Write();
    h_reco_mass_met_outside_topo_dphi_bdte->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    h_reco_mass_met_outside_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_tpt->Write();

    //Writing jet number
    h_jet_n_topo->Write();
    h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_jet_n_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    //Writing b-tag
    h_b_tag_topo->Write();
    h_b_tag_topo_dphi_bdte_iso_rnn_pte_omega_mle_mreco_tpt->Write();

    //Writing isolation variables
    h_elec_0_iso_topo->Write();
    h_elec_0_iso_topo_dphi_bdte_btag_rnn_pte_omega_mle_mreco_tpt->Write();

    h_omega_topo->Write();
    h_omega_topo_dphi->Write();
    h_omega_topo_dphi_bdte->Write();
    h_omega_topo_dphi_bdte_btag->Write();
    h_omega_topo_dphi_bdte_btag_iso->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt->Write();

    h_Z_pt_reco_inside_topo->Write();
    h_Z_pt_reco_cuts_inside->Write();
    h_Z_pt_reco_cuts_tpt_inside->Write();
    h_Z_pt_reco_outside_topo->Write();
    h_Z_pt_reco_cuts_outside->Write();
    h_Z_pt_reco_cuts_tpt_outside->Write();

    h_lep_phi_topo->Write();
    h_tau_phi_topo->Write();
    h_delta_phi->Write();
    h_delta_phi_second_stage->Write();
    h_delta_phi_topo->Write();
    h_tau_nprongs_topo->Write();
    h_lep_phi_cuts->Write();
    h_lep_phi_cuts_tpt->Write();
    h_tau_phi_cuts->Write();
    h_tau_phi_cuts_tpt->Write();
    h_delta_phi_cuts->Write();
    h_delta_phi_cuts_tpt->Write();
    h_delta_phi_cuts_butphi->Write();
    h_tau_nprongs_cuts->Write();
    h_tau_nprongs_cuts_tpt->Write();

    h_ratio_ptjet_zpt_topo->Write();
    h_ratio_lpt_tpt_topo->Write();
    h_ratio_ptjet_zpt_cuts->Write();
    h_ratio_lpt_tpt_cuts->Write();
    h_ratio_ptjet_zpt_cuts_tpt->Write();
    h_ratio_lpt_tpt_cuts_tpt->Write();

    h_n_fake_tracks->Write();
    h_n_core_tracks->Write();
    h_n_isolation_tracks->Write();
    h_n_fake_tracks_cuts->Write();
    h_n_core_tracks_cuts->Write();
    h_n_isolation_tracks_cuts->Write();
    h_n_fake_tracks_cuts_tpt->Write();
    h_n_core_tracks_cuts_tpt->Write();
    h_n_isolation_tracks_cuts_tpt->Write();
    h_n_tracks->Write();
    h_n_tracks_cuts->Write();
    h_n_tracks_cuts_tpt->Write();
}


#endif // End header guard
