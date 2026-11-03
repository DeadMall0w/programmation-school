#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }

void traiterALRM(int);
void installGestionSignaux(void);
int main() {
	printf("PID = %d\n", getpid());
	installGestionSignaux();
	alarm(10) ;
	pause();
	printf("Poursuite du traitement\n");
	while(1);
	return 0;
}

void installGestionSignaux(void) {
	struct sigaction newAct;
	
	newAct.sa_handler = traiterALRM;
	CHECK(sigemptyset(&newAct.sa_mask), "--sigemptyset()--");
	newAct.sa_flags = 0;
	CHECK(sigaction(SIGALRM, &newAct, NULL), "--sigaction()--");
}

void traiterALRM(int sigNum)
{
	printf("Alarme reçue\n");
 
}

