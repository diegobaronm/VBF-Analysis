# VBF Analysis — Scripts folder

This folder contains plotting, modeling, background–estimation, and I/O helper scripts used across the VBF analysis. Below is a practical, per-script guide covering purpose, inputs/outputs, options, and example usage. Prerequisites and common utilities are listed first.


## Prerequisites

- ROOT with Python bindings (PyROOT)
- Python 3 with packages: numpy, pandas, matplotlib, PyYAML, uncertainties, scipy
- This repo on PYTHONPATH so Scripts and AnalysisCommons can be imported
- Optional access to EOS/AFS paths if using remote data locations or upload features

Environment setup
- From inside Scripts, source the helper to add the repo parent to PYTHONPATH:
  - `source SetupPythonScripts.sh`


## Common utilities

- `histogramHelpers.py` (core library)
  - Provides the HistogramInfo class and many histogram utilities: rebinning (`biner`), normalization, blind/unblind helpers, stacking/plotting helpers, data-minus-BG, negative-bin cleanup, SR consistency, uncertainty scaling, and more.
  - Exposes `templatesDict` and also named template lists like `mumuZpeakHistograms`, `llZpeakHistograms`, etc. Pass these to plotting/ratio helpers.
  - No CLI; import as a module.

- `AnalysisCommons` (external to this folder)
  - `Run.py` provides logging (INFO, WARNING, ERROR, DEBUG) and `Logger.LOGLEVEL`.
  - `Constants.py` provides normalization factors and defaults (e.g., `NORM_FACTORS_DICT`, `RQCD_VALUE`, `RQCD_UNCERTAINTY_VALUE`, `DEFAULT_MJJ_REWEIGHTING`).


## Plotting and visualization

### Plot.py
Purpose: YAML-driven plotting of stacks (Data, Signal, Background) with optional Z′ overlays and post-fit scaling.

Inputs
- YAML config file (see `configExamplePlot.yml`) with keys like: `signal_sample`, `qcd_sample`, `is_post_fit`, `vbf_scale`, `qcd_scale`, `histograms`, `final_state`, `region`, `print_version`, `print_overflows`, `blind`, `blind_mass`, `additional_signal`, `unblind_purity_limit`, `background` list, optional `Zprime_pack`.

CLI
- `python Plot.py <config_file> <channel> [--sfs-dict {Zll,Ztautau,Zee,Zmumu}] [--debug]`
  - channel: Zee | Zmumu | Ztautau | Zll
  - On start, asks to confirm the selected `--sfs-dict` (type "yes").

Behavior
- Reads YAML (moves to its directory to resolve relative paths), builds background and optional Z′ pack, sets scale factors:
  - If `is_post_fit: true`, uses `vbf_scale`/`qcd_scale` from config or infers them via `AnalysisCommons.Constants.NORM_FACTORS_DICT` and the `--sfs-dict` set.
  - Otherwise defaults to 1.0 each.
- Calls `histogramHelpers.stackPlot(...)` using the chosen histogram template from `templatesDict`.
- Optional interactive confirmation can be disabled when called programmatically (see PlotVariousEWjjQCDjj.py).

Notes
- Color strings are parsed to ROOT enums with optional "+/-" offset (e.g., `kAzure-4`).
- Watermark automatically encodes QCD/EW samples and post-fit.


### PlotVariousEWjjQCDjj.py
Purpose: Automation wrapper around Plot.py to iterate over all available QCD and EW samples in the YAML folder and produce plots for each combination.

CLI
- Same interface as Plot.py (calls `get_args()` from Plot): `python PlotVariousEWjjQCDjj.py <config_file> <channel> [--sfs-dict ...] [--debug]`

Behavior
- Deletes existing PDFs in the config directory, discovers available QCD files matching the channel and EW choices, logs combinations, and runs Plot() in non-interactive mode.
- If the config declares `is_post_fit: false`, runs unscaled plots only. Otherwise, runs scaled plus an extra unscaled copy when post-fit factors exist.


### CompareShapes.py
Purpose: Overlay up to four shapes from different ROOT files for a given histogram template with consistent rebinning and y-range.

Usage
- Script contains a `main()` example with hardcoded paths; adapt `FILE_DICT`, `REGION`/templates, and histogram list before running.
- Programmatic use: import and call `compareShapesFromDifferentFiles(histoName, histoTemplate, prefix, postfix, dictOfFiles, useDensity)`.

Notes
- Uses `biner()` and `normalization()` from `histogramHelpers` to ensure consistent binning and optional density normalization.


