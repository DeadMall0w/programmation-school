#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
char * strmin(TChaine);

int main()
{
    TChaine chaine = "TouT eN MiNuscUle"; 
    strmin(chaine);
    printf("La nouvelle chaine est : '%s'\n", chaine);
    return 0;
}

/*
Nom : strmin
Entrée : chaine à modifier
Sortie : Chaine modifier
Principe : Transforme la chaine pointé par le pointeur fourni en paramètre en minuscule uniquement
*/
char * strmin(char *ch)
{
    char i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] += 'a' - 'A';
        i++;
    }
    
    return ch;
}