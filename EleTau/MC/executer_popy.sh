#!/bin/bash
cat samples.txt | awk '(/Ztautau/) && !(/VBF/ || /sherpa/)' > samples_PoPy.txt

cd ..

python3 Compiler.py MC

cd MC

rm out/*

parallel --progress -j $1 -a samples_PoPy.txt python3 RunAnalysis.py ::: no

hadd out/Signal_PoPy$2.root out/*.root

cp out/Signal_PoPy$2.root ../Plots/$3/.