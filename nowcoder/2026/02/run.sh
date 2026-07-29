set -e

if [ "$2" == "-s" ];
then
    g++ -o $1 $1.cpp -std=c++20 -Wall -Wextra -fsanitize=address,undefined
else
    g++ -o $1 $1.cpp -std=c++20 -Wall -Wextra
fi

time ./$1 < $1.in
