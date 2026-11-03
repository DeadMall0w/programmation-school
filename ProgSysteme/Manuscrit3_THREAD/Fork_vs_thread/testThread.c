/* ------------------------------------------------------------------------- */
/*	test_thread.c                                                            */
/*	Test de création de threads												 */
/* ------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_THREADS 50000

void *neRienFaire(void *null)
{
    int i;
    i=0;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int status, i;
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NB_THREADS; i++) {
        status = pthread_create(&tid, &attr, neRienFaire, NULL);
        if (status != 0) {
            printf("ERREUR %d sur pthread_create()\n", status);
            exit(EXIT_FAILURE);
        }

        /* Attendre la terminaison du thread */
        status = pthread_join(tid, NULL);
        if (status != 0) {
            printf("ERREUR %d sur pthread_join()\n", status);
            exit(EXIT_FAILURE);
        }
    }

    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

