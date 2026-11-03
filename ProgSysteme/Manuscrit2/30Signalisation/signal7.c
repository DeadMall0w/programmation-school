#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }

#define AU		64		// SIGRTMAX
#define STOP	59		// SIGRTMAX-5
#define	START	58		// SIGRTMAX-6
#define STATE	48		// IGRTMIN+14

void installGestionSignaux(void);
void installGestionSignalTR(int sigNum, void (*handler)(int, siginfo_t *, void *));
void traiterSignalTR(int sigNum, siginfo_t *, void*);

int main () {
	sigset_t sigAttendus;
	siginfo_t infoRecus;
	int sig;
	
	printf("Je suis le processus %d\n", getpid());
	// Préparation des signaux attendus
	CHECK(sigemptyset(&sigAttendus),"-- sigemptyset --");
	CHECK(sigaddset(&sigAttendus,AU),"-- sigaddset --");
	CHECK(sigaddset(&sigAttendus,STOP),"-- sigaddset --");
	CHECK(sigaddset(&sigAttendus,START),"-- sigaddset --");
	CHECK(sigaddset(&sigAttendus,STATE),"-- sigaddset --");
	CHECK(sigprocmask(SIG_UNBLOCK, &sigAttendus,NULL),"-- sigprocmask --");
	// Installation des traitements pour les signaux attendus
	installGestionSignaux();
	// On attend pour tester
	while (1)  {
		memset(&infoRecus, 0, sizeof(infoRecus));
		CHECK(sig=sigwaitinfo(&sigAttendus, &infoRecus),"-- sigwaitinfo --");
		printf("Signal TR reçu %d (val=%d) :\t", sig, infoRecus.si_int);
		switch (sig) {
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
	}	
	
	printf("==Fin sigWait==\n");
	exit(0);
}
void installGestionSignaux(void) {
	installGestionSignalTR(AU, traiterSignalTR);
	installGestionSignalTR(START, traiterSignalTR);
	installGestionSignalTR(STOP, traiterSignalTR);
	installGestionSignalTR(STATE, traiterSignalTR);
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


