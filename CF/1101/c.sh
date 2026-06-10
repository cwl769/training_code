set -e

clang++ -O2 -o cans C_1_Seating_Arrangement_Easy_Version.cpp
clang++ -O2 -o c C_2_Seating_Arrangement_Hard_Version.cpp
clang++ -O2 -o cgen cgen.cpp

ulimit -t 120

for((;;))
do
    ./cgen > c.in
    # ./cans < c.in > c.ans
    time ./c < c.in > c.out
    # diff c.ans c.out -b
done