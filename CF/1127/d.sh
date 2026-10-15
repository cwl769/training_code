set -e

clang++ -o d d.cpp
clang++ -o dsim dsim.cpp

./d < d.in > dsim.in
./dsim < dsim.in