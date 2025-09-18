//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep 15 16:26:32 2025 by ROOT version 6.36.02
// from TTree NOMINAL/NOMINAL
// found on file: user.dbaronmo.46291343._000001.TauID_Zll.root
//////////////////////////////////////////////////////////

#ifndef CLoopSYS_h
#define CLoopSYS_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"
#include "../../../AnalysisCommons/histogramContainer.h"
#include "../../../AnalysisCommons/Tools.h"
#include "../../../AnalysisCommons/Kinematics.h"

class CLoopSYS {
   void Style();
   void Book();
   void Fill(double weight, const std::string& key);

   std::string m_region;
   std::string m_systematicType;
   std::string m_systematicHistogramName;
   std::string m_systematicIdentifier;
   std::vector<std::string> notFull{"basic","all"};
   std::vector<std::string> m_cutNames;
   #include "../AnalysisSYS.h"

public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          HLT_e120_lhloose;
   UInt_t          HLT_e140_lhloose_nod0;
   UInt_t          HLT_e24_lhmedium_L1EM20VH;
   UInt_t          HLT_e26_lhtight_nod0_ivarloose;
   UInt_t          HLT_e60_lhmedium;
   UInt_t          HLT_e60_lhmedium_nod0;
   UInt_t          HLT_mu20_iloose_L1MU15;
   UInt_t          HLT_mu26_ivarmedium;
   UInt_t          HLT_mu50;
   Float_t         NOMINAL_pileup_combined_weight;
   UInt_t          NOMINAL_pileup_random_run_number;
   Float_t         PRW_DATASF_1down_pileup_combined_weight;
   UInt_t          PRW_DATASF_1down_pileup_random_run_number;
   Float_t         PRW_DATASF_1up_pileup_combined_weight;
   UInt_t          PRW_DATASF_1up_pileup_random_run_number;
   UInt_t          event_clean_EC_LooseBad;
   UInt_t          event_clean_EC_TightBad;
   Int_t           event_clean_detector_core;
   Int_t           event_is_bad_batman;
   ULong64_t       event_number;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT;
   Float_t         jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT;
   Float_t         jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT;
   Float_t         jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT;
   Float_t         jet_NOMINAL_central_jets_global_effSF_JVT;
   Float_t         jet_NOMINAL_central_jets_global_ineffSF_JVT;
   Float_t         jet_NOMINAL_forward_jets_global_effSF_JVT;
   Float_t         jet_NOMINAL_forward_jets_global_ineffSF_JVT;
   Float_t         jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85;
   Float_t         jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85;
   UInt_t          ljet_0;
   Float_t         ljet_0_MV2c10_FixedCutBEff_85_weight;
   Float_t         ljet_0_b_tag_score;
   Int_t           ljet_0_b_tagged_MV2c10_FixedCutBEff_85;
   Int_t           ljet_0_origin;
   TLorentzVector  *ljet_0_p4;
   Float_t         ljet_0_q;
   Int_t           ljet_0_type;
   Float_t         ljet_0_width;
   UInt_t          ljet_1;
   Float_t         ljet_1_MV2c10_FixedCutBEff_85_weight;
   Float_t         ljet_1_b_tag_score;
   Int_t           ljet_1_b_tagged_MV2c10_FixedCutBEff_85;
   Int_t           ljet_1_origin;
   TLorentzVector  *ljet_1_p4;
   Float_t         ljet_1_q;
   Int_t           ljet_1_type;
   Float_t         ljet_1_width;
   UInt_t          ljet_2;
   Float_t         ljet_2_MV2c10_FixedCutBEff_85_weight;
   Float_t         ljet_2_b_tag_score;
   Int_t           ljet_2_b_tagged_MV2c10_FixedCutBEff_85;
   Int_t           ljet_2_origin;
   TLorentzVector  *ljet_2_p4;
   Float_t         ljet_2_q;
   Int_t           ljet_2_type;
   Float_t         ljet_2_width;
   UInt_t          mc_channel_number;
   TLorentzVector  *met_reco_p4;
   TLorentzVector  *met_truth_p4;
   UInt_t          muTrigMatch_0_HLT_mu20_iloose_L1MU15;
   UInt_t          muTrigMatch_0_HLT_mu26_ivarmedium;
   UInt_t          muTrigMatch_0_HLT_mu50;
   UInt_t          muTrigMatch_0_trigger_matched;
   UInt_t          muTrigMatch_1_HLT_mu20_iloose_L1MU15;
   UInt_t          muTrigMatch_1_HLT_mu26_ivarmedium;
   UInt_t          muTrigMatch_1_HLT_mu50;
   UInt_t          muTrigMatch_1_trigger_matched;
   UInt_t          muon_0;
   Float_t         muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA;
   Float_t         muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA;
   Float_t         muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA;
   Float_t         muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA;
   Float_t         muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_0_NOMINAL_MuEffSF_Reco_QualMedium;
   Float_t         muon_0_NOMINAL_MuEffSF_TTVA;
   Float_t         muon_0_cluster_eta;
   Float_t         muon_0_cluster_eta_be2;
   Int_t           muon_0_id_bad;
   Int_t           muon_0_id_charge;
   Int_t           muon_0_id_loose;
   Int_t           muon_0_id_medium;
   Int_t           muon_0_id_tight;
   Int_t           muon_0_id_veryloose;
   UInt_t          muon_0_iso_FCLoose;
   UInt_t          muon_0_iso_FCTight;
   UInt_t          muon_0_iso_FixedCutLoose;
   UInt_t          muon_0_iso_FixedCutTight;
   UInt_t          muon_0_iso_FixedCutTightCaloOnly;
   UInt_t          muon_0_iso_Loose_FixedRad;
   UInt_t          muon_0_iso_TightTrackOnly_FixedRad;
   Int_t           muon_0_muonAuthor;
   Int_t           muon_0_muonType;
   Int_t           muon_0_origin;
   TLorentzVector  *muon_0_p4;
   Float_t         muon_0_q;
   Int_t           muon_0_type;
   UInt_t          muon_1;
   Float_t         muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_1_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA;
   Float_t         muon_1_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA;
   Float_t         muon_1_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA;
   Float_t         muon_1_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA;
   Float_t         muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;
   Float_t         muon_1_NOMINAL_MuEffSF_IsoLoose_FixedRad;
   Float_t         muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad;
   Float_t         muon_1_NOMINAL_MuEffSF_Reco_QualMedium;
   Float_t         muon_1_NOMINAL_MuEffSF_TTVA;
   Float_t         muon_1_cluster_eta;
   Float_t         muon_1_cluster_eta_be2;
   Int_t           muon_1_id_bad;
   Int_t           muon_1_id_charge;
   Int_t           muon_1_id_loose;
   Int_t           muon_1_id_medium;
   Int_t           muon_1_id_tight;
   Int_t           muon_1_id_veryloose;
   UInt_t          muon_1_iso_FCLoose;
   UInt_t          muon_1_iso_FCTight;
   UInt_t          muon_1_iso_FixedCutLoose;
   UInt_t          muon_1_iso_FixedCutTight;
   UInt_t          muon_1_iso_FixedCutTightCaloOnly;
   UInt_t          muon_1_iso_Loose_FixedRad;
   UInt_t          muon_1_iso_TightTrackOnly_FixedRad;
   Int_t           muon_1_muonAuthor;
   Int_t           muon_1_muonType;
   Int_t           muon_1_origin;
   TLorentzVector  *muon_1_p4;
   Float_t         muon_1_q;
   Int_t           muon_1_type;
   Float_t         n_actual_int;
   Float_t         n_actual_int_cor;
   Float_t         n_avg_int;
   Float_t         n_avg_int_cor;
   Int_t           n_bjets_MV2c10_FixedCutBEff_85;
   Int_t           n_electrons;
   Int_t           n_electrons_met;
   Int_t           n_electrons_olr;
   Int_t           n_jets;
   Int_t           n_jets_30;
   Int_t           n_jets_40;
   Int_t           n_jets_bad;
   Int_t           n_jets_mc_hs;
   Int_t           n_jets_met;
   Int_t           n_jets_olr;
   Int_t           n_muons;
   Int_t           n_muons_bad;
   Int_t           n_muons_loose;
   Int_t           n_muons_medium;
   Int_t           n_muons_met;
   Int_t           n_muons_olr;
   Int_t           n_muons_tight;
   Int_t           n_muons_veryloose;
   Int_t           n_photons;
   Int_t           n_pvx;
   Int_t           n_taus;
   Int_t           n_taus_met;
   Int_t           n_taus_olr;
   Int_t           n_taus_rnn_loose;
   Int_t           n_taus_rnn_medium;
   Int_t           n_taus_rnn_tight;
   Int_t           n_taus_rnn_veryloose;
   UInt_t          n_truth_gluon_jets;
   UInt_t          n_truth_jets;
   UInt_t          n_truth_jets_pt20_eta45;
   UInt_t          n_truth_quark_jets;
   Int_t           n_vx;
   UInt_t          run_number;
   Float_t         theory_weights_CT18_pdfset;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEW;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEW;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEW;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1;
   Float_t         theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2;
   Float_t         theory_weights_LHE3Weight_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05;
   Float_t         theory_weights_LHE3Weight_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEW;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEW;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEW;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3;
   Float_t         theory_weights_LHE3Weight_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2;
   Float_t         theory_weights_LHE3Weight_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1;
   Float_t         theory_weights_LHE3Weight_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2;
   Float_t         theory_weights_MSHT_pdfset;
   Float_t         theory_weights_alphaS_down;
   Float_t         theory_weights_alphaS_up;
   Float_t         triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         triggerSF_em_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         triggerSF_em_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         triggerSF_em_MUON_EFF_TrigSystUncertainty__1down;
   Float_t         triggerSF_em_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         triggerSF_em_NOMINAL;
   Double_t        weight_mc;
   UInt_t          useEvent;

