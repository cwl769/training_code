set -e

clang++ -o egen egen.cpp -O2 -Wall -Wextra
clang++ -o e e.cpp -O2 -Wall -Wextra
clang++ -o eforce eforce.cpp -O2 -Wall -Wextra

for ((;;))
do
    ./egen > e.in
    cat e.in
    ./e < e.in > e.out
    ./eforce < e.in > e.ans
    diff -b e.out e.ans
done