#!/bin/bash
rm out/*
mc_signal_popy='Ztautau'
year=('2015' '2017' '2018')
for y in ${year[@]}
do
	python3 RunAnalysis.py $mc_signal_popy'_'$y no
done
hadd out/Signal.root out/Ztautau_2018.root out/Ztautau_2017.root out/Ztautau_2015.root
