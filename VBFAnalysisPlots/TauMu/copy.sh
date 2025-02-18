#!/bin/bash
parentDirectory="TauMu"
cp ../../$parentDirectory/MC/out/data.root Data.root
cp ../../$parentDirectory/MC/out/VV.root .
cp ../../$parentDirectory/MC/out/singletop.root .
cp ../../$parentDirectory/MC/out/Wjets.root .
cp ../../$parentDirectory/MC/out/Zmumu.root Zjet.root
cp ../../$parentDirectory/MC/out/ttbar.root ttbar.root
cp ../../$parentDirectory/MC/out/Ztautau_Sherpa.root .
cp ../../$parentDirectory/MC/out/Ztautau_SherpaNLO.root .
cp ../../$parentDirectory/MC/out/Ztautau_PoPy.root .
cp ../../$parentDirectory/MC/out/Ztautau_MG.root .
cp ../../$parentDirectory/MC/out/Ztautau_MGNLO.root .
cp ../../$parentDirectory/MC/out/Higgs.root .
cp ../../$parentDirectory/MC/out/Higgs_EWK.root .
cp ../../$parentDirectory/MC/out/Signal_PoPy.root .
cp ../../$parentDirectory/MC/out/Signal_Sherpa.root .
cp ../../$parentDirectory/MC/out/W_EWK_Sherpa.root .
cp ../../$parentDirectory/MC/out/W_EWK_PoPy.root .
cp ../../$parentDirectory/MC/out/VV_EWK.root .
hadd BG.root VV_EWK.root W_EWK_Sherpa.root VV.root singletop.root Wjets.root Zjet.root ttbar.root Ztautau_Sherpa.root Higgs.root Higgs_EWK.root
hadd MC.root BG.root Signal_Sherpa.root
