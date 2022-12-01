# Week7

## Compilers

1. Overview of Compilers: gcc, clang, msvc, icc...
2. An absolute minimum for all C/C++ programmers: `-Wall -Werror -Wextra -Wpedantic -Wconversion`
    - Wall: all the warnings?
    - Werror: treat warnings as errors
    - Wextra: some extra warnings
    - Wpedantic: no language extension
    - Wconversion: no implicit conversion that loses information
3. Some extra warnings that I recommend: `-Wshadow -Wunused`
4. A useful place to inspect your code: Compiler Explorer
    - Benefits of using multiple compilers

## Debugger

1. vscode debugging
2. gdb and lldb
3. How to use gdb
    - How to start your program
    - How to abort and resume
    - How to set/delete a break point
    - How to view stack/register
    - How to disassemble a function

## System Call Debugger

1. strace in Linux
2. dtrace in Mac
    - I'm still trying to figure out how to use this one

## Static Analysis

1. clang-tidy
    - `clang-tidy filename`
    - .clang-tidy

## Profiling

### CPU Profiler

1. There are a bunch of tools for profiling
    - perf
    - callgrind
    - VTune
    - gperftools (our focus)
2. gperftools
    - What is it?
    - How to install?
    - How to use it?

### Memory Profiler

1. `sanitizer`
    - Address Sanitizer (detect memory issue: leaks, dangling pointers)
    - Undefined Behavior Sanitizer
    - Thread Sanitizer (useful for detecting data races)
2. `leaks` in MacOS
    - MallocStackLogging
3. `valgrind` in Linux

## Code Coverage

1. `gcov` + `lcov` + `genhtml`
2. `kcov`
    - a much easier-to-use code coverage report generator
    - but it's very slow compared with the tools listed above ([at least in MacOS](https://github.com/SimonKagstrom/kcov/issues/356))

## Benchmarking

1. Hyperfine
    - Compare different programs
2. Write your own benchmark
    - Compare different functions