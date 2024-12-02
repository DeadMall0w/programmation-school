#include <stdio.h>
#include <string.h>
#define CHARSIZE 20

int main()
{
    char str1[CHARSIZE] = "Hello,"; 
    char str2[CHARSIZE] = "world !";
    char str3[CHARSIZE];
    fgets(str1, CHARSIZE-1,  stdin);
    str1[strlen(str1) -1] = '\0';
    strcpy(str3, str1);
    strcat(str3, str2);
    printf("%s de longueur : %ld", str3, strlen(str3));
    
    return 0;
}
