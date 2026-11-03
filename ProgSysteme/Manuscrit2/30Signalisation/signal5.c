#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define TIMEOUT 10
#define CHECK(sts , msg) if (-1 == (sts)) {\
	perror (msg);\
	exit( EXIT_FAILURE );\
	}
static void signalHandler (int);
int timeout = 0;

int main (int argc , char *argv [])
{
	struct sigaction newAction ;
	pid_t pidFils ;
	if (argc > 1) {
		timeout = atoi(argv [1]);
		}
	if ( timeout <= 0)
		timeout = TIMEOUT ;
		
	printf ("Le Ctrl -c est désactivé pendant %d s.\n\n", timeout );
	/* Initialisation de la structure sigaction */
	newAction . sa_handler = signalHandler ;
	CHECK ( sigemptyset (& newAction . sa_mask ), " sigemptyset ()");
	newAction . sa_flags = 0;
	/* Installation du gestionnaire du signal SIGINT */
	CHECK ( sigaction (SIGINT , &newAction , NULL), " sigaction ()");
	CHECK ( sigaction (SIGALRM , &newAction , NULL), " sigaction ()");
	
	
	CHECK(pidFils = fork (), "Échec de la création d'un processus fils");
	if ( pidFils == 0) {
		/* On met ici le code spécifique du processus fils */
		CHECK ( alarm (1) , " alarm ()");
		while ( pause () == -1 && errno == EINTR );
		exit (0); /* Fin normale du fils */
	}
	/* On met ici la suite du code du processus père */
	printf ("Je suis le père du processus ...... n°%d\n", pidFils );
	exit( EXIT_SUCCESS );
}
static void signalHandler (int numSig )
{
	switch ( numSig ) {
		case SIGINT :
		/* traitement de SIGINT */
			printf ("\tLe Ctrl -c est désactivé pendant %d s.\n", timeout );
			break ;
		case SIGALRM :
		/* traitement de SIGALRM */
			timeout --;
			if ( timeout <= 0) {
				struct sigaction newAction ;
				/* Initialisation de la structure sigaction */
				newAction . sa_handler = SIG_DFL ; /* gestionnaire par défaut */
				CHECK ( sigemptyset (& newAction . sa_mask ), " sigemptyset ()");
				newAction . sa_flags = 0;
				/* Installation du gestionnaire par défaut */
				CHECK ( sigaction (SIGINT , &newAction , NULL), " sigaction ()");
				printf ("Le traitement normal du Ctr -c est réactivé \n");
			}
			else
				CHECK ( alarm (1) , " alarm ()");
			break ;
		default :
			printf (" Signal %d non traité \n", numSig );
		break ;
		}
}		