### 2HistogramRatio.py and RatioShapes.py
Purpose: Build ratios of two histograms, optionally apply per-bin scale factors to map one to another.

Usage
- Both scripts contain hardcoded usage examples; edit file paths, histogram names, and region templates before running.
- Core functions:
  - `RatioPlot(...)` (2HistogramRatio.py) and `plotIndividualRatio(...)`/`plotRatio(...)` (RatioShapes.py)
  - `generate_plot_input(...)` to define pairs, `get_scale_factors(...)` to compute 1/bin_content scale factors of a ratio.

Notes
- Consistent rebinning and normalization handled via `histogramHelpers`.
- Density vs absolute display controlled by flags in the examples.


### plot2D.cpp
Purpose: ROOT macro to project a TH2F into multiple 1D distributions across x-slices, rebin to custom edges, and overlay normalized shapes.

Usage
- Edit input file and histogram name, then run in ROOT C++ (e.g., `root -l -b -q 'plot2D.cpp'`).


## Background estimation and modeling

### MJEstimate.py
Purpose: Data-driven multijet (MJ) estimation using OS/SS method and optional CR-based RQCD calculation; produces `MJ.root` with histograms per template.

CLI
- `python MJEstimate.py <base_path> <SR_name> [--histo_templates <name>] [--CR <CR_name>]`
  - `--histo_templates` defaults to `tautauZpeakHistograms` (key in `templatesDict`).
  - `--CR` defaults to a sentinel to use default `RQCD` from `AnalysisCommons.Constants`.

Behavior
- Expects directory layout: `<base_path>/<RegionName>OS/` and `<RegionName>SS/` (and CR variants if provided).
- Selects EWjj = Signal_Sherpa and QCDjj = Ztautau_SherpaNLO (with `DEFAULT_MJJ_REWEIGHTING` if available), plus standard backgrounds (VV, ttbar, singletop, …, Tau/Mu/Ele channels add Higgs/Zjets/W_EWK/VV_EWK).
- Interactive menus:
  - Compute RQCD from CRs? Produce MJ.root? If producing, optionally compute RQCD per histogram from CRs.
- For each histogram template in the chosen set:
  - Consistent rebin, subtract MC from data in SRSS, scale by RQCD, sanitize negatives, handle no-MJ-evidence case (force SR bins consistent with 0±σ inside selection window), propagate RQCD uncertainty, save to MJ.root.

Notes
- Uses `templatesDict[...]` for histogram model list and binning.
- Requires ROOT files named like `<sample>.root` in the SR/CR folders.


### MjjFit.py
Purpose: Library of fit models and tools for mjj–based ratio modeling and ABCD extrapolation.

Contents
- Models: `parabolic_model`, `exponential_model`, `linear_model`, `parabolic_cutoff_model`
- FitExperiment and FitExperimentContainer classes: store model, parameters, covariance, reduced χ², and provide predictions (including cutoff behavior) with correlated parameter uncertainties (`uncertainties` package).
- Helpers: `mjj_fit_experiment` (curve_fit with optional hints), `display_fit_experiments` (matplotlib overlay of data vs fits and GoF), `predict_SR_from_experiments` (ABCD extrapolation using three CRs with two modes: function–extrapolation or point–by–point).

Notes
- Pure module; import into analysis scripts.


### RawABCDQCDjj.py
Purpose: Quick ABCD construction and SR/ABCD residuals plot for a given QCDjj sample using matplotlib.

Usage
- Edit `base_path` and the sample at top of `main()`, then run.
- Steps: read SR/CR histograms, rebin/normalize consistently, form ABCD = CRa×CRc/CRb, ratio SR/ABCD with errors, plot and save PDF.


## TRExFitter/CLs preparation

### CreateTRExFitterInputs.py
Purpose: Build a TRExFitter-compatible ROOT file with corrected histogram uncertainties for QCD reweighting models and optional systematics; scp to a remote path.

CLI
- `python CreateTRExFitterInputs.py [--remote-path <afspath>] <local_path> <output_name> [--sys]`
  - `--remote-path` default: `/afs/cern.ch/work/d/dbaronmo/private/Fitter/`
  - `local_path` ends with a trailing slash and contains ROOT files (Data.root, Signal_*.root, QCD RW samples, standard backgrounds, and optionally SYS-tagged systematic files)
  - `output_name` must end with `.root` (remote filename)
  - `--sys` to include all histograms from files whose names contain `SYS`

