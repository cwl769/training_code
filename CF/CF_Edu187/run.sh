#!/bin/bash
set -e

g++ -o $1 $1.cpp
code $1.in
time ./$1 < $1.in