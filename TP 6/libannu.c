#include "libannu.h"
#include <stdio.h>


short chercherpers(Ttabpers Rep, short der, Tchaine nom)
{
    strcpy(Rep[0], nom);
    short i = der;
    
    while (strcmp(Rep[i], nom) != 0)
    {
        i--;
    }

    return i;
}


short insererpers(Ttabpers Rep, short * der, Tchaine nom)
{
    *der += 1;
    short i = 1;
    while (strcmp(Rep[i], nom) < 0 && Rep[i][0] != '\0') //TODO :AJOUTER verif de taille
    {
        i++;
    }


    printf("\n \nAjout de %s la position : %d \n", nom, i);
    
    short j = *der;
    while (j >= i)
    {
        strcpy(Rep[j], Rep[j-1]);
        j--;
    }
    
    strcpy(Rep[i], nom);
    return i;
}



void afficherrep(const Ttabpers Rep, short der)
{
    printf("\n\nAffichage de la liste des clients... \n");
    for (short i = 1; i <= der; i++)
    {
        printf("%d : %s\n", i, Rep[i]);
    }
    
}

short supprimerpers(Ttabpers Rep, short * der, int position)
{
    // la paramètre formel ‘position’ désigne la position dans l’annuaire du client à supprimer 
    int i; //compteur
    int pos; //mémoire

    if (position > *der || position <1) 
        return 0 ;
    else
    {
        pos = position ;
        for (i = position; i <= *der-1; i++)
        {
            strcpy(Rep[i],Rep[i+1]);
        }

        *der = *der -1 ;
        return  pos ;
    }
}