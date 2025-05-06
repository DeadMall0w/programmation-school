#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define MAX_CANDIDAT 12 // on suppose qu'il y a au max 20 candidats
#define MAX_STR 100


const char* candidats[] = { // dans l'ordre trouvé dans le tableur
    "ARTHAUD",
    "ROUSSEL",
    "MACRON",
    "LASSALLE",
    "LE_PEN",
    "ZEMMOUR",
    "MELENCHON",
    "HIDALGO",
    "JADOT",
    "PECRESSE",
    "POUTOU",
    "DUPONT-AIGNAN"
};
int nbVoix[MAX_CANDIDAT];


int trouver_position(const char* nom) {
    for (int i = 0; i < MAX_CANDIDAT; i++) {
        if (strcmp(candidats[i], nom) == 0) {
            return i;
        }
    }
    return -1; // Nom non trouvé
}


int main(int argc , char *argv[])
{

    FILE *fic=NULL; 
    FILE *fd=NULL; 
    char ch[MAX_STR];

    char ville[MAX_STR] = "Lens"; // par défaut c'est Lens comme ville

    
    
    if (argc >= 2){
        strcpy(ville, argv[1]);
    }else{
        printf("AUCUNE NOM DE VILLE INDIQUE : utilisation de la ville de Lens \n");
    }
  
    int r = 0;

    int pos = 0;
    fic=fopen("resultatsTOUR1.txt","rt");    
    if (fic!=NULL)
    {
  
        do {   fscanf(fic,"%s ", ch);
            if (strcmp(ch, ville) == 0) { // on vient de trouver la ville !!
                
                for (r = 0; r < 15; r++)
                {
                    fscanf(fic,"%s ", ch); // à ignorer
                }

                for (int n = 0; n < MAX_CANDIDAT; n++)
                {
                    
                    for (int r = 0; r < 7; r++)
                    {
                        if (r == 3)
                            pos = trouver_position(ch);

                        

                        if (r == 5)
                            nbVoix[pos] += atoi(ch);
                        
                        
                            

                        fscanf(fic,"%s ", ch);
                    }

                }
                
            }

        }
        while(!feof(fic));
        
        
    system("date > ladate");
    fd=fopen("ladate","r");
    fgets(ch,99,fd);
    fclose(fd);
    printf("\n\n\n>>RAPHAEL, %s ",ch);
    fclose(fic);
 
    }
    else printf("\n souci ! le fichier resultatsTOUR1.txt est introuvable.");
    
    for (int j = 0; j < MAX_CANDIDAT; j++)
    {
        printf("\t -------> %s = %d \n", candidats[j], nbVoix[j]);
    }
    
    
    return 0;
}
