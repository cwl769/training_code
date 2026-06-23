set -e

clang++ -o $1 $1.cpp -Wall -Wextra -Wno-char-subscripts #-fsanitize=undefined,address

time ./$1 < $1.in
