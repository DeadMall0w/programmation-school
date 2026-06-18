#! /bin/bash

if [[ $1 =~ ^[0-9]+$ ]]; then

    num="$(($1+1))"
    if [ $num -gt $# ]; then
        exit 1
    fi
    
    shift $1
    echo $1
    exit 0
else 
    exit 1 
fi