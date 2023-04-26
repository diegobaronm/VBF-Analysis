import ROOT as r
import os
import numpy as np

r.TH1.AddDirectory(False)

############################################################################################################
# Function that returns the list of bin edges used by ROOT to rebin a histogram
def biner(edges,bin_widths,histogram):
    # Check that the number of internal edges is one less than the number of bin widths
    if (len(edges)+1!=len(bin_widths)):
        print("Check edges and bin widths array sizes!")
        return
    
    # Get the first and last bin edges of the histogram
    bins=[]
    first_bin = histogram.GetXaxis().GetBinLowEdge(1)
    last_bin = histogram.GetXaxis().GetBinUpEdge(histogram.GetNbinsX())


    for i in range(0,len(edges)):
        n_spaces = int((edges[i] - first_bin)/bin_widths[i])
        bins = np.concatenate((bins,np.linspace(first_bin,edges[i],n_spaces,endpoint=False)))
        first_bin = edges[i]
        if edges[i]==edges[-1]:
            n_spaces = int((last_bin - edges[i])/bin_widths[i+1])
            bins = np.concatenate((bins,np.linspace(edges[i],last_bin,n_spaces,endpoint=False)))
            bins = np.concatenate((bins,[last_bin]))
    return bins

############################################################################################################

# Function to normalise a list of histograms to a given bin width
def normalization(hist_list,norm_bin):
    # Loop the histograms
    for hist in hist_list:
        # Scale each bin of the histogram by the bin width
        for i in range(1,hist.GetNbinsX()+1):
            value=hist.GetBinContent(i)
            error=hist.GetBinError(i)
            sf=hist.GetBinWidth(i)/norm_bin
            hist.SetBinContent(i,value/sf)
            hist.SetBinError(i,error/sf)

############################################################################################################

# Function to return a histogram that is the data minus all the samples included in a list
def dataSubtract(histoName,histogramsPath,dataFileName,sampleFilesToSubtract,histogramInfo,rebin=True):
    # Get the data histogram
    dataFile = r.TFile.Open(histogramsPath+dataFileName+".root")
    dataHistogram = r.TH1F(dataFile.Get(histoName))
    subtractHistograms = []
    # First rebin all the histograms using the histogramInfo dictionary
    if rebin:
        binsArray=biner(histogramInfo[histoName][0],histogramInfo[histoName][1],dataHistogram)
        numberBins=len(binsArray)-1
        dataHistogram = dataHistogram.Rebin(numberBins,dataFileName,binsArray)
        # Now rebin the other samples
        for sampleToSubtract in sampleFilesToSubtract:
            sampleFile = r.TFile.Open(histogramsPath+sampleToSubtract+".root")
            sampleHistogram = r.TH1F(sampleFile.Get(histoName))
            sampleHistogram = sampleHistogram.Rebin(numberBins,sampleToSubtract,binsArray)
            subtractHistograms.append(sampleHistogram)

    # Subtract the samples
    for sampleHistogram in subtractHistograms:
        dataHistogram.Add(sampleHistogram,-1)

    return dataHistogram

############################################################################################################

# Histogram dictionaries for the different channels

# Dictionaries for Z->ee

# Dictionaries for Z->mumu

# Dictionaries for Z->tautau

# Dictionaries for Z->ll

