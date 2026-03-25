#!/usr/bin/env bash
# -----------------------------------------------------------------------
#   run_channel.sh — Run the VBF analysis for a single channel in CI mode.
#
#   Usage:
#     bash test/run_channel.sh <channel> <mode> <region>
#
#   Example:
#     bash test/run_channel.sh EleTau hn ZpeakOS
#
#   Requires:
#     - VBF_TEST_DATA environment variable pointing to test data directory
#     - ROOT installed and available
# -----------------------------------------------------------------------
set -euo pipefail

CHANNEL="${1:?Usage: run_channel.sh <channel> <mode> <region>}"
MODE="${2:-hn}"
REGION="${3:-ZpeakOS}"

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

# Set test data path if not already set
export VBF_TEST_DATA="${VBF_TEST_DATA:-$PROJECT_ROOT/test/test_data}"

# Output goes under test/output/<channel>/<region>/
OUTPUT_DIR="$PROJECT_ROOT/test/output/${CHANNEL}/${REGION}"
mkdir -p "$OUTPUT_DIR"

# Determine the MC input list
INPUT_MC="$SCRIPT_DIR/inputs/${CHANNEL}_mc.txt"
INPUT_DATA="$SCRIPT_DIR/inputs/${CHANNEL}_data.txt"

echo "=== Running $CHANNEL channel ==="
echo "  Mode:       $MODE"
echo "  Region:     $REGION"
echo "  Test data:  $VBF_TEST_DATA"
echo "  Output:     $OUTPUT_DIR"

cd "$PROJECT_ROOT"

# Run MC samples
echo "  Running MC samples..."
python3 RunAnalysis.py "$CHANNEL" "$INPUT_MC" no NOMINAL "$REGION" \
    --mode "$MODE" --output "$OUTPUT_DIR" --loglevel 3

# Run data samples
echo "  Running data samples..."
python3 RunAnalysis.py "$CHANNEL" "$INPUT_DATA" no NOMINAL "$REGION" \
    --mode "$MODE" --output "$OUTPUT_DIR" --loglevel 3

echo "=== $CHANNEL channel completed ==="
echo "  Output files:"
ls -la "$OUTPUT_DIR/NOMINAL/" 2>/dev/null || echo "  (no output files found)"
