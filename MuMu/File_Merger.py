import os
import sys

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

	if type_of_run:
		os.system('hadd '+channel_dir+'MC/out/Zmumu_Sherpa.root NOMINAL/Zmumu_sherpa*.root')
		os.system('hadd '+channel_dir+'MC/out/Zmumu_PoPy.root NOMINAL/Zmumu_201*.root')
		os.system('hadd '+channel_dir+'MC/out/Signal_old.root NOMINAL/VBF_Zmumu_old_201*.root')
		os.system('hadd '+channel_dir+'MC/out/Signal_Sherpa.root NOMINAL/VBF_Zmumu_sherpa_201*.root')
		os.system('hadd '+channel_dir+'MC/out/Signal_PoPy.root NOMINAL/VBF_Zmumu_201*.root')
		os.system('hadd '+channel_dir+'MC/out/VV.root NOMINAL/llll_*.root NOMINAL/lllv_*.root NOMINAL/llvv_*.root NOMINAL/lvvv_*.root NOMINAL/ZqqZvv_*.root NOMINAL/ZqqZll_*.root NOMINAL/WqqZvv_*.root NOMINAL/WqqZll_*.root NOMINAL/WlvZqq_*.root')
		os.system('hadd '+channel_dir+'MC/out/Wjets.root NOMINAL/Wplusenu_*.root NOMINAL/Wminusenu_*.root NOMINAL/Wplusmunu_*.root NOMINAL/Wminusmunu_*.root NOMINAL/Wplustaunu_*.root NOMINAL/Wminustaunu_*.root')
		os.system('hadd '+channel_dir+'MC/out/singletop.root NOMINAL/st_schan_top_*.root NOMINAL/st_schan_atop_*.root NOMINAL/st_tchan_top_*.root NOMINAL/st_tchan_atop_*.root NOMINAL/st_wt_top_*.root NOMINAL/st_wt_atop_*.root')
		os.system('hadd '+channel_dir+'MC/out/ttbar.root NOMINAL/ttbar_*.root')
		os.system('hadd '+channel_dir+'DATA/out/data.root NOMINAL/data_*.root')

	elif type_of_run==2:
		for d in os.listdir():
			if d!="out":
				os.system("hadd out/Signal_Sherpa"+d+".root "+d+"/Zmumu_sherpa*_sys_*"+d+".root")
				os.system("hadd out/Signal_PoPy"+d+".root "+d+"/Zmumu_201*_sys_*"+d+".root")
				os.system("hadd out/VV"+d+".root "+d+"/llll*_sys_*"+d+".root "+d+"/lllv*_sys_*"+d+".root "+d+"/llvv*_sys_*"+d+".root "+d+"/lvvv*_sys_*"+d+".root "+d+"/ZqqZvv*_sys_*"+d+".root "+d+"/ZqqZll*_sys_*"+d+".root "+d+"/WqqZvv*_sys_*"+d+".root "+d+"/WqqZll*_sys_*"+d+".root "+d+"/WlvZqq*_sys_*"+d+".root")

except FileNotFoundError :
	print("Non valid directory!")
	print("You are at ",os.getcwd())