histogramsHighStatsZll = {
"n_bjets":['n b-jets'],
"lepiso":['Lepton Isolation'],
"n_jets_interval":['N jets gap'],
"delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":['#DeltaR(#mu_{1},#mu_{2})'],
"delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":['#DeltaR(#mu_{1},j)'],
"delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":['#DeltaR(#mu_{2},j)'],    
"delta_phi":[[2.0],[0.2,0.8],0.2,'#Delta#phi(#mu_{1},#mu_{2})'],
"lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.1],[0.2,0.199],0.2,'#eta(#mu_{1})'],
"lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.1],[0.2,0.199],0.2,'#eta(#mu_{2})'],
"ljet0_eta_basic_cuts_ptl":[[-3.0,3.0],[0.5,0.2,0.5],0.2,'#eta(j_{1})'],
"ljet1_eta_basic_cuts_ptl":[[-3.0,3.0],[0.5,0.2,0.5],0.2,'#eta(j_{2})'],  
"lep1_pt":[[100,200,300],[20,50,100,350],20,'pT(#mu_{1})'],
"lep2_pt":[[100,200,300],[20,50,100,350],20,'pT(#mu_{2})'],
"ljet0_pt":[[75,460],[15,35,54],15,'pT(j_{1})'],
"ljet1_pt":[[70,440],[10,37,56],10,'pT(j_{2})'],
"ljet2_pt_basic_cuts_ptl":[[100],[20,50],20,'pT(j_{2})'],
"pt_bal":[[0.15,0.3],[0.03,0.05,0.7],0.15,'pT balance'],
"Z_centrality":[[0.5],[0.1,0.5],0.1,'#xi(Z)'],
"delta_y":[[2.0,6.0],[1.0,0.5,1.0],1.0,'#Deltay_{jj}'],
"inv_mass":[[70,110,140,300],[70,5,10,80,700],5,'m_{#mu#mu}'],
"mass_jj":[[1500],[250,500],250,'m_{jj}'],
"Z_pt_reco_basic_cuts_ptl":[[300,600],[20,50,200],20,'pT(Z)'],
"vec_sum_pt_jets_basic_cuts_ptl":[[300],[20,50],20],
"ratio_zpt_sumjetpt_basic_cuts_ptl":[[0.75,1.25],[0.25,0.1,0.25],0.1],
"met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[50],[10,50],10,'MET'],
}

histogramsLowStatsZll = {
"n_bjets":['N b-jets'],
"lepiso":['Lepton Isolation'],
"n_jets_interval":['N jets gap'],
"lep1_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.1],[0.2,0.199],0.2,'#eta(#mu_{1})'],
"lep2_eta_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.1],[0.2,0.199],0.2,'#eta(#mu_{2})'],
"ljet0_eta_basic_cuts_ptl":[[-3.0,3.0],[0.5,0.2,0.5],0.2,'#eta(j_{1})'],
"ljet1_eta_basic_cuts_ptl":[[-3.0,3.0],[0.5,0.2,0.5],0.2,'#eta(j_{2})'],
"delta_R_leplep_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.2],[0.2,0.199],0.2,'#DeltaR(#mu_{1},#mu_{2})'],
"delta_R_lep1jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.2],[0.2,0.199],0.2,'#DeltaR(#mu_{1},j)'],
"delta_R_lep2jet_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[0.2],[0.2,0.199],0.2,'#DeltaR(#mu_{2},j)'],
"delta_phi":[[2.0],[0.2,0.8],0.2,'#Delta#phi(#mu_{1},#mu_{2})'],
"lep1_pt":[[300],[20,50],20,'pT(#mu_{1})'],
"lep2_pt":[[300],[20,50],20,'pT(#mu_{2})'],
"ljet0_pt":[[75,460],[15,35,54],15,'pT(j_{1})'],
"ljet1_pt":[[70,440],[10,37,56],10,'pT(j_{2})'],
"pt_bal":[[0.15,0.3],[0.0499,0.15,0.7],0.15,'pT balance'],
"Z_centrality":[[0.5],[0.1,0.5],0.1,'#xi(Z)'],
"delta_y":[[2.0,6.0],[1.0,0.5,1.0],1.0,'#Deltay_{jj}'],
"inv_mass":[[70,110,140],[10,5,10,20],5,'m_{#mu#mu}'],
"mass_jj":[[1500,3000],[250,500,1000],250,'m_{jj}'],
"Z_pt_reco_basic_cuts_ptl":[[300,600],[20,50,200],20,'pT(Z)'],
"vec_sum_pt_jets_basic_cuts_ptl":[[300],[20,50],20],
"ratio_zpt_sumjetpt_basic_cuts_ptl":[[0.75,1.25],[0.25,0.1,0.25],0.1],
"met_basic_dphi_drap_btag_iso_pt1_pt2_j1pt_j2pt_ptbal_mjj_nji_zcen_mass_ptl":[[50],[10,50],10,'MET'],
}



if __name__ == "__main__":
    print("This is a module with histogram helpers. Import it to use it!")