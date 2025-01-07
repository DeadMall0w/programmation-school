#include <string.h>

#define MAXCAR 30
typedef char Tchaine[MAXCAR+1]; //Le +1 c'est pour le caractere '\0'

#define MAXPERS 10000
typedef Tchaine Ttabpers[MAXPERS+1]; //Le +1 c'est pour la sentinelle

typedef short Telt;

Telt chercherpers(Tchaine Rep[], Telt der, Tchaine nom);

Telt insererpers(Tchaine Rep[], Telt * der, char nom[]);

void afficherrep(const Tchaine Rep[], Telt der);

Telt supprimerpers(Tchaine Rep[], Telt * der, int position);