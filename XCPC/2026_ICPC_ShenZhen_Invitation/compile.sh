#!/bin/bash
set -e

g++ -o g g.cpp
g++ -o g_checker g_checker.cpp

rm -rf ckr_in ckr_out

mkfifo ckr_in
mkfifo ckr_out