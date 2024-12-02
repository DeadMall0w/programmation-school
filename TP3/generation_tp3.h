/**********************************************************************************************************/
/* B2-Auteur : Armand TOGUYENI                                                                               */
/* Application : generation.h                                                                             */
/* Date : 21/11/2020                                                                                       */
/* Version : 1.2                                                                                          */ 
/* Correction : Utilisation de typedef pour définir le type d'element manipule                           */
/**********************************************************************************************************/

//Declaration des bibliotheques utilisees
#ifndef _GENERATION_H
#define  _GENERATION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


//Definition des constantes de l'application
#define     MAXCOMP     100000   // Nombre maximal de composants
#define     MAXAFF      100      // Nombre maximal de composants pour l'affichage
#define     MAXL        16      // Nombre maximal de composant par ligne pour l'affichage
#define     MOYENNE     1000

typedef double element;

/*******************************************************************************/
/* NOM function : genealea	                                               */
/* Description: genere de maniere aleatoire un tableau de reel de n composantes*/
/* Parametres en entree :Tab tableau a trier, n la taille du tableau           */
/* Parametres en sorties:Tab le tableau trie                                   */
/* Retourne :                                                                  */
/*******************************************************************************/
void genealea(element Tab[], int n)
{
 int i; //Compteur de boucle
 long aux; //Afin de ne garder que 2 chiffres apres la virgule
 //Initialisation du pseudo_generateur de nombre aleatoire
 srand((unsigned int)time(NULL));  //On initialise avec la fonction de temps  
 if (n<=MAXCOMP) for(i=1; i<=n; i++) 
     {   
          aux=(long) (100*MOYENNE*(rand()/(element)RAND_MAX)); //Pour conserver 2 chiffres apres la virgule
          Tab[i]=(double)aux/100.0;
     }
 else
     printf("Generation impossible car taille du tableau plus grande que la taille maximale %d !!! \n", MAXCOMP);
} //Accolade de fin de genalea

/********************************************************************************/
/* NOM function : geneord	                                                */
/* Description: genere de maniere croissante un tableau de reel de n composantes*/
/* Parametres en entree :Tab tableau a trier, n la taille du tableau            */
/* Parametres en sorties:Tab le tableau trie                                    */
/* Retourne :                                                                   */
/********************************************************************************/
void geneord(element Tab[], int n)
{
 int i;
  if (n<=MAXCOMP) for (i=1; i<=n; i++) Tab[i]=(element)i*2 ;
  else
     printf("Generation impossible car taille du tableau plus grande que la taille maximale %d !!! \n", MAXCOMP);
}

/**********************************************************************************/
/* NOM function : geneord	                                                  */
/* Description: genere de maniere decroissante un tableau de reel de n composantes*/
/* Parametres en entree :Tab tableau a trier, n la taille du tableau              */
/* Parametres en sorties:Tab le tableau trie                                      */
/* Retourne :                                                                     */
/**********************************************************************************/
void genereve(element Tab[], int n)
{
 int i;
 if (n<=MAXCOMP) for (i=n; i>=1; i--) Tab[n+1-i]=(element)i;
 else
     printf("Generation impossible car taille du tableau plus grande que la taille maximale %d !!! \n", MAXCOMP);
}


#endif
