import os
import sys
import subprocess

from Condor_Lister import menu

clean=menu("Clean the output directories?",["No","Yes"])

if clean:
	os.system("rm MC/out/*.root")
	os.system("rm DATA/out/*.root")

channel_dir=os.getcwd()+'/'

samples_dir=sys.argv[1]

try :
	os.chdir(samples_dir)
	type_of_run = menu("Type of run...",["NOMINAL",'Systematics'])

	if type_of_run==1:
		os.system('hadd -j 10 '+channel_dir+'MC/out/Zmumu_Sherpa.root NOMINAL/Zmumu_sherpa*.root')
		#os.system('hadd '+channel_dir+'MC/out/Zmumu_PoPy.root NOMINAL/Zmumu_201*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Zmumu_MGNLO.root NOMINAL/Zmumu_MGNLO*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Zmumu_MG.root NOMINAL/Zmumu_MG[!NLO]*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Zmumu_SherpaNLO.root NOMINAL/Zmumu_SherpaNLO*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Signal_old.root NOMINAL/VBF_Zmumu_old_201*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Signal_Sherpa.root NOMINAL/VBF_Zmumu_sherpa_201*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Signal_PoPy.root NOMINAL/VBF_Zmumu_201*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/VV.root NOMINAL/llll_*.root NOMINAL/lllv_*.root NOMINAL/llvv_*.root NOMINAL/lvvv_*.root NOMINAL/ZqqZvv_*.root NOMINAL/ZqqZll_*.root NOMINAL/WqqZvv_*.root NOMINAL/WqqZll_*.root NOMINAL/WlvZqq_*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/Wjets.root NOMINAL/Wplusenu_*.root NOMINAL/Wminusenu_*.root NOMINAL/Wplusmunu_*.root NOMINAL/Wminusmunu_*.root NOMINAL/Wplustaunu_*.root NOMINAL/Wminustaunu_*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/singletop.root NOMINAL/st_schan_top_*.root NOMINAL/st_schan_atop_*.root NOMINAL/st_tchan_top_*.root NOMINAL/st_tchan_atop_*.root NOMINAL/st_wt_top_*.root NOMINAL/st_wt_atop_*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/ttbar.root NOMINAL/ttbar_*.root')
		os.system('hadd -j 10 '+channel_dir+'DATA/out/Data.root NOMINAL/data_*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/VV_EWK.root NOMINAL/VV_EWK*.root')		
		os.system('hadd -j 10 '+channel_dir+'MC/out/W_EWK_Sherpa.root NOMINAL/W_EWK_sherpa*.root')
		os.system('hadd -j 10 '+channel_dir+'MC/out/W_EWK_PoPy.root NOMINAL/W_EWK_PoPy*.root')

	elif type_of_run==2:
		for d in os.listdir():
			if d!="Systematics":
				os.system("hadd -j 10 Systematics/Signal_Sherpa_"+d+".root "+d+"/VBF_Zmumu*"+d+".root")
				os.system("hadd -j 10 Systematics/Zmumu_SherpaRW_"+d+".root "+d+"/Zmumu_sherpa*"+d+".root")

except FileNotFoundError :
	print("Non valid directory!")
	print("You are at ",os.getcwd())
