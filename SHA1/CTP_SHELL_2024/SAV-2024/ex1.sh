#! /bin/bash

# Repérage des lignes importantes :
if [ $# -ne 2 ]; then
    echo "Usage: incorrecte !"
    exit 1
fi

if [ -e $1 ]; then
    
    FILE=$1
    KEY=$2
    FOUND=0

    # On lit le fichier ligne par ligne
    while IFS= read -r line; do
        # 1. On cherche la clé (ex: "score")
        if echo "$line" | grep -q "\"$KEY\":"; then
            FOUND=1
            echo "$line"
            continue
        fi

        # 2. Si on a trouvé la clé, on affiche tout jusqu'à tomber sur } ou ]
        if [ $FOUND -eq 1 ]; then
            echo "$line"
            
            # On s'arrête si la ligne contient la fermeture du bloc
            if echo "$line" | grep -qE "[\}\]]"; then
                break
            fi
        fi
    done < "$FILE"
else
    cat $2 | grep $1 | awk '{ print substr($0, 1, length($0)-1) }'
fi

