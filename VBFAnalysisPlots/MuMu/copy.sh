#!/bin/bash
parentDirectory="MuMu"
cp ../../$parentDirectory/DATA/out/Data.root Data.root
cp ../../$parentDirectory/MC/out/VV.root .
cp ../../$parentDirectory/MC/out/VV_EWK.root .
cp ../../$parentDirectory/MC/out/singletop.root .
cp ../../$parentDirectory/MC/out/Wjets.root .
cp ../../$parentDirectory/MC/out/W_EWK_Sherpa.root .
cp ../../$parentDirectory/MC/out/W_EWK_PoPy.root .
cp ../../$parentDirectory/MC/out/Signal_old.root .
cp ../../$parentDirectory/MC/out/Signal_Sherpa.root .
cp ../../$parentDirectory/MC/out/Signal_PoPy.root .
cp ../../$parentDirectory/MC/out/ttbar.root ttbar.root
cp ../../$parentDirectory/MC/out/Zmumu_Sherpa.root .
cp ../../$parentDirectory/MC/out/Zmumu_PoPy.root .
cp ../../$parentDirectory/MC/out/Zmumu_MG.root .
cp ../../$parentDirectory/MC/out/Zmumu_MGNLO.root .
cp ../../$parentDirectory/MC/out/Zmumu_SherpaNLO.root .
hadd BG.root VV.root singletop.root Wjets.root ttbar.root Zmumu_Sherpa.root
hadd MC.root BG.root Signal_Sherpa.root
