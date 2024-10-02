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
    printf("Entrer n : ");
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        if(isPerfectNumber(i) == 1)
            printf("%d est parfait\n", i);
    }
    
}
