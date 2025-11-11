# HandleIO Scripts Guide

This guide explains what each script in `HandleIO/` does, how to run it, and the meaning of its options.

All scripts are Python 3. They assume you have ROOT and `hadd` available in your environment, and that the repository directory structure (channels, metadata) is in place.

## Prerequisites

- Python 3.x
- ROOT installed and configured (so `python -c "import ROOT"` works)
- `hadd` available on your PATH (part of ROOT)
- Repository metadata available: `AnalysisCommons/Metadata/*`

Run scripts from `HandleIO` unless otherwise noted.

---

## CreateListToRun.py

Create per-channel input lists (`Input*.txt`) by querying metadata and filtering nominal vs systematics.

- Interaction flow:
  1) Choose "Nominal" or "Systematics"
  2) Choose where you are running: "Local" or "Lxplus"
  3) Choose channel: TauMu, EleTau, MuEle, Zee, or MuMu

- Output:
  - Writes `Input.txt` in `../<Channel>/` for Local
  - Writes `Input_Condor.txt` in `../<Channel>/` for Lxplus

- Filtering rules:
  - Nominal: excludes samples containing `sys`
  - Systematics: includes samples containing `sys`

- Notes:
  - Uses `AnalysisCommons/Metadata/datasets*.py` to build the list
  - Run from `HandleIO/` (the script `chdir`s into `../<Channel>`)

Example:

```bash
python HandleIO/CreateListToRun.py
```

---

## OutputsMerger.py

Hadd per-channel ROOT files into standard merged outputs for a selected channel.

Usage:

```bash
python HandleIO/OutputsMerger.py \
  --inputs /path/to/input/files \
  --outputs /path/to/output/dir \
  --channel {MuMu,Zee,TauMu,EleTau,MuEle} \
  [--filter SUBSTR] \
  [--rw-samples SAMPLE1,SAMPLE2,... --rw-tags TAG1[,TAG2,...]]
```

Options:
- --inputs: Directory containing the input ROOT files to be merged. Must exist.
- --outputs: Directory to write merged outputs. Will be created if missing. You’ll be prompted whether to clean existing `.root` files.
- --channel: Which channel dictionary to use. One of `MuMu`, `Zee`, `TauMu`, `EleTau`, `MuEle`. Leave empty for full merging.
- --filter: Only process output names containing this substring (e.g. `Zmumu`, `Zee`, `Zprime_1000`).
- --rw-samples: Comma-separated substrings of output names that were reweighted (e.g. `Ztautau_Sherpa,Ztautau_MG`).
- --rw-tags: Comma-separated list of tags to append to output filenames. If a single tag is provided, it is applied to all samples. The script prefixes `RW` automatically (e.g. `RW+ParabolicCutoffClosure`).

Behavior:
- For reweighted outputs, target file becomes `<output>_RW<tag>.root` when the sample key matches.
- Adds Z′ samples automatically to EleTau and TauMu via patterns like `VBF_Zprime_<mass>*.root` for predefined mass lists.

Examples:
- Merge Zmumu channel:
  ```bash
  python HandleIO/OutputsMerger.py --inputs /data/out/Zmumu --outputs /data/merged/Zmumu --channel MuMu
  ```
- Merge only Zprime samples with a reweighting tag:
  ```bash
  python HandleIO/OutputsMerger.py --inputs /data/out/TauMu --outputs /data/merged/TauMu --channel TauMu \
    --rw-samples Ztautau_SherpaNLO,Ztautau_MGNLO --rw-tags ParabolicCutoffClosure
  ```

---

## CheckInputFiles.py

Validate that input ROOT files referenced by metadata exist and contain a given tree; optionally summarize entries for a filtered subset.

Usage:

```bash
python HandleIO/CheckInputFiles.py \
  --channel {ee,mm,tautau} \
  [--tree NOMINAL] \
  [--path /override/base/path/] \
  [--filter SUBSTR]
```

Options:
- --channel: One of `ee`, `mm`, or `tautau`.
- --tree: Tree name to check in each file. Default: `NOMINAL`.
- --path: Optional override for metadata base location. When set, the script scans subdirs under this path whose names contain `mc` or `data` and looks for the expected files there.
- --filter: Only process combos containing this substring; when set, the script also reports the total entry count across filtered files.

Outputs:
- Logs missing samples per combo and a final summary. Non-missing files are validated by opening the ROOT file and checking the tree exists.

---

## CheckOutputFiles.py

Check that your produced output ROOT files match a list of expected input filenames (from a txt list) and emit a list of missing ones.

Usage:

```bash
python HandleIO/CheckOutputFiles.py \
  --inputs /path/to/Input.txt \
  --outputs /path/to/outdir \
  [--tree NOMINAL]
```

Options:
- --inputs: Path to the text file listing expected filenames (one per line).
- --outputs: Directory containing produced `.root` files.
- --tree: The tree token embedded in output filenames; the script strips both `.root` and this token when comparing. Default: `NOMINAL`.

Behavior:
- Writes `Missing_files.txt` next to the `--inputs` file with any entries that are missing in `--outputs`.

---

