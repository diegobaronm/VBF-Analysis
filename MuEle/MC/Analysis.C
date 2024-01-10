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

void CLoop::Book() {

}

void CLoop::Fill(double weight, int z_sample, const std::string& sampleName) {
  double pi=TMath::Pi();
  //Charges and electon ID
  float qelec=elec_0_q;
  float qmuon=muon_0_q;
  bool muon_id=muon_0_id_medium;
  bool elec_id=elec_0_id_tight;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  if (qelec!=qmuon && n_muons==1 && n_electrons==1 && weight > -190 && elec_id && muon_id && n_ljets>=2 && n_ljets<=3){
    
    //angles
    double angle_elec_MET=del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
    double angle_muon_MET=del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
    double angle=del_phi(muon_0_p4->Phi(),elec_0_p4->Phi());
    //trigger decision muon
    bool trigger_decision_mu= false;
    bool trigger_match_mu= false;
    if (run_number>= 276262 && run_number<=284484) {
      trigger_decision_mu= bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
      trigger_match_mu=bool(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50);
    } else {
      trigger_decision_mu= bool(HLT_mu26_ivarmedium | HLT_mu50);
      trigger_match_mu=bool(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50);
    }

    //trigger decision electron
    bool trigger_decision_e= false;
    bool trigger_match_e= false;
    if (run_number>= 276262 && run_number<=284484){
        trigger_decision_e=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
        trigger_match_e=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
    } else {
        trigger_decision_e=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
        trigger_match_e=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
    }

    // INVARIANT MASS 2-JETS
    double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
    //bool twoLightJetsInID = !( abs(ljet_0_p4->Eta())>2.5 && abs(ljet_1_p4->Eta())>2.5 );
    //bool twoLightJetsOutsideID = ( abs(ljet_0_p4->Eta())>2.5 && abs(ljet_1_p4->Eta())>2.5 );
    if (mjj>=250 && ((trigger_decision_mu && trigger_match_mu) || (trigger_decision_e && trigger_match_e))) {

      //topology
      bool inside= abs(angle-(angle_elec_MET+angle_muon_MET))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
      bool outside_elec= angle_elec_MET<angle_muon_MET && abs(angle-(angle_elec_MET+angle_muon_MET)) > 0.00001 && cos(angle_elec_MET)>0;
      bool outside_muon= angle_elec_MET>angle_muon_MET && abs(angle-(angle_elec_MET+angle_muon_MET)) > 0.00001 && cos(angle_muon_MET)>0;
      bool signal_events = inside || outside_elec || outside_muon;

      if (signal_events){
        // RECO mass AND neutrino momentum
        double cot_elec=1.0/tan(elec_0_p4->Phi());
        double cot_muon=1.0/tan(muon_0_p4->Phi());
        double pt_muon_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_elec)/(cos(muon_0_p4->Phi())-sin(muon_0_p4->Phi())*cot_elec);
        double pt_elec_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_muon)/(cos(elec_0_p4->Phi())-sin(elec_0_p4->Phi())*cot_muon);

        double reco_mass{};
        double massMuonElec = sqrt(2*(muon_0_p4->Dot(*elec_0_p4)));
        if(inside){
            reco_mass=sqrt(2*muon_0_p4->Pt()*elec_0_p4->Pt()*(cosh(muon_0_p4->Eta()-elec_0_p4->Eta())-cos(muon_0_p4->Phi()-elec_0_p4->Phi()))+2*elec_0_p4->Pt()*pt_muon_nu*(cosh(elec_0_p4->Eta()-muon_0_p4->Eta())-cos(elec_0_p4->Phi()-muon_0_p4->Phi()))+2*muon_0_p4->Pt()*pt_elec_nu*(cosh(muon_0_p4->Eta()-elec_0_p4->Eta())-cos(muon_0_p4->Phi()-elec_0_p4->Phi()))+2*pt_elec_nu*pt_muon_nu*(cosh(elec_0_p4->Eta()-muon_0_p4->Eta())-cos(elec_0_p4->Phi()-muon_0_p4->Phi())));
        }

        double neutrino_pt=0;
        double reco_mass_outside=0;
        if (outside_elec) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_elec_MET);
          reco_mass=5+sqrt(2*(muon_0_p4->Pt()*elec_0_p4->Pt()*(cosh(muon_0_p4->Eta()-elec_0_p4->Eta())-cos(muon_0_p4->Phi()-elec_0_p4->Phi()))+muon_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-elec_0_p4->Eta())-cos(muon_0_p4->Phi()-elec_0_p4->Phi()))));
        }
        if (outside_muon) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_muon_MET);
          reco_mass=5+sqrt(2*(elec_0_p4->Pt()*muon_0_p4->Pt()*(cosh(elec_0_p4->Eta()-muon_0_p4->Eta())-cos(elec_0_p4->Phi()-muon_0_p4->Phi()))+elec_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-muon_0_p4->Eta())-cos(elec_0_p4->Phi()-muon_0_p4->Phi()))));
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
          Z_pt_x=muon_0_p4->Pt()*cos(muon_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+pt_muon_nu*cos(muon_0_p4->Phi())+pt_elec_nu*cos(elec_0_p4->Phi());
          Z_pt_y=muon_0_p4->Pt()*sin(muon_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+pt_muon_nu*sin(muon_0_p4->Phi())+pt_elec_nu*sin(elec_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }
        if (outside_muon) {
          Z_pt_x=muon_0_p4->Pt()*cos(muon_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(muon_0_p4->Phi());
          Z_pt_y=muon_0_p4->Pt()*sin(muon_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(muon_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }
        if (outside_elec) {
          Z_pt_x=muon_0_p4->Pt()*cos(muon_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(elec_0_p4->Phi());
          Z_pt_y=muon_0_p4->Pt()*sin(muon_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(elec_0_p4->Phi());
          Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
          if (z_sample==0){
            truth_z_pt=Z_pt;
          }
        }

        // TRANSVERSE MASS LEPTON
        double elecmet_mass=sqrt(2*elec_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(elec_0_p4->Phi()-met_reco_p4->Phi())));
        double muonmet_mass=sqrt(2*muon_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(muon_0_p4->Phi()-met_reco_p4->Phi())));
        // Vector sum pT of the jets
        double jet_pt_sum= (*ljet_0_p4 + *ljet_1_p4).Pt();
        // Ratio ZpT/jet_pt_sum
        double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;

        // OMEGA VARIABLE DEFINITION
        double omega=0.0;
        if (inside && (angle_elec_MET<angle_muon_MET)) {
          omega=1.0-(angle_elec_MET)/(angle);
        }
        if (inside && (angle_elec_MET>angle_muon_MET)) {
          omega=(angle_muon_MET)/(angle);
        }
        if (outside_elec) {
          omega=1.0+(angle_elec_MET)/(angle);
        }
        if (outside_muon) {
          omega=-1.0*(angle_muon_MET)/(angle);
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
        double scalarSum = elec_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt();
        TLorentzVector vectorSum = (*elec_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4);
        if (n_jets_interval==1){
          scalarSum+= ljet_2_p4->Pt();
          vectorSum+= (*ljet_2_p4);
        }
        TLorentzVector nu_muon_p4(0,0,0,0);
        TLorentzVector nu_elec_p4(0,0,0,0);
        if(inside){
          nu_muon_p4 = TLorentzVector(pt_muon_nu*cos(muon_0_p4->Phi()),pt_muon_nu*sin(muon_0_p4->Phi()),0,0);
          nu_elec_p4 = TLorentzVector(pt_elec_nu*cos(elec_0_p4->Phi()),pt_elec_nu*sin(elec_0_p4->Phi()),0,0);
        } else {
          if(outside_elec) nu_elec_p4 = TLorentzVector(neutrino_pt*cos(elec_0_p4->Phi()),neutrino_pt*sin(elec_0_p4->Phi()),0,0);
          else if(outside_muon) nu_muon_p4 = TLorentzVector (neutrino_pt*cos(muon_0_p4->Phi()),neutrino_pt*sin(muon_0_p4->Phi()),0,0);
        }
        pt_bal= (vectorSum+nu_muon_p4+nu_elec_p4).Pt()/(scalarSum+nu_muon_p4.Pt()+nu_elec_p4.Pt());

        // Z BOSON CENTRALITY
        double electon_xi=((*muon_0_p4)+(*elec_0_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(electon_xi-0.5*dijet_xi)/delta_y;

        //pT gap jet
        double pt_gap_jet{};
        if (is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4)){pt_gap_jet=ljet_2_p4->Pt();}

        // Minimum DeltaR between electon and jets
        std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
        std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};

        double min_dR_muon = min_deltaR(muon_0_p4,is_jet_present,jet_container);
        double min_dR_elec = min_deltaR(elec_0_p4,is_jet_present,jet_container);

        // Definition of the superCR = CR(a+b+c)
        bool CRa = z_centrality < 0.5 && n_jets_interval == 1;
        bool CRb = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 1;
        bool CRc = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 0;
        bool superCR = CRa || CRb || CRc;

        // ONLY SUPER CR
        //if (!superCR) return;

        // Cuts vector
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        // CUTS
        if (angle<=3.2){cuts[0]=1;}
        if(delta_y>=2.0){cuts[1]=1;} // 2.0
        if(n_bjets_MV2c10_FixedCutBEff_85==0){cuts[2]=1;}
        if(muon_0_iso_TightTrackOnly_FixedRad==1 && elec_0_iso_FCTight==1){cuts[3]=1;}
        if(elec_0_p4->Pt()>=27){cuts[4]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[5]=1;} //85
        if(ljet_1_p4->Pt()>=70){cuts[6]=1;} //80
        if(pt_bal<=0.15){cuts[7]=1;} //0.4
        if(mjj>=1000){cuts[8]=1;} // 1000
        if(n_jets_interval==0){cuts[9]=1;}
        if(z_centrality < 0.5){cuts[10]=1;} // SR -> z_centrality < 0.5
        if (omega> -0.4 && omega <1.4){cuts[11]=1;}
        bool diLeptonMassRequirement = reco_mass<116 && reco_mass>66;
        if (diLeptonMassRequirement){cuts[12]=1;} // Z-peak reco_mass<116 && reco_mass>66 // Higgs reco_mass >= 116 && reco_mass < 150
        if (muon_0_p4->Pt()>=27){cuts[13]=1;}

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        size_t sum{0};
        for(auto &j : cuts){sum=sum+j;}

        std::vector<int> cutsVector{1};
        cutsVector.insert(cutsVector.end(),cuts.begin(),cuts.end());
        bool passedAllCuts = (sum+1==cutsVector.size());
        std::vector<int> notFullCutsVector{1,static_cast<int>(passedAllCuts)};

        //if (sampleName.substr(0,4)=="data" && passedAllCuts) return;

        double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double normPtDifference = (muon_0_p4->Pt()-elec_0_p4->Pt())/(muon_0_p4->Pt()+elec_0_p4->Pt());
        double anglejj = del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
        double metToDilepnuRatio = 0.0;
        double metToDilepRatio = met_reco_p4->Pt()/(muon_0_p4->Pt()+elec_0_p4->Pt());
        if (inside)
        {
          metToDilepnuRatio = met_reco_p4->Pt()/(muon_0_p4->Pt()+pt_muon_nu+elec_0_p4->Pt()+pt_elec_nu);
        }
        if (outside_muon || outside_elec)
        {
          metToDilepnuRatio = met_reco_p4->Pt()/(muon_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt);
        }

        double massMuonClosestJet{0.0};
        double massElecClosestJet{0.0};
        double massMuonFurthestJet{0.0};
        double massElecFurthestJet{0.0};
        bool j0CloserToMuon = muon_0_p4->DeltaR(*ljet_0_p4) <= muon_0_p4->DeltaR(*ljet_1_p4);
        if (j0CloserToMuon)
        {
          massMuonClosestJet = sqrt(2*(muon_0_p4->Dot(*ljet_0_p4)));
          massElecClosestJet = sqrt(2*(elec_0_p4->Dot(*ljet_1_p4)));
          massMuonFurthestJet = sqrt(2*(muon_0_p4->Dot(*ljet_1_p4)));
          massElecFurthestJet = sqrt(2*(elec_0_p4->Dot(*ljet_0_p4)));
        }
        else
        {
          massMuonClosestJet = sqrt(2*(muon_0_p4->Dot(*ljet_1_p4)));
          massElecClosestJet = sqrt(2*(elec_0_p4->Dot(*ljet_0_p4)));
          massMuonFurthestJet = sqrt(2*(muon_0_p4->Dot(*ljet_0_p4)));
          massElecFurthestJet = sqrt(2*(elec_0_p4->Dot(*ljet_1_p4)));
        }
        
        // FILLING CUTS HISTOGRAMS
        delta_phiContainer.Fill(angle,weight,cutsVector);
        delta_yContainer.Fill(delta_y,weight,cutsVector);
        n_bjetsContainer.Fill(n_bjets_MV2c10_FixedCutBEff_85,weight,cutsVector);
        isoContainer.Fill(muon_0_iso_TightTrackOnly_FixedRad && elec_0_iso_FCTight,weight,cutsVector);
        elec_ptContainer.Fill(elec_0_p4->Pt(),weight,cutsVector);
        ljet0_ptContainer.Fill(ljet_0_p4->Pt(),weight,cutsVector);
        ljet1_ptContainer.Fill(ljet_1_p4->Pt(),weight,cutsVector);
        pt_balContainer.Fill(pt_bal,weight,cutsVector);
        mass_jjContainer.Fill(mjj,weight,cutsVector);
        n_jets_intervalContainer.Fill(n_jets_interval,weight,cutsVector);
        Z_centralityContainer.Fill(z_centrality,weight,cutsVector);
        omegaContainer.Fill(omega,weight,cutsVector);
        muon_ptContainer.Fill(muon_0_p4->Pt(),weight,cutsVector);
        reco_massContainer.Fill(reco_mass,weight,cutsVector);
        recoVisibleMassRatioContainer.Fill(reco_mass/massMuonElec,weight,cutsVector);
        if (inside) {
            reco_mass_iContainer.Fill(reco_mass,weight,cutsVector);
            nuElecPtContainer.Fill(pt_elec_nu,weight,notFullCutsVector);
            nuMuonPtContainer.Fill(pt_muon_nu,weight,notFullCutsVector);
            nuPtAssummetryContainer.Fill((pt_elec_nu+pt_muon_nu)/(elec_0_p4->Pt()+muon_0_p4->Pt()),weight,notFullCutsVector);
        }
        if (outside_elec) {
            reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
            nuElecPtContainer.Fill(pt_elec_nu,weight,notFullCutsVector);
            nuPtAssummetryContainer.Fill((neutrino_pt)/(elec_0_p4->Pt()+muon_0_p4->Pt()),weight,notFullCutsVector);
        }
        if (outside_muon) {
            reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
            nuMuonPtContainer.Fill(pt_muon_nu,weight,notFullCutsVector);
            nuPtAssummetryContainer.Fill((neutrino_pt)/(elec_0_p4->Pt()+muon_0_p4->Pt()),weight,notFullCutsVector);
        }
        
        // HISTOGRAM FILLING STARTING IN BASIC SELECTION
        if (weight!=1){
          if(inside){Z_pt_truth_iNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
          if(outside_elec || outside_muon){Z_pt_truth_oNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
        }

        if (inside){
          elecnu_ptContainer.Fill(elec_0_p4->Pt()+pt_elec_nu,weight,cutsVector);
          muonnu_ptContainer.Fill(muon_0_p4->Pt()+pt_muon_nu,weight,cutsVector);
          sum_ptContainer.Fill(muon_0_p4->Pt()+pt_elec_nu+elec_0_p4->Pt()+pt_muon_nu,weight,cutsVector);
          Z_pt_reco_iNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
        } else {
          elecnu_ptContainer.Fill(elec_0_p4->Pt()+neutrino_pt,weight,cutsVector);
          muonnu_ptContainer.Fill(muon_0_p4->Pt()+neutrino_pt,weight,cutsVector);
          sum_ptContainer.Fill(muon_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt,weight,cutsVector);
          Z_pt_reco_oNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
        }

        elec_etaContainer.Fill(elec_0_p4->Eta(),weight,cutsVector);
        muon_etaContainer.Fill(muon_0_p4->Eta(),weight,cutsVector);
        delta_R_muonelecContainer.Fill(muon_0_p4->DeltaR(*elec_0_p4),weight,cutsVector);
        delta_R_elecjetContainer.Fill(min_dR_elec,weight,cutsVector);
        delta_R_muonjetContainer.Fill(min_dR_muon,weight,cutsVector);
        metContainer.Fill(met_reco_p4->Pt(),weight,cutsVector);

        elec_phiNotFullContainer.Fill(elec_0_p4->Phi(),weight,notFullCutsVector);
        muon_phiNotFullContainer.Fill(muon_0_p4->Phi(),weight,notFullCutsVector);
        trans_mass_elecNotFullContainer.Fill(elecmet_mass,weight,notFullCutsVector);
        trans_mass_muonNotFullContainer.Fill(muonmet_mass,weight,notFullCutsVector);
        jet_nNotFullContainer.Fill(n_jets,weight,notFullCutsVector);
        ljet2_ptNotFullContainer.Fill(ljet_2_p4->Pt(),weight,notFullCutsVector);
        ljet3_ptNotFullContainer.Fill(ljet_3_p4->Pt(),weight,notFullCutsVector);
        ljet0_etaNotFullContainer.Fill(ljet_0_p4->Eta(),weight,notFullCutsVector);
        ljet1_etaNotFullContainer.Fill(ljet_1_p4->Eta(),weight,notFullCutsVector);
        ljet2_etaNotFullContainer.Fill(ljet_2_p4->Eta(),weight,notFullCutsVector);
        vec_sum_pt_jetsNotFullContainer.Fill(jet_pt_sum,weight,notFullCutsVector);
        ratio_zpt_sumjetptNotFullContainer.Fill(ratio_zpt_sumjetpt,weight,notFullCutsVector);
        nLightJetsContainer.Fill(n_ljets,weight,notFullCutsVector);
        
        moreCentralJetContainer.Fill(etaMoreCentral,weight,notFullCutsVector);
        lessCentralJetContainer.Fill(etaLessCentral,weight,notFullCutsVector);
        normPtDifferenceContainer.Fill(normPtDifference,weight,notFullCutsVector);
        metToDilepnuRatioContainer.Fill(metToDilepnuRatio,weight,notFullCutsVector);
        metToDilepRatioContainer.Fill(metToDilepRatio,weight,notFullCutsVector);
        delta_phijjContainer.Fill(anglejj,weight,notFullCutsVector);
        massMuonClosestJetContainer.Fill(massMuonClosestJet,weight,notFullCutsVector);
        massElecClosestJetContainer.Fill(massElecClosestJet,weight,notFullCutsVector);
        massMuonFurthestJetContainer.Fill(massMuonFurthestJet,weight,notFullCutsVector);
        massElecFurthestJetContainer.Fill(massElecFurthestJet,weight,notFullCutsVector);
        flavourJet1Container.Fill(ljet_0_matched_pdgId,weight,notFullCutsVector);
        flavourJet2Container.Fill(ljet_1_matched_pdgId,weight,notFullCutsVector);
      }
    }
  }
}

void CLoop::Style(double lumFactor) {
  delta_phiContainer.Write();
  delta_yContainer.Write();
  n_bjetsContainer.Write();
  isoContainer.Write();
  elec_ptContainer.Write();
  ljet0_ptContainer.Write();
  ljet1_ptContainer.Write();
  pt_balContainer.Write();
  mass_jjContainer.Write();
  n_jets_intervalContainer.Write();
  Z_centralityContainer.Write();
  omegaContainer.Write();
  muon_ptContainer.Write();
  reco_mass_iContainer.Write();
  reco_massContainer.Write();
  reco_mass_oContainer.Write();

  elecnu_ptContainer.Write();
  muonnu_ptContainer.Write();
  sum_ptContainer.Write();
  Z_pt_reco_oNotFullContainer.Write();
  Z_pt_reco_iNotFullContainer.Write();
  elec_etaContainer.Write();
  muon_etaContainer.Write();
  delta_R_muonelecContainer.Write();
  delta_R_elecjetContainer.Write();
  delta_R_muonjetContainer.Write();
  metContainer.Write();
  elec_phiNotFullContainer.Write();
  muon_phiNotFullContainer.Write();
  trans_mass_elecNotFullContainer.Write();
  trans_mass_muonNotFullContainer.Write();
  jet_nNotFullContainer.Write();
  ljet2_ptNotFullContainer.Write();
  ljet3_ptNotFullContainer.Write();
  ljet0_etaNotFullContainer.Write();
  ljet1_etaNotFullContainer.Write();
  ljet2_etaNotFullContainer.Write();
  vec_sum_pt_jetsNotFullContainer.Write();
  ratio_zpt_sumjetptNotFullContainer.Write();
  nLightJetsContainer.Write();

  moreCentralJetContainer.Write();
  lessCentralJetContainer.Write();
  normPtDifferenceContainer.Write();
  metToDilepnuRatioContainer.Write();
  metToDilepRatioContainer.Write();
  delta_phijjContainer.Write();
  nuElecPtContainer.Write();
  nuMuonPtContainer.Write();
  nuPtAssummetryContainer.Write();
  massMuonClosestJetContainer.Write();
  massElecClosestJetContainer.Write();
  massMuonFurthestJetContainer.Write();
  massElecFurthestJetContainer.Write();
  flavourJet1Container.Write();
  flavourJet2Container.Write();
  recoVisibleMassRatioContainer.Write();

  if (lumFactor!=1){
    Z_pt_truth_iNotFullContainer.Write();
    Z_pt_truth_oNotFullContainer.Write();
  }

}

#endif // End header guard