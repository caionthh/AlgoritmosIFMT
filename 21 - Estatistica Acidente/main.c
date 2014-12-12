#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct dos estados
struct Estado {
	char *nome; //Nome como um vetor
	int numeroVeiculos; //Numeros de veiculos circulando
	int numeroAcidentes; //Numero de acidentes	
	int percentual; //Percentual de carros em relação a quantidade total de estados
	float mediaAcidentes; //Media de acidentes
} *estados; //Estados como um vetor
int quantEstados = 0; //Quantidade de estados registrados

//Struct de estatistica
struct Estatistica {
	char *estadoMenorIndice, *estadoMaiorIndice; //Nome dos estados com maior e menor indice
	int indiceMenor, indiceMaior; //Maior e menor indice de acidentes
	int somaGeralVeiculos; //Soma de todos os veiculos
} estatistica;

//Adicionar Estado - Pede Nome, quantidade de veiculos circulando, numero de acidentes
void AdicionarEstado(char *nome, int veiculos, int acidentes) {
	
	//Realoca memoria do vetor de estados
	quantEstados += 1; // Adiciona um estado
	estados = realloc(estados, quantEstados * sizeof(struct Estado)); //Usa função realloc para aumentar a memoria registrada pro vetor de estados
	
	//Cadastra novo estado
	estados[quantEstados-1].nome = nome;
	estados[quantEstados-1].numeroVeiculos = veiculos;
	estados[quantEstados-1].numeroAcidentes = acidentes;
	
	//Adicionar veiculos a soma geral
	estatistica.somaGeralVeiculos += veiculos;
	
	//Verifica se este estado tem um indice acima do atual maior
	if (acidentes > estatistica.indiceMaior) {
		estatistica.estadoMaiorIndice = nome; //Passa nome do estado
		estatistica.indiceMaior = acidentes; //Passa acidentes do estado
	}
	//Menor que o menor indice ou o indice menor nao foi configurado
	if (acidentes < estatistica.indiceMenor || estatistica.indiceMenor == 0) {
		estatistica.estadoMenorIndice = nome; //Passa nome do estado
		estatistica.indiceMenor = acidentes; //Passa acidentes do estado;
	}
	
	//Calcular media de acidentes
	estados[quantEstados-1].mediaAcidentes = (acidentes + veiculos) / 2;
	
	//Gira entre todos os estados e faz as verificacoes necessarias
	int i = 0;
	for (i = 0; i < quantEstados; i++) {
				
		//Calcula Percentual novo deste estado
		estados[i].percentual = 100 * ( estados[i].numeroVeiculos / estatistica.somaGeralVeiculos );
	}	
}

//Ler Novo Estado
void LerNovoEstado() {
	
	//Estado
	char nome[255];
	int acidentes = 0, veiculos = 0;
	
	//Ler novo estado
	printf("Cadastre um novo estado: \n");
	printf("\tNome: ");
	fflush(stdin); //Limpa stdin
	fgets(&nome, 255, stdin); //Usa fgets para ler o nome de forma segura
	fflush(stdin); //Limpa stdin
	printf("\n\tVeiculos: ");
	scanf("%d", &veiculos); //Le Veiculos
	fflush(stdin); //Limpa stdin
	printf("\n\tAcidentes: ");
	scanf("%d", &acidentes); //Le Acidentes
	fflush(stdin); //Limpa stdin
	printf ("\n########################################\n");
	
	//Adicionar estado
	AdicionarEstado(nome, veiculos, acidentes);
}

//Mostra Indices
void MostraIndices() {
	
	//Mostra Maior
	printf("Indices de Acidente:\n");
	printf("\tMaior Indice pertence a: %s\n", estatistica.estadoMaiorIndice);
	printf("\tNumero de acidentes: %d\n", estatistica.indiceMaior);
	printf("\n");
	printf("\tMenor Indice pertence a: %s\n", estatistica.estadoMenorIndice);
	printf("\tNumero de acidentes: %d\n", estatistica.indiceMenor);
	
}

void MostraEstatisticas() {
	
	//Mostra Estatisticas
	printf("Estatisticas dos Estados:\n");
	
	//Quantidade de carros
	printf("\n\tExistem %d estados registrados, totalizando % veiculos.", quantEstados, estatistica.somaGeralVeiculos);
	
	//Mostra para cada Estado cadastrado
	int i = 0;
	for ( i = 0; i < quantEstados; i++) {
		
		printf("\t%s:\n", estados[i].nome);
		printf("\tVeiculos: %d\n", estados[i].numeroVeiculos);
		printf("\tAcidentes: %d\n", estados[i].numeroAcidentes);
		printf("\tPercentual: %d\n", estados[i].percentual);
		printf("\tMedia: %.2f\n", estados[i].mediaAcidentes);
		
		printf("\n\n");
	}
	
}

int main(int argc, char *argv[]) {

	//Menu
	int opt = -1;
	
	do {
		//Checa se ha um numero de estados registrados suficiente
		if (quantEstados < 1) {
					
			//Limpa Tela
			system("cls");
			
			//Numero de estados minimo nao atingido
			printf ("########################################");
			printf("\nNumero de estados minimo nao atingido.");
			printf("\nNecessario 15, registrados: %d", quantEstados);
			printf("\n\n\n");
				
			//Ler Estado
			LerNovoEstado();
			
		}
		else
		{
			//Limpar Tela
			system("cls");
			
			//Menu
			printf ("########################################\n");
			printf("\n");
			printf("\tMenu de Estados");
			printf("\n");
			printf("\t1-Adicionar Novo Estado\n");
			printf("\t2-Mostrar Indices de acidentes\n");
			printf("\t3-Mostrar Estatisticas\n");
			printf("\t0-Sair\n\n");
			printf ("########################################\n");
			printf("Digite a opcao desejada: ");
			scanf("%d", &opt);
			
			switch(opt) {
				
				//Sair
				case 0:
					break;
				
				//Adicionar Estado
				case 1:
					printf("\n\n");
					LerNovoEstado();
					break;
					
				case 2:
					printf("\n\n");
					MostraIndices();
					getch();
					break;
					
				case 3:
					printf("\n\n");
					MostraEstatisticas();
					getch();
					break;
				
			}
		}	
		
	} while (opt != 0);


	
	return 0;
}
