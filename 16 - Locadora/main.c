#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Prototipos
void NovoCliente(char nome[255], int dN, int mN, int aN, int rg, int cpf, char end[255], char cid[255], char est[255]);
void PerguntarDados();
void RemoveCliente();
void MostrarClientes(int);
void Locar();
void Devolver();

//Client
struct Cliente {
	int cod;
	char nome[255];
	int diaN, mesN, anoN;
	int rg, cpf;
	char endereco[255], cidade[255], estado[255];
	int totalLocado, locado;
	int removido;
} *clientes;
int numClientes = 0; //Guarda o valor atual de clientes



int main(int argc, char *argv[]) {
	
	//Menu
	int opt = -1;
	do {
		//Limpar tela
		system("cls");
	
		//Mostrar Menu
		printf("#############################################\n");
		printf("           Controle Locadora\n\n");
		printf("\t1 - Cadastrar cliente\n");
		printf("\t2 - Clientes cadastrados\n");
		printf("\t3 - Remover cliente\n");
		printf("\t4 - Locar\n");
		printf("\t5 - Devolucao\n");
		printf("\t6 - Clientes com itens locados\n");
		printf("\t0 - Sair\n\n");
		printf("#############################################\n");
		printf("Digite a opcao desejada: ")	;
		scanf("%d", &opt);
		
		//Interpretar o menu
		switch (opt) {

			//Cadastrar Cliente
			case 1:
				system("cls"); //Limpar tela
				
				//Cadastrar
				PerguntarDados();
				
				//esperar
				getch();
				
				break;

			//Mostrar Clientes
			case 2:
				system("cls"); //Limpar tela
				
				//Mostrar
				MostrarClientes(0); //Mostra todos os clientes (int locados = 0)
				
				//Esperar
				getch();
				
				break;

			//Remover cliente
			case 3:
				
				//Limpar tela
				system("cls");
				
				//Remover
				RemoveCliente();
				
				//Esperar
				getch();
				
				break;
				
			//Locar
			case 4:
				
				//Limpar tela
				system("cls");
				
				//Locar
				Locar();
				
				//Esperar
				getch();
				
				break;
				
			//Devolver
			case 5:
				system("cls"); //Limpar tela
				
				//Devolver
				Devolver();
				
				//Esperar
				getch();
				
				break;				
				
			//Mostrar Clientes
			case 6:
				system("cls"); //Limpar tela
				
				//Mostrar
				MostrarClientes(1); //Mostra clientes com itens (int locados = 1)
				
				//Esperar
				getch();
				
				break;

			//Sair
			case 0:
				break;

			default:
				system("cls");
				printf("Opcao invalida.");
				getch();
				break;	
		}
		
	} while (opt != 0);
	
	
	return 0;
}

//Perguntar Dados
void PerguntarDados() {
	
	//Dados
	char nome[255];
	int dN, mN, aN;
	int rg, cpf;
	char end[255], cid[255], est[255];
	
	//Nome
	printf("\n\nNome do cliente: ");
	fflush(stdin);
	gets(nome); // Pegar nome
	
	//Data
	printf("\nData de Nascimento (dd mm aaaa): ");
	fflush(stdin);
	scanf("%d%d%d", &dN, &mN, &aN);
	
	//RG CPF
	printf("\nRG: ");
	fflush(stdin);
	scanf("%d", &rg);
	printf("\nCPF: ");
	fflush(stdin);
	scanf("%d", &cpf);
	
	//Endereco
	printf("\nEndereco do cliente: ");
	fflush(stdin); //Flush
	gets(end);
	printf("\nCidade: ");
	fflush(stdin); //Flush
	gets(cid);
	printf("\nEstado: ");
	fflush(stdin); //Flush
	gets(est);
	
	//DEBUG
	//printf("%s, %d, %d, %d, %d, %d, %s, %s, %s", nome, dN, mN, aN, rg, cpf, end, cid, est);
	
	//Criar
	NovoCliente(nome, dN, mN, aN, rg, cpf, end, cid, est);	
	
}


//Novo Cliente
void NovoCliente(char nome[255], int dN, int mN, int aN, int rg, int cpf, char end[255], char cid[255], char est[255]) {
	
	//Realocar
	numClientes++; //Somar um cliente
	clientes = realloc(clientes, numClientes * sizeof(struct Cliente)); //Realocar a memoria da array de clientes	
	
	//Passar detalhes do cliente
	clientes[numClientes-1].cod = numClientes; //Passar Codigo
	strcpy(clientes[numClientes-1].nome, nome); //Copiar nome
	clientes[numClientes-1].diaN = dN; //Dia data de nascimento
	clientes[numClientes-1].mesN = mN; //Mes data de nascimento
	clientes[numClientes-1].anoN = aN; //Ano data de nascimento
	clientes[numClientes-1].rg = rg; //RG
	clientes[numClientes-1].cpf = cpf; //CPF
	strcpy(clientes[numClientes-1].endereco, end); //Copiar endereco
	strcpy(clientes[numClientes-1].cidade, cid); //Copiar Cidade
	strcpy(clientes[numClientes-1].estado, est); //Copiar estado
	clientes[numClientes-1].totalLocado = 0;
	clientes[numClientes-1].locado = 0;
	clientes[numClientes-1].removido = 0;

	//Cadastrado
	printf("\n\nNovo cliente cadastrado. COD: %d", clientes[numClientes-1].cod);
}

