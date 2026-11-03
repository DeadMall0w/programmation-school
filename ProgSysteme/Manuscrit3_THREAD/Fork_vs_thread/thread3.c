#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define NBMAX_THREADS 4
#define DUREE_MAX 5

#define CHECK_T(status, msg) \
    if (0 != (status)) { \
        fprintf(stderr, "pthread erreur : %s\n", msg); \
        exit(EXIT_FAILURE); \
    }

/* Signature attendue par pthread_create() ; permet d'écrire monThread
   avec l'en-tête simplifié void *monThread(long no) */
typedef void * (*pf_t)(void *);

void *monThread(long no);
void bye(void);

int main(int argc, char *argv[])
{
    pthread_t tid[NBMAX_THREADS];   /* locale à main : plus de variable globale */
    long i;

    atexit(bye);
    srand((unsigned) time(NULL));

    printf("Le processus %d va créer %d threads\n", getpid(), NBMAX_THREADS);

    /* Numéro d'ordre transmis PAR VALEUR (i + 1), casté en void * :
       long (8 octets) = taille d'un pointeur sur x86-64 */
    for (i = 0; i < NBMAX_THREADS; i++) {
        CHECK_T(pthread_create(&tid[i], NULL, (pf_t) monThread, (void *) (i + 1)),
                "pthread_create()");
    }

    printf("\tattente de la terminaison des threads\n");

    /* Attente dans l'ordre de création ; code de terminaison IGNORÉ (NULL) */
    for (i = 0; i < NBMAX_THREADS; i++) {
        CHECK_T(pthread_join(tid[i], NULL), "pthread_join()");
    }

    return EXIT_SUCCESS;
}

void *monThread(long no)
{
    printf("Début du thread n°%ld\n", no);
    sleep(rand() % DUREE_MAX + 1);   /* durée tirée dans [1, DUREE_MAX] */
    printf("Fin du thread n°%ld\n", no);
    return NULL;   /* pas encore de code de terminaison transmis */
}

void bye(void)
{
    printf("Fin du processus %d\n", getpid());
}