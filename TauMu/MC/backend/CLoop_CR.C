#define CLoop_cxx

#include "../Analysis.C"
#include <cmath>


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

    Long64_t nbytes = 0, nb = 0;

    // loop over number of entries
    for (Long64_t jentry=0; jentry<nLoop;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);    nbytes += nb;
        // if (Cut(ientry) < 0) continue;

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
        if(z_sample==1){
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
        }
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
        double weight_total{0};
        if(!(key.substr(0,4)=="data")){
            weight_total= weight_mc*NOMINAL_pileup_combined_weight;
        }
        // check if event is from real data
        if (weight_total != 0) {
            // take product of all scale factors
            eventWeight = weight_total*lumFactor*zpt_weight*muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/*muon_0_NOMINAL_MuEffSF_IsoFCTightTrackOnly_FixedRad*/*muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad*muon_0_NOMINAL_MuEffSF_Reco_QualMedium
            *muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium*muon_0_NOMINAL_MuEffSF_TTVA
            *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT*
            jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
            *tau_0_NOMINAL_TauEffSF_reco;
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
