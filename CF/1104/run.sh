set -e

clang++ -o $1 $1.cpp -Wall -Wextra

./$1 < $1.in
