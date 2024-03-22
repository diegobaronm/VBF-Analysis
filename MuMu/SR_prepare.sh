#!/bin/bash
cp MC/Analysis_SR.C MC/Analysis.C
cp MC/backend/CLoop_SR.C MC/backend/CLoop.C
rm MC/error/* MC/output/* MC/log/*

python3 Compiler.py MC