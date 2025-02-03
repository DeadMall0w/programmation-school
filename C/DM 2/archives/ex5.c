/*
1. Développer un programme qui permet de trier un tableau monodimensionnel par la
méthode du tri par insertion. Cette méthode pourra être testée à l’aide du programme
de l’exercice 1 qui sera adapté.
2. Faire un jeu d’essais pour prouver le bon fonctionnement de votre programme.
3. Adapter votre programme à l’aide du code donné par l’enseignant. Ce code vous
permet de générer de manière aléatoire des tableaux de grandes tailles et calculer la
durée de tri. Faire des jeux d’essais pour illustrer le bon fonctionnement de votre
programme et évaluer la complexité de la méthode. On tracera la courbe durée de la
méthode de tri en fonction nombre de composants à trier.
4. Chercher sur internet la complexité de la méthode utilisée. Est-ce que vos tests vous
donnent la même complexité ?
*/

#include <stdio.h>
#define MAXTABSIZE 20

void afficherTableau(int [], int );
void trierParInsertion(int [], int );
int remplirTableau(int [], int *);

int main() {
    int tab[MAXTABSIZE];

    printf("Entrez : \n 1 - Pour remplir le tableau \n 2 - Pour utiliser les banques de tests \n");
    int input;
    
    scanf("%d", &input);
    if (input == 1){
        int longeur;
        int result = remplirTableau(tab, &longeur);
        if (result == 1) // Il y a une erreur dans ce que l'utilisateur à entrer, arret du programme.
            return 1;
        
        trierParInsertion(tab, longeur);
        afficherTableau(tab, longeur);
    }else {
        if (input != 2)
        {
            printf("Entrée incorrecte, passage en mode test");
        }
        // Test 1 : Tableau déjà trié
        int longeur1 = 5;
        int tab1[] = {1, 2, 3, 4, 5};
        printf("\nTest 1 : Tableau déjà trié\n");
        trierParInsertion(tab1, longeur1);
        afficherTableau(tab1, longeur1);

        // Test 2 : Tableau trié à l'envers
        int longeur2 = 5;
        int tab2[] = {5, 4, 3, 2, 1};
        printf("\nTest 2 : Tableau trié à l'envers\n");
        trierParInsertion(tab2, longeur2);
        afficherTableau(tab2, longeur2);

        // Test 3 : Tableau avec des doublons
        int longeur3 = 6;
        int tab3[] = {4, 1, 3, 4, 2, 1};
        printf("\nTest 3 : Tableau avec des doublons\n");
        trierParInsertion(tab3, longeur3);
        afficherTableau(tab3, longeur3);

        // Test 4 : Tableau avec un seul élément
        int longeur4 = 1;
        int tab4[] = {42};
        printf("\nTest 4 : Tableau avec un seul élément\n");
        trierParInsertion(tab4, longeur4);
        afficherTableau(tab4, longeur4);
    }
    
}

// Provient du 1er exercice
int remplirTableau(int tab[], int *pt_l)
{
	printf("Veuillez entrer la taille du tableau \n");
    
    int longeur,nb_error = 0;
    do
    {
        printf("Longeur : ");
        scanf("%d", &longeur);

        if (nb_error >= 2){
            printf("Trop d'échec, arrêt du programme.\n");
            return 1;
        }
        if (longeur < 0)
        {
            printf("Veuillez entrer un nombre positif.\n");
            nb_error+=1;
        }else if(longeur > MAXTABSIZE)
        {
            printf("Veuillez entrer un nombre inférieur a %d.\n", MAXTABSIZE+1);
            nb_error+=1;
        }
        
    } while (longeur < 0 || longeur>MAXTABSIZE);
    
    printf("Vous avez choisi un tableau de longueur : %d", longeur);
    for (int i = 0; i < longeur; i++)
    {
        printf("\nEntrez la valeur du tableau à l'index %d : ", i);
        int v = 0;
        scanf("%d", &v);
        tab[i] = v;
    }

    *pt_l = longeur;

    return 0;
}

// tri un tableau par la methode de tri par insertion
void trierParInsertion(int tab[], int longueur)
{
    for (int i = 1; i < longueur; i++)
    {
        int val = tab[i];
        int j = i-1;
        while (j >= 0 && tab[j] > val)
        {
            tab[j+1] = tab[j];
            j--;
        }

        tab[j+1] = val;

    }
}

// affiche un tableau dans le terminal
void afficherTableau(int _tab[], int longueur)
{
    printf("Affichage du tableau : \n");
    for(int i =0; i<longueur; i++)
    {
        printf("%d : %d \n",i, _tab[i]);
    }
}