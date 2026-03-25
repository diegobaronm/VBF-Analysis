# VBF Analysis — CI Test Infrastructure

## Overview

The CI pipeline runs each analysis channel over a small set of real ROOT
files committed to this repository, then optionally compares the output
against reference files.

## Directory layout

```
test/
├── inputs/               # Sample lists fed to RunAnalysis.py
│   ├── EleTau_mc.txt
│   ├── EleTau_data.txt
│   └── ...
├── test_data/            # Real ROOT files (committed, possibly via Git LFS)
│   ├── tautau/           # Used by EleTau, TauMu, MuEle channels
│   │   ├── mc_test/      # Must contain 'mc' in directory name
│   │   │   ├── <ROOT file for Ztautau_2018_0>
│   │   │   └── <ROOT file for Ztautau_2018_1>
│   │   └── data_test/    # Must contain 'data' in directory name
│   │       └── <ROOT file for data_2018_0>
│   ├── zmumu/            # Used by MuMu channel
│   │   ├── mc_test/
│   │   │   ├── <ROOT file for Zmumu_2018_0>
│   │   │   └── <ROOT file for Zmumu_2018_1>
│   │   └── data_test/
│   │       └── <ROOT file for data_2018_0>
│   └── zee/              # Used by Zee channel
│       ├── mc_test/
│       │   ├── <ROOT file for Zee_2018_0>
│       │   └── <ROOT file for Zee_2018_1>
│       └── data_test/
│           └── <ROOT file for data_2018_0>
├── references/           # Reference outputs for comparison (committed)
│   └── <channel>/<region>/NOMINAL/*.root
├── output/               # Runtime output (git-ignored)
├── run_channel.sh        # Runs a single channel
├── compare_outputs.py    # Compares output vs reference ROOT files
└── generate_references.sh # One-time: runs all channels, saves references
```

## Placing test data

The ROOT filenames must match the metadata dictionaries in
`AnalysisCommons/Metadata/datasets*.py`.  For example, `Ztautau_2018_0`
maps to the filename `user.dbaronmo.25819135._000001.LepUniv_ttbar.root`.

The sub-directories under each dataset group (tautau, zmumu, zee) must
contain either `mc` or `data` in their name so that `get_samples_and_dirs()`
discovers them.  The names `mc_test` and `data_test` work.

The sample names listed in `test/inputs/<Channel>_{mc,data}.txt` must
correspond to keys in the respective `datasets*.py` dictionary, and the
matching ROOT files must be present in the correct `mc_test/` or `data_test/`
directory.

### Recommended: Git LFS

If the ROOT files are larger than a few MB, track them with Git LFS:

```bash
git lfs install
git lfs track "test/test_data/**/*.root"
git lfs track "test/references/**/*.root"
git add .gitattributes
```

## Generating references

After placing your test data, run:

```bash
bash test/generate_references.sh
```

This runs all five channels × two regions and copies the outputs into
`test/references/`.  Commit the results so CI can compare against them.

## Running a single channel locally

```bash
export VBF_TEST_DATA="$(pwd)/test/test_data"
bash test/run_channel.sh EleTau hn ZpeakOS
```

## CI workflow

The GitHub Actions workflow (`.github/workflows/ci.yml`) runs on every push
and PR to master/main.  It:

1. **run-channel** — Runs each channel × region combination in a ROOT
   container, producing histograms and ntuples.
2. **compare-references** — Downloads the outputs and compares them against
   committed reference files (if present).
