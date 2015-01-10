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
	struct Funcionarios fun[15]; // criando vetor de 15 posi��es para struct funcion�rios
	struct Contadores cont;
	cont.soma_maior = 0; // Inicializando a vari�vel que ser� a maior soma de pontos
	cont.total_vendas = 0; // Inicializando a vari�vel que ser� o total vendido por todos os vendedores
	while(cont.op != 6){ // Utilizando ciclo while para o menu de op��es
		printf("\n######################  MENU DE OP��ES #####################\n");
		printf("# 1 - Cadastrar nome de funcion�rio e suas vendas          #\n");			
		printf("# 2 - Calcular a pontua��o dos funcion�rios a cada m�s     #\n");
		printf("# 3 - Calcuar a pontua��o dos funcion�rios nos tr�s meses  #\n");
		printf("# 4 - Mostrar a maior pontua��o atingida nos tr�s meses    #\n");
		printf("# 5 - Mostrar o total vendido pelos vendedores             #\n");
		printf("# 6 - Sair                                                 #\n");
		printf("#                 Tecle a op��o desejada                   #\n");
		printf("############################################################\n");
		scanf("%d", &cont.op);
		fflush(stdin);
		
		switch(cont.op){ // Inicio do switch
			case 1: // Cadatrar os funcion�rio e o valor de suas vendas
				for(cont.i = 0; cont.i < 2; cont.i++){ // Ciclo for para varrer o vetor funcion�rios e receber valores
					printf("\nDigite o nome do funcion�rio n� %d\n", cont.i + 1);
					gets(fun[cont.i].nome); // Recebendo o nome do funcion�rio
					printf("Digite quanto o funcion�rio %s vendeu nos meses de:\nNovembro: R$ ", fun[cont.i].nome);
					scanf("%f", &fun[cont.i].novembro); // Vendas do m�s de novembro
					printf("Dezembro: R$ ");
					scanf("%f", &fun[cont.i].dezembro); // Vendas do m�s de dezembro
					printf("Janeiro: R$ ");
					scanf("%f", &fun[cont.i].janeiro); // Vendas do m�s de janeioro
					fflush(stdin);
					
					fun[cont.i].novp = (fun[cont.i].novembro / 100); // Calculando a pontua��o do m�s de novembro 
					fun[cont.i].dezp = (fun[cont.i].dezembro / 100); // Calculando a pontua��o do m�s de dezembro
					fun[cont.i].janp = (fun[cont.i].janeiro / 100); // Calculando a pontua��o do m�s de janeiro
					
					// Calculando a pontua��o geral de cada funcion�rio
					fun[cont.i].pontg = (fun[cont.i].novp + fun[cont.i].dezp + fun[cont.i].janp); 
					
					// Condi��o para encontrar o vendedor com a maior pontua��o
					if(cont.soma_maior < fun[cont.i].pontg){
						cont.soma_maior = fun[cont.i].pontg;
						strcpy(cont.campeao, fun[cont.i].nome);
					}
					
					// Calculando o total de vendas de cada funcion�rio
					fun[cont.i].total_vendas = (fun[cont.i].janeiro + fun[cont.i].dezembro + fun[cont.i].novembro);
					
					// Realizando o somat�tio das vendas de todos os funcion�rios
					cont.total_vendas += fun[cont.i].total_vendas;
				}
			break;
			
			// Mostrar a pontua��o de todos os funcion�rios a cada m�s
			case 2:
				for(cont.i = 0; cont.i < 2; cont.i++){ // Varrendo o vetor funcion�rios
					printf("O funcion�rio %s atingiu as seguintes pontu��es:\n", fun[cont.i].nome);
					// Imprimindo a pontua��o de cada m�s
					printf("Novembro: %d\n", fun[cont.i].novp);
					printf("Dezembro: %d\n", fun[cont.i].dezp);
					printf("Janeiro: %d\n\n", fun[cont.i].janp);
				}
			break;
			
			// Imprimindo o total de pontos de todos os funcion�rios 
			case 3:
				for(cont.i = 0; cont.i < 2; cont.i++){
					printf("O funcion�rio %s possui um total de %d pontos\n", fun[cont.i].nome, fun[cont.i].pontg);
				}
			break;
			
			// Mostrando o vendedor campe�o de vendas e seu total de pontos
			case 4:
				printf("O funcion�rio %s � o campe�o de vendas com %d pontos\n", cont.campeao, cont.soma_maior);
			break;
			
			// Mostrando o somat�rio total de entre os vendedores em reais
			case 5:
				printf("O total vendido por todos os funcion�rio � de: R$ %.2f\n", cont.total_vendas);
			break;
		}
	}
	return 0;
}
