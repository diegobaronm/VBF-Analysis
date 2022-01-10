//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec 10 15:57:16 2019 by ROOT version 6.18/04
// from TTree NOMINAL/NOMINAL
// found on file: user.sdysch.19616269._000010.LepUniv_ttbar.root
//////////////////////////////////////////////////////////

#ifndef CLoop_h
#define CLoop_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>


// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"

class CLoop {
  void Style(double lumFactor);
  void Book(double lumFactor);
  void Fill(double weight, int z_sample);

  #include "../Analysis.h"

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
   UInt_t          eleTrigMatch_0_HLT_e120_lhloose;
   UInt_t          eleTrigMatch_0_HLT_e140_lhloose_nod0;
   UInt_t          eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH;
   UInt_t          eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose;
   UInt_t          eleTrigMatch_0_HLT_e60_lhmedium;
   UInt_t          eleTrigMatch_0_HLT_e60_lhmedium_nod0;
   UInt_t          eleTrigMatch_0_trigger_matched;
   UInt_t          eleTrigMatch_1_HLT_e120_lhloose;
   UInt_t          eleTrigMatch_1_HLT_e140_lhloose_nod0;
   UInt_t          eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH;
   UInt_t          eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose;
   UInt_t          eleTrigMatch_1_HLT_e60_lhmedium;
   UInt_t          eleTrigMatch_1_HLT_e60_lhmedium_nod0;
   UInt_t          eleTrigMatch_1_trigger_matched;
   UInt_t          elec_0;
   Float_t         elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose;
   Float_t         elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight;
   Float_t         elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
   Float_t         elec_0_NOMINAL_EleEffSF_offline_RecoTrk;
   Float_t         elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13;
   Float_t         elec_0_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
   Float_t         elec_0_cluster_eta;
   Float_t         elec_0_cluster_eta_be2;
   Int_t           elec_0_id_bad;
   Int_t           elec_0_id_charge;
   Int_t           elec_0_id_loose;
   Int_t           elec_0_id_medium;
   Int_t           elec_0_id_tight;
   Int_t           elec_0_id_veryloose;
   UInt_t          elec_0_iso_FCLoose;
   UInt_t          elec_0_iso_FCTight;
   UInt_t          elec_0_iso_FixedCutLoose;
   UInt_t          elec_0_iso_FixedCutTight;
   UInt_t          elec_0_iso_FixedCutTightCaloOnly;
   UInt_t          elec_0_iso_Loose_FixedRad;
   UInt_t          elec_0_iso_TightTrackOnly_FixedRad;
   UInt_t          elec_0_matched;
   Int_t           elec_0_matched_classifierParticleOrigin;
   Int_t           elec_0_matched_classifierParticleOutcome;
   Int_t           elec_0_matched_classifierParticleType;
   Int_t           elec_0_matched_isHad;
   Int_t           elec_0_matched_mother_pdgId;
   Int_t           elec_0_matched_mother_status;
   Int_t           elec_0_matched_origin;
   TLorentzVector  *elec_0_matched_p4;
   Int_t           elec_0_matched_pdgId;
   Float_t         elec_0_matched_q;
   Int_t           elec_0_matched_status;
   Int_t           elec_0_matched_type;
   Int_t           elec_0_muonAuthor;
   Int_t           elec_0_muonType;
   Int_t           elec_0_origin;
   TLorentzVector  *elec_0_p4;
   Float_t         elec_0_q;
   Float_t         elec_0_trk_d0;
   Float_t         elec_0_trk_d0_sig;
   TLorentzVector  *elec_0_trk_p4;
   Float_t         elec_0_trk_pt_error;
   Float_t         elec_0_trk_pvx_z0;
   Float_t         elec_0_trk_pvx_z0_sig;
   Float_t         elec_0_trk_pvx_z0_sintheta;
   Int_t           elec_0_trk_vx;
   TVector3        *elec_0_trk_vx_v;
   Float_t         elec_0_trk_z0;
   Float_t         elec_0_trk_z0_sig;
   Float_t         elec_0_trk_z0_sintheta;
   Int_t           elec_0_type;
   UInt_t          elec_1;
   Float_t         elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose;
   Float_t         elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight;
   Float_t         elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
   Float_t         elec_1_NOMINAL_EleEffSF_offline_RecoTrk;
   Float_t         elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13;
   Float_t         elec_1_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
   Float_t         elec_1_cluster_eta;
   Float_t         elec_1_cluster_eta_be2;
   Int_t           elec_1_id_bad;
   Int_t           elec_1_id_charge;
   Int_t           elec_1_id_loose;
   Int_t           elec_1_id_medium;
   Int_t           elec_1_id_tight;
   Int_t           elec_1_id_veryloose;
   UInt_t          elec_1_iso_FCLoose;
   UInt_t          elec_1_iso_FCTight;
   UInt_t          elec_1_iso_FixedCutLoose;
   UInt_t          elec_1_iso_FixedCutTight;
   UInt_t          elec_1_iso_FixedCutTightCaloOnly;
   UInt_t          elec_1_iso_Loose_FixedRad;
   UInt_t          elec_1_iso_TightTrackOnly_FixedRad;
   UInt_t          elec_1_matched;
   Int_t           elec_1_matched_classifierParticleOrigin;
   Int_t           elec_1_matched_classifierParticleOutcome;
   Int_t           elec_1_matched_classifierParticleType;
   Int_t           elec_1_matched_isHad;
   Int_t           elec_1_matched_mother_pdgId;
   Int_t           elec_1_matched_mother_status;
   Int_t           elec_1_matched_origin;
   TLorentzVector  *elec_1_matched_p4;
   Int_t           elec_1_matched_pdgId;
   Float_t         elec_1_matched_q;
   Int_t           elec_1_matched_status;
   Int_t           elec_1_matched_type;
   Int_t           elec_1_muonAuthor;
   Int_t           elec_1_muonType;
   Int_t           elec_1_origin;
   TLorentzVector  *elec_1_p4;
   Float_t         elec_1_q;
   Float_t         elec_1_trk_d0;
   Float_t         elec_1_trk_d0_sig;
   TLorentzVector  *elec_1_trk_p4;
   Float_t         elec_1_trk_pt_error;
   Float_t         elec_1_trk_pvx_z0;
   Float_t         elec_1_trk_pvx_z0_sig;
   Float_t         elec_1_trk_pvx_z0_sintheta;
   Int_t           elec_1_trk_vx;
   TVector3        *elec_1_trk_vx_v;
   Float_t         elec_1_trk_z0;
   Float_t         elec_1_trk_z0_sig;
   Float_t         elec_1_trk_z0_sintheta;
   Int_t           elec_1_type;
   UInt_t          event_clean_EC_LooseBad;
   UInt_t          event_clean_EC_TightBad;
   Int_t           event_clean_detector_core;
   Int_t           event_is_bad_batman;
   ULong64_t       event_number;
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
   UInt_t          ljet_0_matched;
   Int_t           ljet_0_matched_classifierParticleOrigin;
   Int_t           ljet_0_matched_classifierParticleType;
   Int_t           ljet_0_matched_mother_pdgId;
   Int_t           ljet_0_matched_mother_status;
   Int_t           ljet_0_matched_origin;
   TLorentzVector  *ljet_0_matched_p4;
   Int_t           ljet_0_matched_pdgId;
   Float_t         ljet_0_matched_pz;
   Float_t         ljet_0_matched_q;
   Int_t           ljet_0_matched_status;
   Int_t           ljet_0_matched_type;
   Int_t           ljet_0_origin;
   TLorentzVector  *ljet_0_p4;
   Float_t         ljet_0_q;
   Int_t           ljet_0_type;
   Float_t         ljet_0_width;
   UInt_t          ljet_1;
   Float_t         ljet_1_MV2c10_FixedCutBEff_85_weight;
   Float_t         ljet_1_b_tag_score;
   Int_t           ljet_1_b_tagged_MV2c10_FixedCutBEff_85;
   UInt_t          ljet_1_matched;
   Int_t           ljet_1_matched_classifierParticleOrigin;
   Int_t           ljet_1_matched_classifierParticleType;
   Int_t           ljet_1_matched_mother_pdgId;
   Int_t           ljet_1_matched_mother_status;
   Int_t           ljet_1_matched_origin;
   TLorentzVector  *ljet_1_matched_p4;
   Int_t           ljet_1_matched_pdgId;
   Float_t         ljet_1_matched_pz;
   Float_t         ljet_1_matched_q;
   Int_t           ljet_1_matched_status;
   Int_t           ljet_1_matched_type;
   Int_t           ljet_1_origin;
   TLorentzVector  *ljet_1_p4;
   Float_t         ljet_1_q;
   Int_t           ljet_1_type;
   Float_t         ljet_1_width;
   UInt_t          ljet_2;
   Float_t         ljet_2_MV2c10_FixedCutBEff_85_weight;
   Float_t         ljet_2_b_tag_score;
   Int_t           ljet_2_b_tagged_MV2c10_FixedCutBEff_85;
   UInt_t          ljet_2_matched;
   Int_t           ljet_2_matched_classifierParticleOrigin;
   Int_t           ljet_2_matched_classifierParticleType;
   Int_t           ljet_2_matched_mother_pdgId;
   Int_t           ljet_2_matched_mother_status;
   Int_t           ljet_2_matched_origin;
   TLorentzVector  *ljet_2_matched_p4;
   Int_t           ljet_2_matched_pdgId;
   Float_t         ljet_2_matched_pz;
   Float_t         ljet_2_matched_q;
   Int_t           ljet_2_matched_status;
   Int_t           ljet_2_matched_type;
   Int_t           ljet_2_origin;
   TLorentzVector  *ljet_2_p4;
   Float_t         ljet_2_q;
   Int_t           ljet_2_type;
   Float_t         ljet_2_width;
   UInt_t          mc_channel_number;
   TLorentzVector  *met_reco_p4;
   TLorentzVector  *met_truth_p4;
   Int_t           muon_0_matched_classifierParticleOutcome;
   Int_t           muon_0_matched_isHad;
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
   Float_t         triggerSF_em_NOMINAL;
   TLorentzVector  *truth_Z_p4;
   Double_t        weight_mc;
   vector<float>   *weight_mc_v;

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
   TBranch        *b_eleTrigMatch_0_HLT_e120_lhloose;   //!
   TBranch        *b_eleTrigMatch_0_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_eleTrigMatch_0_HLT_e60_lhmedium;   //!
   TBranch        *b_eleTrigMatch_0_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_eleTrigMatch_0_trigger_matched;   //!
   TBranch        *b_eleTrigMatch_1_HLT_e120_lhloose;   //!
   TBranch        *b_eleTrigMatch_1_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_eleTrigMatch_1_HLT_e60_lhmedium;   //!
   TBranch        *b_eleTrigMatch_1_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_eleTrigMatch_1_trigger_matched;   //!
   TBranch        *b_elec_0;   //!
   TBranch        *b_elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose;   //!
   TBranch        *b_elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight;   //!
   TBranch        *b_elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;   //!
   TBranch        *b_elec_0_NOMINAL_EleEffSF_offline_RecoTrk;   //!
   TBranch        *b_elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13;   //!
   TBranch        *b_elec_0_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;   //!
   TBranch        *b_elec_0_cluster_eta;   //!
   TBranch        *b_elec_0_cluster_eta_be2;   //!
   TBranch        *b_elec_0_id_bad;   //!
   TBranch        *b_elec_0_id_charge;   //!
   TBranch        *b_elec_0_id_loose;   //!
   TBranch        *b_elec_0_id_medium;   //!
   TBranch        *b_elec_0_id_tight;   //!
   TBranch        *b_elec_0_id_veryloose;   //!
   TBranch        *b_elec_0_iso_FCLoose;   //!
   TBranch        *b_elec_0_iso_FCTight;   //!
   TBranch        *b_elec_0_iso_FixedCutLoose;   //!
   TBranch        *b_elec_0_iso_FixedCutTight;   //!
   TBranch        *b_elec_0_iso_FixedCutTightCaloOnly;   //!
   TBranch        *b_elec_0_iso_Loose_FixedRad;   //!
   TBranch        *b_elec_0_iso_TightTrackOnly_FixedRad;   //!
   TBranch        *b_elec_0_matched;   //!
   TBranch        *b_elec_0_matched_classifierParticleOrigin;   //!
   TBranch        *b_elec_0_matched_classifierParticleOutcome;   //!
   TBranch        *b_elec_0_matched_classifierParticleType;   //!
   TBranch        *b_elec_0_matched_isHad;   //!
   TBranch        *b_elec_0_matched_mother_pdgId;   //!
   TBranch        *b_elec_0_matched_mother_status;   //!
   TBranch        *b_elec_0_matched_origin;   //!
   TBranch        *b_elec_0_matched_p4;   //!
   TBranch        *b_elec_0_matched_pdgId;   //!
   TBranch        *b_elec_0_matched_q;   //!
   TBranch        *b_elec_0_matched_status;   //!
   TBranch        *b_elec_0_matched_type;   //!
   TBranch        *b_elec_0_muonAuthor;   //!
   TBranch        *b_elec_0_muonType;   //!
   TBranch        *b_elec_0_origin;   //!
   TBranch        *b_elec_0_p4;   //!
   TBranch        *b_elec_0_q;   //!
   TBranch        *b_elec_0_trk_d0;   //!
   TBranch        *b_elec_0_trk_d0_sig;   //!
   TBranch        *b_elec_0_trk_p4;   //!
   TBranch        *b_elec_0_trk_pt_error;   //!
   TBranch        *b_elec_0_trk_pvx_z0;   //!
   TBranch        *b_elec_0_trk_pvx_z0_sig;   //!
   TBranch        *b_elec_0_trk_pvx_z0_sintheta;   //!
   TBranch        *b_elec_0_trk_vx;   //!
   TBranch        *b_elec_0_trk_vx_v;   //!
   TBranch        *b_elec_0_trk_z0;   //!
   TBranch        *b_elec_0_trk_z0_sig;   //!
   TBranch        *b_elec_0_trk_z0_sintheta;   //!
   TBranch        *b_elec_0_type;   //!
   TBranch        *b_elec_1;   //!
   TBranch        *b_elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose;   //!
   TBranch        *b_elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight;   //!
   TBranch        *b_elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;   //!
   TBranch        *b_elec_1_NOMINAL_EleEffSF_offline_RecoTrk;   //!
   TBranch        *b_elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13;   //!
   TBranch        *b_elec_1_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;   //!
   TBranch        *b_elec_1_cluster_eta;   //!
   TBranch        *b_elec_1_cluster_eta_be2;   //!
   TBranch        *b_elec_1_id_bad;   //!
   TBranch        *b_elec_1_id_charge;   //!
   TBranch        *b_elec_1_id_loose;   //!
   TBranch        *b_elec_1_id_medium;   //!
   TBranch        *b_elec_1_id_tight;   //!
   TBranch        *b_elec_1_id_veryloose;   //!
   TBranch        *b_elec_1_iso_FCLoose;   //!
   TBranch        *b_elec_1_iso_FCTight;   //!
   TBranch        *b_elec_1_iso_FixedCutLoose;   //!
   TBranch        *b_elec_1_iso_FixedCutTight;   //!
   TBranch        *b_elec_1_iso_FixedCutTightCaloOnly;   //!
   TBranch        *b_elec_1_iso_Loose_FixedRad;   //!
   TBranch        *b_elec_1_iso_TightTrackOnly_FixedRad;   //!
   TBranch        *b_elec_1_matched;   //!
   TBranch        *b_elec_1_matched_classifierParticleOrigin;   //!
   TBranch        *b_elec_1_matched_classifierParticleOutcome;   //!
   TBranch        *b_elec_1_matched_classifierParticleType;   //!
   TBranch        *b_elec_1_matched_isHad;   //!
   TBranch        *b_elec_1_matched_mother_pdgId;   //!
   TBranch        *b_elec_1_matched_mother_status;   //!
   TBranch        *b_elec_1_matched_origin;   //!
   TBranch        *b_elec_1_matched_p4;   //!
   TBranch        *b_elec_1_matched_pdgId;   //!
   TBranch        *b_elec_1_matched_q;   //!
   TBranch        *b_elec_1_matched_status;   //!
   TBranch        *b_elec_1_matched_type;   //!
   TBranch        *b_elec_1_muonAuthor;   //!
   TBranch        *b_elec_1_muonType;   //!
   TBranch        *b_elec_1_origin;   //!
   TBranch        *b_elec_1_p4;   //!
   TBranch        *b_elec_1_q;   //!
   TBranch        *b_elec_1_trk_d0;   //!
   TBranch        *b_elec_1_trk_d0_sig;   //!
   TBranch        *b_elec_1_trk_p4;   //!
   TBranch        *b_elec_1_trk_pt_error;   //!
   TBranch        *b_elec_1_trk_pvx_z0;   //!
   TBranch        *b_elec_1_trk_pvx_z0_sig;   //!
   TBranch        *b_elec_1_trk_pvx_z0_sintheta;   //!
   TBranch        *b_elec_1_trk_vx;   //!
   TBranch        *b_elec_1_trk_vx_v;   //!
   TBranch        *b_elec_1_trk_z0;   //!
   TBranch        *b_elec_1_trk_z0_sig;   //!
   TBranch        *b_elec_1_trk_z0_sintheta;   //!
   TBranch        *b_elec_1_type;   //!
   TBranch        *b_event_clean_EC_LooseBad;   //!
   TBranch        *b_event_clean_EC_TightBad;   //!
   TBranch        *b_event_clean_detector_core;   //!
   TBranch        *b_event_is_bad_batman;   //!
   TBranch        *b_event_number;   //!
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
   TBranch        *b_ljet_0_matched;   //!
   TBranch        *b_ljet_0_matched_classifierParticleOrigin;   //!
   TBranch        *b_ljet_0_matched_classifierParticleType;   //!
   TBranch        *b_ljet_0_matched_mother_pdgId;   //!
   TBranch        *b_ljet_0_matched_mother_status;   //!
   TBranch        *b_ljet_0_matched_origin;   //!
   TBranch        *b_ljet_0_matched_p4;   //!
   TBranch        *b_ljet_0_matched_pdgId;   //!
   TBranch        *b_ljet_0_matched_pz;   //!
   TBranch        *b_ljet_0_matched_q;   //!
   TBranch        *b_ljet_0_matched_status;   //!
   TBranch        *b_ljet_0_matched_type;   //!
   TBranch        *b_ljet_0_origin;   //!
   TBranch        *b_ljet_0_p4;   //!
   TBranch        *b_ljet_0_q;   //!
   TBranch        *b_ljet_0_type;   //!
   TBranch        *b_ljet_0_width;   //!
   TBranch        *b_ljet_1;   //!
   TBranch        *b_ljet_1_MV2c10_FixedCutBEff_85_weight;   //!
   TBranch        *b_ljet_1_b_tag_score;   //!
   TBranch        *b_ljet_1_b_tagged_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_ljet_1_matched;   //!
   TBranch        *b_ljet_1_matched_classifierParticleOrigin;   //!
   TBranch        *b_ljet_1_matched_classifierParticleType;   //!
   TBranch        *b_ljet_1_matched_mother_pdgId;   //!
   TBranch        *b_ljet_1_matched_mother_status;   //!
   TBranch        *b_ljet_1_matched_origin;   //!
   TBranch        *b_ljet_1_matched_p4;   //!
   TBranch        *b_ljet_1_matched_pdgId;   //!
   TBranch        *b_ljet_1_matched_pz;   //!
   TBranch        *b_ljet_1_matched_q;   //!
   TBranch        *b_ljet_1_matched_status;   //!
   TBranch        *b_ljet_1_matched_type;   //!
   TBranch        *b_ljet_1_origin;   //!
   TBranch        *b_ljet_1_p4;   //!
   TBranch        *b_ljet_1_q;   //!
   TBranch        *b_ljet_1_type;   //!
   TBranch        *b_ljet_1_width;   //!
   TBranch        *b_ljet_2;   //!
   TBranch        *b_ljet_2_MV2c10_FixedCutBEff_85_weight;   //!
   TBranch        *b_ljet_2_b_tag_score;   //!
   TBranch        *b_ljet_2_b_tagged_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_ljet_2_matched;   //!
   TBranch        *b_ljet_2_matched_classifierParticleOrigin;   //!
   TBranch        *b_ljet_2_matched_classifierParticleType;   //!
   TBranch        *b_ljet_2_matched_mother_pdgId;   //!
   TBranch        *b_ljet_2_matched_mother_status;   //!
   TBranch        *b_ljet_2_matched_origin;   //!
   TBranch        *b_ljet_2_matched_p4;   //!
   TBranch        *b_ljet_2_matched_pdgId;   //!
   TBranch        *b_ljet_2_matched_pz;   //!
   TBranch        *b_ljet_2_matched_q;   //!
   TBranch        *b_ljet_2_matched_status;   //!
   TBranch        *b_ljet_2_matched_type;   //!
   TBranch        *b_ljet_2_origin;   //!
   TBranch        *b_ljet_2_p4;   //!
   TBranch        *b_ljet_2_q;   //!
   TBranch        *b_ljet_2_type;   //!
   TBranch        *b_ljet_2_width;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_met_reco_p4;   //!
   TBranch        *b_met_truth_p4;   //!
   TBranch        *b_muon_0_matched_classifierParticleOutcome;   //!
   TBranch        *b_muon_0_matched_isHad;   //!
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
   TBranch        *b_triggerSF_em_NOMINAL;   //!
   TBranch        *b_truth_Z_p4;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_mc_v;   //!

