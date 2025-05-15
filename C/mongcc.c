#include <stdio.h>
#include <string.h>

#define MAX 100
#define PUIT 20
typedef char T_chaine[MAX];



// ************************* tABLES DES TRANSITIONS issues de l'AEFD  ***********************************
//labels des colonnes :     chiffre   +|-    .     e|E      autres 	
int transitions_reel[9][5]={
		/*from 0*/	  {2,1,3,20,20},
		/*from 1*/	  {2,20,3,20,20},
		/*from 2*/	  {2,20,3,20,20},
		/*from 3*/	  {5,20,20,20,20},
		/*from 4*/	  {5,20,20,20,20},
		/*from 5*/	  {5,20,20,6,20},
		/*from 6*/	  {8,7,20,20,20},
		/*from 7*/	  {8,20,20,20,20},
		/*from 8*/	  {8,20,20,20,20}  };
		

                     // 8 represente l'état d'ECHEC
                    // les etats de succes sont 3 et 6
  
				
//labels des colonnes :     chiffre   +      -         e|E      autres
int transitions_entier[6][5]={
		/*from 0*/	  {2,1,1,20,20},
		/*from 1*/	  {2,20,20,20,20},
		/*from 2*/	  {2,20,20,9,20},
		/*from 9*/	  {11,10,20,20,20},
		/*from 10*/	  {11,20,20,20,20},
		/*from 11*/	  {11,20,20,6,20}  };
		
				
//labels des colonnes :     '       \       t|r|n      autres que '\trn 
int transitions_char[4][4]={
		/*from 0*/	  {12,20,20,20},
		/*from 12*/	  {15,13,14,14},
		/*from 13*/	  {14,14,14,20},
		/*from 14*/	  {15,20,20,20}  };
			
			
			
//labels des colonnes :     "       \       t|r|n      autres que "\trn 
int transitions_chaine[4][4]={
		/*from 0*/	  {16,20,20,20},
		/*from 16*/	  {19,17,18,18},
		/*from 17*/	  {18,18,18,20},
		/*from 18*/	  {19,17,18,18}  };



int regexCaracteres(char *chaine,int numligne)
{
int etat=0;
int ETAT;
int i=0;
int L=strlen(chaine);

	    do
	    {

            // printf("etat : %d\n", etat);
		switch(chaine[i])
		{
		    case '\''  :  etat=transitions_char[etat][0];break;
		    
		    case '\\'  :etat=transitions_char[etat][1];break;
		    case 't'  :
		    case 'r'  :
		    case 'n'  :
		    
		     etat=transitions_char[etat][2];break;
		    
		   
		    default :  etat=transitions_char[etat][3];
		    
		    
		}
		//printf("\n pour %c ETAT=%d",chaine[i],etat);
		if (etat>=9) {ETAT=etat;etat-=11;}
		i++;
	    }while(i<L && etat!=PUIT);
	   
	    if (!(ETAT==15)) 
	      {printf("\nERREUR ligne %d :  CARACTERE INCORRECT ",numligne);return 0;}
	     
	     return 1;
}

