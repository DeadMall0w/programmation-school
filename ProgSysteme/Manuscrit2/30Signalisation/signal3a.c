#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }

static void signalHandler (int numSig);

int main () {
	struct sigaction newAct;
	
	// Préparation de structure newAct
	newAct.sa_handler = signalHandler;
	CHECK(sigemptyset(&newAct.sa_mask), "--sigemptyset()--");
	newAct.sa_flags = SA_RESTART;
	// Application de newAct pour SIGINT	
	CHECK(sigaction(SIGINT, &newAct, NULL), "--sigaction()--");
	// On attend pour tester
	alarm(10);
	while (pause()==-1 && errno==EINTR);
//	pause();
	printf("Fin alarme\n");
	exit(0);
}

static void signalHandler (int numSig)
{
	switch ( numSig )
	{
		case SIGINT:
			printf (" ^C reçu mais désactivé\n");	break ;
	}
}
