# LatexUtils

Utilities to collect plots and produce LaTeX-ready yield tables for papers/notes.

These tools assume you are in the project root (`VBF-Analysis`) and that you have the `vbf_pyenv` environment active and ROOT available (see the top-level README for environment setup).

## Contents

- `CopyPlots.py` — Recursively copy only PDF plots from selected analysis folders into a clean destination while preserving directory structure.
- `PrintYields.py` — Read ROOT histograms for each sample and produce yields with statistical uncertainties (CSV and optional LaTeX-ready CSV).
- `PrintYieldsWithSFs.py` — Same as above, but applies per-sample scale factors and writes a LaTeX-ready CSV for the table.
- `LatexTables.ipynb` — Notebook to interactively build/format tables.

## Prerequisites

- Activate the analysis Python environment (creates/loads `vbf_pyenv`):

```bash
source Scripts/SetupPythonScripts.py
source ./setup_vbf_env.sh
```

- Ensure ROOT is installed and available in your PATH (the setup script checks this).

- Optional for notebooks (VS Code): select the `vbf_pyenv` kernel. If you need to import from parent folders in a notebook, add at the top:

```python
import sys, os
sys.path.append(os.path.dirname(os.getcwd()))
```

## Copy only plots (PDFs)

`CopyPlots.py` keeps just the PDF files and the directory hierarchy for a set of allowed top-level folders in `VBFAnalysisPlots`:

```
ALLOWED_DIRS = ['Zee','MuMu','Zll','TauTau','TauMu','EleTau','MuEle','MjjRWStudies']
```

Usage (from repo root):

```bash
python LatexUtils/CopyPlots.py VBFAnalysisPlots DESTINATION_DIR
```

- Source: `VBFAnalysisPlots` (where the analysis plots are stored).
- Destination: any empty or existing folder; subfolders are created as needed.
- Only `.pdf` files are copied; other file types are ignored.
- To change which top-level folders are included, edit `ALLOWED_DIRS` in the script.

## Print yields from ROOT histograms

`PrintYields.py` integrates a histogram in each ROOT file (excluding `MC.root`, `BG.root`, `Average*.root`) and computes the statistical uncertainty using `TH1::IntegralAndError`.

Usage:

```bash
python LatexUtils/PrintYields.py <finalStateName> <histogramName> <path_to_root_files>
```

Example:

```bash
python LatexUtils/PrintYields.py Zll mass_jj VBFAnalysisPlots/Zll/Z-peak/SR
```

Interactive prompts:
- "Print to file (y/n)?" — write results to CSV.
- If yes: "Latex format (y/n)?" — write an additional LaTeX-friendly CSV (`<finalStateName>_latex.csv`).

Outputs:
- `<finalStateName>.csv` with two columns: `Yield`, `Stat. Uncertainty`.
- Optional `<finalStateName>_latex.csv` with formatted strings like `$123.4 \pm 5.6$`.

Notes:
- If a file does not contain the requested histogram or it isn’t a `TH1`, the script prints a warning and records a yield of 0 with uncertainty 0.

## Print yields with scale factors (SFs)

`PrintYieldsWithSFs.py` is parameterized in the script (no CLI). It:
- Opens a set of hard-coded samples under `samplesPath`.
- Reads a specific `histogramName` and takes the content of bin 1 (as currently written).
- Applies sample-specific SFs from `sf_dict` (if the sample is present in the dict).
- Sums MC samples (with some exclusions) into `Total MC`.
- Writes a LaTeX-formatted CSV: `YieldsWithSFs_<channel>.csv`.

Edit the following at the bottom of `PrintYieldsWithSFs.py` before running:

- `samplesPath` — directory with the ROOT files (one per sample, named `<Sample>.root`).
- `channel` — channel name used in the CSV filename.
- `samples` — dict of samples to read; keys are base file names (without `.root`).
- `sf_dict` — dict of `sample -> ufloat(SF, SF_error)` to apply.
- `histogramName` — histogram to read (the script currently uses bin 1 content and error).
- `outputFileName` — CSV output path.

Run:

```bash
python LatexUtils/PrintYieldsWithSFs.py
```

Outputs:
- `YieldsWithSFs_<channel>.csv` with LaTeX strings `$value \pm error$` per sample.

Caveats:
- The "Total MC" sum excludes certain samples (e.g., `Data`, `Signal_PoPy`, `MGNLO`). Adjust the exclusion logic if your sample list changes.
- If a file is missing, the script warns and sets that sample’s yield to 0.

## Notebook: LatexTables.ipynb

Open in VS Code and select the `vbf_pyenv` kernel. Use it to format or combine the CSVs into final LaTeX tables for your document.

## Typical workflow

1. Run your analysis to populate `VBFAnalysisPlots/...`.
2. Copy the plots you need into a clean folder for the note:
   ```bash
   python LatexUtils/CopyPlots.py VBFAnalysisPlots ./LatexUtils/plots_copy
   ```
3. Produce yields for a region:
   ```bash
   python LatexUtils/PrintYields.py Zll mass_jj VBFAnalysisPlots/Zll/Z-peak/SR
   # choose to write CSV and optionally LaTeX format when prompted
   ```
4. If applying SFs:
   - Edit parameters in `PrintYieldsWithSFs.py` and run it to create `YieldsWithSFs_<channel>.csv`.
5. Use `LatexTables.ipynb` to assemble/format final tables.

## Troubleshooting

- "ROOT not found" — ensure ROOT is installed and available in PATH (top-level setup script checks this).
- "Histogram not found or not TH1" — verify `histogramName` and that each file contains the histogram.
- No PDFs copied — confirm your plots are `.pdf` and that the parent folder name is listed in `ALLOWED_DIRS`.
- Notebooks can’t import project modules — add the project path to `sys.path` as shown above and use the `vbf_pyenv` kernel.
