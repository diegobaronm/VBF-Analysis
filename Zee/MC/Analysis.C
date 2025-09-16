// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include"../../AnalysisCommons/Tools.h"
#include "Selections.C"
#include"../../AnalysisCommons/Kinematics.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#include <utility>

void CLoop::Book() {
  m_cutNames = Selections::InitCutNames(m_region);
  double pi=TMath::Pi();

  lep1_etaContainer = histogramContainer("lep1_eta","Lep1 eta",50,-2.5,2.5,m_cutNames);
  lep2_etaContainer = histogramContainer("lep2_eta","Lep2 eta",50,-2.5,2.5,m_cutNames);
  delta_R_leplepContainer = histogramContainer("delta_R_leplep","Delta R lep-lep",60,0,6,m_cutNames);
  delta_R_lep1jetContainer = histogramContainer("delta_R_lep1jet","Delta R lep1-jet",60,0,6,m_cutNames);
  delta_R_lep2jetContainer = histogramContainer("delta_R_lep2jet","Delta R lep2-jet",60,0,6,m_cutNames);
  sum_ptContainer = histogramContainer("sum_pt","Sum of leptons pT",800,0,800,m_cutNames);
  metContainer = histogramContainer("met","Missing Transverse momentum",500,0,500,m_cutNames);
  moreCentralJetContainer = histogramContainer("moreCentralJet","More central tagging jet",140,-7.0,7.0,notFull);
  lessCentralJetContainer = histogramContainer("lessCentralJet","Less central tagging jet",140,-7.0,7.0,notFull);
  delta_phijjContainer = histogramContainer("delta_phijj","Delta phi between tagging jets",32,0,3.2,notFull);
  signedCentralityContainer = histogramContainer("signedCentrality","Z boson signed centrality",400,-2,2,notFull);

  lep1_phiContainer = histogramContainer("lep1_phi","Lep1 phi angle",64,-3.2,3.2,notFull);
  lep2_phiContainer = histogramContainer("lep2_phi","Lep2 phi angle",64,-3.2,3.2,notFull);
  jet_nContainer = histogramContainer("jet_n","Number of jets",10,0,10,notFull);
  Z_pt_recoContainer = histogramContainer("Z_pt_reco","ZpT",1000,0,1000,notFull);
  ljet2_ptContainer = histogramContainer("ljet2_pt","Light jet2 pT",1000,0,1000,notFull);
  gap_jet_ptContainer = histogramContainer("gap_jet_pt","Gap jet pT",1000,0,1000,notFull);
  ljet0_etaContainer = histogramContainer("ljet0_eta","Light jet0 eta",140,-7.0,7.0,notFull);
  ljet1_etaContainer = histogramContainer("ljet1_eta","Light jet1 eta",140,-7.0,7.0,notFull);
  ljet2_etaContainer = histogramContainer("ljet2_eta","Light jet2 eta",140,-7.0,7.0,notFull);
  gap_jet_etaContainer = histogramContainer("gap_jet_eta","Gap jet eta",140,-7.0,7.0,notFull);
  vec_sum_pt_jetsContainer = histogramContainer("vec_sum_pt_jets","Vector sum pT tagging jets",2000,0,2000,notFull);
  ratio_zpt_sumjetptContainer = histogramContainer("ratio_zpt_sumjetpt","Ratio ZpT over vector sum pT tagging jets",500,0,5,notFull);
  Z_pt_truthContainer = histogramContainer("Z_pt_truth","Truth ZpT",1000,0,1000,notFull);

  delta_phiContainer = histogramContainer("delta_phi","Delta phi between leptons",32,0,3.2,m_cutNames,"dphi");
  delta_yContainer = histogramContainer("delta_y","Delta Rapidity",100,0,10,m_cutNames,"drap");
  n_bjetsContainer = histogramContainer("n_bjets","Number of b_jets",5,0,5,m_cutNames,"btag");
  lepisoContainer = histogramContainer("lepiso","Leptons isolation",2,0,2,m_cutNames,"iso");
  lep1_ptContainer = histogramContainer("lep1_pt","Lep 1 pT",500,0,500,m_cutNames,"pt1");
  lep2_ptContainer = histogramContainer("lep2_pt","Lep 2 pT",500,0,500,m_cutNames,"pt2");
  ljet0_ptContainer = histogramContainer("ljet0_pt","Light jet0 pT",1000,0,1000,m_cutNames,"j1pt");
  ljet1_ptContainer = histogramContainer("ljet1_pt","Light jet1 pT",1000,0,1000,m_cutNames,"j2pt");
  pt_balContainer = histogramContainer("pt_bal","pT Balance",100,0,1,m_cutNames,"ptbal");
  mass_jjContainer = histogramContainer("mass_jj","Invariant mass di_jet system",5000,0,5000,m_cutNames,"mjj");
  n_jets_intervalContainer = histogramContainer("n_jets_interval","N jets between rapidity interval",5,0,5,m_cutNames,"nji");
  Z_centralityContainer = histogramContainer("Z_centrality","Z boson centrality",350,0,3.5,m_cutNames,"zcen");
  inv_massContainer = histogramContainer("inv_mass","Invariant mass di-lepton system",1000,0,1000,m_cutNames,"mass");

  sum_of_weights_store = std::make_unique<TH1F>("sum_of_weights_store","Sum of weights",2,0,2);
}

