#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }
void installGestionSignaux(void);

int main () {
	installGestionSignaux();
	// On attend pour tester
	alarm(10);
	while (pause()==-1 && errno == EINTR) ;
//	while (1) pause();
	
	printf("Fin alarme\n");
	exit(0);
}
void installGestionSignal(int sigNum, void (*handler)(int));
void traiterSignal(int sigNum);

void installGestionSignaux(void) {
	installGestionSignal(SIGINT, traiterSignal);
	printf("Le ^C est désactivé\n");
	installGestionSignal(SIGUSR1, traiterSignal);
	installGestionSignal(SIGALRM, traiterSignal);
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
	case SIGINT : 
		printf("\tLe ^C est désactivé\n");
		break;
	case SIGUSR1 : 
		printf("USR1 reçu\n");
		break;
	case SIGALRM : 
		printf("Alarme reçue\n");
		break;
	default:
		printf("Signal inconnu, cela ne devrait pas se produire\n");
	} 
}

