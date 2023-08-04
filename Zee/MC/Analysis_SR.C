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
  
}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();

    bool elec_id = elec_0_id_tight && elec_1_id_tight;
    float q_mu0=elec_0_q;
    float q_mu1=elec_1_q;
    size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

    if (n_electrons==2 && q_mu0!=q_mu1 && elec_id  && n_ljets>=2 && n_ljets<=3){
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
        double signed_z_centrality = (lepton_xi-0.5*dijet_xi)/(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());

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
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
        if(z_centrality < 0.5){cuts[11]=1;}
        if (inv_mass >= 160){cuts[12]=1;} // Z-peak mass range 81 < m < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (event_number%2==0){
          if(elec_0_p4->Pt()>=(a+0)){cuts[13]=1;}
        } else {
          if(elec_1_p4->Pt()>=(b+0)){cuts[13]=1;}
        }

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        size_t sum{};
        for(auto &j : cuts){sum=sum+j;}

        std::vector<int> cutsVector{1};
        cutsVector.insert(cutsVector.end(),cuts.begin(),cuts.end());
        bool passedAllCuts = (sum+1==cutsVector.size());
        std::vector<int> notFullCutsVector{1,static_cast<int>(passedAllCuts)};

        // FILLING CUTS HISTOGRAMS
        delta_phiContainer.Fill(angle,weight,cutsVector);
        delta_yContainer.Fill(delta_y,weight,cutsVector);
        n_bjetsContainer.Fill(n_bjets_MV2c10_FixedCutBEff_85,weight,cutsVector);
        lepisoContainer.Fill(elec_0_iso_FCTight==1 && elec_1_iso_FCTight==1,weight,cutsVector);
        lep1_ptContainer.Fill(elec_0_p4->Pt(),weight,cutsVector);
        lep2_ptContainer.Fill(elec_1_p4->Pt(),weight,cutsVector);
        ljet0_ptContainer.Fill(ljet_0_p4->Pt(),weight,cutsVector);
        ljet1_ptContainer.Fill(ljet_1_p4->Pt(),weight,cutsVector);
        pt_balContainer.Fill(pt_bal,weight,cutsVector);
        mass_jjContainer.Fill(mjj,weight,cutsVector);
        n_jets_intervalContainer.Fill(n_jets_interval,weight,cutsVector);
        Z_centralityContainer.Fill(z_centrality,weight,cutsVector);
        inv_massContainer.Fill(inv_mass,weight,cutsVector);

        //  Filling histos
        lep1_etaContainer.Fill(elec_0_p4->Eta(),weight,cutsVector);
        lep2_etaContainer.Fill(elec_1_p4->Eta(),weight,cutsVector);
        delta_R_leplepContainer.Fill(elec_0_p4->DeltaR(*elec_1_p4),weight,cutsVector);
        delta_R_lep1jetContainer.Fill(min_dR_lep1,weight,cutsVector);
        delta_R_lep2jetContainer.Fill(min_dR_lep2,weight,cutsVector);
        sum_ptContainer.Fill(elec_0_p4->Pt()+elec_1_p4->Pt(),weight,cutsVector);
        metContainer.Fill(met_reco_p4->Pt(),weight,cutsVector);
        lep1_phiContainer.Fill(elec_0_p4->Phi(),weight,notFullCutsVector);
        lep2_phiContainer.Fill(elec_1_p4->Phi(),weight,notFullCutsVector);
        if(weight!=1){Z_pt_truthContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
        if(n_jets_interval==1){gap_jet_ptContainer.Fill(pt_gap_jet,weight,notFullCutsVector);}
        jet_nContainer.Fill(n_jets,weight,notFullCutsVector);
        Z_pt_recoContainer.Fill(Z_pt,weight,notFullCutsVector);
        ljet2_ptContainer.Fill(ljet_2_p4->Pt(),weight,notFullCutsVector);
        ljet0_etaContainer.Fill(ljet_0_p4->Eta(),weight,notFullCutsVector);
        ljet1_etaContainer.Fill(ljet_1_p4->Eta(),weight,notFullCutsVector);
        ljet2_etaContainer.Fill(ljet_2_p4->Eta(),weight,notFullCutsVector);
        vec_sum_pt_jetsContainer.Fill(jet_pt_sum,weight,notFullCutsVector);
        ratio_zpt_sumjetptContainer.Fill(ratio_zpt_sumjetpt,weight,notFullCutsVector);

        double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double anglejj = del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
        moreCentralJetContainer.Fill(etaMoreCentral,weight,notFullCutsVector);
        lessCentralJetContainer.Fill(etaLessCentral,weight,notFullCutsVector);
        delta_phijjContainer.Fill(anglejj,weight,notFullCutsVector);
        signedCentralityContainer.Fill(signed_z_centrality,weight,notFullCutsVector);
      }
    }
  }

void CLoop::Style(double lumFactor) {

  lep1_etaContainer.Write();
  lep2_etaContainer.Write();
  delta_R_leplepContainer.Write();
  delta_R_lep1jetContainer.Write();
  delta_R_lep2jetContainer.Write();
  sum_ptContainer.Write();
  metContainer.Write();
  lep1_phiContainer.Write();
  lep2_phiContainer.Write();
  jet_nContainer.Write();
  Z_pt_recoContainer.Write();
  ljet2_ptContainer.Write();
  ljet0_etaContainer.Write();
  ljet1_etaContainer.Write();
  ljet2_etaContainer.Write();
  vec_sum_pt_jetsContainer.Write();
  ratio_zpt_sumjetptContainer.Write();
  gap_jet_ptContainer.Write();
  signedCentralityContainer.Write();

  moreCentralJetContainer.Write();
  lessCentralJetContainer.Write();
  delta_phijjContainer.Write();

  delta_phiContainer.Write();
  delta_yContainer.Write();
  n_bjetsContainer.Write();
  lepisoContainer.Write();
  lep1_ptContainer.Write();
  lep2_ptContainer.Write();
  ljet0_ptContainer.Write();
  ljet1_ptContainer.Write();
  pt_balContainer.Write();
  mass_jjContainer.Write();
  n_jets_intervalContainer.Write();
  Z_centralityContainer.Write();
  inv_massContainer.Write();

  if (lumFactor!=1){
    Z_pt_truthContainer.Write();
  }
}

#endif // End header guard
