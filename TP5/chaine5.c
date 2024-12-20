#include "chaine5.h"

char * dernier(char * mot, char * ch)
{    
    Tchaine t;
    strcpy(t, ch);

    int i = 0;

    if (strpos(" ", ch) == -1)
    {
        strcpy(mot, ch);
        return ch;
    }
    while (i <= MAXCAR)
    {
        i++;
        saufpremier(mot, ch);
        
        if (mot[0] == '\0')
        {
            strcpy(mot, ch);
            strcpy(ch, t);

            return mot;
        }

        saufpremier(ch, mot);

        if (ch[0] == '\0')
        {
            strcpy(ch, t);

            return mot;
        }
    }    
}

char * saufdernier(char * debch, const Tchaine ch)
{
    Tchaine ch2;
    strcpy(ch2, ch);

    Tchaine t;
    Tchaine v;
    
    while (strpos(" ", ch2) != -1)
    {
        strcpy(v, ch2);
        premier(t, ch2);
        strcpy(ch2, v);
        phrase(debch, t);
        strcpy(t, ch2);  
        saufpremier(ch2,t);
    }

    return debch;
}

char * miroir(char * mirch, const Tchaine ch)
{
    Tchaine ch2;
    strcpy(ch2, ch);

    Tchaine t;
    while (!VIDE(ch2))
    {
        dernier(t, ch2);

        phrase(mirch, t);

        t[0] = '\0';
        saufdernier(t, ch2);

        strcpy(ch2, t);
        t[0] = '\0';

    }
    return mirch;
}

int member(const Tchaine ssch, const Tchaine ch)
{
    return (strpos(ssch, ch) == -1)?0:1;
}


char * efface(char * ch, const Tchaine mot)
{
    while(strpos(mot, ch) != -1)
    {
        int pos = strpos(mot, ch);
        int taille = 1;
        int i =pos;
        while(ch[i] != ' ')
        {
            i++;
            taille++;
        }
        i = pos+taille;
        while(ch[i] != '\0')
        {
            printf("%c\n", ch[i]);
            ch[i-taille] = ch[i];
            i++;
        }

        ch[i-taille] = '\0';
    }

    return ch;

}