Behavior
- Gathers available samples from `local_path` (drops missing), opens only `mass_jj`, and writes a new file named `<channel(local_path)>histograms.root`.
- For QCD RW samples, inflates bin errors using analytic RW uncertainty models (parameters and covariances in-FILE). Handles cutoff variants by propagating uncertainty past cutoff.
- For systematics files, copies all `mass_jj_*` histograms; rescales errors for RW samples as above.
- Uploads to remote via scp (`dbaronmo@lxplus.cern.ch:<remote_path>/<output_name>`).

Notes
- Channel is inferred from `local_path` (`MuMu`→Zmumu, `Zee`→Zee, `TauTau`/`MuEle`→Ztautau, `Zll`→Zll).
- Hardcoded list `histogramNames = ["mass_jj"]`.


### CreateCLsInputs.py
Purpose: Prototype builder for `CLsInputs.csv` from a target folder, with chosen scale factors and rebinning; accumulates background and reports bin-level uncertainties.

Usage
- Script has an example `__main__` with hardcoded paths and scale factors; edit paths, SFs, and `HistogramInfo` definition before running.
- Internals: `build_sample` (returns per-bin contents/errors with optional rebin and scaling), `build_background` sums samples in quadrature, writes a CSV with Background columns and one column per Z′ mass signal.


## Metadata generation utilities

### MetadataGen/dict_creator.py
Purpose: Discover MC sample folders under a path, look up xsec/k-factor/filter eff from `Xsec.csv`, and print dictionary lines for inclusion in metadata.

Usage
- Run `python MetadataGen/dict_creator.py`, answer whether these are systematic samples, then it iterates a predefined `dict_of_samples` map and prints lines like:
  - `'Ztautau_2017'  :  ['<dir>','<mcid>',<xsec>,<kfac>,<filt>] ,`
- To generate entries for other patterns, adjust `dict_of_samples` or call `create_dict(sample_name, sample_match_strings, systematic_samples=True/False)` interactively.

Notes
- Expects `Xsec.csv` present in `MetadataGen`.
- Header comment shows an older CLI; current main() is interactive over `dict_of_samples`.


### MetadataGen/lister_data.py
Purpose: List data ROOT files grouped by year and print helper lists.

CLI
- `python MetadataGen/lister_data.py <base_data_dir>`

Behavior
- Scans subdirs with `data18`, `data17`, `data15`/`data16` in the name and prints simple name→file mappings and composite lists.


### MetadataGen/lister_mc.py
Purpose: Large metadata store of MC sample mappings and storage locations; used to build dictionaries and cross-reference MC IDs, xsecs, and paths.

Usage
- Pure module; import to access dictionaries.


### MetadataGen/theory_variations.py
Purpose: Central dictionary mapping theory/systematic variation keys to weight branch names (includes 0–99 PDF weights).

Usage
- Pure module; import dictionary for downstream use.


## Configuration example

See `configExamplePlot.yml` for a complete Plot configuration. Key fields:
- `signal_sample`, `qcd_sample`, `is_post_fit`, `vbf_scale`, `qcd_scale`
- `histograms` (must match a key in `templatesDict`), `final_state`, `region`, `print_version`, `print_overflows`, `blind`, `blind_mass`, `unblind_purity_limit`
- `background` entries with name/file/color
- Optional `Zprime_pack` entries


## Tips and caveats

- Hardcoded paths: Several example drivers (CompareShapes, Ratio scripts, RawABCDQCDjj, CreateCLsInputs) include user-specific paths; adjust before running.
- Interactive prompts: Plot.py asks to confirm the SF dictionary; MJEstimate has multiple menus; PlotVariousEWjjQCDjj turns interactivity off.
- Naming conventions: This analysis expects ROOT files named by sample (e.g., `Signal_Sherpa.root`, `Ztautau_SherpaNLO_RWParabolicCutoff.root`). Systematics files include `SYS` in the filename.
- Rebinning and units: Always use the matching `HistogramInfo` template when comparing or combining histograms to ensure binning and normalization consistency.
- Dependencies: If you hit import errors for AnalysisCommons, re-run `source SetupPythonScripts.sh` from inside `Scripts`.


## Quick start

- Source environment helper inside `Scripts`.
- Copy and edit `configExamplePlot.yml` for your case, then run Plot.py with your channel and optional `--sfs-dict`.
- Use PlotVariousEWjjQCDjj.py to mass-generate plots across QCD/EW combinations.
- Use MJEstimate.py to create `MJ.root` for Tau/Mu final states.
- Build TRExFitter inputs with CreateTRExFitterInputs.py; use `--sys` to include systematic histograms.
