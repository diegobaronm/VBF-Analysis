// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#include <utility>

const int run2015Begin = 276262;
const int run2015End   = 284484;

const int run2016Begin = 297730;
const int run2016End   = 311481;

const int run2017Begin = 323427;
const int run2017End   = 341649;

const int run2018Begin = 341649;
const int run2018End   = 364292;


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

int is_inside_jets(TLorentzVector * test_jet,TLorentzVector * j1, TLorentzVector * j2){
  double delta_y_j1j2=abs(j1->Rapidity()-j2->Rapidity());
  double delta_y_j1test=abs(j1->Rapidity()-test_jet->Rapidity());
  double delta_y_j2test=abs(j2->Rapidity()-test_jet->Rapidity());
  if(delta_y_j1test>delta_y_j1j2 || delta_y_j2test>delta_y_j1j2){return 0;}
  else{return 1;}
}

double min_deltaR(TLorentzVector* test_particle, std::vector<UInt_t> bool_vector_container, std::vector<TLorentzVector*> jet_container){

  std::vector<double> delta_Rs{};

  for (size_t index{0};index<jet_container.size();index++){
    if (bool_vector_container[index]!=0){
      delta_Rs.push_back(jet_container[index]->DeltaR(*test_particle));
    }
    else {break;}
  }

  double min_dR=*std::min_element(delta_Rs.begin(),delta_Rs.end());
  return min_dR;
}

