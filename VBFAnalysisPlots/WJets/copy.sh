#!/bin/bash
parentDirectory="WJets"
cp ../../$parentDirectory/DATA/out/data.root Data.root
cp ../../$parentDirectory/MC/out/VV.root .
cp ../../$parentDirectory/MC/out/singletop.root .
cp ../../$parentDirectory/MC/out/Wjets.root .
cp ../../$parentDirectory/MC/out/Zmumu.root Zjet.root
cp ../../$parentDirectory/MC/out/ttbar.root ttbar.root
cp ../../$parentDirectory/MC/out/Signal_Sherpa.root .
cp ../../$parentDirectory/MC/out/Signal_PoPy.root .
hadd BG.root VV.root singletop.root Wjets.root Zjet.root ttbar.root
hadd MC.root BG.root Signal_Sherpa.root
