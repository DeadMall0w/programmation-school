#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
int main(void) {
    pid_t pidFils;
    int status;
    pidFils = fork();
    if (pidFils == -1) {
        perror("Échec de fork");
        exit(EXIT_FAILURE);
    }

    if (pidFils == 0) {
        // CODe lorsque c'est l'enfant qui execute
        printf("Je suis le processus n°%d\n", getpid());
        printf("Mon père est le processus n°%d\n", getppid());
        char *argv[12];
        argv[0] = "./testExecve";
        argv[11] = NULL; // marquage de fin de tableau
        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            int val = rand() % 21;
            argv[i + 1] = malloc(3 * sizeof(char));

            sprintf(argv[i + 1], "%d", val);
        }
            // Execution du code
            execve("./testExecve", argv, NULL);
        } else {
            // Code lorsque c'est le parent qui execute
            printf("Je suis le processus n°%d\n", getpid());
            printf("Mon père est le processus n°%d\n", getppid());
            printf("Je suis le père du processus n°%d\n", pidFils);
            // Le père attend que le fils se termine et récupère la somme via la valeur retourné lors de la fin du programme
            wait(&status);
        if (WIFEXITED(status)) {
            printf("Code de terminaison du processus n°%d : %d\n", pidFils,
            WEXITSTATUS(status));
        }
    }
    return 0;
}