   CLoop(TTree *tree=0);
   virtual ~CLoop();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(double lumFactor, bool fastMode, int z_sample, std::string key);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CLoop_cxx
CLoop::CLoop(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.sdysch.19616269._000010.LepUniv_ttbar.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("user.sdysch.19616269._000010.LepUniv_ttbar.root");
      }
      f->GetObject("NOMINAL",tree);

   }
   Init(tree);
}

CLoop::~CLoop()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CLoop::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CLoop::LoadTree(Long64_t entry)
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

void CLoop::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   elec_0_matched_p4 = 0;
   elec_0_p4 = 0;
   elec_0_trk_p4 = 0;
   elec_0_trk_vx_v = 0;
   elec_1_matched_p4 = 0;
   elec_1_p4 = 0;
   elec_1_trk_p4 = 0;
   elec_1_trk_vx_v = 0;
   ljet_0_matched_p4 = 0;
   ljet_0_p4 = 0;
   ljet_1_matched_p4 = 0;
   ljet_1_p4 = 0;
   ljet_2_matched_p4 = 0;
   ljet_2_p4 = 0;
   met_reco_p4 = 0;
   met_truth_p4 = 0;
   truth_Z_p4 = 0;
   weight_mc_v = 0;
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
   fChain->SetBranchAddress("eleTrigMatch_0_HLT_e120_lhloose", &eleTrigMatch_0_HLT_e120_lhloose, &b_eleTrigMatch_0_HLT_e120_lhloose);
   fChain->SetBranchAddress("eleTrigMatch_0_HLT_e140_lhloose_nod0", &eleTrigMatch_0_HLT_e140_lhloose_nod0, &b_eleTrigMatch_0_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH", &eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH, &b_eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose", &eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose, &b_eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("eleTrigMatch_0_HLT_e60_lhmedium", &eleTrigMatch_0_HLT_e60_lhmedium, &b_eleTrigMatch_0_HLT_e60_lhmedium);
   fChain->SetBranchAddress("eleTrigMatch_0_HLT_e60_lhmedium_nod0", &eleTrigMatch_0_HLT_e60_lhmedium_nod0, &b_eleTrigMatch_0_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("eleTrigMatch_0_trigger_matched", &eleTrigMatch_0_trigger_matched, &b_eleTrigMatch_0_trigger_matched);
   fChain->SetBranchAddress("eleTrigMatch_1_HLT_e120_lhloose", &eleTrigMatch_1_HLT_e120_lhloose, &b_eleTrigMatch_1_HLT_e120_lhloose);
   fChain->SetBranchAddress("eleTrigMatch_1_HLT_e140_lhloose_nod0", &eleTrigMatch_1_HLT_e140_lhloose_nod0, &b_eleTrigMatch_1_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH", &eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH, &b_eleTrigMatch_1_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose", &eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose, &b_eleTrigMatch_1_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("eleTrigMatch_1_HLT_e60_lhmedium", &eleTrigMatch_1_HLT_e60_lhmedium, &b_eleTrigMatch_1_HLT_e60_lhmedium);
   fChain->SetBranchAddress("eleTrigMatch_1_HLT_e60_lhmedium_nod0", &eleTrigMatch_1_HLT_e60_lhmedium_nod0, &b_eleTrigMatch_1_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("eleTrigMatch_1_trigger_matched", &eleTrigMatch_1_trigger_matched, &b_eleTrigMatch_1_trigger_matched);
   fChain->SetBranchAddress("elec_0", &elec_0, &b_elec_0);
   fChain->SetBranchAddress("elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose", &elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose, &b_elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose);
   fChain->SetBranchAddress("elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight", &elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight, &b_elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight);
   fChain->SetBranchAddress("elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight", &elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight, &b_elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
   fChain->SetBranchAddress("elec_0_NOMINAL_EleEffSF_offline_RecoTrk", &elec_0_NOMINAL_EleEffSF_offline_RecoTrk, &b_elec_0_NOMINAL_EleEffSF_offline_RecoTrk);
   fChain->SetBranchAddress("elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13", &elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13, &b_elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13);
   fChain->SetBranchAddress("elec_0_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight", &elec_0_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight, &b_elec_0_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
   fChain->SetBranchAddress("elec_0_cluster_eta", &elec_0_cluster_eta, &b_elec_0_cluster_eta);
   fChain->SetBranchAddress("elec_0_cluster_eta_be2", &elec_0_cluster_eta_be2, &b_elec_0_cluster_eta_be2);
   fChain->SetBranchAddress("elec_0_id_bad", &elec_0_id_bad, &b_elec_0_id_bad);
   fChain->SetBranchAddress("elec_0_id_charge", &elec_0_id_charge, &b_elec_0_id_charge);
   fChain->SetBranchAddress("elec_0_id_loose", &elec_0_id_loose, &b_elec_0_id_loose);
   fChain->SetBranchAddress("elec_0_id_medium", &elec_0_id_medium, &b_elec_0_id_medium);
   fChain->SetBranchAddress("elec_0_id_tight", &elec_0_id_tight, &b_elec_0_id_tight);
   fChain->SetBranchAddress("elec_0_id_veryloose", &elec_0_id_veryloose, &b_elec_0_id_veryloose);
   fChain->SetBranchAddress("elec_0_iso_FCLoose", &elec_0_iso_FCLoose, &b_elec_0_iso_FCLoose);
   fChain->SetBranchAddress("elec_0_iso_FCTight", &elec_0_iso_FCTight, &b_elec_0_iso_FCTight);
   fChain->SetBranchAddress("elec_0_iso_FixedCutLoose", &elec_0_iso_FixedCutLoose, &b_elec_0_iso_FixedCutLoose);
   fChain->SetBranchAddress("elec_0_iso_FixedCutTight", &elec_0_iso_FixedCutTight, &b_elec_0_iso_FixedCutTight);
   fChain->SetBranchAddress("elec_0_iso_FixedCutTightCaloOnly", &elec_0_iso_FixedCutTightCaloOnly, &b_elec_0_iso_FixedCutTightCaloOnly);
   fChain->SetBranchAddress("elec_0_iso_Loose_FixedRad", &elec_0_iso_Loose_FixedRad, &b_elec_0_iso_Loose_FixedRad);
   fChain->SetBranchAddress("elec_0_iso_TightTrackOnly_FixedRad", &elec_0_iso_TightTrackOnly_FixedRad, &b_elec_0_iso_TightTrackOnly_FixedRad);
   fChain->SetBranchAddress("elec_0_matched", &elec_0_matched, &b_elec_0_matched);
   fChain->SetBranchAddress("elec_0_matched_classifierParticleOrigin", &elec_0_matched_classifierParticleOrigin, &b_elec_0_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("elec_0_matched_classifierParticleOutcome", &elec_0_matched_classifierParticleOutcome, &b_elec_0_matched_classifierParticleOutcome);
   fChain->SetBranchAddress("elec_0_matched_classifierParticleType", &elec_0_matched_classifierParticleType, &b_elec_0_matched_classifierParticleType);
   fChain->SetBranchAddress("elec_0_matched_isHad", &elec_0_matched_isHad, &b_elec_0_matched_isHad);
   fChain->SetBranchAddress("elec_0_matched_mother_pdgId", &elec_0_matched_mother_pdgId, &b_elec_0_matched_mother_pdgId);
   fChain->SetBranchAddress("elec_0_matched_mother_status", &elec_0_matched_mother_status, &b_elec_0_matched_mother_status);
   fChain->SetBranchAddress("elec_0_matched_origin", &elec_0_matched_origin, &b_elec_0_matched_origin);
   fChain->SetBranchAddress("elec_0_matched_p4", &elec_0_matched_p4, &b_elec_0_matched_p4);
   fChain->SetBranchAddress("elec_0_matched_pdgId", &elec_0_matched_pdgId, &b_elec_0_matched_pdgId);
   fChain->SetBranchAddress("elec_0_matched_q", &elec_0_matched_q, &b_elec_0_matched_q);
   fChain->SetBranchAddress("elec_0_matched_status", &elec_0_matched_status, &b_elec_0_matched_status);
   fChain->SetBranchAddress("elec_0_matched_type", &elec_0_matched_type, &b_elec_0_matched_type);
   fChain->SetBranchAddress("elec_0_muonAuthor", &elec_0_muonAuthor, &b_elec_0_muonAuthor);
   fChain->SetBranchAddress("elec_0_muonType", &elec_0_muonType, &b_elec_0_muonType);
   fChain->SetBranchAddress("elec_0_origin", &elec_0_origin, &b_elec_0_origin);
   fChain->SetBranchAddress("elec_0_p4", &elec_0_p4, &b_elec_0_p4);
   fChain->SetBranchAddress("elec_0_q", &elec_0_q, &b_elec_0_q);
   fChain->SetBranchAddress("elec_0_trk_d0", &elec_0_trk_d0, &b_elec_0_trk_d0);
   fChain->SetBranchAddress("elec_0_trk_d0_sig", &elec_0_trk_d0_sig, &b_elec_0_trk_d0_sig);
   fChain->SetBranchAddress("elec_0_trk_p4", &elec_0_trk_p4, &b_elec_0_trk_p4);
   fChain->SetBranchAddress("elec_0_trk_pt_error", &elec_0_trk_pt_error, &b_elec_0_trk_pt_error);
   fChain->SetBranchAddress("elec_0_trk_pvx_z0", &elec_0_trk_pvx_z0, &b_elec_0_trk_pvx_z0);
   fChain->SetBranchAddress("elec_0_trk_pvx_z0_sig", &elec_0_trk_pvx_z0_sig, &b_elec_0_trk_pvx_z0_sig);
   fChain->SetBranchAddress("elec_0_trk_pvx_z0_sintheta", &elec_0_trk_pvx_z0_sintheta, &b_elec_0_trk_pvx_z0_sintheta);
   fChain->SetBranchAddress("elec_0_trk_vx", &elec_0_trk_vx, &b_elec_0_trk_vx);
   fChain->SetBranchAddress("elec_0_trk_vx_v", &elec_0_trk_vx_v, &b_elec_0_trk_vx_v);
   fChain->SetBranchAddress("elec_0_trk_z0", &elec_0_trk_z0, &b_elec_0_trk_z0);
   fChain->SetBranchAddress("elec_0_trk_z0_sig", &elec_0_trk_z0_sig, &b_elec_0_trk_z0_sig);
   fChain->SetBranchAddress("elec_0_trk_z0_sintheta", &elec_0_trk_z0_sintheta, &b_elec_0_trk_z0_sintheta);
   fChain->SetBranchAddress("elec_0_type", &elec_0_type, &b_elec_0_type);
   fChain->SetBranchAddress("elec_1", &elec_1, &b_elec_1);
   fChain->SetBranchAddress("elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose", &elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose, &b_elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose);
   fChain->SetBranchAddress("elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight", &elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight, &b_elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight);
   fChain->SetBranchAddress("elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight", &elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight, &b_elec_1_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
   fChain->SetBranchAddress("elec_1_NOMINAL_EleEffSF_offline_RecoTrk", &elec_1_NOMINAL_EleEffSF_offline_RecoTrk, &b_elec_1_NOMINAL_EleEffSF_offline_RecoTrk);
   fChain->SetBranchAddress("elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13", &elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13, &b_elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13);
   fChain->SetBranchAddress("elec_1_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight", &elec_1_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight, &b_elec_1_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight);
   fChain->SetBranchAddress("elec_1_cluster_eta", &elec_1_cluster_eta, &b_elec_1_cluster_eta);
   fChain->SetBranchAddress("elec_1_cluster_eta_be2", &elec_1_cluster_eta_be2, &b_elec_1_cluster_eta_be2);
   fChain->SetBranchAddress("elec_1_id_bad", &elec_1_id_bad, &b_elec_1_id_bad);
   fChain->SetBranchAddress("elec_1_id_charge", &elec_1_id_charge, &b_elec_1_id_charge);
   fChain->SetBranchAddress("elec_1_id_loose", &elec_1_id_loose, &b_elec_1_id_loose);
   fChain->SetBranchAddress("elec_1_id_medium", &elec_1_id_medium, &b_elec_1_id_medium);
   fChain->SetBranchAddress("elec_1_id_tight", &elec_1_id_tight, &b_elec_1_id_tight);
   fChain->SetBranchAddress("elec_1_id_veryloose", &elec_1_id_veryloose, &b_elec_1_id_veryloose);
   fChain->SetBranchAddress("elec_1_iso_FCLoose", &elec_1_iso_FCLoose, &b_elec_1_iso_FCLoose);
   fChain->SetBranchAddress("elec_1_iso_FCTight", &elec_1_iso_FCTight, &b_elec_1_iso_FCTight);
   fChain->SetBranchAddress("elec_1_iso_FixedCutLoose", &elec_1_iso_FixedCutLoose, &b_elec_1_iso_FixedCutLoose);
   fChain->SetBranchAddress("elec_1_iso_FixedCutTight", &elec_1_iso_FixedCutTight, &b_elec_1_iso_FixedCutTight);
   fChain->SetBranchAddress("elec_1_iso_FixedCutTightCaloOnly", &elec_1_iso_FixedCutTightCaloOnly, &b_elec_1_iso_FixedCutTightCaloOnly);
   fChain->SetBranchAddress("elec_1_iso_Loose_FixedRad", &elec_1_iso_Loose_FixedRad, &b_elec_1_iso_Loose_FixedRad);
   fChain->SetBranchAddress("elec_1_iso_TightTrackOnly_FixedRad", &elec_1_iso_TightTrackOnly_FixedRad, &b_elec_1_iso_TightTrackOnly_FixedRad);
   fChain->SetBranchAddress("elec_1_matched", &elec_1_matched, &b_elec_1_matched);
   fChain->SetBranchAddress("elec_1_matched_classifierParticleOrigin", &elec_1_matched_classifierParticleOrigin, &b_elec_1_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("elec_1_matched_classifierParticleOutcome", &elec_1_matched_classifierParticleOutcome, &b_elec_1_matched_classifierParticleOutcome);
   fChain->SetBranchAddress("elec_1_matched_classifierParticleType", &elec_1_matched_classifierParticleType, &b_elec_1_matched_classifierParticleType);
   fChain->SetBranchAddress("elec_1_matched_isHad", &elec_1_matched_isHad, &b_elec_1_matched_isHad);
   fChain->SetBranchAddress("elec_1_matched_mother_pdgId", &elec_1_matched_mother_pdgId, &b_elec_1_matched_mother_pdgId);
   fChain->SetBranchAddress("elec_1_matched_mother_status", &elec_1_matched_mother_status, &b_elec_1_matched_mother_status);
   fChain->SetBranchAddress("elec_1_matched_origin", &elec_1_matched_origin, &b_elec_1_matched_origin);
   fChain->SetBranchAddress("elec_1_matched_p4", &elec_1_matched_p4, &b_elec_1_matched_p4);
   fChain->SetBranchAddress("elec_1_matched_pdgId", &elec_1_matched_pdgId, &b_elec_1_matched_pdgId);
   fChain->SetBranchAddress("elec_1_matched_q", &elec_1_matched_q, &b_elec_1_matched_q);
   fChain->SetBranchAddress("elec_1_matched_status", &elec_1_matched_status, &b_elec_1_matched_status);
   fChain->SetBranchAddress("elec_1_matched_type", &elec_1_matched_type, &b_elec_1_matched_type);
   fChain->SetBranchAddress("elec_1_muonAuthor", &elec_1_muonAuthor, &b_elec_1_muonAuthor);
   fChain->SetBranchAddress("elec_1_muonType", &elec_1_muonType, &b_elec_1_muonType);
   fChain->SetBranchAddress("elec_1_origin", &elec_1_origin, &b_elec_1_origin);
   fChain->SetBranchAddress("elec_1_p4", &elec_1_p4, &b_elec_1_p4);
   fChain->SetBranchAddress("elec_1_q", &elec_1_q, &b_elec_1_q);
   fChain->SetBranchAddress("elec_1_trk_d0", &elec_1_trk_d0, &b_elec_1_trk_d0);
   fChain->SetBranchAddress("elec_1_trk_d0_sig", &elec_1_trk_d0_sig, &b_elec_1_trk_d0_sig);
   fChain->SetBranchAddress("elec_1_trk_p4", &elec_1_trk_p4, &b_elec_1_trk_p4);
   fChain->SetBranchAddress("elec_1_trk_pt_error", &elec_1_trk_pt_error, &b_elec_1_trk_pt_error);
   fChain->SetBranchAddress("elec_1_trk_pvx_z0", &elec_1_trk_pvx_z0, &b_elec_1_trk_pvx_z0);
   fChain->SetBranchAddress("elec_1_trk_pvx_z0_sig", &elec_1_trk_pvx_z0_sig, &b_elec_1_trk_pvx_z0_sig);
   fChain->SetBranchAddress("elec_1_trk_pvx_z0_sintheta", &elec_1_trk_pvx_z0_sintheta, &b_elec_1_trk_pvx_z0_sintheta);
   fChain->SetBranchAddress("elec_1_trk_vx", &elec_1_trk_vx, &b_elec_1_trk_vx);
   fChain->SetBranchAddress("elec_1_trk_vx_v", &elec_1_trk_vx_v, &b_elec_1_trk_vx_v);
   fChain->SetBranchAddress("elec_1_trk_z0", &elec_1_trk_z0, &b_elec_1_trk_z0);
   fChain->SetBranchAddress("elec_1_trk_z0_sig", &elec_1_trk_z0_sig, &b_elec_1_trk_z0_sig);
   fChain->SetBranchAddress("elec_1_trk_z0_sintheta", &elec_1_trk_z0_sintheta, &b_elec_1_trk_z0_sintheta);
   fChain->SetBranchAddress("elec_1_type", &elec_1_type, &b_elec_1_type);
   fChain->SetBranchAddress("event_clean_EC_LooseBad", &event_clean_EC_LooseBad, &b_event_clean_EC_LooseBad);
   fChain->SetBranchAddress("event_clean_EC_TightBad", &event_clean_EC_TightBad, &b_event_clean_EC_TightBad);
   fChain->SetBranchAddress("event_clean_detector_core", &event_clean_detector_core, &b_event_clean_detector_core);
   fChain->SetBranchAddress("event_is_bad_batman", &event_is_bad_batman, &b_event_is_bad_batman);
   fChain->SetBranchAddress("event_number", &event_number, &b_event_number);
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
   fChain->SetBranchAddress("ljet_0_matched", &ljet_0_matched, &b_ljet_0_matched);
   fChain->SetBranchAddress("ljet_0_matched_classifierParticleOrigin", &ljet_0_matched_classifierParticleOrigin, &b_ljet_0_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("ljet_0_matched_classifierParticleType", &ljet_0_matched_classifierParticleType, &b_ljet_0_matched_classifierParticleType);
   fChain->SetBranchAddress("ljet_0_matched_mother_pdgId", &ljet_0_matched_mother_pdgId, &b_ljet_0_matched_mother_pdgId);
   fChain->SetBranchAddress("ljet_0_matched_mother_status", &ljet_0_matched_mother_status, &b_ljet_0_matched_mother_status);
   fChain->SetBranchAddress("ljet_0_matched_origin", &ljet_0_matched_origin, &b_ljet_0_matched_origin);
   fChain->SetBranchAddress("ljet_0_matched_p4", &ljet_0_matched_p4, &b_ljet_0_matched_p4);
   fChain->SetBranchAddress("ljet_0_matched_pdgId", &ljet_0_matched_pdgId, &b_ljet_0_matched_pdgId);
   fChain->SetBranchAddress("ljet_0_matched_pz", &ljet_0_matched_pz, &b_ljet_0_matched_pz);
   fChain->SetBranchAddress("ljet_0_matched_q", &ljet_0_matched_q, &b_ljet_0_matched_q);
   fChain->SetBranchAddress("ljet_0_matched_status", &ljet_0_matched_status, &b_ljet_0_matched_status);
   fChain->SetBranchAddress("ljet_0_matched_type", &ljet_0_matched_type, &b_ljet_0_matched_type);
   fChain->SetBranchAddress("ljet_0_origin", &ljet_0_origin, &b_ljet_0_origin);
   fChain->SetBranchAddress("ljet_0_p4", &ljet_0_p4, &b_ljet_0_p4);
   fChain->SetBranchAddress("ljet_0_q", &ljet_0_q, &b_ljet_0_q);
   fChain->SetBranchAddress("ljet_0_type", &ljet_0_type, &b_ljet_0_type);
   fChain->SetBranchAddress("ljet_0_width", &ljet_0_width, &b_ljet_0_width);
   fChain->SetBranchAddress("ljet_1", &ljet_1, &b_ljet_1);
   fChain->SetBranchAddress("ljet_1_MV2c10_FixedCutBEff_85_weight", &ljet_1_MV2c10_FixedCutBEff_85_weight, &b_ljet_1_MV2c10_FixedCutBEff_85_weight);
   fChain->SetBranchAddress("ljet_1_b_tag_score", &ljet_1_b_tag_score, &b_ljet_1_b_tag_score);
   fChain->SetBranchAddress("ljet_1_b_tagged_MV2c10_FixedCutBEff_85", &ljet_1_b_tagged_MV2c10_FixedCutBEff_85, &b_ljet_1_b_tagged_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("ljet_1_matched", &ljet_1_matched, &b_ljet_1_matched);
   fChain->SetBranchAddress("ljet_1_matched_classifierParticleOrigin", &ljet_1_matched_classifierParticleOrigin, &b_ljet_1_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("ljet_1_matched_classifierParticleType", &ljet_1_matched_classifierParticleType, &b_ljet_1_matched_classifierParticleType);
   fChain->SetBranchAddress("ljet_1_matched_mother_pdgId", &ljet_1_matched_mother_pdgId, &b_ljet_1_matched_mother_pdgId);
   fChain->SetBranchAddress("ljet_1_matched_mother_status", &ljet_1_matched_mother_status, &b_ljet_1_matched_mother_status);
   fChain->SetBranchAddress("ljet_1_matched_origin", &ljet_1_matched_origin, &b_ljet_1_matched_origin);
   fChain->SetBranchAddress("ljet_1_matched_p4", &ljet_1_matched_p4, &b_ljet_1_matched_p4);
   fChain->SetBranchAddress("ljet_1_matched_pdgId", &ljet_1_matched_pdgId, &b_ljet_1_matched_pdgId);
   fChain->SetBranchAddress("ljet_1_matched_pz", &ljet_1_matched_pz, &b_ljet_1_matched_pz);
   fChain->SetBranchAddress("ljet_1_matched_q", &ljet_1_matched_q, &b_ljet_1_matched_q);
   fChain->SetBranchAddress("ljet_1_matched_status", &ljet_1_matched_status, &b_ljet_1_matched_status);
   fChain->SetBranchAddress("ljet_1_matched_type", &ljet_1_matched_type, &b_ljet_1_matched_type);
   fChain->SetBranchAddress("ljet_1_origin", &ljet_1_origin, &b_ljet_1_origin);
   fChain->SetBranchAddress("ljet_1_p4", &ljet_1_p4, &b_ljet_1_p4);
   fChain->SetBranchAddress("ljet_1_q", &ljet_1_q, &b_ljet_1_q);
   fChain->SetBranchAddress("ljet_1_type", &ljet_1_type, &b_ljet_1_type);
   fChain->SetBranchAddress("ljet_1_width", &ljet_1_width, &b_ljet_1_width);
   fChain->SetBranchAddress("ljet_2", &ljet_2, &b_ljet_2);
   fChain->SetBranchAddress("ljet_2_MV2c10_FixedCutBEff_85_weight", &ljet_2_MV2c10_FixedCutBEff_85_weight, &b_ljet_2_MV2c10_FixedCutBEff_85_weight);
   fChain->SetBranchAddress("ljet_2_b_tag_score", &ljet_2_b_tag_score, &b_ljet_2_b_tag_score);
   fChain->SetBranchAddress("ljet_2_b_tagged_MV2c10_FixedCutBEff_85", &ljet_2_b_tagged_MV2c10_FixedCutBEff_85, &b_ljet_2_b_tagged_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("ljet_2_matched", &ljet_2_matched, &b_ljet_2_matched);
   fChain->SetBranchAddress("ljet_2_matched_classifierParticleOrigin", &ljet_2_matched_classifierParticleOrigin, &b_ljet_2_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("ljet_2_matched_classifierParticleType", &ljet_2_matched_classifierParticleType, &b_ljet_2_matched_classifierParticleType);
   fChain->SetBranchAddress("ljet_2_matched_mother_pdgId", &ljet_2_matched_mother_pdgId, &b_ljet_2_matched_mother_pdgId);
   fChain->SetBranchAddress("ljet_2_matched_mother_status", &ljet_2_matched_mother_status, &b_ljet_2_matched_mother_status);
   fChain->SetBranchAddress("ljet_2_matched_origin", &ljet_2_matched_origin, &b_ljet_2_matched_origin);
   fChain->SetBranchAddress("ljet_2_matched_p4", &ljet_2_matched_p4, &b_ljet_2_matched_p4);
   fChain->SetBranchAddress("ljet_2_matched_pdgId", &ljet_2_matched_pdgId, &b_ljet_2_matched_pdgId);
   fChain->SetBranchAddress("ljet_2_matched_pz", &ljet_2_matched_pz, &b_ljet_2_matched_pz);
   fChain->SetBranchAddress("ljet_2_matched_q", &ljet_2_matched_q, &b_ljet_2_matched_q);
   fChain->SetBranchAddress("ljet_2_matched_status", &ljet_2_matched_status, &b_ljet_2_matched_status);
   fChain->SetBranchAddress("ljet_2_matched_type", &ljet_2_matched_type, &b_ljet_2_matched_type);
   fChain->SetBranchAddress("ljet_2_origin", &ljet_2_origin, &b_ljet_2_origin);
   fChain->SetBranchAddress("ljet_2_p4", &ljet_2_p4, &b_ljet_2_p4);
   fChain->SetBranchAddress("ljet_2_q", &ljet_2_q, &b_ljet_2_q);
   fChain->SetBranchAddress("ljet_2_type", &ljet_2_type, &b_ljet_2_type);
   fChain->SetBranchAddress("ljet_2_width", &ljet_2_width, &b_ljet_2_width);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("met_reco_p4", &met_reco_p4, &b_met_reco_p4);
   fChain->SetBranchAddress("met_truth_p4", &met_truth_p4, &b_met_truth_p4);
   fChain->SetBranchAddress("muon_0_matched_classifierParticleOutcome", &muon_0_matched_classifierParticleOutcome, &b_muon_0_matched_classifierParticleOutcome);
   fChain->SetBranchAddress("muon_0_matched_isHad", &muon_0_matched_isHad, &b_muon_0_matched_isHad);
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
   fChain->SetBranchAddress("triggerSF_em_NOMINAL", &triggerSF_em_NOMINAL, &b_triggerSF_em_NOMINAL);
   fChain->SetBranchAddress("truth_Z_p4", &truth_Z_p4, &b_truth_Z_p4);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_mc_v", &weight_mc_v, &b_weight_mc_v);
   Notify();
}

Bool_t CLoop::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CLoop::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CLoop::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CLoop_cxx
