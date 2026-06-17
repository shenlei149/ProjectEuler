#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-Release}
JOBS=${JOBS:-$(nproc)}

CLEAN=0
RECONFIGURE=0
declare -a EXTRA_CMAKE_ARGS=()

usage() {
	cat <<'EOF'
Usage: ./build.sh [BuildType] [options] [-- <extra cmake args>]

Options:
  --clean        Remove build directory before building (full rebuild)
  --reconfigure  Re-run CMake configure from scratch (keep build artifacts)
  -h, --help     Show this help message

Examples:
  ./build.sh
  ./build.sh Debug
  ./build.sh Release --clean
  ./build.sh -- -DCMAKE_CXX_COMPILER=clang++
EOF
}

while (($# > 0)); do
	case "$1" in
		-h|--help)
			usage
			exit 0
			;;
		--clean)
			CLEAN=1
			shift
			;;
		--reconfigure)
			RECONFIGURE=1
			shift
			;;
		--)
			shift
			EXTRA_CMAKE_ARGS=("$@")
			break
			;;
		-* )
			echo "Unknown option: $1" >&2
			usage
			exit 1
			;;
		*)
			BUILD_TYPE="$1"
			shift
			;;
	esac
done

if [[ $CLEAN -eq 1 ]]; then
	rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"

if [[ $RECONFIGURE -eq 1 ]]; then
	rm -f "$BUILD_DIR/CMakeCache.txt"
	rm -rf "$BUILD_DIR/CMakeFiles"
fi

# Enable compiler cache automatically if available.
if command -v ccache >/dev/null 2>&1; then
	EXTRA_CMAKE_ARGS+=(
		-DCMAKE_C_COMPILER_LAUNCHER=ccache
		-DCMAKE_CXX_COMPILER_LAUNCHER=ccache
	)
fi

# Configure is incremental when reusing the same build directory.
cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" "${EXTRA_CMAKE_ARGS[@]}"

# Build reuses existing object files unless sources/options changed.
cmake --build "$BUILD_DIR" --parallel "$JOBS"
