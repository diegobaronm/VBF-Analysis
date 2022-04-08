#!/bin/bash
cp ../DATA/out/data.root Data.root
cp ../MC/out/VV.root .
cp ../MC/out/singletop.root .
cp ../MC/out/Wjets.root .
cp ../MC/out/Zjets.root Zjets.root
cp ../MC/out/ttbar.root ttbar.root
cp ../MC/out/Ztautau_Sherpa.root .
cp ../MC/out/Ztautau_PoPy.root .
cp ../MC/out/Ztautau_MG.root .
cp ../MC/out/Higgs.root .
cp ../MC/out/Signal_PoPy.root .
cp ../MC/out/Signal_Sherpa.root .
hadd BG.root VV.root singletop.root Wjets.root Zjets.root ttbar.root Ztautau_Sherpa.root Higgs.root
hadd MC.root BG.root Signal_Sherpa.root
