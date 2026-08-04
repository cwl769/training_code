set -e

clang++ -o a a.cpp -O2
clang++ -o adata adata.cpp -O2
clang++ -o aforce A.cpp -O2

for ((;;))
do
    ./adata > a.in
    ./aforce < a.in > a.ans
    ./a < a.in > a.out
    diff -b a.ans a.out
done

