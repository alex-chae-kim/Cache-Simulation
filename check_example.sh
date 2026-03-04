#!/usr/bin/env bash
set -euo pipefail

INFILE="example/example.in"
EXPECTED="example/example.out"
OUTDIR="output"
OUTFILE="$OUTDIR/out"
TMP="$OUTDIR/.tmp_out"

mkdir -p "$OUTDIR"

./cacheSim < "$INFILE" > "$TMP"

if diff -u "$EXPECTED" "$TMP" > "$OUTFILE"; then
  echo "MATCH: cacheSim output matches example/example.out" > "$OUTFILE"
else
  :
fi
rm -f output/.tmp_out