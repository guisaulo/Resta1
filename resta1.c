//Jogo do Resta 1 - Trabalho Pratico 2 de AEDS1
//Programador: Guilherme Saulo Alves
//Data de Avaliacao: 04/07/2013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogadores.h"

int main () {

srand(time(NULL));

FILE *arq;

Jogo func;
Jogador ger, n;
Jogador jogadorA, jogadorB;

int opcao, retirar = 0, vez = 1, pilhA = 0;
char jogador[8], pilha, voltar;

func.pilha1 = 7, func.pilha2 = 5, func.pilha3 = 3, func.pilha4 = 2;
func.inicio_de_jogo = 0, func.fim_de_jogo = 0;

while((func.fim_de_jogo == 0)&&(opcao!='1'||opcao!='2'||opcao!='3'||opcao!='4'||opcao!='5'||opcao!='6')){
   system ("cls");
   printf ("------ Resta 1 ------\n\n");
   printf ("1) Modo Multiplayer\n");
   printf ("2) Modo Singleplayer\n");
   printf ("3) Cadastrar Usuario\n");
   printf ("4) Sair\n\n");
   fflush(stdin);
   opcao = getchar();

   switch(opcao){
      case '1': //modo multiplayer
    	 system ("cls");
		 printf ("------ Login jogador A ------\n\n");
		 login(&jogadorA);
		 
		 system ("cls");
		 printf ("------ Login jogador B ------\n\n");
		 login(&jogadorB);
		 
		 func.inicio_de_jogo = 1;
		 
    	 func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
		 do{
		    while(func.inicio_de_jogo == 1){
               system ("cls");
		       func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
               imprimePalito(func.pilha1,func.pilha2,func.pilha3,func.pilha4);
		      
			   if (vez % 2 == 1) //alterna o jogador
                  strcpy(jogador,jogadorA.login);
               else
                  strcpy(jogador,jogadorB.login);
			  
			   if(func.totalPalitos == 1 || func.totalPalitos == 0)
			      break;
			  	 
     		   do{
			      printf("\n\nJogador: %s", jogador);
    	          printf("\n\nEscolha a pilha: ");
		          fflush(stdin);
				  pilha = getchar();
				  if((pilha!='1'&&pilha!='2'&&pilha!='3'&&pilha!='4') || ((pilha == '1' && func.pilha1 == 0) || (pilha == '2' && func.pilha2 == 0) || (pilha == '3' && func.pilha3 == 0) || (pilha == '4' && func.pilha4 == 0))){
			         system ("cls");
				     imprimePalito(func.pilha1,func.pilha2,func.pilha3,func.pilha4);
					 printf("\n\nError! Escolha uma pilha valida: ");
				  }
               }while((pilha!='1'&&pilha!='2'&&pilha!='3'&&pilha!='4') || ((pilha == '1' && func.pilha1 == 0) || (pilha == '2' && func.pilha2 == 0) || (pilha == '3' && func.pilha3 == 0) ||(pilha == '4' && func.pilha4 == 0)));
			  		  
			   if(pilha == '1'){
			      printf("\nQuantidade que deseja retirar: ");
		          fflush(stdin);
				  scanf("%d", &retirar);
			     
				  if(retirar > 0 && retirar <= func.pilha1)
                     func.pilha1 -= retirar;
                  else{
                     do{
                        printf("\nError! Escolha uma quantia valida: "); 
		                fflush(stdin);
				        scanf("%d", &retirar);
                     }while((retirar > func.pilha1) || (retirar < 1));			  
				     func.pilha1 -= retirar;
			      }
                  retirar = 0;
			   }			   
		    
			   else if(pilha == '2'){
			      printf("\nQuantidade que deseja retirar: ");
		          fflush(stdin);
				  scanf("%d", &retirar);
			     
				  if(retirar > 0 && retirar <= func.pilha2)
                     func.pilha2 -= retirar;
                  else{
                     do{
                        printf("\nError! Escolha uma quantia valida: "); 
		                fflush(stdin);
				        scanf("%d", &retirar);
                     }while((retirar > func.pilha2) || (retirar < 1));			  
				     func.pilha2 -= retirar;
			      }
                  retirar = 0;
			   }			
		    
			   else if(pilha == '3'){
			      printf("\nQuantidade que deseja retirar: ");
		          fflush(stdin);
				  scanf("%d", &retirar);
			     
				  if(retirar > 0 && retirar <= func.pilha3)
                     func.pilha3 -= retirar;
                  else{
                     do{
                        printf("\nError! Escolha uma quantia valida: "); 
		                fflush(stdin);
				        scanf("%d", &retirar);
                     }while((retirar > func.pilha3) || (retirar < 1));			  
				     func.pilha3 -= retirar;
			      }
                  retirar = 0;
			   }	
			  
			   else if(pilha == '4'){
			      printf("\nQuantidade que deseja retirar: ");
		          fflush(stdin);
		 		  scanf("%d", &retirar);
			     
				  if(retirar > 0 && retirar <= func.pilha4)
                     func.pilha4 -= retirar;
                  else{
                     do{
                        printf("\nError! Escolha uma quantia valida: "); 
		                fflush(stdin);
				        scanf("%d", &retirar);
                     }while((retirar > func.pilha4) || (retirar < 1));			  
				     func.pilha4 -= retirar;
			      }
                  retirar = 0;
			   }	
               vez++;
		    }
		    //informacoes de fim de rodada
			func.inicio_de_jogo = 0;
		    func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
		    if (func.totalPalitos == 1){
		       printf("\n\nJogador %s perdeu!", jogador);
			   if(strcmp(jogador,jogadorA.login) == 0){
		          derrota(jogadorA);
				  vitoria(jogadorB);
				  informacoes(jogadorA);
                  informacoes(jogadorB);				  
			   }
			   else{
			      derrota(jogadorB);
			      vitoria(jogadorA);
				  informacoes(jogadorA);
				  informacoes(jogadorB);
    		   }	    
			}   
			
			else{
		       vez++;
			   if (vez % 2 == 1)
                  strcpy(jogador,jogadorA.login);
               else
                  strcpy(jogador,jogadorB.login);	
               
			   printf("\n\nJogador %s perdeu!", jogador);
			   if(strcmp(jogador,jogadorA.login) == 0){
		          derrota(jogadorA);
				  vitoria(jogadorB);
				  informacoes(jogadorA);
                  informacoes(jogadorB);				  
			   }
			   else{
			      derrota(jogadorB);
			      vitoria(jogadorA);
				  informacoes(jogadorA);
				  informacoes(jogadorB);
    		   }			   
		    }
		    do{
               printf("\n\nVoce quer jogar novamente?(S/N)");
               fflush(stdin);
			   voltar = getchar();
		    }while(voltar!='S'&&voltar!='s'&&voltar!='N'&&voltar!='n');
		   
		   if(voltar=='S'||voltar=='s'){
              func.inicio_de_jogo = 1;
			  func.pilha1 = 7, func.pilha2 = 5, func.pilha3 = 3, func.pilha4 = 2;
			  func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
			  voltar=0;
		   }
           else{
		      func.inicio_de_jogo = 0;
              func.pilha1 = 7, func.pilha2 = 5, func.pilha3 = 3, func.pilha4 = 2;
			  func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
			  voltar = 0;
		   }
		 }while(func.inicio_de_jogo == 1);
	    break;
	  case '2': //modo singleplayer
		 system("cls");
    	 printf ("------ Login jogador A ------\n\n");
		 login(&jogadorA);
	     
		 func.inicio_de_jogo = 1;
		 func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4; 
		 
		 do{
		    while(func.inicio_de_jogo == 1){
		       system ("cls");
			   	
     		   func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
               imprimePalito(func.pilha1,func.pilha2,func.pilha3,func.pilha4);
			   
			   if(func.totalPalitos == 1 || func.totalPalitos == 0){
			      printf("\n\nO Computador retirou %d palitos da pilha %d.", retirar, pilhA);
			   break;
			   }
                				
			   if (vez % 2 == 0){ //vez do computador
			      do{
				     pilhA = 1 + rand() % 4;
				  }while((pilhA == 1 && func.pilha1 == 0) || (pilhA == 2 && func.pilha2 == 0) || (pilhA == 3 && func.pilha3 == 0) ||(pilhA == 4 && func.pilha4 == 0));
				  
				  if(pilhA == 1){
				     retirar = 1 + rand() % func.pilha1;
					 func.pilha1 -= retirar;
		          }
				  else if(pilhA == 2){
				     retirar = 1 + rand() % func.pilha2;
					 func.pilha2 -= retirar;
				  }
				  else if(pilhA == 3){
				     retirar = 1 + rand() % func.pilha3;
					 func.pilha3 -= retirar;
				  }
				  else if(pilhA == 4){
				     retirar = 1 + rand() % func.pilha4;
					 func.pilha4 -= retirar;
				  }
				  
               }
			   
			   else if (vez % 2 == 1) {
			      printf("\n\nO Computador retirou %d palitos da pilha %d.", retirar, pilhA);
				  pilhA = 0;
			      retirar = 0;
     		      do{
			         printf("\n\nJogador: %s", jogadorA.login);
    	             printf("\n\nEscolha a pilha: ");
		             fflush(stdin);
				     pilha = getchar();
				     if((pilha!='1'&&pilha!='2'&&pilha!='3'&&pilha!='4') || ((pilha == '1' && func.pilha1 == 0) || (pilha == '2' && func.pilha2 == 0) || (pilha == '3' && func.pilha3 == 0) || (pilha == '4' && func.pilha4 == 0))){
			            system ("cls");
				        imprimePalito(func.pilha1,func.pilha2,func.pilha3,func.pilha4);
				        printf("\n\nError! Escolha uma pilha valida: ");
				     }
                  }while((pilha!='1'&&pilha!='2'&&pilha!='3'&&pilha!='4') || ((pilha == '1' && func.pilha1 == 0) || (pilha == '2' && func.pilha2 == 0) || (pilha == '3' && func.pilha3 == 0) ||(pilha == '4' && func.pilha4 == 0)));
			  		  
			      if(pilha == '1'){
	                 printf("\nQuantidade que deseja retirar: ");
		             fflush(stdin);
			         scanf("%d", &retirar);
			    
				     if(retirar > 0 && retirar <= func.pilha1)
                        func.pilha1 -= retirar;
                     else{
                        do{
                           printf("\nError! Escolha uma quantia valida: "); 
		                   fflush(stdin);
				           scanf("%d", &retirar);
                        }while((retirar > func.pilha1) || (retirar < 1));			  
				        func.pilha1 -= retirar;
			         }
                     retirar = 0;
			      }			   
		            
			      else if(pilha == '2'){
			         printf("\nQuantidade que deseja retirar: ");
		             fflush(stdin);
				     scanf("%d", &retirar);
			     
    				 if(retirar > 0 && retirar <= func.pilha2)
                        func.pilha2 -= retirar;
                     else{
                        do{
                           printf("\nError! Escolha uma quantia valida: "); 
		                   fflush(stdin);
				           scanf("%d", &retirar);
                        }while((retirar > func.pilha2) || (retirar < 1));			  
				        func.pilha2 -= retirar;
			         }
                     retirar = 0;
			      }			
		    
			      else if(pilha == '3'){
			         printf("\nQuantidade que deseja retirar: ");
		             fflush(stdin);
				     scanf("%d", &retirar);
			     
  				     if(retirar > 0 && retirar <= func.pilha3)
                        func.pilha3 -= retirar;
                     else{
                        do{
                           printf("\nError! Escolha uma quantia valida: "); 
		                   fflush(stdin);
				           scanf("%d", &retirar);
                        }while((retirar > func.pilha3) || (retirar < 1));			  
				        func.pilha3 -= retirar;
			         }
                     retirar = 0;
			      }	
			  
			      else if(pilha == '4'){
			         printf("\nQuantidade que deseja retirar: ");
		             fflush(stdin);
		 		     scanf("%d", &retirar);
			     	 
					 if(retirar > 0 && retirar <= func.pilha4)
                        func.pilha4 -= retirar;
                     else{
                        do{
                           printf("\nError! Escolha uma quantia valida: "); 
	                       fflush(stdin);
	                       scanf("%d", &retirar);
                        }while((retirar > func.pilha4) || (retirar < 1));			  
				        func.pilha4 -= retirar;
			         }
                     retirar = 0;
			      }				        
				
			   }			  
		       vez++;
            }			   

			func.inicio_de_jogo = 0;
		    func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
		    
			if(func.totalPalitos == 1){
		       if(vez % 2 == 1){
                  printf("\n\nJogador %s perdeu!", jogadorA.login);
				  derrota(jogadorA);
				  informacoes(jogadorA);
			   }
               else if (vez % 2 == 0){
                  printf("\n\nComputador perdeu!");
		          vitoria(jogadorA);
				  informacoes(jogadorA);
			   }
			}
			else if(func.totalPalitos == 0){
			   vez++;
			   if(vez % 2 == 1){
                 printf("\n\nJogador %s perdeu!", jogadorA.login);
				 derrota(jogadorA);
                 informacoes(jogadorA);				 
			   }
               else if (vez % 2 == 0){
                 printf("\n\nComputador perdeu!");
				 vitoria(jogadorA);
				 informacoes(jogadorA);
			   }
		    }
		    do{
               printf("\n\nVoce quer jogar novamente?(S/N)");
               fflush(stdin);
			   voltar = getchar();
		 }while(voltar!='S'&&voltar!='s'&&voltar!='N'&&voltar!='n');
		   
		   if(voltar=='S'||voltar=='s'){
              func.inicio_de_jogo = 1;
			  func.pilha1 = 7, func.pilha2 = 5, func.pilha3 = 3, func.pilha4 = 2;
			  func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
			  voltar=0;
			  pilhA = 0;
			  retirar = 0;
			  vez = 1;
		   }
           else{
		      func.inicio_de_jogo = 0;
              func.pilha1 = 7, func.pilha2 = 5, func.pilha3 = 3, func.pilha4 = 2;
			  func.totalPalitos = func.pilha1 + func.pilha2 + func.pilha3 + func.pilha4;
			  voltar = 0;
			  pilhA = 0;
			  retirar = 0;		
              vez = 1;			  
		   }
	     }while(func.inicio_de_jogo == 1);
	     break; 
	  case '3': //carrega modulo para carregar jogador
         system("cls");
		 SalvaJogador(n);	  
	     break;
	  case '4': //abortar jogo
	     func.fim_de_jogo = 1;
		 system("cls");
	     break;
   }
}

return 0;
}