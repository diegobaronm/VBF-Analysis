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

# Function to make the negative bins of a histogram equal to zero. 
def makeNegativeBinsZero(histogram):
    for i in range(1,histogram.GetNbinsX()+1):
        if histogram.GetBinContent(i)<0:
            histogram.SetBinContent(i,0.0)

############################################################################################################

# Function to plot a histogram stack of MC with data
def stackPlot(data,signal,background,histograms,watermark,signalMu = 1.0, backgroundMu = 1.0,average=False,after_fit=False,final_state="Z#rightarrow #mu#mu"):
    samples = data.copy()
    samples.update(background)
    samples.update(signal)

    for i in histograms:
        print("HISTOGRAM = ",i)
        for s in samples:
            file = r.TFile.Open(samples[s][0],"READ")
            hist = file.Get(i)
            hist.SetDirectory(0)
            samples[s].append
            samples[s][2]=hist # add histogram (TH1F) to list of samples
            file.Close()
        if average:
            watermark = "Average"
            if after_fit:
                watermark = "Average_AfterFit"
            
        ###### REBIN AND NORMALISE ######
        if len(histograms[i])>2:
            rebining=biner(histograms[i][0],histograms[i][1],samples["Data"][2])
            print("Using following bins... ",rebining)
            nb=len(rebining)-1
            for s in samples:
                if 'Average' in samples[s][0]:
                    print(s,samples[s])
                    continue
                else :    
                    samples[s][2]=samples[s][2].Rebin(nb,s,rebining)
            hist_list=[samples[s][2] for s in samples if 'Average' not in samples[s][0]]
            normalization(hist_list,histograms[i][2])

        ###### SETTING THE COLOURS ######

        for s in samples:
            if s=="Data":
                samples[s][2].SetMarkerStyle(20)
                samples[s][2].SetMarkerSize(0.5)
                samples[s][2].SetLineColor(samples[s][1])
            else :
                #if s=="Signal" or s=="QCD Z" :
                    #samples[s][2].SetLineWidth(0)
                samples[s][2].SetFillColor(samples[s][1])
                samples[s][2].SetLineColor(samples[s][1]+1)

        #################### SCALING FACTORS FROM FIT ####################

        if after_fit:
            samples["Signal"][2].Scale(signalMu)
            samples["QCD Z"][2].Scale(backgroundMu)
                
        ####################### CREATING MC AND STACK HISTOGRAM ########################        
        
        hs = r.THStack("hs","")
        mc = samples["Signal"][2].Clone()
        for s in samples:
            if s!="Data":
                hs.Add(samples[s][2])
                if s!="Signal":
                    mc.Add(samples[s][2],1)

        ############### DEFINING RATIOS ###############

        ratio = mc.Clone()
        ratio.Divide(samples["Data"][2])
    
        ratio_sg_mc=samples["Signal"][2].Clone()
        ratio_sg_mc.Divide(mc)


        ##### DRAWING TOP PAD, SETTING MARGINS #######
        
        r.gStyle.SetOptStat(1111111)
        r.gStyle.SetStatY(0.97);                
        r.gStyle.SetStatX(1.0);
        r.gStyle.SetStatW(0.12);                
        r.gStyle.SetStatH(0.12);

        canvas = r.TCanvas("canvas2")
        canvas.cd()

        pad1 = r . TPad (" pad1 "," pad1 " ,0 ,0.35 ,1 ,1)
        pad1.SetTopMargin(0.03)
        pad1.SetRightMargin(0.03)
        pad1.SetLeftMargin(0.08)
        pad1.SetBottomMargin(0.0)
        pad1.Draw ()
        pad1.cd ()

        ###### SETTING STATS BOX POSITION ######
        
        r.gStyle.SetStatY(0.95);                
        r.gStyle.SetStatX(0.96);
        r.gStyle.SetStatW(0.1);                
        r.gStyle.SetStatH(0.1);

        
        samples["Data"][2].Draw("pe same")
        hs.Draw("HIST same")
        samples["Data"][2].Draw("pe same")
        samples["Data"][2].Draw("sameaxis")
        
        pad1.SetLogy()
        
        s=samples["Data"][2].GetXaxis().GetBinLowEdge(1)
        e=samples["Data"][2].GetXaxis().GetBinUpEdge(samples["Data"][2].GetNbinsX())
        
        if "reco_mass_" in i:
            s=66
            e=116
        
        samples["Data"][2].GetYaxis().SetRangeUser(0.1 ,13*samples["Data"][2].GetBinContent(samples["Data"][2].GetMaximumBin()))
        samples["Data"][2].GetXaxis().SetRangeUser(s,e)
        hs.GetXaxis().SetRangeUser(s,e)
        if len(histograms[i])>2:
            samples["Data"][2].GetYaxis().SetTitle("Events/"+str(histograms[i][2])+" GeV")
        legend = r . TLegend (0.45 ,0.80 ,0.85 ,0.95)
        for sample in samples:
            legend.AddEntry(samples[sample][2],sample)
        legend.SetNColumns(3)
        r.gStyle.SetLegendBorderSize(0)
        legend . SetLineWidth (0)
        legend . Draw ()

        samples["Data"][2].SetTitle("")
        l=r.TLatex()
        l.SetNDC ()
        l.DrawLatex(0.9,0.7,final_state)
        
        max_ratio = ratio.GetMaximum()
        #if max_ratio > 3:
            #max_ratio = 3
        if max_ratio < 1.5:
            max_ratio = 1.5

        min_ratio = ratio.GetMinimum()
        if min_ratio > 0.7:
            min_ratio = 0.5
            
        canvas.cd()
        pad2 = r . TPad (" pad2 "," pad2 " ,0 ,0.17 ,1 ,0.35)
        pad2.SetRightMargin(0.03)
        pad2.SetLeftMargin(0.08)
        pad2.SetTopMargin(0)
        pad2.SetBottomMargin(0.0)
        pad2.Draw ()
        pad2.cd ()
        ratio.SetFillColorAlpha(r.kBlue,0.35)
        ratio.Draw ("E2")
        ratio.SetTitle("")
        ratio.SetStats(0)
        ratio . GetYaxis (). SetRangeUser (min_ratio ,max_ratio)
        ratio . GetXaxis (). SetRangeUser (s ,e)
        ratio . GetYaxis (). SetTitle ("MC/DATA")
        ratio . GetYaxis (). SetTitleSize (0.15)
        ratio . GetYaxis (). SetTitleOffset (0.25)
        ratio . GetXaxis (). SetTitleSize (0.09)
        ratio.GetXaxis().SetLabelSize(0.10)
        ratio.GetYaxis().SetLabelSize(0.08)
        ratio.SetMarkerStyle(8)
        ratio.SetMarkerSize(0.6)


        ###### SETTING ALL THE HORIZONTAL DASHED LINES #######

        line = r . TLine (s ,1 ,e,1)
        line . SetLineColor ( r . kBlack )
        line . SetLineWidth (2)

        separators = []
        resolution = 10 # In percentage
        j=0
        range_sep = []
        while j < (int(max_ratio)+1):
            step = resolution/100
            if j > min_ratio:
                range_sep.append(j)
            j = j + step

        for k in range (len(range_sep)):
            sep = r.TLine(s ,range_sep[k],e,range_sep[k])
            sep.SetLineColor(r.kBlack)
            sep.SetLineWidth(1)
            sep.SetLineStyle(2)
            separators.append(sep)

        line . Draw (" same ")   
        for separ in separators:
            separ.Draw("same")
        canvas.cd()
        pad3 = r . TPad (" pad3","pad3" ,0.0 ,0.0 ,1 ,0.17)
        pad3.SetRightMargin(0.03)
        pad3.SetLeftMargin(0.08)
        pad3.SetTopMargin(0)
        pad3.SetBottomMargin(0.4)
        pad3.Draw ()
        pad3.cd ()
        ratio_sg_mc.SetStats(0)
        ratio_sg_mc . GetYaxis (). SetRangeUser (0.0 ,1.02)
        ratio_sg_mc . GetXaxis (). SetRangeUser (s ,e)
        ratio_sg_mc . GetYaxis (). SetTitle ("SIGNAL/MC")
        ratio_sg_mc . GetYaxis (). SetTitleSize (0.15)
        ratio_sg_mc . GetYaxis (). SetTitleOffset (0.25)
        ############ X AXIS TITLE #################
        axisTitle='hola'
        if len(histograms[i])>2:
            try :
                axisTitle=histograms[i][3]    
            except :
                pass
        else :
            try :
                axisTitle=histograms[i][0]    
            except :
                pass
        ##########################################
        ratio_sg_mc.SetXTitle(axisTitle)
        ratio_sg_mc.SetTitleSize(0.17,"X")
        ratio_sg_mc.SetTitleOffset(0.9,"X")
        ratio_sg_mc.GetYaxis().SetLabelSize(0.09)
        ratio_sg_mc.GetXaxis().SetLabelSize(0.16)
        ratio_sg_mc.SetMarkerStyle(8)
        ratio_sg_mc.SetMarkerSize(0.6)

        ratio_sg_mc.Draw ("hist p")
        ###### SETTING ALL THE HORIZONTAL DASHED LINES #######

        line11 = r . TLine (s ,0.80 ,e,0.80)
        line11 . SetLineColor ( r . kBlack )
        line11 . SetLineWidth (1)
        line11 . SetLineStyle(2)
        line12 = r . TLine (s ,0.60 ,e,0.60)
        line12 . SetLineColor ( r . kBlack )
        line12 . SetLineWidth (1)
        line12 . SetLineStyle(2)
        line13 = r . TLine (s ,0.40 ,e,0.40)
        line13 . SetLineColor ( r . kBlack )
        line13 . SetLineWidth (1)
        line13 . SetLineStyle(2)
        line14 = r . TLine (s ,0.20 ,e,0.20)
        line14 . SetLineColor ( r . kBlack )
        line14 . SetLineWidth (1)
        line14 . SetLineStyle(2)
        sline = r . TLine (s ,1 ,e,1)
        sline . SetLineColor ( r . kBlack )
        sline . SetLineWidth (2)
        sline.Draw("same")
        line11 . Draw (" same ")
        line12 . Draw (" same ")
        line13 . Draw (" same ")
        line14 . Draw (" same ")
        
        file_name = i+"_"+watermark+".pdf"
        canvas.Update()
        canvas.Print(file_name)


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