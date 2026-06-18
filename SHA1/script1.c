#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    const char *default_path = "/etc/passwd";
    const char *filepath = (argc > 1) ? argv[1] : default_path;

    // Afficher UID réel
    uid_t ruid = getuid();
    printf("UID réel: %d\n", ruid);

    // Afficher UID effectif
    uid_t euid = geteuid();
    printf("UID effectif: %d\n", euid);

    // Afficher les noms correspondants
    struct passwd *pw_real = getpwuid(ruid);
    struct passwd *pw_effective = getpwuid(euid);
    printf("Nom réel: %s\n", pw_real ? pw_real->pw_name : "inconnu");
    printf("Nom effectif: %s\n", pw_effective ? pw_effective->pw_name : "inconnu");

    // Ouvrir le fichier en lecture
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier '%s': %s\n", filepath, strerror(errno));
        return 1;
    }

    // Afficher la première ligne du fichier
    char line[1024];
    if (fgets(line, sizeof(line), fp)) {
        printf("Première ligne: %s", line);
    } else {
        printf("Impossible de lire la première ligne.\n");
    }

    fclose(fp);
    return 0;
}
/*
Lire un arguement en ligne de commande du fichier à afficher (prévoir un chemin par défaut)

Afficher UID rel getuid()
Afficher ui effectif geteuid()
affficher les nom correpondant getpwuid

ouvir le fichier en lecture (en vérifiant qu'on a les droits)
Afficher la premiere ligne du fichier 
*/
//TODO : 