#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Prototipos
void LimparVendas(int);
void CadastrarVendedor(int);
void CadastrarVendas(int);
void CadastrarVendasMes(int, int);
void ConsultarVendedorMes(int, int);
void ConsultarVendedor(int);
void MostrarMaiorVenda();
void MostrarMaiorVendaMes(int);

struct Vendedor {
	int cod;	
	int vendasMes[12];
	
} *vendedores;
int numVendedores = 0;


int main(int argc, char *argv[]) {
	
	//Vars
	int codCad = 0;
	char val;
	int mesVal = 0;
	
	//Menu
	int opt = -1;
	do {
		system("cls"); //Limpar a tela
		printf("################################################\n");
		printf("\t\tControle de vendedores\n\n");
		printf("\t1 - Cadastrar vendedor\n");
		printf("\t2 - Cadastrar venda\n");
		printf("\t3 - Consultar vendas do vendedor (cod e mes)\n");
		printf("\t4 - Consultar vendas do vendedor (cod)\n");
		printf("\t5 - Consultar quem vendeu mais\n");
		printf("\t6 - Consultar mes com maior vendas\n");
		printf("\t7 - Finalizar\n");
		printf("################################################\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opt);
		
		//Limpar tela
		system("cls");
		
		switch(opt) {
			
			case 1:				
				//Cadastrar novo vendedor
				printf("\n\nDigite o codigo do vendedor: ");
				scanf("%d", &codCad);
				CadastrarVendedor(codCad);
				
				//espera
				getch();
					
				break;
			case 2:
				//Pegar Cod
				printf("\n\nDigite o codigo do vendedor: ");
				scanf("%d", &codCad);
				
				//Cadastrar vendas
				mesVal = 0;
				printf("\nDeseja cadastrar as vendas do vendedor?\n\t1 - Todos os meses\n\t2 - Apenas um mes\n\tOutro - Nao\n");
				fflush(stdin);
				val = getchar();
				switch(val) {
					case '1':
						CadastrarVendas(codCad);
						break;
					case '2':
						while (mesVal < 1 || mesVal > 12) {
							printf("\nQual mes deseja cadastrar? (1-12)");
							scanf("%d", &mesVal);
						}
						CadastrarVendasMes(codCad, mesVal);
						break;
					default:
						break;
				}
					
				//espera
				getch();
				
				break;
			case 3:
				
				//Pegar Cod
				printf("\n\nDigite o codigo do vendedor: ");
				scanf("%d", &codCad);
				
				//Mes
				mesVal = 0;
				while (mesVal < 1 || mesVal > 12) {
					printf("\nQual mes deseja consultar? (1-12)");
					scanf("%d", &mesVal);
				}
				
				ConsultarVendedorMes(codCad, mesVal);
				
				//espera
				getch();
				
				break;
			case 4:
				
				//Pegar Cod
				printf("\n\nDigite o codigo do vendedor: ");
				scanf("%d", &codCad);
				ConsultarVendedor(codCad);
				
				//espera
				getch();
				
				break;
			case 5:
				
				//Mes
				mesVal = 0;
				while (mesVal < 1 || mesVal > 12) {
					printf("\nQual mes deseja consultar? (1-12)");
					scanf("%d", &mesVal);
				}
				
				MostrarMaiorVendaMes(mesVal);
				
				//espera
				getch();
				break;
			case 6:
				
				MostrarMaiorVenda();
				
				//espera
				getch();
				break;
			case 7:
				
				//espera
				getch();
				break;
			default:
				
				printf("\n\n Opcao Invalida.");
				//espera
				getch();
				break;
			
		}
		
	} while (opt != 7);
		
	return 0;
}

//Limpar Vendas
void LimparVendas(int index) {
	int i = 0;
	for (i = 0; i < 12; i++) { //Rodar os 12 meses do vendedor cadastrado no index
		vendedores[index].vendasMes[i] = -1; //Coloca em valor negativo para informar o programa que não existe venda cadastrada no mes
	}
}

//Cadastrar novo vendedor
void CadastrarVendedor(int cod) {
	
	//Checa se ja existe o codigo
	int i = 0;
	int flag = 1;
	for (i = 0; i < numVendedores; i++) {
		if (vendedores[i].cod == cod) {
			flag = 0;
			break;
		}
	}
	
	//Codigo nao existe
	if (flag) {
		
		//Somar vendedor
		numVendedores++;
	
		//Realocar Memoria
		vendedores = realloc(vendedores, numVendedores * sizeof(struct Vendedor));
		
		//Alterar dados
		vendedores[numVendedores-1].cod = cod;
		
		//Limpar Vendas
		LimparVendas(numVendedores-1);
		
		//Cadastrar vendas
		int mes = 0;
		printf("\nDeseja cadastrar as vendas do vendedor?\n\t1 - Todos os meses\n\t2 - Apenas um mes\n\tOutro - Nao\n");
		fflush(stdin);
		char opt = getchar();
		switch(opt) {
			case '1':
				CadastrarVendas(cod);
				break;
			case '2':
				while (mes < 1 || mes > 12) {
					printf("\nQual mes deseja cadastrar? (1-12)");
					scanf("%d", &mes);
				}
				CadastrarVendasMes(cod, mes);
				break;
			default:
				break;
		}

	}
	else
	{
		
		printf("\n\nVendedor com codigo ja cadastrado.");
		
	}
}

void CadastrarVendas(int cod) {
	
	//Selecionar Vendedor
	int i = 0;
	for (i = 0; i < numVendedores; i++) {
		
		if (vendedores[i].cod == cod) {
			
			//Perguntar todos os meses
			int mes = 0;
			for (mes = 0; mes < 12; mes++) {
				//Nenhuma Venda cadastrada
				if (vendedores[i].vendasMes[mes] == -1) { 
					printf("\nEntre com as vendas realizadas no mes %d: ", mes+1);
					scanf("%d", &vendedores[i].vendasMes[mes]);
				}
				else
					printf("\nVenda ja cadastrada neste mes.");
			}
			
			break; 
		}
		
	}	
	
}

void CadastrarVendasMes(int cod, int mes) {
	
	//Selecionar Vendedor
	int i = 0;
	for (i = 0; i < numVendedores; i++) {
		
		if (vendedores[i].cod == cod) {
			
			//Nenhuma Venda cadastrada
			if (vendedores[i].vendasMes[mes-1] == -1) {
				//Perguntar
				printf("\nEntre com as vendas realizadas no mes %d: ", mes);
				scanf("%d", &vendedores[i].vendasMes[mes-1]);
			}
			else
				printf("\nJa existe uma venda cadastrada neste mes.");
				
			break;
		}
		
	}
}

//Consultar Vendas funcionario no mes
void ConsultarVendedorMes(int cod, int mes) {
	
	//Selecionar Vendedor
	int i = 0;
	for (i = 0; i < numVendedores; i++) {
	
		if (vendedores[i].cod == cod) {
		
			//Mostrar Vendas do mes
			printf("\nO vendedor %d vendeu, no mes %d, %d.", cod, mes, vendedores[i].vendasMes[mes]);		
		
			break;	
		}
		
	}
	
}

//Consultar Vendas
void ConsultarVendedor(int cod) {
	
	//Selecionar Vendedor
	int i = 0;
	for (i = 0; i < numVendedores; i++) {
	
		if (vendedores[i].cod == cod) {
	
			int somaVendas = 0, mes = 0;
			for (mes = 0; mes < 12; mes++) {
				if (vendedores[i].vendasMes[mes] >= 0) //Somar somente os meses que possuem registro positivo
					somaVendas += vendedores[i].vendasMes[mes];
			}
			
			//Mostrar vendas
			printf("\nO vendedor %d vendeu %d.", cod, somaVendas);
	
			break;
		}
	}
}

//Mes com maior venda
void MostrarMaiorVenda() {
	
	//Verificar todos os meses
	int maiorMes = -1, maiorVendas = -1, i, j;
	for (i = 0; i < 12; i++) {
		
		int vendasMes = 0;
		
		//Verificar todos os funcionarios
		for (j = 0; j < numVendedores; j++) {
			
			//Somar apenas cadastrados
			if(vendedores[j].vendasMes[i] >=0)
				vendasMes += vendedores[j].vendasMes[i];
			
		}
		
		if (vendasMes > maiorVendas) { //Passar os valores do mes atual se for maior que o ja cadastrado
			maiorVendas = vendasMes;
			maiorMes = i+1;
		}
		
	}
	
	//Mostrar
	printf("\n%d e o mes com maior numero de vendas, totalizando %d vendas.", maiorMes, maiorVendas);
	
}

//Vendedor com maior venda no mes
void MostrarMaiorVendaMes(int mes) {
	
	//Pegar vendedor
	int maiorVenda = -1, cod = 0, i;
	for (i = 0; i < numVendedores; i++) {
		
		if (vendedores[i].vendasMes[mes-1] > maiorVenda) { //Vendeu mais
			maiorVenda = vendedores[i].vendasMes[mes-1];
			cod = vendedores[i].cod;
		}
		
	}
	
	//Mostrar
	printf("\nO vendedor que mais vendeu no mes %d foi %d com %d vendas", mes, cod, maiorVenda);
	
}


