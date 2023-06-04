#define CLoop_cxx

#include "../Analysis.C"
#include <cmath>

double mjj_rw_quadratic(double mjj, double a, double b, double c){
    double rw = a*mjj*mjj+b*mjj+c;
    if (rw<0){
        return 0.0;
    } else {
        return rw;
    }
}

double mjj_rw_linear(double mjj, double slope, double level){
    double rw = slope*mjj+level;
    if (rw<0){
        return 0.0;
    } else {
        return rw;
    } 
}

enum class MC
{
    PowHegPythia = 1,
    SHERPA,
    MadGraph
};

enum class Region
{
    DefaultNoRW,
    SR,
    CRa,
    CRb,
    CRc
};

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
    Book(lumFactor);
    // end booking

    Long64_t nentries = fChain->GetEntriesFast();

    // if in fast mode only loop over 1% of the entries
    Long64_t nLoop = nentries;

    std::cout<<"Analysing "<<nLoop<<" Events!"<<std::endl;

    Long64_t nbytes = 0, nb = 0;

    #ifdef NOMINAL
    // Only activate relevant branches
    if (!(key.substr(0,4)=="data")){
    fChain->SetBranchStatus("*",0);
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
    } else {
    fChain->SetBranchStatus("*",0);
    fChain->SetBranchStatus("HLT_e120_lhloose",1);
    fChain->SetBranchStatus("HLT_e140_lhloose_nod0",1);
    fChain->SetBranchStatus("HLT_e24_lhmedium_L1EM20VH",1);
    fChain->SetBranchStatus("HLT_e26_lhtight_nod0_ivarloose",1);
    fChain->SetBranchStatus("HLT_e60_lhmedium",1);
    fChain->SetBranchStatus("HLT_e60_lhmedium_nod0",1);;
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e120_lhloose",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e140_lhloose_nod0",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e60_lhmedium",1);
    fChain->SetBranchStatus("eleTrigMatch_0_HLT_e60_lhmedium_nod0",1);
    fChain->SetBranchStatus("eleTrigMatch_0_trigger_matched",1);
    fChain->SetBranchStatus("elec_0",1);
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

    // loop over number of entries
    for (Long64_t jentry=0; jentry<nLoop;jentry++) {
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
          n_jets_interval=n_jets_interval+is_inside_jets(ljet_2_p4,ljet_0_p4,ljet_1_p4);
        }
        // Z BOSON CENTRALITY
        double lepton_xi=((*tau_0_p4)+(*elec_0_p4)).Rapidity();
        double dijet_xi=ljet_0_p4->Rapidity()+ljet_1_p4->Rapidity();
        double z_centrality=abs(lepton_xi-0.5*dijet_xi)/delta_y;

        Region region = Region::DefaultNoRW;
        if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::SR;}
        else if ((z_centrality<0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRa;}
        else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==1){region = Region::CRb;}
        else if ((z_centrality>=0.5 && z_centrality<=1) && n_jets_interval==0){region = Region::CRc;}

        std::map<Region,std::vector<double>> parametersSHERPA = {
            {Region::DefaultNoRW,{0.0,0.0,1.0}},
            {Region::SR,{1.40E-07,-7.16E-04,1.51E+00}},
            {Region::CRa,{5.61E-08,-4.20E-04,1.25E+00}},
            {Region::CRb,{4.12E-08,-3.64E-04,1.08E+00}},
            {Region::CRc,{1.09E-07,-6.10E-04,1.30E+00}}
        };

        std::map<Region,std::vector<double>> parametersMadGraph = {
            {Region::DefaultNoRW,{0.0,0.0,1.0}},
            {Region::SR,{1.30E-07,-5.29E-04,9.82E-01}},
            {Region::CRa,{1.53E-07,-5.42E-04,1.10E+00}},
            {Region::CRb,{6.24E-08,-2.97E-04,9.72E-01}},
            {Region::CRc,{5.95E-08,-3.32E-04,8.78E-01}}
        };

        double mjj_w=1;
        // mjj reweighting
        MC mcSample = static_cast<MC>(z_sample);
        if(mcSample == MC::PowHegPythia){
            mjj_w = 1.0;
        } else if (mcSample == MC::SHERPA){
            double a = parametersSHERPA[region].at(0);
            double b = parametersSHERPA[region].at(1);
            double c = parametersSHERPA[region].at(2);
            double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
            mjj_w = mjj_rw_quadratic(mjj,a,b,c);
        } else if (mcSample == MC::MadGraph){ 
            double a = parametersMadGraph[region].at(0);
            double b = parametersMadGraph[region].at(1);
            double c = parametersMadGraph[region].at(2);
            double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
            mjj_w = mjj_rw_quadratic(mjj,a,b,c);
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
            *elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13*elec_0_NOMINAL_EleEffSF_offline_RecoTrk
            *elec_0_NOMINAL_EleEffSF_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2018_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_TightLLH_d0z0_v13_isolFCTight
            *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT*
            jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
            *tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron*tau_0_NOMINAL_TauEffSF_JetRNNmedium;
        }

        // fill histograms
        //cout << eventWeight;
        Fill(eventWeight, z_sample);
        // end filling
    }
    key = key+".root";
    const char*  name_root = key.c_str();
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
    cout << time_spent << std::endl;
}
