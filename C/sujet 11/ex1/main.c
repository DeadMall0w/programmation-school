#include <stdio.h>



#define MAX_SIZE 1000
long int sum;
int main() {

    FILE *file;
    int buffer[MAX_SIZE];


    for (int i = 0; i < MAX_SIZE; i++) {
        buffer[i] = 0;
    }


    // Open the binary file for reading
    file = fopen("enigmaBERQUIER", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    size_t n = fread(buffer, sizeof(int), MAX_SIZE, file);
    fclose(file);
    
    printf("Q1 - Il y a %zu entiers.\n", n);


    for (int v = 0; v < n; v += 2) {
        sum += buffer[v];
    }


    printf("Q2 - somme : %ld \n", sum);

    char lettres[6] = {0}; // 5 lettres + \0
    int r = 0;

    for (int i = 1; i < n && r < 5; i += 2) { // i = 1,3,5,7,9 (rang pair)
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            lettres[r] = buffer[i];
            r++;
        }
    }

    printf("Q3 - Lettres : %s\n", lettres);


    return 0;
}

/*
Résultat : 
Q1 - Il y a 607 entiers.
Q2 - somme : 23731 
Q3 - Lettres : KCFAF

*/