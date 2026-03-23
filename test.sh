#!/bin/bash
cd build

# If arguments are provided, pass them directly to the test executable (sequential)
# This allows for manual filtering (e.g. ./test.sh --gtest_filter=...)
if [ $# -gt 0 ]; then
    ./test/ProjectEulerTests "$@"
else
    # Run tests in parallel using ctest
    # -j$(nproc) uses all available CPU cores
    # --output-on-failure shows details only for failed tests
    ctest --output-on-failure -j$(nproc)
fi
