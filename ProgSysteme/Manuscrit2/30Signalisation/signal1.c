#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }
int main () {
	sigset_t intmask;

	// Initialise et affecte le masque
	CHECK(sigemptyset(&intmask), "appel de sigemptyset");
	CHECK(sigaddset(&intmask, SIGINT), "appel de sigaddset");
	// On interdit le control-C
	CHECK(sigprocmask(SIG_BLOCK, &intmask, NULL), "appel de sigprocmask");
	printf("Le ^C est bloqué\n");
	// On attend pour tester
	alarm(10);
	pause();
	printf("Fin alarme\n");
	exit(0);
}
	//CHECK(sigaddset(&intmask, SIGALRM), "appel de sigaddset");

