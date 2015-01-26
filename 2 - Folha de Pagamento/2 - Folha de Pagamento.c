#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Fabrica{
	char nome[30];
	int h_trabalhadas;
	char turno;
	char categoria;
	float val_hora;
	float sal_inicial;
	float sal_final;
	float aux_alimento;
};
struct Aux{
	int i;
	int op;
	int conta_nome;
	float sal_minimo;
};
int main(int argc, char *argv[]) { setlocale(LC_ALL, "Portuguese");
	struct Fabrica fabrica[2];
	struct Aux aux;

	//Menu de op��es utilizando ciclo while
	while(aux.op != 3){
		printf("\n----- Menu de Op��es -----\n\n");
		printf("1- Cadastrar Funcion�rios\n");
		printf("2- Mostrar Folha de Pagamento\n");
		printf("3- Sair");
		printf("\n\nDigite a Op��o Desejada: ");
		scanf("%d", &aux.op);
		fflush(stdin);
		
		// Caso 1 cadastrando funcion�rios
		switch(aux.op){
			case 1:
				for(aux.i = 0; aux.i < 2; aux.i++){
					
					//Recebendo o nome do funcion�rio
					printf("\nDigite o nome do funcion�rio n� %d: ", aux.i + 1);
					gets(fabrica[aux.i].nome);
					
					//Recebendo a quantidade de horas trabalhadas
					printf("\nDigite a quantidade de horas trabalhadas no m�s do funcion�rio n� %d: ", aux.i + 1);
					scanf("%d", &fabrica[aux.i].h_trabalhadas);
					fflush(stdin);
					
					//Recebendo o turno em que o funcion�rio trabalha
					printf("\nDigite o turno que trabalha o funcion�rio n� %d \nM-matutino, V-vespertino e N-noturno: ", aux.i + 1);
					scanf("%c", &fabrica[aux.i].turno);
					fflush(stdin);
					//Condi��o para quando o usu�rio digitar uma op��o inv�lida para o turno
					while(fabrica[aux.i].turno != 'm' && fabrica[aux.i].turno != 'v' && fabrica[aux.i].turno != 'n'){
						printf("\n\nOp��o inv�lida!\n\n");
						printf("\nDigite o turno que trabalha o funcion�rio n� %d \nM-matutino, V-vespertino e N-noturno: ", aux.i + 1);
						scanf("%c", &fabrica[aux.i].turno);
						fflush(stdin);
					}
					
					// Recebendo a categoria que se enquadra o funcion�rio
					printf("\nDigite a categoria do funcion�rio n� %d \nO-oper�rio ou G-gerente: ", aux.i + 1);
					scanf("%c", &fabrica[aux.i].categoria);
					fflush(stdin);
					//Condi��o caso o usu�rio digite op��o inv�lida
					while(fabrica[aux.i].categoria != 'o' && fabrica[aux.i].categoria != 'g'){
						printf("\n\nOp��o Inv�lida!\n");
						printf("\nDigite a categoria do funcion�rio n� %d \nO-oper�rio ou G-gerente: ", aux.i + 1);
						scanf("%c", &fabrica[aux.i].categoria);
						fflush(stdin);
					}
					
					/* Existe uma fun��o que n�o existe na empresa em determinado pr�odo, gerente
					 que trabalhe a tarde, esta condi��o � para caso o usu�rio a escolha */
					if(fabrica[aux.i].categoria == 'g'){
						if(fabrica[aux.i].turno == 'v'){
							printf("\n\nN�o existe esta fun��o neste per�odo na empresa!\n");
							printf("\nDigite o turno que trabalha o funcion�rio n� %d \nM-matutino, V-vespertino e N-noturno: ", aux.i + 1);
							scanf("%c", &fabrica[aux.i].turno);
							fflush(stdin);
							printf("\nDigite a categoria do funcion�rio n� %d \nO-oper�rio ou G-gerente: ", aux.i + 1);
							scanf("%c", &fabrica[aux.i].categoria);
							fflush(stdin);
						}
					}
					
					//valor do sal�rio minimo
					aux.sal_minimo = 112;
					// Valor da hora para gerente que trabalhe a noite
					if(fabrica[aux.i].categoria == 'g'){
						if(fabrica[aux.i].turno == 'n'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.18);
						}
					}
					
					// Valor da hora para gerente que trabalhe de manh� ou a noite
					if(fabrica[aux.i].categoria == 'g'){
						if(fabrica[aux.i].turno == 'm'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.15);
						}
					}
					if(fabrica[aux.i].categoria == 'g'){
						if(fabrica[aux.i].turno == 'n'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.15);
						}
					}
					
					// Valor da hora para oper�rio que trabalhe a noite
					if(fabrica[aux.i].categoria == 'o'){
						if(fabrica[aux.i].turno == 'n'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.13);
						}
					}
					
					// Valor da hora para oper�rio que trabalhe de manh� ou a tarde
					if(fabrica[aux.i].categoria == 'o'){
						if(fabrica[aux.i].turno == 'm'){
								fabrica[aux.i].val_hora = (aux.sal_minimo * 0.10);
						}
					}
					if(fabrica[aux.i].categoria == 'o'){
						if(fabrica[aux.i].turno == 'v'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.10);
						}
					}
					// Calculando o sal�rio inicial
					fabrica[aux.i].sal_inicial = (fabrica[aux.i].val_hora * fabrica[aux.i].h_trabalhadas);
					
					// 1� condi��o para o aux�lio alimenta��o
					if(fabrica[aux.i].sal_inicial <= 300){
						fabrica[aux.i].aux_alimento = (fabrica[aux.i].sal_inicial * 0.20);
					}
					
					// 2� Condi��o para o aux�lio alimenta��o
					if(fabrica[aux.i].sal_inicial > 300){
						if(fabrica[aux.i].sal_inicial < 600){
							fabrica[aux.i].aux_alimento = (fabrica[aux.i].sal_inicial * 0.15);
						}
					}
					
					// 3� Condi��o para o aux�lio alimenta��o
					if(fabrica[aux.i].sal_inicial >= 600){
						fabrica[aux.i].aux_alimento = (fabrica[aux.i].sal_inicial * 0.05);
					}
					
					// Obtendo o sal�rio final
					fabrica[aux.i].sal_final = (fabrica[aux.i].sal_inicial + fabrica[aux.i].aux_alimento);
					fflush(stdin);
				}
				break;
				
				// Imprimindo a folha de pagamento
				case 2:
					for(aux.i = 0; aux.i < 2; aux.i++){
						printf("\n\nO funcion�rio %s trabalhou %d horas no m�s\n", fabrica[aux.i].nome, fabrica[aux.i].h_trabalhadas);
						printf("\nO valor de sua hora trabalhada � de: R$ %.2f\n", fabrica[aux.i].val_hora);
						printf("\nO seu sal�rio inicial � de: R$ %.2f\n", fabrica[aux.i].sal_inicial);
						printf("\nO seu aux�lio alimenta��o � de: R$ %.2f\n", fabrica[aux.i].aux_alimento);
						printf("\nO seu sal�rio final � de: R$ %.2f\n", fabrica[aux.i].sal_final);
					}
				break;	
		}
	}
	return 0;
}
