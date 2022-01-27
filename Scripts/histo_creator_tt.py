import sys

cuts=["basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt"] # "mlt","ebdt" for Zte
cuts_basic=["basic","cuts","tpt"]
histos_full={
"lep_pt":["Lep pT",200,0,200],
"lepnu_pt":["Lep + Neutrino pT",200,0,200],
"tau_pt":["Tau pT",200,0,200],
"taunu_pt":["Tau pT",200,0,200],
"lep_eta":["Lep eta",50,-2.5,2.5],
"tau_eta":["Tau eta",50,-2.5,2.5],
"delta_R_taulep":["Delta R tau-lep",20,0,2],
"delta_R_lepjet":["Delta R lep-jet",20,0,2],
"delta_R_taujet":["Delta R tau-jet",20,0,2],
"sum_pt":["Sum of lepton and tau pT",400,0,400],
"met":["Missing Transverse momentum",300,0,300],
"reco_mass_i":["Reconstructed mass in between events",240,0,240],
"reco_mass_o":["Reconstructed mass outside events",240,0,240],
"tau_matched_1p":["Tau truth matched 1 prong",2,0,2],
"tau_matched_3p":["Tau truth matched 3 prong",2,0,2],
"omega":["Omega variable",60,-3.0,3.0],

}

histos_not_full={"lep_phi":["Lep phi angle",64,-3.2,3.2],
"tau_phi":["Tau phi angle",64,-3.2,3.2],
"tau_nprongs":["Tau prongness",4,0,4],
"trans_lep_mass":["Lepton transverse mass",200,0,200],
"Z_pt_truth_i":["Truth ZpT in between events",400,0,400],
"Z_pt_truth_o":["Truth ZpT outside events",400,0,400],
"rnn_score_1p":["RNN Score 1 prong taus",100,0,1],
"rnn_score_3p":["RNN Score 3 prong taus",100,0,1],
"jet_n":["Number of jets",10,0,10],
"n_bjets":["Number of b_jets",5,0,5],
"lep_iso":["Lep isolation flag",2,0,2],
"delta_phi":["Delta phi between tau and lep",32,0,3.2],
"Z_pt_reco_i":["ZpT in between events",400,0,400],
"Z_pt_reco_o":["ZpT outside events",400,0,400],
"n_fake_tracks":["Number of fake tracks",40,0,40],
"n_core_tracks":["Number of core tracks",40,0,40],
"n_iso_tracks":["Number of isolation tracks",40,0,40],
"n_tracks":["Number of all tracks",40,0,40],
"delta_y":["Delta Rapidity",100,0,10],
"Z_centrality":["Z boson centrality",500,0,5],
"pt_bal":["pT Balance",100,0,1],
"mass_jj":["Invariant mass di_jet system",3000,0,3000],
"n_jets_interval":["N jets between rapidity interval",100,0,10],
"ljet0_pt":["Light jet0 pT",200,0,200],
"ljet1_pt":["Light jet1 pT",200,0,200],
"ljet2_pt":["Light jet2 pT",200,0,200],
"ljet3_pt":["Light jet3 pT",200,0,200],
"gap_jet_pt":["Gap jet pT",200,0,200],
}

histos_cuts={"delta_phi":["Delta phi between tau and lep",32,0,3.2],
"delta_y":["Delta Rapidity",100,0,10],
"n_bjets":["Number of b_jets",5,0,5],
"lepiso":["Lep Isolation",2,0,2],
"rnn_score_1p":["RNN Score 1 prong taus",100,0,1],
"rnn_score_3p":["RNN Score 3 prong taus",100,0,1],
"lep_pt":["Lep pT",200,0,200],
"ljet0_pt":["Light jet0 pT",200,0,200],
"ljet1_pt":["Light jet1 pT",200,0,200],
"pt_bal":["pT Balance",100,0,1],
"mass_jj":["Invariant mass di_jet system",3000,0,3000],
"n_jets_interval":["N jets between rapidity interval",100,0,10],
"Z_centrality":["Z boson centrality",500,0,5],
"omega":["Omega variable",60,-3.0,3.0],
"leptau_mass":["Invariant mass lepton tau system",200,0,200],
"eBDT":["eBDT Score",100,0,1],
"reco_mass_i":["Reconstructed mass in between events",240,0,240],
"reco_mass_o":["Reconstructed mass outside events",240,0,240],
"tau_pt":["Tau pT",200,0,200],
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