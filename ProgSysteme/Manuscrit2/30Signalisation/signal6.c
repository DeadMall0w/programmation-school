#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }

#define AU		64		// SIGRTMAX
#define STOP	59		// SIGRTMAX-5
#define	START	58		// SIGRTMAX-6
#define STATE	48		// IGRTMIN+14

void installGestionSignaux(void);
void installGestionSignal(int sigNum, void (*handler)(int));
void traiterSignal(int sigNum);
void installGestionSignalTR(int sigNum, void (*handler)(int, siginfo_t *, void *));
void traiterSignalTR(int sigNum, siginfo_t *, void*);

int duree=10;
int main () {
	printf("Je suis le processus %d\n", getpid());
	installGestionSignaux();
	// On attend pour tester
	alarm(1);
	while (1) pause();
	
	printf("Fin alarme\n");
	exit(0);
}

void installGestionSignaux(void) {
	installGestionSignal(SIGINT, traiterSignal);
	printf("Le ^C est désactivé pendant %ds\n",duree);
	installGestionSignal(SIGUSR1, traiterSignal);
	installGestionSignal(SIGALRM, traiterSignal);
//	installGestionSignal(AU, traiterSignal);
	installGestionSignalTR(AU, traiterSignalTR);
}
void installGestionSignal(int sigNum, void (*handler)(int)) {
	struct sigaction newAct;
	
	newAct.sa_handler = handler;
	CHECK(sigemptyset(&newAct.sa_mask), "--sigemptyset()--");
	newAct.sa_flags = 0;
	CHECK(sigaction(sigNum, &newAct, NULL), "--sigaction()--");
}
void traiterSignal(int sigNum)
{
	switch (sigNum) {
	case AU : 
		printf("AU\n");
		break;
	case SIGINT : 
		printf("\tLe ^C est désactivé pendant %ds\n",duree);
		break;
	case SIGUSR1 : 
		printf("USR1 reçu\n");
		break;
	case SIGALRM : 
		duree--;
		if (duree > 0) alarm(1);
		else {
			installGestionSignal(SIGINT, SIG_DFL);
			printf("\tLe ^C est réactivé\n");
		}
		break;
	default:
		printf("Signal inconnu, cela ne devrait pas se produire\n");
	} 
}
void installGestionSignalTR(int sigNum, void (*handler)(int, siginfo_t *, void *)) {
	struct sigaction newAct;
	
	newAct.sa_sigaction = handler;
	CHECK(sigemptyset(&newAct.sa_mask), "--sigemptyset()--");
	newAct.sa_flags = SA_SIGINFO;
	CHECK(sigaction(sigNum, &newAct, NULL), "--sigaction()--");
}
void traiterSignalTR(int sigNum, siginfo_t * sigInfo, void* rien)
{
	switch (sigNum) {
	case AU : 
		printf("AU\n");
		break;
	case STOP : 
		printf("STOP\n");
		break;
	case START : 
		printf("START\n");
		break;
	case STATE : 
		printf("STATE\n");
		break;
	default:
		printf("Signal inconnu, cela ne devrait pas se produire\n");
	} 
	printf("\tNum sig = %d, Valeur = %d\n", sigInfo->si_signo,sigInfo->si_int); 
}