//Mostrar todos os Clientes
void MostrarClientes(int locados) {
	
	//Rodar todos
	int cliente = 0;
	for (cliente = 0; cliente < numClientes; cliente++) {
		
		//Todos
		if (locados == 0) {
		
			if (clientes[cliente].removido == 0) {
				
				//Mostrar Nome
				printf("\n%s:\n ", clientes[cliente].nome);
				//Mostrar Data
				printf("\tNascimento: %d/%d/%d\n", clientes[cliente].diaN, clientes[cliente].mesN, clientes[cliente].anoN);
				//Mostrar RG
				printf("\tRG: %d\n", clientes[cliente].rg);
				//Mostrar CPF
				printf("\tCPF: %d\n", clientes[cliente].cpf);
				//Mostrar Endereco
				printf("\tEndereco: %s\n", clientes[cliente].endereco);
				//Mostrar Cidade
				printf("\tCidade: %s\n", clientes[cliente].cidade);
				//Mostrar Estado
				printf("\tEstado: %s\n", clientes[cliente].estado);
				//Locados
				printf("\tItens locados: %d itens.\n", clientes[cliente].locado);
				//Ja locou
				printf("\tJa locou: %d itens.\n", clientes[cliente].totalLocado);
				//Codigo
				printf("\tCod: %d\n", clientes[cliente].cod);
				
			}
		}
		else {
			
			if (clientes[cliente].removido == 0 && clientes[cliente].locado != 0) {
				
				//Mostrar Nome
				printf("\n%s:\n ", clientes[cliente].nome);
				//Mostrar Data
				printf("\tNascimento: %d/%d/%d\n", clientes[cliente].diaN, clientes[cliente].mesN, clientes[cliente].anoN);
				//Mostrar RG
				printf("\tRG: %d\n", clientes[cliente].rg);
				//Mostrar CPF
				printf("\tCPF: %d\n", clientes[cliente].cpf);
				//Mostrar Endereco
				printf("\tEndereco: %s\n", clientes[cliente].endereco);
				//Mostrar Cidade
				printf("\tCidade: %s\n", clientes[cliente].cidade);
				//Mostrar Estado
				printf("\tEstado: %s\n", clientes[cliente].estado);
				//Locados
				printf("\tItens locados: %d itens.\n", clientes[cliente].locado);
				//Ja locou
				printf("\tJa locou: %d itens.\n", clientes[cliente].totalLocado);
				//Codigo
				printf("\tCod: %d\n", clientes[cliente].cod);
				
			}
		}
	}

}

//Remove
void RemoveCliente() {
	
	//Ler cod
	int cod = 0;
	printf("\n\nDigite o codigo do cliente: ");
	scanf("%d", &cod);
	
	
	//Escolher cliente
	int c = 0;
	for (c = 0; c < numClientes; c++) {
		
		//Codigo
		if (clientes[c].cod == cod) {
		
			//Apagar dados do cliente se nao houver locacao
			if (clientes[c].locado == 0 && clientes[c].removido == 0) {
				
				//Limpar dados
				strcpy(clientes[c].nome, "");
				clientes[c].diaN = 0;
				clientes[c].mesN = 0;
				clientes[c].anoN = 0;
				clientes[c].rg = 0;
				clientes[c].cpf = 0;
				strcpy(clientes[c].endereco, "");
				strcpy(clientes[c].cidade, "");
				strcpy(clientes[c].estado, "");
				clientes[c].totalLocado = 0;
				clientes[c].locado = 0;
				clientes[c].removido = 1;
				
			}
			else {
				
				printf("\nCliente não existe ou possui itens locados.\n");
				
			}
		
			break;	
		}
		
	}
	
}

//Locar
void Locar() {
	
	//Cod
	int cod;
	printf("\nCodigo do cliente: ");
	scanf("%d", &cod);	
	
	//Escolher cliente
	int c = 0;
	for (c = 0; c < numClientes;c++) {
		
		//Cliente por cod
		if (clientes[c].cod == cod) {
			
			//nao ha itens locados e nao foi removido
			if (clientes[c].locado == 0 && clientes[c].removido == 0)	 {
				
				//Locar
				printf("\nQuantas itens deseja locar: ");
				int itens = 0;
				scanf("%d", &itens);
				clientes[c].totalLocado += itens;
				clientes[c].locado = itens;
				printf("\n\nLocado %d itens para o cliente %s.\n\n", itens, clientes[c].nome);
				
			}
			else
			 {
			 	printf("Cliente nao existe ou ja possui itens locados.");
			 }
			
			
			break;
		}
			
	}
	
}

//Devolver
void Devolver() {
	
	//Cod
	int cod = 0;
	printf("Digite o codigo do cliente: ");
	scanf("%d", &cod);
	
	
	//Escolher Cliente
	int c = 0;
	for (c = 0; c < numClientes; c++) {
		
		//Por Codigo
		if (clientes[c].cod == cod) {
			
			//Nao removido
			if (clientes[c].removido == 0) {
			
				//Itens
				int itens = 0;
				printf("\n\nQuantos itens deseja devolver: ");
				scanf("%d", &itens);
				
				//Devolucao possivel
				if (itens <= clientes[c].locado) {
					clientes[c].locado -= itens;
					
					printf("\nDevolvido %d itens do cliente %s, cliente possui %d itens locados.", itens, clientes[c].nome, clientes[c].locado);
				}
				else
					printf("\nNao e possivel devolver mais que a quantidade de itens locados.\n\n");
				
			}
			else
				printf("\nCliente nao existe.");
			
			break;
			
		}
		
	}
	
	
}