void CLoop::Fill(double weight, int z_sample, const std::string& sampleName) {
  double pi=TMath::Pi();
  // Charges and lepton ID
  bool correctCharge = Kinematics::isChargeCorrect(m_region,elec_0_q,elec_1_q);
  bool elec_id = elec_0_id_tight && elec_1_id_tight;
  std::size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  // Trigger decision
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
    if(sampleName.substr(0,4)!="data"){
      if (trigger_match_1){weight=weight*elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
      if (trigger_match_2){weight=weight*elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
    }
    trigger_match = trigger_match_1 | trigger_match_2 | trigger_match_12;
  } else {
    trigger_decision = bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
    trigger_match_1 = bool((eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && !(eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
    trigger_match_2 = bool(!(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && (eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
    trigger_match_12 = bool((eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0) && (eleTrigMatch_1_HLT_e120_lhloose | eleTrigMatch_1_HLT_e140_lhloose_nod0 | eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_1_HLT_e60_lhmedium | eleTrigMatch_1_HLT_e60_lhmedium_nod0));
    if(sampleName.substr(0,4)!="data"){
      if (trigger_match_1){weight=weight*elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
      if (trigger_match_2){weight=weight*elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;}
    }
    trigger_match = trigger_match_1 | trigger_match_2 | trigger_match_12;
  }

  // 0) Invariant mass of tagging jets.
  double mjj = Kinematics::Mass({ljet_0_p4, ljet_1_p4});
  double mll = Kinematics::Mass({elec_0_p4, elec_1_p4});

  bool fiducial_selection = n_ljets>=2 && n_electrons==2 
                            && trigger_decision && trigger_match
                            && mjj>=500 && mll>=60 && correctCharge 
                            && ljet_0_p4->Pt() > 25 && ljet_1_p4->Pt() > 25
                            && elec_0_p4->Pt() > 27 && elec_1_p4->Pt() > 27;
  Tools::RecordTotalWeightsAndAfterCut(sum_of_weights_store, weight_mc, fiducial_selection);

  // Prevent high PileUPRW events.
  bool goodPUW = true;
  if(sampleName.substr(0,4) == "data") goodPUW = true; // This is just to be explicit that this should not affect the data.
  else goodPUW = NOMINAL_pileup_combined_weight > -10;

  if (correctCharge && n_electrons==2 && elec_id  && n_ljets>=2 && n_ljets<=3 && goodPUW && mjj>=250 && mll >=40 && trigger_decision && trigger_match){
    g_LOG(LogLevel::DEBUG, "This event passes the basic selection cuts.");
    // Build the kinematic variables needed for the selections.

    // 1) Angles between the leptons.
    double angle = Kinematics::del_phi(elec_1_p4->Phi(),elec_0_p4->Phi());

    // 4) Invariant mass of the di-lepton system.
    double inv_mass = Kinematics::Mass({elec_0_p4, elec_1_p4});

    // 3) ZpT and truth ZpT calculations
    double Z_pt = (*elec_0_p4 + *elec_1_p4).Pt();
    double truth_z_pt = (z_sample==1 || z_sample==2) ? truth_Z_p4->Pt()/1000 : Z_pt;

    // Vector sum pT of the jets
    double jet_pt_sum= (*ljet_0_p4 + *ljet_1_p4).Pt();
    // Ratio ZpT/jet_pt_sum
    double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;

    // VBF-dedicated variables

    // 4) Delta rapidity between the tagging jets.
    double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());

    // 5) Number of jets in the rapidity interval between the tagging jets.
    std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
    std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};
    int n_jets_interval = Kinematics::getNumberOfGapJets(jet_container, is_jet_present);
  
    // 6) pT balance
    std::vector<TLorentzVector*> particles = {ljet_0_p4, ljet_1_p4, elec_0_p4, elec_1_p4};
    if (n_jets_interval==1) particles.push_back(ljet_2_p4);
    double pt_bal = Kinematics::getPtBalance(particles);

    // 7) Z boson centrality
    double signed_z_centrality = Kinematics::getSignedCentrality(ljet_0_p4, ljet_1_p4, elec_0_p4, elec_1_p4);
    double z_centrality = abs(signed_z_centrality);

    // 8) pT gap jet
    double pt_gap_jet = n_jets_interval == 1 ? ljet_2_p4->Pt() : 0.0;

    // Minimum DeltaR between lepton and jets
    double min_dR_lep1 = Kinematics::min_deltaR(elec_0_p4,is_jet_present,jet_container);
    double min_dR_lep2 = Kinematics::min_deltaR(elec_1_p4,is_jet_present,jet_container);

    // Definition of the superCR = CR(a+b+c)
    Region region = Kinematics::getRegion(z_centrality, n_jets_interval);
    bool superCR = (region == Region::CRa) || (region == Region::CRb) || (region == Region::CRc);

    // ONLY SUPER CR
    //if (!superCR) return;

    // Cuts 
    // First initialise the variables used for the cutflow
    Kinematics::VariablesForCutflow cutVars{};
    cutVars.deltaPhiLepLep = angle;
    cutVars.deltaRapidityTaggingJets = delta_y;
    cutVars.nBJets = n_bjets_MV2c10_FixedCutBEff_85;
    cutVars.lep1IsolationTight = elec_0_iso_FCTight;
    cutVars.lep1IsolationLoose = elec_0_iso_FCLoose;
    cutVars.lep2IsolationTight = elec_1_iso_FCTight;
    cutVars.lep2IsolationLoose = elec_1_iso_FCLoose;
    cutVars.lep1pT = elec_0_p4->Pt();
    cutVars.lep2pT = elec_1_p4->Pt();
    cutVars.jet1pT = ljet_0_p4->Pt();
    cutVars.jet2pT = ljet_1_p4->Pt();
    cutVars.pTBalance = pt_bal;
    cutVars.mjj = mjj;
    cutVars.nJetsInGap = n_jets_interval;
    cutVars.centrality = z_centrality;
    cutVars.massLeptonLepton = inv_mass;
    cutVars.eventNumber = event_number;

    // Apply cuts 
    std::vector<int> cuts = Selections::ApplySelection(m_region, cutVars);
    if ((m_cutNames.size() - 1) != cuts.size()){
        g_LOG(LogLevel::ERROR, "The number of cuts is not consistent with the number of cut names.");
        exit(1);
    }

    // Calculate if the event passed all cuts
    std::vector<int> cutsVector{1};
    cutsVector.insert(cutsVector.end(),cuts.begin(),cuts.end());
    bool passedAllCuts = Tools::passedAllCuts(cutsVector);
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
    if(sampleName.substr(0,4)!="data"){Z_pt_truthContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
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
    double anglejj = Kinematics::del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
    moreCentralJetContainer.Fill(etaMoreCentral,weight,notFullCutsVector);
    lessCentralJetContainer.Fill(etaLessCentral,weight,notFullCutsVector);
    delta_phijjContainer.Fill(anglejj,weight,notFullCutsVector);
    signedCentralityContainer.Fill(signed_z_centrality,weight,notFullCutsVector);
    
  }
}

void CLoop::Style(double lumFactor) {
  sum_of_weights_store->Write();
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
