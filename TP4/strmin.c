#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * strmin(TChaine);

int main()
{
    TChaine chaine = "BonJouR teST"; 
    strmin(chaine);
    printf("%s", chaine);
    return 0;
}

char * strmin(char *ch)
{
    char i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            ch[i] += 'a' - 'A';
        }
        i++;
    }
    
    return ch;
    
}