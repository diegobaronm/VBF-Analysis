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

/*string event_rejected(bool cond1, bool cond2, bool cond3, bool cond4, bool cond5, bool cond6){
  string str1="NOPASS";
  string str2="NOPASS";
  string str3="NOPASS";
  string str4="NOPASS";
  string str5="NOPASS";
  string str6="NOPASS";
  if (cond1){
    str1="Passed";
  }
  if (cond2){
    str2="Passed";
  }
  if (cond3){
    str3="Passed";
  }
  if (cond4){
    str4="Passed";
  }
  if (cond5){
    str5="Passed";
  }
  if (cond6){
    str6="Passed";
  }
  return ", "+str1+", "+str2+", "+str3+", "+str4+", "+str5+", "+str6+"\n";
}

string print(std::vector<int> const &input)
{
  string cuts="";
	for (int i = 0; i < input.size(); i++) {
		cuts=cuts+to_string(input.at(i))+',';
	}
  return cuts+'\n';
}
*/

void CLoop::Book(double lumFactor) {
    double pi=TMath::Pi();

    // VARIABLES ONLY ONCE
    h_RunN_topo = new TH1F("RunN_topo","Run number",94000,276000,370000);
    h_RunN_topo_tpt = new TH1F("RunN_topo_tpt","Run number",94000,276000,370000);

    h_EventN_RN358115_topo = new TH1F("EventN_RN358115_topo","Event number RN(358115)",100000,0,3.0e9);
    h_EventN_RN358115_topo_tpt = new TH1F("EventN_RN358115_topo_tpt","Event number RN(358115)",100000,0,3.0e9);

    h_EventN_RN359541_topo = new TH1F("EventN_RN359541_topo","Event number RN(359541)",100000,0,3.0e9);
    h_EventN_RN359541_topo_tpt = new TH1F("EventN_RN359541_topo_tpt","Event number RN(359541)",100000,0,3.0e9);
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

    // Histograms for lepton 1
    //pT
    h_lep1_pt_topo = new TH1F("lep1_pt_topo","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi = new TH1F("lep1_pt_topo_dphi","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag = new TH1F("lep1_pt_topo_dphi_btag","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag_iso = new TH1F("lep1_pt_topo_dphi_btag_iso","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag_iso_pt1 = new TH1F("lep1_pt_topo_dphi_btag_iso_pt1","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2 = new TH1F("lep1_pt_topo_dphi_btag_iso_pt1_pt2","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Transverse momentum of lep1",200,0,200);
    h_lep1_pt_topo_dphi_btag_iso_pt2_mass_ptl = new TH1F("lep1_pt_topo_dphi_btag_iso_pt2_mass_ptl","Transverse momentum of lep1",200,0,200);

    //phi
    h_lep1_phi_topo= new TH1F("lep1_phi_topo","Lepton 1 phi angle",64,-3.2,3.2);
    h_lep1_phi_cuts= new TH1F("lep1_phi_cuts","Lepton 1 phi angle",64,-3.2,3.2);

    // Histograms for lepton 2
    h_lep2_pt_topo = new TH1F("lep2_pt_topo","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi = new TH1F("lep2_pt_topo_dphi","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag = new TH1F("lep2_pt_topo_dphi_btag","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag_iso = new TH1F("lep2_pt_topo_dphi_btag_iso","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag_iso_pt1 = new TH1F("lep2_pt_topo_dphi_btag_iso_pt1","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2 = new TH1F("lep2_pt_topo_dphi_btag_iso_pt1_pt2","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Transverse momentum of lep2",200,0,200);
    h_lep2_pt_topo_dphi_btag_iso_pt1_mass_ptl = new TH1F("lep2_pt_topo_dphi_btag_iso_pt1_mass_ptl","Transverse momentum of lep2",200,0,200);

    // Histograms for sum lepton pt
    h_sumlep_pt_topo = new TH1F("sumlep_pt_topo","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi = new TH1F("sumlep_pt_topo_dphi","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag = new TH1F("sumlep_pt_topo_dphi_btag","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag_iso = new TH1F("sumlep_pt_topo_dphi_btag_iso","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag_iso_pt1 = new TH1F("sumlep_pt_topo_dphi_btag_iso_pt1","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2 = new TH1F("sumlep_pt_topo_dphi_btag_iso_pt1_pt2","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Sum pT",400,0,400);
    h_sumlep_pt_topo_dphi_btag_iso_pt1_mass_ptl = new TH1F("sumlep_pt_topo_dphi_btag_iso_pt1_mass_ptl","Sum pT",400,0,400);

    h_sum_pt_topo_ZpTa = new TH1F("sum_pt_pt_topo_ZpTa","Sum of pT ",400,0,400);
    h_sum_pt_topo_ZpTb = new TH1F("sum_pt_pt_topo_ZpTb","Sum of pT ",400,0,400);
    h_sum_pt_topo_ZpTc = new TH1F("sum_pt_pt_topo_ZpTc","Sum of pT ",400,0,400);

    h_sum_pt_cuts_ZpTa = new TH1F("sum_pt_pt_cuts_ZpTa","Sum of pT ",400,0,400);
    h_sum_pt_cuts_ZpTb = new TH1F("sum_pt_pt_cuts_ZpTb","Sum of pT ",400,0,400);
    h_sum_pt_cuts_ZpTc = new TH1F("sum_pt_pt_cuts_ZpTc","Sum of pT ",400,0,400);

    h_sum_pt_cuts_ptl_ZpTa = new TH1F("sum_pt_pt_cuts_ptl_ZpTa","Sum of pT ",400,0,400);
    h_sum_pt_cuts_ptl_ZpTb = new TH1F("sum_pt_pt_cuts_ptl_ZpTb","Sum of pT ",400,0,400);
    h_sum_pt_cuts_ptl_ZpTc = new TH1F("sum_pt_pt_cuts_ptl_ZpTc","Sum of pT ",400,0,400);

    h_lep2_phi_topo= new TH1F("lep2_phi_topo","Lepton 2 phi",64,-3.2,3.2);
    h_lep2_phi_cuts= new TH1F("lep2_phi_cuts","Lepton 2 phi",64,-3.2,3.2);

    // MET Histograms
    h_met_topo = new TH1F("MET_topo","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi = new TH1F("MET_topo_dphi","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_btag = new TH1F("MET_topo_dphi_btag","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_btag_iso = new TH1F("MET_topo_dphi_btag_iso","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_btag_iso_pt1 = new TH1F("MET_topo_dphi_btag_iso_pt1","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_btag_iso_pt1_pt2 = new TH1F("MET_topo_dphi_btag_iso_pt1_pt2","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("MET_topo_dphi_btag_iso_pt1_pt2_mass","Missing Transverse momentum",300,0,300);
    h_met_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("MET_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Missing Transverse momentum",300,0,300);

    // Invariant mass histograms

    // inv histos
    h_inv_mass_topo = new TH1F("inv_mass_topo","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi = new TH1F("inv_mass_topo_dphi","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag = new TH1F("h_inv_mass_topo_dphi_btag","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso = new TH1F("h_inv_mass_topo_dphi_btag_iso","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1 = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2 = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl","Invariant mass",300,0,300);

    if (lumFactor!=1)
    {
      h_Z_pt_truth_topo = new TH1F("Z_pt_truth_topo","Z_truth boson transverse momentum inside",400,0,400);
      h_Z_pt_truth_cuts = new TH1F("Z_pt_truth_cuts","Z_truth boson transverse momentum inside",400,0,400);
      h_Z_pt_truth_cuts_ptl = new TH1F("Z_pt_truth_cuts_ptl","Z_truth boson transverse momentum inside",400,0,400);
    }

    // Jet Number Histograms
    h_jet_n_topo = new TH1F("jet_n_topo","Number of jets",10,-1,9);
    h_jet_n_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("jet_n_topo_dphi_btag_iso_pt1_pt2_mass","Number of jets",10,-1,9);
    h_jet_n_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("jet_n_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Number of jets",10,-1,9);

    h_b_tag_topo = new TH1F("b_tag_topo","b taging variable",2,0,2);
    h_b_tag_topo_dphi_iso_pt1_pt2_mass_ptl = new TH1F("b_tag_topo_dphi_iso_pt1_pt2_mass_ptl","b taging variable",2,0,2);


    // Isolation variables Histograms
    h_elec_0_isolation_topo = new TH1F("elec_0_isolation_topo","lepton 1 isolation",2,0,2);
    h_elec_0_isolation_topo_dphi_btag_pt1_pt2_mass_ptl = new TH1F("elec_0_isolation_topo_dphi_btag_pt1_pt2_mass_ptl","lepton 1 isolation",2,0,2);

    h_elec_1_isolation_topo = new TH1F("elec_1_isolation_topo","lepton 2 isolation",2,0,2);
    h_elec_1_isolation_topo_dphi_btag_pt1_pt2_mass_ptl = new TH1F("elec_1_isolation_topo_dphi_btag_pt1_pt2_mass_ptl","lepton 2 isolation",2,0,2);

    h_Z_pt_reco_topo = new TH1F("Z_pt_topo","Z boson transverse momentum",400,0,400);
    h_Z_pt_reco_cuts = new TH1F("Z_pt_cuts","Z boson transverse momentum",400,0,400);
    h_Z_pt_reco_cuts_ptl = new TH1F("Z_pt_cuts_ptl","Z boson transverse momentum",400,0,400);

    h_delta_phi= new TH1F("delta_phi","Delta phi leptons",32,0,3.2);
    h_delta_phi_topo= new TH1F("delta_phi_topo","Delta phi leptons",32,0,3.2);
    h_delta_phi_cuts= new TH1F("delta_phi_cuts","Delta phi leptons",32,0,3.2);
    h_delta_phi_cuts_ptl= new TH1F("delta_phi_cuts_ptl","Delta phi leptons",32,0,3.2);
    h_delta_phi_cuts_butphi= new TH1F("delta_phi_cuts_butphi","Delta phi leptons",32,0,3.2);

    //MJ BG DISCRIMINATION VARIABLES
    h_ratio_ptjet_zpt_topo = new TH1F("ratio_ptjet_zpt_topo","ratio_ptjet_zpt",40,0,4);
    h_ratio_lpt_tpt_topo = new TH1F("ratio_lpt_tpt_topo","ratio_lpt_tpt",40,0,4);
    h_ratio_ptjet_zpt_cuts = new TH1F("ratio_ptjet_zpt_cuts","ratio_ptjet_zpt",40,0,4);
    h_ratio_lpt_tpt_cuts = new TH1F("ratio_lpt_tpt_cuts","ratio_lpt_tpt",40,0,4);
    h_ratio_ptjet_zpt_cuts_ptl = new TH1F("ratio_ptjet_zpt_cuts_ptl","ratio_ptjet_zpt",40,0,4);
    h_ratio_lpt_tpt_cuts_ptl = new TH1F("ratio_lpt_tpt_cuts_ptl","ratio_lpt_tpt",40,0,4);
    // TRIGGER STATISTICS
    h_trigger_1_pass = new TH1F("trigger_1_pass","Events where 1 muon fires the trigger",2,0,2);
    h_trigger_1_pass_cuts = new TH1F("trigger_1_pass_cuts","Events where 1 muon fires the trigger",2,0,2);
    h_trigger_2_pass = new TH1F("trigger_2_pass","Events where 2 muons fire the trigger",2,0,2);
    h_trigger_2_pass_cuts = new TH1F("trigger_2_pass_cuts","Events where 2 muons fire the trigger",2,0,2);
}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();
    if (n_electrons==2){
      //angles
      double angle_l_MET=del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(elec_1_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(elec_1_p4->Phi(),elec_0_p4->Phi());

      h_delta_phi->Fill(angle,weight);

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

      h_trigger_1_pass->Fill((trigger_match_1 | trigger_match_2),weight);
      h_trigger_2_pass->Fill(trigger_match_12,weight);

      bool elec_id = elec_0_id_tight && elec_1_id_tight;

      float q_mu0=elec_0_q;
      float q_mu1=elec_1_q;

      if (q_mu0!=q_mu1 && angle<3*pi/4 && trigger_decision && elec_id && trigger_match ) {

        double inv_mass{};
        inv_mass=sqrt(2*elec_0_p4->Pt()*elec_1_p4->Pt()*(cosh(elec_0_p4->Eta()-elec_1_p4->Eta())-cos(elec_0_p4->Phi()-elec_1_p4->Phi())));

        double Z_pt_x=0;
        double Z_pt_y=0;
        double Z_pt=0;
        double r_jpt_zpt=0;
        double r_lpt_tpt=elec_0_p4->Pt()/elec_1_p4->Pt();
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
        h_Z_pt_reco_topo->Fill(Z_pt,weight);
        if (weight!=1){
          h_Z_pt_truth_topo->Fill(truth_z_pt,weight);
        }
        r_jpt_zpt=ljet_0_p4->Pt()/Z_pt;

        // Cuts bits
        vector<int> cuts={0,0,0,0,0,0,0};
        int random=rand()%2;
        double a{50},b{47};
        if(random){
          a=50;
          b=47;
        }
        if (angle<=11*pi/18){
          cuts[0]=1;
        }
        if (n_bjets_MV2c10_FixedCutBEff_85==0){
          cuts[1]=1;
        }
        if (elec_0_iso_FCTight==1 && elec_1_iso_FCTight==1) {
          cuts[2]=1;
        }
        if (elec_0_p4->Pt()>=a) {
          cuts[3]=1;
        }
        if (elec_1_p4->Pt()>=b) {
          cuts[4]=1;
        }
        if (inv_mass<100 && inv_mass>80) {
          cuts[5]=1;
        }
        if(random){
          if(elec_1_p4->Pt()<(b+20)){
            cuts[6]=1;
          }
        } else{
          if(elec_0_p4->Pt()<(a+20)){
            cuts[6]=1;
          }
        }

        vector<int> c_phi={0,1,1,1,1,1,1};
        vector<int> c_btag={1,0,1,1,1,1,1};
        vector<int> c_iso={1,1,0,1,1,1,1};
        vector<int> c_pt1={1,1,1,0,1,1,1};
        vector<int> c_pt2={1,1,1,1,0,1,1};
        vector<int> c_mass={1,1,1,1,1,0,1};
        vector<int> c_ptl={1,1,1,1,1,1,0};
        vector<int> c_all={1,1,1,1,1,1,1};

        if (cuts==c_phi||cuts==c_all) {
          h_delta_phi_cuts_butphi->Fill(angle,weight);
        }
        if ((cuts==c_btag||cuts==c_all) && n_jets!=0) {
          h_b_tag_topo_dphi_iso_pt1_pt2_mass_ptl->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        }
        if (cuts==c_iso||cuts==c_all) {
          h_elec_0_isolation_topo_dphi_btag_pt1_pt2_mass_ptl->Fill(elec_0_iso_FCTight,weight);
          h_elec_1_isolation_topo_dphi_btag_pt1_pt2_mass_ptl->Fill(elec_1_iso_FCTight,weight);
        }
        if (cuts==c_pt1||cuts==c_all) {
          h_lep1_pt_topo_dphi_btag_iso_pt2_mass_ptl->Fill(elec_0_p4->Pt(),weight);
        }
        if (cuts==c_pt2||cuts==c_all) {
          h_lep2_pt_topo_dphi_btag_iso_pt1_mass_ptl->Fill(elec_1_p4->Pt(),weight);
        }
        if (cuts==c_mass||cuts==c_all) {
          h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl->Fill(inv_mass,weight);
        }

        //  Filling histos
        h_RunN_topo->Fill(run_number,weight);
        if(run_number==358115){h_EventN_RN358115_topo->Fill(event_number,weight);}
        if(run_number==359541){h_EventN_RN359541_topo->Fill(event_number,weight);}
        h_jet_n_topo->Fill(n_jets, weight);
        h_b_tag_topo->Fill(n_bjets_MV2c10_FixedCutBEff_85,weight);
        h_elec_0_isolation_topo->Fill(elec_0_iso_FCTight,weight);
        h_elec_1_isolation_topo->Fill(elec_1_iso_FCTight,weight);
        h_met_topo->Fill(met_reco_p4->Pt(),weight);
        h_lep1_pt_topo->Fill(elec_0_p4->Pt(),weight);
        h_lep2_pt_topo->Fill(elec_1_p4->Pt(),weight);
        h_sumlep_pt_topo->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
        h_lep1_phi_topo->Fill(elec_0_p4->Phi(),weight);
        h_lep2_phi_topo->Fill(elec_1_p4->Phi(),weight);
        h_delta_phi_topo->Fill(angle,weight);
        if (Z_pt<100){
          h_sum_pt_topo_ZpTa->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
        } if (Z_pt>100 && Z_pt<150){
          h_sum_pt_topo_ZpTb->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
        } if (Z_pt>150) {
          h_sum_pt_topo_ZpTc->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
        }
        h_inv_mass_topo->Fill(inv_mass,weight);
        h_ratio_ptjet_zpt_topo->Fill(r_jpt_zpt,weight);
        h_ratio_lpt_tpt_topo->Fill(r_lpt_tpt,weight);
        h_ljet1_pt_topo->Fill(ljet_0_p4->Pt(),weight);
        h_ljet2_pt_topo->Fill(ljet_1_p4->Pt(),weight);
        h_ljet3_pt_topo->Fill(ljet_2_p4->Pt(),weight);

        // ANGLE CUT
        if (cuts[0]==1){
          h_met_topo_dphi->Fill(met_reco_p4->Pt(),weight);
          h_lep1_pt_topo_dphi->Fill(elec_0_p4->Pt(),weight);
          h_lep2_pt_topo_dphi->Fill(elec_1_p4->Pt(),weight);
          h_sumlep_pt_topo_dphi->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
          h_inv_mass_topo_dphi->Fill(inv_mass,weight);

          // B TAGGING CUT
          if (cuts[1]==1 || n_jets==0) {
            h_met_topo_dphi_btag->Fill(met_reco_p4->Pt(),weight);
            h_lep1_pt_topo_dphi_btag->Fill(elec_0_p4->Pt(),weight);
            h_lep2_pt_topo_dphi_btag->Fill(elec_1_p4->Pt(),weight);
            h_sumlep_pt_topo_dphi_btag->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
            h_inv_mass_topo_dphi_btag->Fill(inv_mass,weight);

            // ISOLATION CUT
            if (cuts[2]==1) {
              h_met_topo_dphi_btag_iso->Fill(met_reco_p4->Pt(),weight);
              h_lep1_pt_topo_dphi_btag_iso->Fill(elec_0_p4->Pt(),weight);
              h_lep2_pt_topo_dphi_btag_iso->Fill(elec_1_p4->Pt(),weight);
              h_sumlep_pt_topo_dphi_btag_iso->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
              h_inv_mass_topo_dphi_btag_iso->Fill(inv_mass,weight);

              // pT 1 CUT
              if (cuts[3]==1) {
                h_met_topo_dphi_btag_iso_pt1->Fill(met_reco_p4->Pt(),weight);
                h_lep1_pt_topo_dphi_btag_iso_pt1->Fill(elec_0_p4->Pt(),weight);
                h_lep2_pt_topo_dphi_btag_iso_pt1->Fill(elec_1_p4->Pt(),weight);
                h_sumlep_pt_topo_dphi_btag_iso_pt1->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                h_inv_mass_topo_dphi_btag_iso_pt1->Fill(inv_mass,weight);

                // pT 2 CUT
                if (cuts[4]==1) {
                  h_met_topo_dphi_btag_iso_pt1_pt2->Fill(met_reco_p4->Pt(),weight);
                  h_lep1_pt_topo_dphi_btag_iso_pt1_pt2->Fill(elec_0_p4->Pt(),weight);
                  h_lep2_pt_topo_dphi_btag_iso_pt1_pt2->Fill(elec_1_p4->Pt(),weight);
                  h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                  h_inv_mass_topo_dphi_btag_iso_pt1_pt2->Fill(inv_mass,weight);

                    // INV MASS CUT
                  if (cuts[5]==1) {
                    h_jet_n_topo_dphi_btag_iso_pt1_pt2_mass->Fill(n_jets, weight);
                    h_met_topo_dphi_btag_iso_pt1_pt2_mass->Fill(met_reco_p4->Pt(),weight);
                    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass->Fill(elec_0_p4->Pt(),weight);
                    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass->Fill(elec_1_p4->Pt(),weight);
                    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass->Fill(inv_mass,weight);

                    h_ratio_lpt_tpt_cuts->Fill(r_lpt_tpt,weight);
                    h_ratio_ptjet_zpt_cuts->Fill(r_jpt_zpt,weight);
                    h_lep1_phi_cuts->Fill(elec_0_p4->Phi(),weight);
                    h_lep2_phi_cuts->Fill(elec_1_p4->Phi(),weight);
                    h_Z_pt_reco_cuts->Fill(Z_pt,weight);
                    h_ljet1_pt_topo_cuts->Fill(ljet_0_p4->Pt(),weight);
                    h_ljet2_pt_topo_cuts->Fill(ljet_1_p4->Pt(),weight);
                    h_ljet3_pt_topo_cuts->Fill(ljet_2_p4->Pt(),weight);


                    h_trigger_1_pass_cuts->Fill((trigger_match_1 | trigger_match_2),weight);
                    h_trigger_2_pass_cuts->Fill(trigger_match_12,weight);

                    if (Z_pt<100){
                      h_sum_pt_cuts_ZpTa->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                    } if (Z_pt>100 && Z_pt<150){
                      h_sum_pt_cuts_ZpTb->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                    } if (Z_pt>150) {
                      h_sum_pt_cuts_ZpTc->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                    }

                    if (weight!=1){
                      h_Z_pt_truth_cuts->Fill(truth_z_pt,weight);
                    }
                    if(cuts[6]==1){
                      h_RunN_topo_tpt->Fill(run_number,weight);
                      if(run_number==358115){h_EventN_RN358115_topo_tpt->Fill(event_number,weight);}
                      if(run_number==359541){h_EventN_RN359541_topo_tpt->Fill(event_number,weight);}
                      h_met_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(met_reco_p4->Pt(),weight);
                      h_jet_n_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(n_jets, weight);
                      h_lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(elec_0_p4->Pt(),weight);
                      h_lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(elec_1_p4->Pt(),weight);
                      h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                      h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(inv_mass,weight);

                      h_ratio_lpt_tpt_cuts_ptl->Fill(r_lpt_tpt,weight);
                      h_ratio_ptjet_zpt_cuts_ptl->Fill(r_jpt_zpt,weight);
                      h_Z_pt_reco_cuts_ptl->Fill(Z_pt,weight);
                      h_ljet1_pt_topo_cuts_tpt->Fill(ljet_0_p4->Pt(),weight);
                      h_ljet2_pt_topo_cuts_tpt->Fill(ljet_1_p4->Pt(),weight);
                      h_ljet3_pt_topo_cuts_tpt->Fill(ljet_2_p4->Pt(),weight);

                      if (Z_pt<100){
                        h_sum_pt_cuts_ptl_ZpTa->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                      } if (Z_pt>100 && Z_pt<150){
                        h_sum_pt_cuts_ptl_ZpTb->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                      } if (Z_pt>150) {
                        h_sum_pt_cuts_ptl_ZpTc->Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight);
                      }

                      if (weight!=1){
                        h_Z_pt_truth_cuts_ptl->Fill(truth_z_pt,weight);
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
    // This function is where you can control the style elements of your histograms and write them to a file
    // It is called once per data set

    // For example, set some properties of the lep_n histogram
    /*h_lep_n->GetXaxis()->SetTitle("Number of leptons per event"); // label x axis
    h_lep_n->GetYaxis()->SetTitle("Number of entries/bin"); // label y axis
    h_lep_n->SetTitle("Number of leptons  per event");
    h_lep_n->SetLineColor(kRed);*/ // set the line colour to red
    // For more information see https://root.cern.ch/root/htmldoc/guides/users-guide/Histograms.html

    // Write histograms to a file
    // This needs to be done for each histogram
    h_RunN_topo->Write();
    h_RunN_topo_tpt->Write();

    h_EventN_RN358115_topo->Write();
    h_EventN_RN358115_topo_tpt->Write();

    h_EventN_RN359541_topo->Write();
    h_EventN_RN359541_topo_tpt->Write();
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

    h_lep1_pt_topo->Write();
    h_lep1_pt_topo_dphi->Write();
    h_lep1_pt_topo_dphi_btag->Write();
    h_lep1_pt_topo_dphi_btag_iso->Write();
    h_lep1_pt_topo_dphi_btag_iso_pt1->Write();
    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2->Write();
    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_lep1_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();
    h_lep1_pt_topo_dphi_btag_iso_pt2_mass_ptl->Write();

    //phi
    h_lep1_phi_topo->Write();
    h_lep1_phi_cuts->Write();

    // Histograms for lepton 2
    h_lep2_pt_topo->Write();
    h_lep2_pt_topo_dphi->Write();
    h_lep2_pt_topo_dphi_btag->Write();
    h_lep2_pt_topo_dphi_btag_iso->Write();
    h_lep2_pt_topo_dphi_btag_iso_pt1->Write();
    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2->Write();
    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_lep2_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();
    h_lep2_pt_topo_dphi_btag_iso_pt1_mass_ptl->Write();

    h_sumlep_pt_topo->Write();
    h_sumlep_pt_topo_dphi->Write();
    h_sumlep_pt_topo_dphi_btag->Write();
    h_sumlep_pt_topo_dphi_btag_iso->Write();
    h_sumlep_pt_topo_dphi_btag_iso_pt1->Write();
    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2->Write();
    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_sumlep_pt_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();
    h_sumlep_pt_topo_dphi_btag_iso_pt1_mass_ptl->Write();

    h_sum_pt_topo_ZpTa->Write();
    h_sum_pt_topo_ZpTb->Write();
    h_sum_pt_topo_ZpTc->Write();

    h_sum_pt_cuts_ZpTa->Write();
    h_sum_pt_cuts_ZpTb->Write();
    h_sum_pt_cuts_ZpTc->Write();

    h_sum_pt_cuts_ptl_ZpTa->Write();
    h_sum_pt_cuts_ptl_ZpTb->Write();
    h_sum_pt_cuts_ptl_ZpTc->Write();

    h_lep2_phi_topo->Write();
    h_lep2_phi_cuts->Write();

    // MET Histograms
    h_met_topo->Write();
    h_met_topo_dphi->Write();
    h_met_topo_dphi_btag->Write();
    h_met_topo_dphi_btag_iso->Write();
    h_met_topo_dphi_btag_iso_pt1->Write();
    h_met_topo_dphi_btag_iso_pt1_pt2->Write();
    h_met_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_met_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();

    // Invariant mass histograms

    // inv histos
    h_inv_mass_topo->Write();
    h_inv_mass_topo_dphi->Write();
    h_inv_mass_topo_dphi_btag->Write();
    h_inv_mass_topo_dphi_btag_iso->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl->Write();

    if (lumFactor!=1)
    {
      h_Z_pt_truth_topo->Write();
      h_Z_pt_truth_cuts->Write();
      h_Z_pt_truth_cuts_ptl->Write();
    }

    // Jet Number Histograms
    h_jet_n_topo->Write();
    h_jet_n_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_jet_n_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();


    h_b_tag_topo->Write();
    h_b_tag_topo_dphi_iso_pt1_pt2_mass_ptl->Write();


    // Isolation variables Histograms
    h_elec_0_isolation_topo->Write();
    h_elec_0_isolation_topo_dphi_btag_pt1_pt2_mass_ptl->Write();

    h_elec_1_isolation_topo->Write();
    h_elec_1_isolation_topo_dphi_btag_pt1_pt2_mass_ptl->Write();

    h_Z_pt_reco_topo->Write();
    h_Z_pt_reco_cuts->Write();
    h_Z_pt_reco_cuts_ptl->Write();

    h_delta_phi->Write();
    h_delta_phi_topo->Write();
    h_delta_phi_cuts->Write();
    h_delta_phi_cuts_ptl->Write();
    h_delta_phi_cuts_butphi->Write();

    //MJ BG DISCRIMINATION VARIABLES
    h_ratio_ptjet_zpt_topo->Write();
    h_ratio_lpt_tpt_topo->Write();
    h_ratio_ptjet_zpt_cuts->Write();
    h_ratio_lpt_tpt_cuts->Write();
    h_ratio_ptjet_zpt_cuts_ptl->Write();
    h_ratio_lpt_tpt_cuts_ptl->Write();
    // TRIGGER STATISTICS
    h_trigger_1_pass->Write();
    h_trigger_1_pass_cuts->Write();
    h_trigger_2_pass->Write();
    h_trigger_2_pass_cuts->Write();
}

#endif // End header guard