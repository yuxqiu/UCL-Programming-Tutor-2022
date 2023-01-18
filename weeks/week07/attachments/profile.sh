#!/usr/bin/env bash

# This only works in MacOS with brew + gperftools + pprof
cc to-bench.c -o to-bench -L$(brew --prefix gperftools)/lib -lprofiler
CPUPROFILE=out.prof ./to-bench
~/go/bin/pprof --png ./benchmark out.prof