int regexChaine(char *chaine,int numligne)
{
    // printf("\nC'est un chaine !");
int etat=0;
int ETAT;
int i=0;
int L=strlen(chaine);

	    do
	    {

        // printf("\n\tdebut etat : %d\n", etat);
		switch(chaine[i])
		{
		    case '\"'  :  etat=transitions_chaine[etat][0];break;
		    
		    case '\\'  :etat=transitions_chaine[etat][1];break;
		    case 't'  :
		    case 'r'  :
		    case 'n'  :
		    
		     etat=transitions_chaine[etat][2];break;
             
             
             default :  etat=transitions_chaine[etat][3];
             
             
            }
        // printf(" %d", etat);
		//printf("\n pour %c ETAT=%d",chaine[i],etat);
		if (etat>=9) {ETAT=etat;etat-=15;}
		i++;
	    }while(i<L && etat!=PUIT);
	   
	    if (!(ETAT==19)) 
	      {printf("\nERREUR ligne %d :  CARACTERE INCORRECT ",numligne);return 0;}
	     
	     return 1;
}
///////////////////////////////////////////////////////////////////////////
int regexEntiers(char *chaine,int numligne)
{
int etat=0;
int ETAT;
int i=0;
int L=strlen(chaine);

	    do
	    {
		switch(chaine[i])
		{
		    case '0'  :
		    case '1'  :
		    case '2'  :
		    case '3'  :
		    case '4'  :
		    case '5'  :
		    case '6'  :
		    case '7'  :
		    case '8'  :
		    case '9'  :  etat=transitions_entier[etat][0];break;
		    
		    case '+'  :etat=transitions_entier[etat][1];break;
		    case '-'  : etat=transitions_entier[etat][2];break;
		    
		   
		    case 'e'  :
		    case 'E' :  etat=transitions_entier[etat][3];break;
		    default :  etat=transitions_entier[etat][4];
		    
		    
		}
		// printf("\n ETAT=%d",etat);
		if (etat>=9) {ETAT=etat;etat-=6;}
		i++;
	    }while(i<L && etat!=PUIT);
	   
	   
	   if (!(ETAT==2 || ETAT==11)) 
	      {printf("\nERREUR ligne %d :  ENTIER INCORRECT ",numligne);return 0;}
	    
	     return 1;
}

int regexReels(char *chaine,int numligne)
{
    
int etat=0,i=0;
int L=strlen(chaine);
    do
    {
        // printf("ETAT : %d \n", etat);
		switch(chaine[i])
		{
		    case '0'  :
		    case '1'  :
		    case '2'  :
		    case '3'  :
		    case '4'  :
		    case '5'  :
		    case '6'  :
		    case '7'  :
		    case '8'  :
		    case '9'  :  etat=transitions_reel[etat][0];break;
		    
		    case '+'  :
		    case '-'  : etat=transitions_reel[etat][1];break;
		    
		    case '.'  : etat=transitions_reel[etat][2];break;
	    
		    case 'e'  :
		    case 'E' :  etat=transitions_reel[etat][3];break;
		    default :  etat=transitions_reel[etat][4];
		    
		    
		}
		
		i++;
	    }while(i<L && etat!=PUIT);
	   
	    if (!(etat==2 || etat==5 || etat==8))   
	      {printf("\nERREUR ligne %d : REEL INCORRECT ",numligne);return 0;}
	     
	return 1;
}


//////////////////////////////////////////////////////////////////////////////
void viderBuffer() //pour nettoyer qd necessaire, le stdin entre 2 saisies
{
    int c = 0;
    while (c != '\n' && c != EOF) {  c = getchar(); }
}


