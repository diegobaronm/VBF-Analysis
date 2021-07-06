#!/bin/bash

mc_bg=('Wplusenu_'$1 'Wminusenu_'$1 'Wplusmunu_'$1 'Wminusmunu_'$1 'Wplustaunu_'$1 'Wminustaunu_'$1 'Zmumu_'$1 'llll_'$1 'lllv_'$1 'llvv_'$1 'lvvv_'$1 'ZqqZvv_'$1 'ZqqZll_'$1 'WqqZvv_'$1 'WqqZll_'$1 'WlvZqq_'$1 'ttbar_'$1 'st_schan_top_'$1 'st_schan_atop_'$1 'st_tchan_top_'$1 'st_tchan_atop_'$1 'st_wt_top_'$1 'st_wt_atop_'$1)
mc_signal_PoPy='Ztautau_'$1
data='data_'$1

cd MC

python3 RunAnalysis.py $mc_signal_PoPy no

for file in ${mc_bg[@]}
do
  python3 RunAnalysis.py $file no
done

cd ..
cd DATA

for file in $data
do
  python3 RunAnalysis.py $file no
done

cd ..


