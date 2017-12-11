#!/bin/bash

[ $# -lt 2 ] && { echo "Insufficient Number of Parameters"; exit 1; }
args=("$@")
count=1
while [ $count -lt $# ]
do
    cp -r ${args[0]} ${args[count]}
    let count++
done
