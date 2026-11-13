#!/bin/sh
# Compile (if needed) and run the sieve entry. N comes on stdin.
gcc -O3 -march=native -o "$(dirname "$0")/primes" "$(dirname "$0")/primes.c"
exec "$(dirname "$0")/primes"
