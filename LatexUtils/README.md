# LatexUtils

Utilities to collect plots and produce LaTeX-ready yield tables for papers/notes.

These tools assume you are in the project root (`VBF-Analysis`) and that you have the `vbf_pyenv` environment active and ROOT available (see the top-level README for environment setup).

## Contents

- `CopyPlots.py` — Copy PDF plots referenced by a LaTeX document from selected analysis folders into a clean destination while preserving directory structure.
- `ScrapLatexDoc.py` — Parse LaTeX documents to extract figure paths from `\includegraphics` commands. Used by `CopyPlots.py`.
- `PrintYields.py` — Read ROOT histograms for each sample and produce yields with statistical uncertainties (CSV and optional LaTeX-ready CSV).
- `PrintYieldsWithSFs.py` — Same as above, but applies per-sample scale factors and writes a LaTeX-ready CSV for the table.
- `LatexTables.ipynb` — Notebook to interactively build/format tables.

## Prerequisites

- Activate the analysis Python environment (creates/loads `vbf_pyenv`):

```bash
source ./setup_vbf_env.sh
```

- A `_setup_project_path.py` module is available in this directory. If you write new scripts that need to import from `AnalysisCommons` or other project packages, add `import _setup_project_path` at the top. The existing scripts (`CopyPlots.py`, `PrintYields.py`, `PrintYieldsWithSFs.py`, `ScrapLatexDoc.py`) do not currently need project-level imports.

- Ensure ROOT is installed and available in your PATH (the setup script checks this).

- Optional for notebooks (VS Code): select the `vbf_pyenv` kernel. If you need to import from parent folders in a notebook, add at the top:

```python
import sys, os
sys.path.append(os.path.dirname(os.getcwd()))
```

## Copy plots referenced in LaTeX (PDFs)

`CopyPlots.py` copies PDF files from analysis output folders into a destination inside your LaTeX document directory. It only copies PDFs that are actually referenced by `\includegraphics` commands in the `.tex` files (discovered via `ScrapLatexDoc.py`). The following top-level source folders are scanned:

```
ALLOWED_DIRS = ['Zee','MuMu','Zll','TauTau','TauMu','EleTau','MuEle','MjjRWStudies']
```

Usage (from repo root):

```bash
python LatexUtils/CopyPlots.py <source> <latexDocPath> [--destination NAME]
```

- `source`: Directory containing analysis plots (e.g. `VBFAnalysisPlots`).
- `latexDocPath`: Path to the LaTeX document directory. The script scans all `.tex` files here to discover referenced figures.
- `--destination`: Subfolder name inside `latexDocPath` where plots are copied (default: `analysisPlots`). The full destination is `<latexDocPath>/<destination>/`.
- Only `.pdf` files referenced in the LaTeX documents are copied; unreferenced PDFs and other file types are ignored.
- To change which top-level source folders are included, edit `ALLOWED_DIRS` in the script.

Example:

```bash
python LatexUtils/CopyPlots.py VBFAnalysisPlots /path/to/my/paper --destination figures
```

## Parse LaTeX documents for figures

`ScrapLatexDoc.py` extracts figure paths from `\includegraphics` commands in LaTeX documents. It is primarily used by `CopyPlots.py` but can also be used standalone.

Key functions:
- `get_all_figure_paths(root_dir)` — Recursively scans all `.tex` files under `root_dir` and returns a list of all referenced figure paths.
- `get_included_figure_paths(latex_doc_path)` — Extracts figure paths from a single `.tex` file.
- `get_all_tex_files(root_dir)` — Finds all `.tex` files recursively.

Usage (as a module):

```python
from ScrapLatexDoc import get_all_figure_paths
figures = get_all_figure_paths("/path/to/latex/project")
```

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
2. Copy the plots referenced in your LaTeX document:
   ```bash
   python LatexUtils/CopyPlots.py VBFAnalysisPlots /path/to/latex/doc
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
- No PDFs copied — confirm your plots are `.pdf`, that the parent folder name is listed in `ALLOWED_DIRS`, and that the figures are referenced by `\includegraphics` in the `.tex` files under your `latexDocPath`.
- Notebooks can’t import project modules — add the project path to `sys.path` as shown above and use the `vbf_pyenv` kernel.
