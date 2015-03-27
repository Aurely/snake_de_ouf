#!/bin/bash

let "nbr = 0"

./lemipc -1 &

while let "nbr < 1000"
do
    ./lemipc 1 &
    ./lemipc 2 &
#    ./lemipc 3 &
#    ./lemipc 4 &
    let "nbr = nbr + 1"
done
