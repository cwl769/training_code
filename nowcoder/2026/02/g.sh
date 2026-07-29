set -e

g++ -o gdata gdata.cpp -O2
g++ -o gforce gforce.cpp -O2
g++ -o g g.cpp -O2

for ((;;))
    do
        ./gdata > g.in
        ./gforce < g.in > g.ans
        ./g < g.in > g.out
        diff -b g.ans g.out
    done
