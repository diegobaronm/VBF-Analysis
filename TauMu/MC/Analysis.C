// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include"backend/CLoop.h"
#include"../../AnalysisCommons/Tools.h" 
#include <vector>
#include <TMVA/Reader.h>
#include <algorithm>
//#include <bits/stdc++.h>
#include <utility>

void CLoop::Book() {
  m_cutNames = InitCutNames(m_region);
  double pi=TMath::Pi();

  trueMass_2D_lepTransMass_basic_all = new TH2F("trueMass_2D_lepTransMass_basic_all","trueMass Vs lepton transverse mass",1000,0,1000,50,0,500);
  trueMass_2D_transverseRecoMassRatio_basic_all = new TH2F("trueMass_2D_transverseRecoMassRatio_basic_all","trueMass Vs transverse-reco mass ratio",1000,0,1000,200,0.0,2.0);
  lepnu_ptContainer = histogramContainer("lepnu_pt","Lep + Neutrino pT",500,0,500,m_cutNames);
  taunu_ptContainer = histogramContainer("taunu_pt","Tau pT",500,0,500,m_cutNames);
  lep_etaContainer = histogramContainer("lep_eta","Lep eta",50,-2.5,2.5,m_cutNames);
  tau_etaContainer = histogramContainer("tau_eta","Tau eta",50,-2.5,2.5,m_cutNames);
  delta_R_taulepContainer = histogramContainer("delta_R_taulep","Delta R tau-lep",60,0,6,m_cutNames);
  delta_R_lepjetContainer = histogramContainer("delta_R_lepjet","Delta R lep-jet",60,0,6,m_cutNames);
  delta_R_taujetContainer = histogramContainer("delta_R_taujet","Delta R tau-jet",60,0,6,m_cutNames);
  sum_ptContainer = histogramContainer("sum_pt","Sum of lepton and tau pT",800,0,800,m_cutNames);
  moreCentralJetContainer = histogramContainer("moreCentralJet","More central tagging jet",140,-7.0,7.0,notFull);
  lessCentralJetContainer = histogramContainer("lessCentralJet","Less central tagging jet",140,-7.0,7.0,notFull);
  normPtDifferenceContainer = histogramContainer("normPtDifference"," (tau-mu)/(tau+mu) pT ",200,-1.0,1.0,notFull);
  metToDilepnuRatioContainer = histogramContainer("metToDilepnuRatio","MET/(tau+mu+neutrinos) pT",50,0,5.0,notFull);
  metToDilepRatioContainer = histogramContainer("metToDilepRatio","MET/(tau+mu) pT",50,0,5.0,notFull);
  delta_phijjContainer = histogramContainer("delta_phijj","Delta phi between tagging jets",32,0,3.2,notFull);
  massTauClosestJetContainer = histogramContainer("massTauClosestJet","Mass of tau and closest jet",2000,0,2000,notFull);
  massTauFurthestJetContainer = histogramContainer("massTauFurthestJet","Mass of tau and furthest jet",2000,0,2000,notFull);
  nuPtAssummetryContainer = histogramContainer("nuPtAssummetry","Neutrinos pT difference over sumn",40,-1,1,notFull);
  massLepClosestJetContainer = histogramContainer("massLepClosestJet","Mass of lep and closest jet",2000,0,2000,notFull);
  flavourJet1Container = histogramContainer("flavourJet1","Jet1 truth flavour",50,-25,25,notFull);
  flavourJet2Container = histogramContainer("flavourJet2","Jet2 truth flavour",50,-25,25,notFull);
  nLightJetsContainer = histogramContainer("nLightJets","Number of light jets",4,0,4,notFull);
  muonPdgIDContainer = histogramContainer("muonPdgID","Muon truth pdgID",50,-25,25,notFull);
  tauPdgIDContainer = histogramContainer("tauPdgID","Tau truth pdgID",50,-25,25,notFull);
  signedCentralityContainer = histogramContainer("signedCentrality","Z boson signed centrality",400,-2,2,notFull);

  lep_phiNotFullContainer = histogramContainer("lep_phi","Lep phi angle",64,-3.2,3.2,notFull);
  tau_phiNotFullContainer = histogramContainer("tau_phi","Tau phi angle",64,-3.2,3.2,notFull);
  tau_nprongsNotFullContainer = histogramContainer("tau_nprongs","Tau prongness",4,0,4,notFull);
  jet_nNotFullContainer = histogramContainer("jet_n","Number of jets",10,0,10,notFull);
  Z_pt_reco_iNotFullContainer = histogramContainer("Z_pt_reco_i","ZpT in between events",1000,0,1000,notFull);
  Z_pt_reco_oNotFullContainer = histogramContainer("Z_pt_reco_o","ZpT outside events",1000,0,1000,notFull);
  n_fake_tracksNotFullContainer = histogramContainer("n_fake_tracks","Number of fake tracks",40,0,40,notFull);
  n_core_tracksNotFullContainer = histogramContainer("n_core_tracks","Number of core tracks",40,0,40,notFull);
  n_iso_tracksNotFullContainer = histogramContainer("n_iso_tracks","Number of isolation tracks",40,0,40,notFull);
  n_tracksNotFullContainer = histogramContainer("n_tracks","Number of all tracks",40,0,40,notFull);
  ljet2_ptNotFullContainer = histogramContainer("ljet2_pt","Light jet2 pT",1000,0,1000,notFull);
  ljet3_ptNotFullContainer = histogramContainer("ljet3_pt","Light jet3 pT",1000,0,1000,notFull);
  gap_jet_ptNotFullContainer = histogramContainer("gap_jet_pt","Gap jet pT",1000,0,1000,notFull);
  ljet0_etaNotFullContainer = histogramContainer("ljet0_eta","Light jet0 eta",140,-7.0,7.0,notFull);
  ljet1_etaNotFullContainer = histogramContainer("ljet1_eta","Light jet1 eta",140,-7.0,7.0,notFull);
  ljet2_etaNotFullContainer = histogramContainer("ljet2_eta","Light jet2 eta",140,-7.0,7.0,notFull);
  gap_jet_etaNotFullContainer = histogramContainer("gap_jet_eta","Gap jet eta",140,-7.0,7.0,notFull);
  vec_sum_pt_jetsNotFullContainer = histogramContainer("vec_sum_pt_jets","Vector sum pT tagging jets",2000,0,2000,notFull);
  ratio_zpt_sumjetptNotFullContainer = histogramContainer("ratio_zpt_sumjetpt","Ratio ZpT over vector sum pT tagging jets",500,0,5,notFull);
  tau_matched_1pNotFullContainer = histogramContainer("tau_matched_1p","Tau truth matched 1 prong",2,0,2,notFull);
  tau_matched_3pNotFullContainer = histogramContainer("tau_matched_3p","Tau truth matched 3 prong",2,0,2,notFull);
  Z_pt_truth_iNotFullContainer = histogramContainer("Z_pt_truth_i","Truth ZpT in between events",1000,0,1000,notFull);
  Z_pt_truth_oNotFullContainer = histogramContainer("Z_pt_truth_o","Truth ZpT outside events",1000,0,1000,notFull);

  trueMassContainer = histogramContainer("true_mass","True mass tau-tau",1000,0,1000,notFull);
  recoTrueMassRatioContainer = histogramContainer("recoTrueMassRatio","reco-true mass ratio",100,0,10,notFull);
  recoVisibleMassRatioContainer = histogramContainer("recoVisibleMassRatio","reco-visible mass ratio",100,0,10,m_cutNames,"rvr");
  visibleMassContainer = histogramContainer("visibleMass","Visible mass tau-lep",1000,0,1000,notFull);
  taunuptContainer = histogramContainer("nuTauPt","Neutrino tau side pT",200,0,200,m_cutNames,"taunupt");
  lepnuptContainer = histogramContainer("lepNuPt","Lepton neutrino pT",200,0,200,m_cutNames,"lepnupt");
  ptsymContainer = histogramContainer("pTsymmetry","Lepton-tau pT normalised difference",200,-1,1,m_cutNames,"ptsym");  
  bdtContainer = histogramContainer("bdtScore","BDT Score",200,-1,1,m_cutNames,"mva");
  delta_phiContainer = histogramContainer("delta_phi","Delta phi between tau and lep",32,0,3.2,m_cutNames,"dphi");
  delta_yContainer = histogramContainer("delta_y","Delta Rapidity",100,0,10,m_cutNames,"drap");
  n_bjetsContainer = histogramContainer("n_bjets","Number of b_jets",5,0,5,m_cutNames,"btag");
  lepisoContainer = histogramContainer("lepiso","Lep Isolation",2,0,2,m_cutNames,"iso");
  rnn_score_1pContainer = histogramContainer("rnn_score_1p","RNN Score 1 prong taus",100,0,1,m_cutNames,"rnn");
  rnn_score_3pContainer = histogramContainer("rnn_score_3p","RNN Score 3 prong taus",100,0,1,m_cutNames,"rnn");
  lep_ptContainer = histogramContainer("lep_pt","Lep pT",500,0,500,m_cutNames,"ptl");
  tau_ptContainer = histogramContainer("tau_pt","Tau pT",500,0,500,m_cutNames,"tpt");
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
  metContainer = histogramContainer("met","Missing Transverse momentum",500,0,500,m_cutNames,"met");
  lepTransMassContainer = histogramContainer("lepTransMass","Transverse mass lepton",500,0,500,notFull);
  tauTransMassContainer = histogramContainer("tauTransMass","Transverse mass tau",500,0,500,notFull);
  transMassSumContainer = histogramContainer("transMassSum","Transverse mass sum",1000,0,1000,notFull);
  transMassRatioContainer = histogramContainer("transMassRatio","Transverse mass ratio",200,-1.0,1.0,notFull);
  transMassRecoMassRatioContainer = histogramContainer("transMassRecoMassRatio","Transverse mass - reco mass ratio",200,0.0,2.0,notFull);
  transMassRecoMassRatio66to116Container = histogramContainer("transMassRecoMassRatio66to116","Transverse mass - reco mass ratio 66 to 116 GeV",200,0.0,2.0,notFull);
  transMassRecoMassRatio116to160Container = histogramContainer("transMassRecoMassRatio116to160","Transverse mass - reco mass ratio 116 to 160 GeV",200,0.0,2.0,notFull);
  transMassRecoMassRatio160to400Container = histogramContainer("transMassRecoMassRatio160to400","Transverse mass - reco mass ratio 160 to 400 GeV",200,0.0,2.0,notFull);
  transMassRecoMassRatio400toContainer = histogramContainer("transMassRecoMassRatio400to","Transverse mass - reco mass ratio 400 up GeV",200,0.0,2.0,notFull);
}

