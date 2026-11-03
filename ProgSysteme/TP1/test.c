#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h> // pour la fonction 'pause()'

// Constantes
#define NB_PHILOSOPHE 5

// *************** Macro fonctions
/* Contrôle systématique du code de retour des primitives pthread :
   elles retournent 0 en cas de succès (errno n'est pas utilisée). */
#define CHECK_T(status, msg) \
    if (0 != (status)) { \
        fprintf(stderr, "pthread erreur : %s\n", msg); \
        exit(EXIT_FAILURE); \
    }

#define CHECK(sts, msg) \
    if (0 != (sts)) { \
        fprintf(stderr, "pthread erreur : %s\n", msg); \
        exit(EXIT_FAILURE); \
    }

#define CHECK_ZERO(sts, msg)\
    if (0 != (sts)) { \
        fprintf(stderr, "pthread erreur : %s\n", msg); \
        exit(EXIT_FAILURE); \
    }

#define VD(i) (i==NB_PHILOSOPHE-1)?0:(i)+1
#define VG(i) (i==0)?NB_PHILOSOPHE-1:(i)-1

// en µs
#define TEMPO_MIN_P 2000
#define TEMPO_MAX_P 6000


#define TEMPO_MIN_M 1000
#define TEMPO_MAX_M 2000


typedef enum{A, M, P} etat_t;
typedef void* (pFcxTrhead) (void*);

// Notre mémoire partagée
etat_t tabEtats[NB_PHILOSOPHE] = {P}; // si on ne veut pas initaliser les deux premiers : {,,P}

// Pour le transitoire on va utiliser un mutex
sem_t mutex;
sem_t SP[NB_PHILOSOPHE]; // sémaphore privée d'autorisation

// **** prototypes de fonctions
void Penser(void);
void Manger(void);

void* ThreadPhilo(void* arg);
void AfficherEtats(void);
void ModifierEtat(int no, etat_t nouvEtat);
void Tester(int m);
void bye(void);


void* ThreadPhilo(void* arg){
    long no = *(long*)arg;
    while (1){
        Penser();
        CHECK(sem_wait(&mutex), "");
            ModifierEtat(no, A);
            Tester(no);
        CHECK(sem_post(&mutex), "");
        CHECK(sem_wait(&SP[no]), "");
        Manger();
        CHECK(sem_wait(&mutex), "");
            ModifierEtat(no, P);
            Tester(VD(no));
            Tester(VG(no));
        CHECK(sem_post(&mutex), "...");
    }
    return NULL;
}

void AfficherEtats(void){
    for (int i = 0; i < NB_PHILOSOPHE; i++) {
        switch (tabEtats[i]) {
            case A: printf("A "); break;
            case M: printf("M "); break;
            case P: printf("P "); break;
        }
    }
    printf("\n"); 
}

void ModifierEtat(int no, etat_t nouvEtat){
    tabEtats[no] = nouvEtat;
    AfficherEtats();
}

void Tester(int m){
    if (tabEtats[m] == A && tabEtats[VG(m)] != M && tabEtats[VD(m)] != M){
        ModifierEtat(m, M);
        CHECK(sem_post(&SP[m]), "....");
    }
}

void Penser(void){
    usleep(TEMPO_MIN_P + (rand()+1) %TEMPO_MAX_P);
}

void Manger(void){
    usleep(TEMPO_MIN_M + (rand()+1) %TEMPO_MAX_M);
}



int main(){
    // bloquer tous les signaux, débloque ctrl+c
    atexit(bye);
    AfficherEtats();
    CHECK(sem_init(&mutex, 0, 1), "...");
    for (int i = 0; i < NB_PHILOSOPHE; i++)
        CHECK(sem_init(&SP[i], 0, 0), "...");
    
    pthread_t tid[NB_PHILOSOPHE];
    long numeros[NB_PHILOSOPHE];
    for (long i = 0; i < NB_PHILOSOPHE; i++) {
        numeros[i] = i;
        CHECK_ZERO(pthread_create(&tid[i], NULL, ThreadPhilo, &numeros[i]), "...");
        CHECK_ZERO(pthread_detach(tid[i]), "...");
    }

    while (1)
        pause();
    return 0;
    
}


void bye(void){
    sem_destroy(&mutex);
    for(int i = 0; i < NB_PHILOSOPHE; i++)
        sem_destroy(&SP[i]);

    printf("Fin du repas \n");
}
