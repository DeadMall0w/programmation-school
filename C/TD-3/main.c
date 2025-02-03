#include <stdio.h>
#include <ctype.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE + 1];
char *dernier(char *);
char longueur(const char *);

int main()
{
    TChaine chaine = "Le premier mot";
    TChaine mot;
    
    printf("Le dernier mot est : '%s'\n", mot);


    printf("\n\n\n");

    TChaine c = "Bonjour le monde";
    char * t = &c[1];
    
    
    char v = 0;
    while (t[v] != '\0')
    {
        printf("%c", t[v]);
        v++;
    }

    return 0;
}

/*
Nom : dernier
Entrée : variable `mot` dans lequel va être placé le dernier mot, et variable `chaine` contenant la chaîne.
Sortie : pointeur sur le début du dernier mot dans la chaîne d'origine.
Principe : Parcourt la chaîne pour trouver le début et la fin du dernier mot, puis le copie dans `mot`.
*/
char *dernier(char *chaine)
{
    int i = longueur(chaine) - 1;


    // Trouver le début du dernier mot
    int fin = i; // Fin du dernier mot
    while (i >= 0 && !isspace(chaine[i])) {
        i--;
    }
    int debut = i + 1; // Début du dernier mot

    return &chaine[5];
}

/*
Nom : longueur
Entrée : chaîne de caractères
Sortie : longueur de la chaîne
Principe : Compte les caractères jusqu'à '\0'.
*/
char longueur(const char *ch)
{
    char i = 0;
    while (ch[i] != '\0')
        i++;
    return i;
}