void CLoop::Fill(double weight, int z_sample, const std::string& sampleName) {
  double pi=TMath::Pi();
  // Charges and lepton ID
  bool correctCharge = Kinematics::isChargeCorrect(m_region,muon_0_q,tau_0_q);
  bool lepton_id=muon_0_id_medium;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  // Trigger decision
    bool trigger_decision= false;
    bool trigger_match= false;
    if (run_number>= 276262 && run_number<=284484) {
      trigger_decision= bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
      trigger_match=bool(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50);
    } else {
      trigger_decision= bool(HLT_mu26_ivarmedium | HLT_mu50);
      trigger_match=bool(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50);
    }

  // 0) Invariant mass of tagging jets.
  double mjj = Kinematics::Mass({ljet_0_p4, ljet_1_p4});

  if (correctCharge && n_muons==1 && n_taus_rnn_loose>=1 && weight > -190 && lepton_id && n_ljets>=2 && n_ljets<=3 && mjj>=250 && trigger_decision  && trigger_match && abs(tau_0_p4->Eta())>=0.1){
    
    // Build the kinematic variables needed for the selections.
    
    // 1) Angles between the MET, Tau and Muon.
    double angle_l_MET = Kinematics::del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
    double angle_tau_MET = Kinematics::del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
    double angle = Kinematics::del_phi(tau_0_p4->Phi(),muon_0_p4->Phi());

    // 2) Get the topology of the tau-tau system.
    Kinematics::TauTauTopology tauTauTopology = Kinematics::getTauTauTopology(angle_l_MET, angle_tau_MET, angle);
    if (tauTauTopology == Kinematics::TauTauTopology::NOT_VALID) return;
    g_LOG(LogLevel::DEBUG, "This event passes the basic selection cuts.");

    // 3) Neutrino momentum
    TLorentzVector nu_tau_p4 = Kinematics::getTauNeutrino(tauTauTopology,met_reco_p4,tau_0_p4,muon_0_p4);
    TLorentzVector nu_lep_p4 = Kinematics::getLepNeutrino(tauTauTopology,met_reco_p4,tau_0_p4,muon_0_p4);

    // 4) Reconstructed mass
    double reco_mass = Kinematics::getRecoMass(tauTauTopology, tau_0_p4, muon_0_p4, &nu_tau_p4, &nu_lep_p4);

    // 5) ZpT and truth ZpT calculations
    double Z_pt = (*muon_0_p4 + *tau_0_p4 + nu_tau_p4 + nu_lep_p4).Pt();
    double truth_z_pt = (z_sample==1 || z_sample==2) ? truth_Z_p4->Pt()/1000 : Z_pt;

    // LEP-TAU INVARIANT MASS
    double inv_taulep = Kinematics::Mass({muon_0_p4,tau_0_p4});
    // Vector sum pT of the jets
    double jet_pt_sum = (*ljet_0_p4 + *ljet_1_p4).Pt();
    // Ratio ZpT/jet_pt_sum
    double ratio_zpt_sumjetpt = Z_pt/jet_pt_sum;

    // 6) Omega variable calculation
    double omega = Kinematics::getOmega(tauTauTopology, angle_l_MET, angle_tau_MET, angle);


    // VBF-dedicated variables

    // 7) Delta rapidity between the tagging jets.
    double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());
    
    // 8) Number of jets in the rapidity interval between the tagging jets.
    std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
    std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};
    int n_jets_interval = Kinematics::getNumberOfGapJets(jet_container, is_jet_present);

    // 9) pT balance
    std::vector<TLorentzVector*> particles = {ljet_0_p4, ljet_1_p4, tau_0_p4, muon_0_p4, &nu_tau_p4, &nu_lep_p4};
    if (n_jets_interval==1) particles.push_back(ljet_2_p4);
    double pt_bal = Kinematics::getPtBalance(particles);

    // 10) Z boson centrality
    double signed_z_centrality = Kinematics::getSignedCentrality(ljet_0_p4, ljet_1_p4, tau_0_p4, muon_0_p4);
    double z_centrality = abs(signed_z_centrality);

    // 11) pT gap jet
    double pt_gap_jet = n_jets_interval == 1 ? ljet_2_p4->Pt() : 0.0;

    // Minimum DeltaR between lepton and jets
    double min_dR_tau = Kinematics::min_deltaR(tau_0_p4,is_jet_present,jet_container);
    double min_dR_lep = Kinematics::min_deltaR(muon_0_p4,is_jet_present,jet_container);

    // More kinematic variables
    double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
    double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
    double normPtDifference = (tau_0_p4->Pt()-muon_0_p4->Pt())/(tau_0_p4->Pt()+muon_0_p4->Pt());
    double anglejj = Kinematics::del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
    double metToDilepRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt());
    double metToDilepnuRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+nu_tau_p4.Pt()+muon_0_p4->Pt()+nu_lep_p4.Pt());

    double massTauCloserJet{0.0};
    double massLepClosestJet{0.0};
    double massTauFurthestJet{0.0};
    bool j0CloserToTau = tau_0_p4->DeltaR(*ljet_0_p4) <= tau_0_p4->DeltaR(*ljet_1_p4);
    if (j0CloserToTau)
    {
      massTauCloserJet = sqrt(2*(tau_0_p4->Dot(*ljet_0_p4)));
      massTauFurthestJet = sqrt(2*(tau_0_p4->Dot(*ljet_1_p4)));
      massLepClosestJet = sqrt(2*(muon_0_p4->Dot(*ljet_1_p4)));
    }
    else
    {
      massTauCloserJet = sqrt(2*(tau_0_p4->Dot(*ljet_1_p4)));
      massTauFurthestJet = sqrt(2*(tau_0_p4->Dot(*ljet_0_p4)));
      massLepClosestJet = sqrt(2*(muon_0_p4->Dot(*ljet_0_p4)));
    }

    // Transverse mass
    double transverseMassLep = Kinematics::TransverseMass(muon_0_p4,met_reco_p4);
    double transverseMassTau = Kinematics::TransverseMass(tau_0_p4,met_reco_p4);
    double transverseMassSum = transverseMassTau + transverseMassLep;
    double transverseMassRatio = (transverseMassTau - transverseMassLep)/transverseMassSum;

    // Handling BDT
    float bdt_transmasslep = reco_mass > 200 ? transverseMassLep/std::pow(reco_mass,0.3) : transverseMassLep/std::pow(200,0.3); // for transverse-reco mass ratio
    m_vbfBDT.update(mjj, delta_y, pt_bal, z_centrality, omega, bdt_transmasslep, event_number);
    double VBFBDT_score = m_vbfBDT.evaluate();

    // Truth studies
    TLorentzVector truth_lep_p4{};
    double trueMass{};
    double recoTrueMassRatio{};
    if (sampleName.find("truth")!=std::string::npos){
      truth_lep_p4 = (*taulep_0_truth_invis_p4)+(*taulep_0_truth_vis_p4);
      trueMass = sqrt(2*(truth_lep_p4*(*tau_0_truth_total_p4)));
      recoTrueMassRatio = trueMass==0.0 ? 0.0 : reco_mass/trueMass;
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
    cutVars.nTauProngs = tau_0_n_charged_tracks;
    cutVars.tauJetRNNScore = tau_0_jet_rnn_score_trans;
    cutVars.lep1pT = muon_0_p4->Pt();
    cutVars.taupT = tau_0_p4->Pt();
    cutVars.jet1pT = ljet_0_p4->Pt();
    cutVars.jet2pT = ljet_1_p4->Pt();
    cutVars.mjj = mjj;
    cutVars.pTBalance = pt_bal;
    cutVars.nJetsInGap = n_jets_interval;
    cutVars.centrality = z_centrality;
    cutVars.omega = omega;
    cutVars.recoMass = reco_mass;
    cutVars.vbfBDTScore = VBFBDT_score;
    cutVars.lepPtAssymetry = normPtDifference;
    cutVars.recoVisibleMassRatio = reco_mass/inv_taulep;
  
    // Apply cuts 
    std::vector<int> cuts = ApplySelection(m_region, cutVars);
    if ((m_cutNames.size() - 1) != cuts.size()){
        g_LOG(LogLevel::ERROR, "The number of cuts is not consistent with the number of cut names.");
        exit(1);
    }

    // Calculate if the event passed all cuts
    std::vector<int> cutsVector{1};
    cutsVector.insert(cutsVector.end(),cuts.begin(),cuts.end());
    bool passedAllCuts = Tools::passedAllCuts(cutsVector);
    std::vector<int> notFullCutsVector{1,static_cast<int>(passedAllCuts)};

    // Blind H-M region
    std::vector<int> cutsSignalRegion = ApplySelection("HighMass", cutVars);
    bool signalRegion = Tools::passedAllCuts(cutsSignalRegion);

    if (sampleName.substr(0,4)=="data" && signalRegion && Kinematics::isChargeCorrect("OS",muon_0_q,tau_0_q)) return;

    bool MJCR = (tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans < 0.25) || (tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans < 0.40) || (muon_0_iso_TightTrackOnly_FixedRad==0);
    bool failedMVA = (VBFBDT_score <= 0.3) || (normPtDifference <= -0.3) || (reco_mass/inv_taulep >= 4.0) || (tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans < 0.25) || (tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans < 0.40);
    //if (sampleName.substr(0,4)=="data" && !MJCR) return;

    // Fill the histograms
    if (passedAllCuts) trueMass_2D_lepTransMass_basic_all->Fill(trueMass,transverseMassLep,weight);
    if (passedAllCuts) trueMass_2D_transverseRecoMassRatio_basic_all->Fill(trueMass,transverseMassLep/reco_mass,weight);
    lep_ptContainer.Fill(muon_0_p4->Pt(),weight,cutsVector);
    tau_ptContainer.Fill(tau_0_p4->Pt(),weight,cutsVector);
    omegaContainer.Fill(omega,weight,cutsVector);
    n_bjetsContainer.Fill(n_bjets_MV2c10_FixedCutBEff_85,weight,cutsVector);
    lepisoContainer.Fill(muon_0_iso_TightTrackOnly_FixedRad,weight,cutsVector);
    delta_phiContainer.Fill(angle,weight,cutsVector);
    delta_yContainer.Fill(delta_y,weight,cutsVector);
    Z_centralityContainer.Fill(z_centrality,weight,cutsVector);
    pt_balContainer.Fill(pt_bal,weight,cutsVector);
    mass_jjContainer.Fill(mjj,weight,cutsVector);
    n_jets_intervalContainer.Fill(n_jets_interval,weight,cutsVector);
    ljet0_ptContainer.Fill(ljet_0_p4->Pt(),weight,cutsVector);
    ljet1_ptContainer.Fill(ljet_1_p4->Pt(),weight,cutsVector);
    reco_massContainer.Fill(reco_mass,weight,cutsVector);
    bdtContainer.Fill(VBFBDT_score,weight,cutsVector);
    ptsymContainer.Fill(normPtDifference,weight,cutsVector);
    muonPdgIDContainer.Fill(muon_0_matched_pdgId,weight,notFullCutsVector);
    tauPdgIDContainer.Fill(tau_0_truth_pdgId,weight,notFullCutsVector);
    signedCentralityContainer.Fill(signed_z_centrality,weight,notFullCutsVector);
    visibleMassContainer.Fill(inv_taulep,weight,notFullCutsVector);
    recoVisibleMassRatioContainer.Fill(reco_mass/inv_taulep,weight,cutsVector);
    recoTrueMassRatioContainer.Fill(recoTrueMassRatio,weight,notFullCutsVector);
    trueMassContainer.Fill(trueMass,weight,notFullCutsVector);
    
    lepTransMassContainer.Fill(transverseMassLep,weight,notFullCutsVector);
    tauTransMassContainer.Fill(transverseMassTau,weight,notFullCutsVector);
    transMassSumContainer.Fill(transverseMassSum,weight,notFullCutsVector);
    transMassRatioContainer.Fill(transverseMassRatio,weight,notFullCutsVector);
    transMassRecoMassRatioContainer.Fill(transverseMassLep/reco_mass,weight,notFullCutsVector);
    if (reco_mass>=400) transMassRecoMassRatio400toContainer.Fill(transverseMassLep/reco_mass,weight,notFullCutsVector);
    else if (reco_mass>=160) transMassRecoMassRatio160to400Container.Fill(transverseMassLep/reco_mass,weight,notFullCutsVector);
    else if (reco_mass>=116) transMassRecoMassRatio116to160Container.Fill(transverseMassLep/reco_mass,weight,notFullCutsVector);
    else transMassRecoMassRatio66to116Container.Fill(transverseMassLep/reco_mass,weight,notFullCutsVector);

    if (tau_0_n_charged_tracks==1){
      rnn_score_1pContainer.Fill(tau_0_jet_rnn_score_trans,weight,cutsVector);
    }
    if (tau_0_n_charged_tracks==3){
      rnn_score_3pContainer.Fill(tau_0_jet_rnn_score_trans,weight,cutsVector);
    }
    if (tauTauTopology == Kinematics::TauTauTopology::INSIDE) {
      lepnuptContainer.Fill(nu_lep_p4.Pt(),weight,cutsVector);
      reco_mass_iContainer.Fill(reco_mass,weight,cutsVector);
      taunuptContainer.Fill(nu_tau_p4.Pt(),weight,cutsVector);
      nuPtAssummetryContainer.Fill((nu_lep_p4.Pt()-nu_tau_p4.Pt())/(nu_lep_p4.Pt()+nu_tau_p4.Pt()),weight,notFullCutsVector);
    }
    if (tauTauTopology == Kinematics::TauTauTopology::OUTSIDE_LEP) {
      lepnuptContainer.Fill(nu_lep_p4.Pt(),weight,cutsVector);
      reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
      nuPtAssummetryContainer.Fill(1.0,weight,notFullCutsVector);
    }
    if (tauTauTopology == Kinematics::TauTauTopology::OUTSIDE_TAU) {
      reco_mass_oContainer.Fill(reco_mass,weight,cutsVector);
      taunuptContainer.Fill(nu_tau_p4.Pt(),weight,cutsVector);
      nuPtAssummetryContainer.Fill(-1.0,weight,notFullCutsVector);
    }
  

    if (tauTauTopology == Kinematics::TauTauTopology::INSIDE){
      lepnu_ptContainer.Fill(muon_0_p4->Pt()+nu_lep_p4.Pt(),weight,cutsVector);
      taunu_ptContainer.Fill(tau_0_p4->Pt()+nu_tau_p4.Pt(),weight,cutsVector);
      sum_ptContainer.Fill(muon_0_p4->Pt()+nu_lep_p4.Pt()+tau_0_p4->Pt()+nu_tau_p4.Pt(),weight,cutsVector);
      Z_pt_reco_iNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
    } else {
      lepnu_ptContainer.Fill(muon_0_p4->Pt()+nu_lep_p4.Pt(),weight,cutsVector);
      taunu_ptContainer.Fill(tau_0_p4->Pt()+nu_tau_p4.Pt(),weight,cutsVector);
      sum_ptContainer.Fill(muon_0_p4->Pt()+tau_0_p4->Pt()+nu_tau_p4.Pt()+nu_lep_p4.Pt(),weight,cutsVector);
      Z_pt_reco_oNotFullContainer.Fill(Z_pt,weight,notFullCutsVector);
    }
    lep_etaContainer.Fill(muon_0_p4->Eta(),weight,cutsVector);
    tau_etaContainer.Fill(tau_0_p4->Eta(),weight,cutsVector);
    delta_R_taulepContainer.Fill(tau_0_p4->DeltaR(*muon_0_p4),weight,cutsVector);
    delta_R_lepjetContainer.Fill(min_dR_lep,weight,cutsVector);
    delta_R_taujetContainer.Fill(min_dR_tau,weight,cutsVector);
    metContainer.Fill(met_reco_p4->Pt(),weight,cutsVector);

    if (sampleName.substr(0,4)!="data"){
      if(tauTauTopology == Kinematics::TauTauTopology::INSIDE){Z_pt_truth_iNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
      else {Z_pt_truth_oNotFullContainer.Fill(truth_z_pt,weight,notFullCutsVector);}
      if (tau_0_n_charged_tracks==1){
        tau_matched_1pNotFullContainer.Fill(tau_0_truth_isHadTau,weight,notFullCutsVector);
      }
      if (tau_0_n_charged_tracks==3){
        tau_matched_3pNotFullContainer.Fill(tau_0_truth_isHadTau,weight,notFullCutsVector);
      }
    }
    if(n_jets_interval==1){gap_jet_ptNotFullContainer.Fill(pt_gap_jet,weight,notFullCutsVector);}
    lep_phiNotFullContainer.Fill(muon_0_p4->Phi(),weight,notFullCutsVector);
    tau_phiNotFullContainer.Fill(tau_0_p4->Phi(),weight,notFullCutsVector);
    tau_nprongsNotFullContainer.Fill(tau_0_n_charged_tracks,weight,notFullCutsVector);
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

void CLoop::Style(double lumFactor) {
  trueMass_2D_lepTransMass_basic_all->Write();
  trueMass_2D_transverseRecoMassRatio_basic_all->Write();
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
  reco_mass_iContainer.Write();
  reco_massContainer.Write();
  reco_mass_oContainer.Write();
  bdtContainer.Write();
  lepnuptContainer.Write();
  ptsymContainer.Write();
  muonPdgIDContainer.Write();
  tauPdgIDContainer.Write();
  signedCentralityContainer.Write();
  visibleMassContainer.Write();
  recoVisibleMassRatioContainer.Write();
  trueMassContainer.Write();
  recoTrueMassRatioContainer.Write();
  transMassRecoMassRatioContainer.Write();
  transMassRecoMassRatio66to116Container.Write();
  transMassRecoMassRatio116to160Container.Write();
  transMassRecoMassRatio160to400Container.Write();
  transMassRecoMassRatio400toContainer.Write();

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
  taunuptContainer.Write();
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

// Tree variables 
// Signal tree
extern double SigTree_mcWeight;
extern double SigTree_mjj;
extern double SigTree_deltaRapidity;
extern double SigTree_deltaPhiLT;
extern double SigTree_deltaPhiJJ;
extern double SigTree_jetRNNScore;
extern double SigTree_ptBalance;
extern double SigTree_zCentrality;
extern double SigTree_omega;
extern double SigTree_reco_mass;
extern double SigTree_lepNuPt;
extern double SigTree_transverseMassLep;
extern double SigTree_transverseRecoMassVariable;
extern double SigTree_massTauLep;
extern int SigTree_nLightJets;
extern double SigTree_tau_pT;
extern double SigTree_lep_pT;
extern double SigTree_jet0_pT;
extern double SigTree_jet1_pT;
extern double SigTree_met_pT;
extern double SigTree_event_number;
// Background tree
extern double BgTree_mcWeight;
extern double BgTree_mjj;
extern double BgTree_deltaRapidity;
extern double BgTree_deltaPhiLT;
extern double BgTree_deltaPhiJJ;
extern double BgTree_jetRNNScore;
extern double BgTree_ptBalance;
extern double BgTree_zCentrality;
extern double BgTree_omega;
extern double BgTree_reco_mass;
extern double BgTree_lepNuPt;
extern double BgTree_transverseMassLep;
extern double BgTree_transverseRecoMassVariable;
extern double BgTree_massTauLep;
extern int BgTree_nLightJets;
extern double BgTree_tau_pT;
extern double BgTree_lep_pT;
extern double BgTree_jet0_pT;
extern double BgTree_jet1_pT;
extern double BgTree_met_pT;
extern double BgTree_event_number;

void CLoop::FillTree(double weight, int z_sample, const std::string& sampleName, TTree* stree, TTree* btree) {
  double pi=TMath::Pi();
  //Charges and lepton ID
  float ql=muon_0_q;
  float qtau=tau_0_q;
  bool lepton_id=muon_0_id_medium;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  if (ql!=qtau && n_muons==1 && n_taus_rnn_loose>=1 && weight > -190 && lepton_id && n_ljets>=2 && n_ljets<=3){
    
    //angles
    double angle_l_MET=Kinematics::del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
    double angle_tau_MET=Kinematics::del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
    double angle=Kinematics::del_phi(tau_0_p4->Phi(),muon_0_p4->Phi());
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
        if (outside_lep) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_l_MET);
          reco_mass = 5+sqrt(2*(muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+tau_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))));
        }
        if (outside_tau) {
          neutrino_pt=met_reco_p4->Pt()*cos(angle_tau_MET);
          reco_mass = 5+sqrt(2*(muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+muon_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))));
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
          n_jets_interval=n_jets_interval+Kinematics::is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4);
        }
        //PT BALANCE
        double pt_bal{0};
        double scalarSum = tau_0_p4->Pt()+muon_0_p4->Pt()+ljet_0_p4->Pt()+ljet_1_p4->Pt()+bjet_0_p4->Pt();
        TLorentzVector vectorSum = (*tau_0_p4)+(*muon_0_p4)+(*ljet_0_p4)+(*ljet_1_p4)+(*bjet_0_p4);
        if (n_jets_interval==1){
          scalarSum+= ljet_2_p4->Pt();
          vectorSum+= (*ljet_2_p4);
        }
        TLorentzVector nu_tau_p4(0,0,0,0);
        TLorentzVector nu_lep_p4(0,0,0,0);
        if(inside){
          nu_tau_p4 = TLorentzVector(pt_tau_nu*cos(tau_0_p4->Phi()),pt_tau_nu*sin(tau_0_p4->Phi()),0,0);
          nu_lep_p4 = TLorentzVector(pt_lep_nu*cos(muon_0_p4->Phi()),pt_lep_nu*sin(muon_0_p4->Phi()),0,0);
        } else {
          if(outside_lep) nu_lep_p4 = TLorentzVector(neutrino_pt*cos(muon_0_p4->Phi()),neutrino_pt*sin(muon_0_p4->Phi()),0,0);
          else if(outside_tau) nu_tau_p4 = TLorentzVector (neutrino_pt*cos(tau_0_p4->Phi()),neutrino_pt*sin(tau_0_p4->Phi()),0,0);
        }
        pt_bal= (vectorSum+nu_tau_p4+nu_lep_p4).Pt()/(scalarSum+nu_tau_p4.Pt()+nu_lep_p4.Pt());

        // Z BOSON CENTRALITY
        double lepton_xi=((*tau_0_p4)+(*muon_0_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        //pT gap jet
        double pt_gap_jet{};
        if (Kinematics::is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4)){pt_gap_jet=ljet_2_p4->Pt();}

        // Minimum DeltaR between lepton and jets
        std::vector<UInt_t> is_jet_present{ljet_0,ljet_1,ljet_2};
        std::vector<TLorentzVector*> jet_container{ljet_0_p4,ljet_1_p4,ljet_2_p4};

        double min_dR_tau = Kinematics::min_deltaR(tau_0_p4,is_jet_present,jet_container);
        double min_dR_lep = Kinematics::min_deltaR(muon_0_p4,is_jet_present,jet_container);

        // Definition of the superCR = CR(a+b+c)
        bool CRa = z_centrality < 0.5 && n_jets_interval == 1;
        bool CRb = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 1;
        bool CRc = z_centrality>=0.5 && z_centrality <=1 && n_jets_interval == 0;
        bool superCR = CRa || CRb || CRc;

        // ONLY SUPER CR
        //if (!superCR) return;

        // Cuts vector
        vector<int> cuts={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        // CUTS
        if (angle<=3.2){cuts[0]=1;}
        if(delta_y>=2.0){cuts[1]=1;}
        if(n_bjets_MV2c10_FixedCutBEff_85==1){cuts[2]=1;}
        if(muon_0_iso_TightTrackOnly_FixedRad==1){cuts[3]=1;}
        if(tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans >= 0.25){cuts[4]=1;}
        if(tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans >= 0.40){cuts[4]=1;}
        if(muon_0_p4->Pt()>=27){cuts[5]=1;}
        if(ljet_0_p4->Pt()>=75){cuts[6]=1;}
        if(ljet_1_p4->Pt()>=65){cuts[7]=1;}
        if(pt_bal<=0.15){cuts[8]=1;}
        if(mjj>=750){cuts[9]=1;}
        if(n_jets_interval==0){cuts[10]=1;}
        if(z_centrality<0.5){cuts[11]=1;} // SR -> z_centrality < 0.5
        if (omega> -0.2 && omega <1.4){cuts[12]=1;} // Z-peak omega> -0.2 && omega <1.6
        bool diLeptonMassRequirement = reco_mass>120;
        if (diLeptonMassRequirement){cuts[13]=1;} // Z-peak reco_mass<116 && reco_mass>66 // Higgs reco_mass >= 116 && reco_mass < 150
        if (tau_0_p4->Pt()>=25){cuts[14]=1;}

        // SUM OF THE VECTOR STORING IF CUTS PASS OR NOT
        size_t sum{0};
        for(auto &j : cuts){sum=sum+j;}

        std::vector<int> cutsVector{1};
        cutsVector.insert(cutsVector.end(),cuts.begin(),cuts.end());
        bool passedAllCuts = (sum+1==cutsVector.size());
        std::vector<int> notFullCutsVector{1,static_cast<int>(passedAllCuts)};

        double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
        double normPtDifference = (tau_0_p4->Pt()-muon_0_p4->Pt())/(tau_0_p4->Pt()+muon_0_p4->Pt());
        double anglejj = Kinematics::del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
        double metToDilepnuRatio = 0.0;
        double metToDilepRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt());
        if (inside)
        {
          metToDilepnuRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+pt_tau_nu+muon_0_p4->Pt()+pt_lep_nu);
        }
        if (outside_lep || outside_tau)
        {
          metToDilepnuRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+muon_0_p4->Pt()+neutrino_pt);
        }

        double massTauCloserJet{0.0};
        double massLepClosestJet{0.0};
        double massTauFurthestJet{0.0};
        bool j0CloserToTau = tau_0_p4->DeltaR(*ljet_0_p4) <= tau_0_p4->DeltaR(*ljet_1_p4);
        if (j0CloserToTau)
        {
          massTauCloserJet = sqrt(2*(tau_0_p4->Dot(*ljet_0_p4)));
          massTauFurthestJet = sqrt(2*(tau_0_p4->Dot(*ljet_1_p4)));
          massLepClosestJet = sqrt(2*(muon_0_p4->Dot(*ljet_1_p4)));
        }
        else
        {
          massTauCloserJet = sqrt(2*(tau_0_p4->Dot(*ljet_1_p4)));
          massTauFurthestJet = sqrt(2*(tau_0_p4->Dot(*ljet_0_p4)));
          massLepClosestJet = sqrt(2*(muon_0_p4->Dot(*ljet_0_p4)));
        }

        // Neutrino cuts
        bool taunuPtPass = true;
        bool lepnuPtPass = true;
        if (inside) 
        {
          taunuPtPass = pt_tau_nu>=15;
          lepnuPtPass = pt_tau_nu>=30;
        } else {
          if (outside_lep) lepnuPtPass = neutrino_pt>=30;
          if (outside_tau) taunuPtPass = neutrino_pt>=15;
        }

        // Transverse mass
        double transverseMassLep = sqrt(2*muon_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(muon_0_p4->Phi()-met_reco_p4->Phi())));
        double transverseMassTau = sqrt(2*tau_0_p4->Pt()*met_reco_p4->Pt()*(1-cos(tau_0_p4->Phi()-met_reco_p4->Phi())));
        double transverseRecoMassRatio = reco_mass > 200 ? transverseMassLep/std::pow(reco_mass,0.3) : transverseMassLep/std::pow(200,0.3);
        

        bool testCuts = transverseMassLep <= 65 && massTauCloserJet >= 90;
        if (passedAllCuts){
        // FILLING TTree
        // Check if sample is VBF Ztautau
        // LEP-TAU INVARIANT MASS
        double inv_taulep=sqrt((2*muon_0_p4->Pt()*tau_0_p4->Pt())*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi())));
        bool isVBFZtautau = sampleName.find("VBF") != std::string::npos && sampleName.find("Ztautau") != std::string::npos && sampleName.find("old") == std::string::npos;
        bool isVBFHiggs = sampleName.find("H") != std::string::npos && sampleName.find("VBF") != std::string::npos;
        if (isVBFZtautau || isVBFHiggs) {
          SigTree_mcWeight = weight;
          SigTree_mjj = mjj;
          SigTree_deltaRapidity = delta_y;
          SigTree_mjj = mjj;
          SigTree_deltaRapidity = delta_y;
          SigTree_deltaPhiLT = angle;
          SigTree_deltaPhiJJ = anglejj;
          SigTree_jetRNNScore = tau_0_jet_rnn_score_trans;
          SigTree_ptBalance = pt_bal;
          SigTree_zCentrality = z_centrality;
          SigTree_omega = omega;
          SigTree_reco_mass = reco_mass;
          if (inside) SigTree_lepNuPt = pt_lep_nu;
          if (outside_lep) SigTree_lepNuPt = neutrino_pt;
          if (outside_tau) SigTree_lepNuPt = 0.0;
          SigTree_transverseMassLep = transverseMassLep;
          SigTree_transverseRecoMassVariable = transverseRecoMassRatio;
          SigTree_massTauLep = inv_taulep;
          SigTree_nLightJets = n_ljets;
          SigTree_tau_pT = tau_0_p4->Pt();
          SigTree_lep_pT = muon_0_p4->Pt();
          SigTree_jet0_pT = ljet_0_p4->Pt();
          SigTree_jet1_pT = ljet_1_p4->Pt();
          SigTree_met_pT = met_reco_p4->Pt();
          SigTree_event_number = event_number;
          // Fill tree
          stree->Fill();
        } else {
          BgTree_mcWeight = weight;
          BgTree_mjj = mjj;
          BgTree_deltaRapidity = delta_y;
          BgTree_mjj = mjj;
          BgTree_deltaRapidity = delta_y;
          BgTree_deltaPhiLT = angle;
          BgTree_deltaPhiJJ = anglejj;
          BgTree_jetRNNScore = tau_0_jet_rnn_score_trans;
          BgTree_ptBalance = pt_bal;
          BgTree_zCentrality = z_centrality;
          BgTree_omega = omega;
          BgTree_reco_mass = reco_mass;
          if (inside) BgTree_lepNuPt = pt_lep_nu;
          if (outside_lep) BgTree_lepNuPt = neutrino_pt;
          if (outside_tau) BgTree_lepNuPt = 0.0;
          BgTree_transverseMassLep = transverseMassLep;
          BgTree_transverseRecoMassVariable = transverseRecoMassRatio;
          BgTree_massTauLep = inv_taulep;
          BgTree_nLightJets = n_ljets;
          BgTree_tau_pT = tau_0_p4->Pt();
          BgTree_lep_pT = muon_0_p4->Pt();
          BgTree_jet0_pT = ljet_0_p4->Pt();
          BgTree_jet1_pT = ljet_1_p4->Pt();
          BgTree_met_pT = met_reco_p4->Pt();
          BgTree_event_number = event_number;
          // Fill tree
          btree->Fill();
        }
        }
      }
    }
  }
}

#endif // End header guard