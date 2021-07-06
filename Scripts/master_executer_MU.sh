#!/bin/bash
rm -r MC/out_previous
rm -r DATA/out_previous
mv MC/out/ MC/out_previous/
mkdir MC/out/
mv DATA/out/ DATA/out_previous/
mkdir DATA/out/

years=('2018' '2017' '2015')
for i in ${years[@]}
do
    ./executer.sh $i
done

hadd MC/out/Ztautau.root MC/out/Ztautau_2018.root MC/out/Ztautau_2017.root MC/out/Ztautau_2015.root
hadd MC/out/Zmumu.root MC/out/Zmumu_2018.root MC/out/Zmumu_2017.root MC/out/Zmumu_2015.root
hadd MC/out/VV.root MC/out/VV_2018.root MC/out/VV_2017.root MC/out/VV_2015.root
hadd MC/out/Wjets.root MC/out/Wjets_2018.root MC/out/Wjets_2017.root MC/out/Wjets_2015.root
hadd MC/out/singletop.root MC/out/singletop_2018.root MC/out/singletop_2017.root MC/out/singletop_2015.root
hadd MC/out/ttbar.root MC/out/ttbar_2018.root MC/out/ttbar_2017.root MC/out/ttbar_2015.root
hadd DATA/out/data.root DATA/out/data_2018.root DATA/out/data_2017.root DATA/out/data_2015.root
