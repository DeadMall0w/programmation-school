/***********************************************************************************************/
/* B2 - Auteur :                                                                               */
/* Application : tp3_partie1.c - traitement de base sur les tableaux non tries                 */
/* Date : 08/11/2021                                                                           */
/* Version : 1.0                                                                               */
/* Compilation : gcc tp3_partie1.c -o tp3_partie1 -lm 					        */
/* Utilisation : ./tp3_partiel1                                                                */
/***********************************************************************************************/

//Declaration des bibliotheques utilisees
#include <stdio.h>
#include <sys/time.h> //Necessaire pour utiliser la fonction gettimeofday
#include "generation_tp3.h"

//Prototypes des fonctions
// Le type "element" est defini dans "generation_tp3.h"
void lister (const element T[], int taille);
int ajouter(element T[], int *taille, element valeur, int taillemax);
int rechercher(element T[], const int taille, const element valeur);
element modifier(element T[], const int taille, const int pos, const element valeur);
element supprimer(element T[], int *taille, const int pos);


int main()
{
  //Declaration des variables
 element T1[MAXCOMP+1]; //Tableaux de MAXCOMP d'entiers. Le +1 est pour la sentinnelle !!!
 int dernier=0 ; //position du dernier element saisi du tableau
 element val ; // Valeur a ajoutee
 int position; //position d'un element rechercher
 long duree;
 struct timeval debut, fin ; 
 int choix; //Saisie reponse user pour le choix de la methode de generation du tableau
 int i; //compteur de boucle
 
do
{
 
 // Affichage d'un menu
    
    printf("1 - Generer un tableau de maniere aleatoire \n");
    printf("2 - Rechercher un element du tableau  \n");
    printf("3 - Ajouter un element au tableau \n");
    printf("4 - Modifier la valeur d'un element du tableau \n");	
    printf("5 - Supprimer un element du tableau \n");
    printf("6 - Lister tous les elements du tableau \n");
    printf("7 - Afficher la valeur d'un element en fonction de sa position \n");
    printf("9 - Quitter \n");    
    printf(" Votre choix: ");
    scanf("%d", &choix);
    getchar(); //Suppression du retour chariot qui reste dans le buffer de lecture
    
    switch (choix) 
    {
        case 1 : //Saisie de la dimension effective du tableau
                i=0;
                do
                {
                    if (i<3) i=i+1; else 
                                    {
                                    printf(" 3 erreurs de saisies. L'application est arretee !!! \n ");
                                    return EXIT_FAILURE;
                                    }
                    printf("Entrer la taille du tableau a generer : ");
                    scanf("%d",&dernier);
                }
                while ((dernier<1) || (dernier>MAXCOMP));
                genealea(T1,dernier);
                 break;
        case 2 : printf(" RECHERCHE DANS UN TABLEAU NON TRIE \n");
                printf("Saisir la valeur rechercher :");
                scanf("%lf",&val);
                getchar();
                gettimeofday(&debut,NULL); //Date de debut de la recherche         
                
                
                //Inserer ici le code pour tester la fonction rechercher
                position = rechercher(T1, dernier, val);
                
                
                gettimeofday(&fin,NULL); //Date de fin de la recherche                  
                if (position==0) printf("La recherche a echoue !!!\n");
                 else printf("La valeur %f a ete trouve à la position %d \n", val, position);
                duree= (fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);
                printf("La recherche sequentielle de la valeur %.2lf dans un tableau de %d elements a pris %ld us !!! \n",val, dernier,duree);                             
                break; 
        case 3 : printf(" AJOUT DANS UN TABLEAU NON TRIE \n");
                printf("saisie de la valeur a jouter : ");
                scanf("%lf",&val); //Adapter au fait que les elements sont des "double" !!!
                getchar();
                gettimeofday(&debut,NULL); //Date de debut de l'ajout  
                 
                //Inserer ici le code pour tester la fonction ajouter
                ajouter(T1, &dernier, val, MAXCOMP+1);
                
                gettimeofday(&fin,NULL); //Date de la fin de l'ajout
				duree= (double)(fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);				
                printf("L'ajout d'un element dans un tableau de %d elements a pris %ld us !!! \n",dernier-1,duree); 
                 break;
        case 4 : printf(" MODIFICATION DANS UN TABLEAU NON TRIE \n");
                printf("Saisir la valeur a modifier :");
                scanf("%lf",&val);
                getchar();

                element nVal;
                printf("Saisir la nouvelle valeur :");
                scanf("%lf",&nVal);
                getchar();
                position=rechercher(T1,dernier, val);
                gettimeofday(&debut,NULL); //Date de debut de la modification                
                
                //Inserer ici le code pour tester la fonction modifier
                modifier(T1, dernier, position, nVal);
                
                gettimeofday(&fin,NULL); //Date de fin de la suppression 
                if ((position!=0) && (debut.tv_sec==fin.tv_sec)) printf("La modification de la valeur %.2lf dans un tableau de %d elements a pris %d us !!! \n",val, dernier,(int) (fin.tv_usec-debut.tv_usec)); 
                          else if (position!=0) 
                                {
                                duree= (fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);
                                printf("La modification de la valeur %.2lf dans un tableau de %d elements a pris %ld us !!! \n",val, dernier,duree); 
                                }                                    
                break;            
        case 5 : printf(" SUPPRESSION DANS UN TABLEAU NON TRIE \n");
                printf("Saisir la valeur a supprimer :");
                scanf("%lf",&val);
                getchar();
                position=rechercher(T1,dernier, val);
                gettimeofday(&debut,NULL); //Date de debut de la suppression                
                
                //Inserer ici le code pour tester la fonction supprimer
                position = supprimer(T1, &dernier, position);
                
                gettimeofday(&fin,NULL); //Date de fin de la suppression 
                if ((position!=0) && (debut.tv_sec==fin.tv_sec)) printf("La suppression de la valeur %.2lf dans un tableau de %d elements a pris %d us !!! \n",val, dernier,(int) (fin.tv_usec-debut.tv_usec)); 
                          else if (position!=0) 
                                {
                                duree= (fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);
                                printf("La suppression de la valeur %.2lf dans un tableau de %d elements a pris %ld us !!! \n",val, dernier,duree); 
                                }                                    
                break;       
        case 6 : printf(" AFFICHAGE D'UN TABLEAU \n"); 
                 
                //Inserer ici le code pour afficher un tableau dont la taille ne doit pas depsser MAXAFF
                if (dernier > MAXAFF)
                {
                    printf(" /!\\ LE TABLEAU EST TROP GRAND, TRONCAGE DES ELEMENTS EN TROP\n");
                }
                lister(T1, dernier);

                 break;            
        case 7 : printf(" AFFICHAGE D'UN ELEMENT EN FONCTION DE SA POSITION\n");
 
                //Inserer ici le code pour afficher une element en fonction de sa position
                int pos;
                printf("Position de l'element:");
                scanf("%d",&pos);
                getchar();

                if (pos <= 0)
                {
                    printf("Veuillez entrer un nombre strictement superieur a 0");
                    break;
                }

                if (pos > dernier)
                {
                    printf("Veuillez entrer un nombre dans les limites du tableau");
                    break;
                }

                printf("%g", T1[pos]);

                 break;
        case 9 : printf("Fin de l'application !!!\n");
                 break;
        default : printf("Cette saisie n'est pas correcte !!! !!! \n");
        }
}       
while (choix!=9); 
       
 
 return EXIT_SUCCESS;     
} //Accolade de fin du programme



