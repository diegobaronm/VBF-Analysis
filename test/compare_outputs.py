#!/usr/bin/env python3
"""
Compare analysis output ROOT files against reference files.

Checks:
  1. Both files exist and are valid ROOT files
  2. Same number of keys (histograms/trees)
  3. Same set of histogram/tree names
  4. For selected important histograms (e.g. Mjj, inv_mass, reco_mass):
     - Same number of bins
     - Bin contents match within tolerance
     - Integral matches within tolerance

Usage:
    python3 test/compare_outputs.py <output_file> <reference_file> [--tolerance 1e-6]
    python3 test/compare_outputs.py <output_dir> <reference_dir> [--tolerance 1e-6]

Exit codes:
    0 = All comparisons passed
    1 = One or more comparisons failed
"""
import os
import sys
import argparse
import glob

import ROOT
ROOT.gROOT.SetBatch(True)


# Histograms that are especially important to validate in detail
IMPORTANT_HISTOGRAMS = [
    "mass_jj",       # Mjj distribution (VBF key variable)
    "inv_mass",      # Invariant mass (Zee/MuMu)
    "reco_mass",     # Reconstructed mass (EleTau/TauMu/MuEle)
    "delta_y",       # Delta rapidity between jets
    "delta_phi",     # Delta phi
    "lep1_pt",       # Leading lepton pT (Zee/MuMu)
    "lep_pt",        # Lepton pT (EleTau/TauMu)
    "tau_pt",        # Tau pT
    "ljet0_pt",      # Leading jet pT
    "ljet1_pt",      # Sub-leading jet pT
    "pt_bal",        # pT balance
    "Z_centrality",  # Z centrality
    "bdt",           # BDT score
    "met",           # Missing transverse energy
]


def get_all_keys(tfile):
    """Return a sorted list of key names in a ROOT file."""
    return sorted([k.GetName() for k in tfile.GetListOfKeys()])


def is_histogram(obj):
    """Check if a ROOT object is a histogram (TH1 or TH2)."""
    return isinstance(obj, (ROOT.TH1, ROOT.TH2))


def is_tree(obj):
    """Check if a ROOT object is a TTree."""
    return isinstance(obj, ROOT.TTree)


def compare_histograms(h1, h2, name, tolerance=1e-6):
    """Compare two histograms bin-by-bin. Returns list of error messages."""
    errors = []

    # Check number of bins
    if h1.GetNbinsX() != h2.GetNbinsX():
        errors.append(f"  {name}: bin count mismatch: {h1.GetNbinsX()} vs {h2.GetNbinsX()}")
        return errors

    # Check integral
    int1 = h1.Integral()
    int2 = h2.Integral()
    if abs(int1) < 1e-15 and abs(int2) < 1e-15:
        pass  # Both empty, that's fine
    elif abs(int1) > 1e-15 and abs(int2 - int1) / max(abs(int1), 1e-15) > tolerance:
        errors.append(f"  {name}: integral mismatch: {int1:.8g} vs {int2:.8g}")

    # Check bin contents
    n_mismatched = 0
    for b in range(0, h1.GetNbinsX() + 2):  # Include under/overflow
        c1 = h1.GetBinContent(b)
        c2 = h2.GetBinContent(b)
        if abs(c1) < 1e-15 and abs(c2) < 1e-15:
            continue
        denom = max(abs(c1), abs(c2), 1e-15)
        if abs(c1 - c2) / denom > tolerance:
            n_mismatched += 1
            if n_mismatched <= 3:  # Show first few mismatches
                errors.append(f"  {name} bin {b}: {c1:.8g} vs {c2:.8g}")

    if n_mismatched > 3:
        errors.append(f"  {name}: {n_mismatched} total bin mismatches (showing first 3)")

    return errors


def compare_trees(t1, t2, name):
    """Compare two TTrees by entry count and branch names."""
    errors = []

    if t1.GetEntries() != t2.GetEntries():
        errors.append(f"  {name} (TTree): entry count mismatch: {t1.GetEntries()} vs {t2.GetEntries()}")

    branches1 = sorted([b.GetName() for b in t1.GetListOfBranches()])
    branches2 = sorted([b.GetName() for b in t2.GetListOfBranches()])

    if branches1 != branches2:
        only_in_1 = set(branches1) - set(branches2)
        only_in_2 = set(branches2) - set(branches1)
        if only_in_1:
            errors.append(f"  {name}: branches only in output: {only_in_1}")
        if only_in_2:
            errors.append(f"  {name}: branches only in reference: {only_in_2}")

    return errors


def is_important(name):
    """Check if a histogram name matches one of the important histograms."""
    for pattern in IMPORTANT_HISTOGRAMS:
        # Match if the base name starts with the pattern (before cut labels)
        base = name.split("_")[0] if "_" in name else name
        # More flexible: check if any important pattern is a prefix
        if name.startswith(pattern) or name == pattern:
            return True
    return False


