/************************************************************************B2**/
/*Fichier: annuaire.c							   	*/
/*NOM :						 						*/
/* Version : 1.0									*/
/*Date : 06/01/2025							   		*/
/***************************************************************************/
#include <stdio.h>


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
char Repert[MAXPERS]; // Repertoire de personne
int *dernier; //Position du dernier entre. Mais le 0 c'est pour la sentinnelle
int trouv; // drapeau utilise pour savoir si l'insertion a ete faite
char* nom; //Variable pour saisir le nom de la personne
int monchoix; // Variable pour saisir les reponses de l'utilisateur pour traiter les options du menu 




 //Affichage du menu 
 int rep=menu();

 //Traitement de la reponse de la l'utilisateur
switch (rep)
{
    case 1 : printf("\n Saisir un nom :");
             scanf("%s",&nom);
             printf("\n Nom saisi : '%c'",nom);
             if (!chercherpers(nom,Repert,*dernier)) 
                insererpers(nom,Repert,dernier);
             if (!trouv) printf("\n Le repertoire est plein !!!\n\n");
             break;
    case 2 : printf("\n Saisir un nom :");
             scanf("%d",&nom);
             printf("\n La position est %d !!! ", chercherpers(nom,Repert,*dernier));
             break;
    case 3 : afficherrep(Repert,*dernier);
                break;
    case 4 : printf("\n FIN !!!\n\n");
             break;
    default : printf("\n Cas imprevu !!!\n\n");
}

while (monchoix!=4); //On arrete quand l'utilisateur choisi l'option 4

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
int *choix;  //Permet de saisir la reponse de l'utilisateur

 printf("\n 1-  Entrer un nom de client");
 printf("\n 2-  Rechercher la position d'un client");
 printf("\n 3-  Afficher l'annuaire ");
 printf("\n 4-  Quitter");
 printf("\n  Votre choix :"); 
 scanf("%d",&choix);
 getchar();
return choix;

}
 

