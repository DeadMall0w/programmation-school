#! /bin/bash

# Fonctionnement : 
# Renvoie le factoriel du nombre passé en paramètre, s'il y en a aucun on demande à l'utilisateur un nombre
# On doit vérifier que le nombre possède bien un factoriel (nombre négatif)

# Test existence de paramètre
if [ $# -lt 1 ]; then
    read -p "Enter a number : " n
else
    n=$1
fi

if [[ ! $n =~ ^[0-9]+$ ]]; then
    echo "ERREUR : '$1' Not a number !"
    exit 1
fi

num=1
for (( i=1; i<=$n; i++ ))
do  
    num=$((num*i))
done
echo $num