#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLEN 8
#define PASSWORD "essai"
pid_t pidFils = 0;
int delai = 30; // vvaleurs par défaut
int nb_essais = 3;

// gestion de l'alarme
void handler_pere_sigalrm(int sig) {
    if (pidFils > 0) {
        kill(pidFils, SIGUSR2);
    }
}

// gestion du ctrl C
void handler_fils_sigint(int sig) {
    printf("\n[%d] --> Le Ctrl-c est désactivé.\n", getpid());
}

int main(int argc, char *argv[]) {
    if (argc > 1) delai = atoi(argv[1]);
    if (argc > 2) nb_essais = atoi(argv[2]);

    printf("Vous avez %d secondes pour entrer votre mot de passe\n", delai);

    sigset_t masque;
    sigemptyset(&masque);
    sigaddset(&masque, SIGINT);
    
    // bloquer le ctrl+C
    sigprocmask(SIG_BLOCK, &masque, NULL); 

    // maque pour le fils
    struct sigaction actionInt;
    actionInt.sa_handler = handler_fils_sigint;
    sigemptyset(&actionInt.sa_mask);
    actionInt.sa_flags = SA_RESTART;
    sigaction(SIGINT, &actionInt, NULL);

    // masque du père
    struct sigaction actionAlarme;
    actionAlarme.sa_handler = handler_pere_sigalrm;
    sigemptyset(&actionAlarme.sa_mask);
    actionAlarme.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &actionAlarme, NULL);


    pidFils = fork();

    if (pidFils == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pidFils == 0) { /// enfant
        sigprocmask(SIG_UNBLOCK, &masque, NULL); 
        
        // masques
        sigset_t masqueFils;
        sigemptyset(&masqueFils);
        sigaddset(&masqueFils, SIGALRM);
        sigprocmask(SIG_BLOCK, &masqueFils, NULL);

        int tentatives = 0;
        char mdp[MAXLEN + 1];
        char *p;

        printf("Vous avez %d essais pour entrer votre mot de passe, et une durée limitée\n", nb_essais);

        while (tentatives < nb_essais) {
            // Logique d'affichage simplifiée
            printf("essai n %d: ", tentatives);
            
            fflush(stdout);

            if (fgets(mdp, sizeof(mdp), stdin) != NULL) {
                if ((p = strchr(mdp, '\n')) != NULL) {
                    *p = '\0';
                } else {
                    while (getchar() != '\n'); 
                }

                if (strcmp(mdp, PASSWORD) == 0) { // mdp identique
                    exit(0);
                }
            }
            tentatives++;
        }
        exit(tentatives);

    } else {

        alarm(delai); // lancement chrono
        
        int status;
        wait(&status); // pause jusqu'a un retour du filss
        alarm(0); // on désactive l'alarme dans le cas ou le fils nous renvoie la bonne réponse

        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            printf("Terminaison du processus %d\n", pidFils);
            printf("[%d] Fin du processus père\n", getpid());
            
            // Vérification s'il avait rentrée le bon code
            if (code == 0) { 
                printf("Mot de passe valide connexion acceptée\n");
            } else {
                printf("Échec des %d tentatives connexion refusée\n", code);
            }
        } 
        else if (WIFSIGNALED(status)) { // processus fil coupé, alarme a sonnée
            if (WTERMSIG(status) == SIGUSR2) {
                printf("Terminaison du processus %d Délai expiré\n", pidFils);
                printf("[%d] Fin du processus père\n", getpid());
                printf("connexion refusée\n");
            }
        }
    }
    return 0;
}