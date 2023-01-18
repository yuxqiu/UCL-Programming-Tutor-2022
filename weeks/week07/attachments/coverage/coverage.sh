#!/usr/bin/env bash

cc --coverage to_test_coverage.c -o to_test_coverage

./to_test_coverage

gcov to_test_coverage.c
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory out