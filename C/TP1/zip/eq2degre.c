// resolution d'une equation du 2e degre
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	//déclaration des variables
	int a,b,c;
	float d = 0;
	//acquisition des variables
	printf("\n Ax²+Bx+C=0");
	printf("\n entrez A: ");
	scanf("%d",&a); // & manquant
	printf("\n entrez B: ");
	scanf("%d",&b); // & manquant
	printf("\n entrez C: ");
	scanf("%d",&c); // & manquant

	//Condition invalidant la suite du prgm
	if(a==0) // Oublie d'un = apres le a
	{
		printf("\n ce n'est plus du 2nd degré");
		return 0;
	}
	else
	{
		d=(b*b)-(4.0*a*c);
		printf("delta : %d", d);
		if(d<0) // d remplacé par )
			printf("\n 2 solutions complexes conjuguées: (-%d+i racine(%f)) /%d et (-%d-i racine(%f)) /%d",b,-d,2*a,b,-d,2*a); // modification de %f dans les racines car d est un double
		else
			if(d>0)
				printf("\n 2 solutions réelles: (-%d+racine(%f)) /%d et (-%d-racine(%f)) /%d",b,d,2*a,b,d,2*a); // modification de %f dans les racines car d est un double
			else
				printf("\n 1 solution double :-%d /%d",b,2*a);

	}
	printf("\n");
	return 1;
}
