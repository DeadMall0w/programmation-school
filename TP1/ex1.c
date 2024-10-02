#include <stdio.h>

/*
0 : 0
1 : 1
2 : 1+3 = 4
3 : 1+3+5 = 9
4 : 1+3+5+7 = 16
5 : 1+3+5+7+9 = 25
*/

int main() {
    int n = 0;
    do
    {
        printf("Entrer n : ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("Veuillez entrer un nombre positif.\n");
        }
        
    } while (n< 0);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (i*2) + 1;
    }
    
    printf("La somme des %d premiers nombres impairs est : %d \n", n, sum);
    return 0;
}