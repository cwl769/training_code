set -e

./ecompile.sh

for ((;;))
do
    ./egen > e.in
    ./ee > judger_out < judger_in
done