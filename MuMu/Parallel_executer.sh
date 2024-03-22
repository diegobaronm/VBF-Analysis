#!/bin/bash
rm MC/out/NOMINAL/*

python3 Compiler.py MC

cd MC

# If data is passed as parameter, run the analysis for data
# If not, run the analysis for MC
#!/bin/bash

if [ "$2" = "OnlyMC" ]; then
    # Code to execute if the script is called with parameter "Data"
    echo "Running only MC"
    parallel -j $1 --progress -a InputDatasets/Input.txt python3 RunAnalysis.py ::: no ::: NOMINAL
    # Add your code here
else
    echo "Running MC and Data"
    parallel -j $1 --progress -a InputDatasets/InputData.txt python3 RunAnalysis.py ::: no ::: NOMINAL
    parallel -j $1 --progress -a InputDatasets/Input.txt python3 RunAnalysis.py ::: no ::: NOMINAL
fi

cd ..