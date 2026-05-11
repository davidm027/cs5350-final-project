set -e

mkdir -p build/

cmake -S . -B build/ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH="$CONDA_PREFIX" 
cmake --build build/ --parallel
