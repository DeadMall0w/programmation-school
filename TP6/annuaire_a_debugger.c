/************************************************************************B2**/
/*Fichier: annuaire.c							   	*/
/*NOM :						 						*/
/* Version : 1.0									*/
/*Date : 06/01/2025							   		*/
/***************************************************************************/
#include <stdio.h>
#include "libannu.h"

/***************************************************************************/
/* NOM FONCTION : menu						           */
/* DESCRIPTION :  Affiche le menu et saisi le choix de l'utilisateur       */
/* Retourne : le choix de l'utilisateur          			   */
/* Effets de bords : Saisie au clavier                                     */
/* Parametres en entree : 						   */
/* Parametres en sortie :                                                  */
/***************************************************************************/
int menu();

int main()
{
Ttabpers Repert; // Repertoire de personne
Telt dernier = 0; //Position du dernier entre. Mais le 0 c'est pour la sentinnelle
Telt trouv; // drapeau utilise pour savoir si l'insertion a ete faite
Tchaine nom; //Variable pour saisir le nom de la personne
Telt monchoix; // Variable pour saisir les reponses de l'utilisateur pour traiter les options du menu 


do
{


 //Affichage du menu 
 monchoix=menu();

 //Traitement de la reponse de la l'utilisateur
switch (monchoix)
{
    case 1 : printf("\n Saisir un nom :");
             scanf("%s",nom);
             getchar();
             printf("\n Nom saisi : '%s'",nom);
             if (!chercherpers(Repert,dernier, nom)) 
                trouv = insererpers(Repert,&dernier,nom);
            if (trouv == 0)
                printf("\n Le repertoire est plein !!!\n");
            break;
    case 2 : printf("\n Saisir un nom :");
             scanf("%s",nom);
             getchar();
             printf("\n La position est %d !!! ", chercherpers(Repert,dernier, nom));
             break;
    case 3 : printf("\n Saisir un nom :");
            scanf("%s",nom);
             getchar();
            trouv = chercherpers(Repert,dernier, nom);
            if (trouv != 0) 
            {
                supprimerpers(Repert, &dernier, trouv);
                printf("\n %s à été supprimé de l'annuaire \n", nom);
            }
            else
                printf("\n La personne n'a pas été trouvé !\n");
            break;
    case 4 : afficherrep(Repert,dernier);
                break;
    case 5 : printf("\n FIN !!!\n\n");
             break;
    default : printf("\n Cas imprevu !!!\n\n");
}

} while (monchoix!=5); //On arrete quand l'utilisateur choisi l'option 4

return 1;    
}

/***************************************************************************/
/* NOM FONCTION : menu						           */
/* DESCRIPTION :  Affiche le menu et saisi le choix de l'utilisateur       */
/* Retourne : le choix de l'utilisateur          			   */
/* Effets de bords : Saisie au clavier                                     */
/* Parametres en entree : 						   */
/* Parametres en sortie :                                                  */
/***************************************************************************/
int menu()
{
int choix;  //Permet de saisir la reponse de l'utilisateur

 printf("\n 1-  Entrer un nom de client");
 printf("\n 2-  Rechercher la position d'un client");
 printf("\n 3-  Supprimer un client de l'annuaire");
 printf("\n 4-  Afficher l'annuaire");
 printf("\n 5-  Quitter");
 printf("\n  Votre choix :"); 
 scanf("%d",&choix);
 getchar();
return choix;

}
 

