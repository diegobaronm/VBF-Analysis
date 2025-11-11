# VBF-Analysis

To run one of the channels you have two options:

## Local run

Go to the `MC` directory inside the respective channel directory (for example `TauMu/MC`) and run:

`python3 RunAnalysis.py`

If you use the help options you will see

```
usage: RunAnalysis.py [-h] [--j J] [--clean] sample {yes,no} tree region

Run VBF Analysis!

positional arguments:
  sample      The name of the sample from the ones on the metadata. It can also
              be a file in which case the code will check that the path exists
              and will do parallel processing according to the optional --j
              parameter.
  {yes,no}    Is the code running remotely? (yes/no)
  tree        Tree to run over. Usually NOMINAL.
  region      Region to run over. Should contain OS or SS in the name.

options:
  -h, --help  show this help message and exit
  --j J       Number of jobs to run in parallel. Default is 1.
  --clean     Clean the output directory before running the analysis. Default
              is False.
```

then, one valid run will look like:

```
python3 RunAnalysis.py InputDatasets/Higgs.txt no NOMINAL NewZpeakOS --j10
```

## Condor run:

Run the `Submit.py` command and choose the desired channel and follow the instructions.

## Inputs/Outputs handling:

Code to do IO operations are stored in the `HandleIO` directory. An explanation of the scripts that live there can be found in the [README.md](HandleIO/README.md)

## Python environment for code in `Scripts/HandleIO`

The analysis scripts in the `Scripts` directory require a Python environment with specific packages. A setup script is provided to automatically create and manage this environment. Load it with `source SetupPythonScripts.sh`.

### Prerequisites

- **ROOT**: The analysis requires ROOT to be installed and available in your system PATH. The setup script will automatically check for ROOT availability before proceeding.

### Environment Setup

Run the setup script from the project root directory:

```bash
source setup_vbf_env.sh
```

This script will:
1. **Check ROOT availability**: Verify that ROOT is installed and display its location and version
2. **Create virtual environment**: Create a Python virtual environment named `vbf_pyenv` (only on first run)
3. **Install dependencies**: Install required packages from `requirements.txt` (numpy, pandas, scipy)
4. **Activate environment**: Automatically activate the environment for immediate use

### Usage

- **First run**: Creates the environment and installs all dependencies
- **Subsequent runs**: Simply activates the existing environment
- **Manual activation**: `source vbf_pyenv/bin/activate`
- **Deactivation**: `deactivate`

If ROOT is not found, the script will exit with installation instructions.

### Note for Jupyter Notebooks in VS Code

When working with Jupyter notebooks in VS Code (like `Scripts/SREstimator.ipynb`):

1. **Select the correct kernel**: Choose `vbf_pyenv` as the Python kernel in VS Code
2. **Add project path**: Include the following code at the beginning of your notebook to ensure proper module imports:

```python
import sys
import os
sys.path.append(os.path.dirname(os.getcwd()))  # Add parent directory to path
```

This ensures that the notebook can access all modules and scripts in the project directory structure.


# Common problems:

This is a list of things that can usually go wrong while running the code.
- Using MC-only variables in `if` statements when running over real data samples.