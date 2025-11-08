#! /bin/bash

factorial(){
    result=1
    list=$(seq 2 $NUM)
    for n in $list; do
        result=$((result * $n))
    done
    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM