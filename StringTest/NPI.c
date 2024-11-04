#include <stdio.h>
#include <string.h>

typedef struct {
    int corps[50];
    int taille;
} TPile;

void empiler(TPile, int);
int depiler(TPile);

TPile pile;
int main() {
    pile.taille = 0;
    empiler(pile, 18);
    empiler(pile, 34);
    empiler(pile, 15);

    int i1 = depiler(pile);
    int i2 = depiler(pile);
    int i3 = depiler(pile);

    printf("depile : %d", i1);
    printf("depile : %d", i2);
    printf("depile : %d", i3);



    return 0;
}

void empiler(TPile _pile, int elt)
{
    _pile.corps[_pile.taille] = elt;
    _pile.taille += 1;
}

int depiler(TPile _pile)
{
    _pile.taille -= 1;
    return _pile.corps[_pile.taille+1];
}