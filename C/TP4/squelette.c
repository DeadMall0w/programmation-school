#include <stdio.h>
#define STRINGSIZE 80

typedef char TChaine[STRINGSIZE+1];
typedef char TPosition;

char * format(char *);
char * strmin(TChaine);
TPosition strpos(char *, char *);

char * premier(char *, const char * );
char * saufpremier(char *, const char * );
char * phrase(char *, const char * );

TPosition longueur(const char *);

int main()
{
    int input;
    do
    {
        printf("0 - Tester strmin\n");
        printf("1 - Tester strpos\n");
        printf("2 - Tester format\n");
        printf("3 - Tester premier\n");
        printf("4 - Tester saufpremier\n");
        printf("5 - Tester phrase\n");

        printf("6 - Longueur chaine\n");

        printf("9 - Quitter\n");

        scanf("%d", &input);
        getchar();
        TChaine chaine; 
        TChaine mot;
        TPosition p;

        switch (input)
        {
        case 0: // strmin
            printf("Entrer la chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            format(chaine);
            strmin(chaine);
            printf("'%s'\n", chaine);
            break;
        case 1: // strpos
            printf("Entrer la chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            format(chaine);

            printf("Entrer le mot à chercher : \n");

            fgets(mot, STRINGSIZE-1,  stdin);
            format(mot);

            p = strpos(mot, chaine);
            if (p == -1)
            {
                printf("Le mot n'a pas été trouvé\n");
            }
            else
            {
                printf("Le mot à été trouvé en position : %d\n", p);
            }
            break;
        case 2: // format
            printf("Entrer la chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            format(chaine);
            printf("'%s'\n", chaine);
            break;
        case 3: // premier
            printf("Entrer la chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            format(chaine);
            premier(mot, chaine);
            printf("Le premier mot est : '%s'\n", mot);
            break;
        case 4: // saufpremier
            printf("Entrer la chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            format(chaine);
            saufpremier(mot, chaine);
            printf("Tout sauf le premier mot : '%s'\n", mot);
            break;
        case 5: // phrase
            printf("Entrer la premiere chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            chaine[longueur(chaine)-1]='\0';

            printf("Entrer le deuxieme chaine : \n");

            fgets(mot, STRINGSIZE-1,  stdin);
            mot[longueur(mot)-1]='\0';
            
            phrase(chaine, mot);
            
            printf("La phrase est : '%s'\n", chaine);
            break;
        case 6: // longueur
            printf("Entrer la chaine : \n");

            fgets(chaine, STRINGSIZE-1,  stdin);
            p = longueur(chaine);
            chaine[longueur(chaine)-1]='\0';
            printf("La longueur de la chaine est : '%d'\n", p-1);
            break;
        case 9:
            printf("--ARRET DU PROGRAMME--\n");
            break;
        
        default:
            printf("Aucune correspondance, arret du programme\n");
            return -1;
        }
    } while (input != 9);
    


    return 0;
}

TPosition longueur(const char * ch)
{
    TPosition i = 0;
    while (ch[i] != '\0')
        i++;
    return i;
}

/*
Nom : format
Entrée : chaine à formater
Sortie : Chaine formate
Principe : enleve les espaces redondant, les espaces en debut et en fin de chaine, enleve les tabulations et les retours chariots.
*/
char * format(char *ch)
{
    char i = 0;
    char j = 0;
    char HM = -1; //HM = -1 ou 0: pas d'espace, HM = 1 : espace a rajouter 

    while (ch[j] != '\0')
    {
        if (ch[j] == ' ' || ch[j] == '\t' || ch[j] == '\n')
        {
            j++;
            if (HM != -1)
            {
                HM = 1;
            }
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
            {
                HM = 0;
            }
            ch[i] = ch[j];
            i++;
            j++;
        }
    }
    ch[i] = '\0';
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
    char debutMot = -1;
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


char * premier(char * mot, const char * chaine)
{
    char i=0;
    while(chaine[i] != ' ' && chaine[i] != '\0')
    {
        mot[i] = chaine[i];
        i++;
    }

    return mot;
}


char * saufpremier(char * restch, const char * chaine)
{
    char i=0;
    char j=0;
    char premiermot = 1;
    while(chaine[i] != '\0')
    {
        if(premiermot == 1 && chaine[i] == ' ')
        {
            premiermot = 0; // Le premier mot vient d'être depassé
            i++; // On passe l'espace
        }
        if (premiermot == 0)
        {
            restch[j] = chaine[i];
            j++;
        }
        i++;
    }

    return restch;
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
