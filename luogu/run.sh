set -e

if [ "$2" == "-s" ];
then
    clang++ -o $1 $1.cpp -std=c++20 -Wall -Wextra -Wno-shift-op-parentheses -fsanitize=address,undefined
else
    clang++ -o $1 $1.cpp -std=c++20 -Wall -Wextra -Wno-shift-op-parentheses
fi

time ./$1 < $1.in