void CLoop::Book(double lumFactor) {
    double pi=TMath::Pi();

    #ifdef WEIGHTSYSTEMATICS

    h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("mass_jj_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("mass_jj_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("mass_jj_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("mass_jj_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_PRW_DATASF_1down_pileup_combined_weight = new TH1F("mass_jj_PRW_DATASF_1down_pileup_combined_weight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_PRW_DATASF_1up_pileup_combined_weight = new TH1F("mass_jj_PRW_DATASF_1up_pileup_combined_weight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT = new TH1F("mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT = new TH1F("mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT = new TH1F("mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT = new TH1F("mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT = new TH1F("mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT = new TH1F("mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT = new TH1F("mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT = new TH1F("mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium = new TH1F("mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium","Invariant mass di-jet system",5000,0,5000);

    #endif 

    h_delta_phi = new TH1F("delta_phi","Delta phi between tau and lep",32,0,3.2);
    h_delta_y = new TH1F("delta_y","Delta Rapidity",100,0,10);
    h_n_bjets = new TH1F("n_bjets","Number of b_jets",5,0,5);
    h_lepiso = new TH1F("lepiso","Lep Isolation",2,0,2);
    h_rnn_score_1p = new TH1F("rnn_score_1p","RNN Score 1 prong taus",100,0,1);
    h_rnn_score_3p = new TH1F("rnn_score_3p","RNN Score 3 prong taus",100,0,1);
    h_lep_pt = new TH1F("lep_pt","Lep pT",500,0,500);
    h_tau_pt = new TH1F("tau_pt","Tau pT",500,0,500);
    h_ljet0_pt = new TH1F("ljet0_pt","Light jet0 pT",1000,0,1000);
    h_ljet1_pt = new TH1F("ljet1_pt","Light jet1 pT",1000,0,1000);
    h_pt_bal = new TH1F("pt_bal","pT Balance",100,0,1);
    h_mass_jj = new TH1F("mass_jj","Invariant mass di_jet system",5000,0,5000);
    h_n_jets_interval = new TH1F("n_jets_interval","N jets between rapidity interval",10,0,10);
    h_Z_centrality = new TH1F("Z_centrality","Z boson centrality",500,0,5);
    h_omega = new TH1F("omega","Omega variable",60,-3.0,3.0);
    h_reco_mass_i = new TH1F("reco_mass_i","Reconstructed mass in between events",240,0,240);
    h_reco_mass_o = new TH1F("reco_mass_o","Reconstructed mass outside events",240,0,240);
    h_reco_mass = new TH1F("reco_mass_","Reconstructed mass all events",240,0,240);
}

void CLoop::Fill(double weight, int z_sample) {
  double pi=TMath::Pi();
  //Charges and lepton ID
  float ql=muon_0_q;
  float qtau=tau_0_q;
  bool lepton_id=muon_0_id_medium;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;
  
  if (ql!=qtau && n_muons==1 && n_taus_rnn_loose>=1 && weight > -190 && lepton_id && n_ljets>=2 && n_ljets<=3 && useEvent==1){
    
    //angles
    double angle_l_MET=del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
    double angle_tau_MET=del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
    double angle=del_phi(tau_0_p4->Phi(),muon_0_p4->Phi());
    //trigger decision
    bool trigger_decision= false;
    bool trigger_match= false;
    if (run_number>= 276262 && run_number<=284484) {
      trigger_decision= bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
      trigger_match=bool(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50);
    } else {
      trigger_decision= bool(HLT_mu26_ivarmedium | HLT_mu50);
      trigger_match=bool(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50);
    }
    // INVARIANT MASS 2-JETS
    double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
    if (mjj>=250 && trigger_decision  && trigger_match  && abs(muon_0_p4->Eta())>=0.1 && abs(tau_0_p4->Eta())>=0.1) {

      //topology
      bool inside= abs(angle-(angle_l_MET+angle_tau_MET))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
      bool outside_lep= angle_l_MET<angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_l_MET)>0;
      bool outside_tau= angle_l_MET>angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_tau_MET)>0;
      bool signal_events = inside || outside_lep || outside_tau;

      if (signal_events){
        // RECO mass AND neutrino momentum
        double cot_lep=1.0/tan(muon_0_p4->Phi());
        double cot_tau=1.0/tan(tau_0_p4->Phi());
        double pt_tau_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_lep)/(cos(tau_0_p4->Phi())-sin(tau_0_p4->Phi())*cot_lep);
        double pt_lep_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_tau)/(cos(muon_0_p4->Phi())-sin(muon_0_p4->Phi())*cot_tau);

        double reco_mass{};
        if(inside){
            reco_mass=sqrt(2*muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+2*muon_0_p4->Pt()*pt_tau_nu*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+2*tau_0_p4->Pt()*pt_lep_nu*(cosh(tau_0_p4->Eta()-muon_0_p4->Eta())-cos(tau_0_p4->Phi()-muon_0_p4->Phi()))+2*pt_lep_nu*pt_tau_nu*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi())));
        }

        double neutrino_pt=0;
        double reco_mass_outside=0;
        if (outside_lep) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_l_MET);
          reco_mass_outside=5+sqrt(2*(muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+tau_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))));
        }
        if (outside_tau) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_tau_MET);
          reco_mass_outside=5+sqrt(2*(muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+muon_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))));
        }

        // ZpT calculations
        double Z_pt_x=0;
        double Z_pt_y=0;
        double Z_pt=0;
        double truth_z_pt=0.0;

        // truth ZpT definition
        if (z_sample==1 || z_sample==2)
        {
          truth_z_pt=truth_Z_p4->Pt()/1000;
        }

        if (inside) {
          Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi())+pt_tau_nu*cos(tau_0_p4->Phi())+pt_lep_nu*cos(muon_0_p4->Phi());
          Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi())+pt_tau_nu*sin(tau_0_p4->Phi())+pt_lep_nu*sin(muon_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }
        if (outside_tau) {
          Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi())+neutrino_pt*cos(tau_0_p4->Phi());
          Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi())+neutrino_pt*sin(tau_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }
        if (outside_lep) {
          Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi())+neutrino_pt*cos(muon_0_p4->Phi());
          Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi())+neutrino_pt*sin(muon_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }

        // TRANSVERSE MASS LEPTON
        double lepmet_mass=sqrt(2*muon_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(muon_0_p4->Phi()-met_reco_p4->Phi())));
        // Vector sum pT of the jets
        double jet_pt_sum= (*ljet_0_p4 + *ljet_1_p4).Pt();
        // Ratio ZpT/jet_pt_sum
        double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;

        // OMEGA VARIABLE DEFINITION
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

        // VBF variables
        // DELTA RAPIDITY 2-JETS
        double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());
        // NUMBER OF JETS INTERVAL
        int n_jets_interval{};
        if(n_ljets>2){
          n_jets_interval=n_jets_interval+is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4);
        }
        //PT BALANCE
        double pt_bal{0};
        if(inside){
          TLorentzVector nu_tau_p4(pt_tau_nu*cos(tau_0_p4->Phi()),pt_tau_nu*sin(tau_0_p4->Phi()),0,0);
          TLorentzVector nu_lep_p4(pt_lep_nu*cos(muon_0_p4->Phi()),pt_lep_nu*sin(muon_0_p4->Phi()),0,0);
          if (n_jets_interval==0){
            pt_bal=(((*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+nu_tau_p4+nu_lep_p4)).Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+nu_tau_p4.Pt()+nu_lep_p4.Pt());
          } else {
            pt_bal=(((*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4)+nu_tau_p4+nu_lep_p4)).Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt()+nu_tau_p4.Pt()+nu_lep_p4.Pt());
          }


        } else {
          if (outside_lep){
            TLorentzVector nu_p4(pt_lep_nu*cos(muon_0_p4->Phi()),pt_lep_nu*sin(muon_0_p4->Phi()),0,0);
            if (n_jets_interval==0){
              pt_bal=(((*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+nu_p4.Pt());
            } else {
              pt_bal=(((*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt()+nu_p4.Pt());
            }
          } else{
            if(outside_tau){
              TLorentzVector nu_p4(pt_tau_nu*cos(tau_0_p4->Phi()),pt_tau_nu*sin(tau_0_p4->Phi()),0,0);
              if (n_jets_interval==0){
                pt_bal=(((*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+nu_p4.Pt());
              } else {
                pt_bal=(((*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt()+nu_p4.Pt());
              }
            }
          }
        }
        // Z BOSON CENTRALITY
        double lepton_xi=((*tau_0_p4)+(*muon_0_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        //pT gap jet
        double pt_gap_jet{};
        if (is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4)){pt_gap_jet=ljet_2_p4->Pt();}

        // Minimum DeltaR between lepton and jets
        std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
        std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};

        double min_dR_tau = min_deltaR(tau_0_p4,is_jet_present,jet_container);
        double min_dR_lep = min_deltaR(muon_0_p4,is_jet_present,jet_container);

        // Definition of the superCR = CR(a+b+c)
        bool CRa = z_centrality < 0.5 && n_jets_interval == 1;
        bool CRb = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 1;
        bool CRc = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 0;
        bool superCR = CRa || CRb || CRc;

        // Cuts vector
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        // CUTS
        if (angle<=3.2){cuts[0]=1;}
        if(delta_y>=2.0){cuts[1]=1;}
        if(n_bjets_MV2c10_FixedCutBEff_85==0){cuts[2]=1;}
        if(muon_0_iso_TightTrackOnly_FixedRad==1){cuts[3]=1;}
        if(tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans>=0.25){cuts[4]=1;}
        if(tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans>=0.40){cuts[4]=1;}
        if(muon_0_p4->Pt()>=27){cuts[5]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[6]=1;}
        if(ljet_1_p4->Pt()>=70){cuts[7]=1;}
        if(pt_bal<=0.15){cuts[8]=1;}
        if(mjj>=1000){cuts[9]=1;}
        if(n_jets_interval==0){cuts[10]=1;}
        if(z_centrality<0.5){cuts[11]=1;} // SR -> z_centrality < 0.5
        if (omega> -0.2 && omega <1.6){cuts[12]=1;}
        if (inside) {
          if (reco_mass<116 && reco_mass>66){cuts[13]=1;}
        }
        if (outside_lep) {
          if (reco_mass_outside<116 && reco_mass_outside>66){cuts[13]=1;}
        }
        if (outside_tau) {
          if (reco_mass_outside<116 && reco_mass_outside>66){cuts[13]=1;}
        }
        if (tau_0_p4->Pt()>=25){cuts[14]=1;}

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        int sum{};
        for(auto &j : cuts){sum=sum+j;}

        // FILLING CUTS HISTOGRAMS
        if ((sum-cuts[0])==14) {
          h_delta_phi->Fill(angle,weight);
        }
        if ((sum-cuts[1])==14) {
          h_delta_y->Fill(delta_y,weight);
        }
        if ((sum-cuts[2])==14) {
          h_n_bjets->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        }
        if ((sum-cuts[3])==14) {
          h_lepiso->Fill(muon_0_iso_TightTrackOnly_FixedRad,weight);
        }
        if ((sum-cuts[4])==14) {
          if (tau_0_n_charged_tracks==1){
            h_rnn_score_1p->Fill(tau_0_jet_rnn_score_trans,weight);
          }
          if (tau_0_n_charged_tracks==3){
            h_rnn_score_3p->Fill(tau_0_jet_rnn_score_trans,weight);
          }
        }
        if ((sum-cuts[5])==14) {
          h_lep_pt->Fill(muon_0_p4->Pt(),weight);
        }
        if ((sum-cuts[6])==14) {
          h_ljet0_pt->Fill(ljet_0_p4->Pt(),weight);
        }
        if ((sum-cuts[7])==14) {
          h_ljet1_pt->Fill(ljet_1_p4->Pt(),weight);
        }
        if ((sum-cuts[8])==14) {
          h_pt_bal->Fill(pt_bal,weight);
        }
        if ((sum-cuts[9])==14) {
          h_mass_jj->Fill(mjj,weight);

          #ifdef WEIGHTSYSTEMATICS
          h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(mjj,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
          h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(mjj,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
          h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(mjj,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
          h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(mjj,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
          h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
          h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(mjj,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
          h_mass_jj_PRW_DATASF_1down_pileup_combined_weight->Fill(mjj,weight*PRW_DATASF_1down_pileup_combined_weight/NOMINAL_pileup_combined_weight);
          h_mass_jj_PRW_DATASF_1up_pileup_combined_weight->Fill(mjj,weight*PRW_DATASF_1up_pileup_combined_weight/NOMINAL_pileup_combined_weight);
          h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Fill(mjj,weight*jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
          h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Fill(mjj,weight*jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
          h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Fill(mjj,weight*jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
          h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Fill(mjj,weight*jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
          h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Fill(mjj,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
          h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Fill(mjj,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
          h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Fill(mjj,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
          h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Fill(mjj,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium->Fill(mjj,weight*tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium/tau_0_NOMINAL_TauEffSF_JetRNNmedium);
          #endif

        }
        if ((sum-cuts[10])==14) {
          h_n_jets_interval->Fill(n_jets_interval,weight);
        }
        if ((sum-cuts[11])==14) {
          h_Z_centrality->Fill(z_centrality,weight);
        }
        if ((sum-cuts[12])==14) {
          h_omega->Fill(omega,weight);
        }
        if (inside) {
          if ((sum-cuts[13])==14) {
            h_reco_mass_i->Fill(reco_mass,weight);
            h_reco_mass->Fill(reco_mass,weight);
          }
        }
        if (outside_lep) {
          if ((sum-cuts[13])==14) {
            h_reco_mass_o->Fill(reco_mass_outside,weight);
            h_reco_mass->Fill(reco_mass_outside,weight);
          }
        }
        if (outside_tau) {
          if ((sum-cuts[13])==14) {
            h_reco_mass_o->Fill(reco_mass_outside,weight);
            h_reco_mass->Fill(reco_mass_outside,weight);
          }
        }
        if ((sum-cuts[14])==14) {
          h_tau_pt->Fill(tau_0_p4->Pt(),weight);
        }
      }
    }
  }
}

void CLoop::Style(double lumFactor) {
    
  #ifdef WEIGHTSYSTEMATICS
  h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
  h_mass_jj_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
  h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
  h_mass_jj_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
  h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
  h_mass_jj_PRW_DATASF_1down_pileup_combined_weight->Write();
  h_mass_jj_PRW_DATASF_1up_pileup_combined_weight->Write();
  h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Write();
  h_mass_jj_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Write();
  h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Write();
  h_mass_jj_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Write();
  h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Write();
  h_mass_jj_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Write();
  h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Write();
  h_mass_jj_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium->Write();
  h_mass_jj_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium->Write();
  #endif
  
  h_delta_phi->Write();
  h_delta_y->Write();
  h_n_bjets->Write();
  h_lepiso->Write();
  h_rnn_score_1p->Write();
  h_rnn_score_3p->Write();
  h_lep_pt->Write();
  h_ljet0_pt->Write();
  h_ljet1_pt->Write();
  h_pt_bal->Write();
  h_mass_jj->Write();
  h_n_jets_interval->Write();
  h_Z_centrality->Write();
  h_omega->Write();
  h_reco_mass_i->Write();
  h_reco_mass_o->Write();
  h_reco_mass->Write();
  h_tau_pt->Write();
}

#endif // End header guard

