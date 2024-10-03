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
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;

    printf("Entrer a : ");
    scanf("%lf", &a);

    printf("Entrer b : ");
    scanf("%lf", &b);

    printf("Entrer c : ");
    scanf("%lf", &c);

    printf("Resolution de l equation : %gx^2 + %gx + %g = 0\n", a, b ,c);

    d = b*b - 4*a*c;
    printf("Delta : %.5g\n", d);

    if (d > 0) // 2 solutions
    {
        float s1 = (- b - sqrt(d))/(2 * a);
        float s2 = (- b + sqrt(d))/(2 * a);

        printf("Les 2 solutions de l equation sont : \n");
        printf("%.5g \n", s1);
        printf("%.5g \n", s2);

    }
    else if (d == 0) // 1 solution
    {
        float s = -b/(2 * a);

        printf("La solution de l equation est : \n");
        printf("%.5g \n", s);

    }
    else // 2 solutions dans C
    {
        float m = (- b)/(2 * a);
        float q = (sqrt(-d))/(2 * a);
        // float s2 = (- b + sqrt(d))/(2 * a);

        printf("Les 2 solutions de l equation sont : \n");
        printf("%.5g - %.5gi \n", m, q);
        printf("%.5g + %.5gi \n", m, q);
    }
}