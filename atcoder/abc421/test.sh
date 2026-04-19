set -e

g++ d_generator.cpp -o d_generator
g++ -o d d.cpp -O2 -Wall -Wextra -fsanitize=address -fsanitize=undefined

for ((i=1;i<=1000;i++));
do
    ./d_generator > d.in
    ./d < d.in
done