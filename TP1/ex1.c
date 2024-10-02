#include <stdio.h>

/*
0 : 0
1 : 1
2 : 1+3 = 4
3 : 1+3+5 = 9
4 : 1+3+5+9 = 16
*/

int main() {
    printf("Entrer n : ");
    int n = 0;
    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (i*2) + 1;
    }
    
    printf("La somme des %d premiers nombres impairs est : %d \n", n, sum);
    return 0;
}