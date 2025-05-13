#include <stdio.h>
#include <string.h>

#define MAX 50

// Déclaration de l'enum AVANT tout usage
typedef enum {
    CHAR_DIGIT, // 0
    CHAR_SIGN,  // 1
    CHAR_EXPONENT, // 2
    CHAR_OTHER, // 3
    CHAR_POINT // 4
} CharType;

// Prototypes
char computeAEFD(void);
CharType classify_char(char c);

// Variables globales
char etat = 0;
char input[MAX] = "";

//          digit  +/−   E/e  autre
char matrix[100][5] = {
    {2, 1, 10, 10, 6}, // etat 0
    {2, 10, 10, 10, 6}, // etat 1
    {2, 10, 3, 10, 6}, // etat 2
    {5, 4, 10, 10, 10}, // etat 3
    {5, 10, 10, 10, 10}, // etat 4
    {5, 10, 10, 10, 10}, // etat 5
    {7, 10, 10, 10, 10}, // etat 6
    {7, 10, 3, 10, 10} // etat 7
};

// Fonction de classification
CharType classify_char(char c) {
    if (c >= '0' && c <= '9') {
        return CHAR_DIGIT;
    } else if (c == '+' || c == '-') {
        return CHAR_SIGN;
    } else if (c == 'E' || c == 'e') {
        return CHAR_EXPONENT;
    }else if (c == '.'){
        return CHAR_POINT;
    } else {
        return CHAR_OTHER;
    }
}

// Fonction principale
int main(void) {

    while (1){

        printf("Chaine : ");
        fgets(input, MAX, stdin);
        
        // Enlève le \n final si présent
        input[strcspn(input, "\n")] = '\0';
        
        if (computeAEFD()) {
            printf("C'est bien un nombre flottant !\n");
        } else {
            printf("Ce n'est pas un nombre flottant !\n");
        }
        
    }
    return 0;
}
    
    // Lecture de l'automate
    char computeAEFD(void) {
    int i = 0;
    etat = 0;

    while (input[i] != '\0') {
        CharType type = classify_char(input[i]);

        // printf("'%c' - type %d, etat %d -> \n", input[i], type, etat);

        etat = matrix[etat][type];

        // printf("nv etat :  %d\n\n", etat);
        printf("etat :  %d\n", etat);


        if (etat == 10) {
            return 0; // état d'erreur
        }

        i++;
    }

    // Exemple : tu devras ajuster selon les états finaux de ton automate
    return (etat == 2 || etat == 5 || etat == 7); // par exemple
}
