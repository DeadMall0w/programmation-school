#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * format(char *);

int main()
{
    TChaine chaine = "\tbonjour   le   monde  \t"; 
    format(chaine);
    printf("La nouvelle chaine formate est : '%s'\n", chaine);
    return 0;
}

/*
Nom : format
Entrée : chaine à formater
Sortie : Chaine formate
Principe : enleve les espaces redondant, les espaces en debut et en fin de chaine, enleve les tabulations.
*/
char * format(char *ch)
{
    char i = 0;
    char j = 0;
    char HM = -1; //HM = -1 ou 0: pas d'espace, HM = 1 : espace a rajouter 

    while (ch[j] != '\0')
    {
        if (ch[j] == ' ' || ch[j] == '\t')
        {
            if (HM != -1)
                HM = 1;
        }
        else
        {
            if (HM == 1)
            {
                ch[i] = ' ';
                i++;
                HM = 0;
            }
            if(HM == -1)
                HM = 0;
            ch[i] = ch[j];
            i++;
        }
        j++;
    }
    ch[i] = '\0';

    return ch;
}