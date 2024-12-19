#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * phrase(char *, const char * );

int main()
{
    TChaine dest = "titi et gros ";
    TChaine src = "minet";
    phrase(dest, src);
    printf("La phrase est : '%s'\n", dest);
    return 0;
}


char * phrase(char * dest, const char * src)
{
    char i = 0;
    char j = 0;
    char findest = 0;

    while (i <= STRINGSIZE && src[j] != '\0')
    {
        if (findest == 1){
            dest[i-1] = src[j]; 
            j++;
        }
        else if (dest[i] == '\0')
            findest = 1;
        i++;
    }

    if (i != 0) // dans le cas ou src est vide
        dest[i-1] = '\0';
    
    return dest;
}