#include <stdio.h>
#include <stdlib.h>


int main() // manque du int, créant  un warning lors de la compilation
{

	/* variables */ 

	float  billet ; /* billet dont on veut faire la monnaie*/
	int nbp2 ; /* nb de pieces de 2€*/
	int nbp1 ;
	int nbp50;
	int nbp20;
	int nbp10;
	int nbp5;
	int nbp2c;
	int nbp1c;
	int diviseur ; 

	/* Initialisation*/



	printf(" \n\n Saisir la valeur d'un billet (entier superieur  a 2 €) :");
	scanf("%f",&billet); // manque d'un & devant billet
	fflush(stdin);
	printf("\nValeur saisie : %f", billet); // & en trop devant billet, et changement de %fls en %f pour correspondre à un double

	diviseur=200;
	billet=billet*100; /* pour tout convertir en centimes d'euros*/

	/* Traitement */

	do
	{ 

		switch (diviseur) {
			case 200 :  /* pieces de 2€ */
				nbp2=billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=100;
				printf("\n Il y a %d pieces de 2€",nbp2);
				break;
			case 100 :   /* pieces de 1€ */
				nbp1=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=50;
				printf("\n Il y a %d pieces de 1€",nbp1); // oublie de %d au milieu du printf
				break;
			case 50 :  /* pieces de 50 cts */
				nbp50=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=20;
				printf("\n Il y a %d pieces de 50 cts",nbp50);
				break;
			case 20 :   /* pieces de 20 cts */
				nbp20=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=10;
				printf("\n Il y a %d pieces de 20 cts",nbp20);
				break;
			case 10 :  /* pieces de 10 cts */
				nbp10=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=5;
				printf("\n Il y a %d pieces de 10 cts",nbp10);
				break;
			case 5 :   /* pieces de 5 cts */
				nbp5=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=2;
				printf("\n Il y a %d pieces de 5 cts",nbp5);
				break;
			case 2 :  /* pieces de 2 cts */
				nbp2c=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=1;
				printf("\n Il y a %d pieces de 2 cts",nbp2c);
				break;
			case 1 :   /* pieces de 1 cts */
				nbp1c=(int)billet/diviseur;
				billet=(int)billet%diviseur;
				diviseur=1;
				printf("\n Il y a %d pieces de 1 cts",nbp1c);
				break;
			default : printf("\n\n Cas imprevu !!! Il y a une erreur");
				} 
		}
	while (billet>0); // (billet > 0) plus logique que juste (billet) meme si les 2 fonctionne dans la cas de nombre positif

	return 0; // return 0 au lieu de 1, car il n'y a pas d'erreur

}

