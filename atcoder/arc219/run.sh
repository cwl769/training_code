set -e

clang++ -o $1 $1.cpp -Wall -Wextra -std=c++23 #-fsanitize=undefined,address

./$1 < $1.in