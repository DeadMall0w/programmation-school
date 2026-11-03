#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }
void installDeroute(int numSig, void (*pfct)(int));
void deroute(int numSig);
int duree = 10;
int main (int c, char **v) {
	int pidFils; int status;
	if (c>1) duree=atoi(v[1]);
//	installDeroute(SIGINT, deroute);
	printf("[PID=%d] Le ^C est désactivé pendant [%d]\n", getpid(), duree);
	// On installe le déroutement (traitement de signal) pour alarme
	installDeroute(SIGALRM, deroute);
	// Créer un fils
	CHECK(pidFils=fork(),"-- fork() --");
	if (pidFils == 0) {
		// On installe le gestionnaire de SIGINT
		installDeroute(SIGINT, deroute);
		alarm(1);
		while (pause()==-1 && errno == EINTR) ;
		exit(10);
	}
	printf("Un processus Fils a été créé [PID=%d]\n", pidFils);
	// On installe le gestionnaire de SIGINT avec SIG_IGN
	installDeroute(SIGINT, SIG_IGN);
	CHECK(wait(&status),"-- wait()--");
	
	if (WIFEXITED(status)) 
		printf ("Le fils s'est terminé avec la valeur %d\n", WEXITSTATUS(status));
	if (WIFSIGNALED(status)) 
		printf ("Le fils s'est terminé avec le signal %d\n", WTERMSIG(status));
	printf("Fin du père & du fils\n");
	exit(0);
}
void installDeroute(int numSig, void (*pfct)(int)) {
	struct sigaction newAct;
	// renseigner l'action newAct pour numSig
	newAct.sa_handler = pfct;
	CHECK(sigemptyset (&newAct.sa_mask),"-- sigemptyset() --");
	newAct.sa_flags = SA_RESTART;
	// On installe le gestionnaire
	CHECK(sigaction (numSig, &newAct, NULL),"-- sigaction() --");
}
void deroute(int numSig)
{
	switch (numSig) {
		case SIGINT : 
			printf("\t[PID=%d] Le ^C est désactivé pendant [%d]\n", getpid(), duree);
			break;
		case SIGALRM : 
			duree--;
			if (duree>0) alarm(1);
			else {
				installDeroute(SIGINT, SIG_DFL);
				printf("[PID=%d] Le ^C est réactivé depuis maintenant\n", getpid());
				}
			break;
		default :
		printf("Incrédible\n");
	}
	
}

