#! /bin/bash


echo $V

# Fonctions utiles
enter2continue(){
    read -p "ENTREE pour continuer" t
    clear
}


ask2quit(){
    read -p "Quitter [Y/N]" inp
    if [ $inp = "Y" ]; then
        exit 0
    fi
    menu
}

echo2(){ # Envoie un message dans la sortie d'erreur
    echo "$@" >&2

}






# Fonction de menu
menu(){

    clear 
    echo "Menu made by Raphael !"
    cat << EOF
-[q] : Quitter
-[m] : menu
-[1] : enter2continue
-[2] : ask2quit
-[3] : echo2
-[4] : log
-[5] : warn
-[6] : err
-[7] : debug
EOF








    echo -n "Choix : "
    read INPUT

    case $INPUT in
    "q")
        echo "Au revoir !"
        exit 0
        ;;
    "m")
        menu
        ;;
    "1")
        enter2continue
        ;;
    "2")
        ask2quit
        ;;
    "3")
        echo "Message d'erreur : "
        read err
        echo2 $err
        ;;
    "1")
        enter2continue
        ;;
    "1")
        enter2continue
        ;;
    *)
        menu
        ;;
    esac
}


#menu


