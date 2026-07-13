set -e

if [ "$2" == "-s" ];
then
    echo "Compile with sanitizer"
    clang++ -o $1 $1.cpp -Wall -Wextra -fsanitize=address,undefined
else
    clang++ -o $1 $1.cpp -Wall -Wextra
fi

time ./$1 < $1.in
