// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include <stdlib.h>
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

bool CLoop::DeltaR(TLorentzVector * lep ,int n_jets, double delta_R){
  if(n_jets==0){ return true;}
  else if (n_jets==1){return (lep->DeltaR(*ljet_0_p4)>0.4);}
  else if (n_jets==2){return (lep->DeltaR(*ljet_0_p4)>0.4) && (lep->DeltaR(*ljet_1_p4)>0.4);}
  else if (n_jets>=3){return (lep->DeltaR(*ljet_0_p4)>0.4) && (lep->DeltaR(*ljet_1_p4)>0.4) && (lep->DeltaR(*ljet_2_p4)>0.4);}
  return 0;
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
  double pi = TMath::Pi();
  h_lep1_pt_basic = new TH1F("lep1_pt_basic","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi = new TH1F("lep1_pt_basic_dphi","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap = new TH1F("lep1_pt_basic_dphi_drap","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag = new TH1F("lep1_pt_basic_dphi_drap_btag","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso = new TH1F("lep1_pt_basic_dphi_drap_btag_iso","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1 = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Lep 1 pT",500,0,500);
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Lep 1 pT",500,0,500);


  h_lep2_pt_basic = new TH1F("lep2_pt_basic","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi = new TH1F("lep2_pt_basic_dphi","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap = new TH1F("lep2_pt_basic_dphi_drap","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag = new TH1F("lep2_pt_basic_dphi_drap_btag","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso = new TH1F("lep2_pt_basic_dphi_drap_btag_iso","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1 = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Lep 2 pT",500,0,500);
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Lep 2 pT",500,0,500);

  h_lep1_eta_basic = new TH1F("lep1_eta_basic","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi = new TH1F("lep1_eta_basic_dphi","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap = new TH1F("lep1_eta_basic_dphi_drap","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag = new TH1F("lep1_eta_basic_dphi_drap_btag","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso = new TH1F("lep1_eta_basic_dphi_drap_btag_iso","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1 = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Lep 1 eta",50,-2.5,2.5);
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Lep 1 eta",50,-2.5,2.5);


  h_lep2_eta_basic = new TH1F("lep2_eta_basic","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi = new TH1F("lep2_eta_basic_dphi","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap = new TH1F("lep2_eta_basic_dphi_drap","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag = new TH1F("lep2_eta_basic_dphi_drap_btag","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso = new TH1F("lep2_eta_basic_dphi_drap_btag_iso","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1 = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Lep 2 eta",50,-2.5,2.5);
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Lep 2 eta",50,-2.5,2.5);


  h_delta_R_leplep_basic = new TH1F("delta_R_leplep_basic","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi = new TH1F("delta_R_leplep_basic_dphi","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap = new TH1F("delta_R_leplep_basic_dphi_drap","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag = new TH1F("delta_R_leplep_basic_dphi_drap_btag","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1 = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Delta R lep-lep",60,0,6);
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Delta R lep-lep",60,0,6);


  h_delta_R_lep1jet_basic = new TH1F("delta_R_lep1jet_basic","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi = new TH1F("delta_R_lep1jet_basic_dphi","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap = new TH1F("delta_R_lep1jet_basic_dphi_drap","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1 = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Delta R lep1-jet",60,0,6);
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Delta R lep1-jet",60,0,6);


  h_delta_R_lep2jet_basic = new TH1F("delta_R_lep2jet_basic","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi = new TH1F("delta_R_lep2jet_basic_dphi","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap = new TH1F("delta_R_lep2jet_basic_dphi_drap","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1 = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Delta R lep2-jet",60,0,6);
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Delta R lep2-jet",60,0,6);


  h_sum_pt_basic = new TH1F("sum_pt_basic","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi = new TH1F("sum_pt_basic_dphi","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap = new TH1F("sum_pt_basic_dphi_drap","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag = new TH1F("sum_pt_basic_dphi_drap_btag","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso = new TH1F("sum_pt_basic_dphi_drap_btag_iso","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1 = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Sum of leptons pT",800,0,800);
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Sum of leptons pT",800,0,800);


  h_met_basic = new TH1F("met_basic","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi = new TH1F("met_basic_dphi","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap = new TH1F("met_basic_dphi_drap","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag = new TH1F("met_basic_dphi_drap_btag","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso = new TH1F("met_basic_dphi_drap_btag_iso","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1 = new TH1F("met_basic_dphi_drap_btag_iso_pt1","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Missing Transverse momentum",500,0,500);
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Missing Transverse momentum",500,0,500);


  h_inv_mass_basic = new TH1F("inv_mass_basic","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi = new TH1F("inv_mass_basic_dphi","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap = new TH1F("inv_mass_basic_dphi_drap","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag = new TH1F("inv_mass_basic_dphi_drap_btag","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso = new TH1F("inv_mass_basic_dphi_drap_btag_iso","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1 = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2 = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass","Invariant mass di-lepton system",240,0,240);
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl = new TH1F("inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl","Invariant mass di-lepton system",240,0,240);


  h_lep1_phi_basic = new TH1F("lep1_phi_basic","Lep 1 phi angle",64,-3.2,3.2);
  h_lep1_phi_basic_cuts = new TH1F("lep1_phi_basic_cuts","Lep 1 phi angle",64,-3.2,3.2);
  h_lep1_phi_basic_cuts_ptl = new TH1F("lep1_phi_basic_cuts_ptl","Lep 1 phi angle",64,-3.2,3.2);


  h_lep2_phi_basic = new TH1F("lep2_phi_basic","Lep 2 phi angle",64,-3.2,3.2);
  h_lep2_phi_basic_cuts = new TH1F("lep2_phi_basic_cuts","Lep 2 phi angle",64,-3.2,3.2);
  h_lep2_phi_basic_cuts_ptl = new TH1F("lep2_phi_basic_cuts_ptl","Lep 2 phi angle",64,-3.2,3.2);


  h_jet_n_basic = new TH1F("jet_n_basic","Number of jets",10,0,10);
  h_jet_n_basic_cuts = new TH1F("jet_n_basic_cuts","Number of jets",10,0,10);
  h_jet_n_basic_cuts_ptl = new TH1F("jet_n_basic_cuts_ptl","Number of jets",10,0,10);


  h_n_bjets_basic = new TH1F("n_bjets_basic","Number of b_jets",5,0,5);
  h_n_bjets_basic_cuts = new TH1F("n_bjets_basic_cuts","Number of b_jets",5,0,5);
  h_n_bjets_basic_cuts_ptl = new TH1F("n_bjets_basic_cuts_ptl","Number of b_jets",5,0,5);


  h_lep_iso_basic = new TH1F("lep_iso_basic","Lep 1,2 isolation flag",2,0,2);
  h_lep_iso_basic_cuts = new TH1F("lep_iso_basic_cuts","Lep 1,2 isolation flag",2,0,2);
  h_lep_iso_basic_cuts_ptl = new TH1F("lep_iso_basic_cuts_ptl","Lep 1,2 isolation flag",2,0,2);


  h_delta_phi_basic = new TH1F("delta_phi_basic","Delta phi between leptons",32,0,3.2);
  h_delta_phi_basic_cuts = new TH1F("delta_phi_basic_cuts","Delta phi between leptons",32,0,3.2);
  h_delta_phi_basic_cuts_ptl = new TH1F("delta_phi_basic_cuts_ptl","Delta phi between leptons",32,0,3.2);


  h_Z_pt_reco_basic = new TH1F("Z_pt_reco_basic","ZpT",1000,0,1000);
  h_Z_pt_reco_basic_cuts = new TH1F("Z_pt_reco_basic_cuts","ZpT",1000,0,1000);
  h_Z_pt_reco_basic_cuts_ptl = new TH1F("Z_pt_reco_basic_cuts_ptl","ZpT",1000,0,1000);


  h_delta_y_basic = new TH1F("delta_y_basic","Delta Rapidity",100,0,10);
  h_delta_y_basic_cuts = new TH1F("delta_y_basic_cuts","Delta Rapidity",100,0,10);
  h_delta_y_basic_cuts_ptl = new TH1F("delta_y_basic_cuts_ptl","Delta Rapidity",100,0,10);


  h_Z_centrality_basic = new TH1F("Z_centrality_basic","Z boson centrality",500,0,5);
  h_Z_centrality_basic_cuts = new TH1F("Z_centrality_basic_cuts","Z boson centrality",500,0,5);
  h_Z_centrality_basic_cuts_ptl = new TH1F("Z_centrality_basic_cuts_ptl","Z boson centrality",500,0,5);


  h_pt_bal_basic = new TH1F("pt_bal_basic","pT Balance",100,0,1);
  h_pt_bal_basic_cuts = new TH1F("pt_bal_basic_cuts","pT Balance",100,0,1);
  h_pt_bal_basic_cuts_ptl = new TH1F("pt_bal_basic_cuts_ptl","pT Balance",100,0,1);


  h_mass_jj_basic = new TH1F("mass_jj_basic","Invariant mass di_jet system",5000,0,5000);
  h_mass_jj_basic_cuts = new TH1F("mass_jj_basic_cuts","Invariant mass di_jet system",5000,0,5000);
  h_mass_jj_basic_cuts_ptl = new TH1F("mass_jj_basic_cuts_ptl","Invariant mass di_jet system",5000,0,5000);


  h_n_jets_interval_basic = new TH1F("n_jets_interval_basic","N jets between rapidity interval",10,0,10);
  h_n_jets_interval_basic_cuts = new TH1F("n_jets_interval_basic_cuts","N jets between rapidity interval",10,0,10);
  h_n_jets_interval_basic_cuts_ptl = new TH1F("n_jets_interval_basic_cuts_ptl","N jets between rapidity interval",10,0,10);


  h_ljet0_pt_basic = new TH1F("ljet0_pt_basic","Light jet0 pT",1000,0,1000);
  h_ljet0_pt_basic_cuts = new TH1F("ljet0_pt_basic_cuts","Light jet0 pT",1000,0,1000);
  h_ljet0_pt_basic_cuts_ptl = new TH1F("ljet0_pt_basic_cuts_ptl","Light jet0 pT",1000,0,1000);


  h_ljet1_pt_basic = new TH1F("ljet1_pt_basic","Light jet1 pT",1000,0,1000);
  h_ljet1_pt_basic_cuts = new TH1F("ljet1_pt_basic_cuts","Light jet1 pT",1000,0,1000);
  h_ljet1_pt_basic_cuts_ptl = new TH1F("ljet1_pt_basic_cuts_ptl","Light jet1 pT",1000,0,1000);


  h_ljet2_pt_basic = new TH1F("ljet2_pt_basic","Light jet2 pT",1000,0,1000);
  h_ljet2_pt_basic_cuts = new TH1F("ljet2_pt_basic_cuts","Light jet2 pT",1000,0,1000);
  h_ljet2_pt_basic_cuts_ptl = new TH1F("ljet2_pt_basic_cuts_ptl","Light jet2 pT",1000,0,1000);


  h_gap_jet_pt_basic = new TH1F("gap_jet_pt_basic","Gap jet pT",1000,0,1000);
  h_gap_jet_pt_basic_cuts = new TH1F("gap_jet_pt_basic_cuts","Gap jet pT",1000,0,1000);
  h_gap_jet_pt_basic_cuts_ptl = new TH1F("gap_jet_pt_basic_cuts_ptl","Gap jet pT",1000,0,1000);


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


  h_vec_sum_pt_jets_basic = new TH1F("vec_sum_pt_jets_basic","Vector sum pT tagging jets",2000,0,2000);
  h_vec_sum_pt_jets_basic_cuts = new TH1F("vec_sum_pt_jets_basic_cuts","Vector sum pT tagging jets",2000,0,2000);
  h_vec_sum_pt_jets_basic_cuts_ptl = new TH1F("vec_sum_pt_jets_basic_cuts_ptl","Vector sum pT tagging jets",2000,0,2000);


  h_ratio_zpt_sumjetpt_basic = new TH1F("ratio_zpt_sumjetpt_basic","Ratio ZpT over vector sum pT tagging jets",500,0,5);
  h_ratio_zpt_sumjetpt_basic_cuts = new TH1F("ratio_zpt_sumjetpt_basic_cuts","Ratio ZpT over vector sum pT tagging jets",500,0,5);
  h_ratio_zpt_sumjetpt_basic_cuts_ptl = new TH1F("ratio_zpt_sumjetpt_basic_cuts_ptl","Ratio ZpT over vector sum pT tagging jets",500,0,5);


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

  if (lumFactor!=1){
    h_Z_pt_truth_basic = new TH1F("Z_pt_truth_basic","Truth ZpT",1000,0,1000);
    h_Z_pt_truth_basic_cuts = new TH1F("Z_pt_truth_basic_cuts","Truth ZpT",1000,0,1000);
    h_Z_pt_truth_basic_cuts_ptl = new TH1F("Z_pt_truth_basic_cuts_ptl","Truth ZpT",1000,0,1000);
  }
}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();
    //Charges and lepton ID
    bool muon_id=muon_0_id_medium && muon_1_id_medium;
    float q_mu0=muon_0_q;
    float q_mu1=muon_1_q;
    size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

    if (n_muons==2 && q_mu0!=q_mu1 && muon_id && n_ljets>=2 && n_ljets<=3){
      //angles
      double angle_l_MET=del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(muon_1_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(muon_1_p4->Phi(),muon_0_p4->Phi());

      bool trigger_decision = false;
      bool trigger_match = false;
      bool trigger_match_1 = false;
      bool trigger_match_2 = false;
      bool trigger_match_12 = false;
      if (run_number>= 276262 && run_number<=284484) {
        trigger_decision = bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
        trigger_match_1 = bool((muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50) && !(muTrigMatch_1_HLT_mu20_iloose_L1MU15 | muTrigMatch_1_HLT_mu50));
        trigger_match_2 = bool(!(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu20_iloose_L1MU15 | muTrigMatch_1_HLT_mu50));
        trigger_match_12 = bool((muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu20_iloose_L1MU15 | muTrigMatch_1_HLT_mu50));
        if(weight!=1){
          if (trigger_match_1){weight=weight*muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;}
          if (trigger_match_2){weight=weight*muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;}
        }
        trigger_match= trigger_match_1 | trigger_match_2 | trigger_match_12;
      } else {
        trigger_decision = bool(HLT_mu26_ivarmedium | HLT_mu50);
        trigger_match_1 = bool((muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && !(muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
        trigger_match_2 = bool(!(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
        trigger_match_12 = bool((muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
        if(weight!=1){
          if (trigger_match_1){weight=weight*muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;}
          if (trigger_match_2){weight=weight*muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;}
        }
        trigger_match= trigger_match_1 | trigger_match_2 | trigger_match_12;
      }

      // INVARIANT MASS 2-JETS
      double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));

      if (mjj>=250 && angle<7*pi/9 && trigger_decision && trigger_match && abs(muon_0_p4->Eta())>=0.1 && abs(muon_1_p4->Eta())>=0.1) {

        double inv_mass{};
        inv_mass=sqrt(2*muon_0_p4->Pt()*muon_1_p4->Pt()*(cosh(muon_0_p4->Eta()-muon_1_p4->Eta())-cos(muon_0_p4->Phi()-muon_1_p4->Phi())));

        double Z_pt_x=0;
        double Z_pt_y=0;
        double Z_pt=0;
        double truth_z_pt=0.0;

        if (z_sample==1 || z_sample==2)
        {
          truth_z_pt=truth_Z_p4->Pt()/1000;
        }

        Z_pt_x=muon_1_p4->Pt()*cos(muon_1_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi());
        Z_pt_y=muon_1_p4->Pt()*sin(muon_1_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi());
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
          pt_bal=(((*muon_0_p4)+(*muon_1_p4)+(*ljet_0_p4)+(*ljet_1_p4))).Pt()/(muon_0_p4->Pt()+muon_1_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt());
        } else {
          pt_bal=(((*muon_0_p4)+(*muon_1_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*ljet_2_p4))).Pt()/(muon_0_p4->Pt()+muon_1_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+ljet_2_p4->Pt());
        }

        // Z BOSON CENTRALITY
        double lepton_xi=((*muon_0_p4)+(*muon_1_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        //pT gap jet
        double pt_gap_jet{};
        if (is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4)){pt_gap_jet=ljet_2_p4->Pt();}


        // Minimum DeltaR between lepton and jets
        std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
        std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};

        double min_dR_lep1 = min_deltaR(muon_0_p4,is_jet_present,jet_container);
        double min_dR_lep2 = min_deltaR(muon_1_p4,is_jet_present,jet_container);

        // Cuts vector
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        double a{50},b{40};
        // CUTS
        if (angle<=3.2){cuts[0]=1;}
        if(delta_y>=2.0){cuts[1]=1;}
        if(n_bjets_MV2c10_FixedCutBEff_85==0){cuts[2]=1;}
        if(muon_0_iso_TightTrackOnly_FixedRad==1 && muon_1_iso_TightTrackOnly_FixedRad==1){cuts[3]=1;}
        if(muon_0_p4->Pt()>=a){cuts[4]=1;}
        if(muon_1_p4->Pt()>=b){cuts[5]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[6]=1;}
        if(ljet_1_p4->Pt()>=70){cuts[7]=1;}
        if(pt_bal<=0.15){cuts[8]=1;}
        if(mjj>=1000){cuts[9]=1;}
        if(n_jets_interval==0){cuts[10]=1;}
        if(z_centrality < 0.5 /*&& z_centrality <= 1.0*/){cuts[11]=1;}
        if (inv_mass<101 && inv_mass>81){cuts[12]=1;}
        if (event_number%2==0){
          if(muon_0_p4->Pt()>=(a+0)){cuts[13]=1;}
        } else {
          if(muon_1_p4->Pt()>=(b+0)){cuts[13]=1;}
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
          h_lepiso->Fill(muon_0_iso_TightTrackOnly_FixedRad==1 && muon_0_iso_TightTrackOnly_FixedRad==1,weight);
        }
        if ((sum-cuts[4])==13) {
          h_lep1_pt->Fill(muon_0_p4->Pt(),weight);
        }
        if ((sum-cuts[5])==13) {
          h_lep2_pt->Fill(muon_1_p4->Pt(),weight);
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
        }
        if ((sum-cuts[10])==13) {
          h_n_jets_interval->Fill(n_jets_interval,weight);
          h_gap_jet_pt_basic_cuts_ptl->Fill(pt_gap_jet,weight);
        }
        if ((sum-cuts[11])==13) {
          h_Z_centrality->Fill(z_centrality,weight);
        }
        if ((sum-cuts[12])==13) {
          h_inv_mass->Fill(inv_mass,weight);
        }

        //  Filling histos
        h_lep1_pt_basic->Fill(muon_0_p4->Pt(),weight);
        h_lep2_pt_basic->Fill(muon_1_p4->Pt(),weight);
        h_lep1_eta_basic->Fill(muon_0_p4->Eta(),weight);
        h_lep2_eta_basic->Fill(muon_1_p4->Eta(),weight);
        h_delta_R_leplep_basic->Fill(muon_0_p4->DeltaR(*muon_1_p4),weight);
        h_delta_R_lep1jet_basic->Fill(min_dR_lep1,weight);
        h_delta_R_lep2jet_basic->Fill(min_dR_lep2,weight);
        h_sum_pt_basic->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
        h_met_basic->Fill(met_reco_p4->Pt(),weight);
        h_inv_mass_basic->Fill(inv_mass,weight);

        h_lep1_phi_basic->Fill(muon_0_p4->Phi(),weight);
        h_lep2_phi_basic->Fill(muon_1_p4->Phi(),weight);
        if(weight!=1){h_Z_pt_truth_basic->Fill(truth_z_pt,weight);}
        h_jet_n_basic->Fill(n_jets,weight);
        h_n_bjets_basic->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        h_lep_iso_basic->Fill(muon_0_iso_TightTrackOnly_FixedRad==1 && muon_0_iso_TightTrackOnly_FixedRad==1,weight);
        h_delta_phi_basic->Fill(angle,weight);
        h_Z_pt_reco_basic->Fill(Z_pt,weight);
        h_delta_y_basic->Fill(delta_y,weight);
        h_Z_centrality_basic->Fill(z_centrality,weight);
        h_pt_bal_basic->Fill(pt_bal,weight);
        h_mass_jj_basic->Fill(mjj,weight);
        h_n_jets_interval_basic->Fill(n_jets_interval,weight);
        h_ljet0_pt_basic->Fill(ljet_0_p4->Pt(),weight);
        h_ljet1_pt_basic->Fill(ljet_1_p4->Pt(),weight);
        h_ljet2_pt_basic->Fill(ljet_2_p4->Pt(),weight);
        h_ljet0_eta_basic->Fill(ljet_0_p4->Eta(),weight);
        h_ljet1_eta_basic->Fill(ljet_1_p4->Eta(),weight);
        h_ljet2_eta_basic->Fill(ljet_2_p4->Eta(),weight);
        h_vec_sum_pt_jets_basic->Fill(jet_pt_sum,weight);
        h_ratio_zpt_sumjetpt_basic->Fill(ratio_zpt_sumjetpt,weight);


        // DELTA PHI CUT
        if (cuts[0]==1){
          h_lep1_pt_basic_dphi->Fill(muon_0_p4->Pt(),weight);
          h_lep2_pt_basic_dphi->Fill(muon_1_p4->Pt(),weight);
          h_sum_pt_basic_dphi->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
          h_met_basic_dphi->Fill(met_reco_p4->Pt(),weight);
          h_inv_mass_basic_dphi->Fill(inv_mass,weight);

          // DELTA RAPIDITY CUT
          if (cuts[1]==1) {
            h_lep1_pt_basic_dphi_drap->Fill(muon_0_p4->Pt(),weight);
            h_lep2_pt_basic_dphi_drap->Fill(muon_1_p4->Pt(),weight);
            h_sum_pt_basic_dphi_drap->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
            h_met_basic_dphi_drap->Fill(met_reco_p4->Pt(),weight);
            h_inv_mass_basic_dphi_drap->Fill(inv_mass,weight);

            // B-TAG CUT
            if (cuts[2]==1) {
              h_lep1_pt_basic_dphi_drap_btag->Fill(muon_0_p4->Pt(),weight);
              h_lep2_pt_basic_dphi_drap_btag->Fill(muon_1_p4->Pt(),weight);
              h_sum_pt_basic_dphi_drap_btag->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
              h_met_basic_dphi_drap_btag->Fill(met_reco_p4->Pt(),weight);
              h_inv_mass_basic_dphi_drap_btag->Fill(inv_mass,weight);

              // ISOLATION CUT
              if (cuts[3]==1) {
                h_lep1_pt_basic_dphi_drap_btag_iso->Fill(muon_0_p4->Pt(),weight);
                h_lep2_pt_basic_dphi_drap_btag_iso->Fill(muon_1_p4->Pt(),weight);
                h_sum_pt_basic_dphi_drap_btag_iso->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                h_met_basic_dphi_drap_btag_iso->Fill(met_reco_p4->Pt(),weight);
                h_inv_mass_basic_dphi_drap_btag_iso->Fill(inv_mass,weight);

                // LEPTON 1 PT CUT
                if (cuts[4]==1) {
                  h_lep1_pt_basic_dphi_drap_btag_iso_pt1->Fill(muon_0_p4->Pt(),weight);
                  h_lep2_pt_basic_dphi_drap_btag_iso_pt1->Fill(muon_1_p4->Pt(),weight);
                  h_sum_pt_basic_dphi_drap_btag_iso_pt1->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                  h_met_basic_dphi_drap_btag_iso_pt1->Fill(met_reco_p4->Pt(),weight);
                  h_inv_mass_basic_dphi_drap_btag_iso_pt1->Fill(inv_mass,weight);

                    // LEPTON 2 PT CUT
                  if (cuts[5]==1) {
                    h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2->Fill(muon_0_p4->Pt(),weight);
                    h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2->Fill(muon_1_p4->Pt(),weight);
                    h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                    h_met_basic_dphi_drap_btag_iso_pt1_pt2->Fill(met_reco_p4->Pt(),weight);
                    h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2->Fill(inv_mass,weight);

                    // JET 1 PT CUT
                    if(cuts[6]==1){
                      h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Fill(muon_0_p4->Pt(),weight);
                      h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Fill(muon_1_p4->Pt(),weight);
                      h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                      h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Fill(met_reco_p4->Pt(),weight);
                      h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Fill(inv_mass,weight);

                      // JET 2 PT CUT
                      if(cuts[7]==1){
                        h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Fill(muon_0_p4->Pt(),weight);
                        h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Fill(muon_1_p4->Pt(),weight);
                        h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                        h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Fill(met_reco_p4->Pt(),weight);
                        h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Fill(inv_mass,weight);

                        // PT BALANCE CUT
                        if(cuts[8]==1){
                          h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Fill(muon_0_p4->Pt(),weight);
                          h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Fill(muon_1_p4->Pt(),weight);
                          h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                          h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Fill(met_reco_p4->Pt(),weight);
                          h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Fill(inv_mass,weight);

                          // MASS DI-JET SYSTEM CUT
                          if(cuts[9]==1){
                            h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Fill(muon_0_p4->Pt(),weight);
                            h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Fill(muon_1_p4->Pt(),weight);
                            h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                            h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Fill(met_reco_p4->Pt(),weight);
                            h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Fill(inv_mass,weight);

                            // N JETS IN THE INTERVAL CUT
                            if(cuts[10]==1){
                              h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Fill(muon_0_p4->Pt(),weight);
                              h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Fill(muon_1_p4->Pt(),weight);
                              h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                              h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Fill(met_reco_p4->Pt(),weight);
                              h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Fill(inv_mass,weight);

                              // Z CENTRALITY CUT
                              if(cuts[11]==1){
                                h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(muon_0_p4->Pt(),weight);
                                h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(muon_1_p4->Pt(),weight);
                                h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(muon_0_p4->Eta(),weight);
                                h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(muon_1_p4->Eta(),weight);
                                h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(muon_0_p4->DeltaR(*muon_1_p4),weight);
                                h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(min_dR_lep1,weight);
                                h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(min_dR_lep2,weight);
                                h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                                h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(met_reco_p4->Pt(),weight);
                                h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Fill(inv_mass,weight);

                                // LEPTONS MASS CUT
                                if(cuts[12]==1){
                                  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(muon_0_p4->Pt(),weight);
                                  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(muon_1_p4->Pt(),weight);
                                  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(muon_0_p4->Eta(),weight);
                                  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(muon_1_p4->Eta(),weight);
                                  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(muon_0_p4->DeltaR(*muon_1_p4),weight);
                                  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(min_dR_lep1,weight);
                                  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(min_dR_lep2,weight);
                                  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                                  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(met_reco_p4->Pt(),weight);
                                  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Fill(inv_mass,weight);

                                  h_lep1_phi_basic_cuts->Fill(muon_0_p4->Phi(),weight);
                                  h_lep2_phi_basic_cuts->Fill(muon_1_p4->Phi(),weight);
                                  if(weight!=1){h_Z_pt_truth_basic_cuts->Fill(truth_z_pt,weight);}
                                  h_jet_n_basic_cuts->Fill(n_jets,weight);
                                  h_n_bjets_basic_cuts->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
                                  h_lep_iso_basic_cuts->Fill(muon_0_iso_TightTrackOnly_FixedRad==1 && muon_0_iso_TightTrackOnly_FixedRad==1,weight);
                                  h_delta_phi_basic_cuts->Fill(angle,weight);
                                  h_Z_pt_reco_basic_cuts->Fill(Z_pt,weight);
                                  h_delta_y_basic_cuts->Fill(delta_y,weight);
                                  h_Z_centrality_basic_cuts->Fill(z_centrality,weight);
                                  h_pt_bal_basic_cuts->Fill(pt_bal,weight);
                                  h_mass_jj_basic_cuts->Fill(mjj,weight);
                                  h_n_jets_interval_basic_cuts->Fill(n_jets_interval,weight);
                                  h_ljet0_pt_basic_cuts->Fill(ljet_0_p4->Pt(),weight);
                                  h_ljet1_pt_basic_cuts->Fill(ljet_1_p4->Pt(),weight);
                                  h_ljet2_pt_basic_cuts->Fill(ljet_2_p4->Pt(),weight);
                                  h_ljet0_eta_basic_cuts->Fill(ljet_0_p4->Eta(),weight);
                                  h_ljet1_eta_basic_cuts->Fill(ljet_1_p4->Eta(),weight);
                                  h_ljet2_eta_basic_cuts->Fill(ljet_2_p4->Eta(),weight);
                                  h_vec_sum_pt_jets_basic_cuts->Fill(jet_pt_sum,weight);
                                  h_ratio_zpt_sumjetpt_basic_cuts->Fill(ratio_zpt_sumjetpt,weight);

                                  // LEPTON PT CUT
                                  if(cuts[13]==1){
                                    h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(muon_0_p4->Pt(),weight);
                                    h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(muon_1_p4->Pt(),weight);
                                    h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(muon_0_p4->Eta(),weight);
                                    h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(muon_1_p4->Eta(),weight);
                                    h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(muon_0_p4->DeltaR(*muon_1_p4),weight);
                                    h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(min_dR_lep1,weight);
                                    h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(min_dR_lep2,weight);
                                    h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(muon_0_p4->Pt()+muon_1_p4->Pt(),weight);
                                    h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(met_reco_p4->Pt(),weight);
                                    h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Fill(inv_mass,weight);

                                    h_lep1_phi_basic_cuts_ptl->Fill(muon_0_p4->Phi(),weight);
                                    h_lep2_phi_basic_cuts_ptl->Fill(muon_1_p4->Phi(),weight);
                                    if(weight!=1){h_Z_pt_truth_basic_cuts_ptl->Fill(truth_z_pt,weight);}
                                    h_jet_n_basic_cuts_ptl->Fill(n_jets,weight);
                                    h_n_bjets_basic_cuts_ptl->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
                                    h_lep_iso_basic_cuts_ptl->Fill(muon_0_iso_TightTrackOnly_FixedRad==1 && muon_0_iso_TightTrackOnly_FixedRad==1,weight);
                                    h_delta_phi_basic_cuts_ptl->Fill(angle,weight);
                                    h_Z_pt_reco_basic_cuts_ptl->Fill(Z_pt,weight);
                                    h_delta_y_basic_cuts_ptl->Fill(delta_y,weight);
                                    h_Z_centrality_basic_cuts_ptl->Fill(z_centrality,weight);
                                    h_pt_bal_basic_cuts_ptl->Fill(pt_bal,weight);
                                    h_mass_jj_basic_cuts_ptl->Fill(mjj,weight);
                                    h_n_jets_interval_basic_cuts_ptl->Fill(n_jets_interval,weight);
                                    h_ljet0_pt_basic_cuts_ptl->Fill(ljet_0_p4->Pt(),weight);
                                    h_ljet1_pt_basic_cuts_ptl->Fill(ljet_1_p4->Pt(),weight);
                                    h_ljet2_pt_basic_cuts_ptl->Fill(ljet_2_p4->Pt(),weight);
                                    h_ljet0_eta_basic_cuts_ptl->Fill(ljet_0_p4->Eta(),weight);
                                    h_ljet1_eta_basic_cuts_ptl->Fill(ljet_1_p4->Eta(),weight);
                                    h_ljet2_eta_basic_cuts_ptl->Fill(ljet_2_p4->Eta(),weight);
                                    h_vec_sum_pt_jets_basic_cuts_ptl->Fill(jet_pt_sum,weight);
                                    h_ratio_zpt_sumjetpt_basic_cuts_ptl->Fill(ratio_zpt_sumjetpt,weight);
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
  h_lep1_pt_basic->Write();
  h_lep1_pt_basic_dphi->Write();
  h_lep1_pt_basic_dphi_drap->Write();
  h_lep1_pt_basic_dphi_drap_btag->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_lep1_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_lep2_pt_basic->Write();
  h_lep2_pt_basic_dphi->Write();
  h_lep2_pt_basic_dphi_drap->Write();
  h_lep2_pt_basic_dphi_drap_btag->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_lep2_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();

  h_lep1_eta_basic->Write();
  h_lep1_eta_basic_dphi->Write();
  h_lep1_eta_basic_dphi_drap->Write();
  h_lep1_eta_basic_dphi_drap_btag->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_lep2_eta_basic->Write();
  h_lep2_eta_basic_dphi->Write();
  h_lep2_eta_basic_dphi_drap->Write();
  h_lep2_eta_basic_dphi_drap_btag->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_delta_R_leplep_basic->Write();
  h_delta_R_leplep_basic_dphi->Write();
  h_delta_R_leplep_basic_dphi_drap->Write();
  h_delta_R_leplep_basic_dphi_drap_btag->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_delta_R_lep1jet_basic->Write();
  h_delta_R_lep1jet_basic_dphi->Write();
  h_delta_R_lep1jet_basic_dphi_drap->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_delta_R_lep2jet_basic->Write();
  h_delta_R_lep2jet_basic_dphi->Write();
  h_delta_R_lep2jet_basic_dphi_drap->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_sum_pt_basic->Write();
  h_sum_pt_basic_dphi->Write();
  h_sum_pt_basic_dphi_drap->Write();
  h_sum_pt_basic_dphi_drap_btag->Write();
  h_sum_pt_basic_dphi_drap_btag_iso->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_sum_pt_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_met_basic->Write();
  h_met_basic_dphi->Write();
  h_met_basic_dphi_drap->Write();
  h_met_basic_dphi_drap_btag->Write();
  h_met_basic_dphi_drap_btag_iso->Write();
  h_met_basic_dphi_drap_btag_iso_pt1->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_inv_mass_basic->Write();
  h_inv_mass_basic_dphi->Write();
  h_inv_mass_basic_dphi_drap->Write();
  h_inv_mass_basic_dphi_drap_btag->Write();
  h_inv_mass_basic_dphi_drap_btag_iso->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass->Write();
  h_inv_mass_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl->Write();


  h_lep1_phi_basic->Write();
  h_lep1_phi_basic_cuts->Write();
  h_lep1_phi_basic_cuts_ptl->Write();


  h_lep2_phi_basic->Write();
  h_lep2_phi_basic_cuts->Write();
  h_lep2_phi_basic_cuts_ptl->Write();


  h_jet_n_basic->Write();
  h_jet_n_basic_cuts->Write();
  h_jet_n_basic_cuts_ptl->Write();


  h_n_bjets_basic->Write();
  h_n_bjets_basic_cuts->Write();
  h_n_bjets_basic_cuts_ptl->Write();


  h_lep_iso_basic->Write();
  h_lep_iso_basic_cuts->Write();
  h_lep_iso_basic_cuts_ptl->Write();


  h_delta_phi_basic->Write();
  h_delta_phi_basic_cuts->Write();
  h_delta_phi_basic_cuts_ptl->Write();


  h_Z_pt_reco_basic->Write();
  h_Z_pt_reco_basic_cuts->Write();
  h_Z_pt_reco_basic_cuts_ptl->Write();


  h_delta_y_basic->Write();
  h_delta_y_basic_cuts->Write();
  h_delta_y_basic_cuts_ptl->Write();


  h_Z_centrality_basic->Write();
  h_Z_centrality_basic_cuts->Write();
  h_Z_centrality_basic_cuts_ptl->Write();


  h_pt_bal_basic->Write();
  h_pt_bal_basic_cuts->Write();
  h_pt_bal_basic_cuts_ptl->Write();


  h_mass_jj_basic->Write();
  h_mass_jj_basic_cuts->Write();
  h_mass_jj_basic_cuts_ptl->Write();


  h_n_jets_interval_basic->Write();
  h_n_jets_interval_basic_cuts->Write();
  h_n_jets_interval_basic_cuts_ptl->Write();


  h_ljet0_pt_basic->Write();
  h_ljet0_pt_basic_cuts->Write();
  h_ljet0_pt_basic_cuts_ptl->Write();


  h_ljet1_pt_basic->Write();
  h_ljet1_pt_basic_cuts->Write();
  h_ljet1_pt_basic_cuts_ptl->Write();


  h_ljet2_pt_basic->Write();
  h_ljet2_pt_basic_cuts->Write();
  h_ljet2_pt_basic_cuts_ptl->Write();


  h_gap_jet_pt_basic->Write();
  h_gap_jet_pt_basic_cuts->Write();
  h_gap_jet_pt_basic_cuts_ptl->Write();

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


  h_vec_sum_pt_jets_basic->Write();
  h_vec_sum_pt_jets_basic_cuts->Write();
  h_vec_sum_pt_jets_basic_cuts_ptl->Write();


  h_ratio_zpt_sumjetpt_basic->Write();
  h_ratio_zpt_sumjetpt_basic_cuts->Write();
  h_ratio_zpt_sumjetpt_basic_cuts_ptl->Write();


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

  if (lumFactor!=1){
    h_Z_pt_truth_basic->Write();
    h_Z_pt_truth_basic_cuts->Write();
    h_Z_pt_truth_basic_cuts_ptl->Write();
  }
}

#endif // End header guard
