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

  
}

void CLoop::Fill(double weight, int z_sample) {
  double pi=TMath::Pi();
  //Charges and lepton ID
  float ql=elec_0_q;
  float qtau=tau_0_q;
  bool lepton_id=elec_0_id_tight;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  if (ql!=qtau && n_electrons==1 && n_taus_rnn_loose>=1 && lepton_id && n_ljets>=2 && n_ljets<=3){
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
        if (outside_lep) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_l_MET);
          reco_mass = 5+sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+tau_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))));
        }
        if (outside_tau) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_tau_MET);
          reco_mass = 5+sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+elec_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))));
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
        if(elec_0_iso_FCTight==1){cuts[3]=1;}
        if(tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans >= 0.25){cuts[4]=1;}
        if(tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans >= 0.40){cuts[4]=1;}
        if(elec_0_p4->Pt()>=27){cuts[5]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[6]=1;}
        if(ljet_1_p4->Pt()>=70){cuts[7]=1;}
        if(pt_bal<=0.15){cuts[8]=1;}
        if(mjj>=1000){cuts[9]=1;}
        if(n_jets_interval==0){cuts[10]=1;}
        if(z_centrality<0.5){cuts[11]=1;} // SR -> z_centrality < 0.5
        if (omega> 0.2 && omega <1.1){cuts[12]=1;} // Z-peak omega> -0.2 && omega <1.6
        if(inv_taulep<=80 || inv_taulep>=100){cuts[13]=1;}
        if (tau_0_ele_bdt_score_trans_retuned>=0.05){cuts[14]=1;}
        bool diLeptonMassRequirement = reco_mass >= 150;
        if (diLeptonMassRequirement){cuts[15]=1;} // Z-peak reco_mass<116 && reco_mass>66 // Higgs reco_mass >= 116 && reco_mass < 150
        if (tau_0_p4->Pt()>=25){cuts[16]=1;}

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        size_t sum{0};
        for(auto &j : cuts){sum=sum+j;}

        std::vector<int> cutsVector{1};
        cutsVector.insert(cutsVector.end(),cuts.begin(),cuts.end());
        bool passedAllCuts = (sum+1==cutsVector.size());
        std::vector<int> notFullCutsVector{1,static_cast<int>(passedAllCuts)};

        double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double normPtDifference = (tau_0_p4->Pt()-elec_0_p4->Pt())/(tau_0_p4->Pt()+elec_0_p4->Pt());
        double anglejj = del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
        double metToDilepnuRatio = 0.0;
        double metToDilepRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt());
        if (inside)
        {
          metToDilepnuRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+pt_tau_nu+elec_0_p4->Pt()+pt_lep_nu);
        }
        if (outside_lep || outside_tau)
        {
          metToDilepnuRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt()+neutrino_pt);
        }

        double massTauCloserJet{0.0};
        double massLepClosestJet{0.0};
        double massTauFurthestJet{0.0};
        bool j0CloserToTau = tau_0_p4->DeltaR(*ljet_0_p4) <= tau_0_p4->DeltaR(*ljet_1_p4);
        if (j0CloserToTau)
        {
          massTauCloserJet = sqrt(2*(tau_0_p4->Dot(*ljet_0_p4)));
          massTauFurthestJet = sqrt(2*(tau_0_p4->Dot(*ljet_1_p4)));
          massLepClosestJet = sqrt(2*(elec_0_p4->Dot(*ljet_1_p4)));
        }
        else
        {
          massTauCloserJet = sqrt(2*(tau_0_p4->Dot(*ljet_1_p4)));
          massTauFurthestJet = sqrt(2*(tau_0_p4->Dot(*ljet_0_p4)));
          massLepClosestJet = sqrt(2*(elec_0_p4->Dot(*ljet_0_p4)));
        }
        bool neutrinoPtAboveT = false;
        if (inside) 
        {
          neutrinoPtAboveT = (pt_tau_nu>=25 && pt_lep_nu>=35);
        } else 
        {
          neutrinoPtAboveT = outside_lep ? neutrino_pt>=35 : neutrino_pt>=25;
        }

        // Transverse mass
        double transverseMassLep = (*elec_0_p4 + *met_reco_p4).Mt();
        double transverseMassTau = (*tau_0_p4 + *met_reco_p4).Mt();
        double transverseMassSum = transverseMassTau + transverseMassLep;
        double transverseMassRatio = (transverseMassTau - transverseMassLep)/transverseMassSum;

        bool testCuts = massTauCloserJet>=90 && normPtDifference > -0.3;
        if (true){
        // HISTOGRAM FILLING 
        lep_ptContainer.Fill(elec_0_p4->Pt(),weight,cutsVector);
        tau_ptContainer.Fill(tau_0_p4->Pt(),weight,cutsVector);
        omegaContainer.Fill(omega,weight,cutsVector);
        n_bjetsContainer.Fill(n_bjets_MV2c10_FixedCutBEff_85,weight,cutsVector);
        lepisoContainer.Fill(elec_0_iso_FCTight,weight,cutsVector);
        delta_phiContainer.Fill(angle,weight,cutsVector);
        delta_yContainer.Fill(delta_y,weight,cutsVector);
        Z_centralityContainer.Fill(z_centrality,weight,cutsVector);
        pt_balContainer.Fill(pt_bal,weight,cutsVector);
        mass_jjContainer.Fill(mjj,weight,cutsVector);
        n_jets_intervalContainer.Fill(n_jets_interval,weight,cutsVector);
        ljet0_ptContainer.Fill(ljet_0_p4->Pt(),weight,cutsVector);
        ljet1_ptContainer.Fill(ljet_1_p4->Pt(),weight,cutsVector);
        leptau_massContainer.Fill(inv_taulep,weight,cutsVector);
        eBDTContainer.Fill(tau_0_ele_bdt_score_trans_retuned,weight,cutsVector);
        reco_massContainer.Fill(reco_mass,weight,cutsVector);

        lepTransMassContainer.Fill(transverseMassLep,weight,notFullCutsVector);
        tauTransMassContainer.Fill(transverseMassTau,weight,notFullCutsVector);
        transMassSumContainer.Fill(transverseMassSum,weight,notFullCutsVector);
        transMassRatioContainer.Fill(transverseMassRatio,weight,notFullCutsVector);

        if (tau_0_n_charged_tracks==1){
          rnn_score_1pContainer.Fill(tau_0_jet_rnn_score_trans,weight,cutsVector);
        }
        if (tau_0_n_charged_tracks==3){
          rnn_score_3pContainer.Fill(tau_0_jet_rnn_score_trans,weight,cutsVector);
        }
        if (inside) {
          reco_mass_iContainer.Fill(reco_mass,weight,cutsVector);
          nuLepPtContainer.Fill(pt_lep_nu,weight,notFullCutsVector);
          nuTauPtContainer.Fill(pt_tau_nu,weight,notFullCutsVector);
          nuPtAssummetryContainer.Fill((pt_lep_nu-pt_tau_nu)/(pt_lep_nu+pt_tau_nu),weight,notFullCutsVector);
        }
        if (outside_lep) {
          reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
          nuLepPtContainer.Fill(neutrino_pt,weight,notFullCutsVector);
          nuPtAssummetryContainer.Fill(1.0,weight,notFullCutsVector);
        }
        if (outside_tau) {
          reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
          nuTauPtContainer.Fill(neutrino_pt,weight,notFullCutsVector);
          nuPtAssummetryContainer.Fill(-1.0,weight,notFullCutsVector);
        }
      

        if (inside){
          lepnu_ptContainer.Fill(elec_0_p4->Pt()+pt_lep_nu,weight,cutsVector);
          taunu_ptContainer.Fill(tau_0_p4->Pt()+pt_tau_nu,weight,cutsVector);
          sum_ptContainer.Fill(elec_0_p4->Pt()+pt_lep_nu+tau_0_p4->Pt()+pt_tau_nu,weight,cutsVector);
          Z_pt_reco_iNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
        } else {
          lepnu_ptContainer.Fill(elec_0_p4->Pt()+neutrino_pt,weight,cutsVector);
          taunu_ptContainer.Fill(tau_0_p4->Pt()+neutrino_pt,weight,cutsVector);
          sum_ptContainer.Fill(elec_0_p4->Pt()+tau_0_p4->Pt()+neutrino_pt,weight,cutsVector);
          Z_pt_reco_oNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
        }
        lep_etaContainer.Fill(elec_0_p4->Eta(),weight,cutsVector);
        tau_etaContainer.Fill(tau_0_p4->Eta(),weight,cutsVector);
        delta_R_taulepContainer.Fill(tau_0_p4->DeltaR(*elec_0_p4),weight,cutsVector);
        delta_R_lepjetContainer.Fill(min_dR_lep,weight,cutsVector);
        delta_R_taujetContainer.Fill(min_dR_tau,weight,cutsVector);
        metContainer.Fill(met_reco_p4->Pt(),weight,cutsVector);

        if (weight!=1){
          if(inside){Z_pt_truth_iNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
          if(outside_lep || outside_tau){Z_pt_truth_oNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
          if (tau_0_n_charged_tracks==1){
            tau_matched_1pNotFullContainer.Fill(tau_0_truth_isHadTau,weight,notFullCutsVector);
          }
          if (tau_0_n_charged_tracks==3){
            tau_matched_3pNotFullContainer.Fill(tau_0_truth_isHadTau,weight,notFullCutsVector);
          }
        }
        if(n_jets_interval==1){gap_jet_ptNotFullContainer.Fill(pt_gap_jet,weight,notFullCutsVector);}
        lep_phiNotFullContainer.Fill(elec_0_p4->Phi(),weight,notFullCutsVector);
        tau_phiNotFullContainer.Fill(tau_0_p4->Phi(),weight,notFullCutsVector);
        tau_nprongsNotFullContainer.Fill(tau_0_n_charged_tracks,weight,notFullCutsVector);
        trans_lep_massNotFullContainer.Fill(lepmet_mass,weight,notFullCutsVector);
        jet_nNotFullContainer.Fill(n_jets,weight,notFullCutsVector);
        n_fake_tracksNotFullContainer.Fill(tau_0_n_fake_tracks,weight,notFullCutsVector);
        n_core_tracksNotFullContainer.Fill(tau_0_n_core_tracks,weight,notFullCutsVector);
        n_iso_tracksNotFullContainer.Fill(tau_0_n_isolation_tracks,weight,notFullCutsVector);
        n_tracksNotFullContainer.Fill(tau_0_n_all_tracks,weight,notFullCutsVector);
        ljet2_ptNotFullContainer.Fill(ljet_2_p4->Pt(),weight,notFullCutsVector);
        ljet3_ptNotFullContainer.Fill(ljet_3_p4->Pt(),weight,notFullCutsVector);
        ljet0_etaNotFullContainer.Fill(ljet_0_p4->Eta(),weight,notFullCutsVector);
        ljet1_etaNotFullContainer.Fill(ljet_1_p4->Eta(),weight,notFullCutsVector);
        ljet2_etaNotFullContainer.Fill(ljet_2_p4->Eta(),weight,notFullCutsVector);
        trans_mass_lepNotFullContainer.Fill(lepmet_mass,weight,notFullCutsVector);
        vec_sum_pt_jetsNotFullContainer.Fill(jet_pt_sum,weight,notFullCutsVector);
        ratio_zpt_sumjetptNotFullContainer.Fill(ratio_zpt_sumjetpt,weight,notFullCutsVector);
        nLightJetsContainer.Fill(n_ljets,weight,notFullCutsVector);
        
        moreCentralJetContainer.Fill(etaMoreCentral,weight,notFullCutsVector);
        lessCentralJetContainer.Fill(etaLessCentral,weight,notFullCutsVector);
        normPtDifferenceContainer.Fill(normPtDifference,weight,notFullCutsVector);
        metToDilepnuRatioContainer.Fill(metToDilepnuRatio,weight,notFullCutsVector);
        metToDilepRatioContainer.Fill(metToDilepRatio,weight,notFullCutsVector);
        delta_phijjContainer.Fill(anglejj,weight,notFullCutsVector);
        massTauClosestJetContainer.Fill(massTauCloserJet,weight,notFullCutsVector);
        massTauFurthestJetContainer.Fill(massTauFurthestJet,weight,notFullCutsVector);
        massLepClosestJetContainer.Fill(massLepClosestJet,weight,notFullCutsVector);
        flavourJet1Container.Fill(ljet_0_matched_pdgId,weight,notFullCutsVector);
        flavourJet2Container.Fill(ljet_1_matched_pdgId,weight,notFullCutsVector);}
      }
  }
}
}

