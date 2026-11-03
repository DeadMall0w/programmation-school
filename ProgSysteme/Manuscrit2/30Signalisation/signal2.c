#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }
int main () {
	struct sigaction newAct;
	
	// Préparation de structure newAct
	newAct.sa_handler = SIG_IGN;
	CHECK(sigemptyset(&newAct.sa_mask), "--sigemptyset()--");
	newAct.sa_flags = 0;
	// Application de newAct pour SIGINT	
	CHECK(sigaction(SIGINT, &newAct, NULL), "--sigaction()--");
	printf("Le ^C sera reçu mais ignoré\n");
	// On attend pour tester
	alarm(10);
	pause();
	printf("Fin alarme\n");
	exit(0);
}