/**************************************************************************************************/
/*Fonction : lister                                                                             */
/* Description : Afficher les composantes d'un tableau mono-dimentionnel si leur nombre est       */
/* inferieur a MAXAFF                                                                             */
/* Entrees : T le tableau et taille son nombre de composantes                                     */
/* Sorties :                                                                                      */
/* Retourne :                                                                                     */
/**************************************************************************************************/

void lister (const element T[], const int taille)
{
	// n = taille, si taille < MAXAFF
	// n = MAXAFF, si 
    int n = (taille > MAXAFF)? MAXAFF: taille;
    
    for (int i = 1; i <= n; i++)
    {
        printf("%g \n", T[i]);
    } 
}

/**************************************************************************************************/
/*Fonction : rechercher                                                                           */
/* Description : Rechercher un element dans un tableau non trie par la methode de la sentinnelle  */
/* Entrees : T le tableau, taille son nombre de composantes et valeur l'element a ajoute          */
/* Sorties :                                                                                      */
/* Retourne : la position de l'element rechercher ou 0 si non trouve                              */
/**************************************************************************************************/
int rechercher(element T[], const int taille, const element valeur)
{
    int i = taille;
    T[0] = valeur;
    while(T[i] != valeur)
    {
        i--;
    }
    return i;
}

/**************************************************************************************************/
/* Fonction : ajouter                                                                               */
/* Description : Ajouter un element au tableau                                                     */
/* Entrees : T le tableau, taille son nombre de composantes,valeur l'element a ajoute et taillemax *
/* Le nombre maximal de composants de T                                                            */
/* Sorties : T le tableau, taille son nombre de composants                                         */
/* Retourne : la position de l'element ajoute ou 0 si l'ajout n'est pas effectue                   */
/**************************************************************************************************/
int ajouter(element T[], int *taille, element valeur, int taillemax)
{

    if (*taille >= taillemax)
    {
        printf(" /!\\ LE TABLEAU EST TROP PLEIN, ELEMENT NON AJOUTE\n");
        return 0; // element non rajoute
    }
    *taille = *taille +1;
    T[*taille] = valeur;
    
    return *taille;    
}

/**************************************************************************************************/
/*Fonction : modifier                                                                             */
/* Description : Modifier la valeur de l'element en position pos dans un tableau                  */
/* Entrees : T le tableau, taille son nombre de composantes et pos la position de l'element a     */
/* modifier , valeur la nouvelle valeur de l'element						   */
/* Sorties : T le tableau									   */
/* Retourne : la valeur de l'element supprimé ou 0.0 si la suppression est impossible  ? MODIFICATION ?             */
/**************************************************************************************************/
element modifier(element T[], const int taille, const int pos, const element valeur)
{
    if (pos <= 0 || pos > taille){
        return 0.0;
    }
    element t = T[pos];
    T[pos] = valeur;
    return t;
}

/**************************************************************************************************/
/*Fonction : supprimer                                                                            */
/* Description : Supprimer un element dont ont connait la position dans un tableau                */
/* Entrees : T le tableau, taille son nombre de composantes et pos la position de l'element a     */
/* supprimer																					  */
/* Sorties : T le tableau, taille son nombre de composantes                                       */
/* Retourne : la valeur de l'element supprimé ou 0.0 si la suppression est impossible               */
/**************************************************************************************************/
element supprimer(element T[], int *taille, const int pos)
{

    if (*taille <= 0)
    {
        printf(" /!\\ LE TABLEAU EST VIDE, AUCUN ELEMENT SUPPRIME\n");
        return 0;
    }

    if(pos <= 0 || pos > *taille)
    {
        printf(" /!\\ IMPOSSIBLE DE SUPPRIMER EN DEHORS DES LIMITES DU TABLEAU\n");
        return 0;
    }
    T[0] = T[pos];
    for (int i = pos; i < *taille; i++)
    {
        T[i] = T[i+1]; 
    }
    
    *taille = *taille -1;
    
    return T[0]; 
}

