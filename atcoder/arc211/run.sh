set -e

g++ -o $1 $1.cpp -Wall -Wextra

touch $1.in
code $1.in

time ./$1 < $1.in