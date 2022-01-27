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
		os.system('hadd '+channel_dir+'MC/out/Signal_Sherpa.root NOMINAL/VBF_Ztautau_sherpa*.root')
		os.system('hadd '+channel_dir+'MC/out/Signal_PoPy.root NOMINAL/VBF_Ztautau_201*.root')
		os.system('hadd '+channel_dir+'MC/out/Ztautau_Sherpa.root NOMINAL/Ztautau_sherpa*.root')
		os.system('hadd '+channel_dir+'MC/out/Ztautau_PoPy.root NOMINAL/Ztautau_201*.root')
		os.system('hadd '+channel_dir+'MC/out/Zjets.root NOMINAL/Zmumu_*.root NOMINAL/Zee_*.root')
		os.system('hadd '+channel_dir+'MC/out/Higgs.root NOMINAL/WpH*.root NOMINAL/WmH*.root NOMINAL/ZHllbb*.root NOMINAL/ZHlltautau*.root NOMINAL/ggHttlm15hp20*.root NOMINAL/ggHttlp15hm20*.root NOMINAL/VBFHttlm15hp20*.root NOMINAL/VBFHttlp15hm20*.root')
		os.system('hadd '+channel_dir+'MC/out/VV.root NOMINAL/llll_*.root NOMINAL/lllv_*.root NOMINAL/llvv_*.root NOMINAL/lvvv_*.root NOMINAL/ZqqZvv_*.root NOMINAL/ZqqZll_*.root NOMINAL/WqqZvv_*.root NOMINAL/WqqZll_*.root NOMINAL/WlvZqq_*.root')
		os.system('hadd '+channel_dir+'MC/out/Wjets.root NOMINAL/Wplusenu_*.root NOMINAL/Wminusenu_*.root NOMINAL/Wplusmunu_*.root NOMINAL/Wminusmunu_*.root NOMINAL/Wplustaunu_*.root NOMINAL/Wminustaunu_*.root')
		os.system('hadd '+channel_dir+'MC/out/singletop.root NOMINAL/st_schan_top_*.root NOMINAL/st_schan_atop_*.root NOMINAL/st_tchan_top_*.root NOMINAL/st_tchan_atop_*.root NOMINAL/st_wt_top_*.root NOMINAL/st_wt_atop_*.root')
		os.system('hadd '+channel_dir+'MC/out/ttbar.root NOMINAL/ttbar_*.root')
		os.system('hadd '+channel_dir+'DATA/out/data.root NOMINAL/data_*.root')

	elif type_of_run==2:
		for d in os.listdir():
			if d!="out":
				os.system("hadd out/Signal_Sherpa"+d+".root "+d+"/Ztautau_sherpa*_sys_*"+d+".root")
				os.system("hadd out/Signal_PoPy"+d+".root "+d+"/Ztautau_201*_sys_*"+d+".root")
				os.system("hadd out/Zjets"+d+".root "+d+"/Zmumu_*_sys_*"+d+".root "+d+"/Zee_*_sys_*"+d+".root")
				os.system("hadd out/VV"+d+".root "+d+"/llll*_sys_*"+d+".root "+d+"/lllv*_sys_*"+d+".root "+d+"/llvv*_sys_*"+d+".root "+d+"/lvvv*_sys_*"+d+".root "+d+"/ZqqZvv*_sys_*"+d+".root "+d+"/ZqqZll*_sys_*"+d+".root "+d+"/WqqZvv*_sys_*"+d+".root "+d+"/WqqZll*_sys_*"+d+".root "+d+"/WlvZqq*_sys_*"+d+".root")

except FileNotFoundError :
	print("Non valid directory!")
	print("You are at ",os.getcwd())