#!/bin/bash
cat samples.txt | awk '(/Ztautau/ && /sherpa/) && !(/VBF/)' > samples_Sherpa.txt

cd ..

python3 Compiler.py MC

cd MC

rm out/*

parallel --progress -j $1 -a samples_Sherpa.txt python3 RunAnalysis.py ::: no

hadd out/Signal_Sherpa$2.root out/*.root

cp out/Signal_Sherpa$2.root ../Plots/$3/.