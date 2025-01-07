#include <string.h>

#define MAXCAR 30
typedef char Tchaine[MAXCAR+1]; //Le +1 c'est pour le caractere '\0'

#define MAXPERS 10000
typedef Tchaine Ttabpers[MAXPERS+1]; //Le +1 c'est pour la sentinelle


short chercherpers(Ttabpers Ttebpers, short der, Tchaine nom);

short insererpers(Ttabpers Rep, short * der, Tchaine nom);

void afficherrep(const Ttabpers Rep, short der);

short supprimerpers(Ttabpers Rep, short * der, int position);