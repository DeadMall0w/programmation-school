/************************************************************************/
/* AUTEUR : BERQUIER Raphal						                                  */
/* DATE : 14/12/2024							                                      */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Interpreteur de commande                               */
/* NOM FICHIER : tp5.c						                                      */
/************************************************************************/


//Includes
#include "chaine5.h"

#define MAX 5

void menu();


int main()
{
 char cde[MAX] ; // permet de saisir une commande
 Tchaine s1,s2; // Chaines de caracteres
                 /*0   4   8   12  16  20    24   28   32   36  */
char liste_cdes[]="pre-sfp-phr-der-sfd-mir-mmb-eff-hlp-fin"; //Definie la liste des commandes de l'interpreteur
int termine=FAUX ;
int pos ; // variable correspondant a la position de "cde" dans "liste_cdes"

char command[4];
do
{

menu() ; // Affiche la liste des commandes (a realiser)
//saisir la commande et calculer sa position dans la liste des commandes
scanf("%s", cde);
getchar();
pos = strpos(cde, liste_cdes);
s1[0] = '\0';
s2[0] = '\0';

switch (pos)
{
case 0 : //Commande premier (pre)
  printf("Tapez une chaine de caractère : ");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("\n1er mot = '%s' \n ", premier(s2,s1)) ;
  getchar();
  break ;
  
case 4 : //Commande saufpremier (sfp)
  printf("Tapez une chaine de caractère : ");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("\nTout sauf le premier mot = '%s' \n ", saufpremier(s2,s1)) ;
  getchar();
  break;

case 8 : //Commande phrase (phr)
  printf("Tapez une première chaine : ");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("Tapez une deuxième chaine : ");
  fgets(s2, MAXCAR,stdin);format(s2);
  getchar();

  printf("\nLes deux chaines concaténé est = '%s' \n ", phrase(s1,s2)) ;
  break ;

case 12 : //Commande dernier (der) 
    printf("Tapez une chaine de caractère : ");
    fgets(s1, MAXCAR,stdin);format(s1);
    dernier(s2, s1);
    printf("dernier mot = '%s' \n ", s2) ;
    getchar();

  break ;
  
case 16 : //Commande saufdernier (sfd)
    printf("Tapez une chaine de caractère : ");
    fgets(s1, MAXCAR,stdin);format(s1);
    saufdernier(s2, s1);
    printf("Tout sauf le dernier mot = '%s' \n ", s2) ;
    getchar();
  break ;  
  
case 20: //Commande miroir (mir)
    printf("Tapez une chaine de caractère : ");
    fgets(s1, MAXCAR,stdin);format(s1);
    miroir(s2, s1);
    printf("Le miroir est = '%s' \n ", s2) ;
    getchar();
  
  break ;  

case 24 : //Commande member (mmb)
    
  printf("Tapez une première chaine : ");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("Tapez une deuxième chaine : ");
  fgets(s2, MAXCAR,stdin);format(s2);
  if (member(s2,s1)){
    printf("La sous chaine a été trouvé ! \n");
  }
  else
  {
    printf("La sous chaine n'a pas été trouvé ! \n ");
  }
  getchar();
  
  break ;  
  
case 28 : //Commande effacer (eff)
    printf("Tapez une première chaine : ");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("Tapez une deuxième chaine : ");
  fgets(s2, MAXCAR,stdin);format(s2);

  printf("\nLa nouvelle chaine est = '%s' \n ", efface(s1,s2)) ; 
  getchar();
  
  break;
  
case 32 : menu();
break ;
case 36 : termine=VRAI ;
break ;
default : printf("\007\007 Cde inconnue. Recommencez !!!\n") ;

  while (getchar() != '\n') {} // vider le buffer

}
}
while (!termine) ;

}


void menu()
{
  
  printf("- 'pre' pour avoir le premier mot d'une chaine.\n");
  printf("- 'sfp' pour tout sauf le premier mot d'une chaine.\n");
  printf("- 'phr' pour concatener une chaîne.\n");
  printf("- 'der' pour avoir le dernier mot d'une chaine.\n");
  printf("- 'sfd' pour tout sauf le dernier mot d'une chaine.\n");
  printf("- 'mir' pour avoir le miroir d'une chaine.\n");
  printf("- 'mmb' pour savoir si une sous chaine est presente.\n");
  printf("- 'eff' pour effacer toutes les occurences d'une chaine dans une sous chaine.\n");
  printf("- 'hlp' pour afficher le menu.\n");
  printf("- 'fin' pour terminer le programme.\n");
  
}