//////////////////////////////////////////////////////////////////////////////
int appartient(char * letypelu,char *T[])
{
int i=0;
while(strcmp(T[i],"")!=0)
	{
	if (strcmp(T[i],letypelu)==0) return i;
	i++;		
	
	}


return -1;

}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
int main(int argc,char *argv[])
{
char *lestypesAcceptes[]={"char","int","float","double","void",""};
char *lesmotsClesAcceptes[]={"#include",""};
char *lesoperateursAcceptes[]={"=","{","}",""};
char *lesbibliothequesAcceptees[]={"<stdio.h>","<string.h>",""};
char *lesfonctionsAcceptees[]={"main()",""};

char car;
char ligne[1000];//on suppose qu'aucune ligne du fichier à compiler ne sera plus longue que 999
char type[7]; 
char *space;
char *egal;
char myTest[115] = ""; // on suppose qu'une variable ne peut pas contenir plus de 100 caractère
int i=0,numligne=1,quelType,NBerreurs=0,reponse;

FILE *f=NULL;
f=fopen(argv[1],"r");

int F_tableau = 0;
do
{
	fscanf(f,"%c",ligne+i); //printf("%c",*(ligne+i));
	*(ligne+i+1)='\0';	
	
	if(*(ligne+i)=='\n') {
				*(ligne+i)='\0';
				//printf("\n>>%s<<",ligne);
				i=0;
				//getchar();
				space=strchr(ligne,' ');
				if (space!=NULL) {
						*(space)='\0';
						//Premier morceau
						//printf("\n\t-->%s<<",ligne);
						if (!(ligne[0]=='{' || ligne[0]=='}'))
						{ 
						if (ligne[0]=='#' && appartient(ligne,lesmotsClesAcceptes)==-1) {NBerreurs++; printf("\nERREUR ligne %d : %s mot cle inconnu",numligne,ligne);} 
						else if (ligne[0]!='#' && (quelType=appartient(ligne,lestypesAcceptes))==-1) { NBerreurs++; printf("\nERREUR DE TYPE ligne %d : %s inconnu",numligne,ligne); }
						
						}
						
						//2eme morceau
						// printf("\n\t-->%s<<",space+1);
						if(*(space+1)=='<')
						{	if ((appartient(space+1,lesbibliothequesAcceptees))==-1)
						  {NBerreurs++; printf("\nERREUR DE LIBRAIRIE ligne %d : %s inconnue",numligne,space+1);} 
						}
						else
						{
						if ((egal=strchr(space+1,'='))==NULL && (appartient(space+1,lesfonctionsAcceptees)==-1)) 
							{NBerreurs++;printf("\nERREUR DE FONCTION ligne %d : %s inconnue",numligne,space+1);}
						
						else
						{ //appel aux AEFD
						// printf("\n APPEL A l'AEFD %d",quelType);
						
                        switch(quelType)
							{
							case 0 : 
								// printf("\n ANALYSE DU CARACTERE SUIVANT : %s",egal); 			
								egal[strlen(egal)-1]='\0';
								// printf("\n ANALYSE DU CARACTERE SUIVANT : %s",egal); 			
								// printf("\nEgal ? : %s", egal);

                                strcpy(myTest, space+1);
                                // printf("\n My test : %s", myTest);
                                char * result = strchr(myTest, '=');
								// printf("\n\tresult : %ld", result - myTest);
                                // printf("\n chars before : %c%c%c", myTest[result - myTest -2], myTest[result - myTest -1], myTest[result - myTest]);
                                
                                if (myTest[result - myTest -2] == '[' && myTest[result - myTest -1] == ']') // C'est un tableau => chaine de caractère
                                    reponse=regexChaine(egal+1,numligne);
                                else
                                    reponse=regexCaracteres(egal+1,numligne);
                                // printf("\nC'est ici que tout ce joue !\n");
								if (reponse==0) NBerreurs++;
								
								//printf("\nREPONSE=%d",reponse);break;
							
								break;
							case 1 : 
								//printf("\n ANALYSE DE L'ENTIER SUIVANT : %s",egal+1); 			
								egal[strlen(egal)-1]='\0';
								//printf("\n ANALYSE DE L'ENTIER SUIVANT : %s",egal+1); 			
								
								reponse=regexEntiers(egal+1,numligne);
								if (reponse==0) NBerreurs++;
								
								
								//printf("\nREPONSE=%d",reponse);break;
							
								break;
							case 2 : 
							case 3 : 
								//printf("\n ANALYSE DU REEL SUIVANT : %s",egal+1); 			
								egal[strlen(egal)-1]='\0';
								//printf("\n ANALYSE DU REEL SUIVANT : %s",egal+1); 			
								
								reponse=regexReels(egal+1,numligne);
								if (reponse==0) NBerreurs++;
								//printf("\nREPONSE=%d",reponse);break;
							
							
							}
						}
						
						}
						
						
						}
				numligne++;
				} 
	
	else i++;
	


}while(!feof(f));
fclose(f);


    printf("\n\n\nVOUS AVEZ %d ERREURS DE COMPILATION \n\n\tBERQUIER Raphaël - B2\n\n",NBerreurs);
    return 0;
}

