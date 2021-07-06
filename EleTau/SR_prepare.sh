#!/bin/bash
cp MC/Analysis_SR.C MC/Analysis_SR_BU.C
cp MC/Analysis_CR.C MC/Analysis_CR_BU.C
cp MC/Analysis.C MC/Analysis_LastRunned.C
cp MC/Analysis_SR.C MC/Analysis.C
cp MC/Analysis.C DATA/Analysis.C

cp MC/backend/CLoop_SR.C MC/backend/CLoop.C
cp MC/backend/CLoop_SR.C DATA/backend/CLoop.C


cp MC/backend/CLoop.h DATA/backend/CLoop.h