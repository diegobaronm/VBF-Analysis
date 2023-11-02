#!/bin/bash
parentDirectory="EleTau"
cp ../../$parentDirectory/DATA/out/data.root Data.root
cp ../../$parentDirectory/MC/out/VV.root .
cp ../../$parentDirectory/MC/out/singletop.root .
cp ../../$parentDirectory/MC/out/Wjets.root .
cp ../../$parentDirectory/MC/out/Zjets.root Zjets.root
cp ../../$parentDirectory/MC/out/ttbar.root ttbar.root
cp ../../$parentDirectory/MC/out/Ztautau_Sherpa.root .
cp ../../$parentDirectory/MC/out/Ztautau_SherpaNLO.root .
cp ../../$parentDirectory/MC/out/Ztautau_PoPy.root .
cp ../../$parentDirectory/MC/out/Ztautau_MG.root .
cp ../../$parentDirectory/MC/out/Ztautau_MGNLO.root .
cp ../../$parentDirectory/MC/out/Higgs.root .
cp ../../$parentDirectory/MC/out/Signal_PoPy.root .
cp ../../$parentDirectory/MC/out/Signal_Sherpa.root .
cp ../../$parentDirectory/MC/out/W_EWK_Sherpa.root .
cp ../../$parentDirectory/MC/out/W_EWK_PoPy.root .
cp ../../$parentDirectory/MC/out/VV_EWK.root .
hadd BG.root VV_EWK.root W_EWK_Sherpa.root VV.root singletop.root Wjets.root Zjets.root ttbar.root Ztautau_Sherpa.root Higgs.root
hadd MC.root BG.root Signal_Sherpa.root
