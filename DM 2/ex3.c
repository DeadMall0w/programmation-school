/*
1. Développer un programme qui permet de trier un tableau monodimensionnel par la
méthode du tri sélection. Cette méthode pourra être testée à l’aide du programme de
l’exercice 1 qui sera adapté.
2. Faire un jeu d’essai pour prouver le bon fonctionnement de votre programme.
3. Adapter votre programme à l’aide du code donné par l’enseignant. Ce code vous
permet de générer de manière aléatoire des tableaux de grandes tailles et calculer la
durée de tri. Faire des jeux d’essais pour illustrer le bon fonctionnement de votre
programme et évaluer la complexité de la méthode. On tracera la courbe durée de la
méthode de tri en fonction nombre de composants à trier.
4. Chercher sur internet la complexité de la méthode utilisée. Est-ce que vos tests vous
donnent la même complexité ?
*/
#include <stdio.h>

#define MAXTABSIZE 10000

void afficherTableau(int [], int );
void trierParSelection(int [], int );
int trouverPlusPetiteValeur(int [], int, int);
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
        
        trierParSelection(tab, longeur);
        afficherTableau(tab, longeur);
    }else {
        if (input != 2)
        {
            printf("Entrée incorrecte, passage en mode test");
        }
        // tests
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

// trie un tableau de longueur donnée
void trierParSelection(int tab[], int longueur)
{
    for (int i = 0; i < longueur; i++)
    {
        int minIndex = trouverPlusPetiteValeur(tab, i, longueur);

        int temp = tab[minIndex];
        tab[minIndex] = tab[i];
        tab[i] = temp;
    }
}

// Trouve la plus petite valeur dans l'interval [debut; fin] dans un tableau.
int trouverPlusPetiteValeur(int tab[], int debut, int fin)
{
    int minIndex = debut;
    int minValeur = tab[debut];

    for (int i = debut; i < fin; i++)
    {
        if (tab[i] < minValeur)
        {
            minValeur = tab[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

// afficher toutes les lignes du tableau dans le terminal
void afficherTableau(int _tab[], int longueur)
{
    printf("Affichage du tableau : \n");
    for(int i = 0; i < longueur; i++)
    {
        printf("%d : %d \n",i, _tab[i]);
    }
}