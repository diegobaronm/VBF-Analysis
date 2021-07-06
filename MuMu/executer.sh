#!/bin/bash

mc_bg=('Wplusenu_'$1 'Wminusenu_'$1 'Wplusmunu_'$1 'Wminusmunu_'$1 'Wplustaunu_'$1 'Wminustaunu_'$1 'Zmumu_'$1 'llll_'$1 'lllv_'$1 'llvv_'$1 'lvvv_'$1 'ZqqZvv_'$1 'ZqqZll_'$1 'WqqZvv_'$1 'WqqZll_'$1 'WlvZqq_'$1 'ttbar_'$1 'st_schan_top_'$1 'st_schan_atop_'$1 'st_tchan_top_'$1 'st_tchan_atop_'$1 'st_wt_top_'$1 'st_wt_atop_'$1)
mc_Ztautau_PoPy='Ztautau_'$1
data='data_'$1

cd MC

python3 RunAnalysis.py $mc_Ztautau_PoPy no

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

# Adding all different files

cd MC/out/

hadd $mc_Ztautau_PoPy'.root' $mc_Ztautau_PoPy*

for sample in ${mc_bg[@]}
do
  hadd $sample'.root' $sample*
done

cd ../..

hadd MC/out/VV_$1.root MC/out/llll_$1.root MC/out/lllv_$1.root MC/out/llvv_$1.root MC/out/lvvv_$1.root MC/out/ZqqZvv_$1.root MC/out/ZqqZll_$1.root MC/out/WqqZvv_$1.root MC/out/WqqZll_$1.root MC/out/WlvZqq_$1.root
hadd MC/out/Wjets_$1.root MC/out/Wplusenu_$1.root MC/out/Wminusenu_$1.root MC/out/Wplusmunu_$1.root MC/out/Wminusmunu_$1.root MC/out/Wplustaunu_$1.root MC/out/Wminustaunu_$1.root
hadd MC/out/singletop_$1.root MC/out/st_schan_top_$1.root MC/out/st_schan_atop_$1.root MC/out/st_tchan_top_$1.root MC/out/st_tchan_atop_$1.root MC/out/st_wt_top_$1.root MC/out/st_wt_atop_$1.root

hadd DATA/out/data_$1.root DATA/out/data_$1*

