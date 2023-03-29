import sys

systematicsWeight = {
"elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_TightLLH_d0z0_v13":"elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13",
"elec_0_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_TightLLH_d0z0_v13":"elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13",
"elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight":"elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight",
"elec_0_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight":"elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight",
"elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_offline_RecoTrk":"elec_0_NOMINAL_EleEffSF_offline_RecoTrk",
"elec_0_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_offline_RecoTrk":"elec_0_NOMINAL_EleEffSF_offline_RecoTrk",
"elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1down_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight":"elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight",
"elec_0_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR_1up_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight":"elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight",

"muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad":"muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",
"muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad":"muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",
"muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad":"muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",
"muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad":"muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",
"muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium":"muon_0_NOMINAL_MuEffSF_Reco_QualMedium",
"muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium":"muon_0_NOMINAL_MuEffSF_Reco_QualMedium",
"muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium":"muon_0_NOMINAL_MuEffSF_Reco_QualMedium",
"muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium":"muon_0_NOMINAL_MuEffSF_Reco_QualMedium",
"muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",
"muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium":"muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",

"PRW_DATASF_1down_pileup_combined_weight":"NOMINAL_pileup_combined_weight",
"PRW_DATASF_1up_pileup_combined_weight":"NOMINAL_pileup_combined_weight",

"jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT":"jet_NOMINAL_central_jets_global_effSF_JVT",
"jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT":"jet_NOMINAL_central_jets_global_ineffSF_JVT",
"jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT":"jet_NOMINAL_central_jets_global_effSF_JVT",
"jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT":"jet_NOMINAL_central_jets_global_ineffSF_JVT",
"jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT":"jet_NOMINAL_forward_jets_global_effSF_JVT",
"jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT":"jet_NOMINAL_forward_jets_global_ineffSF_JVT",
"jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT":"jet_NOMINAL_forward_jets_global_effSF_JVT",
"jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT":"jet_NOMINAL_forward_jets_global_ineffSF_JVT",

"tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1down_TauEffSF_LooseEleBDT_electron":"tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron",
"tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1up_TauEffSF_LooseEleBDT_electron":"tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron",
"tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron":"tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron",
"tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron":"tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron",
"tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco":"tau_0_NOMINAL_TauEffSF_reco",
"tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco":"tau_0_NOMINAL_TauEffSF_reco",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium",
"tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium":"tau_0_NOMINAL_TauEffSF_JetRNNmedium"
}

