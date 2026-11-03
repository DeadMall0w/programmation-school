#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#define CHECK(sts,msg) if ((sts) == -1) { perror(msg); exit(-1); }
#include <sys/types.h>
#include <sys/wait.h>

void installGestionSignaux(void);
void installGestionSignal(int sigNum, void (*handler)(int));
void traiterSignal(int sigNum);

int duree=10;
int main () {
	pid_t pidFils; int status;

	printf("Je suis le processus %d\n", getpid());
	// le père bloque le ^C
	installGestionSignal(SIGINT, SIG_IGN);
	printf("Le ^C est ignoré par le processus père\n");
	// Créer un fils
	CHECK(pidFils=fork(),"-- fork() --");

	if (pidFils == 0) {
		installGestionSignaux();
		alarm(1);
		while (pause()==-1 && errno == EINTR) ;
		exit(10);
	}
	printf("J'ai créé un fils de PID %d\n",pidFils);
	CHECK(wait(&status),"-- wait()--");
	
	if (WIFEXITED(status)) 
		printf ("Le fils s'est terminé avec la valeur %d\n", WEXITSTATUS(status));
	if (WIFSIGNALED(status)) 
		printf ("Le fils s'est terminé avec le signal %d\n", WTERMSIG(status));
	printf("Fin du père & du fils\n");
	return 0;
}

void installGestionSignaux(void) {
	installGestionSignal(SIGINT, traiterSignal);
	printf("Le ^C est désactivé pendant %ds\n",duree);
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
		printf("\tLe ^C est désactivé pendant %ds\n",duree);
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

