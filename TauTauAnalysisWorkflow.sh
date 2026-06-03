#!/bin/bash
SELECTION_NAME=Higgs
HISTO_TEMPLATES_NAME=tautauHiggsHistograms
RESULTS_PATH=../VBFAnalysisPlots/TauTau/TauhadTaulep/Higgs/
RESULTS_DIR=BDT5Folds

# OS region
echo "Running analysis for OS region..."
python3 RunAnalysis.py TauMu InputDatasets/Input.txt no NOMINAL ${SELECTION_NAME}OS --clean --mode h --j 10
python3 RunAnalysis.py EleTau InputDatasets/Input.txt no NOMINAL ${SELECTION_NAME}OS --clean --mode h --j 10
cd HandleIO
echo "Merging outputs for OS region..."
python3 OutputsMerger.py --inputs ../TauMu/MC/out/NOMINAL/ --outputs ../TauMu/MC/out/ --channel TauMu --rw-samples Ztautau_Sherpa,Ztautau_SherpaNLO,Ztautau_MG,Ztautau_MGNLO --rw-tags ParabolicCutoffClosure
python3 OutputsMerger.py --inputs ../EleTau/MC/out/NOMINAL/ --outputs ../EleTau/MC/out/ --channel EleTau --rw-samples Ztautau_Sherpa,Ztautau_SherpaNLO,Ztautau_MG,Ztautau_MGNLO --rw-tags ParabolicCutoffClosure
python3 AddChannels.py
cd ..
# SS region
echo "Running analysis for SS region..."
python3 RunAnalysis.py TauMu InputDatasets/Input.txt no NOMINAL ${SELECTION_NAME}SS --clean --mode h --j 10
python3 RunAnalysis.py EleTau InputDatasets/Input.txt no NOMINAL ${SELECTION_NAME}SS --clean --mode h --j 10
cd HandleIO
echo "Merging outputs for SS region..."
python3 OutputsMerger.py --inputs ../TauMu/MC/out/NOMINAL/ --outputs ../TauMu/MC/out/ --channel TauMu --rw-samples Ztautau_Sherpa,Ztautau_SherpaNLO,Ztautau_MG,Ztautau_MGNLO --rw-tags ParabolicCutoffClosure
python3 OutputsMerger.py --inputs ../EleTau/MC/out/NOMINAL/ --outputs ../EleTau/MC/out/ --channel EleTau --rw-samples Ztautau_Sherpa,Ztautau_SherpaNLO,Ztautau_MG,Ztautau_MGNLO --rw-tags ParabolicCutoffClosure
python3 AddChannels.py
cd ..
# Calculate MJ
cd Scripts
echo "Calculating MJ..."
python3 MJEstimate.py ${RESULTS_PATH} ${RESULTS_DIR} --histo_templates ${HISTO_TEMPLATES_NAME}
# Plot
# python3 PlotVariousEWjjQCDjj.py ../VBFAnalysisPlots/TauTau/TauhadTaulep/Zpeak/NewBDTOS/configPlot.yml Ztautau --sfs-dict Zll
