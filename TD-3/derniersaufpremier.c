//fonction premier (var mot : Tchaine ; ch : Tchaine) :Tchaine ;
#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * saufpremier(char *, const char * );

int main()
{
    printf("Hello, world !");
    
    TChaine chaine = "Pas le premier mot bonjour";
    TChaine mot = "";
    TChaine tmp = "";

    
    while (1)
    {

        saufpremier(mot, chaine);
        
        if (mot[0] == '\0')
        {
            break;
        }

        saufpremier(chaine, mot);

        if (chaine[0] == '\0')
        {
            break;
        }
    }

   /*
   printf("La chaine est : '%s'\n", chaine);
        printf("Le mot est : '%s'\n", mot);

        saufpremier(mot, chaine);
        

        printf("La chaine est : '%s'\n", chaine);
        printf("Le mot est : '%s'\n", mot);

        saufpremier(chaine, mot);
        

        printf("La chaine est : '%s'\n", chaine);
        printf("Le mot est : '%s'\n", mot);

        saufpremier(mot, chaine);
        

        printf("La chaine est : '%s'\n", chaine);
        printf("Le mot est : '%s'\n", mot);

        saufpremier(chaine, mot);*/
        
        
    
    
    printf("La chaine est : '%s'\n", mot);
    printf("La chaine est : '%s'\n", chaine);


    
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

    restch[j] = '\0';

    return restch;
}