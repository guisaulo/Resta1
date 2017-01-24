#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogadores.h"

//funcao que imprime as pilhas
void imprimePalito(int pilha1, int pilha2, int pilha3, int pilha4){

printf("\n1\t2\t3\t4\t\n");

for(int i = 0; i < pilha1; i++)
   printf("þ");
   printf("\t");

for(int j = 0; j < pilha2; j++)
   printf("þ");
   printf("\t");

for(int k = 0; k < pilha3; k++)
   printf("þ");
   printf("\t");

for(int l = 0; l < pilha4; l++)
   printf("þ");
   printf("\t");

}

//funcao que salva informacoes de um jogador
void SalvaJogador (Jogador n){

FILE *arq;

arq = fopen("jogadores.txt","a");
       
if(arq == NULL){
   printf("\nErro ao ler o arquivo!");
   system("pause");
   return;
}  
         
printf("\nDigite seus dados para cadastrar: \n\n");
printf("\nLogin (8 caracteres): ");
fflush(stdin);
gets(n.login);
fprintf(arq, "%s,", n.login);
		 
printf("\nSenha (8 caracteres): ");
gets(n.senha);		
fprintf(arq, "%s,", n.senha);
		 
printf("\nNome: ");
gets(n.nome);
fprintf(arq, "%s,", n.nome);
		 
printf("\nIdade: ");
scanf("%d", &n.idade);		
fprintf(arq, "%d,", n.idade);
		 
n.num_vitorias = 0;
fprintf(arq, "%d,", n.num_vitorias);
	 
n.num_derrotas = 0;
fprintf(arq, "%d\n", n.num_derrotas);
fclose(arq);

}

//funcao que recebe login e senha
void login(Jogador *n){

int aux;

do{
   printf("Digite seu login: ");
   scanf("%s", &(*n).login);
   setbuf(stdin, NULL);
   
   printf("\nDigite sua senha: ");
   scanf("%s", &(*n).senha);
   setbuf(stdin, NULL);
   
   aux = verificalogin(*n);
   
   if(aux != 0)
      printf("\nSenha ou usuario incorreto, tente novamente.\n");
}while (aux != 0);

}

//funcao que compara login e senha
int verificalogin(Jogador n){

FILE *arq;  
char *vlogin, *vsenha, *vnome, buf[100];
int aux, vidade, vvitorias, vderrotas;

 arq = fopen("jogadores.txt", "r");
 
   do{
      fgets(buf, 100, arq);
      vlogin = strtok(buf, ",");
	  vsenha = strtok(NULL, ",");
      vnome = strtok(NULL, ",");
	  vidade = atoi(strtok(NULL, ","));
	  vvitorias = atoi(strtok(NULL, ","));
	  vderrotas = atoi(strtok(NULL, ","));
   }while(!feof(arq) && strcmp(vlogin,n.login)!=0 && strcmp(vsenha,n.senha)!=0);
   
   if(strcmp(vlogin,n.login) == 0 && strcmp(vsenha,n.senha) == 0)
      return 0;
   else
      return -1;
}

//funcao que credita uma vitoria para um jogador especifico
void vitoria (Jogador n){

FILE *arq;

arq = fopen("vitorias.txt", "a");

fprintf (arq, "%s ", n.login);

fclose (arq);

}

//funcao que credita uma derrota para um jogador especifico
void derrota (Jogador n){

FILE *arq;

arq = fopen("derrotas.txt", "a");

fprintf (arq, "%s ", n.login);

fclose (arq);

}

//funcao que carrega informacoes do jogador e imprime na tela
void informacoes(Jogador n){
    int i=0, j=0;
    char vit[50], der[50];
    FILE *vitorias, *derrotas;
    vitorias = fopen("vitorias.txt", "r");
    derrotas = fopen("derrotas.txt", "r");
    while (!feof(vitorias))
    {
        fscanf(vitorias,"%s", &vit);
        if (strcmp(vit,n.login) == 0) i++;
        else i = i;
    }
    fclose(vitorias);
    while (!feof(derrotas))
    {
        fscanf(derrotas,"%s", &der);
        if (strcmp(der,n.login) == 0) j++;
        else j = j;
    }
    if (i!=0) i--; if (j!=0) j--;
    fclose(derrotas);
	printf("\n----------------------------ESTATISTICAS-------------------------------------\n");
    printf("\n\nO jogador %s ganhou %d vezes e perdeu %d vezes.\n\n", n.login, i, j);
	printf("\n---------------------------------------------------------------------------\n\n");
}