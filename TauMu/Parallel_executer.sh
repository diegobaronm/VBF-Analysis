#!/bin/bash
rm MC/out/NOMINAL/*
rm DATA/out/NOMINAL/*

#python3 Compiler.py DATA

#cd DATA

#parallel -j $1 --progress -a Input.txt python3 RunAnalysis.py ::: no ::: 
NOMINAL

#cd ..

python3 Compiler.py MC

cd MC

parallel -j $1 --progress -a Input.txt python3 RunAnalysis.py ::: no ::: NOMINAL

cd ..

cp DATA/out/NOMINAL/*.root MC/out/NOMINAL/.
