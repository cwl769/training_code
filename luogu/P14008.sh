set -e

g++ -o data data.cpp
g++ -o force force.cpp
g++ -o P14008 P14008.cpp

for((;;))
do
    ./data > P14008.in
    ./force < P14008.in > P14008.ans
    ./P14008 < P14008.in > P14008.out
    diff -b P14008.ans P14008.out
done