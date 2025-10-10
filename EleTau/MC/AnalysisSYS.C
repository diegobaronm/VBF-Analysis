// Include the file that lets the program know about the data
#include"../../AnalysisCommons/Tools.h"
#include "Selections.C"
#include"../../AnalysisCommons/Systematics.h" 
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

void CLoopSYS::Book() {
    m_cutNames = Selections::InitCutNames(m_region);

    if (m_systematicType == "sf") {
      DEFINE_SYS_HISTOGRAMS(elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_offline_TightLLH_d0z0_v13)
      DEFINE_SYS_HISTOGRAMS(elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight)
      DEFINE_SYS_HISTOGRAMS(elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_offline_RecoTrk)
      DEFINE_SYS_HISTOGRAMS(elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight)
      DEFINE_SYS_HISTOGRAMS(PRW_DATASF, pileup_combined_weight)
      DEFINE_SYS_HISTOGRAMS(jet_JET_JvtEfficiency, central_jets_global_effSF_JVT)
      DEFINE_SYS_HISTOGRAMS(jet_JET_JvtEfficiency, central_jets_global_ineffSF_JVT)
      DEFINE_SYS_HISTOGRAMS(jet_JET_fJvtEfficiency, forward_jets_global_effSF_JVT)
      DEFINE_SYS_HISTOGRAMS(jet_JET_fJvtEfficiency, forward_jets_global_ineffSF_JVT)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_0, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_1, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_2, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_0, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_1, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_2, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_3, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_0, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_1, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_2, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_3, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation_from_charm, global_effSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_0, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_1, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_2, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_0, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_1, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_2, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_3, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_0, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_1, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_2, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_3, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation_from_charm, global_ineffSF_MV2c10_FixedCutBEff_85)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL, TauEffSF_reco)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST, TauEffSF_JetRNNmedium)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT, TauEffSF_LooseEleBDT_electron)
      DEFINE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST, TauEffSF_LooseEleBDT_electron)
    }
    // For the other kind of systematics...
    std::string sysHistogramName = "mass_jj_" + m_systematicHistogramName;
    mass_jj_sys_hist = std::make_unique<TH1F>(sysHistogramName.c_str(),"Invariant mass di-jet system",5000,0,5000);
}

