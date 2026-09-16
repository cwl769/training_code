set -e

clang++ -o a a.cpp
clang++ -o acheck acheck.cpp

for ((i = 1; i <= 600; i++))
do
    echo $i > a.in
    ./a < a.in > a.out
    ./acheck
    echo "$i accept"
done
