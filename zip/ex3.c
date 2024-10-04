#include <stdio.h>
#include <math.h>
/* Consignes
Résolution d'une équation du second degré
Écrire un programme permettant de résoudre une équation du second degré. Les paramètres
de ce programme seront les coefficients a, b et c de l’équation ax2+bx+c=0.
Vous envisagerez tous les cas de figure, y compris les cas ou certains coefficients sont nuls.
*/


int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    double d = 0;

    printf("Entrer a : ");
    scanf("%d", &a);

    printf("Entrer b : ");
    scanf("%d", &b);

    printf("Entrer c : ");
    scanf("%d", &c);

    printf("Resolution de l equation : %fx² + %fx + %f = 0\n", a, b ,c);

    d = b*b - 4*a*c;
    printf("delta : %f\n", d);

    if (d > 0) // 2 solutions
    {
        float s1 = (- b - sqrt(d))/(2 * a);
        float s2 = (- b + sqrt(d))/(2 * a);

        printf("Les 2 solutions de l'équation sont : \n");
        printf("%f \n", s1);
        printf("%f \n", s2);

    }
    else if (d == 0) // 1 solution
    {
        float s = -b/(2 * a);

        printf("La solution de l'équation est : \n");
        printf("%f \n", s);

    }
    else // pas de solution réel
    {
        printf("Pas de solution réel.\n");
    }
}