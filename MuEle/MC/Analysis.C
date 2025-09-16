// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include"../../AnalysisCommons/Tools.h"
#include "Selections.C"
#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#include <utility>

void CLoop::Book() {
  m_cutNames = Selections::InitCutNames(m_region);
  double pi=TMath::Pi();

  elecnu_ptContainer = histogramContainer("elecnu_pt","Lep + Neutrino pT",500,0,500,m_cutNames);
  muonnu_ptContainer = histogramContainer("muonnu_pt","Tau pT",500,0,500,m_cutNames);
  elec_etaContainer = histogramContainer("elec_eta","Lep eta",50,-2.5,2.5,m_cutNames);
  muon_etaContainer = histogramContainer("muon_eta","Tau eta",50,-2.5,2.5,m_cutNames);
  delta_R_muonelecContainer = histogramContainer("delta_R_muonelec","Delta R muon-elec",60,0,6,m_cutNames);
  delta_R_elecjetContainer = histogramContainer("delta_R_elecjet","Delta R elec-jet",60,0,6,m_cutNames);
  delta_R_muonjetContainer = histogramContainer("delta_R_muonjet","Delta R muon-jet",60,0,6,m_cutNames);
  sum_ptContainer = histogramContainer("sum_pt","Sum of electon and muon pT",800,0,800,m_cutNames);
  metContainer = histogramContainer("met","Missing Transverse momentum",500,0,500,m_cutNames);
  moreCentralJetContainer = histogramContainer("moreCentralJet","More central tagging jet",140,-7.0,7.0,notFull);
  lessCentralJetContainer = histogramContainer("lessCentralJet","Less central tagging jet",140,-7.0,7.0,notFull);
  normPtDifferenceContainer = histogramContainer("normPtDifference"," (mu-e)/(mu+e) pT ",200,-1.0,1.0,notFull);
  metToDilepnuRatioContainer = histogramContainer("metToDilepnuRatio","MET/(mu+e+neutrinos) pT",50,0,5.0,notFull);
  metToDilepRatioContainer = histogramContainer("metToDilepRatio","MET/(mu+e) pT",50,0,5.0,notFull);
  delta_phijjContainer = histogramContainer("delta_phijj","Delta phi between tagging jets",32,0,3.2,notFull);
  nuElecPtContainer = histogramContainer("nuElecPt","Neutrino electron side pT",200,0,200,notFull);
  nuMuonPtContainer = histogramContainer("nuMuonPt","Neutrino muon side pT",200,0,200,notFull);
  nuPtAssummetryContainer = histogramContainer("nuPtAssummetry","Neutrinos pT difference over sum",40,-1,1,notFull);
  massElecClosestJetContainer = histogramContainer("massElecClosestJet","Mass of electron and closest jet",2000,0,2000,notFull);
  massMuonClosestJetContainer = histogramContainer("massMuonClosestJet","Mass of muon and closest jet",2000,0,2000,notFull);
  massElecFurthestJetContainer = histogramContainer("massElecFurthestJet","Mass of electron and furthest jet",2000,0,2000,notFull);
  massMuonFurthestJetContainer = histogramContainer("massMuonFurthestJet","Mass of muon and furthest jet",2000,0,2000,notFull);
  flavourJet1Container = histogramContainer("flavourJet1","Jet1 truth flavour",50,-25,25,notFull);
  flavourJet2Container = histogramContainer("flavourJet2","Jet2 truth flavour",50,-25,25,notFull);
  nLightJetsContainer = histogramContainer("nLightJets","Number of light jets",4,0,4,notFull);

  elec_phiNotFullContainer = histogramContainer("elec_phi","Lep phi angle",64,-3.2,3.2,notFull);
  muon_phiNotFullContainer = histogramContainer("muon_phi","Tau phi angle",64,-3.2,3.2,notFull);
  jet_nNotFullContainer = histogramContainer("jet_n","Number of jets",10,0,10,notFull);
  Z_pt_reco_iNotFullContainer = histogramContainer("Z_pt_reco_i","ZpT in between events",1000,0,1000,notFull);
  Z_pt_reco_oNotFullContainer = histogramContainer("Z_pt_reco_o","ZpT outside events",1000,0,1000,notFull);
  ljet2_ptNotFullContainer = histogramContainer("ljet2_pt","Light jet2 pT",1000,0,1000,notFull);
  ljet3_ptNotFullContainer = histogramContainer("ljet3_pt","Light jet3 pT",1000,0,1000,notFull);
  gap_jet_ptNotFullContainer = histogramContainer("gap_jet_pt","Gap jet pT",1000,0,1000,notFull);
  ljet0_etaNotFullContainer = histogramContainer("ljet0_eta","Light jet0 eta",140,-7.0,7.0,notFull);
  ljet1_etaNotFullContainer = histogramContainer("ljet1_eta","Light jet1 eta",140,-7.0,7.0,notFull);
  ljet2_etaNotFullContainer = histogramContainer("ljet2_eta","Light jet2 eta",140,-7.0,7.0,notFull);
  gap_jet_etaNotFullContainer = histogramContainer("gap_jet_eta","Gap jet eta",140,-7.0,7.0,notFull);
  trans_mass_elecNotFullContainer = histogramContainer("trans_mass_elec","Transverse mass electon",150,0,150,notFull);
  trans_mass_muonNotFullContainer = histogramContainer("trans_mass_muon","Transverse mass muon",150,0,150,notFull);
  vec_sum_pt_jetsNotFullContainer = histogramContainer("vec_sum_pt_jets","Vector sum pT tagging jets",2000,0,2000,notFull);
  ratio_zpt_sumjetptNotFullContainer = histogramContainer("ratio_zpt_sumjetpt","Ratio ZpT over vector sum pT tagging jets",500,0,5,notFull);
  Z_pt_truth_iNotFullContainer = histogramContainer("Z_pt_truth_i","Truth ZpT in between events",1000,0,1000,notFull);
  Z_pt_truth_oNotFullContainer = histogramContainer("Z_pt_truth_o","Truth ZpT outside events",1000,0,1000,notFull);

  delta_phiContainer = histogramContainer("delta_phi","Delta phi between elec and muon",32,0,3.2,m_cutNames,"dphi");
  delta_yContainer = histogramContainer("delta_y","Delta Rapidity",100,0,10,m_cutNames,"drap");
  n_bjetsContainer = histogramContainer("n_bjets","Number of b_jets",5,0,5,m_cutNames,"btag");
  isoContainer = histogramContainer("iso","Lep Isolation",2,0,2,m_cutNames,"iso");
  elec_ptContainer = histogramContainer("elec_pt","Lep pT",500,0,500,m_cutNames,"ptl");
  muon_ptContainer = histogramContainer("muon_pt","Tau pT",500,0,500,m_cutNames,"tpt");
  ljet0_ptContainer = histogramContainer("ljet0_pt","Light jet0 pT",1000,0,1000,m_cutNames,"j1pt");
  ljet1_ptContainer = histogramContainer("ljet1_pt","Light jet1 pT",1000,0,1000,m_cutNames,"j2pt");
  pt_balContainer = histogramContainer("pt_bal","pT Balance",100,0,1,m_cutNames,"ptbal");
  mass_jjContainer = histogramContainer("mass_jj","Invariant mass di_jet system",5000,0,5000,m_cutNames,"mjj");
  n_jets_intervalContainer = histogramContainer("n_jets_interval","N jets between rapidity interval",10,0,10,m_cutNames,"nji");
  Z_centralityContainer = histogramContainer("Z_centrality","Z boson centrality",500,0,5,m_cutNames,"zcen");
  omegaContainer = histogramContainer("omega","Omega variable",60,-3.0,3.0,m_cutNames,"omega");
  reco_mass_iContainer = histogramContainer("reco_mass_i","Reconstructed mass in between events",1000,0,1000,m_cutNames,"mreco");
  reco_mass_oContainer = histogramContainer("reco_mass_o","Reconstructed mass outside events",1000,0,1000,m_cutNames,"mreco");
  reco_massContainer = histogramContainer("reco_mass_","Reconstructed mass all events",1000,0,1000,m_cutNames,"mreco");
  recoVisibleMassRatioContainer = histogramContainer("recoVisibleMassRatio","reco-visible mass ratio",100,0,10,notFull);
}

