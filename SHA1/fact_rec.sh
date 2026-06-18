#! /bin/bash

# Factorielle de manière recursive

# Condition d'arret
if [ $1 -lt 1 ]; then
    echo 1
    exit 0
fi

rep=$(./fact_rec.sh $(($1-1)))
echo $((rep*$1))

