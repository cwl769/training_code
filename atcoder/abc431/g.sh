#!/bin/bash
set -e

g++ -o g_data g_data.cpp -O2
g++ -o g g.cpp -O2

for ((;;))
do
    ./g_data > g.in
    ./g < g.in > g.out
done