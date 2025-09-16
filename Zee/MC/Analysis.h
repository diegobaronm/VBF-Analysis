#ifndef Header
#define Header

// declare histograms here
// jet pT
#define NOMINAL // In previous versions of the code there was... SHAPESYSTEMATICS, WEIGHTSYSTEMATICS. But I decided to completely separate it.
#ifdef NOMINAL
histogramContainer lep1_etaContainer;
histogramContainer lep2_etaContainer;
histogramContainer delta_R_leplepContainer;
histogramContainer delta_R_lep1jetContainer;
histogramContainer delta_R_lep2jetContainer;
histogramContainer sum_ptContainer;
histogramContainer metContainer;
histogramContainer moreCentralJetContainer;
histogramContainer lessCentralJetContainer;
histogramContainer delta_phijjContainer;
histogramContainer signedCentralityContainer;

histogramContainer lep1_phiContainer;
histogramContainer lep2_phiContainer;
histogramContainer jet_nContainer;
histogramContainer Z_pt_recoContainer;
histogramContainer ljet2_ptContainer;
histogramContainer gap_jet_ptContainer;
histogramContainer ljet0_etaContainer;
histogramContainer ljet1_etaContainer;
histogramContainer ljet2_etaContainer;
histogramContainer gap_jet_etaContainer;
histogramContainer vec_sum_pt_jetsContainer;
histogramContainer ratio_zpt_sumjetptContainer;
histogramContainer Z_pt_truthContainer;

std::unique_ptr<TH1F> sum_of_weights_store;
#endif

histogramContainer delta_phiContainer;
histogramContainer delta_yContainer;
histogramContainer n_bjetsContainer;
histogramContainer lepisoContainer;
histogramContainer lep1_ptContainer;
histogramContainer lep2_ptContainer;
histogramContainer ljet0_ptContainer;
histogramContainer ljet1_ptContainer;
histogramContainer pt_balContainer;
histogramContainer mass_jjContainer;
histogramContainer n_jets_intervalContainer;
histogramContainer Z_centralityContainer;
histogramContainer inv_massContainer;

#endif
