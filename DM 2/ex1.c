#include <stdio.h>
#define MAXTABSIZE 20

int main() {
    int tab[MAXTABSIZE];

	printf("Veuillez entrer la taille du tableau \n");
    
    int longeur,nb_error = 0;
    do
    {
        if (nb_error >= 3){
            printf("Trop d'échec, arrêt du programme.\n");
            return 1;
        }
        printf("Longeur : ");
        scanf("%d", &longeur);
        if (longeur < 0)
        {
            printf("Veuillez entrer un nombre positif.\n");
            nb_error+=1;
        }else if(longeur > MAXTABSIZE)
        {
            printf("Veuillez entrer un nombre inférieur a %d.\n", MAXTABSIZE+1);
            nb_error+=1;
        }
        
    } while (longeur< 0 || longeur>MAXTABSIZE);
    
    printf("Vous avez choisi un tableau de longueur : %d", longeur);
    for (int i = 0; i < longeur; i++)
    {
        printf("\nEntrez la valeur du tableau à l'index %d : ", i);
        int v = 0;
        scanf("%d", &v);
        tab[i] = v;
    }


    printf("Les valeurs du tableau sont : \n");
    for(int j = 0; j < longeur; j++)
    {
        printf("v[%d] = %d \n", j, tab[j]);
    }
    return 0;
    
}