#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
typedef char TPosition;
TPosition strpos(char *, char *);

int main()
{
    TPosition p;
    TChaine mot = "le";
    TChaine ch = "Bonjour tout le monde";
    p = strpos(mot, ch);
    if (p == -1)
    {
        printf("Le mot n'a pas été trouvé\n");
    }
    else
    {
        printf("Le mot à été trouvé en position : %d\n", p);
    }
    return 0;
}

/*
Nom : strpos
Entrée : mot à chercher, chaine dans lequel on cherche le mot 
Sortie : Position du mot dans la chaine si trouvé, sinon -1
Principe : Renvoie la position du mot dans la chaine si le mot es trouvé, sinon il renvoie -1
*/
TPosition strpos(char * mot,char * ch)
{
    char i = 0;
    char j = 0;
    TPosition debutMot = -1;
    while (ch[i] != '\0')
    {
        if (ch[i] == mot[j])
        {
            if (debutMot == -1)
                debutMot = i;
            
            j++;
            if (mot[j] == '\0')
                return debutMot;
        }
        else
        {
            debutMot = -1;
            j=0;
            if (ch[i] == mot[j])
            {
                if (debutMot == -1)
                    debutMot = i;
                
                j++;
                if (mot[j] == '\0')
                    return debutMot;
            }
        }
        i++;
    }
    
    return -1;
}