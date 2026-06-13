set -e

clang++ -o $1 $1.cpp -Wall -Wextra #-fsanitize=undefined,address

time ./$1 < $1.in
