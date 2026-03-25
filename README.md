# VBF-Analysis

Analysis framework for Vector Boson Fusion (VBF) production at the ATLAS experiment, studying ττ/ee/μμ decay channels.

## Repository structure

```
VBF-Analysis/
├── RunAnalysis.py               # Unified entry point for all channels
├── requirements.txt             # Python dependencies
├── setup_vbf_env.sh             # Virtual-environment setup script
│
├── AnalysisCommons/             # Shared analysis code
│   ├── Logger.py                # Logging (timestamps, colour, optional file output)
│   ├── Constants.py             # Physics constants (RQCD, normalisation factors, Z' xsecs)
│   ├── Run.py                   # Core analysis engine (event loop, compilation, output handling)
│   ├── Systematics.py           # 160+ systematic variation definitions
│   └── Metadata/                # Dataset and channel configuration
│       ├── ChannelConfig.py     # Channel registry (maps name → metadata)
│       ├── DatasetsPaths.py     # Input ntuple paths (per-user)
│       ├── OutputPaths.py       # Output paths for HTCondor (per-user)
│       ├── infofile*.py         # MC cross-section / efficiency metadata
│       └── datasets*.py         # Dataset combination definitions
│
├── EleTau/ TauMu/ MuEle/        # τ-lepton decay channels
│   └── MC/
│       ├── Analysis.C           # Channel-specific C++ selection code
│       ├── backend/             # Compiled C++ event loop (CLoop.C, CLoopSYS.C)
│       └── InputDatasets/       # Input file lists
│
├── MuMu/ Zee/                   # Di-lepton decay channels (same structure)
│
├── HandleIO/                    # I/O helpers (file merging, validation, systematics)
├── Scripts/                     # Post-processing, plotting, background estimation
├── LatexUtils/                  # LaTeX yield tables and plot copying
└── CondorSubmit/                # HTCondor job submission
```

## Running the analysis

### Local

Run any channel from the project root:

```bash
python3 RunAnalysis.py <channel> <sample> <remote> <tree> <region> [options]
```

**Example:**

```bash
python3 RunAnalysis.py EleTau InputDatasets/Higgs.txt no NOMINAL NewZpeakOS --j 10
```

Valid channels: `EleTau`, `TauMu`, `MuEle`, `MuMu`, `Zee`.

### Full CLI reference

```
positional arguments:
  channel               Channel to run (EleTau, TauMu, MuEle, MuMu, Zee)
  sample                Sample name from metadata or path to a .txt file with
                        one sample per line for batch processing
  {yes,no}              Is the code running remotely? (yes/no)
  tree                  Tree to run over (usually NOMINAL)
  region                Region name (must contain OS or SS)

options:
  --mode {h,n,hn}       Output mode: histograms (h), ntuples (n), or both (hn).
                        Default: h
  --j J                 Number of parallel jobs. Default: 1
  --clean               Clean the output directory before running
  --output DIR          Override output directory (default: out/<tree>/)
  --loglevel {1,2,3,4}  Log level: 1=ERROR, 2=WARNING, 3=INFO, 4=DEBUG.
                        Default: 3
  --log-file PATH       Also write log messages to this file
  --sys                 Run systematic variations
  --sys-channel CH      Systematics channel (Zee, Zmm, Zem, Ztm, Zte).
                        Required when --sys is set
  --sys-type TYPES      Comma-separated systematic types to run
                        (sf, kinematic, theory). Default: sf,kinematic
```

### HTCondor

```bash
cd CondorSubmit
python3 Submit.py
```

Follow the interactive prompts to select the channel, input files, region, and submission site.

## Environment setup

### Python environment

The analysis scripts in `Scripts/`, `HandleIO/`, and `LatexUtils/` require Python 3 with specific packages. A setup script creates and manages a virtual environment:

```bash
source setup_vbf_env.sh
```

This will:
1. Check that ROOT is installed and available
2. Create a `vbf_pyenv` virtual environment (first run only)
3. Install dependencies from `requirements.txt` (numpy, pandas, scipy, pyhf, matplotlib, uncertainties)
4. Activate the environment

Subsequent runs simply activate the existing environment. To deactivate: `deactivate`.

### PYTHONPATH for Scripts

When running scripts from the `Scripts/` directory, source the helper to add the project root to `PYTHONPATH`:

```bash
cd Scripts
source SetupPythonScripts.sh
```

### Jupyter notebooks in VS Code

Select `vbf_pyenv` as the Python kernel, then add at the top of your notebook:

```python
import sys, os
sys.path.append(os.path.dirname(os.getcwd()))
```

## Configuration for new users

Several scripts need to know where input ntuples and outputs live. To configure paths for your user, add your `$USER` as a key to the path dictionaries in:

- `AnalysisCommons/Metadata/DatasetsPaths.py` — directories containing input ntuples
- `AnalysisCommons/Metadata/OutputPaths.py` — output directories for HTCondor jobs
- `HandleIO/AddMjjRWFiles.py` — `BASE_PATH` for Mjj reweighted files
- `Scripts/CreateTRExFitterInputs.py` — `REMOTE_PATH` and scp host for TRExFitter uploads

## Logging

The analysis uses a custom logging system in `AnalysisCommons/Logger.py` with four levels:

| Level | Constant | Colour |
|---|---|---|
| 1 | `ERROR` | Red |
| 2 | `WARNING` | Yellow |
| 3 | `INFO` | Green |
| 4 | `DEBUG` | Blue |

All log messages include timestamps. To also write logs to a file, pass `--log-file <path>` to `RunAnalysis.py` or call `Logger.enableFileLogging(path)` in your scripts.

A reusable interactive `menu()` function is also available:

```python
from AnalysisCommons.Logger import menu
choice = menu("Pick an option:", ["Option A", "Option B", "Option C"])
```

## Additional tools

### Input/Output handling — `HandleIO/`

Scripts for creating input lists, merging ROOT files, validating outputs, and combining channels. See [HandleIO/README.md](HandleIO/README.md).

### Post-processing, plotting, fitting — `Scripts/`

YAML-driven plotting, multijet estimation, TRExFitter/CLs input preparation, and metadata generation utilities. See [Scripts/README.md](Scripts/README.md).

### LaTeX utilities — `LatexUtils/`

Yield extraction, scale-factor application, and plot copying for papers/notes. See [LatexUtils/README.md](LatexUtils/README.md).

## Common problems

- **Using MC-only variables in `if` statements when running over real data samples.** The C++ selection code may access MC-specific branches that don't exist in data trees.
- **ROOT not found** — Ensure ROOT is installed and on your `PATH` before sourcing `setup_vbf_env.sh`.
- **Import errors for `AnalysisCommons`** — Source `SetupPythonScripts.sh` from within `Scripts/`, or run scripts from the project root.
- **No dataset paths for your user** — Add your `$USER` to `DatasetsPaths.py` (see "Configuration for new users" above).