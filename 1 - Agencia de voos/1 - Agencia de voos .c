#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Avioes{
	int num_aviao;	
	char lugares[60][30];
	int num_lugares;
};
struct Aux{
	int i;
	int j;
	int escolha_aviao;
	int op;
	int cont_reserva;
	int cont_reserva2;
	char nome_passageiro[30];
};
int main(int argc, char *argv[]) { setlocale(LC_ALL,"portuguese");
	//Declarando as vari�veis dos registros
	struct Avioes avioes[4];
	struct Aux aux;
	
	//Ciclo para mostrar o menu de op��es e sair quando digitar 6
	while(aux.op != 6){
		printf("\n---- Menu de Op��es-------\n");
		printf(" 1- Cadastrar os numeros dos avi�es\n");
		printf(" 2- Cadastrar o numero de lugares dispon�vel em cada avi�o\n");
		printf(" 3- Reservar Passagem\n");
		printf(" 4- Consultar por Avi�o\n");
		printf(" 5- Consultar por Passageiro\n");
		printf(" 6- Sair\n\n");
		printf("Digite o numero da op��o desejada: ");
		scanf("%d", &aux.op);
		fflush(stdin);
		
		switch(aux.op){
		
			//Cadastrar o numero dos avi�es
			case 1:
				for(aux.i = 0; aux.i < 4; aux.i++){
					printf("\nCadastre o numero do avi�o %d: ", aux.i + 1);
					scanf("%d", &avioes[aux.i].num_aviao);
				}
				fflush(stdin);
			break;
			
			//Cadastrar o numero de lugares disponivel em cada avi�o
			case 2:
				for(aux.i = 0; aux.i < 4; aux.i++){
					printf("\nCadastre o numero de lugares dispon�vel para o avi�o %d  \nQue dever� ter capacidade m�xima de 60 lugares: ", aux.i + 1);
					scanf("%d", &avioes[aux.i].num_lugares);
				}
				fflush(stdin);
			break;
			
			//Escolha do avi�o que deseja efetuar a reserva
			case 3:
				printf("\nDigite o numero do avi�o que deseja efetuar a reserva: ");
				scanf("%d", &aux.escolha_aviao);
				fflush(stdin);
				
				/* Varrendo o vetor avi�es a procura do n� do avi�o escolhido se encontrado
				efetuar a reserva solicitando o nome do cliente e apresenta a mensagem 
				Reserva confirmada, se n�o apresentar a mensagem Numero inv�lido */ 
				for(aux.i = 0; aux.i < 4; aux.i++){
					for(aux.j = 0; aux.j < avioes[aux.i].num_lugares; aux.j++){
						if(aux.escolha_aviao == avioes[aux.i].num_aviao){
							if(avioes[aux.i].num_lugares > 0){
								printf("\nDigite o nome do passageiro:\n");
								gets(avioes[aux.i].lugares[aux.cont_reserva]);
								printf("\n* Reserva confirmada *\n\n");
								//Depois de reservar passagem diminui uma vaga no avi�o
								avioes[aux.i].num_lugares--;
								// Contador para as reservas feitas que ser� utilizado no case 4
								aux.cont_reserva++; 
								break;                
							}
						}
					}
				}
				
				// Cond��o caso o numero do avi�o digitado seja inexistente
				if(aux.escolha_aviao != avioes[0].num_aviao && aux.escolha_aviao != avioes[1].num_aviao && aux.escolha_aviao != avioes[2].num_aviao && aux.escolha_aviao != avioes[3].num_aviao)
					printf("\nNumero Invalido\n\n");
				
				// Quando escolhido a op��o 3 mostra o numero dos avi�es e vagas dispon�veis em cada um deles
				for(aux.i = 0; aux.i < 4; aux.i++){
					printf("Avi�o: %d\n",avioes[aux.i].num_aviao);
					printf("Lugares Dispon�veis: %d\n\n", avioes[aux.i].num_lugares);
				}
			break;
			
			// Mostrar as reservas feitas em determinado voo
			case 4:
				printf("\nDigite o numero do avi�o que deseja visualizar as reservas: ");
				scanf("%d", &aux.escolha_aviao);
				fflush(stdin);
				
				// Encontrando o avi�o e imprimindo as reservas j� realizadas
				for(aux.i = 0; aux.i < 4; aux.i++){
					for(aux.j = 0; aux.j < aux.cont_reserva; aux.j++){
						if(aux.escolha_aviao == avioes[aux.i].num_aviao){
							printf("\n\nReseva em nome de: %s\n", avioes[aux.i].lugares[aux.j]);
						}
					}
				}
			break;
			
			// Verificar reservas a partir do nome do cliente
			case 5:
				printf("\nDigite o nome do passageiro que deseja verificar suas reservas: ");
				gets(aux.nome_passageiro);
				
				// Varrendo as reservas de todos os voos buscando pelo nome do cliente
				for(aux.i = 0; aux.i < 4; aux.i++){
					for(aux.j = 0; aux.j < 60; aux.j++){
						// fun��o strcmp compara dois vetores char e retorna um valor
						if(strcmp(aux.nome_passageiro,avioes[aux.i].lugares[aux.j]) == 0){
							printf("\nO cliente %s possui reserva no voo n�: %d\n", aux.nome_passageiro, avioes[aux.i].num_aviao);
							aux.cont_reserva2++;
						}
					}
				}
				printf("\nO cliente %s possui %d reservas em seu nome.\n", aux.nome_passageiro, aux.cont_reserva2);
		}
	
	}
	return 0;
}
