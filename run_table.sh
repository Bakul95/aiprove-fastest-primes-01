#!/bin/sh
# Compile (if needed) and run the precomputed-table entry. Needs sieve.bin next to the binary.
gcc -O3 -march=native -o "$(dirname "$0")/primes_table" "$(dirname "$0")/primes_table.c"
exec "$(dirname "$0")/primes_table" "$0"
