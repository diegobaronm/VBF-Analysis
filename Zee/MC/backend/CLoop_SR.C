#define CLoop_cxx

#include "../Analysis.C"
#include <cmath>

double mjj_rw_madgraph(double mjj, double a, double b, double c){
    return a*mjj*mjj+b*mjj+c;
}

double mjj_rw_sherpa(double mjj, double slope, double level){
    return slope*mjj+level;  
}

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
    Long64_t nLoop_five_percent = nentries/20;

    std::cout<<"Analysing "<<nLoop<<" Events!"<<std::endl;

    Long64_t nbytes = 0, nb = 0;

    // loop over number of entries
    for (Long64_t jentry=0; jentry<nLoop;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);    nbytes += nb;
        // if (Cut(ientry) < 0) continue;

        if (nLoop >= 1000000 && jentry % nLoop_five_percent ==0 && jentry>0 ) {
            std::cout<<"Analysed... "<<100*double(jentry)/nLoop<<"% of events!"<<std::endl;
        }

        double mjj_w=1;
        // mjj reweighting
        if(z_sample==1 ){
            double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
            mjj_w = mjj_rw_sherpa(mjj,1.0,1.0);
        } else if (z_sample==2){
            double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
            mjj_w = mjj_rw_sherpa(mjj,-3.932E-04,1.314E+00);
        } else if (z_sample==3){
            double mjj=sqrt(2*(ljet_0_p4->Dot(*ljet_1_p4)));
            mjj_w = mjj_rw_madgraph(mjj,-1.545E-09,-1.436E-04,8.347E-01);
        }

        // ZpT reweighting

        double z_w=1;
        double zpt_weight=1/z_w;


        // calculate event weight
        double eventWeight = 1;
        double weight_total{0};
        if(!(key.substr(0,4)=="data")){
            weight_total= weight_mc*NOMINAL_pileup_combined_weight;
        }
        // check if event is from real data
        if (!(key.substr(0,4)=="data")) {
            // take product of all scale factors
            eventWeight = weight_total*lumFactor*zpt_weight*mjj_w
            *elec_0_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_0_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13*elec_0_NOMINAL_EleEffSF_offline_RecoTrk
            *jet_NOMINAL_central_jets_global_effSF_JVT*jet_NOMINAL_central_jets_global_ineffSF_JVT*jet_NOMINAL_forward_jets_global_effSF_JVT
            *jet_NOMINAL_forward_jets_global_ineffSF_JVT*jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85*jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85
            *elec_1_NOMINAL_EleEffSF_Isolation_TightLLH_d0z0_v13_FCTight*elec_1_NOMINAL_EleEffSF_offline_TightLLH_d0z0_v13*elec_1_NOMINAL_EleEffSF_offline_RecoTrk;
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
