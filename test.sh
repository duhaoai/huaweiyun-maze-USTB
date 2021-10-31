#! usr/bash
num=1000

: > ans.txt

step=0.1
for a in `seq $num`
do
    (./maze 1)>> ans.txt
    echo "the ${a} th loop"
    sleep $step

done
echo "load at ans.txt"