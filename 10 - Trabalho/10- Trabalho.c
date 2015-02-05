#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Matricula{
	int cod_aluno;
	int indica_6;
	char descricao[30];
	int cod_disciplina;
	int total_faltas;
	float nota_final;
	float max_faltas;
};

struct Aluno{
	char reprovado[30];
	char nome[30];
	int codigo;
	int serie;
	struct Matricula matricula[3];
};

struct Contadores{
	int op;
	int contador;
	int i;
	int teste_cod;
	int aux;
	int conta_aluno;
	int conta_matricula;
	int j;
	int procura_disciplina;
};

struct Diciplinas{
	int cod_disciplina;
	char descricao[30];
	int carga_horaria;
	float max_faltas;
};

int main(int argc, char *argv[]) { setlocale(LC_ALL, "Portuguese");
	struct Aluno aluno[10];
	struct Diciplinas disciplina[6];
	struct Contadores cont;
	cont.aux = 0;
	cont.contador = 0;
	cont.conta_aluno = 0;
	cont.conta_matricula = 0;
	while(cont.op != 7){
		printf("\n|---------------- Menu de Opções ---------------------|\n");
		printf("| 1- Cadastrar Disciplina                             |\n");
		printf("| 2- Cadastrar Aluno                                  |\n");
		printf("| 3- Realizar Matricula em Disciplina                 |\n");
		printf("| 4- Lançar Resultados Finais                         |\n");
		printf("| 5- Consultar Alunos Reprovados                      |\n");
		printf("| 6- Mostrar Disciplinas Cursadas por um Aluno        |\n");
		printf("| 7- Sair                                             |\n");
		printf("|Digite o numero da opção desejada:                   |\n");
		printf("|-----------------------------------------------------|\n");
		scanf("%d", &cont.op);
		fflush(stdin);
		
		switch(cont.op){
			case 1:
				// Verificando se foi atingido o limite de disciplinas
				if(cont.aux == 2){
					printf("Já estão Cadastradas as 6 Disciplinas Possíveis!\n");
					break;
				}
				
				// Recebendo o codigo da disciplina
				printf("\nEntre com o codigo da disciplina: ");
				scanf("%d", &cont.teste_cod);
				fflush(stdin);
				
				//Verificando se já existe disciplina com o codigo digitado
				
				if(cont.teste_cod == disciplina[0].cod_disciplina && cont.teste_cod == disciplina[1].cod_disciplina && cont.teste_cod == disciplina[2].cod_disciplina && cont.teste_cod == disciplina[3].cod_disciplina && cont.teste_cod == disciplina[4].cod_disciplina && cont.teste_cod == disciplina[5].cod_disciplina){
					printf("Código Inválido\n");
					break;
				} else {
					if(cont.teste_cod != disciplina[0].cod_disciplina && cont.teste_cod != disciplina[1].cod_disciplina && cont.teste_cod != disciplina[2].cod_disciplina && cont.teste_cod != disciplina[3].cod_disciplina && cont.teste_cod != disciplina[4].cod_disciplina && cont.teste_cod != disciplina[5].cod_disciplina){
					
						// Recebendo os dados da disciplina
						disciplina[cont.aux].cod_disciplina = cont.teste_cod;
						printf("\nEntre com o nome da disciplina: ");
						gets(disciplina[cont.aux].descricao);
						printf("\nEntre com a carga horária da disciplina: ");
						scanf("%d", &disciplina[cont.aux].carga_horaria);
						// calculando o máximo de faltas possível na disciplina
						disciplina[cont.aux].max_faltas = (disciplina[cont.aux].carga_horaria * 0,25);
						printf("A disciplina %s foi fadastrada com sucesso!\n", disciplina[cont.aux].descricao);
						cont.aux++;// Incremento no contador de disiciplinas
						break;
					}
				}
				
			case 2:
				// Verificando se ainda a vagas para cadastrar aluno
				if(cont.conta_aluno == 2){
					printf("A escola está com todas as vagas preenchidas!\n");
					break;
				}
				
				// Recebendo o codigo do aluno
				printf("\nEntre com o codigo do aluno: ");
				scanf("%d", &cont.teste_cod);
				fflush(stdin);
				
				// Verificando se existe aluno cadastrado com o codigo digitado
				if(cont.teste_cod == aluno[0].codigo && cont.teste_cod == aluno[1].codigo){
					printf("Codigo Inválido!\n");
					break;
				} else{ // Recebendo os dados do aluno
					if(cont.teste_cod != aluno[0].codigo && cont.teste_cod != aluno[1].codigo){
						aluno[cont.conta_aluno].codigo = cont.teste_cod;
						printf("\nDigite o nome do aluno: ");
						gets(aluno[cont.conta_aluno].nome);
						printf("\nDigite a série: ");
						scanf("%d", &aluno[cont.conta_aluno].serie);
						
						// Mostrar mensagem caso seja digitado serie inválida e receber novamente
						if(aluno[cont.conta_aluno].serie != 8 && aluno[cont.conta_aluno].serie != 5 && aluno[cont.conta_aluno].serie != 6 && aluno[cont.conta_aluno].serie != 7){
							printf("\nEstão disponíveis somente de 5 a 8 para as series! Digite novamente: ");
							scanf("%d", &aluno[cont.conta_aluno].serie);
						}
						// Confirmando a matricula
						printf("O aluno %s foi cadastrado com sucesso!\n", aluno[cont.conta_aluno].nome);
						cont.conta_aluno++;
						break;
					}
				}
			
			case 3:
				// Recebendo o codigo do aluno
				printf("\nEntre com o codigo do aluno: ");
				scanf("%d", &cont.teste_cod);
				fflush(stdin);
				
				// Verificando se há aluno com o código digitado
				if(cont.teste_cod != aluno[0].codigo && cont.teste_cod != aluno[1].codigo){
					printf("Codigo inválido!\n");
					break;
				}
				
				// Procurando aluno entre os matriculados
				for(cont.i = 0; cont.i < 2; cont.i++){
					// Depois de encontrar o aluno recebe o codigo da disciplina
					if(cont.teste_cod == aluno[cont.i].codigo){
						aluno[cont.i].matricula[cont.conta_matricula].cod_aluno = cont.teste_cod;
						printf("\nDigite o codigo da disciplina: ");
						scanf("%d", &cont.teste_cod);
						fflush(stdin);
						
						// Recebendo o limite de faltas da disciplina que já está cadastrada e o nome da disciplina na matricula
						for(cont.j = 0; cont.j < 2; cont.j++){
							if(cont.teste_cod == disciplina[cont.j].cod_disciplina){
								aluno[cont.i].matricula[cont.conta_matricula].max_faltas = disciplina[cont.j].max_faltas;
								strcpy(aluno[cont.i].matricula[cont.conta_matricula].descricao, disciplina[cont.j].descricao);
							}
						}
						// Verificando se existe disciplina com o codigo digitado
						if(cont.teste_cod != disciplina[0].cod_disciplina && cont.teste_cod != disciplina[1].cod_disciplina){
							printf("Codigo Inválido!\n");
							break;
						}else {
							
							// Matriculando o aluno em disciplina
							aluno[cont.i].matricula[cont.conta_matricula].cod_disciplina = cont.teste_cod;
							// A indica_6 será utilizada no caso 6	
							aluno[cont.i].matricula[cont.conta_matricula].indica_6 = 1;
							printf("Matricula realizada com sucesso!\n");
							cont.conta_matricula++;
							break;
						}
					}
				}
				break;
				
			case 4:
				// Recebendo o codigo do aluno
				printf("\nEntre com o codigo do aluno: ");
				scanf("%d", &cont.teste_cod);
				fflush(stdin);
				
				// Verificando se há aluno com o código digitado
				if(cont.teste_cod != aluno[0].codigo && cont.teste_cod != aluno[1].codigo){
					printf("Codigo inválido!\n");
					break;
				}
				
				// Procurando aluno através do codigo digitado
				for(cont.i = 0; cont.i < 2; cont.i++){
					if(cont.teste_cod == aluno[cont.i].codigo){
						// Recebendo o codigo da disciplina que será cadastrado as faltas e a nota final
						printf("\nDigite o codigo da disciplina: ");
						scanf("%d", &cont.procura_disciplina);
						fflush(stdin);
						//Procurando disciplina
						for(cont.j = 0; cont.j < 3; cont.j++){
							if(cont.procura_disciplina == aluno[cont.i].matricula[cont.j].cod_disciplina){
								// Recebendo o total de faltas e a nota final
								printf("\nEntre com o total de faltas do aluno %s: ", aluno[cont.i].nome);
								scanf("%d", &aluno[cont.i].matricula[cont.j].total_faltas);
								fflush(stdin);
								
								printf("\nEntre com a nota final do aluno %s: ", aluno[cont.i].nome);
								scanf("%f", &aluno[cont.i].matricula[cont.j].nota_final);
								fflush(stdin);
								printf("Os dados foram lançados com sucesso!\n");
								break;
							}
						}
					}
				}
			break;
				
			case 5:
				// Mostrar alunos reprovados
				for(cont.i = 0; cont.i < 2; cont.i++){
					for(cont.j = 0; cont.j < 2; cont.j++){
						// Se o aluno estiver reprovado na disciplina seu nome será copiado para outra variável
						if(aluno[cont.i].matricula[cont.j].nota_final < 7 && aluno[cont.i].matricula[cont.j].total_faltas > aluno[cont.i].matricula[cont.j].max_faltas){
							strcpy(aluno[cont.i].reprovado, aluno[cont.i].nome);
							cont.contador++;
						}else{
							break;
						}
					}
				}
				getchar();
				// Se houver aluno reprovado imprimir lista 
				if(cont.contador == 0){
					break;
				}else{
					for(cont.i = 0; cont.i < cont.contador; cont.i++){
						printf("%s\n", aluno[cont.i].reprovado);
					}
				}
			break;
			
			case 6:
				// Recebendo o codigo do aluno
				printf("\nEntre com o codigo do aluno: ");
				scanf("%d", &cont.teste_cod);
				fflush(stdin);
				for(cont.i = 0; cont.i < 2; cont.i++){
					// Procurando por aluno que tenha o codigo digitado
					if(cont.teste_cod == aluno[cont.i].codigo){
						for(cont.j = 0; cont.j < 2; cont.j++){
							// Encontrando disciplinas matriculadas e imprimindo variáveis
							if(aluno[cont.i].matricula[cont.j].indica_6 == 1){// Utilizando variável criada para indicar que a posição do vetor está ocupada
								printf("Disciplina: %s\nFaltas: %d\nNota final: %.1f\n", aluno[cont.i].matricula[cont.j].descricao, aluno[cont.i].matricula[cont.j].total_faltas, aluno[cont.i].matricula[cont.j].nota_final);
								// Verificando se aluno está reprovado ou aprovado e mostra o resultado
								if(aluno[cont.i].matricula[cont.j].nota_final < 7){
									printf("Reprovado\n");
								}else{
									printf("Aprovado");
								}
							}
						}
					}
				}
			break;		
		}
	}
	return 0;
}
