#! /bin/bash




#! 1 :  séparation en plusieurs fichiers

# Repérage des différents noms des compéts
sed 's/>/>\n/g' classement_permanent.html | sed 's/<[^>]*>//g' | sed '/^\s*$/d' | grep -A 2 "Classement" | cut -d ':' -f 2 > nom_tournois


# On remplit le tableau 'tab' directement depuis la commande
mapfile -t tab < <(grep -E "Homme|Femme" nom_tournois)



# Recherche des plages à découper
lines=$(sed 's/>/>\n/g' $1 | sed 's/<[^>]*>//g' | sed '/^\s*$/d' | grep -n "Classement" | cut -d ':' -f 1)

tab_line=($lines)

echo "${tab_line[0]}"


# Creation des fichiers
n=0
v=0
for file in "${tab[@]}"; do
    v=$((n+1)) 
    # echo "${tab_line[n]} - ${tab_line[v]} VIDE POUR L INSTANT" > "$file"
    sed 's/>/>\n/g' classement_permanent.html | sed 's/<[^>]*>//g' | sed '/^\s*$/d' | sed -n "${tab_line[n]},${tab_line[v]}p" | tail -n +11 > "$file"
    n=$v
    echo "n:$n"
    
    file_parsed="${file}.passwd"


    awk '{
    # On accumule la ligne courante dans une variable
    # Si c est la premiere ligne du bloc, on l initialise
    if (line == "") { line = $0 } 
    else { line = line ":" $0 }

    # Toutes les 7 lignes (puisqu un bloc fait 7 lignes : rang, nom, club, 4 scores)
    if (NR % 7 == 0) {
        print line;
        line = ""; # On réinitialise pour le bloc suivant
    }
}' "$file" > "$file_parsed"
done






# repérage des différentes lignes
#sed 's/>/>\n/g' classement_permanent.html | sed 's/<[^>]*>//g' | sed '/^\s*$/d' | grep -n "Classement" | cut -d ':' -f 1

# sed 's/>/>\n/g' $1 | sed 's/<[^>]*>//g' | sed '/^\s*$/d' > tmp


# 1. On nettoie le HTML pour avoir un élément par ligne
# 2. On lit ce flux ligne par ligne
# 3. On stocke dans un tableau 't'
# 4. Si la condition est remplie, on affiche au format passwd et on vide le tableau



# exit

# t=()

# # Le pipeline de nettoyage vu précédemment
# sed 's/>/>\n/g' $1 | sed 's/<[^>]*>//g' | sed '/^[[:space:]]*$/d' | while read -r line
# do
#     # Nettoyage des espaces superflus autour de la donnée
#     clean_line=$(echo "$line" | xargs)
    
#     # Ajout à notre tableau temporaire
#     t+=("$clean_line")

#     # CONDITION : Ici, on décide quand "valider" l'entrée.
#     # Exemple 1 : Si on a collecté 3 éléments (Nom, UID, Shell)
#     if [ ${#t[@]} -eq 6 ]; then
        
#         # Format : user:password:UID:GID:comment:home:shell
#         # On accède aux éléments avec ${t[index]} (index commence à 0)
#         echo "${t[0]}:${t[1]}:${t[2]}:${t[3]}:${t[4]}:${t[5]}" >> resultats.txt
        
#         # ON VIDE LE TABLEAU pour l'utilisateur suivant
#         t=()
#     fi
# done