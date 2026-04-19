set -e

g++ -o g g.cpp
g++ -o gs gs.cpp
g++ -o g_data g_data.cpp

for ((;;))
do
    ./g_data > g.in
    ./g < g.in > g.out
    ./gs < g.in > gs.out
    diff -b g.out gs.out
done