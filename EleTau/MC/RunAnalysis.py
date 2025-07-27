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

from AnalysisCommons.Metadata.infofileTauTau import infos
from AnalysisCommons.Metadata.datasetsTauTau import dataSets, realList, dataCombos, dirs
from AnalysisCommons.Metadata.OutputPaths import Zte_outputs_path
from AnalysisCommons.Run import RunAnalysis, INFO

def main():
    INFO.log("Starting Ztaue analysis script.")
    RunAnalysis(dataCombos = dataCombos,
                dataSets = dataSets,
                realList = realList,
                infos = infos,
                dirs = dirs,
                output_dict = Zte_outputs_path)
    INFO.log("Finished Ztaue analysis script.")

if __name__ == "__main__":
    main()