   // List of branches
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_NOMINAL_pileup_combined_weight;   //!
   TBranch        *b_NOMINAL_pileup_random_run_number;   //!
   TBranch        *b_PRW_DATASF_1down_pileup_combined_weight;   //!
   TBranch        *b_PRW_DATASF_1down_pileup_random_run_number;   //!
   TBranch        *b_PRW_DATASF_1up_pileup_combined_weight;   //!
   TBranch        *b_PRW_DATASF_1up_pileup_random_run_number;   //!
   TBranch        *b_event_clean_EC_LooseBad;   //!
   TBranch        *b_event_clean_EC_TightBad;   //!
   TBranch        *b_event_clean_detector_core;   //!
   TBranch        *b_event_is_bad_batman;   //!
   TBranch        *b_event_number;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_central_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_central_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_forward_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_forward_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_ljet_0;   //!
   TBranch        *b_ljet_0_MV2c10_FixedCutBEff_85_weight;   //!
   TBranch        *b_ljet_0_b_tag_score;   //!
   TBranch        *b_ljet_0_b_tagged_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_ljet_0_origin;   //!
   TBranch        *b_ljet_0_p4;   //!
   TBranch        *b_ljet_0_q;   //!
   TBranch        *b_ljet_0_type;   //!
   TBranch        *b_ljet_0_width;   //!
   TBranch        *b_ljet_1;   //!
   TBranch        *b_ljet_1_MV2c10_FixedCutBEff_85_weight;   //!
   TBranch        *b_ljet_1_b_tag_score;   //!
   TBranch        *b_ljet_1_b_tagged_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_ljet_1_origin;   //!
   TBranch        *b_ljet_1_p4;   //!
   TBranch        *b_ljet_1_q;   //!
   TBranch        *b_ljet_1_type;   //!
   TBranch        *b_ljet_1_width;   //!
   TBranch        *b_ljet_2;   //!
   TBranch        *b_ljet_2_MV2c10_FixedCutBEff_85_weight;   //!
   TBranch        *b_ljet_2_b_tag_score;   //!
   TBranch        *b_ljet_2_b_tagged_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_ljet_2_origin;   //!
   TBranch        *b_ljet_2_p4;   //!
   TBranch        *b_ljet_2_q;   //!
   TBranch        *b_ljet_2_type;   //!
   TBranch        *b_ljet_2_width;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_met_reco_p4;   //!
   TBranch        *b_met_truth_p4;   //!
   TBranch        *b_muTrigMatch_0_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_muTrigMatch_0_HLT_mu26_ivarmedium;   //!
   TBranch        *b_muTrigMatch_0_HLT_mu50;   //!
   TBranch        *b_muTrigMatch_0_trigger_matched;   //!
   TBranch        *b_muTrigMatch_1_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_muTrigMatch_1_HLT_mu26_ivarmedium;   //!
   TBranch        *b_muTrigMatch_1_HLT_mu50;   //!
   TBranch        *b_muTrigMatch_1_trigger_matched;   //!
   TBranch        *b_muon_0;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA;   //!
   TBranch        *b_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA;   //!
   TBranch        *b_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA;   //!
   TBranch        *b_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_0_NOMINAL_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_0_NOMINAL_MuEffSF_TTVA;   //!
   TBranch        *b_muon_0_cluster_eta;   //!
   TBranch        *b_muon_0_cluster_eta_be2;   //!
   TBranch        *b_muon_0_id_bad;   //!
   TBranch        *b_muon_0_id_charge;   //!
   TBranch        *b_muon_0_id_loose;   //!
   TBranch        *b_muon_0_id_medium;   //!
   TBranch        *b_muon_0_id_tight;   //!
   TBranch        *b_muon_0_id_veryloose;   //!
   TBranch        *b_muon_0_iso_FCLoose;   //!
   TBranch        *b_muon_0_iso_FCTight;   //!
   TBranch        *b_muon_0_iso_FixedCutLoose;   //!
   TBranch        *b_muon_0_iso_FixedCutTight;   //!
   TBranch        *b_muon_0_iso_FixedCutTightCaloOnly;   //!
   TBranch        *b_muon_0_iso_Loose_FixedRad;   //!
   TBranch        *b_muon_0_iso_TightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_0_muonAuthor;   //!
   TBranch        *b_muon_0_muonType;   //!
   TBranch        *b_muon_0_origin;   //!
   TBranch        *b_muon_0_p4;   //!
   TBranch        *b_muon_0_q;   //!
   TBranch        *b_muon_0_type;   //!
   TBranch        *b_muon_1;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA;   //!
   TBranch        *b_muon_1_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA;   //!
   TBranch        *b_muon_1_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA;   //!
   TBranch        *b_muon_1_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;   //!
   TBranch        *b_muon_1_NOMINAL_MuEffSF_IsoLoose_FixedRad;   //!
   TBranch        *b_muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_1_NOMINAL_MuEffSF_Reco_QualMedium;   //!
   TBranch        *b_muon_1_NOMINAL_MuEffSF_TTVA;   //!
   TBranch        *b_muon_1_cluster_eta;   //!
   TBranch        *b_muon_1_cluster_eta_be2;   //!
   TBranch        *b_muon_1_id_bad;   //!
   TBranch        *b_muon_1_id_charge;   //!
   TBranch        *b_muon_1_id_loose;   //!
   TBranch        *b_muon_1_id_medium;   //!
   TBranch        *b_muon_1_id_tight;   //!
   TBranch        *b_muon_1_id_veryloose;   //!
   TBranch        *b_muon_1_iso_FCLoose;   //!
   TBranch        *b_muon_1_iso_FCTight;   //!
   TBranch        *b_muon_1_iso_FixedCutLoose;   //!
   TBranch        *b_muon_1_iso_FixedCutTight;   //!
   TBranch        *b_muon_1_iso_FixedCutTightCaloOnly;   //!
   TBranch        *b_muon_1_iso_Loose_FixedRad;   //!
   TBranch        *b_muon_1_iso_TightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_1_muonAuthor;   //!
   TBranch        *b_muon_1_muonType;   //!
   TBranch        *b_muon_1_origin;   //!
   TBranch        *b_muon_1_p4;   //!
   TBranch        *b_muon_1_q;   //!
   TBranch        *b_muon_1_type;   //!
   TBranch        *b_n_actual_int;   //!
   TBranch        *b_n_actual_int_cor;   //!
   TBranch        *b_n_avg_int;   //!
   TBranch        *b_n_avg_int_cor;   //!
   TBranch        *b_n_bjets_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_n_electrons;   //!
   TBranch        *b_n_electrons_met;   //!
   TBranch        *b_n_electrons_olr;   //!
   TBranch        *b_n_jets;   //!
   TBranch        *b_n_jets_30;   //!
   TBranch        *b_n_jets_40;   //!
   TBranch        *b_n_jets_bad;   //!
   TBranch        *b_n_jets_mc_hs;   //!
   TBranch        *b_n_jets_met;   //!
   TBranch        *b_n_jets_olr;   //!
   TBranch        *b_n_muons;   //!
   TBranch        *b_n_muons_bad;   //!
   TBranch        *b_n_muons_loose;   //!
   TBranch        *b_n_muons_medium;   //!
   TBranch        *b_n_muons_met;   //!
   TBranch        *b_n_muons_olr;   //!
   TBranch        *b_n_muons_tight;   //!
   TBranch        *b_n_muons_veryloose;   //!
   TBranch        *b_n_photons;   //!
   TBranch        *b_n_pvx;   //!
   TBranch        *b_n_taus;   //!
   TBranch        *b_n_taus_met;   //!
   TBranch        *b_n_taus_olr;   //!
   TBranch        *b_n_taus_rnn_loose;   //!
   TBranch        *b_n_taus_rnn_medium;   //!
   TBranch        *b_n_taus_rnn_tight;   //!
   TBranch        *b_n_taus_rnn_veryloose;   //!
   TBranch        *b_n_truth_gluon_jets;   //!
   TBranch        *b_n_truth_jets;   //!
   TBranch        *b_n_truth_jets_pt20_eta45;   //!
   TBranch        *b_n_truth_quark_jets;   //!
   TBranch        *b_n_vx;   //!
   TBranch        *b_run_number;   //!
   TBranch        *b_theory_weights_CT18_pdfset;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEW;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEW;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEW;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1;   //!
   TBranch        *b_theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEW;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEW;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEW;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1;   //!
   TBranch        *b_theory_weights_LHE3Weight_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2;   //!
   TBranch        *b_theory_weights_MSHT_pdfset;   //!
   TBranch        *b_theory_weights_alphaS_down;   //!
   TBranch        *b_theory_weights_alphaS_up;   //!
   TBranch        *b_triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_triggerSF_em_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_triggerSF_em_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_triggerSF_em_MUON_EFF_TrigSystUncertainty__1down;   //!
   TBranch        *b_triggerSF_em_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_triggerSF_em_NOMINAL;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_useEvent;   //!

