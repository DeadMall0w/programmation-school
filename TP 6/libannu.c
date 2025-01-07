#include "libannu.h"
#include <stdio.h>


/**************************************************************************************************/
/*Fonction : chercherpers                                                                            */
/* Description : Renvoie la position d'une personne dans la base de donnée                */
/* Entrees : Rep : TChaine * -> le repertoire, der :  Telt -> position du dernier element, nom : Tchaine -> nom à chercher    */																					  
/* Sortie : indice de la position de la personne ou 0 si pas trouvé                                      */
/**************************************************************************************************/
Telt chercherpers(Tchaine Rep[], Telt der, Tchaine nom)
{
    strcpy(Rep[0], nom);
    Telt i = der;
    
    while (strcmp(Rep[i], nom) != 0)
    {
        i--;
    }

    return i;
}


/**************************************************************************************************/
/*Fonction : insererpers                                                                            */
/* Description : Ajoute une personne dans la base de donnée                */
/* Entrees : Rep : TChaine * -> le repertoire, der :  Telt -> position du dernier element, nom : Tchaine -> nom à ajouter    */																					  
/* Sortie : indice de la position ou la personne à été rajouté                              */
/**************************************************************************************************/
Telt insererpers(Tchaine Rep[], Telt * der, char nom[])
{
    *der += 1;
    if(*der >= MAXPERS){ *der = MAXPERS; return 0; }
    Telt i = 1;
    while (strcmp(Rep[i], nom) < 0 && Rep[i][0] != '\0') //TODO :AJOUTER verif de taille
    {
        i++;
    }


    printf("\n \nAjout de %s la position : %d \n", nom, i);
    
    Telt j = *der;
    while (j >= i)
    {
        strcpy(Rep[j], Rep[j-1]);
        j--;
    }
    
    strcpy(Rep[i], nom);
    return i;
}


/**************************************************************************************************/
/*Fonction : afficherrep                                                                            */
/* Description : Affiche toutes les personnes de la base de donnée                */
/* Entrees : Rep : TChaine * -> le repertoire, der :  Telt -> position du dernier element  */																					  
/* Sortie :                               */
/**************************************************************************************************/
void afficherrep(const Tchaine Rep[], Telt der)
{
    printf("\n\nAffichage de la liste des clients... \n");
    for (Telt i = 1; i <= der; i++)
    {
        printf("%d : %s\n", i, Rep[i]);
    }
    
}

/**************************************************************************************************/
/*Fonction : supprimerpers                                                                            */
/* Description : Supprimer une personne dans la base de donnée                */
/* Entrees : Rep : TChaine * -> le repertoire, der :  Telt -> position du dernier element, position : int -> position de l'element a supprimer  */																					  
/* Sortie : La position de l'element supprimer, 0 si ce n'est pas possible                              */
/**************************************************************************************************/
Telt supprimerpers(Tchaine Rep[], Telt * der, int position)
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