void CLoop::Style(double lumFactor) {
  lep_ptContainer.Write();
  tau_ptContainer.Write();
  omegaContainer.Write();
  n_bjetsContainer.Write();
  lepisoContainer.Write();
  delta_phiContainer.Write();
  delta_yContainer.Write();
  Z_centralityContainer.Write();
  pt_balContainer.Write();
  mass_jjContainer.Write();
  n_jets_intervalContainer.Write();
  ljet0_ptContainer.Write();
  ljet1_ptContainer.Write();
  rnn_score_1pContainer.Write();
  rnn_score_3pContainer.Write();
  leptau_massContainer.Write();
  eBDTContainer.Write();
  reco_mass_iContainer.Write();
  reco_massContainer.Write();
  reco_mass_oContainer.Write();

  lepTransMassContainer.Write();
  tauTransMassContainer.Write();
  transMassSumContainer.Write();
  transMassRatioContainer.Write();

  lepnu_ptContainer.Write();
  taunu_ptContainer.Write();
  sum_ptContainer.Write();
  Z_pt_reco_iNotFullContainer.Write();
  Z_pt_reco_oNotFullContainer.Write();

  lep_etaContainer.Write();
  tau_etaContainer.Write();
  delta_R_taulepContainer.Write();
  delta_R_lepjetContainer.Write();
  delta_R_taujetContainer.Write();
  metContainer.Write();

  gap_jet_ptNotFullContainer.Write();
  lep_phiNotFullContainer.Write();
  tau_phiNotFullContainer.Write();
  tau_nprongsNotFullContainer.Write();
  trans_lep_massNotFullContainer.Write();
  jet_nNotFullContainer.Write();
  n_fake_tracksNotFullContainer.Write();
  n_core_tracksNotFullContainer.Write();
  n_iso_tracksNotFullContainer.Write();
  n_tracksNotFullContainer.Write();
  ljet2_ptNotFullContainer.Write();
  ljet3_ptNotFullContainer.Write();
  ljet0_etaNotFullContainer.Write();
  ljet1_etaNotFullContainer.Write();
  ljet2_etaNotFullContainer.Write();
  trans_mass_lepNotFullContainer.Write();
  vec_sum_pt_jetsNotFullContainer.Write();
  ratio_zpt_sumjetptNotFullContainer.Write();
  nLightJetsContainer.Write();

  moreCentralJetContainer.Write();
  lessCentralJetContainer.Write();
  normPtDifferenceContainer.Write();
  metToDilepnuRatioContainer.Write();
  metToDilepRatioContainer.Write();
  delta_phijjContainer.Write();
  massTauClosestJetContainer.Write();
  massLepClosestJetContainer.Write();
  massTauFurthestJetContainer.Write();
  nuLepPtContainer.Write();
  nuTauPtContainer.Write();
  nuPtAssummetryContainer.Write();
  flavourJet1Container.Write();
  flavourJet2Container.Write();

  if (lumFactor!=1){
    Z_pt_truth_iNotFullContainer.Write();
    Z_pt_truth_oNotFullContainer.Write();
    tau_matched_1pNotFullContainer.Write();
    tau_matched_3pNotFullContainer.Write();
  }
}
#endif // End header guard
