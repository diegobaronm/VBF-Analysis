#!/bin/bash
rm -r MC/out_previous
rm -r DATA/out_previous
mv MC/out/ MC/out_previous/
mkdir MC/out/
mv DATA/out/ DATA/out_previous/
mkdir DATA/out/
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

hadd MC/out/Signal_Sherpa.root MC/out/Ztautau_sherpa*.root
hadd MC/out/Signal_PoPy.root MC/out/Ztautau_201*.root
hadd MC/out/Zmumu.root MC/out/Zmumu_201*.root
hadd MC/out/VV.root MC/out/llll*.root MC/out/lllv*.root MC/out/llvv*.root MC/out/lvvv*.root MC/out/ZqqZvv*.root MC/out/ZqqZll*.root MC/out/WqqZvv*.root MC/out/WqqZll*.root MC/out/WlvZqq*.root
hadd MC/out/Wjets.root MC/out/Wplusenu*.root MC/out/Wminusenu*.root MC/out/Wplusmunu*.root MC/out/Wminusmunu*.root MC/out/Wplustaunu*.root MC/out/Wminustaunu*.root
hadd MC/out/singletop.root MC/out/st_schan_top*.root MC/out/st_schan_atop*.root MC/out/st_tchan_top*.root MC/out/st_tchan_atop*.root MC/out/st_wt_top*.root MC/out/st_wt_atop*.root
hadd MC/out/ttbar.root MC/out/ttbar_201*.root
hadd DATA/out/data.root DATA/out/data_201*.root