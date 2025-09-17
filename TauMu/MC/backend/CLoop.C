#define CLoop_cxx

#include "../Analysis.C"
#include <cmath>
#include <TMVA/Reader.h>
#include <TMacro.h>
#include "../../../AnalysisCommons/reweightingTools.h"
#include"../../../AnalysisCommons/Tools.h"
#include"../../../AnalysisCommons/Kinematics.h"

#ifdef NOMINAL
// Tree variables 
// Signal tree
double SigTree_mcWeight;
double SigTree_mjj;
double SigTree_deltaRapidity;
double SigTree_deltaPhiLT;
double SigTree_deltaPhiJJ;
double SigTree_jetRNNScore;
double SigTree_ptBalance;
double SigTree_zCentrality;
double SigTree_omega;
double SigTree_reco_mass;
double SigTree_lepNuPt;
double SigTree_transverseMassLep;
double SigTree_transverseRecoMassVariable;
double SigTree_massTauLep;
int SigTree_nLightJets;
double SigTree_tau_pT;
double SigTree_lep_pT;
double SigTree_jet0_pT;
double SigTree_jet1_pT;
double SigTree_met_pT;
double SigTree_event_number;
// Background tree
double BgTree_mcWeight;
double BgTree_mjj;
double BgTree_deltaRapidity;
double BgTree_deltaPhiLT;
double BgTree_deltaPhiJJ;
double BgTree_jetRNNScore;
double BgTree_ptBalance;
double BgTree_zCentrality;
double BgTree_omega;
double BgTree_reco_mass;
double BgTree_lepNuPt;
double BgTree_transverseMassLep;
double BgTree_transverseRecoMassVariable;
double BgTree_massTauLep;
int BgTree_nLightJets;
double BgTree_tau_pT;
double BgTree_lep_pT;
double BgTree_jet0_pT;
double BgTree_jet1_pT;
double BgTree_met_pT;
double BgTree_event_number;

#endif

