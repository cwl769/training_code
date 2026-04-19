#!/bin/bash
set -e

g++ a_force.cpp -o a_force
g++ a_data.cpp -o a_data
g++ a.cpp -o a

for ((;;))
do
    ./a_data > a.in
    ./a_force < a.in > a.ans
    ./a < a.in > a.out
    diff a.ans a.out -b
done