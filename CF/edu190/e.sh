set -e

clang++ -o egen egen.cpp -Wall -Wextra -O2
clang++ E_Minimum_Influence.cpp -o E_Minimum_Influence -Wall -Wextra -O2

for ((;;))
do
    ./egen > e.in
    time ./E_Minimum_Influence < e.in > e.out
done