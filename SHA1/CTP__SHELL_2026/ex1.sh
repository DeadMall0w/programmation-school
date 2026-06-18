#!/bin/bash


# Mettre ici getops
# if [nomalisation] : 
#  ./normalise.sh
# fi


#* A mettre dans le fichier normalise.sh
# On extrait tout ce qui se trouve entre la balise du tableau et sa fermeture
# sed -n '/<table class="coupe"/,/<\/table>/p/g' 1982.html > etape1.txt
I=1946
while [ $I -lt 2026 ]; do # tant que I < 2025 

    fichier="${I}.html" #on choppe le fichier correspondant 



    # Trouve où couper le fichier
    start=$(cat ${fichier} | grep -n '<table'  | cut -d: -f1 | head -1)
    end=$(cat ${fichier} | grep -n '</table>'  | cut -d: -f1 | head -1 )

    # Coupe le fichier
    sed -n "${start},${end}p" "$fichier" > etape1.txt

    # Supprime tout le HTML
    sed 's/<[^>]*>//g' etape1.txt > etape2.txt

    #* Améliore le HTML
    # Le tail -n +8 coupe les 8 première lignes du fichier
    sed -E 's/[[:space:]]+/ /g; s/^[[:space:]]+|[[:space:]]+$//g' etape2.txt | grep -v '^$' | tail -n +8 > etape3.txt

    # Mise en forme avec ::
    # xargs permet de faire les paquets et sed permet de mettre en forme avec '::'
    #cat etape3.txt | xargs -L 6 | sed 's/ /::/g' > etape4.txt
    mkdir -p out # S'assurer que le fichier existe bien
    cat etape3.txt | paste -d: - - - - - - > out/${I}
    
    I=$(($I+1))
done





