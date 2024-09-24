#define CLoop_cxx

#include "../Analysis.C"
#include "../Selections.C"
#include <cmath>
#include "../../../AnalysisCommons/rewightingTools.h"
#include"../../../AnalysisCommons/Kinematics.h"

void CLoop::Loop(double lumFactor, int z_sample, const std::string& key)
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

    if (fChain == 0) return;


    // book histograms
    Book();
    // end booking

    Long64_t nentries = fChain->GetEntriesFast();

    // if in fast mode only loop over 1% of the entries
    Long64_t nLoop = nentries;
    Long64_t nLoop_five_percent = nentries/20;

    g_LOG(LogLevel::INFO,"Number of events to analyse = ", nLoop);

    Long64_t nbytes = 0, nb = 0;
    #ifdef NOMINAL
    // Only relevant branches are activated
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
    fChain->SetBranchStatus("ljet_1",1);
    fChain->SetBranchStatus("ljet_1_p4",1);
    fChain->SetBranchStatus("ljet_1_q",1);
    fChain->SetBranchStatus("ljet_2",1);
    fChain->SetBranchStatus("ljet_2_p4",1);
    fChain->SetBranchStatus("ljet_2_q",1);
    fChain->SetBranchStatus("met_reco_p4",1);
    fChain->SetBranchStatus("met_truth_p4",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu20_iloose_L1MU15",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu26_ivarmedium",1);
    fChain->SetBranchStatus("muTrigMatch_0_HLT_mu50",1);
    fChain->SetBranchStatus("muTrigMatch_0_trigger_matched",1);
    fChain->SetBranchStatus("muTrigMatch_1_HLT_mu20_iloose_L1MU15",1);
    fChain->SetBranchStatus("muTrigMatch_1_HLT_mu26_ivarmedium",1);
    fChain->SetBranchStatus("muTrigMatch_1_HLT_mu50",1);
    fChain->SetBranchStatus("muTrigMatch_1_trigger_matched",1);
    fChain->SetBranchStatus("muon_0",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_Reco_QualMedium",1);
    fChain->SetBranchStatus("muon_0_NOMINAL_MuEffSF_TTVA",1);
    fChain->SetBranchStatus("muon_0_id_medium",1);
    fChain->SetBranchStatus("muon_0_id_tight",1);
    fChain->SetBranchStatus("muon_0_iso_FCLoose",1);
    fChain->SetBranchStatus("muon_0_iso_FCTight",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutLoose",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutTight",1);
    fChain->SetBranchStatus("muon_0_iso_FixedCutTightCaloOnly",1);
    fChain->SetBranchStatus("muon_0_iso_Loose_FixedRad",1);
    fChain->SetBranchStatus("muon_0_iso_TightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_0_p4",1);
    fChain->SetBranchStatus("muon_0_q",1);
    fChain->SetBranchStatus("muon_1",1);
    fChain->SetBranchStatus("muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium",1);
    fChain->SetBranchStatus("muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium",1);
    fChain->SetBranchStatus("muon_1_NOMINAL_MuEffSF_IsoLoose_FixedRad",1);
    fChain->SetBranchStatus("muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_1_NOMINAL_MuEffSF_Reco_QualMedium",1);
    fChain->SetBranchStatus("muon_1_NOMINAL_MuEffSF_TTVA",1);
    fChain->SetBranchStatus("muon_1_id_medium",1);
    fChain->SetBranchStatus("muon_1_id_tight",1);
    fChain->SetBranchStatus("muon_1_iso_FCLoose",1);
    fChain->SetBranchStatus("muon_1_iso_FCTight",1);
    fChain->SetBranchStatus("muon_1_iso_FixedCutLoose",1);
    fChain->SetBranchStatus("muon_1_iso_FixedCutTight",1);
    fChain->SetBranchStatus("muon_1_iso_FixedCutTightCaloOnly",1);
    fChain->SetBranchStatus("muon_1_iso_Loose_FixedRad",1);
    fChain->SetBranchStatus("muon_1_iso_TightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("muon_1_p4",1);
    fChain->SetBranchStatus("muon_1_q",1);
    fChain->SetBranchStatus("n_bjets_MV2c10_FixedCutBEff_85",1);
    fChain->SetBranchStatus("n_jets",1);
    fChain->SetBranchStatus("n_muons",1);
    fChain->SetBranchStatus("run_number",1);
    fChain->SetBranchStatus("triggerSF_em_NOMINAL",1);
    fChain->SetBranchStatus("truth_Z_p4",1);
    fChain->SetBranchStatus("weight_mc",1);
    fChain->SetBranchStatus("weight_mc_v",1);
    #endif
    // loop over number of entries
    for (Long64_t jentry=0; jentry<nLoop;jentry++) {
        g_LOG(LogLevel::DEBUG," ");
        g_LOG(LogLevel::DEBUG,"New Event n = ", jentry);
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry,0);    nbytes += nb;
        // if (Cut(ientry) < 0) continue;

        if (nLoop >= 1000000 && jentry % nLoop_five_percent ==0 && jentry>0 ) {
            g_LOG(LogLevel::INFO, 100*double(jentry)/nLoop, "% Analysed.");
        }

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
        double lepton_xi=((*muon_0_p4)+(*muon_1_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        Region region = Region::DefaultNoRW;
        if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::SR;}
        else if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRa;}
        else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRb;}
        else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::CRc;}

        double mjj = sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
        double mjj_w = 1.0;

        // mjj reweighting
        bool reweight_mjj = true;
        MC mcSample = static_cast<MC>(z_sample);
        if (reweight_mjj){
            if(mcSample == MC::PowHegPythia){
                mjj_w = mjj_rw(mjj,parametersPowHegPythia[region]);
            } else if (mcSample == MC::SHERPA){
                mjj_w = mjj_rw(mjj,parametersSHERPA[region]); 
            } else if (mcSample == MC::MadGraph){ 
                mjj_w = mjj_rw(mjj,parametersMadGraph[region]);
            } else if (mcSample == MC::SHERPANLO){ 
                mjj_w = mjj_rw(mjj,parametersSHERPANLO[region]);
            } else if (mcSample == MC::MadGraphNLO){ 
                mjj_w = mjj_rw(mjj,parametersMadGraphNLO[region]);
            } 
        }

        // ZpT reweighting		
        double z_w=1;
        if(mcSample == MC::PowHegPythia){
            double zpt=truth_Z_p4->Pt()/1000;
            z_w = zpT_rw_popy(zpt);
        }
        double zpt_weight=1/z_w;

        // calculate event weight
        double eventWeight = 1;
        // check if event is from real data
        if (!(key.substr(0,4)=="data")) {
            // take product of all scale factors
            eventWeight = weight_mc*NOMINAL_pileup_combined_weight*lumFactor*zpt_weight*mjj_w
            *muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium/*muon_0_NOMINAL_MuEffSF_TTVA*/
            *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT
            *jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
            *muon_1_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_1_NOMINAL_MuEffSF_Reco_QualMedium/*muon_1_NOMINAL_MuEffSF_TTVA*/;
        }

        // fill histograms
        //cout << eventWeight;
        Fill(eventWeight, z_sample, key);
        // end filling
    }
    std::string keyRoot = key+".root";
    const char*  name_root = keyRoot.c_str();
    // set style of histograms and write to output file
    // open output file
    TFile outfile(name_root,"recreate");
    Style(lumFactor);
    // end style and writing
    //
    outfile.Close();

    clock_t endTime = clock(); // get end time
    // calculate time taken and print it
    double time_spent = (endTime - startTime) / CLOCKS_PER_SEC;
    g_LOG(LogLevel::INFO,"Time processing == ", time_spent);
}
