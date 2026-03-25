#!/usr/bin/env bash
# -----------------------------------------------------------------------
#   generate_references.sh — Run all channels and save outputs as
#   reference files for future CI comparisons.
#
#   This should be run ONCE when setting up the CI, or whenever the
#   analysis code changes intentionally. The resulting reference files
#   are committed to the repository.
#
#   Prerequisites:
#     - Real ROOT files already placed in test/test_data/ (see test/README.md)
#
#   Usage:
#     bash test/generate_references.sh
# -----------------------------------------------------------------------
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

export VBF_TEST_DATA="$PROJECT_ROOT/test/test_data"

# Verify test data exists
if [ ! -d "$VBF_TEST_DATA" ] || [ -z "$(find "$VBF_TEST_DATA" -name '*.root' 2>/dev/null)" ]; then
    echo "ERROR: No ROOT files found under $VBF_TEST_DATA"
    echo "Place your simulation ROOT files there first (see test/README.md)."
    exit 1
fi

CHANNELS=("EleTau" "TauMu" "MuEle" "MuMu" "Zee")
REGIONS=("ZpeakOS" "HighMassOS")

# Run analysis for each channel and region
for CHANNEL in "${CHANNELS[@]}"; do
    for REGION in "${REGIONS[@]}"; do
        echo ""
        echo "=== Running $CHANNEL / $REGION ==="
        bash "$SCRIPT_DIR/run_channel.sh" "$CHANNEL" "hn" "$REGION" || {
            echo "WARNING: $CHANNEL / $REGION failed, skipping..."
            continue
        }
    done
done

# Copy outputs to references directory
echo ""
echo "=== Saving reference files ==="
REF_DIR="$SCRIPT_DIR/references"
rm -rf "$REF_DIR"

for CHANNEL in "${CHANNELS[@]}"; do
    for REGION in "${REGIONS[@]}"; do
        OUT_DIR="$SCRIPT_DIR/output/${CHANNEL}/${REGION}/NOMINAL"
        if [ -d "$OUT_DIR" ]; then
            DEST="$REF_DIR/${CHANNEL}/${REGION}/NOMINAL"
            mkdir -p "$DEST"
            cp "$OUT_DIR"/*.root "$DEST/" 2>/dev/null || true
            echo "  Saved: $CHANNEL/$REGION ($(ls "$DEST"/*.root 2>/dev/null | wc -l) files)"
        else
            echo "  Skipped: $CHANNEL/$REGION (no output)"
        fi
    done
done

echo ""
echo "=== Reference generation complete ==="
echo "Reference files are in: $REF_DIR"
echo "Commit these to the repository for CI comparisons."
