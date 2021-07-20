import sys

cuts=["basic","dphi","drap","btag","iso","pt1","pt2","j1pt","j2pt","ptbal","mjj","nji","zcen","mass","ptl"]
cuts_basic=["basic","cuts","tpt"]
histos_full={
"lep1_pt":["Lep 1 pT",200,0,200],
"lep2_pt":["Lep 2 pT",200,0,200],
"sum_pt":["Sum of leptons pT",400,0,400],
"met":["Missing Transverse momentum",300,0,300],
"inv_mass":["Invariant mass di-lepton system",240,0,240],
}

histos_not_full={"lep1_phi":["Lep 1 phi angle",64,-3.2,3.2],
"lep2_phi":["Lep 2 phi angle",64,-3.2,3.2],
"Z_pt_truth":["Truth ZpT",400,0,400],
"jet_n":["Number of jets",10,0,10],
"n_bjets":["Number of b_jets",5,0,5],
"lep_iso":["Lep 1,2 isolation flag",2,0,2],
"delta_phi":["Delta phi between leptons",32,0,3.2],
"Z_pt_reco":["ZpT",400,0,400],
"delta_y":["Delta Rapidity",100,0,10],
"Z_centrality":["Z boson centrality",500,0,5],
"pt_bal":["pT Balance",100,0,1],
"mass_jj":["Invariant mass di_jet system",3000,0,3000],
"n_jets_interval":["N jets between rapidity interval",100,0,10],
"ljet0_pt":["Light jet0 pT",200,0,200],
"ljet1_pt":["Light jet1 pT",200,0,200],
"ljet2_pt":["Light jet2 pT",200,0,200],
"gap_jet_pt":["Gap jet pT",200,0,200],
}

histos_cuts={"delta_phi":["Delta phi between leptons",32,0,3.2],
"delta_y":["Delta Rapidity",100,0,10],
"n_bjets":["Number of b_jets",5,0,5],
"lepiso":["Leptons isolation",2,0,2],
"lep1_pt":["Lep 1 pT",200,0,200],
"lep2_pt":["Lep 2 pT",200,0,200],
"ljet0_pt":["Light jet0 pT",200,0,200],
"ljet1_pt":["Light jet1 pT",200,0,200],
"pt_bal":["pT Balance",100,0,1],
"mass_jj":["Invariant mass di_jet system",3000,0,3000],
"n_jets_interval":["N jets between rapidity interval",100,0,10],
"Z_centrality":["Z boson centrality",500,0,5],
"inv_mass":["Invariant mass di-lepton system",240,0,240],
}

histos_all=dict(histos_full,**histos_not_full)

def book():
    for i in histos_all:
        if i in histos_full:
            temp=""
            for j in cuts:
                temp=temp+'_'+j
                print('h_'+i+temp+' = new TH1F("'+i+temp+'","'+histos_all[i][0]+'",'+str(histos_all[i][1])+','+str(histos_all[i][2])+','+str(histos_all[i][3])+');')
            print("\n")
        if i in histos_not_full:
            temp=""
            for j in cuts_basic:
                temp=temp+'_'+j
                print('h_'+i+temp+' = new TH1F("'+i+temp+'","'+histos_all[i][0]+'",'+str(histos_all[i][1])+','+str(histos_all[i][2])+','+str(histos_all[i][3])+');')
            print("\n")
    for i in histos_cuts:
        print('h_'+i+' = new TH1F("'+i+'","'+histos_cuts[i][0]+'",'+str(histos_cuts[i][1])+','+str(histos_cuts[i][2])+','+str(histos_cuts[i][3])+');')




def write():
    for i in histos_all:
        if i in histos_full:
            temp=""
            for j in cuts:
                temp=temp+'_'+j
                print('h_'+i+temp+'->Write();')
            print("\n")
        if i in histos_not_full:
            temp=""
            for j in cuts_basic:
                temp=temp+'_'+j
                print('h_'+i+temp+'->Write();')
            print("\n")
    for i in histos_cuts:
        print('h_'+i+'->Write();')


def fill():
    for i in histos_all:
        if i in histos_full:
            temp=""
            for j in cuts:
                temp=temp+'_'+j
            print('h_'+i+temp+'->Fill(,weight);')
        if i in histos_not_full:
            temp=""
            for j in cuts_basic:
                temp=temp+'_'+j
            print('h_'+i+temp+'->Fill(,weight);')
    for i in histos_cuts:
        print('h_'+i+'->Fill(,weight);')


def define():
    for i in histos_all:
        if i in histos_full:
            temp=""
            for j in cuts:
                temp=temp+'_'+j
                print('TH1F* '+'h_'+i+temp+';')
            print("\n")
        if i in histos_not_full:
            temp=""
            for j in cuts_basic:
                temp=temp+'_'+j
                print('TH1F* '+'h_'+i+temp+';')
            print("\n")
    for i in histos_cuts:
        print('TH1F* '+'h_'+i+';')

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