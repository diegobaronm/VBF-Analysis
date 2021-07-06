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
year=('2018' '2017' '2015')
for n in ${samples[@]}
do
    for y in ${year[@]}
    do
        python3 RunAnalysis.py $mc_signal_sherpa$n'_'$y no
    done
done
rm out/Ztautau_sherpa*_*_*.root
hadd out/Signal.root out/*

cd ..

years=('2018' '2017' '2015')
for i in ${years[@]}
do
    ./executer.sh $i
done

hadd MC/out/Signal_PoPy.root MC/out/Ztautau_2018.root MC/out/Ztautau_2017.root MC/out/Ztautau_2015.root
hadd MC/out/Zmumu.root MC/out/Zmumu_2018.root MC/out/Zmumu_2017.root MC/out/Zmumu_2015.root
hadd MC/out/VV.root MC/out/VV_2018.root MC/out/VV_2017.root MC/out/VV_2015.root
hadd MC/out/Wjets.root MC/out/Wjets_2018.root MC/out/Wjets_2017.root MC/out/Wjets_2015.root
hadd MC/out/singletop.root MC/out/singletop_2018.root MC/out/singletop_2017.root MC/out/singletop_2015.root
hadd MC/out/ttbar.root MC/out/ttbar_2018.root MC/out/ttbar_2017.root MC/out/ttbar_2015.root
hadd DATA/out/data.root DATA/out/data_2018.root DATA/out/data_2017.root DATA/out/data_2015.root
