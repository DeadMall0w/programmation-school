/**********************************************************************************************************/
/* Auteur : Armand TOGUYENI                                                                               */
/* Application : tp2_tri_squellette.c                                                                     */
/* Date : 15/11/2020                                                                                       */
/* Version : 1.1                                                                                          */ 
/* Corrections : affichage tableau et de la duree  d'un tri                                               */                                                     
/**********************************************************************************************************/

//Declaration des bibliotheques utilisees
#include <stdio.h>
#include <sys/time.h> //Necessaire pour utiliser la fonction gettimeofday
#include "generation.h"

int main()
{
  //Declaration des varaibles
 double T1[MAXCOMP], T2[MAXCOMP]  ; //Tableaux de MAXCOMP d'entiers
 int i; //Compteur de boucle
 int nb; //dimension du tableau
 double duree;
 struct timeval debut, fin ; 
 char rep; //Saisie reponse du user
 int choix; //Saisie reponse user pour le choix de la methode de generation du tableau
 
 printf("\n\n\t\t APPLICATION D'EVALUATION DE METHODES DE TRI ...\n\n ");
  
do
{
    //Saisie de la dimension effectivedu tableau
    i=0;
    do
    {
        if (i<3) i=i+1; else 
            {
                printf(" \n 3 erreurs de saisies. L'application est arretee !!! ");
                return EXIT_FAILURE;
            }
            printf("\n Entrer la taille du tableau a generer : ");
        scanf("%d",&nb);
    }
    while ((nb<1) || (nb>MAXCOMP));
    
    printf("\n 1 - Generation d'un tableau avec un ordre aleatoire" );
    printf("\n 2 - Generation d'un tableau dans l'ordre croissant");
    printf("\n 3 - Generation d'un tableau dans l'ordre decroissant");
    printf(" \n Choix de la methode de generation : ");
    scanf("%d", &choix);
    getchar(); //Suppression du RC
    
    switch (choix) 
    {
        case 1 : genealea(T1,nb);
                 break;
        case 2 : geneord(T1,nb);
                 break;
        case 3 : genereve(T1,nb);
                 break;
        default : printf("\n Cette methode de generation n'existe pas !!!");
    }
 
 //Affichage du tableau genere s'il n'est pas trop grand
 if (nb<=MAXAFF)
 {
    printf("\n Voulez-vous afficher le tableau (O/N): "); 
    rep=getchar();
    getchar();
    if (tolower(rep)=='o')
          for(i=1; i<=nb; i++)
              {
                if (!(i % MAXL)) printf("\n") ; //On passe a la ligne suivante chaque fois que l'on a affiche MAXL composant sur une ligne
                printf("%.2lf \t",T1[i]);
              }
    printf("\n"); //Passage de l'affichage a la ligne suivante        
 }
    
    do
    {
        //Affectation du tableau genere dans un autre tableau poue sauvegarde de la valeur
        for(i=0 ; i <=nb ; i++) T2[i]=T1[i];
        
        //Choix d'une methode de tri
        printf("\n a - Tri selection ");
        printf("\n b - Tri echange ");
        printf("\n c - Tri insertion ");
        printf("\n Choix de la methode de tri : ");
        rep=getchar();
        getchar();
        
        //Traitement en fonction de la methode de tri choisie
        switch (rep)
        {
            case 'a': 
            case 'A':     printf("\n \t\t\t Tri Selection ");
                          gettimeofday(&debut,NULL); //Date de debut du tri  
 
                          //A completer avec la methode de tri selection
                          
                          gettimeofday(&fin,NULL);  //Date de din du trin 
                          duree= (double)(fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);
                          printf("\n Le tri selection d'un tableau de %d elements a pris %lf us !!! ",nb,duree); 
                            break;
            case 'b':
            case 'B': printf("\n \t\t\t Tri Echanges ou Tri à Bulles ");
                          gettimeofday(&debut,NULL); //Date de debut du tri  
                            
                          //A completer avec la methode de tri echange
                          
                          gettimeofday(&fin,NULL);  //Date de din du trin 
                          duree= (double)(fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);
                          printf("Le tri echange d'un tableau de %d elements a pris %lf us !!! \n",nb,duree); 

                            break;
            case 'c':
            case 'C': printf("\nh \t\t\t Tri Insertion \n");
                          gettimeofday(&debut,NULL); //Date de debut du tri  
 
                          //A completer avec la methode de tri insertion
                          
                          gettimeofday(&fin,NULL);  //Date de din du trin 
                          duree= (double)(fin.tv_sec*1000000+fin.tv_usec)-(debut.tv_sec*1000000+debut.tv_usec);
                          printf("Le tri insertion d'un tableau de %d elements a pris %lf  us !!! \n",nb,duree); 
                            break;
            default : printf("\n Il n'y a pas de methode de tri correspondant a votre selection !!! \n");
        }
    //Affichage du tableau genere s'il n'est pas trop grand
if (nb<=MAXAFF)
    {
    printf("\n Voulez-vous afficher le tableau (O/N): "); 
    rep=getchar();
    getchar();
    if (tolower(rep)=='o')
          for(i=1; i<=nb; i++)
              {
                if (!(i % MAXL)) printf("\n") ; //On passe a la ligne suivante chaque fois que l'on a affiche MAXL composant sur une ligne
                printf("%.2lf \t",T2[i]);
              }
    printf("\n"); //Passage de l'affichage a la ligne suivante        
    }
        
        printf("\n Voulez-vous poursuivre avec une autre methode de tri et le meme tableau (O/N) :");
        rep=getchar();
        getchar();
    }
    while (tolower(rep)=='o');
    
    printf("\n Voulez-vous poursuivre l'application (O/N) :");
    rep=getchar();
    getchar();
}
while (tolower(rep)=='o');
 
 printf("\n FIN APPLICATION D'EVALUATION DES METHODES DE TRI !!! \n\n");
 return EXIT_SUCCESS;     
} //Accolade de fin du programme
