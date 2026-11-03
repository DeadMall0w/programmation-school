#include "libSignal.h"
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef CHECK
#define CHECK(sts, msg)                                                        \
  if ((sts) == -1) {                                                           \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  }
#endif

void installSignal(int numSig, void (*handler)(int), int flags) {
  struct sigaction newAct;
  newAct.sa_handler = handler;
  newAct.sa_flags = flags;
  CHECK(sigemptyset(&newAct.sa_mask), "--sigemptyset--");
  CHECK(sigaction(numSig, &newAct, NULL), "--sigaction--");
}

/*
Traitement:
        -Déclarer une variable de type Va_list    /   Va_list pArg;
        -positionner la variable sur le début des paramétres variables  /
Va_list(param,pArg); -avancer paramétre par paramétre  / Va_arg(pArg, <type
param>);
        - libérer la ressource / va_end(pArg);

        -généralement, l'argument avant les ... designe le nb de parametre (le +
simple) -autre possibilité courante, on utilise NULL comme dernier paramétre

        ex de fprintf: utilise un format ou chaque % désigne un paramétre

        /**
           *\fn	  void debloquerSignaux(int nbSig, ...);

        **/

void debloquerSignaux(int nbSig, ...) {
  sigset_t mask;
  va_list pArg;
  va_start(pArg, nbSig);
  CHECK(sigemptyset(&mask), "--sigemptyset--");
  for (int i = 0; i < nbSig; i++) {
    CHECK(sigaddset(&mask, va_arg(pArg, int)), "--sigaddset--");
  }
  CHECK(sigprocmask(SIG_UNBLOCK, &mask, NULL), "--sigprocmask--");
  va_end(pArg);
}

void installSignaux(void (*handler)(int), int flags, int nbSig, ...) {
  va_list pArg;
  va_start(pArg, nbSig);
  for (int i = 0; i < nbSig; i++) {
    int numSig = va_arg(pArg, int);
    installSignal(numSig, handler, flags);
  }
  va_end(pArg);
}

void bloquerTousSignaux(void) {
  sigset_t mask;
  CHECK(sigfillset(&mask), "--sigfillset--");
  CHECK(sigprocmask(SIG_BLOCK, &mask, NULL), "--sigprocmask--");
}

void installSIGCHLD(void) {
  installSignal(SIGCHLD, traiterSIGCHLD, SA_RESTART);
}

void traiterSIGCHLD(int sig) {
  (void)sig;
  while (waitpid(-1, NULL, WNOHANG) > 0)
    ;
}

/*
        - ecrire la fct void bloquerTousSignaux(void);
        - ecrire la fct void installSIGCHLD(void);
        - ecrire la fct void traiterSIGCHLD(void)
        */

void traiterSIGINT(int sig) {
  (void)sig;
  printf("\n[SIGINT] Signal ^C reçu : fermeture du programme via exit().\n");
  exit(EXIT_SUCCESS);
}

int main(void) {
  bloquerTousSignaux();
  installSignal(SIGINT, traiterSIGINT, 0);
  debloquerSignaux(1, SIGINT);
  printf("Tous les signaux sont bloqués sauf ^C (SIGINT).\n");
  printf("Attente pendant 60 secondes\n");
  for (int i = 1; i <= 60; i++) {
    printf("Seconde : %d / 60\n", i);
    sleep(1);
  }
  printf("Fin de la période d'attente de 60 secondes.\n");
  return 0;
}
