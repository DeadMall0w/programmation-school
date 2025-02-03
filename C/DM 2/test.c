#include <stdio.h>
#define MAXTABSIZE 20

int main() {
    int tab[MAXTABSIZE][MAXTABSIZE];

	printf("Veuillez entrer les tailles du tableau \n");
    
    int nb_ligne,nb_colonne,nb_error = 0;
    do
    {
        if (nb_error >= 3){
            printf("Trop d'échec, arrêt du programme.\n");
            return 1;
        }
        printf("Longeur : ");
        scanf("%d", &nb_colonne);

        printf("Hauteur : ");
        scanf("%d", &nb_ligne);
        

        if (nb_ligne < 0)
        {
            printf("Veuillez entrer un nombre de ligne positif.\n");
            nb_error+=1;
        }else if(nb_ligne > MAXTABSIZE)
        {
            printf("Veuillez entrer un nombre de ligne inférieur a %d.\n", MAXTABSIZE+1);
            nb_error+=1;
        }

        if (nb_colonne < 0)
        {
            printf("Veuillez entrer un nombre de colonne positif.\n");
            nb_error+=1;
        }else if(nb_colonne > MAXTABSIZE)
        {
            printf("Veuillez entrer un nombre de colonne inférieur a %d.\n", MAXTABSIZE+1);
            nb_error+=1;
        }
        
    } while (nb_ligne< 0 || nb_ligne>MAXTABSIZE || nb_colonne<0 || nb_colonne>MAXTABSIZE);
    
    printf("Nombres correctes");
    
}