// Include the file that lets the program know about the data
#include"../../AnalysisCommons/Tools.h"
#include "Selections.C"
#include"../../AnalysisCommons/Systematics.h" 
#include <vector>
#include <string>
#include <map>
#include <TMVA/Reader.h>
#include <algorithm>
#include <utility>

void CLoopSYS::Book() {
    m_cutNames = Selections::InitCutNames(m_region);
    double pi=TMath::Pi();

    if (m_systematicType == "sf") {
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TTVA_STAT, MuEffSF_TTVA)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TTVA_SYS, MuEffSF_TTVA)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_STAT_LOWPT, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_SYS_LOWPT, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_ISO_STAT, MuEffSF_IsoTightTrackOnly_FixedRad)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_ISO_SYS, MuEffSF_IsoTightTrackOnly_FixedRad)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_STAT, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_SYS, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TrigStatUncertainty, combined)
      DEFINE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TrigSystUncertainty, combined)
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
    }

    std::string sysHistogramName = "mass_jj_" + m_systematicHistogramName;
    mass_jj_sys_hist = std::make_unique<TH1F>(sysHistogramName.c_str(),"Invariant mass di-jet system",5000,0,5000);
}

void CLoopSYS::Fill(double weight, const std::string& key) {
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

  if (useEvent==1 && correctCharge && n_muons==1 && n_taus_rnn_loose>=1 && weight > -190 && lepton_id && n_ljets>=2 && n_ljets<=3 && mjj>=250 && trigger_decision  && trigger_match && abs(tau_0_p4->Eta())>=0.1){
    
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
    cutVars.mjj = 2000; // To write all the mjj spectrum in the histograms
    cutVars.pTBalance = pt_bal;
    cutVars.nJetsInGap = n_jets_interval;
    cutVars.centrality = z_centrality;
    cutVars.omega = omega;
    cutVars.recoMass = reco_mass;
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

    // Fill the histograms for SF systematics
    if (m_systematicType == "sf" && passedAllCuts) {
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_TTVA_STAT, MuEffSF_TTVA, muon_0_NOMINAL_MuEffSF_TTVA)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_TTVA_SYS, MuEffSF_TTVA, muon_0_NOMINAL_MuEffSF_TTVA)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_STAT_LOWPT, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_SYS_LOWPT, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_ISO_STAT, MuEffSF_IsoTightTrackOnly_FixedRad, muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_ISO_SYS, MuEffSF_IsoTightTrackOnly_FixedRad, muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_STAT, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_SYS, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_TRIGGER_HISTOGRAMS(muon_0_MUON_EFF_TrigStatUncertainty, combined, MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium)
      FILL_SYS_TRIGGER_HISTOGRAMS(muon_0_MUON_EFF_TrigSystUncertainty, combined, MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium)
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
      mass_jj_sys_hist->Fill(mjj, weight); // Do the nominal for free here

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
      // Do the weight adjustment
      if (key.find("VBF") != std::string::npos && m_systematicIdentifier.find("ASSEW") != std::string::npos) {
        g_LOG(LogLevel::DEBUG, "VBF samples do not have some theory weights (ASSEW*), fallick to nominal.");
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
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TTVA_STAT, MuEffSF_TTVA)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TTVA_SYS, MuEffSF_TTVA)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_STAT_LOWPT, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_SYS_LOWPT, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_ISO_STAT, MuEffSF_IsoTightTrackOnly_FixedRad)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_ISO_SYS, MuEffSF_IsoTightTrackOnly_FixedRad)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_STAT, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_RECO_SYS, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TrigStatUncertainty, combined)
      WRITE_SYS_HISTOGRAMS(muon_0_MUON_EFF_TrigSystUncertainty, combined)
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
    }

    // Write the histograms for other systematics
    mass_jj_sys_hist->Write();
}