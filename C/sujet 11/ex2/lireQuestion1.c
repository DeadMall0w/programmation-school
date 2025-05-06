#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

int main(int argc , char *argv[])
{

    FILE *fic=NULL; 
    FILE *fd=NULL; 
    int NC1=0,NC2=0;
    int som1=0,som2=0;
    char ch[100];

    char name1[100] = "";
    char name2[100] = "";

    char surName1[100] = "";
    char surName2[100] = "";
    
    
    if (argc >= 3){
        strcpy(surName1, argv[1]);
        strcpy(surName2, argv[2]);
    }
  
    
    int flag = 0;
    fic=fopen("resultatsTOUR1.txt","rt");    
    if (fic!=NULL)
    {
  
        do {   fscanf(fic,"%s ", ch);
            if(flag == 10){
                flag = 0;
                som1 += atoi(ch);
            }else if(flag == 20){
                flag = 0;
                som2 += atoi(ch);
            }else if(flag == 1){
                flag = 10;
            }else if(flag == 2){
                flag = 20;
            }


            if(strcmp(surName1, ch) == 0){
                flag = 1;
            }else if (strcmp(surName2, ch) == 0){
                flag = 2;
            }

        }
        while(!feof(fic));
        
        
    system("date > ladate");
    fd=fopen("ladate","r");
    fgets(ch,99,fd);
    fclose(fd);
    printf("\n\n\n>>RAPHAEL, %s ",ch);         //remplacez par votre NOM
    fclose(fic);//fclose(ficint2);
 
    }
    else printf("\n souci ! le fichier resultatsTOUR1.txt est introuvable.");
    
         
         
    printf("\n \t------------>%s = %d  <->  %s = %d\n", surName1, som1, surName2, som2);
    return 0;
}
