set -e

g++ -o d d.cpp
g++ -o d_data d_data.cpp
g++ -o d_check d_check.cpp

for ((;;)) 
do
    ./d_data > d.in
    ./d_check < d.in > d.ans
    ./d < d.in > d.out
    diff d.out d.ans -b
done