void CLoop::Loop(double lumFactor, int z_sample, const std::string& key, int logLevel)
{
//    In a ROOT session, you can do:
//        root> .L CLoop.C
//        root> CLoop t
//        root> t.GetEntry(12); // Fill t data members with entry number 12
//        root> t.Show();         // Show values of entry 12
//        root> t.Show(16);      // Read and show values of entry 16
//        root> t.Loop();         // Loop on all entries
//

//      This is the loop skeleton where:
//     jentry is the global entry number in the chain
//     ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//     jentry for TChain::GetEntry
//     ientry for TTree::GetEntry and TBranch::GetEntry
//
//         To read only selected branches, Insert statements like:
// METHOD1:
//     fChain->SetBranchStatus("*",0);  // disable all branches
//     fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//     fChain->GetEntry(jentry);         //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
    clock_t startTime = clock(); // get start time

    // Set the logging level
    g_LOG.setLogLevel(static_cast<LogLevel>(logLevel));

    if (fChain == 0) return;

    // book histograms
    Book();

    Long64_t nentries = fChain->GetEntriesFast();

    // if in fast mode only loop over 1% of the entries
    Long64_t nLoop = nentries;

    g_LOG(LogLevel::INFO,"Number of events to analyse = ", nLoop);

    Long64_t nbytes = 0, nb = 0;

    #ifdef NOMINAL
    // Only activate relevant branches
    if (!(key.substr(0,4)=="data")){
    fChain->SetBranchStatus("*",0);
    fChain->SetBranchStatus("HLT_mu20_iloose_L1MU15",1);
    fChain->SetBranchStatus("HLT_mu26_ivarmedium",1);
    fChain->SetBranchStatus("HLT_mu50",1);
    fChain->SetBranchStatus("NOMINAL_pileup_combined_weight",1);
    fChain->SetBranchStatus("NOMINAL_pileup_random_run_number",1);
    fChain->SetBranchStatus("event_number",1);
    fChain->SetBranchStatus("jet_NOMINAL_central_jets_global_effSF_JVT",1);
    fChain->SetBranchStatus("jet_NOMINAL_central_jets_global_ineffSF_JVT",1);
    fChain->SetBranchStatus("jet_NOMINAL_forward_jets_global_effSF_JVT",1);
    fChain->SetBranchStatus("jet_NOMINAL_forward_jets_global_ineffSF_JVT",1);
    fChain->SetBranchStatus("jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85",1);
    fChain->SetBranchStatus("jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85",1);
    fChain->SetBranchStatus("ljet_0",1);
    fChain->SetBranchStatus("ljet_0_p4",1);
    fChain->SetBranchStatus("ljet_0_q",1);
    fChain->SetBranchStatus("ljet_0_matched_pdgId",1);
    fChain->SetBranchStatus("ljet_1",1);
    fChain->SetBranchStatus("ljet_1_p4",1);
    fChain->SetBranchStatus("ljet_1_q",1);
    fChain->SetBranchStatus("ljet_1_matched_pdgId",1);
    fChain->SetBranchStatus("ljet_2",1);
    fChain->SetBranchStatus("ljet_2_p4",1);
    fChain->SetBranchStatus("ljet_2_q",1);
    fChain->SetBranchStatus("ljet_3",1);
    fChain->SetBranchStatus("ljet_3_p4",1);
    fChain->SetBranchStatus("ljet_3_q",1);
    fChain->SetBranchStatus("bjet_0",1);
    fChain->SetBranchStatus("bjet_0_p4",1);
    fChain->SetBranchStatus("bjet_0_q",1);
    fChain->SetBranchStatus("met_reco_p4",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu20_iloose_L1MU15",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu26_ivarmedium",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu50",1);
    fChain->SetBranchStatus("muTrigMatch_0_trigger_matched",1);
    fChain->SetBranchStatus("muon_0",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_Reco_QualMedium",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_TTVA",1);
    fChain->SetBranchStatus("muon_0_id_medium",1);
    fChain->SetBranchStatus("muon_0_iso_FCLoose",1);
    fChain->SetBranchStatus("muon_0_iso_FCTight",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutLoose",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutTight",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutTightCaloOnly",1);
    fChain->SetBranchStatus("muon_0_iso_Loose_FixedRad",1);
    fChain->SetBranchStatus("muon_0_iso_TightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_0_p4",1);
    fChain->SetBranchStatus("muon_0_q",1);
    fChain->SetBranchStatus("n_bjets_MV2c10_FixedCutBEff_85",1);
    fChain->SetBranchStatus("n_electrons",1);
    fChain->SetBranchStatus("n_jets",1);
    fChain->SetBranchStatus("n_muons",1);
    fChain->SetBranchStatus("n_taus",1);
    fChain->SetBranchStatus("n_taus_rnn_loose",1);
    fChain->SetBranchStatus("n_taus_rnn_medium",1);
    fChain->SetBranchStatus("n_taus_rnn_tight",1);
    fChain->SetBranchStatus("n_taus_rnn_veryloose",1);
    fChain->SetBranchStatus("run_number",1);
    fChain->SetBranchStatus("tau_0",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_JetRNNloose",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_JetRNNmedium",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_JetRNNtight",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_MediumEleBDT_electron",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_reco",1);
    fChain->SetBranchStatus("tau_0_NOMINAL_TauEffSF_selection",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_loose_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_medium_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_score_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_score_trans_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_tight_retuned",1);
    fChain->SetBranchStatus("tau_0_jet_bdt_score",1);
    fChain->SetBranchStatus("tau_0_jet_bdt_score_trans",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_loose",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_medium",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_score",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_score_trans",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_tight",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_veryloose",1);
    fChain->SetBranchStatus("tau_0_n_all_tracks",1);
    fChain->SetBranchStatus("tau_0_n_charged_tracks",1);
    fChain->SetBranchStatus("tau_0_n_conversion_tracks",1);
    fChain->SetBranchStatus("tau_0_n_core_tracks",1);
    fChain->SetBranchStatus("tau_0_n_fake_tracks",1);
    fChain->SetBranchStatus("tau_0_n_isolation_tracks",1);
    fChain->SetBranchStatus("tau_0_n_old_tracks",1);
    fChain->SetBranchStatus("tau_0_n_unclassified_tracks",1);
    fChain->SetBranchStatus("tau_0_p4",1);
    fChain->SetBranchStatus("tau_0_q",1);
    fChain->SetBranchStatus("tau_0_truth_isEle",1);
    fChain->SetBranchStatus("tau_0_truth_isHadTau",1);
    fChain->SetBranchStatus("tau_0_truth_isJet",1);
    fChain->SetBranchStatus("tau_0_truth_isMuon",1);
    fChain->SetBranchStatus("tau_0_truth_isTau",1);
    fChain->SetBranchStatus("triggerSF_em_NOMINAL",1);
    fChain->SetBranchStatus("truth_Z_p4",1);
    fChain->SetBranchStatus("weight_mc",1);
    fChain->SetBranchStatus("weight_mc_v",1);
    fChain->SetBranchStatus("event_number",1);   
    fChain->SetBranchStatus("tau_0_truth_pdgId",1);
    fChain->SetBranchStatus("muon_0_matched_pdgId",1);
    fChain->SetBranchStatus("taulep_0_truth_vis_p4",1);
    fChain->SetBranchStatus("taulep_0_truth_invis_p4",1);
    fChain->SetBranchStatus("tau_0_truth_total_p4",1);
    } else {
    fChain->SetBranchStatus("*",0);
    fChain->SetBranchStatus("HLT_mu20_iloose_L1MU15",1);
    fChain->SetBranchStatus("HLT_mu26_ivarmedium",1);
    fChain->SetBranchStatus("HLT_mu50",1);
    fChain->SetBranchStatus("event_number",1);
    fChain->SetBranchStatus("ljet_0",1);
    fChain->SetBranchStatus("ljet_0_p4",1);
    fChain->SetBranchStatus("ljet_0_q",1);
    fChain->SetBranchStatus("ljet_1",1);
    fChain->SetBranchStatus("ljet_1_p4",1);
    fChain->SetBranchStatus("ljet_1_q",1);
    fChain->SetBranchStatus("ljet_2",1);
    fChain->SetBranchStatus("ljet_2_p4",1);
    fChain->SetBranchStatus("ljet_2_q",1);
    fChain->SetBranchStatus("ljet_3",1);
    fChain->SetBranchStatus("ljet_3_p4",1);
    fChain->SetBranchStatus("ljet_3_q",1);
    fChain->SetBranchStatus("met_reco_p4",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu20_iloose_L1MU15",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu26_ivarmedium",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu50",1);
    fChain->SetBranchStatus("muTrigMatch_0_trigger_matched",1);
    fChain->SetBranchStatus("muon_0",1);
    fChain->SetBranchStatus("muon_0_id_medium",1);
    fChain->SetBranchStatus("muon_0_iso_FCLoose",1);
    fChain->SetBranchStatus("muon_0_iso_FCTight",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutLoose",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutTight",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutTightCaloOnly",1);
    fChain->SetBranchStatus("muon_0_iso_Loose_FixedRad",1);
    fChain->SetBranchStatus("muon_0_iso_TightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_0_p4",1);
    fChain->SetBranchStatus("muon_0_q",1);
    fChain->SetBranchStatus("n_bjets_MV2c10_FixedCutBEff_85",1);
    fChain->SetBranchStatus("n_electrons",1);
    fChain->SetBranchStatus("n_jets",1);
    fChain->SetBranchStatus("n_muons",1);
    fChain->SetBranchStatus("n_taus",1);
    fChain->SetBranchStatus("n_taus_rnn_loose",1);
    fChain->SetBranchStatus("n_taus_rnn_medium",1);
    fChain->SetBranchStatus("n_taus_rnn_tight",1);
    fChain->SetBranchStatus("n_taus_rnn_veryloose",1);
    fChain->SetBranchStatus("run_number",1);
    fChain->SetBranchStatus("tau_0",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_loose_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_medium_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_score_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_score_trans_retuned",1);
    fChain->SetBranchStatus("tau_0_ele_bdt_tight_retuned",1);
    fChain->SetBranchStatus("tau_0_jet_bdt_score",1);
    fChain->SetBranchStatus("tau_0_jet_bdt_score_trans",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_loose",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_medium",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_score",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_score_trans",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_tight",1);
    fChain->SetBranchStatus("tau_0_jet_rnn_veryloose",1);
    fChain->SetBranchStatus("tau_0_n_all_tracks",1);
    fChain->SetBranchStatus("tau_0_n_charged_tracks",1);
    fChain->SetBranchStatus("tau_0_n_conversion_tracks",1);
    fChain->SetBranchStatus("tau_0_n_core_tracks",1);
    fChain->SetBranchStatus("tau_0_n_fake_tracks",1);
    fChain->SetBranchStatus("tau_0_n_isolation_tracks",1);
    fChain->SetBranchStatus("tau_0_n_old_tracks",1);
    fChain->SetBranchStatus("tau_0_n_unclassified_tracks",1);
    fChain->SetBranchStatus("tau_0_p4",1);
    fChain->SetBranchStatus("tau_0_q",1);
    }
    #endif

    // Create output file for the events passing the selection
    std::string keyRoot = key+".root";
    const char*  name_root = keyRoot.c_str();
    // set style of histograms and write to output file
    // open output file
    TFile outfile(name_root,"recreate");
    // Create TTree
    bool saveHistograms = true;
    #ifdef NOMINAL
    bool saveEvents = false;
    TTree* signalTree = new TTree("SIGNAL", "Signal TTree");
    TTree* bgTree = new TTree("BG", "Background TTree");

    // Setting tree branches
    signalTree->Branch("mcWeight", &SigTree_mcWeight);
    signalTree->Branch("mjj", &SigTree_mjj);
    signalTree->Branch("deltaRapidity", &SigTree_deltaRapidity);
    signalTree->Branch("deltaPhiLT",&SigTree_deltaPhiLT);
    signalTree->Branch("deltaPhiJJ",&SigTree_deltaPhiJJ);
    signalTree->Branch("jetRNNScore",&SigTree_jetRNNScore);
    signalTree->Branch("ptBalance",&SigTree_ptBalance);
    signalTree->Branch("zCentrality",&SigTree_zCentrality);
    signalTree->Branch("omega",&SigTree_omega);
    signalTree->Branch("reco_mass",&SigTree_reco_mass);
    signalTree->Branch("lepNuPt",&SigTree_lepNuPt);
    signalTree->Branch("transverseMassLep",&SigTree_transverseMassLep);
    signalTree->Branch("transverseRecoMassVariable",&SigTree_transverseRecoMassVariable);
    signalTree->Branch("massTauLep",&SigTree_massTauLep);
    signalTree->Branch("nLightJets",&SigTree_nLightJets);
    signalTree->Branch("tau_p4", &SigTree_tau_pT);
    signalTree->Branch("lep_p4", &SigTree_lep_pT);
    signalTree->Branch("jet0_p4", &SigTree_jet0_pT);
    signalTree->Branch("jet1_p4", &SigTree_jet1_pT);
    signalTree->Branch("met_p4", &SigTree_met_pT);
    signalTree->Branch("eventNumber", &SigTree_event_number);

    bgTree->Branch("mcWeight", &BgTree_mcWeight);
    bgTree->Branch("mjj", &BgTree_mjj);
    bgTree->Branch("deltaRapidity", &BgTree_deltaRapidity);
    bgTree->Branch("deltaPhiLT",&BgTree_deltaPhiLT);
    bgTree->Branch("deltaPhiJJ",&BgTree_deltaPhiJJ);
    bgTree->Branch("jetRNNScore",&BgTree_jetRNNScore);
    bgTree->Branch("ptBalance",&BgTree_ptBalance);
    bgTree->Branch("zCentrality",&BgTree_zCentrality);
    bgTree->Branch("omega",&BgTree_omega);
    bgTree->Branch("reco_mass",&BgTree_reco_mass);
    bgTree->Branch("lepNuPt",&BgTree_lepNuPt);
    bgTree->Branch("transverseMassLep",&BgTree_transverseMassLep);
    bgTree->Branch("transverseRecoMassVariable",&BgTree_transverseRecoMassVariable);
    bgTree->Branch("massTauLep",&BgTree_massTauLep);
    bgTree->Branch("nLightJets",&BgTree_nLightJets);
    bgTree->Branch("tau_p4", &BgTree_tau_pT);
    bgTree->Branch("lep_p4", &BgTree_lep_pT);
    bgTree->Branch("jet0_p4", &BgTree_jet0_pT);
    bgTree->Branch("jet1_p4", &BgTree_jet1_pT);
    bgTree->Branch("met_p4", &BgTree_met_pT);
    bgTree->Branch("eventNumber", &BgTree_event_number);
    #endif
    // loop over number of entries
    for (Long64_t jentry=0; jentry<nLoop;jentry++) {
        g_LOG(LogLevel::DEBUG," ");
        g_LOG(LogLevel::DEBUG,"New Event n = ", jentry);
        
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry,0);    nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        // Variables defining regions
        // DELTA RAPIDITY 2-JETS
        double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());
        // NUMBER OF JETS INTERVAL
        size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;
        int n_jets_interval{};
        if(n_ljets>2){
          n_jets_interval=n_jets_interval+Kinematics::is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4);
        }
        // Z BOSON CENTRALITY
        double lepton_xi=((*tau_0_p4)+(*muon_0_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        Region region = Region::DefaultNoRW;
        if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::SR;}
        else if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRa;}
        else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRb;}
        else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::CRc;}

        // Mjj reweighting
        double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
        bool do_data_driven = true;
        bool do_mc_driven = true;

        double mjj_w = calculateMjjWeight(do_data_driven, do_mc_driven, mjj, region, z_sample);

        double eventWeight = 1;
        g_LOG(LogLevel::DEBUG,"Initial event w = ", eventWeight);
        g_LOG(LogLevel::DEBUG,"MC w = ", weight_mc);
        g_LOG(LogLevel::DEBUG,"Mjj w = ", mjj_w);
        g_LOG(LogLevel::DEBUG,"Lumfactor w = ", lumFactor);
        g_LOG(LogLevel::DEBUG,"PU w = ", NOMINAL_pileup_combined_weight);
        g_LOG(LogLevel::DEBUG,"Muon SFs = ", muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium*muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium
            *muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
        g_LOG(LogLevel::DEBUG,"Jet SFs = ", jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT);
        g_LOG(LogLevel::DEBUG,"Tau SFs = ", tau_0_NOMINAL_TauEffSF_reco*tau_0_NOMINAL_TauEffSF_JetRNNmedium);

        // check if event is from real data
        if (!(key.substr(0,4)=="data")) {
            if (!(NOMINAL_pileup_combined_weight > -1)) continue; // TO AVOID FILLING HUGE WEIGHTS IN EWK Sample
            // Do not apply pileup reweighting to VBF MadGraph samples
            float puWeight = NOMINAL_pileup_combined_weight;
            if (key.find("VBF") != std::string::npos && key.find("MG") != std::string::npos)
                puWeight = 1.0;
            // take product of all scale factors
            eventWeight = weight_mc*puWeight*lumFactor*mjj_w
            *muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium*muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium
            *muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium*muon_0_NOMINAL_MuEffSF_TTVA
            *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT
            *jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
            *tau_0_NOMINAL_TauEffSF_reco*tau_0_NOMINAL_TauEffSF_JetRNNmedium;
        }

        // fill histograms
        g_LOG(LogLevel::DEBUG,"Final event w = ", eventWeight);
        if (saveHistograms) Fill(eventWeight, z_sample, key);
        #ifdef NOMINAL
        if (saveEvents) FillTree(eventWeight, z_sample, key, signalTree, bgTree);
        // end filling
        #endif
    }
    // end style and writing
    if (saveHistograms) Style(lumFactor);   
    #ifdef NOMINAL
    if (saveEvents) {
        outfile.WriteObject(signalTree,"SIGNAL");
        outfile.WriteObject(bgTree,"BACKGROUND");
    }
    // Add the code to the file if it is the first sample of the kind
    std::vector<std::string> tokens = split(key,'_');
    std::string lastToken = tokens[tokens.size()-1];
    bool isFirstSample = lastToken=="0NOMINAL.root";
    if (isFirstSample) {
        TMacro sourceCode("Analysis.C");
        sourceCode.Write();
    }
    delete signalTree;
    delete bgTree;
    #endif
    outfile.Close();
    clock_t endTime = clock(); // get end time
    // calculate time taken and print it
    double time_spent = (endTime - startTime) / CLOCKS_PER_SEC;
    g_LOG(LogLevel::INFO,"Time processing == ", time_spent);
}
