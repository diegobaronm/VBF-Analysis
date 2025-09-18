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
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_TTVA_STAT, MuEffSF_TTVA)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_TTVA_SYS, MuEffSF_TTVA)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_STAT_LOWPT, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_SYS_LOWPT, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_ISO_STAT, MuEffSF_IsoTightTrackOnly_FixedRad)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_ISO_SYS, MuEffSF_IsoTightTrackOnly_FixedRad)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_STAT, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_SYS, MuEffSF_Reco_QualMedium)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_TrigStatUncertainty, combined)
      DEFINE_SYS_HISTOGRAMS(muon_MUON_EFF_TrigSystUncertainty, combined)
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
    }
    // For the other kind of systematics...
    std::string sysHistogramName = "mass_jj_" + m_systematicHistogramName;
    mass_jj_sys_hist = std::make_unique<TH1F>(sysHistogramName.c_str(),"Invariant mass di-jet system",5000,0,5000);
}

void CLoopSYS::Fill(double weight, const std::string& key) {
  double pi=TMath::Pi();
  // Charges and lepton ID
  bool correctCharge = Kinematics::isChargeCorrect(m_region,muon_0_q,muon_1_q);
  bool muon_id = muon_0_id_medium && muon_1_id_medium;
  std::size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;

  // Trigger decision
  double muon_trigger_SF = 1.0;
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
  
    if (trigger_match_1){muon_trigger_SF=muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;}
    if (trigger_match_2){muon_trigger_SF=muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;}

    trigger_match= trigger_match_1 | trigger_match_2 | trigger_match_12;
  } else {
    trigger_decision = bool(HLT_mu26_ivarmedium | HLT_mu50);
    trigger_match_1 = bool((muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && !(muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
    trigger_match_2 = bool(!(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
    trigger_match_12 = bool((muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));

    if (trigger_match_1){muon_trigger_SF=muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;}
    if (trigger_match_2){muon_trigger_SF=muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;}

    trigger_match= trigger_match_1 | trigger_match_2 | trigger_match_12;
  }
  weight *= muon_trigger_SF;

  // 0) Invariant mass of tagging jets.
  double mjj = Kinematics::Mass({ljet_0_p4, ljet_1_p4});
  double mll = Kinematics::Mass({muon_0_p4, muon_1_p4});

  // Prevent high PileUPRW events.
  bool goodPUW = true;
  goodPUW = NOMINAL_pileup_combined_weight > -10;

  if (useEvent==1 && correctCharge && n_muons==2 && muon_id && n_ljets>=2 && n_ljets<=3 && goodPUW && mjj>=250 && mll >=40 && trigger_decision && trigger_match){
    g_LOG(LogLevel::DEBUG, "This event passes the basic selection cuts.");
    // Build the kinematic variables needed for the selections.
    
    // 1) Angles between the leptons.
    double angle = Kinematics::del_phi(muon_1_p4->Phi(),muon_0_p4->Phi());

    // 4) Invariant mass of the di-lepton system.
    double inv_mass = Kinematics::Mass({muon_0_p4, muon_1_p4});

    // 3) ZpT and truth ZpT calculations
    double Z_pt = (*muon_0_p4 + *muon_1_p4).Pt();

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
    std::vector<TLorentzVector*> particles = {ljet_0_p4, ljet_1_p4, muon_0_p4, muon_1_p4};
    if (n_jets_interval==1) particles.push_back(ljet_2_p4);
    double pt_bal = Kinematics::getPtBalance(particles);


    // 7) Z boson centrality
    double signed_z_centrality = Kinematics::getSignedCentrality(ljet_0_p4, ljet_1_p4, muon_0_p4, muon_1_p4);
    double z_centrality = abs(signed_z_centrality);

    // 8) pT gap jet
    double pt_gap_jet = n_jets_interval == 1 ? ljet_2_p4->Pt() : 0.0;


    // Minimum DeltaR between lepton and jets
    double min_dR_lep1 = Kinematics::min_deltaR(muon_0_p4,is_jet_present,jet_container);
    double min_dR_lep2 = Kinematics::min_deltaR(muon_1_p4,is_jet_present,jet_container);

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
    cutVars.lep2IsolationTight = muon_1_iso_TightTrackOnly_FixedRad;
    cutVars.lep2IsolationLoose = muon_1_iso_Loose_FixedRad;
    cutVars.lep1pT = muon_0_p4->Pt();
    cutVars.lep2pT = muon_1_p4->Pt();
    cutVars.jet1pT = ljet_0_p4->Pt();
    cutVars.jet2pT = ljet_1_p4->Pt();
    cutVars.pTBalance = pt_bal;
    cutVars.mjj = 2000; // To save all the mjj spectrum.
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

    // Fill the histograms for SF systematics
    if (m_systematicType == "sf" && passedAllCuts) {
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_TTVA_STAT, MuEffSF_TTVA, muon_0_NOMINAL_MuEffSF_TTVA, muon_1_NOMINAL_MuEffSF_TTVA)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_TTVA_SYS, MuEffSF_TTVA, muon_0_NOMINAL_MuEffSF_TTVA, muon_1_NOMINAL_MuEffSF_TTVA)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_RECO_STAT_LOWPT, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium, muon_1_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_RECO_SYS_LOWPT, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium, muon_1_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_ISO_STAT, MuEffSF_IsoTightTrackOnly_FixedRad, muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad, muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_ISO_SYS, MuEffSF_IsoTightTrackOnly_FixedRad, muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad, muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_RECO_STAT, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium, muon_1_NOMINAL_MuEffSF_Reco_QualMedium)
      FILL_SYS_2LEP_HISTOGRAMS(MUON_EFF_RECO_SYS, MuEffSF_Reco_QualMedium, muon_0_NOMINAL_MuEffSF_Reco_QualMedium, muon_1_NOMINAL_MuEffSF_Reco_QualMedium)
      if (run_number>= 276262 && run_number<=284484) {
        if (trigger_match_1) {
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigStatUncertainty, combined, muon_0_MUON_EFF_TrigStatUncertainty, MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, muon_trigger_SF)
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigSystUncertainty, combined, muon_0_MUON_EFF_TrigSystUncertainty, MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, muon_trigger_SF)
        } else if (trigger_match_2) {
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigStatUncertainty, combined, muon_1_MUON_EFF_TrigStatUncertainty, MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, muon_trigger_SF)
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigSystUncertainty, combined, muon_1_MUON_EFF_TrigSystUncertainty, MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, muon_trigger_SF)
        } else {
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS_DUMMY(muon_MUON_EFF_TrigStatUncertainty, combined)
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS_DUMMY(muon_MUON_EFF_TrigSystUncertainty, combined)
        }
      } else {
        if (trigger_match_1) {
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigStatUncertainty, combined, muon_0_MUON_EFF_TrigStatUncertainty, MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, muon_trigger_SF)
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigSystUncertainty, combined, muon_0_MUON_EFF_TrigSystUncertainty, MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, muon_trigger_SF)
        } else if (trigger_match_2) {
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigStatUncertainty, combined, muon_1_MUON_EFF_TrigStatUncertainty, MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, muon_trigger_SF)
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(muon_MUON_EFF_TrigSystUncertainty, combined, muon_1_MUON_EFF_TrigSystUncertainty, MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, muon_trigger_SF)
        } else {
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS_DUMMY(muon_MUON_EFF_TrigStatUncertainty, combined)
          FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS_DUMMY(muon_MUON_EFF_TrigSystUncertainty, combined)
        }
      }
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
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_TTVA_STAT, MuEffSF_TTVA)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_TTVA_SYS, MuEffSF_TTVA)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_STAT_LOWPT, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_SYS_LOWPT, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_ISO_STAT, MuEffSF_IsoTightTrackOnly_FixedRad)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_ISO_SYS, MuEffSF_IsoTightTrackOnly_FixedRad)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_STAT, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_RECO_SYS, MuEffSF_Reco_QualMedium)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_TrigStatUncertainty, combined)
      WRITE_SYS_HISTOGRAMS(muon_MUON_EFF_TrigSystUncertainty, combined)
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
    }

    // Write the histograms for other systematics
    mass_jj_sys_hist->Write();
}