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
  h_lep_pt_basic = new TH1F("lep_pt_basic","Lep pT",500,0,500);
  h_lep_pt_basic_dphi = new TH1F("lep_pt_basic_dphi","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap = new TH1F("lep_pt_basic_dphi_drap","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag = new TH1F("lep_pt_basic_dphi_drap_btag","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso = new TH1F("lep_pt_basic_dphi_drap_btag_iso","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Lep pT",500,0,500);
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Lep pT",500,0,500);


  h_lepnu_pt_basic = new TH1F("lepnu_pt_basic","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi = new TH1F("lepnu_pt_basic_dphi","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap = new TH1F("lepnu_pt_basic_dphi_drap","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag = new TH1F("lepnu_pt_basic_dphi_drap_btag","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Lep + Neutrino pT",500,0,500);
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Lep + Neutrino pT",500,0,500);


  h_tau_pt_basic = new TH1F("tau_pt_basic","Tau pT",500,0,500);
  h_tau_pt_basic_dphi = new TH1F("tau_pt_basic_dphi","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap = new TH1F("tau_pt_basic_dphi_drap","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag = new TH1F("tau_pt_basic_dphi_drap_btag","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso = new TH1F("tau_pt_basic_dphi_drap_btag_iso","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Tau pT",500,0,500);
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Tau pT",500,0,500);


  h_taunu_pt_basic = new TH1F("taunu_pt_basic","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi = new TH1F("taunu_pt_basic_dphi","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap = new TH1F("taunu_pt_basic_dphi_drap","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag = new TH1F("taunu_pt_basic_dphi_drap_btag","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso = new TH1F("taunu_pt_basic_dphi_drap_btag_iso","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Tau pT",500,0,500);
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Tau pT",500,0,500);

  h_lep_eta_basic = new TH1F("lep_eta_basic","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi = new TH1F("lep_eta_basic_dphi","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap = new TH1F("lep_eta_basic_dphi_drap","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag = new TH1F("lep_eta_basic_dphi_drap_btag","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso = new TH1F("lep_eta_basic_dphi_drap_btag_iso","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Lep eta",50,-2.5,2.5);
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Lep eta",50,-2.5,2.5);


  h_tau_eta_basic = new TH1F("tau_eta_basic","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi = new TH1F("tau_eta_basic_dphi","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap = new TH1F("tau_eta_basic_dphi_drap","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag = new TH1F("tau_eta_basic_dphi_drap_btag","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso = new TH1F("tau_eta_basic_dphi_drap_btag_iso","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Tau eta",50,-2.5,2.5);
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Tau eta",50,-2.5,2.5);


  h_delta_R_taulep_basic = new TH1F("delta_R_taulep_basic","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi = new TH1F("delta_R_taulep_basic_dphi","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap = new TH1F("delta_R_taulep_basic_dphi_drap","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag = new TH1F("delta_R_taulep_basic_dphi_drap_btag","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Delta R tau-lep",60,0,6);
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Delta R tau-lep",60,0,6);


  h_delta_R_lepjet_basic = new TH1F("delta_R_lepjet_basic","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi = new TH1F("delta_R_lepjet_basic_dphi","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap = new TH1F("delta_R_lepjet_basic_dphi_drap","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag = new TH1F("delta_R_lepjet_basic_dphi_drap_btag","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Delta R lep-jet",60,0,6);
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Delta R lep-jet",60,0,6);


  h_delta_R_taujet_basic = new TH1F("delta_R_taujet_basic","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi = new TH1F("delta_R_taujet_basic_dphi","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap = new TH1F("delta_R_taujet_basic_dphi_drap","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag = new TH1F("delta_R_taujet_basic_dphi_drap_btag","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Delta R tau-jet",60,0,6);
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Delta R tau-jet",60,0,6);

  h_sum_pt_basic = new TH1F("sum_pt_basic","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi = new TH1F("sum_pt_basic_dphi","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap = new TH1F("sum_pt_basic_dphi_drap","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag = new TH1F("sum_pt_basic_dphi_drap_btag","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso = new TH1F("sum_pt_basic_dphi_drap_btag_iso","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Sum of lepton and tau pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Sum of lepton and tau pT",800,0,800);


  h_met_basic = new TH1F("met_basic","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi = new TH1F("met_basic_dphi","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap = new TH1F("met_basic_dphi_drap","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag = new TH1F("met_basic_dphi_drap_btag","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso = new TH1F("met_basic_dphi_drap_btag_iso","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn = new TH1F("met_basic_dphi_drap_btag_iso_rnn","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Missing Transverse momentum",500,0,500);


  h_reco_mass_i_basic = new TH1F("reco_mass_i_basic","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi = new TH1F("reco_mass_i_basic_dphi","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap = new TH1F("reco_mass_i_basic_dphi_drap","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag = new TH1F("reco_mass_i_basic_dphi_drap_btag","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Reconstructed mass in between events",1000,0,1000);


  h_reco_mass_o_basic = new TH1F("reco_mass_o_basic","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi = new TH1F("reco_mass_o_basic_dphi","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap = new TH1F("reco_mass_o_basic_dphi_drap","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag = new TH1F("reco_mass_o_basic_dphi_drap_btag","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Reconstructed mass outside events",1000,0,1000);


  h_omega_basic = new TH1F("omega_basic","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi = new TH1F("omega_basic_dphi","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap = new TH1F("omega_basic_dphi_drap","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag = new TH1F("omega_basic_dphi_drap_btag","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso = new TH1F("omega_basic_dphi_drap_btag_iso","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn = new TH1F("omega_basic_dphi_drap_btag_iso_rnn","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Omega variable",60,-3.0,3.0);
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Omega variable",60,-3.0,3.0);


  h_lep_phi_basic = new TH1F("lep_phi_basic","Lep phi angle",64,-3.2,3.2);
  h_lep_phi_basic_cuts = new TH1F("lep_phi_basic_cuts","Lep phi angle",64,-3.2,3.2);
  h_lep_phi_basic_cuts_tpt = new TH1F("lep_phi_basic_cuts_tpt","Lep phi angle",64,-3.2,3.2);


  h_tau_phi_basic = new TH1F("tau_phi_basic","Tau phi angle",64,-3.2,3.2);
  h_tau_phi_basic_cuts = new TH1F("tau_phi_basic_cuts","Tau phi angle",64,-3.2,3.2);
  h_tau_phi_basic_cuts_tpt = new TH1F("tau_phi_basic_cuts_tpt","Tau phi angle",64,-3.2,3.2);


  h_tau_nprongs_basic = new TH1F("tau_nprongs_basic","Tau prongness",4,0,4);
  h_tau_nprongs_basic_cuts = new TH1F("tau_nprongs_basic_cuts","Tau prongness",4,0,4);
  h_tau_nprongs_basic_cuts_tpt = new TH1F("tau_nprongs_basic_cuts_tpt","Tau prongness",4,0,4);


  h_trans_lep_mass_basic = new TH1F("trans_lep_mass_basic","Lepton transverse mass",200,0,200);
  h_trans_lep_mass_basic_cuts = new TH1F("trans_lep_mass_basic_cuts","Lepton transverse mass",200,0,200);
  h_trans_lep_mass_basic_cuts_tpt = new TH1F("trans_lep_mass_basic_cuts_tpt","Lepton transverse mass",200,0,200);


  h_rnn_score_1p_basic = new TH1F("rnn_score_1p_basic","RNN Score 1 prong taus",100,0,1);
  h_rnn_score_1p_basic_cuts = new TH1F("rnn_score_1p_basic_cuts","RNN Score 1 prong taus",100,0,1);
  h_rnn_score_1p_basic_cuts_tpt = new TH1F("rnn_score_1p_basic_cuts_tpt","RNN Score 1 prong taus",100,0,1);


  h_rnn_score_3p_basic = new TH1F("rnn_score_3p_basic","RNN Score 3 prong taus",100,0,1);
  h_rnn_score_3p_basic_cuts = new TH1F("rnn_score_3p_basic_cuts","RNN Score 3 prong taus",100,0,1);
  h_rnn_score_3p_basic_cuts_tpt = new TH1F("rnn_score_3p_basic_cuts_tpt","RNN Score 3 prong taus",100,0,1);


  h_jet_n_basic = new TH1F("jet_n_basic","Number of jets",10,0,10);
  h_jet_n_basic_cuts = new TH1F("jet_n_basic_cuts","Number of jets",10,0,10);
  h_jet_n_basic_cuts_tpt = new TH1F("jet_n_basic_cuts_tpt","Number of jets",10,0,10);


  h_n_bjets_basic = new TH1F("n_bjets_basic","Number of b_jets",5,0,5);
  h_n_bjets_basic_cuts = new TH1F("n_bjets_basic_cuts","Number of b_jets",5,0,5);
  h_n_bjets_basic_cuts_tpt = new TH1F("n_bjets_basic_cuts_tpt","Number of b_jets",5,0,5);


  h_lep_iso_basic = new TH1F("lep_iso_basic","Lep isolation flag",2,0,2);
  h_lep_iso_basic_cuts = new TH1F("lep_iso_basic_cuts","Lep isolation flag",2,0,2);
  h_lep_iso_basic_cuts_tpt = new TH1F("lep_iso_basic_cuts_tpt","Lep isolation flag",2,0,2);


  h_delta_phi_basic = new TH1F("delta_phi_basic","Delta phi between tau and lep",32,0,3.2);
  h_delta_phi_basic_cuts = new TH1F("delta_phi_basic_cuts","Delta phi between tau and lep",32,0,3.2);
  h_delta_phi_basic_cuts_tpt = new TH1F("delta_phi_basic_cuts_tpt","Delta phi between tau and lep",32,0,3.2);


  h_Z_pt_reco_i_basic = new TH1F("Z_pt_reco_i_basic","ZpT in between events",1000,0,1000);
  h_Z_pt_reco_i_basic_cuts = new TH1F("Z_pt_reco_i_basic_cuts","ZpT in between events",1000,0,1000);
  h_Z_pt_reco_i_basic_cuts_tpt = new TH1F("Z_pt_reco_i_basic_cuts_tpt","ZpT in between events",1000,0,1000);


  h_Z_pt_reco_o_basic = new TH1F("Z_pt_reco_o_basic","ZpT outside events",1000,0,1000);
  h_Z_pt_reco_o_basic_cuts = new TH1F("Z_pt_reco_o_basic_cuts","ZpT outside events",1000,0,1000);
  h_Z_pt_reco_o_basic_cuts_tpt = new TH1F("Z_pt_reco_o_basic_cuts_tpt","ZpT outside events",1000,0,1000);


  h_n_fake_tracks_basic = new TH1F("n_fake_tracks_basic","Number of fake tracks",40,0,40);
  h_n_fake_tracks_basic_cuts = new TH1F("n_fake_tracks_basic_cuts","Number of fake tracks",40,0,40);
  h_n_fake_tracks_basic_cuts_tpt = new TH1F("n_fake_tracks_basic_cuts_tpt","Number of fake tracks",40,0,40);


  h_n_core_tracks_basic = new TH1F("n_core_tracks_basic","Number of core tracks",40,0,40);
  h_n_core_tracks_basic_cuts = new TH1F("n_core_tracks_basic_cuts","Number of core tracks",40,0,40);
  h_n_core_tracks_basic_cuts_tpt = new TH1F("n_core_tracks_basic_cuts_tpt","Number of core tracks",40,0,40);


  h_n_iso_tracks_basic = new TH1F("n_iso_tracks_basic","Number of isolation tracks",40,0,40);
  h_n_iso_tracks_basic_cuts = new TH1F("n_iso_tracks_basic_cuts","Number of isolation tracks",40,0,40);
  h_n_iso_tracks_basic_cuts_tpt = new TH1F("n_iso_tracks_basic_cuts_tpt","Number of isolation tracks",40,0,40);


  h_n_tracks_basic = new TH1F("n_tracks_basic","Number of all tracks",40,0,40);
  h_n_tracks_basic_cuts = new TH1F("n_tracks_basic_cuts","Number of all tracks",40,0,40);
  h_n_tracks_basic_cuts_tpt = new TH1F("n_tracks_basic_cuts_tpt","Number of all tracks",40,0,40);


  h_delta_y_basic = new TH1F("delta_y_basic","Delta Rapidity",100,0,10);
  h_delta_y_basic_cuts = new TH1F("delta_y_basic_cuts","Delta Rapidity",100,0,10);
  h_delta_y_basic_cuts_tpt = new TH1F("delta_y_basic_cuts_tpt","Delta Rapidity",100,0,10);


  h_Z_centrality_basic = new TH1F("Z_centrality_basic","Z boson centrality",500,0,5);
  h_Z_centrality_basic_cuts = new TH1F("Z_centrality_basic_cuts","Z boson centrality",500,0,5);
  h_Z_centrality_basic_cuts_tpt = new TH1F("Z_centrality_basic_cuts_tpt","Z boson centrality",500,0,5);


  h_pt_bal_basic = new TH1F("pt_bal_basic","pT Balance",100,0,1);
  h_pt_bal_basic_cuts = new TH1F("pt_bal_basic_cuts","pT Balance",100,0,1);
  h_pt_bal_basic_cuts_tpt = new TH1F("pt_bal_basic_cuts_tpt","pT Balance",100,0,1);


  h_mass_jj_basic = new TH1F("mass_jj_basic","Invariant mass di_jet system",5000,0,5000);
  h_mass_jj_basic_cuts = new TH1F("mass_jj_basic_cuts","Invariant mass di_jet system",5000,0,5000);
  h_mass_jj_basic_cuts_tpt = new TH1F("mass_jj_basic_cuts_tpt","Invariant mass di_jet system",5000,0,5000);


  h_n_jets_interval_basic = new TH1F("n_jets_interval_basic","N jets between rapidity interval",10,0,10);
  h_n_jets_interval_basic_cuts = new TH1F("n_jets_interval_basic_cuts","N jets between rapidity interval",100,0,10);
  h_n_jets_interval_basic_cuts_tpt = new TH1F("n_jets_interval_basic_cuts_tpt","N jets between rapidity interval",10,0,10);


  h_ljet0_pt_basic = new TH1F("ljet0_pt_basic","Light jet0 pT",1000,0,1000);
  h_ljet0_pt_basic_cuts = new TH1F("ljet0_pt_basic_cuts","Light jet0 pT",1000,0,1000);
  h_ljet0_pt_basic_cuts_tpt = new TH1F("ljet0_pt_basic_cuts_tpt","Light jet0 pT",1000,0,1000);


  h_ljet1_pt_basic = new TH1F("ljet1_pt_basic","Light jet1 pT",1000,0,1000);
  h_ljet1_pt_basic_cuts = new TH1F("ljet1_pt_basic_cuts","Light jet1 pT",1000,0,1000);
  h_ljet1_pt_basic_cuts_tpt = new TH1F("ljet1_pt_basic_cuts_tpt","Light jet1 pT",1000,0,1000);


  h_ljet2_pt_basic = new TH1F("ljet2_pt_basic","Light jet2 pT",1000,0,1000);
  h_ljet2_pt_basic_cuts = new TH1F("ljet2_pt_basic_cuts","Light jet2 pT",1000,0,1000);
  h_ljet2_pt_basic_cuts_tpt = new TH1F("ljet2_pt_basic_cuts_tpt","Light jet2 pT",1000,0,1000);


  h_ljet3_pt_basic = new TH1F("ljet3_pt_basic","Light jet3 pT",1000,0,1000);
  h_ljet3_pt_basic_cuts = new TH1F("ljet3_pt_basic_cuts","Light jet3 pT",1000,0,1000);
  h_ljet3_pt_basic_cuts_tpt = new TH1F("ljet3_pt_basic_cuts_tpt","Light jet3 pT",1000,0,1000);

  h_gap_jet_pt_basic_cuts_tpt = new TH1F("gap_jet_pt_basic_cuts_tpt","Gap jet pT",1000,0,1000);

  h_ljet0_eta_basic = new TH1F("ljet0_eta_basic","Light jet0 eta",140,-7.0,7.0);
  h_ljet0_eta_basic_cuts = new TH1F("ljet0_eta_basic_cuts","Light jet0 eta",140,-7.0,7.0);
  h_ljet0_eta_basic_cuts_ptl = new TH1F("ljet0_eta_basic_cuts_ptl","Light jet0 eta",140,-7.0,7.0);


  h_ljet1_eta_basic = new TH1F("ljet1_eta_basic","Light jet1 eta",140,-7.0,7.0);
  h_ljet1_eta_basic_cuts = new TH1F("ljet1_eta_basic_cuts","Light jet1 eta",140,-7.0,7.0);
  h_ljet1_eta_basic_cuts_ptl = new TH1F("ljet1_eta_basic_cuts_ptl","Light jet1 eta",140,-7.0,7.0);


  h_ljet2_eta_basic = new TH1F("ljet2_eta_basic","Light jet2 eta",140,-7.0,7.0);
  h_ljet2_eta_basic_cuts = new TH1F("ljet2_eta_basic_cuts","Light jet2 eta",140,-7.0,7.0);
  h_ljet2_eta_basic_cuts_ptl = new TH1F("ljet2_eta_basic_cuts_ptl","Light jet2 eta",140,-7.0,7.0);


  h_gap_jet_eta_basic = new TH1F("gap_jet_eta_basic","Gap jet eta",140,-7.0,7.0);
  h_gap_jet_eta_basic_cuts = new TH1F("gap_jet_eta_basic_cuts","Gap jet eta",140,-7.0,7.0);
  h_gap_jet_eta_basic_cuts_ptl = new TH1F("gap_jet_eta_basic_cuts_ptl","Gap jet eta",140,-7.0,7.0);


  h_trans_mass_lep_basic = new TH1F("trans_mass_lep_basic","Transverse mass lepton",150,0,150);
  h_trans_mass_lep_basic_cuts = new TH1F("trans_mass_lep_basic_cuts","Transverse mass lepton",150,0,150);
  h_trans_mass_lep_basic_cuts_tpt = new TH1F("trans_mass_lep_basic_cuts_tpt","Transverse mass lepton",150,0,150);


  h_vec_sum_pt_jets_basic = new TH1F("vec_sum_pt_jets_basic","Vector sum pT tagging jets",2000,0,2000);
  h_vec_sum_pt_jets_basic_cuts = new TH1F("vec_sum_pt_jets_basic_cuts","Vector sum pT tagging jets",2000,0,2000);
  h_vec_sum_pt_jets_basic_cuts_tpt = new TH1F("vec_sum_pt_jets_basic_cuts_tpt","Vector sum pT tagging jets",2000,0,2000);


  h_ratio_zpt_sumjetpt_basic = new TH1F("ratio_zpt_sumjetpt_basic","Ratio ZpT over vector sum pT tagging jets",500,0,5);
  h_ratio_zpt_sumjetpt_basic_cuts = new TH1F("ratio_zpt_sumjetpt_basic_cuts","Ratio ZpT over vector sum pT tagging jets",500,0,5);
  h_ratio_zpt_sumjetpt_basic_cuts_tpt = new TH1F("ratio_zpt_sumjetpt_basic_cuts_tpt","Ratio ZpT over vector sum pT tagging jets",500,0,5);


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
  h_leptau_mass = new TH1F("leptau_mass","Invariant mass lepton tau system",200,0,200);
  h_eBDT = new TH1F("eBDT","eBDT Score",100,0,1);
  h_reco_mass_i = new TH1F("reco_mass_i","Reconstructed mass in between events",1000,0,1000);
  h_reco_mass_o = new TH1F("reco_mass_o","Reconstructed mass outside events",1000,0,1000);
  h_reco_mass = new TH1F("reco_mass_","Reconstructed mass all events",1000,0,1000);

  if (lumFactor!=1){
    h_tau_matched_1p_basic = new TH1F("tau_matched_1p_basic","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi = new TH1F("tau_matched_1p_basic_dphi","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap = new TH1F("tau_matched_1p_basic_dphi_drap","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag = new TH1F("tau_matched_1p_basic_dphi_drap_btag","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Tau truth matched 1 prong",2,0,2);
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Tau truth matched 1 prong",2,0,2);


    h_tau_matched_3p_basic = new TH1F("tau_matched_3p_basic","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi = new TH1F("tau_matched_3p_basic_dphi","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap = new TH1F("tau_matched_3p_basic_dphi_drap","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag = new TH1F("tau_matched_3p_basic_dphi_drap_btag","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco","Tau truth matched 3 prong",2,0,2);
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt = new TH1F("tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt","Tau truth matched 3 prong",2,0,2);

    h_Z_pt_truth_i_basic = new TH1F("Z_pt_truth_i_basic","Truth ZpT in between events",1000,0,1000);
    h_Z_pt_truth_i_basic_cuts = new TH1F("Z_pt_truth_i_basic_cuts","Truth ZpT in between events",1000,0,1000);
    h_Z_pt_truth_i_basic_cuts_tpt = new TH1F("Z_pt_truth_i_basic_cuts_tpt","Truth ZpT in between events",1000,0,1000);


    h_Z_pt_truth_o_basic = new TH1F("Z_pt_truth_o_basic","Truth ZpT outside events",1000,0,1000);
    h_Z_pt_truth_o_basic_cuts = new TH1F("Z_pt_truth_o_basic_cuts","Truth ZpT outside events",1000,0,1000);
    h_Z_pt_truth_o_basic_cuts_tpt = new TH1F("Z_pt_truth_o_basic_cuts_tpt","Truth ZpT outside events",1000,0,1000);
  }
}

void CLoop::Fill(double weight, int z_sample) {
  double pi=TMath::Pi();
  //Charges and lepton ID
  float ql=elec_0_q;
  float qtau=tau_0_q;
  bool lepton_id=elec_0_id_tight;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  if (ql==qtau && n_electrons==1 && n_taus_rnn_loose>=1 && lepton_id && n_ljets>=2 && n_ljets<=3){
    //angles
    double angle_l_MET=del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
    double angle_tau_MET=del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
    double angle=del_phi(tau_0_p4->Phi(),elec_0_p4->Phi());
    //trigger decision
    bool trigger_decision= false;
    bool trigger_match= false;
    if (run_number>= 276262 && run_number<=284484){
        trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
        trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
    } else {
        trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
        trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
    }
    // INVARIANT MASS 2-JETS
    double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
    if (mjj>=250 && trigger_decision && trigger_match) {
      //topology
      bool inside= abs(angle-(angle_l_MET+angle_tau_MET))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
      bool outside_lep= angle_l_MET<angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_l_MET)>0;
      bool outside_tau= angle_l_MET>angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_tau_MET)>0;
      bool signal_events = inside || outside_lep || outside_tau;

      if (signal_events){
        // RECO mass AND neutrino momentum
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

        // ZpT calculations
        double Z_pt_x=0;
        double Z_pt_y=0;
        double Z_pt=0;
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
        }
        if (outside_tau) {
          Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(tau_0_p4->Phi());
          Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(tau_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }
        if (outside_lep) {
          Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(elec_0_p4->Phi());
          Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(elec_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }

        // LEPTON TRANSVERSE MASS AND LEP-TAU INVARIANT MASS
        double lepmet_mass=sqrt(2*elec_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(elec_0_p4->Phi()-met_reco_p4->Phi())));
        double inv_taulep=sqrt((2*elec_0_p4->Pt()*tau_0_p4->Pt())*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi())));
        // Vector sum pT of the jets
        double jet_pt_sum= (*ljet_0_p4 + *ljet_1_p4).Pt();
        // Ratio ZpT/jet_pt_sum
        double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;


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
          TLorentzVector nu_lep_p4(pt_lep_nu*cos(elec_0_p4->Phi()),pt_lep_nu*sin(elec_0_p4->Phi()),0,0);
          if (n_jets_interval==0){
            pt_bal=(((*tau_0_p4)+(*elec_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+nu_tau_p4+nu_lep_p4)).Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+nu_tau_p4.Pt()+nu_lep_p4.Pt());
          } else {
            pt_bal=(((*tau_0_p4)+(*elec_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4)+nu_tau_p4+nu_lep_p4)).Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt()+nu_tau_p4.Pt()+nu_lep_p4.Pt());
          }


        } else {
          if (outside_lep){
            TLorentzVector nu_p4(pt_lep_nu*cos(elec_0_p4->Phi()),pt_lep_nu*sin(elec_0_p4->Phi()),0,0);
            if (n_jets_interval==0){
              pt_bal=(((*tau_0_p4)+(*elec_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+nu_p4.Pt());
            } else {
              pt_bal=(((*tau_0_p4)+(*elec_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt()+nu_p4.Pt());
            }
          } else{
            if(outside_tau){
              TLorentzVector nu_p4(pt_tau_nu*cos(tau_0_p4->Phi()),pt_tau_nu*sin(tau_0_p4->Phi()),0,0);
              if (n_jets_interval==0){
                pt_bal=(((*tau_0_p4)+(*elec_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+nu_p4.Pt());
              } else {
                pt_bal=(((*tau_0_p4)+(*elec_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4)+nu_p4)).Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt()+nu_p4.Pt());
              }
            }
          }
        }
        // Z BOSON CENTRALITY
        double lepton_xi=((*tau_0_p4)+(*elec_0_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        //pT gap jet
        double pt_gap_jet{};
        if (is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4)){pt_gap_jet=ljet_2_p4->Pt();}

        // Minimum DeltaR between lepton and jets
        std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
        std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};

        double min_dR_tau = min_deltaR(tau_0_p4,is_jet_present,jet_container);
        double min_dR_lep = min_deltaR(elec_0_p4,is_jet_present,jet_container);

        // Definition of the superCR = CR(a+b+c)
        bool CRa = z_centrality < 0.5 && n_jets_interval == 1;
        bool CRb = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 1;
        bool CRc = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 0;
        bool superCR = CRa || CRb || CRc;

        // Cuts vector
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        // CUTS
        if (angle<=3.2){cuts[0]=1;}
        if(delta_y>=2.0){cuts[1]=1;}
        if(n_bjets_MV2c10_FixedCutBEff_85==0){cuts[2]=1;}
        if(elec_0_iso_FCTight==0){cuts[3]=1;}
        if(tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans < 0.25){cuts[4]=1;}
        if(tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans < 0.40){cuts[4]=1;}
        if(elec_0_p4->Pt()>=27){cuts[5]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[6]=1;}
        if(ljet_1_p4->Pt()>=70){cuts[7]=1;}
        if(pt_bal<=0.15){cuts[8]=1;}
        if(mjj>=250){cuts[9]=1;}
        if(n_jets_interval==0){cuts[10]=1;}
        if(z_centrality<0.5){cuts[11]=1;} // SR -> z_centrality < 0.5
        if (omega> -0.2 && omega <1.6){cuts[12]=1;}
        if(inv_taulep<=80){cuts[13]=1;}
        if (tau_0_ele_bdt_score_trans_retuned>=0.05){cuts[14]=1;}
        if (inside) {
          if (reco_mass > 66 && reco_mass < 116){cuts[15]=1;} // Z-peak reco_mass<116 && reco_mass>66
        }
        if (outside_lep) {
          if (reco_mass > 66 && reco_mass < 116){cuts[15]=1;}
        }
        if (outside_tau) {
          if (reco_mass > 66 && reco_mass < 116){cuts[15]=1;}
        }
        if (tau_0_p4->Pt()>=25){cuts[16]=1;}

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        int sum{};
        for(auto &j : cuts){sum=sum+j;}

        // FILLING CUTS HISTOGRAMS
        if ((sum-cuts[0])==16) {
          h_delta_phi->Fill(angle,weight);
        }
        if ((sum-cuts[1])==16) {
          h_delta_y->Fill(delta_y,weight);
        }
        if ((sum-cuts[2])==16) {
          h_n_bjets->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        }
        if ((sum-cuts[3])==16) {
          h_lepiso->Fill(elec_0_iso_FCTight,weight);
        }
        if ((sum-cuts[4])==16) {
          if (tau_0_n_charged_tracks==1){
            h_rnn_score_1p->Fill(tau_0_jet_rnn_score_trans,weight);
          }
          if (tau_0_n_charged_tracks==3){
            h_rnn_score_3p->Fill(tau_0_jet_rnn_score_trans,weight);
          }
        }
        if ((sum-cuts[5])==16) {
          h_lep_pt->Fill(elec_0_p4->Pt(),weight);
        }
        if ((sum-cuts[6])==16) {
          h_ljet0_pt->Fill(ljet_0_p4->Pt(),weight);
        }
        if ((sum-cuts[7])==16) {
          h_ljet1_pt->Fill(ljet_1_p4->Pt(),weight);
        }
        if ((sum-cuts[8])==16) {
          h_pt_bal->Fill(pt_bal,weight);
        }
        if ((sum-cuts[9])==16) {
          h_mass_jj->Fill(mjj,weight);
        }
        if ((sum-cuts[10])==16) {
          h_n_jets_interval->Fill(n_jets_interval,weight);
          h_gap_jet_pt_basic_cuts_tpt->Fill(pt_gap_jet,weight);
        }
        if ((sum-cuts[11])==16) {
          h_Z_centrality->Fill(z_centrality,weight);
        }
        if ((sum-cuts[12])==16) {
          h_omega->Fill(omega,weight);
        }
        if ((sum-cuts[13])==16) {
          h_leptau_mass->Fill(inv_taulep,weight);
        }
        if ((sum-cuts[14])==16) {
          h_eBDT->Fill(tau_0_ele_bdt_score_trans_retuned,weight);
        }
        if (inside) {
          if ((sum-cuts[15])==16) {
            h_reco_mass_i->Fill(reco_mass,weight);
            h_reco_mass->Fill(reco_mass,weight);
          }
        }
        if (outside_lep) {
          if ((sum-cuts[15])==16) {
            h_reco_mass_o->Fill(reco_mass_outside,weight);
            h_reco_mass->Fill(reco_mass_outside,weight);
          }
        }
        if (outside_tau) {
          if ((sum-cuts[15])==16) {
            h_reco_mass_o->Fill(reco_mass_outside,weight);
            h_reco_mass->Fill(reco_mass_outside,weight);
          }
        }
        if ((sum-cuts[16])==16) {
          h_tau_pt->Fill(tau_0_p4->Pt(),weight);
        }


        // HISTOGRAM FILLING STARTING IN BASIC SELECTION
        if (weight!=1){
          if(inside){h_Z_pt_truth_i_basic->Fill(truth_z_pt,weight);}
          if(outside_lep || outside_tau){h_Z_pt_truth_o_basic->Fill(truth_z_pt,weight);}
          if (tau_0_n_charged_tracks==1){
            h_tau_matched_1p_basic->Fill(tau_0_truth_isHadTau,weight);
          }
          if (tau_0_n_charged_tracks==3){
            h_tau_matched_3p_basic->Fill(tau_0_truth_isHadTau,weight);
          }
        }

        if (inside){
          h_reco_mass_i_basic->Fill(reco_mass,weight);
          h_lepnu_pt_basic->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
          h_taunu_pt_basic->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
          h_sum_pt_basic->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
          h_Z_pt_reco_i_basic->Fill(Z_pt,weight);
        } else {
          h_reco_mass_o_basic->Fill(reco_mass_outside,weight);
          h_lepnu_pt_basic->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
          h_taunu_pt_basic->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
          h_sum_pt_basic->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
          h_Z_pt_reco_o_basic->Fill(Z_pt,weight);
        }
        if (tau_0_n_charged_tracks==1){h_rnn_score_1p_basic->Fill(tau_0_jet_rnn_score_trans,weight);}
        if (tau_0_n_charged_tracks==3){h_rnn_score_3p_basic->Fill(tau_0_jet_rnn_score_trans,weight);}

        h_lep_pt_basic->Fill(elec_0_p4->Pt(),weight);
        h_tau_pt_basic->Fill(tau_0_p4->Pt(),weight);
        h_lep_eta_basic->Fill(elec_0_p4->Eta(),weight);
        h_tau_eta_basic->Fill(tau_0_p4->Eta(),weight);
        h_delta_R_taulep_basic->Fill(tau_0_p4->DeltaR(*elec_0_p4),weight);
        h_delta_R_lepjet_basic->Fill(min_dR_lep,weight);
        h_delta_R_taujet_basic->Fill(min_dR_tau,weight);
        h_met_basic->Fill(met_reco_p4->Pt(),weight);
        h_omega_basic->Fill(omega,weight);

        h_lep_phi_basic->Fill(elec_0_p4->Phi(),weight);
        h_tau_phi_basic->Fill(tau_0_p4->Phi(),weight);
        h_tau_nprongs_basic->Fill(tau_0_n_charged_tracks,weight);
        h_trans_lep_mass_basic->Fill(lepmet_mass,weight);
        h_jet_n_basic->Fill(n_jets,weight);
        h_n_bjets_basic->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        h_lep_iso_basic->Fill(elec_0_iso_FCTight,weight);
        h_delta_phi_basic->Fill(angle,weight);
        h_n_fake_tracks_basic->Fill(tau_0_n_fake_tracks,weight);
        h_n_core_tracks_basic->Fill(tau_0_n_core_tracks,weight);
        h_n_iso_tracks_basic->Fill(tau_0_n_isolation_tracks,weight);
        h_n_tracks_basic->Fill(tau_0_n_all_tracks,weight);
        h_delta_y_basic->Fill(delta_y,weight);
        h_Z_centrality_basic->Fill(z_centrality,weight);
        h_pt_bal_basic->Fill(pt_bal,weight);
        h_mass_jj_basic->Fill(mjj,weight);
        h_n_jets_interval_basic->Fill(n_jets_interval,weight);
        h_ljet0_pt_basic->Fill(ljet_0_p4->Pt(),weight);
        h_ljet1_pt_basic->Fill(ljet_1_p4->Pt(),weight);
        h_ljet2_pt_basic->Fill(ljet_2_p4->Pt(),weight);
        h_ljet3_pt_basic->Fill(ljet_3_p4->Pt(),weight);
        h_ljet0_eta_basic->Fill(ljet_0_p4->Eta(),weight);
        h_ljet1_eta_basic->Fill(ljet_1_p4->Eta(),weight);
        h_ljet2_eta_basic->Fill(ljet_2_p4->Eta(),weight);
        h_trans_mass_lep_basic->Fill(lepmet_mass,weight);
        h_vec_sum_pt_jets_basic->Fill(jet_pt_sum,weight);
        h_ratio_zpt_sumjetpt_basic->Fill(ratio_zpt_sumjetpt,weight);

        // ANGLE CUT
        if (cuts[0]==1){
          if (weight!=1){
            if (tau_0_n_charged_tracks==1){
              h_tau_matched_1p_basic_dphi->Fill(tau_0_truth_isHadTau,weight);
            }
            if (tau_0_n_charged_tracks==3){
              h_tau_matched_3p_basic_dphi->Fill(tau_0_truth_isHadTau,weight);
            }
          }

          if (inside){
            h_reco_mass_i_basic_dphi->Fill(reco_mass,weight);
            h_lepnu_pt_basic_dphi->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
            h_taunu_pt_basic_dphi->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
            h_sum_pt_basic_dphi->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
          } else {
            h_reco_mass_o_basic_dphi->Fill(reco_mass_outside,weight);
            h_lepnu_pt_basic_dphi->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
            h_taunu_pt_basic_dphi->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
            h_sum_pt_basic_dphi->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
          }

          h_lep_pt_basic_dphi->Fill(elec_0_p4->Pt(),weight);
          h_tau_pt_basic_dphi->Fill(tau_0_p4->Pt(),weight);
          h_met_basic_dphi->Fill(met_reco_p4->Pt(),weight);
          h_omega_basic_dphi->Fill(omega,weight);

          // DELTA Y CUT
          if (cuts[1]==1) {
            if (weight!=1){
              if (tau_0_n_charged_tracks==1){
                h_tau_matched_1p_basic_dphi_drap->Fill(tau_0_truth_isHadTau,weight);
              }
              if (tau_0_n_charged_tracks==3){
                h_tau_matched_3p_basic_dphi_drap->Fill(tau_0_truth_isHadTau,weight);
              }
            }

            if (inside){
              h_reco_mass_i_basic_dphi_drap->Fill(reco_mass,weight);
              h_lepnu_pt_basic_dphi_drap->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
              h_taunu_pt_basic_dphi_drap->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
              h_sum_pt_basic_dphi_drap->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
            } else {
              h_reco_mass_o_basic_dphi_drap->Fill(reco_mass_outside,weight);
              h_lepnu_pt_basic_dphi_drap->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
              h_taunu_pt_basic_dphi_drap->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
              h_sum_pt_basic_dphi_drap->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
            }

            h_lep_pt_basic_dphi_drap->Fill(elec_0_p4->Pt(),weight);
            h_tau_pt_basic_dphi_drap->Fill(tau_0_p4->Pt(),weight);
            h_met_basic_dphi_drap->Fill(met_reco_p4->Pt(),weight);
            h_omega_basic_dphi_drap->Fill(omega,weight);
            /// B TAG CUT
            if (cuts[2]==1) {
              if (weight!=1){
                if (tau_0_n_charged_tracks==1){
                  h_tau_matched_1p_basic_dphi_drap_btag->Fill(tau_0_truth_isHadTau,weight);
                }
                if (tau_0_n_charged_tracks==3){
                  h_tau_matched_3p_basic_dphi_drap_btag->Fill(tau_0_truth_isHadTau,weight);
                }
              }

              if (inside){
                h_reco_mass_i_basic_dphi_drap_btag->Fill(reco_mass,weight);
                h_lepnu_pt_basic_dphi_drap_btag->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                h_taunu_pt_basic_dphi_drap_btag->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                h_sum_pt_basic_dphi_drap_btag->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
              } else {
                h_reco_mass_o_basic_dphi_drap_btag->Fill(reco_mass_outside,weight);
                h_lepnu_pt_basic_dphi_drap_btag->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                h_taunu_pt_basic_dphi_drap_btag->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                h_sum_pt_basic_dphi_drap_btag->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
              }

              h_lep_pt_basic_dphi_drap_btag->Fill(elec_0_p4->Pt(),weight);
              h_tau_pt_basic_dphi_drap_btag->Fill(tau_0_p4->Pt(),weight);
              h_met_basic_dphi_drap_btag->Fill(met_reco_p4->Pt(),weight);
              h_omega_basic_dphi_drap_btag->Fill(omega,weight);

              // ISOLATION CUT
              if (cuts[3]==1) {
                if (weight!=1){
                  if (tau_0_n_charged_tracks==1){
                    h_tau_matched_1p_basic_dphi_drap_btag_iso->Fill(tau_0_truth_isHadTau,weight);
                  }
                  if (tau_0_n_charged_tracks==3){
                    h_tau_matched_3p_basic_dphi_drap_btag_iso->Fill(tau_0_truth_isHadTau,weight);
                  }
                }

                if (inside){
                  h_reco_mass_i_basic_dphi_drap_btag_iso->Fill(reco_mass,weight);
                  h_lepnu_pt_basic_dphi_drap_btag_iso->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                  h_taunu_pt_basic_dphi_drap_btag_iso->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                  h_sum_pt_basic_dphi_drap_btag_iso->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                } else {
                  h_reco_mass_o_basic_dphi_drap_btag_iso->Fill(reco_mass_outside,weight);
                  h_lepnu_pt_basic_dphi_drap_btag_iso->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                  h_taunu_pt_basic_dphi_drap_btag_iso->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                  h_sum_pt_basic_dphi_drap_btag_iso->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                }

                h_lep_pt_basic_dphi_drap_btag_iso->Fill(elec_0_p4->Pt(),weight);
                h_tau_pt_basic_dphi_drap_btag_iso->Fill(tau_0_p4->Pt(),weight);
                h_met_basic_dphi_drap_btag_iso->Fill(met_reco_p4->Pt(),weight);
                h_omega_basic_dphi_drap_btag_iso->Fill(omega,weight);


                // JET RNN SCORE CUT
                if (cuts[4]==1) {
                  if (weight!=1){
                    if (tau_0_n_charged_tracks==1){
                      h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn->Fill(tau_0_truth_isHadTau,weight);
                    }
                    if (tau_0_n_charged_tracks==3){
                      h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn->Fill(tau_0_truth_isHadTau,weight);
                    }
                  }

                  if (inside){
                    h_reco_mass_i_basic_dphi_drap_btag_iso_rnn->Fill(reco_mass,weight);
                    h_lepnu_pt_basic_dphi_drap_btag_iso_rnn->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                    h_taunu_pt_basic_dphi_drap_btag_iso_rnn->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                    h_sum_pt_basic_dphi_drap_btag_iso_rnn->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                  } else {
                    h_reco_mass_o_basic_dphi_drap_btag_iso_rnn->Fill(reco_mass_outside,weight);
                    h_lepnu_pt_basic_dphi_drap_btag_iso_rnn->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                    h_taunu_pt_basic_dphi_drap_btag_iso_rnn->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                    h_sum_pt_basic_dphi_drap_btag_iso_rnn->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                  }

                  h_lep_pt_basic_dphi_drap_btag_iso_rnn->Fill(elec_0_p4->Pt(),weight);
                  h_tau_pt_basic_dphi_drap_btag_iso_rnn->Fill(tau_0_p4->Pt(),weight);
                  h_met_basic_dphi_drap_btag_iso_rnn->Fill(met_reco_p4->Pt(),weight);
                  h_omega_basic_dphi_drap_btag_iso_rnn->Fill(omega,weight);


                    // LEPTON PT CUT
                  if (cuts[5]==1) {
                    if (weight!=1){
                      if (tau_0_n_charged_tracks==1){
                        h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl->Fill(tau_0_truth_isHadTau,weight);
                      }
                      if (tau_0_n_charged_tracks==3){
                        h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl->Fill(tau_0_truth_isHadTau,weight);
                      }
                    }

                    if (inside){
                      h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl->Fill(reco_mass,weight);
                      h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                      h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                      h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                    } else {
                      h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl->Fill(reco_mass_outside,weight);
                      h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                      h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                      h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                    }

                    h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(elec_0_p4->Pt(),weight);
                    h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl->Fill(tau_0_p4->Pt(),weight);
                    h_met_basic_dphi_drap_btag_iso_rnn_ptl->Fill(met_reco_p4->Pt(),weight);
                    h_omega_basic_dphi_drap_btag_iso_rnn_ptl->Fill(omega,weight);


                      // JET 1 PT CUT
                    if (cuts[6]==1) {
                      if (weight!=1){
                        if (tau_0_n_charged_tracks==1){
                          h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(tau_0_truth_isHadTau,weight);
                        }
                        if (tau_0_n_charged_tracks==3){
                          h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(tau_0_truth_isHadTau,weight);
                        }
                      }

                      if (inside){
                        h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(reco_mass,weight);
                        h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                        h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                        h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                      } else {
                        h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(reco_mass_outside,weight);
                        h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                        h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                        h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                      }

                      h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(elec_0_p4->Pt(),weight);
                      h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(tau_0_p4->Pt(),weight);
                      h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(met_reco_p4->Pt(),weight);
                      h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Fill(omega,weight);

                      // JET 2 PT CUT
                      if(cuts[7]==1){
                        if (weight!=1){
                          if (tau_0_n_charged_tracks==1){
                            h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(tau_0_truth_isHadTau,weight);
                          }
                          if (tau_0_n_charged_tracks==3){
                            h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(tau_0_truth_isHadTau,weight);
                          }
                        }

                        if (inside){
                          h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(reco_mass,weight);
                          h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                          h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                          h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                        } else {
                          h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(reco_mass_outside,weight);
                          h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                          h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                          h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                        }

                        h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(elec_0_p4->Pt(),weight);
                        h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(tau_0_p4->Pt(),weight);
                        h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(met_reco_p4->Pt(),weight);
                        h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Fill(omega,weight);

                        // PT BALANCE CUT
                        if(cuts[8]==1){
                          if (weight!=1){
                            if (tau_0_n_charged_tracks==1){
                              h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(tau_0_truth_isHadTau,weight);
                            }
                            if (tau_0_n_charged_tracks==3){
                              h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(tau_0_truth_isHadTau,weight);
                            }
                          }

                          if (inside){
                            h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(reco_mass,weight);
                            h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                            h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                            h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                          } else {
                            h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(reco_mass_outside,weight);
                            h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                            h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                            h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                          }

                          h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(elec_0_p4->Pt(),weight);
                          h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(tau_0_p4->Pt(),weight);
                          h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(met_reco_p4->Pt(),weight);
                          h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Fill(omega,weight);

                          // INVARIANT MASS DI-JET SYSTEM CUT
                          if(cuts[9]==1){
                            if (weight!=1){
                              if (tau_0_n_charged_tracks==1){
                                h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(tau_0_truth_isHadTau,weight);
                              }
                              if (tau_0_n_charged_tracks==3){
                                h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(tau_0_truth_isHadTau,weight);
                              }
                            }

                            if (inside){
                              h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(reco_mass,weight);
                              h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                              h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                              h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                            } else {
                              h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(reco_mass_outside,weight);
                              h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                              h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                              h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                            }

                            h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(elec_0_p4->Pt(),weight);
                            h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(tau_0_p4->Pt(),weight);
                            h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(met_reco_p4->Pt(),weight);
                            h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Fill(omega,weight);

                            // N JETS IN BETWEEN CUT
                            if(cuts[10]==1){
                              if (weight!=1){
                                if (tau_0_n_charged_tracks==1){
                                  h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(tau_0_truth_isHadTau,weight);
                                }
                                if (tau_0_n_charged_tracks==3){
                                  h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(tau_0_truth_isHadTau,weight);
                                }
                              }

                              if (inside){
                                h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(reco_mass,weight);
                                h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                              } else {
                                h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(reco_mass_outside,weight);
                                h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                              }

                              h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(elec_0_p4->Pt(),weight);
                              h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(tau_0_p4->Pt(),weight);
                              h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(met_reco_p4->Pt(),weight);
                              h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Fill(omega,weight);

                              // Z CENTRALITY CUT
                              if(cuts[11]==1){
                                if (weight!=1){
                                  if (tau_0_n_charged_tracks==1){
                                    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(tau_0_truth_isHadTau,weight);
                                  }
                                  if (tau_0_n_charged_tracks==3){
                                    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(tau_0_truth_isHadTau,weight);
                                  }
                                }

                                if (inside){
                                  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(reco_mass,weight);
                                  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                                } else {
                                  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(reco_mass_outside,weight);
                                  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                                }

                                h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(elec_0_p4->Pt(),weight);
                                h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(tau_0_p4->Pt(),weight);
                                h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(met_reco_p4->Pt(),weight);
                                h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(omega,weight);

                                // OMEGA CUT
                                if(cuts[12]==1){
                                  if (weight!=1){
                                    if (tau_0_n_charged_tracks==1){
                                      h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(tau_0_truth_isHadTau,weight);
                                    }
                                    if (tau_0_n_charged_tracks==3){
                                      h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(tau_0_truth_isHadTau,weight);
                                    }
                                  }

                                  if (inside){
                                    h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(reco_mass,weight);
                                    h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                    h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                    h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                                  } else {
                                    h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(reco_mass_outside,weight);
                                    h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                    h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                    h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                                  }

                                  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(elec_0_p4->Pt(),weight);
                                  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(tau_0_p4->Pt(),weight);
                                  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(met_reco_p4->Pt(),weight);
                                  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Fill(omega,weight);

                                  // TAU LEP INVARIANT MASS CUT
                                  if(cuts[13]==1){
                                    if (weight!=1){
                                      if (tau_0_n_charged_tracks==1){
                                        h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(tau_0_truth_isHadTau,weight);
                                      }
                                      if (tau_0_n_charged_tracks==3){
                                        h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(tau_0_truth_isHadTau,weight);
                                      }
                                    }

                                    if (inside){
                                      h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(reco_mass,weight);
                                      h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                      h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                      h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                                    } else {
                                      h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(reco_mass_outside,weight);
                                      h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                      h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                      h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                                    }

                                    h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(elec_0_p4->Pt(),weight);
                                    h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(tau_0_p4->Pt(),weight);
                                    h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(met_reco_p4->Pt(),weight);
                                    h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Fill(omega,weight);


                                    // eBDT SCORE CUT
                                    if(cuts[14]==1){
                                      if (weight!=1){
                                        if (tau_0_n_charged_tracks==1){
                                          h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_truth_isHadTau,weight);
                                        }
                                        if (tau_0_n_charged_tracks==3){
                                          h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_truth_isHadTau,weight);
                                        }
                                      }

                                      if (inside){
                                        h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(reco_mass,weight);
                                        h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                        h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                        h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                                      } else {
                                        h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(reco_mass_outside,weight);
                                        h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                        h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                        h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                                      }

                                      h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(elec_0_p4->Pt(),weight);
                                      h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_p4->Pt(),weight);
                                      h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(elec_0_p4->Eta(),weight);
                                      h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_p4->Eta(),weight);
                                      h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(tau_0_p4->DeltaR(*elec_0_p4),weight);
                                      h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(min_dR_lep,weight);
                                      h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(min_dR_tau,weight);
                                      h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(met_reco_p4->Pt(),weight);
                                      h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Fill(omega,weight);

                                      // INVARIANT MASS TAU LEP CUT
                                      if(cuts[15]==1){
                                        if (weight!=1){
                                          if(inside){h_Z_pt_truth_i_basic_cuts->Fill(truth_z_pt,weight);}
                                          if(outside_lep || outside_tau){h_Z_pt_truth_o_basic_cuts->Fill(truth_z_pt,weight);}
                                          if (tau_0_n_charged_tracks==1){
                                            h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_truth_isHadTau,weight);
                                          }
                                          if (tau_0_n_charged_tracks==3){
                                            h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_truth_isHadTau,weight);
                                          }
                                        }

                                        if (inside){
                                          h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(reco_mass,weight);
                                          h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                          h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                          h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                                          h_Z_pt_reco_i_basic_cuts->Fill(Z_pt,weight);
                                        } else {
                                          h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(reco_mass_outside,weight);
                                          h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                          h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                          h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                                          h_Z_pt_reco_o_basic_cuts->Fill(Z_pt,weight);
                                        }
                                        if (tau_0_n_charged_tracks==1){h_rnn_score_1p_basic_cuts->Fill(tau_0_jet_rnn_score_trans,weight);}
                                        if (tau_0_n_charged_tracks==3){h_rnn_score_3p_basic_cuts->Fill(tau_0_jet_rnn_score_trans,weight);}

                                        h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(elec_0_p4->Pt(),weight);
                                        h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_p4->Pt(),weight);
                                        h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(elec_0_p4->Eta(),weight);
                                        h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_p4->Eta(),weight);
                                        h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(tau_0_p4->DeltaR(*elec_0_p4),weight);
                                        h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(min_dR_lep,weight);
                                        h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(min_dR_tau,weight);
                                        h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(met_reco_p4->Pt(),weight);
                                        h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Fill(omega,weight);

                                        h_lep_phi_basic_cuts->Fill(elec_0_p4->Phi(),weight);
                                        h_tau_phi_basic_cuts->Fill(tau_0_p4->Phi(),weight);
                                        h_tau_nprongs_basic_cuts->Fill(tau_0_n_charged_tracks,weight);
                                        h_trans_lep_mass_basic_cuts->Fill(lepmet_mass,weight);
                                        h_jet_n_basic_cuts->Fill(n_jets,weight);
                                        h_n_bjets_basic_cuts->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
                                        h_lep_iso_basic_cuts->Fill(elec_0_iso_FCTight,weight);
                                        h_delta_phi_basic_cuts->Fill(angle,weight);
                                        h_n_fake_tracks_basic_cuts->Fill(tau_0_n_fake_tracks,weight);
                                        h_n_core_tracks_basic_cuts->Fill(tau_0_n_core_tracks,weight);
                                        h_n_iso_tracks_basic_cuts->Fill(tau_0_n_isolation_tracks,weight);
                                        h_n_tracks_basic_cuts->Fill(tau_0_n_all_tracks,weight);
                                        h_delta_y_basic_cuts->Fill(delta_y,weight);
                                        h_Z_centrality_basic_cuts->Fill(z_centrality,weight);
                                        h_pt_bal_basic_cuts->Fill(pt_bal,weight);
                                        h_mass_jj_basic_cuts->Fill(mjj,weight);
                                        h_n_jets_interval_basic_cuts->Fill(n_jets_interval,weight);
                                        h_ljet0_pt_basic_cuts->Fill(ljet_0_p4->Pt(),weight);
                                        h_ljet1_pt_basic_cuts->Fill(ljet_1_p4->Pt(),weight);
                                        h_ljet2_pt_basic_cuts->Fill(ljet_2_p4->Pt(),weight);
                                        h_ljet3_pt_basic_cuts->Fill(ljet_3_p4->Pt(),weight);
                                        h_ljet0_eta_basic_cuts->Fill(ljet_0_p4->Eta(),weight);
                                        h_ljet1_eta_basic_cuts->Fill(ljet_1_p4->Eta(),weight);
                                        h_ljet2_eta_basic_cuts->Fill(ljet_2_p4->Eta(),weight);
                                        h_trans_mass_lep_basic_cuts->Fill(lepmet_mass,weight);
                                        h_vec_sum_pt_jets_basic_cuts->Fill(jet_pt_sum,weight);
                                        h_ratio_zpt_sumjetpt_basic_cuts->Fill(ratio_zpt_sumjetpt,weight);

                                        // TAU PT CUT
                                        if(cuts[16]==1){
                                          if (weight!=1){
                                            if(inside){h_Z_pt_truth_i_basic_cuts_tpt->Fill(truth_z_pt,weight);}
                                            if(outside_lep || outside_tau){h_Z_pt_truth_o_basic_cuts_tpt->Fill(truth_z_pt,weight);}
                                            if (tau_0_n_charged_tracks==1){
                                              h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                                            }
                                            if (tau_0_n_charged_tracks==3){
                                              h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                                            }
                                          }

                                          if (inside){
                                            h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(reco_mass,weight);
                                            h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(elec_0_p4->Pt()+pt_lep_nu,weight);
                                            h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_p4->Pt()+pt_tau_nu,weight);
                                            h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight);
                                            h_Z_pt_reco_i_basic_cuts_tpt->Fill(Z_pt,weight);
                                          } else {
                                            h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(reco_mass_outside,weight);
                                            h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(elec_0_p4->Pt()+neutrino_pt,weight);
                                            h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_p4->Pt()+neutrino_pt,weight);
                                            h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight);
                                            h_Z_pt_reco_o_basic_cuts_tpt->Fill(Z_pt,weight);
                                          }
                                          if (tau_0_n_charged_tracks==1){h_rnn_score_1p_basic_cuts_tpt->Fill(tau_0_jet_rnn_score_trans,weight);}
                                          if (tau_0_n_charged_tracks==3){h_rnn_score_3p_basic_cuts_tpt->Fill(tau_0_jet_rnn_score_trans,weight);}

                                          h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(elec_0_p4->Pt(),weight);
                                          h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_p4->Pt(),weight);
                                          h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(elec_0_p4->Eta(),weight);
                                          h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_p4->Eta(),weight);
                                          h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(tau_0_p4->DeltaR(*elec_0_p4),weight);
                                          h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(min_dR_lep,weight);
                                          h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(min_dR_tau,weight);
                                          h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(met_reco_p4->Pt(),weight);
                                          h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Fill(omega,weight);

                                          h_lep_phi_basic_cuts_tpt->Fill(elec_0_p4->Phi(),weight);
                                          h_tau_phi_basic_cuts_tpt->Fill(tau_0_p4->Phi(),weight);
                                          h_tau_nprongs_basic_cuts_tpt->Fill(tau_0_n_charged_tracks,weight);
                                          h_trans_lep_mass_basic_cuts_tpt->Fill(lepmet_mass,weight);
                                          h_jet_n_basic_cuts_tpt->Fill(n_jets,weight);
                                          h_n_bjets_basic_cuts_tpt->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
                                          h_lep_iso_basic_cuts_tpt->Fill(elec_0_iso_FCTight,weight);
                                          h_delta_phi_basic_cuts_tpt->Fill(angle,weight);
                                          h_n_fake_tracks_basic_cuts_tpt->Fill(tau_0_n_fake_tracks,weight);
                                          h_n_core_tracks_basic_cuts_tpt->Fill(tau_0_n_core_tracks,weight);
                                          h_n_iso_tracks_basic_cuts_tpt->Fill(tau_0_n_isolation_tracks,weight);
                                          h_n_tracks_basic_cuts_tpt->Fill(tau_0_n_all_tracks,weight);
                                          h_delta_y_basic_cuts_tpt->Fill(delta_y,weight);
                                          h_Z_centrality_basic_cuts_tpt->Fill(z_centrality,weight);
                                          h_pt_bal_basic_cuts_tpt->Fill(pt_bal,weight);
                                          h_mass_jj_basic_cuts_tpt->Fill(mjj,weight);
                                          h_n_jets_interval_basic_cuts_tpt->Fill(n_jets_interval,weight);
                                          h_ljet0_pt_basic_cuts_tpt->Fill(ljet_0_p4->Pt(),weight);
                                          h_ljet1_pt_basic_cuts_tpt->Fill(ljet_1_p4->Pt(),weight);
                                          h_ljet2_pt_basic_cuts_tpt->Fill(ljet_2_p4->Pt(),weight);
                                          h_ljet3_pt_basic_cuts_tpt->Fill(ljet_3_p4->Pt(),weight);
                                          h_ljet0_eta_basic_cuts_ptl->Fill(ljet_0_p4->Eta(),weight);
                                          h_ljet1_eta_basic_cuts_ptl->Fill(ljet_1_p4->Eta(),weight);
                                          h_ljet2_eta_basic_cuts_ptl->Fill(ljet_2_p4->Eta(),weight);
                                          h_trans_mass_lep_basic_cuts_tpt->Fill(lepmet_mass,weight);
                                          h_vec_sum_pt_jets_basic_cuts_tpt->Fill(jet_pt_sum,weight);
                                          h_ratio_zpt_sumjetpt_basic_cuts_tpt->Fill(ratio_zpt_sumjetpt,weight);
                                        }
                                      }
                                    }
                                  }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
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
  h_lep_pt_basic->Write();
  h_lep_pt_basic_dphi->Write();
  h_lep_pt_basic_dphi_drap->Write();
  h_lep_pt_basic_dphi_drap_btag->Write();
  h_lep_pt_basic_dphi_drap_btag_iso->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_lep_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_lepnu_pt_basic->Write();
  h_lepnu_pt_basic_dphi->Write();
  h_lepnu_pt_basic_dphi_drap->Write();
  h_lepnu_pt_basic_dphi_drap_btag->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_lepnu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_tau_pt_basic->Write();
  h_tau_pt_basic_dphi->Write();
  h_tau_pt_basic_dphi_drap->Write();
  h_tau_pt_basic_dphi_drap_btag->Write();
  h_tau_pt_basic_dphi_drap_btag_iso->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_tau_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_taunu_pt_basic->Write();
  h_taunu_pt_basic_dphi->Write();
  h_taunu_pt_basic_dphi_drap->Write();
  h_taunu_pt_basic_dphi_drap_btag->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_taunu_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_lep_eta_basic->Write();
  h_lep_eta_basic_dphi->Write();
  h_lep_eta_basic_dphi_drap->Write();
  h_lep_eta_basic_dphi_drap_btag->Write();
  h_lep_eta_basic_dphi_drap_btag_iso->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_lep_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_tau_eta_basic->Write();
  h_tau_eta_basic_dphi->Write();
  h_tau_eta_basic_dphi_drap->Write();
  h_tau_eta_basic_dphi_drap_btag->Write();
  h_tau_eta_basic_dphi_drap_btag_iso->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_tau_eta_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_delta_R_taulep_basic->Write();
  h_delta_R_taulep_basic_dphi->Write();
  h_delta_R_taulep_basic_dphi_drap->Write();
  h_delta_R_taulep_basic_dphi_drap_btag->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_delta_R_taulep_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_delta_R_lepjet_basic->Write();
  h_delta_R_lepjet_basic_dphi->Write();
  h_delta_R_lepjet_basic_dphi_drap->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_delta_R_lepjet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_delta_R_taujet_basic->Write();
  h_delta_R_taujet_basic_dphi->Write();
  h_delta_R_taujet_basic_dphi_drap->Write();
  h_delta_R_taujet_basic_dphi_drap_btag->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_delta_R_taujet_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_sum_pt_basic->Write();
  h_sum_pt_basic_dphi->Write();
  h_sum_pt_basic_dphi_drap->Write();
  h_sum_pt_basic_dphi_drap_btag->Write();
  h_sum_pt_basic_dphi_drap_btag_iso->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_met_basic->Write();
  h_met_basic_dphi->Write();
  h_met_basic_dphi_drap->Write();
  h_met_basic_dphi_drap_btag->Write();
  h_met_basic_dphi_drap_btag_iso->Write();
  h_met_basic_dphi_drap_btag_iso_rnn->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_met_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_reco_mass_i_basic->Write();
  h_reco_mass_i_basic_dphi->Write();
  h_reco_mass_i_basic_dphi_drap->Write();
  h_reco_mass_i_basic_dphi_drap_btag->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_reco_mass_i_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_reco_mass_o_basic->Write();
  h_reco_mass_o_basic_dphi->Write();
  h_reco_mass_o_basic_dphi_drap->Write();
  h_reco_mass_o_basic_dphi_drap_btag->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_reco_mass_o_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();



  h_omega_basic->Write();
  h_omega_basic_dphi->Write();
  h_omega_basic_dphi_drap->Write();
  h_omega_basic_dphi_drap_btag->Write();
  h_omega_basic_dphi_drap_btag_iso->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
  h_omega_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


  h_lep_phi_basic->Write();
  h_lep_phi_basic_cuts->Write();
  h_lep_phi_basic_cuts_tpt->Write();


  h_tau_phi_basic->Write();
  h_tau_phi_basic_cuts->Write();
  h_tau_phi_basic_cuts_tpt->Write();


  h_tau_nprongs_basic->Write();
  h_tau_nprongs_basic_cuts->Write();
  h_tau_nprongs_basic_cuts_tpt->Write();


  h_trans_lep_mass_basic->Write();
  h_trans_lep_mass_basic_cuts->Write();
  h_trans_lep_mass_basic_cuts_tpt->Write();


  h_rnn_score_1p_basic->Write();
  h_rnn_score_1p_basic_cuts->Write();
  h_rnn_score_1p_basic_cuts_tpt->Write();


  h_rnn_score_3p_basic->Write();
  h_rnn_score_3p_basic_cuts->Write();
  h_rnn_score_3p_basic_cuts_tpt->Write();


  h_jet_n_basic->Write();
  h_jet_n_basic_cuts->Write();
  h_jet_n_basic_cuts_tpt->Write();


  h_n_bjets_basic->Write();
  h_n_bjets_basic_cuts->Write();
  h_n_bjets_basic_cuts_tpt->Write();


  h_lep_iso_basic->Write();
  h_lep_iso_basic_cuts->Write();
  h_lep_iso_basic_cuts_tpt->Write();


  h_delta_phi_basic->Write();
  h_delta_phi_basic_cuts->Write();
  h_delta_phi_basic_cuts_tpt->Write();


  h_Z_pt_reco_i_basic->Write();
  h_Z_pt_reco_i_basic_cuts->Write();
  h_Z_pt_reco_i_basic_cuts_tpt->Write();


  h_Z_pt_reco_o_basic->Write();
  h_Z_pt_reco_o_basic_cuts->Write();
  h_Z_pt_reco_o_basic_cuts_tpt->Write();


  h_n_fake_tracks_basic->Write();
  h_n_fake_tracks_basic_cuts->Write();
  h_n_fake_tracks_basic_cuts_tpt->Write();


  h_n_core_tracks_basic->Write();
  h_n_core_tracks_basic_cuts->Write();
  h_n_core_tracks_basic_cuts_tpt->Write();


  h_n_iso_tracks_basic->Write();
  h_n_iso_tracks_basic_cuts->Write();
  h_n_iso_tracks_basic_cuts_tpt->Write();


  h_n_tracks_basic->Write();
  h_n_tracks_basic_cuts->Write();
  h_n_tracks_basic_cuts_tpt->Write();


  h_delta_y_basic->Write();
  h_delta_y_basic_cuts->Write();
  h_delta_y_basic_cuts_tpt->Write();


  h_Z_centrality_basic->Write();
  h_Z_centrality_basic_cuts->Write();
  h_Z_centrality_basic_cuts_tpt->Write();


  h_pt_bal_basic->Write();
  h_pt_bal_basic_cuts->Write();
  h_pt_bal_basic_cuts_tpt->Write();


  h_mass_jj_basic->Write();
  h_mass_jj_basic_cuts->Write();
  h_mass_jj_basic_cuts_tpt->Write();


  h_n_jets_interval_basic->Write();
  h_n_jets_interval_basic_cuts->Write();
  h_n_jets_interval_basic_cuts_tpt->Write();


  h_ljet0_pt_basic->Write();
  h_ljet0_pt_basic_cuts->Write();
  h_ljet0_pt_basic_cuts_tpt->Write();


  h_ljet1_pt_basic->Write();
  h_ljet1_pt_basic_cuts->Write();
  h_ljet1_pt_basic_cuts_tpt->Write();


  h_ljet2_pt_basic->Write();
  h_ljet2_pt_basic_cuts->Write();
  h_ljet2_pt_basic_cuts_tpt->Write();


  h_ljet3_pt_basic->Write();
  h_ljet3_pt_basic_cuts->Write();
  h_ljet3_pt_basic_cuts_tpt->Write();

  h_gap_jet_pt_basic_cuts_tpt->Write();

  h_ljet0_eta_basic->Write();
  h_ljet0_eta_basic_cuts->Write();
  h_ljet0_eta_basic_cuts_ptl->Write();


  h_ljet1_eta_basic->Write();
  h_ljet1_eta_basic_cuts->Write();
  h_ljet1_eta_basic_cuts_ptl->Write();


  h_ljet2_eta_basic->Write();
  h_ljet2_eta_basic_cuts->Write();
  h_ljet2_eta_basic_cuts_ptl->Write();


  h_gap_jet_eta_basic->Write();
  h_gap_jet_eta_basic_cuts->Write();
  h_gap_jet_eta_basic_cuts_ptl->Write();

  h_trans_mass_lep_basic->Write();
  h_trans_mass_lep_basic_cuts->Write();
  h_trans_mass_lep_basic_cuts_tpt->Write();


  h_vec_sum_pt_jets_basic->Write();
  h_vec_sum_pt_jets_basic_cuts->Write();
  h_vec_sum_pt_jets_basic_cuts_tpt->Write();


  h_ratio_zpt_sumjetpt_basic->Write();
  h_ratio_zpt_sumjetpt_basic_cuts->Write();
  h_ratio_zpt_sumjetpt_basic_cuts_tpt->Write();

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
  h_leptau_mass->Write();
  h_eBDT->Write();
  h_reco_mass_i->Write();
  h_reco_mass_o->Write();
  h_reco_mass->Write();
  h_tau_pt->Write();

  if (lumFactor!=1){
    h_tau_matched_1p_basic->Write();
    h_tau_matched_1p_basic_dphi->Write();
    h_tau_matched_1p_basic_dphi_drap->Write();
    h_tau_matched_1p_basic_dphi_drap_btag->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
    h_tau_matched_1p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();


    h_tau_matched_3p_basic->Write();
    h_tau_matched_3p_basic_dphi->Write();
    h_tau_matched_3p_basic_dphi_drap->Write();
    h_tau_matched_3p_basic_dphi_drap_btag->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco->Write();
    h_tau_matched_3p_basic_dphi_drap_btag_iso_rnn_ptl_j1pt_j2pt_ptbal_mjj_nji_zcen_omega_mlt_ebdt_mreco_tpt->Write();

    h_Z_pt_truth_i_basic->Write();
    h_Z_pt_truth_i_basic_cuts->Write();
    h_Z_pt_truth_i_basic_cuts_tpt->Write();


    h_Z_pt_truth_o_basic->Write();
    h_Z_pt_truth_o_basic_cuts->Write();
    h_Z_pt_truth_o_basic_cuts_tpt->Write();
  }
}


#endif // End header guard
