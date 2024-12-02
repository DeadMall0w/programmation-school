#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
typedef char TPosition;
TPosition strpos(const TChaine, const TChaine);

int main()
{
    TPosition p;
    TChaine mot = "le";
    TChaine ch = "Bonjour tout le monde";
    p = strpos(mot, ch);
    printf("%d", p);
    return 0;
}

//Fonction strpos (Tchaine mot, Tchaine ch) : Tposition ;
TPosition strpos(const TChaine mot, const TChaine ch)
{
    char i = 0;
    char j = 0;
    char debutMot = -1;
    while (ch[i] != '\0')
    {
        //printf("%c", ch[i]);
        if (ch[i] == mot[j])
        {
          //  printf("mot[%d] = %c, mot[%d] = %c",j, mot[j], i, ch[i]);
            if (debutMot == -1)
                debutMot = i;
            
            j++;
            if (mot[j] == '\0')
            {
                return debutMot;
            }
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
                {
                    return debutMot;
                }
            }
        }

        
        i++;
    }
    
    return -1;
}