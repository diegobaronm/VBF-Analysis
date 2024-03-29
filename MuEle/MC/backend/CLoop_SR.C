#define CLoop_cxx

#include "../Analysis.C"
#include <cmath>
#include <TMacro.h>
#include "../../../AnalysisCommons/rewightingTools.h"
#include"../../../AnalysisCommons/Tools.h" 

void CLoop::Loop(double lumFactor, int z_sample, std::string key)
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

    std::cout<<"Analysing "<<nLoop<<" Events!"<<std::endl;

    Long64_t nbytes = 0, nb = 0;
    #ifdef NOMINAL
    // Only activate relevant branches
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
    fChain->SetBranchStatus("HLT_e120_lhloose",1);
    fChain->SetBranchStatus("HLT_e140_lhloose_nod0",1);
    fChain->SetBranchStatus("HLT_e24_lhmedium_L1EM20VH",1);
    fChain->SetBranchStatus("HLT_e26_lhtight_nod0_ivarloose",1);
    fChain->SetBranchStatus("HLT_e60_lhmedium",1);
    fChain->SetBranchStatus("HLT_e60_lhmedium_nod0",1);;
    fChain->SetBranchStatus("NOMINAL_pileup_combined_weight",1);
    fChain->SetBranchStatus("NOMINAL_pileup_random_run_number",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e120_lhloose",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e140_lhloose_nod0",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e60_lhmedium",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e60_lhmedium_nod0",1);
    fChain->SetBranchStatus("eleTrigMatch_0_trigger_matched",1);
    fChain->SetBranchStatus("elec_0",1);
    fChain->SetBranchStatus("elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCLoose",1);
    fChain->SetBranchStatus("elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight",1);
    fChain->SetBranchStatus("elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight",1);
    fChain->SetBranchStatus("elec_0_NOMINAL_EleEffSF_offline_RecoTrk",1);
    fChain->SetBranchStatus("elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13",1);
    fChain->SetBranchStatus("elec_0_NOMINAL_efficiency_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight",1);
    fChain->SetBranchStatus("elec_0_id_tight",1);
    fChain->SetBranchStatus("elec_0_iso_FCLoose",1);
    fChain->SetBranchStatus("elec_0_iso_FCTight",1);
    fChain->SetBranchStatus("elec_0_iso_FixedCutLoose",1);
    fChain->SetBranchStatus("elec_0_iso_FixedCutTight",1);
    fChain->SetBranchStatus("elec_0_iso_FixedCutTightCaloOnly",1);
    fChain->SetBranchStatus("elec_0_iso_Loose_FixedRad",1);
    fChain->SetBranchStatus("elec_0_iso_TightTrackOnly_FixedRad",1);
    fChain->SetBranchStatus("elec_0_p4",1);
    fChain->SetBranchStatus("elec_0_q",1);
    fChain->SetBranchStatus("n_bjets_MV2c10_FixedCutBEff_85",1);
    fChain->SetBranchStatus("n_electrons",1);
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
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);    nbytes += nb;
        // if (Cut(ientry) < 0) continue;

        // Variables defining regions
        // DELTA RAPIDITY 2-JETS
        double delta_y = abs(ljet_0_p4->Rapidity()-ljet_1_p4->Rapidity());
        // NUMBER OF JETS INTERVAL
        size_t n_ljets=n_jets-n_bjets_MV2c10_FixedCutBEff_85;
        int n_jets_interval{};
        if(n_ljets>2){
          n_jets_interval=n_jets_interval+is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4);
        }
        // Z BOSON CENTRALITY
        double lepton_xi=((*elec_0_p4)+(*muon_0_p4)).Rapidity();
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
        if (reweight_mjj){
            MC mcSample = static_cast<MC>(z_sample);
            if(mcSample == MC::PowHegPythia){
                mjj_w = 1.0;
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
        // SHERPA REWEIGHTING
        /*if (z_sample==2){
            double zpt=truth_Z_p4->Pt()/1000;
            if (zpt>30 & zpt<80){
                z_w=((0.95-0.98)/(log10(80)-log10(30)))*(log10(zpt)-log10(30))+0.98;
            }
            if (zpt>80){
                z_w=((1-0.95)/(log10(400)-log10(80)))*(log10(zpt)-log10(80))+0.95;
            }
        }*/
        // PYTHIA REWEIGHTING
        /*if(z_sample==1){
            double zpt=truth_Z_p4->Pt()/1000;
            if(zpt>=40 & zpt<46){
                z_w=0.995;
            }else if(zpt>=46 & zpt<48){
                z_w=0.99;
            }else if(zpt>=48 & zpt<51){
                z_w=0.983;
            }else if(zpt>=51 & zpt<54){
                z_w=0.974;
            }else if(zpt>=54 & zpt<58){
                z_w=0.978;
            }else if(zpt>=58 & zpt<60){
                z_w=0.969;
            }else if(zpt>=60 & zpt<65){
                z_w=0.95;
            }else if(zpt>=65 & zpt<70){
                z_w=0.949;
            }else if(zpt>=70 & zpt<75){
                z_w=0.942;
            }else if(zpt>=75 & zpt<80){
                z_w=0.937;
            }else if(zpt>=80 & zpt<85){
                z_w=0.92;
            }else if(zpt>=85 & zpt<95){
                z_w=0.9;
            }else if(zpt>=95 & zpt<108){
                z_w=0.891;
            }else if(zpt>=108 & zpt<130){
                z_w=0.863;
            }else if(zpt>=130 & zpt<151){
                z_w=0.84;
            }else if(zpt>=151){
                z_w=0.8;
            }
        }*/
        /*if (z_sample==1){
            double zpt=truth_Z_p4->Pt()/1000;
            if (zpt>40 & zpt<80){
                z_w=((0.93-1)/(log10(80)-log10(40)))*(log10(zpt)-log10(40))+1;
            }
            if (zpt>=80 & zpt<151){
                z_w=((0.8-0.93)/(log10(151)-log10(80)))*(log10(zpt)-log10(80))+0.93;
            }
            if (zpt>=151){
                z_w=0.80;
            }
        }*/
        double zpt_weight=1/z_w;

        double eventWeight = 1;
        // check if event is from real data
        if (!(key.substr(0,4)=="data")) {
            // take product of all scale factors
            eventWeight = weight_mc*NOMINAL_pileup_combined_weight*lumFactor*zpt_weight*mjj_w
            *muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium*muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium
            *muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium/*muon_0_NOMINAL_MuEffSF_TTVA*/
            *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT
            *jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
            *elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13*elec_0_NOMINAL_EleEffSF_offline_RecoTrk
            *elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight;
        }

        // fill histograms
        //cout << eventWeight;
        Fill(eventWeight, z_sample, key);
        // end filling
    }
    key = key+".root";
    const char*  name_root = key.c_str();
    // set style of histograms and write to output file
    // open output file
    TFile outfile(name_root,"recreate");
    Style(lumFactor);
    // Add the code to the file if it is the first sample of the kind
    std::vector<std::string> tokens = split(key,'_');
    std::string lastToken = tokens[tokens.size()-1];
    bool isFirstSample = lastToken=="0NOMINAL.root";
    if (isFirstSample) {
        TMacro sourceCode("Analysis.C");
        sourceCode.Write();
    }
    outfile.Close();

    clock_t endTime = clock(); // get end time
    // calculate time taken and print it
    double time_spent = (endTime - startTime) / CLOCKS_PER_SEC;
    cout << time_spent << std::endl;
}
