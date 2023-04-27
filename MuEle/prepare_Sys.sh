#!/bin/bash
cp MC/Analysis_Sys.C MC/Analysis.C
cp MC/backend/CLoop_SR.C MC/backend/CLoop.C
python3 Compiler.py MC
rm MC/error/* MC/output/* MC/log/*
