#!/bin/bash

set -e 

code $1.in
g++ -o $1 $1.cpp -Wall -Wextra