void CLoopSYS::Fill(double weight, const std::string& key) {
  double pi=TMath::Pi();
  // Charges and lepton ID
  bool correctCharge = Kinematics::isChargeCorrect(m_region,elec_0_q,tau_0_q);
  bool lepton_id=elec_0_id_tight;
  size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  // Trigger decision
  bool trigger_decision= false;
  bool trigger_match= false;
  if (run_number>= 276262 && run_number<=284484){
      trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
      trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
  } else {
      trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
      trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
  }

  // 0) Invariant mass of tagging jets.
  double mjj = Kinematics::Mass({ljet_0_p4, ljet_1_p4});

  // Apply fix for '_thsys' samples
  if (key.find("_thsys") != std::string::npos) {
    useEvent = 1;
  }

  if (useEvent==1 && correctCharge && n_electrons==1 && n_taus_rnn_loose>=1 && lepton_id && n_ljets>=2 && n_ljets<=3 && mjj>=250 && trigger_decision && trigger_match){

    // Build the kinematic variables needed for the selections.
    
    // 1) Angles between the MET, Tau and Electron.
    double angle_l_MET = Kinematics::del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
    double angle_tau_MET = Kinematics::del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
    double angle = Kinematics::del_phi(tau_0_p4->Phi(),elec_0_p4->Phi());
    
    // 2) Get the topology of the tau-tau system.
    Kinematics::TauTauTopology tauTauTopology = Kinematics::getTauTauTopology(angle_l_MET, angle_tau_MET, angle);
    if (tauTauTopology == Kinematics::TauTauTopology::NOT_VALID) return;
    g_LOG(LogLevel::DEBUG, "This event passes the basic selection cuts.");
    
    // 3) Neutrino momentum
    TLorentzVector nu_tau_p4 = Kinematics::getTauNeutrino(tauTauTopology,met_reco_p4,tau_0_p4,elec_0_p4);
    TLorentzVector nu_lep_p4 = Kinematics::getLepNeutrino(tauTauTopology,met_reco_p4,tau_0_p4,elec_0_p4);

    // 4) Reconstructed mass
    double reco_mass = Kinematics::getRecoMass(tauTauTopology, tau_0_p4, elec_0_p4, &nu_tau_p4, &nu_lep_p4);
    
    // 5) ZpT and truth ZpT calculations
    double Z_pt = (*elec_0_p4 + *tau_0_p4 + nu_tau_p4 + nu_lep_p4).Pt();

    // LEP-TAU INVARIANT MASS
    double inv_taulep = Kinematics::Mass({elec_0_p4,tau_0_p4});
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
    std::vector<TLorentzVector*> particles = {ljet_0_p4, ljet_1_p4, tau_0_p4, elec_0_p4, &nu_tau_p4, &nu_lep_p4};
    if (n_jets_interval==1) particles.push_back(ljet_2_p4);
    double pt_bal = Kinematics::getPtBalance(particles);

    // 10) Z boson centrality
    double signed_z_centrality = Kinematics::getSignedCentrality(ljet_0_p4, ljet_1_p4, tau_0_p4, elec_0_p4);
    double z_centrality = abs(signed_z_centrality);

    // 11) pT gap jet
    double pt_gap_jet = n_jets_interval == 1 ? ljet_2_p4->Pt() : 0.0;

    // Minimum DeltaR between lepton and jets
    double min_dR_tau = Kinematics::min_deltaR(tau_0_p4,is_jet_present,jet_container);
    double min_dR_lep = Kinematics::min_deltaR(elec_0_p4,is_jet_present,jet_container);

    // More kinamatic variables
    double etaMoreCentral = abs(ljet_0_p4->Eta())>=abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
    double etaLessCentral = abs(ljet_0_p4->Eta())<abs(ljet_1_p4->Eta()) ? ljet_1_p4->Eta() : ljet_0_p4->Eta();
    double normPtDifference = (tau_0_p4->Pt()-elec_0_p4->Pt())/(tau_0_p4->Pt()+elec_0_p4->Pt());
    double anglejj = Kinematics::del_phi(ljet_0_p4->Phi(),ljet_1_p4->Phi());
    double metToDilepRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+elec_0_p4->Pt());
    double metToDilepnuRatio = met_reco_p4->Pt()/(tau_0_p4->Pt()+nu_tau_p4.Pt()+elec_0_p4->Pt()+nu_lep_p4.Pt());


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

    // Transverse mass
    double transverseMassLep = Kinematics::TransverseMass(elec_0_p4,met_reco_p4);
    double transverseMassTau = Kinematics::TransverseMass(tau_0_p4,met_reco_p4);
    double transverseMassSum = transverseMassTau + transverseMassLep;
    double transverseMassRatio = (transverseMassTau - transverseMassLep)/transverseMassSum;

    // Handling external BDT
    float bdt_transmasslep = reco_mass > 200 ? transverseMassLep/std::pow(reco_mass,0.3) : transverseMassLep/std::pow(200,0.3); // for transverse-reco mass ratio
    m_vbfBDT.update(mjj, delta_y, pt_bal, z_centrality, omega, bdt_transmasslep, event_number);
    double VBFBDT_score = m_vbfBDT.evaluate();

    // Cuts 
    // First initialise the variables used for the cutflow
    Kinematics::VariablesForCutflow cutVars{};
    cutVars.deltaPhiLepLep = angle;
    cutVars.deltaRapidityTaggingJets = delta_y;
    cutVars.nBJets = n_bjets_MV2c10_FixedCutBEff_85;
    cutVars.lep1IsolationTight = elec_0_iso_FCTight;
    cutVars.lep1IsolationLoose = elec_0_iso_FCLoose;
    cutVars.nTauProngs = tau_0_n_charged_tracks;
    cutVars.tauJetRNNScore = tau_0_jet_rnn_score_trans;
    cutVars.lep1pT = elec_0_p4->Pt();
    cutVars.taupT = tau_0_p4->Pt();
    cutVars.jet1pT = ljet_0_p4->Pt();
    cutVars.jet2pT = ljet_1_p4->Pt();
    cutVars.mjj = 2000; // To fill the entire mjj spectrum
    cutVars.pTBalance = pt_bal;
    cutVars.nJetsInGap = n_jets_interval;
    cutVars.centrality = z_centrality;
    cutVars.omega = omega;
    cutVars.massTauLepton = inv_taulep;
    cutVars.recoMass = reco_mass;
    cutVars.eBDTScore = tau_0_ele_bdt_score_trans_retuned;
    cutVars.vbfBDTScore = VBFBDT_score;
    cutVars.lepPtAssymetry = normPtDifference;
    cutVars.recoVisibleMassRatio = reco_mass/inv_taulep;
    
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

    // Do the NOMINAL
    if (m_systematicType == "nominal" && passedAllCuts) {
      mass_jj_sys_hist->Fill(mjj, weight);
    }

    // Fill the histograms for SF systematics
    if (m_systematicType == "sf" && passedAllCuts) {
      FILL_SYS_HISTOGRAMS(elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_offline_TightLLH_d0z0_v13, elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13)
      FILL_SYS_HISTOGRAMS(elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight, elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight)
      FILL_SYS_HISTOGRAMS(elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_offline_RecoTrk, elec_0_NOMINAL_EleEffSF_offline_RecoTrk)
      FILL_SYS_HISTOGRAMS(elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight, elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight)
      FILL_SYS_HISTOGRAMS(PRW_DATASF, pileup_combined_weight, NOMINAL_pileup_combined_weight)
      FILL_SYS_HISTOGRAMS(jet_JET_JvtEfficiency, central_jets_global_effSF_JVT, jet_NOMINAL_central_jets_global_effSF_JVT)
      FILL_SYS_HISTOGRAMS(jet_JET_JvtEfficiency, central_jets_global_ineffSF_JVT, jet_NOMINAL_central_jets_global_ineffSF_JVT)
      FILL_SYS_HISTOGRAMS(jet_JET_fJvtEfficiency, forward_jets_global_effSF_JVT, jet_NOMINAL_forward_jets_global_effSF_JVT)
      FILL_SYS_HISTOGRAMS(jet_JET_fJvtEfficiency, forward_jets_global_ineffSF_JVT, jet_NOMINAL_forward_jets_global_ineffSF_JVT)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_0, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_1, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_2, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_0, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_1, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_2, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_3, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_0, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_1, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_2, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_3, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation_from_charm, global_effSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_0, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_1, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_2, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_0, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_1, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_2, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_3, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_0, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_1, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_2, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_3, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation_from_charm, global_ineffSF_MV2c10_FixedCutBEff_85, jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL, TauEffSF_reco, tau_0_NOMINAL_TauEffSF_reco)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST, TauEffSF_JetRNNmedium, tau_0_NOMINAL_TauEffSF_JetRNNmedium)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT, TauEffSF_LooseEleBDT_electron, tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron)
      FILL_SYS_HISTOGRAMS(tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST, TauEffSF_LooseEleBDT_electron, tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron)

    } else if (m_systematicType == "kinematic" && passedAllCuts) {
      mass_jj_sys_hist->Fill(mjj, weight);

    } else if (m_systematicType == "theory" && passedAllCuts) {
      std::map<std::string, float> theory_weights_map;
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_CT18_pdfset)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEW)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEW)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEW)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEW)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEW)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEW)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_LHE3Weight_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_MSHT_pdfset)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_alphaS_down)
      INSERT_SYS_THEORY_MAP(theory_weights_map, theory_weights_alphaS_up)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_0)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_1)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_2)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_3)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_4)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_5)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_6)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_7)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_8)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_9)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_10)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_11)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_12)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_13)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_14)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_15)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_16)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_17)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_18)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_19)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_20)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_21)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_22)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_23)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_24)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_25)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_26)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_27)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_28)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_29)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_30)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_31)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_32)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_33)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_34)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_35)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_36)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_37)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_38)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_39)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_40)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_41)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_42)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_43)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_44)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_45)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_46)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_47)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_48)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_49)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_50)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_51)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_52)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_53)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_54)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_55)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_56)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_57)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_58)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_59)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_60)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_61)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_62)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_63)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_64)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_65)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_66)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_67)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_68)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_69)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_70)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_71)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_72)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_73)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_74)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_75)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_76)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_77)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_78)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_79)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_80)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_81)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_82)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_83)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_84)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_85)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_86)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_87)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_88)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_89)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_90)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_91)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_92)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_93)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_94)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_95)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_96)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_97)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_98)
      INSERT_SYS_THEORY_MAP(theory_weights_map,  theory_weights_pdf_ztt_weight_99)
      // Do the weight adjustment
      if (key.find("VBF") != std::string::npos && m_systematicIdentifier.find("ASSEW") != std::string::npos) {
        g_LOG(LogLevel::DEBUG, "VBF samples do not have some theory weights (ASSEW*), falling back to nominal.");
      } else {
        weight = (weight / weight_mc) * theory_weights_map[m_systematicIdentifier]; // Remove nominal weight_mc and apply the systematic one
      }
      mass_jj_sys_hist->Fill(mjj, weight);
      
    }
    

  }
}

