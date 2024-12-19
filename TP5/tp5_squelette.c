/************************************************************************/
/* AUTEUR : 						                                                                                  */
/* DATE : 14/12/2024							                                                             */
/* VERSION : 1.0                                                                                                */
/* DESCRIPTION : Interpreteur de commande                                            */
/* NOM FICHIER : tp5.c						                                                            */
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

do
{

menu() ; // Affiche la liste des commandes (a realiser)
//saisir la commande et calculer sa position dans la liste des commandes

switch (pos)
{
case 0 : //Commande premier (pre)
  printf("Tapez une premiere chaine de caracteres (s1) :");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("1er mot= '%s' \n ", premier(s2,s1)) ;
  getchar();
  break ;
  
case 4 : //Commande saufpremier (sfp)
  
    // A completer 
    
  break ;  

case 8 : //Commande phrase (phr)
  
    // A completer 
    
  break ;

case 12 : //Commande dernier (der)
    
    // A completer 
    
  break ;
  
case 16 : //Commande saufdernier (sfd)
    
    // A completer 
  
  break ;  
  
case 20: //Commande miroir (mir)
    
    // A completer 
  
  break ;  

case 24 : //Commande member (mmb)
    
    // A completer 
  
  break ;  
  
case 28 : //Commande effacer (eff)
    
    // A completer 
  
  break;
  
case 32 : menu();
break ;
case 36 : termine=VRAI ;
break ;
default : printf("\007\007 Cde inconnue. Recommencez !!!\n") ;
}
}
while (!termine) ;

}


void menu()
{
  
    // A completer
  
}
