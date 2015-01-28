#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Documentos{
	int num_doc;
	int cod_cliente;
	int data_venc;
	int data_pag;
	float valor;
	float juros;
};
struct Clientes{
	int cod_cliente;
	char nome[30];
	char fone[15];
	char cidade[30];
	char estado[30];
	char rua[30];
	int numero;
	struct Documentos documentos[2];
};

struct Contadores{
	int op;
	int auxiliar;
	int data_in;
	int data_fin;
	int i;
	int organiza;
	int conta_clientes;
	int j;
	int conta_doc;
	int conta_8;
	int cont;
	int teste_cod;
};

int main(int argc, char *argv[]) { setlocale(LC_ALL, "portuguese");
	struct Clientes clientes[2];
	struct Contadores aux;
	aux.cont = 0;
	aux.conta_doc = 0;
	aux.conta_clientes = 0;
	// Utilizando while para o menu  de op��es
	while(aux.op != 9){
		printf("\n------- Op��es --------\n");
		printf("1- Cadastrar Clintes\n");
		printf("2- Cadastrar Documentos\n");
		printf("3- Excluir Clientes\n");
		printf("4- Excluir Documentos Individuais\n");
		printf("5- Excluir Documentos por Cliente\n");
		printf("6- Excluir Documentos por Per�odo\n");
		printf("7- Alterar as Informa��es sobre os Clientes\n");
		printf("8- Mostrar o Total de Documentos de um Cliente\n");
		printf("9- Sair\n");
		printf("Digite a op��o desejada:\n\n");
		scanf("%d", &aux.op);
		fflush(stdin);
		
		switch(aux.op){
			
			// Cadastrando clientes
			case 1:
				if(aux.cont == 2){// Condi��o caso o limite de clientes seja atingido
					printf("Limite de clientes foi atingido\n");
					break;
				}
				printf("Digite o codigo do cliente: ");
				scanf("%d", &aux.teste_cod);// Recebendo o codigo para procurar o cliente
				fflush(stdin);
				
				// Verificando se j� existe um cliente com o codigo digitado
				if(aux.teste_cod == clientes[0].cod_cliente && aux.teste_cod == clientes[1].cod_cliente){
					printf("Codigo inv�lido");// Caso j� exista cliente com esse codigo mostrar a mensagem e sair
					break;
				} else{ // Caso contr�rio recebe os dados do cliente
					if(aux.teste_cod != clientes[0].cod_cliente && aux.teste_cod != clientes[1].cod_cliente){
						clientes[aux.cont].cod_cliente = aux.teste_cod;
						printf("Digite o nome do cliente: ");
						gets(clientes[aux.cont].nome);
						printf("Digite o endere�o do cliente\nCidade: ");
						gets(clientes[aux.cont].cidade);
						printf("Estado: ");
						gets(clientes[aux.cont].estado);
						printf("Rua: ");
						gets(clientes[aux.cont].rua);
						printf("Telefone: ");
						gets(clientes[aux.cont].fone);
						printf("Numero: ");
						scanf("%d", &clientes[aux.cont].numero);
						fflush(stdin);
						aux.cont++;
						break;
					}
				}
				
			case 2:
				if(aux.conta_doc > 2){ // Se for atingido o limite de documentos mostrar mensagem e sair
					printf("O limite de documentos foi atingido\n");
					break; 
				}
				
				printf("Entre com o codigo do cliente que deseja cadastrar um documento: ");
				scanf("%d", &aux.teste_cod);
				fflush(stdin); // Recebendo codigo para procurar cliente
				
				// Se n�o for encontrado cliente mostrar mensagem e sair
				if(aux.teste_cod != clientes[0].cod_cliente && aux.teste_cod != clientes[1].cod_cliente){
					printf("Codigo inv�lido\n");
					break;
				}
				
				// Encontrando o cliente e cadastrando o documento em seu nome
				for(aux.i = 0; aux.i < 2; aux.i++){
					for(aux.j = 0; aux.j < 2; aux.j++){
						if(aux.teste_cod == clientes[aux.i].cod_cliente){
							// Recebendo os dados do documento
							clientes[aux.i].documentos[aux.conta_doc].cod_cliente = aux.teste_cod;
							printf("Digite o numero do documento: ");
							scanf("%d", &clientes[aux.i].documentos[aux.conta_doc].num_doc);
							printf("Digite a data de vencimento do documento: ");
							scanf("%d", &clientes[aux.i].documentos[aux.conta_doc].data_venc);
							printf("Digite a data de pagamento do documento: ");
							scanf("%d", &clientes[aux.i].documentos[aux.conta_doc].data_pag);
							printf("Digite o valor do documento: ");
							scanf("%f", &clientes[aux.i].documentos[aux.conta_doc].valor);
						
							/* Calculando o campo juros do documento caso tenha sido pago com atraso
						 	ser� cobrado uma taxa de 5 % */
							if(clientes[aux.i].documentos[aux.conta_doc].data_pag > clientes[aux.i].documentos[aux.conta_doc].data_venc){
								clientes[aux.i].documentos[aux.conta_doc].juros = (clientes[aux.i].documentos[aux.conta_doc].valor * 0,05);
							}
							aux.conta_doc++;
							break;
						}
					}
				}
				break;
				
			case 3:
				// Recebendo o codigo do cliente que ser� exclu�do
				printf("Entre com o codigo do cliente que deseja excluir: ");
				scanf("%d", &aux.teste_cod);
				fflush(stdin);
				
				// Se n�o existir cliente com o codigo digitado mostrar a mensagem e sair
				if(aux.teste_cod != clientes[0].cod_cliente && aux.teste_cod != clientes[1].cod_cliente){
					printf("Codigo inv�lido");
					break;
				}
				
				// Procurando o cliente que ser� exclu�do
				for(aux.i = 0; aux.i < 2; aux.i++){
					for(aux.j = 0; aux.j < 2; aux.j++){
						if(aux.teste_cod == clientes[aux.i].cod_cliente){
							clientes[aux.i].cod_cliente = 0;
							printf("O cliente %s foi exclu�do\n", clientes[aux.i].nome);
							// Reorganizando o vetor ap�s excluir o cliente
							aux.auxiliar = clientes[aux.i].cod_cliente;
							clientes[aux.i].cod_cliente = clientes[aux.j].cod_cliente;
							clientes[aux.j].cod_cliente = aux.auxiliar;
							aux.cont--;
						}
					}
				}
				break;
			case 4:
				// Recebendo o codigo do cliente que deseja procurar documento em seu nome
				printf("Entre com o codigo do cliente que deseja excluir documentos que est�o em seu nome: ");
				scanf("%d", &aux.teste_cod);
				
				// Procurando o cliente
				for(aux.i = 0; aux.i < 2; aux.i++){
					// Quando encontrado o cliente entrar com o numero do documento
					if(aux.teste_cod == clientes[aux.i].cod_cliente){
						printf("Digite o numero do documento: ");
						scanf("%d", &aux.auxiliar);
						// Condi��o caso n�o haja documento com o numero digitado
						if(aux.auxiliar != clientes[aux.i].documentos[0].num_doc && aux.auxiliar != clientes[aux.i].documentos[1].num_doc){
							printf("Documento n�o encontrado!\n");
							break;
						}
						
						// Procurando documento pelo numero
						for(aux.j = 0; aux.j < 2; aux.j++){
							if(aux.auxiliar == clientes[aux.i].documentos[aux.j].num_doc){
								printf("O documento n�: %d foi exclu�do\n", clientes[aux.i].documentos[aux.j].num_doc);
								clientes[aux.i].documentos[aux.j].cod_cliente = 0;
								clientes[aux.i].documentos[aux.j].num_doc = 0;
								aux.conta_doc--;
								
								// Reorganizando o vetor ap�s excluir o documento 
								aux.organiza = clientes[aux.i].documentos[aux.i].cod_cliente;
								clientes[aux.i].documentos[aux.i].cod_cliente = clientes[aux.i].documentos[aux.j].cod_cliente;
								clientes[aux.i].documentos[aux.j].cod_cliente = aux.organiza;
								break;
							}
						}
					}
				}
				
			case 5:
				printf("Entre com o codigo do cliente que deseja excluir os documentos em seu nome: ");
				scanf("%d", &aux.teste_cod);
				
				if(aux.teste_cod != clientes[0].cod_cliente && aux.teste_cod != clientes[1].cod_cliente){
					printf("Cliente n�o encontrado\n\n");
					break;
				}
				
				for(aux.i = 0; aux.i < 2; aux.i++){
					if(aux.teste_cod == clientes[aux.i].cod_cliente){
						for(aux.j = 0; aux.j < 2; aux.j++){
							if(aux.teste_cod == clientes[aux.i].documentos[aux.j].cod_cliente){
								printf("O documento n�: %d foi exclu�do\n\n", clientes[aux.i].documentos[aux.j].num_doc);
								clientes[aux.i].documentos[aux.j].cod_cliente = 0;
								clientes[aux.i].documentos[aux.j].num_doc = 0;
								aux.conta_doc--;
								
								// Reorganizando o vetor ap�s excluir o documento 
								aux.organiza = clientes[aux.i].documentos[aux.i].cod_cliente;
								clientes[aux.i].documentos[aux.i].cod_cliente = clientes[aux.i].documentos[aux.j].cod_cliente;
								clientes[aux.i].documentos[aux.j].cod_cliente = aux.organiza;
								break;
							}
						}
					}
				}
			case 6:
				// Recebendo o per�odo em que os documentos ser�o exclu�dos 
				printf("Entre com o per�odo em que desja excluir os documentos\nData de inidio: ");
				scanf("%d", &aux.data_in);
				printf("Data de final do per�odo: ");
				scanf("%d", &aux.data_fin);
				
				/* Varrendo todos os clientes e seus docuementos a procura dos que possuem o 
				vencimentos dentro do per�odo digitado*/ 
				for(aux.i = 0; aux.i < 2;aux.i++){
					for(aux.j = 0; aux.j < 2; aux.j++){
						if(clientes[aux.i].documentos[aux.j].data_venc > aux.data_in){
							if(clientes[aux.i].documentos[aux.j].data_pag < aux.data_fin){
								clientes[aux.i].documentos[aux.j].cod_cliente = 0;
								clientes[aux.i].documentos[aux.j].data_venc = 0;
								aux.conta_doc--;
							}
						}
					}	
				}
				// Mostrando o per�odo em que foi exclu�do os documentos que possuem essa data
				printf("Todos os documentos que vencem entre os dias %d e %d foram exclu�dos\n", aux.data_in, aux.data_fin);
			break;
			
			case 7:
				// Recebendo o codigo do cliente que deseja alterar suas informa��es
				printf("Entre com o codigo do cliente que deseja alterar as suas informa��es: ");
				scanf("%d", &aux.teste_cod);
				fflush(stdin);
				
				// Verificando se o codigo � v�lido
				if(aux.teste_cod != clientes[0].cod_cliente && aux.teste_cod != clientes[1].cod_cliente){
					printf("Cliente n�o encontrado!\n");
					break;
				}
				
				// Varrendo o vetor a procura do cliente com mesmo codigo digitado
				for(aux.i = 0; aux.i < 2; aux.i++){
					// Se encontrado receber novas informa��es para o cliente
					if(aux.teste_cod == clientes[aux.i].cod_cliente){
						printf("Digite o nome do cliente: ");
						gets(clientes[aux.i].nome);
						printf("Digite o endere�o do cliente\nCidade: ");
						gets(clientes[aux.i].cidade);
						printf("Estado: ");
						gets(clientes[aux.i].estado);
						printf("Rua: ");
						gets(clientes[aux.i].rua);
						printf("N�: ");
						scanf("%d", &clientes[aux.i].numero);
						fflush(stdin);
						printf("Telefone: ");
						gets(clientes[aux.i].fone);
						printf("As informa��es sobre o cliente %s foram alteradas com sucesso!\n", clientes[aux.i].nome);
						break;
						
					} 
				}
			case 8:
				aux.conta_8 = 0;// contador de documentos
				// Recebendo o codigo do clliente que ter� seus documentos contados
				printf("Entre com o codigo do cliente que deseja visualizar seu total de documentos: ");
				scanf("%d", &aux.teste_cod);
				// Procurando o cliente com o codigo digitado
				 for(aux.i = 0; aux.i < 2; aux.i++){
				 	if(aux.teste_cod == clientes[aux.i].cod_cliente){
				 		for(aux.j = 0; aux.j < 2; aux.j++){
						    // Quando encontrado  o cliente procurar documentos com mesmo codigo
				 			if(clientes[aux.i].documentos[aux.j].cod_cliente == aux.teste_cod){
				 				aux.conta_8++;// Ao encontrar documento encrementa o contador
				 			}
				 		}
				 	}
				 }
				 
				 // Mostrando o total de documentos em nome do cliente solicitado
				 printf("O cliente de codigo: %d possui %d documento em seu nome\n", aux.teste_cod, aux.conta_8);
		}
	}
	return 0;
}
