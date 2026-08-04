set -e

clang++ -o bdata bdata.cpp -O2 -fsanitize=undefined
clang++ -o b b.cpp -O2 -fsanitize=undefined
clang++ -o B B.cpp -O2 -fsanitize=undefined

for((;;))
do
    ./bdata > b.in
    ./B < b.in > b.ans
    ./b < b.in > b.out
    diff -b b.ans b.out
done