#!/bin/bash
echo $PWD
ls
shopt -s expand_aliases
alias setupATLAS='source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh'
setupATLAS
asetup StatAnalysis,0.6.2
cd MuMu/MC
python3 RunAnalysis.py ${1} ${2} ${3} ${4} --output ${5}