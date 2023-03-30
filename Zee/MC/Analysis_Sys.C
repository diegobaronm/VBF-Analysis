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
    h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13 = new TH1F("mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13 = new TH1F("mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13 = new TH1F("mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13 = new TH1F("mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13 = new TH1F("mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13 = new TH1F("mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight = new TH1F("mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight = new TH1F("mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight = new TH1F("mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight = new TH1F("mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight = new TH1F("mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight = new TH1F("mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk = new TH1F("mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk = new TH1F("mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk = new TH1F("mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk = new TH1F("mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk = new TH1F("mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk = new TH1F("mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight = new TH1F("mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight = new TH1F("mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight = new TH1F("mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight = new TH1F("mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight = new TH1F("mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight","Invariant mass di-jet system",5000,0,5000);
    h_mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight = new TH1F("mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight","Invariant mass di-jet system",5000,0,5000);
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
    #endif
    h_delta_phi = new TH1F("delta_phi","Delta phi between leptons",32,0,3.2);
    h_delta_y = new TH1F("delta_y","Delta Rapidity",100,0,10);
    h_n_bjets = new TH1F("n_bjets","Number of b_jets",5,0,5);
    h_lepiso = new TH1F("lepiso","Leptons isolation",2,0,2);
    h_lep1_pt = new TH1F("lep1_pt","Lep 1 pT",500,0,500);
    h_lep2_pt = new TH1F("lep2_pt","Lep 2 pT",500,0,500);
    h_ljet0_pt = new TH1F("ljet0_pt","Light jet0 pT",1000,0,1000);
    h_ljet1_pt = new TH1F("ljet1_pt","Light jet1 pT",1000,0,1000);
    h_pt_bal = new TH1F("pt_bal","pT Balance",100,0,1);
    h_mass_jj = new TH1F("mass_jj","Invariant mass di_jet system",5000,0,5000);
    h_n_jets_interval = new TH1F("n_jets_interval","N jets between rapidity interval",5,0,5);
    h_Z_centrality = new TH1F("Z_centrality","Z boson centrality",350,0,3.5);
    h_inv_mass = new TH1F("inv_mass","Invariant mass di-lepton system",240,0,240);
}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();

    bool elec_id = elec_0_id_tight && elec_1_id_tight;
    float q_mu0=elec_0_q;
    float q_mu1=elec_1_q;
    size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

    if (n_electrons==2 && q_mu0!=q_mu1 && elec_id  && n_ljets>=2 && n_ljets<=3 && useEvent==1){
      //angles
      double angle_l_MET=del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(elec_1_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(elec_1_p4->Phi(),elec_0_p4->Phi());

      bool trigger_decision= false;
      bool trigger_match= false;
      bool trigger_match_1 = false;
      bool trigger_match_2 = false;
      bool trigger_match_12 = false;
      if (run_number>= 276262 && run_number<=284484) {
        trigger_decision = bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
        trigger_match_1 = bool((eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && !(eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
        trigger_match_2 = bool(!(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && (eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
        trigger_match_12 = bool((eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && (eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
        if(weight!=1){
          if (trigger_match_1){weight=weight*elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
          if (trigger_match_2){weight=weight*elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
        }
        trigger_match = trigger_match_1 | trigger_match_2 | trigger_match_12;
      } else {
        trigger_decision = bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
        trigger_match_1 = bool((eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && !(eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
        trigger_match_2 = bool(!(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && (eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
        trigger_match_12 = bool((eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && (eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
        if(weight!=1){
          if (trigger_match_1){weight=weight*elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
          if (trigger_match_2){weight=weight*elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
        }
        trigger_match = trigger_match_1 | trigger_match_2 | trigger_match_12;
      }

      // INVARIANT MASS 2-JETS
      double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
      if (mjj>=250 && trigger_decision && trigger_match) {

        double inv_mass{};
        inv_mass=sqrt(2*elec_0_p4->Pt()*elec_1_p4->Pt()*(cosh(elec_0_p4->Eta()-elec_1_p4->Eta())-cos(elec_0_p4->Phi()-elec_1_p4->Phi())));

        double Z_pt_x=0;
        double Z_pt_y=0;
        double Z_pt=0;
        double truth_z_pt=0.0;

        if (z_sample==1 || z_sample==2)
        {
          truth_z_pt=truth_Z_p4->Pt()/1000;
        }

        Z_pt_x=elec_1_p4->Pt()*cos(elec_1_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi());
        Z_pt_y=elec_1_p4->Pt()*sin(elec_1_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi());
        Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
        if (z_sample==0){
            truth_z_pt=Z_pt;
        }

        // Vector sum pT of the jets
        double jet_pt_sum= (*ljet_0_p4 + *ljet_1_p4).Pt();
        // Ratio ZpT/jet_pt_sum
        double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;

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
        if(n_jets_interval==0){
          pt_bal=(((*elec_0_p4)+(*elec_1_p4)+(*ljet_0_p4)+(*ljet_1_p4))).Pt()/(elec_0_p4->Pt()+elec_1_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt());
        } else {
          pt_bal=(((*elec_0_p4)+(*elec_1_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4))).Pt()/(elec_0_p4->Pt()+elec_1_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt());
        }

        // Z BOSON CENTRALITY
        double lepton_xi=((*elec_0_p4)+(*elec_1_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        //pT gap jet
        double pt_gap_jet{};
        if (is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4)){pt_gap_jet=ljet_2_p4->Pt();}

        // Minimum DeltaR between lepton and jets
        std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
        std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};

        double min_dR_lep1 = min_deltaR(elec_0_p4,is_jet_present,jet_container);
        double min_dR_lep2 = min_deltaR(elec_1_p4,is_jet_present,jet_container);

        // Definition of the superCR = CR(a+b+c)
        bool CRa = z_centrality < 0.5 && n_jets_interval == 1;
        bool CRb = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 1;
        bool CRc = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 0;
        bool superCR = CRa || CRb || CRc;

        // Cuts vector
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        double a{50},b{40};
        // CUTS
        if (angle<=3.2){cuts[0]=1;}
        if(delta_y>=2.0){cuts[1]=1;}
        if(n_bjets_MV2c10_FixedCutBEff_85==0){cuts[2]=1;}
        if(elec_0_iso_FCTight==1 && elec_1_iso_FCTight==1){cuts[3]=1;}
        if(elec_0_p4->Pt()>=a){cuts[4]=1;}
        if(elec_1_p4->Pt()>=b){cuts[5]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[6]=1;}
        if(ljet_1_p4->Pt()>=70){cuts[7]=1;}
        if(pt_bal<=0.15){cuts[8]=1;}
        if(mjj>=1000){cuts[9]=1;}
        if(n_jets_interval==0){cuts[10]=1;}
        if(z_centrality<0.5){cuts[11]=1;}
        if (inv_mass>81 && inv_mass<101){cuts[12]=1;} // Low mass range 81 < m < 101 GeV.
        if (event_number%2==0){
          if(elec_0_p4->Pt()>=(a+0)){cuts[13]=1;}
        } else {
          if(elec_1_p4->Pt()>=(b+0)){cuts[13]=1;}
        }

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        int sum{};
        for(auto &j : cuts){sum=sum+j;}

       // FILLING CUTS HISTOGRAMS
        if ((sum-cuts[0])==13) {
          h_delta_phi->Fill(angle,weight);
        }
        if ((sum-cuts[1])==13) {
          h_delta_y->Fill(delta_y,weight);
        }
        if ((sum-cuts[2])==13) {
          h_n_bjets->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        }
        if ((sum-cuts[3])==13) {
          h_lepiso->Fill(elec_0_iso_FCTight==1 && elec_1_iso_FCTight==1,weight);
        }
        if ((sum-cuts[4])==13) {
          h_lep1_pt->Fill(elec_0_p4->Pt(),weight);
        }
        if ((sum-cuts[5])==13) {
          h_lep2_pt->Fill(elec_1_p4->Pt(),weight);
        }
        if ((sum-cuts[6])==13) {
          h_ljet0_pt->Fill(ljet_0_p4->Pt(),weight);
        }
        if ((sum-cuts[7])==13) {
          h_ljet1_pt->Fill(ljet_1_p4->Pt(),weight);
        }
        if ((sum-cuts[8])==13) {
          h_pt_bal->Fill(pt_bal,weight);
        }
        if ((sum-cuts[9])==13) {
          h_mass_jj->Fill(mjj,weight);
          #ifdef WEIGHTSYSTEMATICS
          h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13->Fill(mjj,weight*elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13/elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13);
            h_mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13->Fill(mjj,weight*elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13/elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13);
            h_mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13->Fill(mjj,weight*(elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13*elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13)/(elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13*elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13));
            h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13->Fill(mjj,weight*elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13/elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13);
            h_mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13->Fill(mjj,weight*elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13/elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13);
            h_mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13->Fill(mjj,weight*(elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13*elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13)/(elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13*elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13));
            h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Fill(mjj,weight*elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight/elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight);
            h_mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Fill(mjj,weight*elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight/elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight);
            h_mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Fill(mjj,weight*(elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight)/(elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight));
            h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Fill(mjj,weight*elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight/elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight);
            h_mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Fill(mjj,weight*elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight/elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight);
            h_mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Fill(mjj,weight*(elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight)/(elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight));
            h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk->Fill(mjj,weight*elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk/elec_0_NOMINAL_EleEffSF_offline_RecoTrk);
            h_mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk->Fill(mjj,weight*elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk/elec_1_NOMINAL_EleEffSF_offline_RecoTrk);
            h_mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk->Fill(mjj,weight*(elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk*elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk)/(elec_0_NOMINAL_EleEffSF_offline_RecoTrk*elec_1_NOMINAL_EleEffSF_offline_RecoTrk));
            h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk->Fill(mjj,weight*elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk/elec_0_NOMINAL_EleEffSF_offline_RecoTrk);
            h_mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk->Fill(mjj,weight*elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk/elec_1_NOMINAL_EleEffSF_offline_RecoTrk);
            h_mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk->Fill(mjj,weight*(elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk*elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk)/(elec_0_NOMINAL_EleEffSF_offline_RecoTrk*elec_1_NOMINAL_EleEffSF_offline_RecoTrk));
            h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Fill(mjj,weight*elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight/elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
            h_mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Fill(mjj,weight*elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight/elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
            h_mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Fill(mjj,weight*(elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight*elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight)/(elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight*elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight));
            h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Fill(mjj,weight*elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight/elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
            h_mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Fill(mjj,weight*elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight/elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
            h_mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Fill(mjj,weight*(elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight*elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight)/(elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight*elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight));
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
            #endif
        }
        if ((sum-cuts[10])==13) {
          h_n_jets_interval->Fill(n_jets_interval,weight);
        }
        if ((sum-cuts[11])==13) {
          h_Z_centrality->Fill(z_centrality,weight);
        }
        if ((sum-cuts[12])==13) {
          h_inv_mass->Fill(inv_mass,weight);
        }
      }
    }
  }

void CLoop::Style(double lumFactor) {
    #ifdef WEIGHTSYSTEMATICS
    h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13->Write();
    h_mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13->Write();
    h_mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13->Write();
    h_mass_jj_elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13->Write();
    h_mass_jj_elec_1_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13->Write();
    h_mass_jj_elec_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13->Write();
    h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Write();
    h_mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Write();
    h_mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Write();
    h_mass_jj_elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Write();
    h_mass_jj_elec_1_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Write();
    h_mass_jj_elec_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight->Write();
    h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk->Write();
    h_mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk->Write();
    h_mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk->Write();
    h_mass_jj_elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk->Write();
    h_mass_jj_elec_1_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk->Write();
    h_mass_jj_elec_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk->Write();
    h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Write();
    h_mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Write();
    h_mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Write();
    h_mass_jj_elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Write();
    h_mass_jj_elec_1_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Write();
    h_mass_jj_elec_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight->Write();
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
    #endif

    h_delta_phi->Write();
    h_delta_y->Write();
    h_n_bjets->Write();
    h_lepiso->Write();
    h_lep1_pt->Write();
    h_lep2_pt->Write();
    h_ljet0_pt->Write();
    h_ljet1_pt->Write();
    h_pt_bal->Write();
    h_mass_jj->Write();
    h_n_jets_interval->Write();
    h_Z_centrality->Write();
    h_inv_mass->Write();
}

#endif // End header guard