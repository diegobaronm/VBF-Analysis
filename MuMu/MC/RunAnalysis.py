#!/usr/bin/env python3

# ----------------------------------------------------------------
#
#	The shebang above is MANDATORY for Condor execution!
#
# ----------------------------------------------------------------

# script which the user launches to ask which data sets to analyse, handle weighting and launch the
# analysis

import sys
sys.path.append('../../') # allow code to be imported from main directory

from AnalysisCommons.Metadata.infofileZmumu import infos
from AnalysisCommons.Metadata.datasetsZmumu import dataSets, realList, dataCombos, dirs
from AnalysisCommons.Metadata.OutputPaths import Zmm_outputs_path
from AnalysisCommons.Run import RunAnalysis, INFO

def main():
    INFO.log("Starting Zmumu analysis script.")
    RunAnalysis(dataCombos = dataCombos,
                dataSets = dataSets,
                realList = realList,
                infos = infos,
                dirs = dirs,
                output_dict = Zmm_outputs_path)
    INFO.log("Finished Zmumu analysis script.")

if __name__ == "__main__":
    main()