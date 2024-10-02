#include <stdio.h>

/*
nombre parfait : 
6=1+2+3
*/

int isPerfectNumber(int number){
    int sum = 0;
    for (int i = 1 ; i < number ; i++)
    {
        if ((number%i)==0)
            sum += i;
        
    }

    if (sum == number)
        return 1;

    return 0;
}


int main()
{
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


    printf("La liste des nombres parfaits inférieurs à %d est :\n", n);
    for (int i = 1; i < n; i++)
    {
        if(isPerfectNumber(i) == 1)
            printf("- %d \n", i);
    }
}
