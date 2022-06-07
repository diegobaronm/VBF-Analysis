#!/bin/bash
cp MC/Analysis_SR.C MC/Analysis.C
cp MC/Analysis.C DATA/Analysis.C
cp MC/Analysis.h DATA/Analysis.h

cp MC/backend/CLoop_SR.C MC/backend/CLoop.C
cp MC/backend/CLoop_SR.C DATA/backend/CLoop.C

cp MC/backend/CLoop.h DATA/backend/CLoop.h

rm MC/error/* MC/output/* MC/log/*
rm DATA/error/* DATA/output/* DATA/log/*

python3 Compiler.py MC
python3 Compiler.py DATA
