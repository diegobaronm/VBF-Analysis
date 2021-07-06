#!/bin/bash

if [$2=="erase"]
then
  rm MC/out/*
  rm DATA/out/*
fi
mc_bg=('Wplusenu_'$1 'Wminusenu_'$1 'Wplusmunu_'$1 'Wminusmunu_'$1 'Wplustaunu_'$1 'Wminustaunu_'$1 'Zmumu_'$1 'llll_'$1 'lllv_'$1 'llvv_'$1 'lvvv_'$1 'ttbar_'$1 'st_schan_'$1 'sat_schan_'$1 'st_tchan_'$1 'sat_tchan_'$1 'st_wt_'$1 'sat_wt_'$1)
mc_signal='Ztautau_'$1
data='data_'$1

cd MC

python3.7 RunAnalysis.py $mc_signal no

for file in ${mc_bg[@]}
do
  python3.7 RunAnalysis.py $file no
done

cd ..
cd DATA

for file in $data
do
  python3.7 RunAnalysis.py $file no
done

cd ..

hadd MC/out/VV_$1.root MC/out/llll_$1.root MC/out/lllv_$1.root MC/out/llvv_$1.root MC/out/lvvv_$1.root
hadd MC/out/Wjets_$1.root MC/out/Wplusenu_$1.root MC/out/Wminusenu_$1.root MC/out/Wplusmunu_$1.root MC/out/Wminusmunu_$1.root MC/out/Wplustaunu_$1.root MC/out/Wminustaunu_$1.root
hadd MC/out/singletop_$1.root MC/out/st_schan_$1.root MC/out/sat_schan_$1.root MC/out/st_tchan_$1.root MC/out/sat_tchan_$1.root MC/out/st_wt_$1.root MC/out/sat_wt_$1.root

hadd DATA/out/data_$1.root DATA/out/data_$1*

