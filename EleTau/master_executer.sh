#!/bin/bash
rm -r MC/out_previous
rm -r DATA/out_previous
mv MC/out/ MC/out_previous/
mkdir MC/out/
mv DATA/out/ DATA/out_previous/
mkdir DATA/out/
cp MC/Analysis.h DATA/Analysis.h


# COMPILE C++ ANALYSIS SCRIPT
python3 Compiler.py

cd MC
mc_signal_sherpa='Ztautau_sherpa'
samples=('1' '2' '3' '4' '5' '6' '7' '8' '9' '10' '11' '12' '13' '14')
year=('2015' '2017' '2018')
for n in ${samples[@]}
do
    for y in ${year[@]}
    do
        python3 RunAnalysis.py $mc_signal_sherpa$n'_'$y no
    done
done

hadd out/Signal.root out/*

cd ..


years=('2018' '2017' '2015')
for i in ${years[@]}
do
    ./executer.sh $i
done

hadd MC/out/Signal_PoPy.root MC/out/Ztautau_201*.root
hadd MC/out/Zjets.root MC/out/Zmumu_*.root MC/out/Zee_*.root
hadd MC/out/VV.root MC/out/llll_*.root MC/out/lllv_*.root MC/out/llvv_*.root MC/out/lvvv_*.root MC/out/ZqqZvv_*.root MC/out/ZqqZll_*.root MC/out/WqqZvv_*.root MC/out/WqqZll_*.root MC/out/WlvZqq_*.root
hadd MC/out/Wjets.root MC/out/Wplusenu_*.root MC/out/Wminusenu_*.root MC/out/Wplusmunu_*.root MC/out/Wminusmunu_*.root MC/out/Wplustaunu_*.root MC/out/Wminustaunu_*.root
hadd MC/out/singletop.root MC/out/st_schan_top_*.root MC/out/st_schan_atop_*.root MC/out/st_tchan_top_*.root MC/out/st_tchan_atop_*.root MC/out/st_wt_top_*.root MC/out/st_wt_atop_*.root
hadd MC/out/ttbar.root MC/out/ttbar_201*.root
hadd DATA/out/data.root DATA/out/data_201*.root
