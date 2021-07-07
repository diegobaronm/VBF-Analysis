#!/bin/bash
cp ../DATA/out/data.root Data.root
cp ../MC/out/VV.root .
cp ../MC/out/singletop.root .
cp ../MC/out/Wjets.root .
cp ../MC/out/Zmumu.root Zjet.root
cp ../MC/out/ttbar.root ttbar.root
cp ../MC/out/Signal_Sherpa.root .
cp ../MC/out/Signal_PoPy.root .
cp ../MC/out/VBF_Ztautau.root .
hadd BG.root VV.root singletop.root Wjets.root Zjet.root ttbar.root VBF_Ztautau.root
hadd MC.root BG.root Signal_Sherpa.root
