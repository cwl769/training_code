set -e

g++ -o e_force e_force.cpp
g++ -o e_data e_data.cpp
g++ -o e e.cpp -Wall -Wextra

for ((;;))
do
    ./e_data > e.in
    ./e_force < e.in > e.ans
    ./e < e.in > e.out
    diff -b e.out e.ans
done