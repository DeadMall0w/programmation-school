#include <stdio.h>
#define MAXTABSIZE 20

int main() {
    int tab[MAXTABSIZE];
    int n,u = 0;
    do
    {
        printf("Entrer n : ");
        scanf("%d", &n);

        if (u >= 2){
            printf("Trop d'échec, arrêt du programme.\n");
            return 1;
        }
        if (n < 0)
        {
            printf("Veuillez entrer un nombre positif.\n");
            u+=1;
        }else if(n > 20)
        {
            printf("Veuillez entrer un nombre inférieur a 20.\n");
            u+=1;
        }
        
    } while (n< 0 || n>20);

    printf("%d", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEntrez la valeur du tableau à l'index %d : ", i);
        int v = 0;
        scanf("%d", &v);
        tab[i] = v;
    }


    printf("Les valeurs que vous avez rentrées sont : ");
    for(int j = 0; j < n; j++)
    {
        printf("%d -> %d | ", j, tab[j]);
    }
    return 0;
}