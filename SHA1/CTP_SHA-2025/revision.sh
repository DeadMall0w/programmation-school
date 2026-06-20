#! /bin/bash 
source revision.lib


while getopts ":r:t:e:j:" opt; do
	case $opt in
	
	r) 
        echo "r"
        FIC=$OPTARG
		# FIC doit etre un fichier ordinaire (pas un rep, un périphérique, ...)  et etre non vide
		if [ ! -d $FIC -o ! -s $FIC ]; then 
			echo "Le dossier n'existe pas ou il est vide" 1>&2
			exit 2
		fi  
		;;
	t) 
        echo "t"
		RESULTAT=$OPTARG
		;;
	e) 
        echo "e"
		EQUIPE="$OPTARG"
		;;
	j) 
        echo "j"
		JOUEUR="$OPTARG"
		if [ ! -s $JOUEUR ]; then 
			echo "Le fichier n'existe pas ou il est vide" 1>&2
			exit 2
		fi  
		;;
		
		
	\?)
	echo "L'option -$OPTARG est invalide" >&2
	exit 1
	;;

	# cas où la chaine commence par ":" : les erreurs sont signalées par : au lieu de ? 
	# :)
	# echo "L'option -$OPTARG attend un argument" >&2
	# exit 1
	# ;;

	esac
done

if [ ! -d "$RESULTAT" -o -z "$RESULTAT" ]; then 
			echo "Le dossier n'existe pas ou n'est pas fournit creation de resultats" 1>&2
			RESULTAT=$(pwd)/"RESULTAT"
            mkdir $RESULTAT
fi  

if [ -z "$EQUIPE" ]; then
    echo "argument manquant EQUIPE" >&2
    exit 2
fi






for FICHIER in $(ls $FIC/*.html); do
    normaliser $FICHIER $RESULTAT
done

normaliser2.0 $JOUEUR $RESULTAT

extraction "$RESULTAT/rondes" $EQUIPE $RESULTAT

Recherche $FIC $RESULTAT $JOUEUR

#for FICHIER in $(ls $RESULTAT); do
 #   Nom=$(basename $FICHIER)
  #  cat $FICHIER | grep -q "$CLUB"
#done











