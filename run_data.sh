#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 <filename-in-data>"
  echo "Example: $0 test1"
  exit 1
fi

INPUT="data/$1"
OUTDIR="output"
OUTFILE="$OUTDIR/out"

if [[ ! -f "$INPUT" ]]; then
  echo "Error: input file not found: $INPUT" >&2
  exit 1
fi

mkdir -p "$OUTDIR"

./cacheSim < "$INPUT" > "$OUTFILE"