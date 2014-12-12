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

	//Menu de opções utilizando ciclo while
	while(aux.op != 3){
		printf("\n----- Menu de Opções -----\n\n");
		printf("1- Cadastrar Funcionários\n");
		printf("2- Mostrar Folha de Pagamento\n");
		printf("3- Sair");
		printf("\n\nDigite a Opção Desejada: ");
		scanf("%d", &aux.op);
		fflush(stdin);
		
		// Caso 1 cadastrando funcionários
		switch(aux.op){
			case 1:
				for(aux.i = 0; aux.i < 2; aux.i++){
					
					//Recebendo o nome do funcionário
					printf("\nDigite o nome do funcionário nº %d: ", aux.i + 1);
					gets(fabrica[aux.i].nome);
					
					//Recebendo a quantidade de horas trabalhadas
					printf("\nDigite a quantidade de horas trabalhadas no mês do funcionário nº %d: ", aux.i + 1);
					scanf("%d", &fabrica[aux.i].h_trabalhadas);
					fflush(stdin);
					
					//Recebendo o turno em que o funcionário trabalha
					printf("\nDigite o turno que trabalha o funcionário nº %d \nM-matutino, V-vespertino e N-noturno: ", aux.i + 1);
					scanf("%c", &fabrica[aux.i].turno);
					fflush(stdin);
					//Condição para quando o usuário digitar uma opção inválida para o turno
					while(fabrica[aux.i].turno != 'm' && fabrica[aux.i].turno != 'v' && fabrica[aux.i].turno != 'n'){
						printf("\n\nOpção inválida!\n\n");
						printf("\nDigite o turno que trabalha o funcionário nº %d \nM-matutino, V-vespertino e N-noturno: ", aux.i + 1);
						scanf("%c", &fabrica[aux.i].turno);
						fflush(stdin);
					}
					
					// Recebendo a categoria que se enquadra o funcionário
					printf("\nDigite a categoria do funcionário nº %d \nO-operário ou G-gerente: ", aux.i + 1);
					scanf("%c", &fabrica[aux.i].categoria);
					fflush(stdin);
					//Condição caso o usuário digite opção inválida
					while(fabrica[aux.i].categoria != 'o' && fabrica[aux.i].categoria != 'g'){
						printf("\n\nOpção Inválida!\n");
						printf("\nDigite a categoria do funcionário nº %d \nO-operário ou G-gerente: ", aux.i + 1);
						scanf("%c", &fabrica[aux.i].categoria);
						fflush(stdin);
					}
					
					/* Existe uma função que não existe na empresa em determinado príodo, gerente
					 que trabalhe a tarde, esta condição é para caso o usuário a escolha */
					if(fabrica[aux.i].categoria == 'g'){
						if(fabrica[aux.i].turno == 'v'){
							printf("\n\nNão existe esta função neste período na empresa!\n");
							printf("\nDigite o turno que trabalha o funcionário nº %d \nM-matutino, V-vespertino e N-noturno: ", aux.i + 1);
							scanf("%c", &fabrica[aux.i].turno);
							fflush(stdin);
							printf("\nDigite a categoria do funcionário nº %d \nO-operário ou G-gerente: ", aux.i + 1);
							scanf("%c", &fabrica[aux.i].categoria);
							fflush(stdin);
						}
					}
					
					//valor do salário minimo
					aux.sal_minimo = 112;
					// Valor da hora para gerente que trabalhe a noite
					if(fabrica[aux.i].categoria == 'g'){
						if(fabrica[aux.i].turno == 'n'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.18);
						}
					}
					
					// Valor da hora para gerente que trabalhe de manhã ou a noite
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
					
					// Valor da hora para operário que trabalhe a noite
					if(fabrica[aux.i].categoria == 'o'){
						if(fabrica[aux.i].turno == 'n'){
							fabrica[aux.i].val_hora = (aux.sal_minimo * 0.13);
						}
					}
					
					// Valor da hora para operário que trabalhe de manhã ou a tarde
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
					// Calculando o salário inicial
					fabrica[aux.i].sal_inicial = (fabrica[aux.i].val_hora * fabrica[aux.i].h_trabalhadas);
					
					// 1ª condição para o auxílio alimentação
					if(fabrica[aux.i].sal_inicial <= 300){
						fabrica[aux.i].aux_alimento = (fabrica[aux.i].sal_inicial * 0.20);
					}
					
					// 2ª Condição para o auxílio alimentação
					if(fabrica[aux.i].sal_inicial > 300){
						if(fabrica[aux.i].sal_inicial < 600){
							fabrica[aux.i].aux_alimento = (fabrica[aux.i].sal_inicial * 0.15);
						}
					}
					
					// 3ª Condição para o auxílio alimentação
					if(fabrica[aux.i].sal_inicial >= 600){
						fabrica[aux.i].aux_alimento = (fabrica[aux.i].sal_inicial * 0.05);
					}
					
					// Obtendo o salário final
					fabrica[aux.i].sal_final = (fabrica[aux.i].sal_inicial + fabrica[aux.i].aux_alimento);
					fflush(stdin);
				}
				break;
				
				// Imprimindo a folha de pagamento
				case 2:
					for(aux.i = 0; aux.i < 2; aux.i++){
						printf("\n\nO funcionário %s trabalhou %d horas no mês\n", fabrica[aux.i].nome, fabrica[aux.i].h_trabalhadas);
						printf("\nO valor de sua hora trabalhada é de: R$ %.2f\n", fabrica[aux.i].val_hora);
						printf("\nO seu salário inicial é de: R$ %.2f\n", fabrica[aux.i].sal_inicial);
						printf("\nO seu auxílio alimentação é de: R$ %.2f\n", fabrica[aux.i].aux_alimento);
						printf("\nO seu salário final é de: R$ %.2f\n", fabrica[aux.i].sal_final);
					}
				break;	
		}
	}
	return 0;
}
