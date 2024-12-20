#include "chaine4.h"

#define VIDE(ch)  (strlen(ch)==0)
#define EGAL(ch1, ch2) (strcmp(ch1,ch2)==0)

char * dernier(char * mot, char * ch);
char * saufdernier(char *, const Tchaine ch);
char * miroir(char *, const Tchaine ch);
int member(const Tchaine ssch, const Tchaine ch);
char * efface(char * ch, const Tchaine mot);