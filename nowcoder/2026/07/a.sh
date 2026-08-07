set -e

clang++ -o adata adata.cpp -O2
clang++ -o aforce aforce.cpp -O2
clang++ -o a a.cpp -O2

for((;;))
do
    ./adata > a.in
    ./aforce < a.in > a.ans
    time ./a < a.in > a.out
    diff -b a.ans a.out
done