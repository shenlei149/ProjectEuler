#!/bin/bash
BUILD_TYPE=${1:-Release}
rm -rf build
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..
cmake --build . -j$(nproc)
