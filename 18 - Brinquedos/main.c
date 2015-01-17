#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Prototipos
void CadastrarProduto(int, char *, float, float, int, int);
void PerguntarDados();
void Vender();
void LucroProduto();
void EmFalta();

//Brinquedo
struct Brinquedo {
	int cod;
	char desc[500];
	float compra;
	float venda;
	int estoque;
	int minEstoque;
	int vendidos;
	float lucro;
	
} *brinquedos;
int numBrinquedos = 0;

//Loja
struct Loja {
	
	int lucroTotal;
	int somaProdutos;
	
} loja;


int main(int argc, char *argv[]) {
	
	//Menu
	int opt = 0;
	do {
		system("cls");
		
		printf("#####################################################\n");
		printf("		Controle da loja\n\n");
		printf("\t1 - Cadastrar Produto\n");
		printf("\t2 - Lucro por produto\n");
		printf("\t3 - Produtos em falta\n");
		printf("\t4 - Vender produto\n");
		printf("\t0 - Sair\n\n");
		printf("#####################################################\n");		
		printf("Opcao desejada: ");
		scanf("%d", &opt);
		
		//interpretar menu
		switch(opt) {
			
			case 1: //Cadastrar novo produto
				
				system("cls");
				
				//Perguntar Dados
				PerguntarDados();
				
				getch();//Esperar
				
				break;
				
			case 2: //Lucro
				system("cls");
				
				LucroProduto();
				
				getch();//Esperar
				
				break;
			
			case 3: //Em falta
				system("cls");
				
				EmFalta();
				
				getch();//Esperar
				
				break;
			
			case 4: //Vender
				system("cls");
				
				Vender();
				
				getch();
				break;
				
			case 0:
				break;
			
			default:
				system("cls");
				printf("\nInvalido.");
				getch();
				break;
		}
		
	} while (opt != 0);
	
	
	
	return 0;
}

void CadastrarProduto(int cod, char desc[500], float compra, float venda, int estoque, int estoqueMin) {
	
	//Realocar memoria
	numBrinquedos++;
	brinquedos = realloc(brinquedos, numBrinquedos * sizeof(struct Brinquedo));
	
	//Cadastrar dados 
	brinquedos[numBrinquedos-1].cod = cod;
	strcpy(brinquedos[numBrinquedos-1].desc, desc);
	brinquedos[numBrinquedos-1].compra = compra;
	brinquedos[numBrinquedos-1].venda = venda;
	brinquedos[numBrinquedos-1].estoque = estoque;
	brinquedos[numBrinquedos-1].minEstoque = estoqueMin;
	brinquedos[numBrinquedos-1].vendidos = 0;
	
	//Loja
	loja.somaProdutos += estoque;
	
	//Cadastrado
	printf("\n\nNovo produto cadastrado. COD: %d", cod);
	
}

//Perguntar Dados
void PerguntarDados() {
	
	//Variaveis
	int cod = 0;
	char desc[500];
	float compra = 0, venda = 0;
	int estoque = 0, estoqueMin = 0;
	
	//Codigo
	printf("\n\nCodigo do produto: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Descricao do produto
	printf("\nDescricao do produto:\n");
	fflush(stdin);
	gets(desc);
	
	//Compra e venda
	printf("\nPreco de compra: ");
	fflush(stdin);
	scanf("%f", &compra);
	printf("\nPreco de venda: ");
	fflush(stdin);
	scanf("%f", &venda);
	
	//Estoque
	printf("\nEm estoque: ");
	fflush(stdin);
	scanf("%d", &estoque);
	printf("\nEstoque minimo: ");
	fflush(stdin);
	scanf("%d", &estoqueMin);
	
	//Cadastrar
	CadastrarProduto(cod, desc, compra, venda, estoque, estoqueMin);
	
}

//Vender
void Vender() {
	
	//Codigo
	int cod = 0;
	printf("Codigo do produto: ");
	scanf("%d", &cod);
	
	//Selecionar produto
	int b = 0;
	for (b = 0; b < numBrinquedos; b++) {
		
		//Por codigo
		if (brinquedos[b].cod == cod) {
			
			//Vender
			int venda = 0;
			printf("\nQuantidade (max %d): ", brinquedos[b].estoque);
			scanf("%d", &venda);
			
			if (venda <= brinquedos[b].estoque) {
				
				float totalVenda = brinquedos[b].venda*venda; //Valor da venda
				float lucro = (brinquedos[b].venda-brinquedos[b].compra) * venda; //Lucro
				
				//Atualizar Brinquedo
				brinquedos[b].estoque -= venda;
				brinquedos[b].vendidos += venda;
				brinquedos[b].lucro += lucro;
				
				//Atualizar loja
				loja.lucroTotal += lucro;
				loja.somaProdutos -= venda;
				
				printf("Produto vendido. Total: %.2f", totalVenda);
				
			}
			
			break;
		}
	}
	
}

//Lucro Produto
void LucroProduto() {
	
		//Codigo
	int cod = 0;
	printf("Codigo do produto: ");
	scanf("%d", &cod);
	
	//Selecionar produto
	int b = 0;
	for (b = 0; b < numBrinquedos; b++) {
		
		//Por codigo
		if (brinquedos[b].cod == cod) {
		
			float lucro = brinquedos[b].lucro;
			float percentual = (100 * lucro) / loja.lucroTotal;
		
			//Mostrar lucro
			printf("\nLucro obtido com o produto %d e de %.2f, representando %.2f%% do total das vendas.", cod, lucro, percentual);
	
			
			break;
		}
		
	}
	
}

void EmFalta() {
	
	int b = 0;
	for (b = 0; b < numBrinquedos; b++) {
		
		if (brinquedos[b].estoque <= brinquedos[b].minEstoque) {
			
			printf("O produto %d esta em falta, quantidade: %d de %d.\n", brinquedos[b].cod, brinquedos[b].estoque, brinquedos[b].minEstoque);
			
		}
				
	}
}
