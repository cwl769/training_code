set -e

clang++ -o f f.cpp -O2
clang++ -o fgen fgen.cpp -O2
clang++ -o fstd fstd.cpp -O2

for((;;))
do
    ./fgen > f.in
    ./fstd < f.in > f.ans
    ./f < f.in > f.out
    diff -b f.out f.ans
done