def compare_files(output_path, reference_path, tolerance=1e-6):
    """Compare two ROOT files. Returns (n_checks, errors_list)."""
    errors = []
    n_checks = 0

    # Open files
    f_out = ROOT.TFile.Open(output_path, "READ")
    f_ref = ROOT.TFile.Open(reference_path, "READ")

    if not f_out or f_out.IsZombie():
        return 0, [f"Cannot open output file: {output_path}"]
    if not f_ref or f_ref.IsZombie():
        f_out.Close()
        return 0, [f"Cannot open reference file: {reference_path}"]

    # Compare key lists
    keys_out = get_all_keys(f_out)
    keys_ref = get_all_keys(f_ref)
    n_checks += 1

    if len(keys_out) != len(keys_ref):
        errors.append(f"Key count mismatch: output has {len(keys_out)}, reference has {len(keys_ref)}")

    only_in_out = set(keys_out) - set(keys_ref)
    only_in_ref = set(keys_ref) - set(keys_out)
    if only_in_out:
        errors.append(f"Keys only in output ({len(only_in_out)}): {list(only_in_out)[:10]}")
    if only_in_ref:
        errors.append(f"Keys only in reference ({len(only_in_ref)}): {list(only_in_ref)[:10]}")

    # Compare common objects — only important histograms and trees
    common_keys = set(keys_out) & set(keys_ref)
    for key_name in sorted(common_keys):
        obj_out = f_out.Get(key_name)
        obj_ref = f_ref.Get(key_name)

        if is_histogram(obj_out) and is_histogram(obj_ref):
            if not is_important(key_name):
                continue
            n_checks += 1
            print(f"    Comparing important histogram: {key_name} contents...")
            hist_errors = compare_histograms(obj_out, obj_ref, key_name, tolerance)
            errors.extend(hist_errors)
        elif is_tree(obj_out) and is_tree(obj_ref):
            n_checks += 1
            tree_errors = compare_trees(obj_out, obj_ref, key_name)
            errors.extend(tree_errors)

    # Specifically check important histograms exist
    for pattern in IMPORTANT_HISTOGRAMS:
        found = any(k.startswith(pattern) for k in keys_out)
        if not found:
            # Not an error for all channels (e.g. inv_mass only in Zee/MuMu)
            pass

    f_out.Close()
    f_ref.Close()

    return n_checks, errors


def compare_directories(output_dir, reference_dir, tolerance=1e-6):
    """Compare all ROOT files in two directories. Returns overall pass/fail."""
    total_checks = 0
    total_errors = []
    files_compared = 0

    # Find all ROOT files in the reference directory
    ref_files = glob.glob(os.path.join(reference_dir, "**", "*.root"), recursive=True)

    if not ref_files:
        print(f"WARNING: No reference files found in {reference_dir}")
        return True

    for ref_path in sorted(ref_files):
        # Compute corresponding output path
        rel_path = os.path.relpath(ref_path, reference_dir)
        out_path = os.path.join(output_dir, rel_path)

        if not os.path.exists(out_path):
            total_errors.append(f"Missing output file: {rel_path}")
            continue

        print(f"  Comparing: {rel_path}")
        n_checks, errors = compare_files(out_path, ref_path, tolerance)
        total_checks += n_checks
        total_errors.extend(errors)
        files_compared += 1

    # Summary
    print(f"\n  Files compared: {files_compared}")
    print(f"  Total checks:   {total_checks}")
    print(f"  Errors:         {len(total_errors)}")

    if total_errors:
        print("\n  FAILURES:")
        for err in total_errors:
            print(f"    {err}")
        return False

    return True


def main():
    parser = argparse.ArgumentParser(description="Compare VBF analysis output to references")
    parser.add_argument("output", help="Output ROOT file or directory")
    parser.add_argument("reference", help="Reference ROOT file or directory")
    parser.add_argument("--tolerance", type=float, default=1e-6,
                        help="Relative tolerance for bin comparison (default: 1e-6)")
    args = parser.parse_args()

    print(f"Comparing output vs reference (tolerance={args.tolerance})")
    print(f"  Output:    {args.output}")
    print(f"  Reference: {args.reference}")

    if os.path.isdir(args.output) and os.path.isdir(args.reference):
        passed = compare_directories(args.output, args.reference, args.tolerance)
    elif os.path.isfile(args.output) and os.path.isfile(args.reference):
        n_checks, errors = compare_files(args.output, args.reference, args.tolerance)
        print(f"  Checks: {n_checks}, Errors: {len(errors)}")
        if errors:
            print("\n  FAILURES:")
            for err in errors:
                print(f"    {err}")
        passed = len(errors) == 0
    else:
        print("ERROR: Both arguments must be either files or directories")
        sys.exit(1)

    if passed:
        print("\nPASSED: All comparisons match.")
        sys.exit(0)
    else:
        print("\nFAILED: Some comparisons did not match.")
        sys.exit(1)


if __name__ == "__main__":
    main()