void CLoop::Fill(double weight, int z_sample, const std::string& sampleName) { // Muon is tau
  double pi=TMath::Pi();
  // Charges and lepton ID
  bool correctCharge = Kinematics::isChargeCorrect(m_region,elec_0_q,muon_0_q);
  bool muon_id = muon_0_id_medium;
  bool elec_id = elec_0_id_tight;
  size_t n_ljets = n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  // Trigger decision
  // Muon
  bool trigger_decision_mu= false;
  bool trigger_match_mu= false;
  if (run_number>= 276262 && run_number<=284484) {
    trigger_decision_mu= bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
    trigger_match_mu=bool(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50);
  } else {
    trigger_decision_mu= bool(HLT_mu26_ivarmedium | HLT_mu50);
    trigger_match_mu=bool(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50);
  }

  // Electron
  bool trigger_decision_e= false;
  bool trigger_match_e= false;
  if (run_number>= 276262 && run_number<=284484){
      trigger_decision_e=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
      trigger_match_e=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
  } else {
      trigger_decision_e=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
      trigger_match_e=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
  }

  // 0) Invariant mass of tagging jets.
  double mjj = Kinematics::Mass({ljet_0_p4, ljet_1_p4});

  if (correctCharge && n_muons==1 && n_electrons==1 && weight > -190 && elec_id && muon_id && n_ljets>=2 && n_ljets<=3 && mjj>=250 && ((trigger_decision_mu && trigger_match_mu) || (trigger_decision_e && trigger_match_e))){
    
    // Build the kinematic variables needed for the selections.
    
    // 1) Angles between the MET, Tau and Muon.
    double angle_elec_MET = Kinematics::del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
    double angle_muon_MET = Kinematics::del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
    double angle = Kinematics::del_phi(muon_0_p4->Phi(),elec_0_p4->Phi());

    // 2) Get the topology of the tau-tau system.
    Kinematics::TauTauTopology tauTauTopology = Kinematics::getTauTauTopology(angle_elec_MET, angle_muon_MET, angle);
    if (tauTauTopology == Kinematics::TauTauTopology::NOT_VALID) return;
    g_LOG(LogLevel::DEBUG, "This event passes the basic selection cuts.");

    // 3) Neutrino momentum
    TLorentzVector nu_muon_p4 = Kinematics::getTauNeutrino(tauTauTopology,met_reco_p4,muon_0_p4,elec_0_p4);
    TLorentzVector nu_elec_p4 = Kinematics::getLepNeutrino(tauTauTopology,met_reco_p4,muon_0_p4,elec_0_p4);

    // 4) Reconstructed mass
    double reco_mass = Kinematics::getRecoMass(tauTauTopology, muon_0_p4, elec_0_p4, &nu_muon_p4, &nu_elec_p4);
    double massMuonElec = Kinematics::Mass({muon_0_p4,elec_0_p4});

    // 5) ZpT and truth ZpT calculations
    double Z_pt = (*elec_0_p4 + *muon_0_p4 + nu_muon_p4 + nu_elec_p4).Pt();
    double truth_z_pt = (z_sample==1 || z_sample==2) ? truth_Z_p4->Pt()/1000 : Z_pt;

    // TRANSVERSE MASS LEPTON
    double elecmet_mass = Kinematics::TransverseMass(elec_0_p4, met_reco_p4);
    double muonmet_mass = Kinematics::TransverseMass(muon_0_p4, met_reco_p4);
    // Vector sum pT of the jets
    double jet_pt_sum = (*ljet_0_p4 + *ljet_1_p4).Pt();
    // Ratio ZpT/jet_pt_sum
    double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;

    // 6) Omega variable calculation
    double omega = Kinematics::getOmega(tauTauTopology, angle_elec_MET, angle_muon_MET, angle);

    // VBF-dedicated variables

    // 7) Delta rapidity between the tagging jets.
    double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());

    // 8) Number of jets in the rapidity interval between the tagging jets.
    std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
    std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};
    int n_jets_interval = Kinematics::getNumberOfGapJets(jet_container, is_jet_present);
  
    // 9) pT balance
    std::vector<TLorentzVector*> particles = {ljet_0_p4, ljet_1_p4, muon_0_p4, elec_0_p4, &nu_muon_p4, &nu_elec_p4};
    if (n_jets_interval==1) particles.push_back(ljet_2_p4);
    double pt_bal = Kinematics::getPtBalance(particles);

    // 10) Z boson centrality
    double signed_z_centrality = Kinematics::getSignedCentrality(ljet_0_p4, ljet_1_p4, muon_0_p4, elec_0_p4);
    double z_centrality = abs(signed_z_centrality);

    // 11) pT gap jet
    double pt_gap_jet = n_jets_interval == 1 ? ljet_2_p4->Pt() : 0.0;

    // Minimum DeltaR between leptons and jets
    double min_dR_muon = Kinematics::min_deltaR(muon_0_p4,is_jet_present,jet_container);
    double min_dR_elec = Kinematics::min_deltaR(elec_0_p4,is_jet_present,jet_container);

    double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
    double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
    double normPtDifference = (muon_0_p4->Pt()-elec_0_p4->Pt())/(muon_0_p4->Pt()+elec_0_p4->Pt());
    double anglejj = Kinematics::del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
    double metToDilepnuRatio = 0.0;
    double metToDilepRatio = met_reco_p4->Pt()/(muon_0_p4->Pt()+elec_0_p4->Pt());
    if (tauTauTopology == Kinematics::TauTauTopology::INSIDE)
    {
      metToDilepnuRatio = met_reco_p4->Pt()/(muon_0_p4->Pt()+nu_muon_p4.Pt()+elec_0_p4->Pt()+nu_elec_p4.Pt());
    }
    else
    {
      metToDilepnuRatio = met_reco_p4->Pt()/(muon_0_p4->Pt()+elec_0_p4->Pt()+nu_muon_p4.Pt()+nu_elec_p4.Pt());
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
    cutVars.lep1IsolationTight = muon_0_iso_TightTrackOnly_FixedRad;
    cutVars.lep1IsolationLoose = muon_0_iso_Loose_FixedRad;
    cutVars.lep2IsolationTight = elec_0_iso_FCTight;
    cutVars.lep2IsolationLoose = elec_0_iso_FCLoose;
    cutVars.lep1pT = elec_0_p4->Pt();
    cutVars.lep2pT = muon_0_p4->Pt();
    cutVars.jet1pT = ljet_0_p4->Pt();
    cutVars.jet2pT = ljet_1_p4->Pt();
    cutVars.mjj = mjj;
    cutVars.pTBalance = pt_bal;
    cutVars.nJetsInGap = n_jets_interval;
    cutVars.centrality = z_centrality;
    cutVars.omega = omega;
    cutVars.recoMass = reco_mass;
    cutVars.recoVisibleMassRatio = reco_mass/massMuonElec;

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
    recoVisibleMassRatioContainer.Fill(reco_mass/massMuonElec,weight,notFullCutsVector);
    if (tauTauTopology == Kinematics::TauTauTopology::INSIDE) {
        reco_mass_iContainer.Fill(reco_mass,weight,cutsVector);
        nuElecPtContainer.Fill(nu_elec_p4.Pt(),weight,notFullCutsVector);
        nuMuonPtContainer.Fill(nu_muon_p4.Pt(),weight,notFullCutsVector);
        nuPtAssummetryContainer.Fill((nu_elec_p4.Pt()+nu_muon_p4.Pt())/(elec_0_p4->Pt()+muon_0_p4->Pt()),weight,notFullCutsVector);
    }
    if (tauTauTopology == Kinematics::TauTauTopology::OUTSIDE_ELEC) {
        reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
        nuElecPtContainer.Fill(nu_elec_p4.Pt(),weight,notFullCutsVector);
        nuPtAssummetryContainer.Fill((nu_muon_p4.Pt()+nu_elec_p4.Pt())/(elec_0_p4->Pt()+muon_0_p4->Pt()),weight,notFullCutsVector);
    }
    if (tauTauTopology == Kinematics::TauTauTopology::OUTSIDE_MUON) {
        reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
        nuMuonPtContainer.Fill(nu_muon_p4.Pt(),weight,notFullCutsVector);
        nuPtAssummetryContainer.Fill((nu_muon_p4.Pt()+nu_elec_p4.Pt())/(elec_0_p4->Pt()+muon_0_p4->Pt()),weight,notFullCutsVector);
    }
    
    // HISTOGRAM FILLING STARTING IN BASIC SELECTION
    if (sampleName.substr(0,4)!="data"){
      if(tauTauTopology == Kinematics::TauTauTopology::INSIDE){Z_pt_truth_iNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
      else {Z_pt_truth_oNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
    }

    if (tauTauTopology == Kinematics::TauTauTopology::INSIDE){
      elecnu_ptContainer.Fill(elec_0_p4->Pt()+nu_elec_p4.Pt(),weight,cutsVector);
      muonnu_ptContainer.Fill(muon_0_p4->Pt()+nu_muon_p4.Pt(),weight,cutsVector);
      sum_ptContainer.Fill(muon_0_p4->Pt()+nu_elec_p4.Pt()+elec_0_p4->Pt()+nu_muon_p4.Pt(),weight,cutsVector);
      Z_pt_reco_iNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
    } else {
      elecnu_ptContainer.Fill(elec_0_p4->Pt()+nu_muon_p4.Pt()+nu_elec_p4.Pt(),weight,cutsVector);
      muonnu_ptContainer.Fill(muon_0_p4->Pt()+nu_muon_p4.Pt()+nu_elec_p4.Pt(),weight,cutsVector);
      sum_ptContainer.Fill(muon_0_p4->Pt()+elec_0_p4->Pt()+nu_muon_p4.Pt()+nu_elec_p4.Pt(),weight,cutsVector);
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