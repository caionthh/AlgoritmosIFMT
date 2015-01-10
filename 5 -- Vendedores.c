#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Funcionarios{
	char nome[30];
	float novembro;
	float dezembro;
	float janeiro;
	int novp;
	int dezp;
	int janp;
	int pontg;
	float total_vendas;
};

struct Contadores{
	int i;
	int op;
	int aux;
	int soma_maior;
	char campeao[30];
	float total_vendas;
};	

int main(int argc, char *argv[]) { setlocale (LC_ALL, "portuguese");
	struct Funcionarios fun[15]; // criando vetor de 15 posições para struct funcionários
	struct Contadores cont;
	cont.soma_maior = 0; // Inicializando a variável que será a maior soma de pontos
	cont.total_vendas = 0; // Inicializando a variável que será o total vendido por todos os vendedores
	while(cont.op != 6){ // Utilizando ciclo while para o menu de opções
		printf("\n######################  MENU DE OPÇÕES #####################\n");
		printf("# 1 - Cadastrar nome de funcionário e suas vendas          #\n");			
		printf("# 2 - Calcular a pontuação dos funcionários a cada mês     #\n");
		printf("# 3 - Calcuar a pontuação dos funcionários nos três meses  #\n");
		printf("# 4 - Mostrar a maior pontuação atingida nos três meses    #\n");
		printf("# 5 - Mostrar o total vendido pelos vendedores             #\n");
		printf("# 6 - Sair                                                 #\n");
		printf("#                 Tecle a opção desejada                   #\n");
		printf("############################################################\n");
		scanf("%d", &cont.op);
		fflush(stdin);
		
		switch(cont.op){ // Inicio do switch
			case 1: // Cadatrar os funcionário e o valor de suas vendas
				for(cont.i = 0; cont.i < 2; cont.i++){ // Ciclo for para varrer o vetor funcionários e receber valores
					printf("\nDigite o nome do funcionário nº %d\n", cont.i + 1);
					gets(fun[cont.i].nome); // Recebendo o nome do funcionário
					printf("Digite quanto o funcionário %s vendeu nos meses de:\nNovembro: R$ ", fun[cont.i].nome);
					scanf("%f", &fun[cont.i].novembro); // Vendas do mês de novembro
					printf("Dezembro: R$ ");
					scanf("%f", &fun[cont.i].dezembro); // Vendas do mês de dezembro
					printf("Janeiro: R$ ");
					scanf("%f", &fun[cont.i].janeiro); // Vendas do mês de janeioro
					fflush(stdin);
					
					fun[cont.i].novp = (fun[cont.i].novembro / 100); // Calculando a pontuação do mês de novembro 
					fun[cont.i].dezp = (fun[cont.i].dezembro / 100); // Calculando a pontuação do mês de dezembro
					fun[cont.i].janp = (fun[cont.i].janeiro / 100); // Calculando a pontuação do mês de janeiro
					
					// Calculando a pontuação geral de cada funcionário
					fun[cont.i].pontg = (fun[cont.i].novp + fun[cont.i].dezp + fun[cont.i].janp); 
					
					// Condição para encontrar o vendedor com a maior pontuação
					if(cont.soma_maior < fun[cont.i].pontg){
						cont.soma_maior = fun[cont.i].pontg;
						strcpy(cont.campeao, fun[cont.i].nome);
					}
					
					// Calculando o total de vendas de cada funcionário
					fun[cont.i].total_vendas = (fun[cont.i].janeiro + fun[cont.i].dezembro + fun[cont.i].novembro);
					
					// Realizando o somatótio das vendas de todos os funcionários
					cont.total_vendas += fun[cont.i].total_vendas;
				}
			break;
			
			// Mostrar a pontuação de todos os funcionários a cada mês
			case 2:
				for(cont.i = 0; cont.i < 2; cont.i++){ // Varrendo o vetor funcionários
					printf("O funcionário %s atingiu as seguintes pontuções:\n", fun[cont.i].nome);
					// Imprimindo a pontuação de cada mês
					printf("Novembro: %d\n", fun[cont.i].novp);
					printf("Dezembro: %d\n", fun[cont.i].dezp);
					printf("Janeiro: %d\n\n", fun[cont.i].janp);
				}
			break;
			
			// Imprimindo o total de pontos de todos os funcionários 
			case 3:
				for(cont.i = 0; cont.i < 2; cont.i++){
					printf("O funcionário %s possui um total de %d pontos\n", fun[cont.i].nome, fun[cont.i].pontg);
				}
			break;
			
			// Mostrando o vendedor campeão de vendas e seu total de pontos
			case 4:
				printf("O funcionário %s é o campeão de vendas com %d pontos\n", cont.campeao, cont.soma_maior);
			break;
			
			// Mostrando o somatório total de entre os vendedores em reais
			case 5:
				printf("O total vendido por todos os funcionário é de: R$ %.2f\n", cont.total_vendas);
			break;
		}
	}
	return 0;
}
