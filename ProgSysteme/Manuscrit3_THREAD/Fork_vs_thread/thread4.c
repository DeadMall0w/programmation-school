#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define NBMAX_THREADS 4
#define DUREE_MAX 5

/* Contrôle systématique du code de retour des primitives pthread :
   elles retournent 0 en cas de succès (errno n'est pas utilisée). */
#define CHECK_T(status, msg) \
    if (0 != (status)) { \
        fprintf(stderr, "pthread erreur : %s\n", msg); \
        exit(EXIT_FAILURE); \
    }

/* Type « pointeur de fonction void *(*)(void *) », signature attendue
   par pthread_create(). Il permet d'écrire monThread avec un en-tête
   simplifié (long no) au lieu de (void *arg). */
typedef void * (*pf_t)(void *);

void *monThread(long no);
void bye(void);

int main(int argc, char *argv[])
{
    pthread_t tid[NBMAX_THREADS]; /* identifiants des threads créés   */
    long *status = NULL;          /* adresse du code de terminaison  */
    long i;

    atexit(bye);                  /* appelé automatiquement par exit() */

    /* Optionnel : pour varier les durées de sommeil à chaque exécution */
    srand((unsigned) time(NULL));

    printf("Le processus %d va créer %d threads\n", getpid(), NBMAX_THREADS);

    /* Création : on transmet le numéro d'ordre PAR VALEUR (i + 1),
       casté en void *. Sur x86-64, un long fait 8 octets, comme un
       pointeur : le cast est donc sans perte. */
    for (i = 0; i < NBMAX_THREADS; i++) {
        CHECK_T(pthread_create(&tid[i], NULL, (pf_t) monThread, (void *) (i + 1)),
                "pthread_create()");
    }

    printf("\tattente de la terminaison des threads\n");

    /* Attente dans l'ORDRE DE CRÉATION : le thread principal se bloque
       sur tid[0] tant que le thread n°1 n'est pas terminé, même si les
       autres se terminent avant lui. */
    for (i = 0; i < NBMAX_THREADS; i++) {
        CHECK_T(pthread_join(tid[i], (void **) &status), "pthread_join()");
        printf("--> fin du thread n°%ld avec le code %ld\n", i + 1, *status);
        free(status);   /* le thread principal libère la zone allouée par le fils */
    }

    return EXIT_SUCCESS;
}

/* Corps des threads : no = numéro d'ordre de création */
void *monThread(long no)
{
    /* Résultat alloué DYNAMIQUEMENT (sur le tas) : seule façon de garantir
       que la valeur survit à la fin du thread.
       - variable locale  -> détruite avec la pile du thread ;
       - variable static  -> partagée par tous les threads (scénario d'erreur
         du cours : un thread lit 26 au lieu de 25). */
    long *resultat = malloc(sizeof(long));
    if (resultat == NULL) {
        fprintf(stderr, "thread n°%ld : erreur d'allocation\n", no);
        return NULL;
    }
    *resultat = no;   /* le code de terminaison = le numéro d'ordre */

    printf("Début du thread n°%ld\n", no);
    sleep(rand() % DUREE_MAX + 1);   /* durée tirée dans [1, DUREE_MAX] */
    printf("Fin du thread n°%ld\n", no);

    /* On retourne l'ADRESSE de la zone : pthread_join() la rangera dans
       la variable status du thread principal. */
    return (void *) resultat;
}

void bye(void)
{
    printf("Fin du processus %d\n", getpid());
}