#include "libannu.h"
#include <stdio.h>


short chercherpers(Ttabpers Ttebpers, Tchaine nom)
{
    strcpy(Ttebpers[0], nom);
    short i = MAXPERS+1;
    
    while (strcmp(Ttebpers[i], nom) != 0)
    {
        i--;
    }

    return i;
}


short insererpers(Ttabpers Rep, short * der, Tchaine nom)
{
    
    &der += 1;
}



void afficherrep(Ttabpers Rep, short der)
{
    for (short i = 1; i < der; i++)
    {
        printf("%d : %s", i, Rep[i]);
    }
    
}

short supprimerpers(Ttabpers Rep, short * der, int position)
{

}