## CheckSystematics.py

Quick sanity checks on systematic histograms in ROOT files by comparing to `mass_jj_NOMINAL` within a tolerance.

Usage:

```bash
python HandleIO/CheckSystematics.py /path/to/Systematics/ [--tolerance 10]
```

Options:
- input_path (positional): Directory containing systematic ROOT files; the script looks for files with `SYS` in the name.
- --tolerance: Allowed percentage difference for entries, mean, and standard deviation relative to NOMINAL. Default: 10.

Behavior:
- For each file, opens `mass_jj_NOMINAL` and compares every other histogram in the file. Warns when differences exceed the tolerance.

---

## AddSystematics.py

Combine two channels’ systematic ROOT files by summing relevant histograms and writing a combined file.

Usage:

```bash
python AddSystematics.py <channel1> <channel2> <output_path> \
  [--ch1-path /override/path1/] [--ch2-path /override/path2/]
```

Options:
- channel1, channel2: Distinct channels; allowed: `Ztm`, `Zte`, `Ztl`, `Zem`, `Zmm`, `Zee`.
- output_path: Directory where combined ROOT files are written.
- --ch1-path, --ch2-path: Override default input directories. Defaults:
  - Ztm → `../VBFAnalysisPlots/TauMu/Zpeak/Systematics/`
  - Zte → `../VBFAnalysisPlots/EleTau/Zpeak/Systematics/`
  - Ztl → `../VBFAnalysisPlots/TauTau/TauhadTaulep/Systematics/`
  - Zem → `../VBFAnalysisPlots/MuEle/Zpeak/Systematics/`
  - Zmm → `../VBFAnalysisPlots/MuMu/Zpeak/Systematics/`
  - Zee → `../VBFAnalysisPlots/Zee/Zpeak/Systematics/`

Behavior:
- Expects exactly one VBF systematic file (filename containing `VBF`) and one QCD file (filename containing `SherpaNLO`) for each channel.
- For each pair, writes `<file1_basename>_plus_<file2_basename>.root` under `output_path` with:
  - `mass_jj_NOMINAL` = NOMINAL1 + NOMINAL2
  - For each systematic in `AnalysisCommons.Systematics.LIST_OF_SYSTEMATICS`, adds `mass_jj_<sys>` from both files (falls back to NOMINAL if the sys hist is missing - this happens for systematics only affecting one channel).
- Prompts for confirmation before running.

---

## AddMjjRWFiles.py

Collect and hadd pre-produced Mjj reweighted samples from known directories into a clean output structure.

Usage:

```bash
python HandleIO/AddMjjRWFiles.py <output_root>
```

Options:
- output_root (positional): Base directory to write results. The script will create subdirectories like `<output_root>/<channel>/<region>/`.

Behavior:
- Hardcoded input locations under `BASE_PATH = /data/dbaronmo/Chicago_VBF_Outputs/` across channels `Zee` and `Zmm` and regions `CRa`, `CRb`, `CRc`, `SR` with closure and non-closure variants.
- For each source directory and each sample family (Sherpa, MGNLO, MG, SherpaNLO), builds output filenames like `<Channel>_<Family>_<RWSuffix>.root`.
- Checks that a representative file exists in the source directory before running `hadd`.

Note:
- You may need to update `BASE_PATH` and the `DICT_PATH_SUFFIX` mappings in the script for your environment.

---

## AddChannels.py

Interactive merging of across-channel samples to produce combined categories using `hadd`.

How it works:
- On start, shows a menu:
  1) Merge TauMu + EleTau → writes to `TauTau/TauhadTaulep/<dir_name>/`
  2) Merge TauLep (TauTau/TauhadTaulep) + MuEle → writes to `TauTau/<dir_name>/`
  3) Merge Zee + MuMu → writes to `Zll/<dir_name>/`
- You’ll be prompted for `dir_name` (must be `A` or `A/B`; no leading/trailing slashes). Directories are created if missing.
- For (1) and (2) the script copies input ROOT files from channel folders into the working structure, then hadds paired samples.
- For (3) you can choose whether files are already in-place; otherwise it will copy them to the expected locations and then hadd.

Important notes:
- The script changes to a hardcoded working directory: `VBFAnalysisPlots/`. This directory is needed and is where your plots go.
- Uses `DEFAULT_MJJ_REWEIGHTING` and adds alternative RW variants for some Zll cases (e.g., `RWExponentialClosure`, `RWParabolicCutoff`).

Run:

```bash
python HandleIO/AddChannels.py
```

You’ll be guided interactively; no CLI flags are needed.

---

## Tips and troubleshooting

- If you see ROOT-related import errors, ensure you’ve initialized your ROOT environment (e.g., source your setup script in `Scripts/`).
- `hadd` errors typically indicate missing input files or mismatched glob patterns. Try listing files in the `--inputs` directory and comparing with the expected patterns in the script.
- For `AddMjjRWFiles.py`, verify that the `BASE_PATH` paths exist and contain files matching the expected patterns.
- For `AddSystematics.py`, ensure each channel folder has exactly one VBF and one SherpaNLO systematic ROOT file.

