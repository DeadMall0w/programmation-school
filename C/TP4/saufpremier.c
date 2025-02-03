//fonction premier (var mot : Tchaine ; ch : Tchaine) :Tchaine ;
#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * saufpremier(char *, const char * );

int main()
{
    TChaine chaine = "Pas le premier mot";
    TChaine restch;
    saufpremier(restch, chaine);
    printf("La chaine est : '%s'\n", restch);
    
    return 0;
}


char * saufpremier(char * restch, const char * chaine)
{
    char i=0;
    char j=0;
    char premiermot = 1;
    while(chaine[i] != '\0')
    {
        if(premiermot == 1 && chaine[i] == ' ')
        {
            premiermot = 0; // Le premier mot vient d'être depassé
            i++; // On passe l'espace
        }
        if (premiermot == 0)
        {
            restch[j] = chaine[i];
            j++;
        }
        i++;
    }

    return restch;
}