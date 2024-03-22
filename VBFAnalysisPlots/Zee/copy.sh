#!/bin/bash
parentDirectory="Zee"
cp ../../$parentDirectory/MC/out/Data.root Data.root
cp ../../$parentDirectory/MC/out/VV.root .
cp ../../$parentDirectory/MC/out/VV_EWK.root .
cp ../../$parentDirectory/MC/out/singletop.root .
cp ../../$parentDirectory/MC/out/Wjets.root .
cp ../../$parentDirectory/MC/out/W_EWK_Sherpa.root .
cp ../../$parentDirectory/MC/out/W_EWK_PoPy.root .
cp ../../$parentDirectory/MC/out/Zmumu.root .
cp ../../$parentDirectory/MC/out/Zee_PoPy.root .
cp ../../$parentDirectory/MC/out/Zee_Sherpa.root .
cp ../../$parentDirectory/MC/out/Zee_MG.root .
cp ../../$parentDirectory/MC/out/ttbar.root ttbar.root
cp ../../$parentDirectory/MC/out/Signal_old.root .
cp ../../$parentDirectory/MC/out/Signal_Sherpa.root .
cp ../../$parentDirectory/MC/out/Signal_PoPy.root .
cp ../../$parentDirectory/MC/out/Ztautau_PoPy.root .
cp ../../$parentDirectory/MC/out/Zee_MGNLO.root .
cp ../../$parentDirectory/MC/out/Zee_SherpaNLO.root .
hadd BG.root VV.root singletop.root Wjets.root Ztautau_PoPy.root ttbar.root Zmumu.root Zee_Sherpa.root
hadd MC.root BG.root Signal_Sherpa.root