void CLoopSYS::Style() {
    // Write the histograms for SF systematics
    if (m_systematicType == "sf") {
      WRITE_SYS_HISTOGRAMS(elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_offline_TightLLH_d0z0_v13)
      WRITE_SYS_HISTOGRAMS(elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight)
      WRITE_SYS_HISTOGRAMS(elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_offline_RecoTrk)
      WRITE_SYS_HISTOGRAMS(elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR, EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight)
      WRITE_SYS_HISTOGRAMS(PRW_DATASF, pileup_combined_weight)
      WRITE_SYS_HISTOGRAMS(jet_JET_JvtEfficiency, central_jets_global_effSF_JVT)
      WRITE_SYS_HISTOGRAMS(jet_JET_JvtEfficiency, central_jets_global_ineffSF_JVT)
      WRITE_SYS_HISTOGRAMS(jet_JET_fJvtEfficiency, forward_jets_global_effSF_JVT)
      WRITE_SYS_HISTOGRAMS(jet_JET_fJvtEfficiency, forward_jets_global_ineffSF_JVT)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_0, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_1, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_2, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_0, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_1, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_2, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_3, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_0, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_1, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_2, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_3, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation_from_charm, global_effSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_0, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_1, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_B_2, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_0, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_1, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_2, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_C_3, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_0, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_1, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_2, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_Eigen_Light_3, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(jet_FT_EFF_extrapolation_from_charm, global_ineffSF_MV2c10_FixedCutBEff_85)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL, TauEffSF_reco)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST, TauEffSF_JetRNNmedium)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT, TauEffSF_LooseEleBDT_electron)
      WRITE_SYS_HISTOGRAMS(tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST, TauEffSF_LooseEleBDT_electron)
    }

    // Write the histograms for other systematics
    mass_jj_sys_hist->Write();
}