systematicsShape = [
"EG_RESOLUTION_ALL_1down",
"EG_RESOLUTION_ALL_1up",
"EG_SCALE_AF2_1down",
"EG_SCALE_AF2_1up",
"EG_SCALE_ALL_1down",
"EG_SCALE_ALL_1up",
"JET_BJES_Response_1down",
"JET_BJES_Response_1up",
"JET_EffectiveNP_1_1down",
"JET_EffectiveNP_1_1up",
"JET_EffectiveNP_2_1down",
"JET_EffectiveNP_2_1up",
"JET_EffectiveNP_3_1down",
"JET_EffectiveNP_3_1up",
"JET_EffectiveNP_4_1down",
"JET_EffectiveNP_4_1up",
"JET_EffectiveNP_5_1down",
"JET_EffectiveNP_5_1up",
"JET_EffectiveNP_6_1down",
"JET_EffectiveNP_6_1up",
"JET_EffectiveNP_7_1down",
"JET_EffectiveNP_7_1up",
"JET_EffectiveNP_8restTerm_1down",
"JET_EffectiveNP_8restTerm_1up",
"JET_EtaIntercalibration_Modelling_1down",
"JET_EtaIntercalibration_Modelling_1up",
"JET_EtaIntercalibration_NonClosure_2018data_1down",
"JET_EtaIntercalibration_NonClosure_2018data_1up",
"JET_EtaIntercalibration_NonClosure_highE_1down",
"JET_EtaIntercalibration_NonClosure_highE_1up",
"JET_EtaIntercalibration_NonClosure_negEta_1down",
"JET_EtaIntercalibration_NonClosure_negEta_1up",
"JET_EtaIntercalibration_NonClosure_posEta_1down",
"JET_EtaIntercalibration_NonClosure_posEta_1up",
"JET_EtaIntercalibration_TotalStat_1down",
"JET_EtaIntercalibration_TotalStat_1up",
"JET_Flavor_Composition_1down",
"JET_Flavor_Composition_1up",
"JET_Flavor_Response_1down",
"JET_Flavor_Response_1up",
"JET_JER_DataVsMC_MC16_1down",
"JET_JER_DataVsMC_MC16_1up",
"JET_JER_EffectiveNP_1_1down",
"JET_JER_EffectiveNP_1_1up",
"JET_JER_EffectiveNP_2_1down",
"JET_JER_EffectiveNP_2_1up",
"JET_JER_EffectiveNP_3_1down",
"JET_JER_EffectiveNP_3_1up",
"JET_JER_EffectiveNP_4_1down",
"JET_JER_EffectiveNP_4_1up",
"JET_JER_EffectiveNP_5_1down",
"JET_JER_EffectiveNP_5_1up",
"JET_JER_EffectiveNP_6_1down",
"JET_JER_EffectiveNP_6_1up",
"JET_JER_EffectiveNP_7restTerm_1down",
"JET_JER_EffectiveNP_7restTerm_1up",
"JET_Pileup_OffsetMu_1down",
"JET_Pileup_OffsetMu_1up",
"JET_Pileup_OffsetNPV_1down",
"JET_Pileup_OffsetNPV_1up",
"JET_Pileup_PtTerm_1down",
"JET_Pileup_PtTerm_1up",
"JET_Pileup_RhoTopology_1down",
"JET_Pileup_RhoTopology_1up",
"JET_PunchThrough_MC16_1down",
"JET_PunchThrough_MC16_1up",
"JET_SingleParticle_HighPt_1down",
"JET_SingleParticle_HighPt_1up",
"JET_TILECORR_Uncertainty_1down",
"JET_TILECORR_Uncertainty_1up",
"MET_SoftTrk_ResoPara",
"MET_SoftTrk_ResoPerp",
"MET_SoftTrk_Scale_1down",
"MET_SoftTrk_Scale_1up",
"MUON_ID_1down",
"MUON_ID_1up",
"MUON_MS_1down",
"MUON_MS_1up",
"MUON_SAGITTA_RESBIAS_1down",
"MUON_SAGITTA_RESBIAS_1up",
"MUON_SAGITTA_RHO_1down",
"MUON_SAGITTA_RHO_1up",
"MUON_SCALE_1down",
"MUON_SCALE_1up",
"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1down",
"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1up",
"TAUS_TRUEHADTAU_SME_TES_INSITUEXP_1down",
"TAUS_TRUEHADTAU_SME_TES_INSITUEXP_1up",
"TAUS_TRUEHADTAU_SME_TES_INSITUFIT_1down",
"TAUS_TRUEHADTAU_SME_TES_INSITUFIT_1up",
"TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE_1down",
"TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE_1up",
"TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST_1down",
"TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST_1up",
]



histosSystematics={"mass_jj_":["Invariant mass di-jet system",5000,0,5000,"mjj"],}


def book():
    for i in histosSystematics:
        for systematic in systematicsWeight:
            print('h_'+i+systematic+' = new TH1F("'+i+systematic+'","'+histosSystematics[i][0]+'",'+str(histosSystematics[i][1])+','+str(histosSystematics[i][2])+','+str(histosSystematics[i][3])+');')
        for systematic in systematicsShape:
            print('h_'+i+systematic+' = new TH1F("'+i+systematic+'","'+histosSystematics[i][0]+'",'+str(histosSystematics[i][1])+','+str(histosSystematics[i][2])+','+str(histosSystematics[i][3])+');')




def write():
    for i in histosSystematics:
        for systematic in systematicsWeight:
            print('h_'+i+systematic+'->Write();')
        for systematic in systematicsShape:
            print('h_'+i+systematic+'->Write();')


def fill():
    for i in histosSystematics:
        for systematic in systematicsWeight:
            print('h_'+i+systematic+'->Fill('+histosSystematics[i][4]+',weight*'+systematic+'/'+systematicsWeight[systematic]+');')
        for systematic in systematicsShape:
            print('h_'+i+systematic+'->Fill('+histosSystematics[i][4]+',weight);')


def define():
    for i in histosSystematics:
        for systematic in systematicsWeight:
            print('TH1F* '+'h_'+i+systematic+';')
        for systematic in systematicsShape:
            print('TH1F* '+'h_'+i+systematic+';')
        

if sys.argv[1]=="book":
	book()
elif sys.argv[1]=="write":
	write()
elif sys.argv[1]=="define":
	define()
elif sys.argv[1]=="fill":
	fill()
else :
	print("Incorrect argument! TRY AGAIN!")