//fonction premier (var mot : Tchaine ; ch : Tchaine) :Tchaine ;
#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * premier(char *, const char * );

int main()
{
    TChaine chaine = "Le premier mot";
    TChaine mot;
    premier(mot, chaine);
    printf("Le premier mot est : '%s'\n", mot);
    return 0;
}

/*
Nom : premier
Entrée : variable dans lequel va être placé le premier mot, variable contenant la chaine
Sortie : premier mot de la chaine
Principe : Ajoute dans mot tant qu'on est pas à la fin de la chaine et à la fin du premier mot 
*/
char * premier(char * mot, const char * chaine)
{
    char i=0;
    while(chaine[i] != ' ' && chaine[i] != '\0')
    {
        mot[i] = chaine[i];
        i++;
    }

    return mot;
}