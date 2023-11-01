#!/bin/bash
cp ../DATA/out/Data.root Data.root
cp ../MC/out/VV.root .
cp ../MC/out/VV_EWK.root .
cp ../MC/out/singletop.root .
cp ../MC/out/Wjets.root .
cp ../MC/out/W_EWK_Sherpa.root .
cp ../MC/out/W_EWK_PoPy.root .
cp ../MC/out/Zmumu.root .
cp ../MC/out/Zee_PoPy.root .
cp ../MC/out/Zee_Sherpa.root .
cp ../MC/out/Zee_MG.root .
cp ../MC/out/ttbar.root ttbar.root
cp ../MC/out/Signal_old.root .
cp ../MC/out/Signal_Sherpa.root .
cp ../MC/out/Signal_PoPy.root .
cp ../MC/out/Ztautau_PoPy.root .
cp ../MC/out/Zee_MGNLO.root .
cp ../MC/out/Zee_SherpaNLO.root .
hadd BG.root VV.root singletop.root Wjets.root Ztautau_PoPy.root ttbar.root Zmumu.root Zee_Sherpa.root
hadd MC.root BG.root Signal_Sherpa.root
