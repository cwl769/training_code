#!/bin/bash
set -e

clang++ -o e e.cpp
clang++ -o egen egen.cpp

for((;;))
do
    ./egen > e.in
    ./e < e.in
done