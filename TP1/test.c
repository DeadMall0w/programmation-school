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
    int number = 0;
    printf("n : ");
    scanf("%d", &number);
    for (int i = 1 ; i < number ; i++)
    {
        if ((number%i)==0)
            printf("%d \n", i);
        
    }   
}