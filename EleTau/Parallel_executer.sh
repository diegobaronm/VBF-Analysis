#!/bin/bash
rm MC/out/*
rm DATA/out/*
cp MC/Analysis.h DATA/Analysis.h

python3 Compiler.py DATA

python3 lister.py DATA

cd DATA

parallel -j $1 --progress -a samples.txt python3 RunAnalysis.py ::: no

cd ..

python3 Compiler.py MC

python3 lister.py MC

cd MC

parallel -j $1 --progress -a samples.txt python3 RunAnalysis.py ::: no

cd ..


hadd MC/out/Ztautau_Sherpa.root MC/out/Ztautau_sherpa*.root
hadd MC/out/Ztautau_PoPy.root MC/out/Ztautau_201*.root
hadd MC/out/Signal.root MC/out/VBF_Ztautau_201*.root
hadd MC/out/VBF_Zee.root MC/out/VBF_Zee_201*.root
hadd MC/out/Zjets.root MC/out/Zmumu_*.root MC/out/Zee_*.root
hadd MC/out/VV.root MC/out/llll_*.root MC/out/lllv_*.root MC/out/llvv_*.root MC/out/lvvv_*.root MC/out/ZqqZvv_*.root MC/out/ZqqZll_*.root MC/out/WqqZvv_*.root MC/out/WqqZll_*.root MC/out/WlvZqq_*.root
hadd MC/out/Wjets.root MC/out/Wplusenu_*.root MC/out/Wminusenu_*.root MC/out/Wplusmunu_*.root MC/out/Wminusmunu_*.root MC/out/Wplustaunu_*.root MC/out/Wminustaunu_*.root
hadd MC/out/singletop.root MC/out/st_schan_top_*.root MC/out/st_schan_atop_*.root MC/out/st_tchan_top_*.root MC/out/st_tchan_atop_*.root MC/out/st_wt_top_*.root MC/out/st_wt_atop_*.root
hadd MC/out/Higgs.root MC/out/WpH*.root MC/out/WmH*.root MC/out/ZHllbb*.root MC/out/ZHlltautau*.root MC/out/ggHttlm15hp20*.root MC/out/ggHttlp15hm20*.root MC/out/VBFHttlm15hp20*.root MC/out/VBFHttlp15hm20*.root
hadd MC/out/ttbar.root MC/out/ttbar_201*.root
hadd DATA/out/data.root DATA/out/data_201*.root