   CLoopSYS(TTree *tree=0, const std::string& region = "", const std::string& sysType="", const std::string& sysHistogramName="", const std::string& sysIdentifier="");
   virtual ~CLoopSYS();
   virtual Int_t    Cut(/*Long64_t entry*/);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(double lumFactor, int z_sample, const std::string& key, int logLevel);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CLoopSYS_cxx
CLoopSYS::CLoopSYS(TTree *tree, const std::string& region, const std::string& sysType, const std::string& sysHistogramName, const std::string& sysIdentifier) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.dbaronmo.46291343._000001.TauID_Zll.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("user.dbaronmo.46291343._000001.TauID_Zll.root");
      }
      f->GetObject("NOMINAL",tree);

   }
   m_region = region;
   if (sysType == "") throw std::runtime_error("No valid systematic type provided to CLoopSYS");
   m_systematicType = sysType;
   m_systematicHistogramName = sysHistogramName;
   m_systematicIdentifier = sysIdentifier;
   Init(tree);
}

CLoopSYS::~CLoopSYS()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CLoopSYS::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CLoopSYS::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CLoopSYS::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ljet_0_p4 = 0;
   ljet_1_p4 = 0;
   ljet_2_p4 = 0;
   met_reco_p4 = 0;
   met_truth_p4 = 0;
   muon_0_p4 = 0;
   muon_1_p4 = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("NOMINAL_pileup_combined_weight", &NOMINAL_pileup_combined_weight, &b_NOMINAL_pileup_combined_weight);
   fChain->SetBranchAddress("NOMINAL_pileup_random_run_number", &NOMINAL_pileup_random_run_number, &b_NOMINAL_pileup_random_run_number);
   fChain->SetBranchAddress("PRW_DATASF_1down_pileup_combined_weight", &PRW_DATASF_1down_pileup_combined_weight, &b_PRW_DATASF_1down_pileup_combined_weight);
   fChain->SetBranchAddress("PRW_DATASF_1down_pileup_random_run_number", &PRW_DATASF_1down_pileup_random_run_number, &b_PRW_DATASF_1down_pileup_random_run_number);
   fChain->SetBranchAddress("PRW_DATASF_1up_pileup_combined_weight", &PRW_DATASF_1up_pileup_combined_weight, &b_PRW_DATASF_1up_pileup_combined_weight);
   fChain->SetBranchAddress("PRW_DATASF_1up_pileup_random_run_number", &PRW_DATASF_1up_pileup_random_run_number, &b_PRW_DATASF_1up_pileup_random_run_number);
   fChain->SetBranchAddress("event_clean_EC_LooseBad", &event_clean_EC_LooseBad, &b_event_clean_EC_LooseBad);
   fChain->SetBranchAddress("event_clean_EC_TightBad", &event_clean_EC_TightBad, &b_event_clean_EC_TightBad);
   fChain->SetBranchAddress("event_clean_detector_core", &event_clean_detector_core, &b_event_clean_detector_core);
   fChain->SetBranchAddress("event_is_bad_batman", &event_is_bad_batman, &b_event_is_bad_batman);
   fChain->SetBranchAddress("event_number", &event_number, &b_event_number);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT", &jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT, &b_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT", &jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT, &b_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT", &jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT, &b_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT", &jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT, &b_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT", &jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT, &b_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT", &jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT, &b_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT", &jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT, &b_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT", &jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT, &b_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_central_jets_global_effSF_JVT", &jet_NOMINAL_central_jets_global_effSF_JVT, &b_jet_NOMINAL_central_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_central_jets_global_ineffSF_JVT", &jet_NOMINAL_central_jets_global_ineffSF_JVT, &b_jet_NOMINAL_central_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_forward_jets_global_effSF_JVT", &jet_NOMINAL_forward_jets_global_effSF_JVT, &b_jet_NOMINAL_forward_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_forward_jets_global_ineffSF_JVT", &jet_NOMINAL_forward_jets_global_ineffSF_JVT, &b_jet_NOMINAL_forward_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85", &jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85, &b_jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85", &jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85, &b_jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("ljet_0", &ljet_0, &b_ljet_0);
   fChain->SetBranchAddress("ljet_0_MV2c10_FixedCutBEff_85_weight", &ljet_0_MV2c10_FixedCutBEff_85_weight, &b_ljet_0_MV2c10_FixedCutBEff_85_weight);
   fChain->SetBranchAddress("ljet_0_b_tag_score", &ljet_0_b_tag_score, &b_ljet_0_b_tag_score);
   fChain->SetBranchAddress("ljet_0_b_tagged_MV2c10_FixedCutBEff_85", &ljet_0_b_tagged_MV2c10_FixedCutBEff_85, &b_ljet_0_b_tagged_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("ljet_0_origin", &ljet_0_origin, &b_ljet_0_origin);
   fChain->SetBranchAddress("ljet_0_p4", &ljet_0_p4, &b_ljet_0_p4);
   fChain->SetBranchAddress("ljet_0_q", &ljet_0_q, &b_ljet_0_q);
   fChain->SetBranchAddress("ljet_0_type", &ljet_0_type, &b_ljet_0_type);
   fChain->SetBranchAddress("ljet_0_width", &ljet_0_width, &b_ljet_0_width);
   fChain->SetBranchAddress("ljet_1", &ljet_1, &b_ljet_1);
   fChain->SetBranchAddress("ljet_1_MV2c10_FixedCutBEff_85_weight", &ljet_1_MV2c10_FixedCutBEff_85_weight, &b_ljet_1_MV2c10_FixedCutBEff_85_weight);
   fChain->SetBranchAddress("ljet_1_b_tag_score", &ljet_1_b_tag_score, &b_ljet_1_b_tag_score);
   fChain->SetBranchAddress("ljet_1_b_tagged_MV2c10_FixedCutBEff_85", &ljet_1_b_tagged_MV2c10_FixedCutBEff_85, &b_ljet_1_b_tagged_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("ljet_1_origin", &ljet_1_origin, &b_ljet_1_origin);
   fChain->SetBranchAddress("ljet_1_p4", &ljet_1_p4, &b_ljet_1_p4);
   fChain->SetBranchAddress("ljet_1_q", &ljet_1_q, &b_ljet_1_q);
   fChain->SetBranchAddress("ljet_1_type", &ljet_1_type, &b_ljet_1_type);
   fChain->SetBranchAddress("ljet_1_width", &ljet_1_width, &b_ljet_1_width);
   fChain->SetBranchAddress("ljet_2", &ljet_2, &b_ljet_2);
   fChain->SetBranchAddress("ljet_2_MV2c10_FixedCutBEff_85_weight", &ljet_2_MV2c10_FixedCutBEff_85_weight, &b_ljet_2_MV2c10_FixedCutBEff_85_weight);
   fChain->SetBranchAddress("ljet_2_b_tag_score", &ljet_2_b_tag_score, &b_ljet_2_b_tag_score);
   fChain->SetBranchAddress("ljet_2_b_tagged_MV2c10_FixedCutBEff_85", &ljet_2_b_tagged_MV2c10_FixedCutBEff_85, &b_ljet_2_b_tagged_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("ljet_2_origin", &ljet_2_origin, &b_ljet_2_origin);
   fChain->SetBranchAddress("ljet_2_p4", &ljet_2_p4, &b_ljet_2_p4);
   fChain->SetBranchAddress("ljet_2_q", &ljet_2_q, &b_ljet_2_q);
   fChain->SetBranchAddress("ljet_2_type", &ljet_2_type, &b_ljet_2_type);
   fChain->SetBranchAddress("ljet_2_width", &ljet_2_width, &b_ljet_2_width);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("met_reco_p4", &met_reco_p4, &b_met_reco_p4);
   fChain->SetBranchAddress("met_truth_p4", &met_truth_p4, &b_met_truth_p4);
   fChain->SetBranchAddress("muTrigMatch_0_HLT_mu20_iloose_L1MU15", &muTrigMatch_0_HLT_mu20_iloose_L1MU15, &b_muTrigMatch_0_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("muTrigMatch_0_HLT_mu26_ivarmedium", &muTrigMatch_0_HLT_mu26_ivarmedium, &b_muTrigMatch_0_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("muTrigMatch_0_HLT_mu50", &muTrigMatch_0_HLT_mu50, &b_muTrigMatch_0_HLT_mu50);
   fChain->SetBranchAddress("muTrigMatch_0_trigger_matched", &muTrigMatch_0_trigger_matched, &b_muTrigMatch_0_trigger_matched);
   fChain->SetBranchAddress("muTrigMatch_1_HLT_mu20_iloose_L1MU15", &muTrigMatch_1_HLT_mu20_iloose_L1MU15, &b_muTrigMatch_1_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("muTrigMatch_1_HLT_mu26_ivarmedium", &muTrigMatch_1_HLT_mu26_ivarmedium, &b_muTrigMatch_1_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("muTrigMatch_1_HLT_mu50", &muTrigMatch_1_HLT_mu50, &b_muTrigMatch_1_HLT_mu50);
   fChain->SetBranchAddress("muTrigMatch_1_trigger_matched", &muTrigMatch_1_trigger_matched, &b_muTrigMatch_1_trigger_matched);
   fChain->SetBranchAddress("muon_0", &muon_0, &b_muon_0);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad", &muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad, &b_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad", &muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad, &b_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad", &muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad, &b_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad", &muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad, &b_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium", &muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium, &b_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA", &muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA, &b_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA", &muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA, &b_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA", &muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA, &b_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA", &muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA, &b_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad", &muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad, &b_muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_0_NOMINAL_MuEffSF_Reco_QualMedium", &muon_0_NOMINAL_MuEffSF_Reco_QualMedium, &b_muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_0_NOMINAL_MuEffSF_TTVA", &muon_0_NOMINAL_MuEffSF_TTVA, &b_muon_0_NOMINAL_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_0_cluster_eta", &muon_0_cluster_eta, &b_muon_0_cluster_eta);
   fChain->SetBranchAddress("muon_0_cluster_eta_be2", &muon_0_cluster_eta_be2, &b_muon_0_cluster_eta_be2);
   fChain->SetBranchAddress("muon_0_id_bad", &muon_0_id_bad, &b_muon_0_id_bad);
   fChain->SetBranchAddress("muon_0_id_charge", &muon_0_id_charge, &b_muon_0_id_charge);
   fChain->SetBranchAddress("muon_0_id_loose", &muon_0_id_loose, &b_muon_0_id_loose);
   fChain->SetBranchAddress("muon_0_id_medium", &muon_0_id_medium, &b_muon_0_id_medium);
   fChain->SetBranchAddress("muon_0_id_tight", &muon_0_id_tight, &b_muon_0_id_tight);
   fChain->SetBranchAddress("muon_0_id_veryloose", &muon_0_id_veryloose, &b_muon_0_id_veryloose);
   fChain->SetBranchAddress("muon_0_iso_FCLoose", &muon_0_iso_FCLoose, &b_muon_0_iso_FCLoose);
   fChain->SetBranchAddress("muon_0_iso_FCTight", &muon_0_iso_FCTight, &b_muon_0_iso_FCTight);
   fChain->SetBranchAddress("muon_0_iso_FixedCutLoose", &muon_0_iso_FixedCutLoose, &b_muon_0_iso_FixedCutLoose);
   fChain->SetBranchAddress("muon_0_iso_FixedCutTight", &muon_0_iso_FixedCutTight, &b_muon_0_iso_FixedCutTight);
   fChain->SetBranchAddress("muon_0_iso_FixedCutTightCaloOnly", &muon_0_iso_FixedCutTightCaloOnly, &b_muon_0_iso_FixedCutTightCaloOnly);
   fChain->SetBranchAddress("muon_0_iso_Loose_FixedRad", &muon_0_iso_Loose_FixedRad, &b_muon_0_iso_Loose_FixedRad);
   fChain->SetBranchAddress("muon_0_iso_TightTrackOnly_FixedRad", &muon_0_iso_TightTrackOnly_FixedRad, &b_muon_0_iso_TightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_0_muonAuthor", &muon_0_muonAuthor, &b_muon_0_muonAuthor);
   fChain->SetBranchAddress("muon_0_muonType", &muon_0_muonType, &b_muon_0_muonType);
   fChain->SetBranchAddress("muon_0_origin", &muon_0_origin, &b_muon_0_origin);
   fChain->SetBranchAddress("muon_0_p4", &muon_0_p4, &b_muon_0_p4);
   fChain->SetBranchAddress("muon_0_q", &muon_0_q, &b_muon_0_q);
   fChain->SetBranchAddress("muon_0_type", &muon_0_type, &b_muon_0_type);
   fChain->SetBranchAddress("muon_1", &muon_1, &b_muon_1);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad", &muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad, &b_muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_1_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad", &muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad, &b_muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_1_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad", &muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad, &b_muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_1_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad", &muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad, &b_muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_1_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium", &muon_1_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium, &b_muon_1_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA", &muon_1_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA, &b_muon_1_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA", &muon_1_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA, &b_muon_1_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA", &muon_1_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA, &b_muon_1_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA", &muon_1_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA, &b_muon_1_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_1_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium", &muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium, &b_muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium", &muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium, &b_muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
   fChain->SetBranchAddress("muon_1_NOMINAL_MuEffSF_IsoLoose_FixedRad", &muon_1_NOMINAL_MuEffSF_IsoLoose_FixedRad, &b_muon_1_NOMINAL_MuEffSF_IsoLoose_FixedRad);
   fChain->SetBranchAddress("muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad", &muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad, &b_muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_1_NOMINAL_MuEffSF_Reco_QualMedium", &muon_1_NOMINAL_MuEffSF_Reco_QualMedium, &b_muon_1_NOMINAL_MuEffSF_Reco_QualMedium);
   fChain->SetBranchAddress("muon_1_NOMINAL_MuEffSF_TTVA", &muon_1_NOMINAL_MuEffSF_TTVA, &b_muon_1_NOMINAL_MuEffSF_TTVA);
   fChain->SetBranchAddress("muon_1_cluster_eta", &muon_1_cluster_eta, &b_muon_1_cluster_eta);
   fChain->SetBranchAddress("muon_1_cluster_eta_be2", &muon_1_cluster_eta_be2, &b_muon_1_cluster_eta_be2);
   fChain->SetBranchAddress("muon_1_id_bad", &muon_1_id_bad, &b_muon_1_id_bad);
   fChain->SetBranchAddress("muon_1_id_charge", &muon_1_id_charge, &b_muon_1_id_charge);
   fChain->SetBranchAddress("muon_1_id_loose", &muon_1_id_loose, &b_muon_1_id_loose);
   fChain->SetBranchAddress("muon_1_id_medium", &muon_1_id_medium, &b_muon_1_id_medium);
   fChain->SetBranchAddress("muon_1_id_tight", &muon_1_id_tight, &b_muon_1_id_tight);
   fChain->SetBranchAddress("muon_1_id_veryloose", &muon_1_id_veryloose, &b_muon_1_id_veryloose);
   fChain->SetBranchAddress("muon_1_iso_FCLoose", &muon_1_iso_FCLoose, &b_muon_1_iso_FCLoose);
   fChain->SetBranchAddress("muon_1_iso_FCTight", &muon_1_iso_FCTight, &b_muon_1_iso_FCTight);
   fChain->SetBranchAddress("muon_1_iso_FixedCutLoose", &muon_1_iso_FixedCutLoose, &b_muon_1_iso_FixedCutLoose);
   fChain->SetBranchAddress("muon_1_iso_FixedCutTight", &muon_1_iso_FixedCutTight, &b_muon_1_iso_FixedCutTight);
   fChain->SetBranchAddress("muon_1_iso_FixedCutTightCaloOnly", &muon_1_iso_FixedCutTightCaloOnly, &b_muon_1_iso_FixedCutTightCaloOnly);
   fChain->SetBranchAddress("muon_1_iso_Loose_FixedRad", &muon_1_iso_Loose_FixedRad, &b_muon_1_iso_Loose_FixedRad);
   fChain->SetBranchAddress("muon_1_iso_TightTrackOnly_FixedRad", &muon_1_iso_TightTrackOnly_FixedRad, &b_muon_1_iso_TightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_1_muonAuthor", &muon_1_muonAuthor, &b_muon_1_muonAuthor);
   fChain->SetBranchAddress("muon_1_muonType", &muon_1_muonType, &b_muon_1_muonType);
   fChain->SetBranchAddress("muon_1_origin", &muon_1_origin, &b_muon_1_origin);
   fChain->SetBranchAddress("muon_1_p4", &muon_1_p4, &b_muon_1_p4);
   fChain->SetBranchAddress("muon_1_q", &muon_1_q, &b_muon_1_q);
   fChain->SetBranchAddress("muon_1_type", &muon_1_type, &b_muon_1_type);
   fChain->SetBranchAddress("n_actual_int", &n_actual_int, &b_n_actual_int);
   fChain->SetBranchAddress("n_actual_int_cor", &n_actual_int_cor, &b_n_actual_int_cor);
   fChain->SetBranchAddress("n_avg_int", &n_avg_int, &b_n_avg_int);
   fChain->SetBranchAddress("n_avg_int_cor", &n_avg_int_cor, &b_n_avg_int_cor);
   fChain->SetBranchAddress("n_bjets_MV2c10_FixedCutBEff_85", &n_bjets_MV2c10_FixedCutBEff_85, &b_n_bjets_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("n_electrons", &n_electrons, &b_n_electrons);
   fChain->SetBranchAddress("n_electrons_met", &n_electrons_met, &b_n_electrons_met);
   fChain->SetBranchAddress("n_electrons_olr", &n_electrons_olr, &b_n_electrons_olr);
   fChain->SetBranchAddress("n_jets", &n_jets, &b_n_jets);
   fChain->SetBranchAddress("n_jets_30", &n_jets_30, &b_n_jets_30);
   fChain->SetBranchAddress("n_jets_40", &n_jets_40, &b_n_jets_40);
   fChain->SetBranchAddress("n_jets_bad", &n_jets_bad, &b_n_jets_bad);
   fChain->SetBranchAddress("n_jets_mc_hs", &n_jets_mc_hs, &b_n_jets_mc_hs);
   fChain->SetBranchAddress("n_jets_met", &n_jets_met, &b_n_jets_met);
   fChain->SetBranchAddress("n_jets_olr", &n_jets_olr, &b_n_jets_olr);
   fChain->SetBranchAddress("n_muons", &n_muons, &b_n_muons);
   fChain->SetBranchAddress("n_muons_bad", &n_muons_bad, &b_n_muons_bad);
   fChain->SetBranchAddress("n_muons_loose", &n_muons_loose, &b_n_muons_loose);
   fChain->SetBranchAddress("n_muons_medium", &n_muons_medium, &b_n_muons_medium);
   fChain->SetBranchAddress("n_muons_met", &n_muons_met, &b_n_muons_met);
   fChain->SetBranchAddress("n_muons_olr", &n_muons_olr, &b_n_muons_olr);
   fChain->SetBranchAddress("n_muons_tight", &n_muons_tight, &b_n_muons_tight);
   fChain->SetBranchAddress("n_muons_veryloose", &n_muons_veryloose, &b_n_muons_veryloose);
   fChain->SetBranchAddress("n_photons", &n_photons, &b_n_photons);
   fChain->SetBranchAddress("n_pvx", &n_pvx, &b_n_pvx);
   fChain->SetBranchAddress("n_taus", &n_taus, &b_n_taus);
   fChain->SetBranchAddress("n_taus_met", &n_taus_met, &b_n_taus_met);
   fChain->SetBranchAddress("n_taus_olr", &n_taus_olr, &b_n_taus_olr);
   fChain->SetBranchAddress("n_taus_rnn_loose", &n_taus_rnn_loose, &b_n_taus_rnn_loose);
   fChain->SetBranchAddress("n_taus_rnn_medium", &n_taus_rnn_medium, &b_n_taus_rnn_medium);
   fChain->SetBranchAddress("n_taus_rnn_tight", &n_taus_rnn_tight, &b_n_taus_rnn_tight);
   fChain->SetBranchAddress("n_taus_rnn_veryloose", &n_taus_rnn_veryloose, &b_n_taus_rnn_veryloose);
   fChain->SetBranchAddress("n_truth_gluon_jets", &n_truth_gluon_jets, &b_n_truth_gluon_jets);
   fChain->SetBranchAddress("n_truth_jets", &n_truth_jets, &b_n_truth_jets);
   fChain->SetBranchAddress("n_truth_jets_pt20_eta45", &n_truth_jets_pt20_eta45, &b_n_truth_jets_pt20_eta45);
   fChain->SetBranchAddress("n_truth_quark_jets", &n_truth_quark_jets, &b_n_truth_quark_jets);
   fChain->SetBranchAddress("n_vx", &n_vx, &b_n_vx);
   fChain->SetBranchAddress("run_number", &run_number, &b_run_number);
   fChain->SetBranchAddress("theory_weights_CT18_pdfset", &theory_weights_CT18_pdfset, &b_theory_weights_CT18_pdfset);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05", &theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05, &b_theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1", &theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1, &b_theory_weights_LHE3Weight_ME_ONLY_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEW", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEW, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEW);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEW", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEW, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEW);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEW", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEW, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEW);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2", &theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2, &b_theory_weights_LHE3Weight_ME_ONLY_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1", &theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1, &b_theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2", &theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2, &b_theory_weights_LHE3Weight_ME_ONLY_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05", &theory_weights_LHE3Weight_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05, &b_theory_weights_LHE3Weight_MUR05_MUF05_PDF303200_PSMUR05_PSMUF05);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1", &theory_weights_LHE3Weight_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1, &b_theory_weights_LHE3Weight_MUR05_MUF1_PDF303200_PSMUR05_PSMUF1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05", &theory_weights_LHE3Weight_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05, &b_theory_weights_LHE3Weight_MUR1_MUF05_PDF303200_PSMUR1_PSMUF05);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEW", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEW, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEW);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_ASSEWLO1LO2LO3);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEW", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEW, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEW);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_EXPASSEWLO1LO2LO3);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEW", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEW, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEW);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3", &theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3, &b_theory_weights_LHE3Weight_MUR1_MUF1_PDF303200_MULTIASSEWLO1LO2LO3);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2", &theory_weights_LHE3Weight_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2, &b_theory_weights_LHE3Weight_MUR1_MUF2_PDF303200_PSMUR1_PSMUF2);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1", &theory_weights_LHE3Weight_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1, &b_theory_weights_LHE3Weight_MUR2_MUF1_PDF303200_PSMUR2_PSMUF1);
   fChain->SetBranchAddress("theory_weights_LHE3Weight_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2", &theory_weights_LHE3Weight_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2, &b_theory_weights_LHE3Weight_MUR2_MUF2_PDF303200_PSMUR2_PSMUF2);
   fChain->SetBranchAddress("theory_weights_MSHT_pdfset", &theory_weights_MSHT_pdfset, &b_theory_weights_MSHT_pdfset);
   fChain->SetBranchAddress("theory_weights_alphaS_down", &theory_weights_alphaS_down, &b_theory_weights_alphaS_down);
   fChain->SetBranchAddress("theory_weights_alphaS_up", &theory_weights_alphaS_up, &b_theory_weights_alphaS_up);
   fChain->SetBranchAddress("triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down", &triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down, &b_triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down);
   fChain->SetBranchAddress("triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up", &triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up, &b_triggerSF_em_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up);
   fChain->SetBranchAddress("triggerSF_em_MUON_EFF_TrigStatUncertainty__1down", &triggerSF_em_MUON_EFF_TrigStatUncertainty__1down, &b_triggerSF_em_MUON_EFF_TrigStatUncertainty__1down);
   fChain->SetBranchAddress("triggerSF_em_MUON_EFF_TrigStatUncertainty__1up", &triggerSF_em_MUON_EFF_TrigStatUncertainty__1up, &b_triggerSF_em_MUON_EFF_TrigStatUncertainty__1up);
   fChain->SetBranchAddress("triggerSF_em_MUON_EFF_TrigSystUncertainty__1down", &triggerSF_em_MUON_EFF_TrigSystUncertainty__1down, &b_triggerSF_em_MUON_EFF_TrigSystUncertainty__1down);
   fChain->SetBranchAddress("triggerSF_em_MUON_EFF_TrigSystUncertainty__1up", &triggerSF_em_MUON_EFF_TrigSystUncertainty__1up, &b_triggerSF_em_MUON_EFF_TrigSystUncertainty__1up);
   fChain->SetBranchAddress("triggerSF_em_NOMINAL", &triggerSF_em_NOMINAL, &b_triggerSF_em_NOMINAL);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("useEvent", &useEvent, &b_useEvent);
   Notify();
}

bool CLoopSYS::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void CLoopSYS::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CLoopSYS::Cut(/*Long64_t entry*/)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CLoopSYS_cxx
