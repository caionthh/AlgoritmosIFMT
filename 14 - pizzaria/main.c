#include <stdio.h>
#include <stdlib.h>
#include <conio.c>
#include <string.h>

// DEFINNICAO DAS ESTRUTURAS
struct pizza{
	char cod [10];
	char nome [30];
	float vlr; // as casas decimais devem ser separadas por virgula nao por ponto
} p[3];

struct cliente {
	char num_telefone[10];
	char nome[50];
	char endereco[100];
	char complemento[100];
	char cpf[15]; //000.000.000.00  
}c[4];

struct pedido{
	int num; // poderia ser char mais devido a um erro na versao 5.5.2 do dev decidimos utilizar o tipo de dados inteiro
	char num_tel[10];
	char cod_pizza[10];
	int cod_moto;
	char situacao;
} ped[5];

// VARIAVEIS GLOBAL
int qt = 0; // variavel controla a quantidade de pizza cadastrada
int qt_cliente = 0;
int qt_pedidos = 0;

// PROTOTIPO DE FUNÇAO
void menu();
void opcao();
void cadastro_pizzas();
void cadastro_cliente();
void cadastro_pedidos();
void despacho_pizza();
void finalizar_pedidos();
void total_cliente();
void situacao_pedido();
void motoqueiro_pedidos();
void opcao_invalida();

// PROGRAMA PRINCIPAL
void main ()
{
	menu();
}

void menu()
{
	system("cls");
	printf("|------------------------MENU------------------------|\n");
	printf("|   1 - CADASTRO DE PIZZAS                           |\n");
	printf("|   2 - CADASTRO DE CLIENTES                         |\n");
	printf("|   3 - CADASTRO DE PEDIDOS                          |\n");
	printf("|   4 - DESPACHO DA PIZZA                            |\n");
	printf("|   5 - FINALIZAR PEDIDO                             |\n");
	printf("|   6 - TOTAL GASTO EM PIZZA POR CLIENTE             |\n");
	printf("|   7 - SITUACAO DOS PEDIDOS (SITUACAO PIZZA)        |\n");
	printf("|   8 - MOTOQUEIRO COM MAIS ENTREGAS                 |\n");
	printf("|----------------------------------------------------|\n");
	printf("|DIGITE A OPCAO DESEJADA.:                           |\n");
	printf("|----------------------------------------------------|\n");
	gotoxy(strlen("DIGITE A OPCAO DESEJADA.:")+3,11);
	opcao();
}

void opcao()// funcao seleciona a opcao desejada e direciona para a funcao escolhida
{
	char opcao = ' ';
	scanf("%c",&opcao);

	switch(opcao)
	{
		case '1': cadastro_pizzas(); break;
		case '2': cadastro_cliente(); break;
		case '3': cadastro_pedidos(); break;
		case '4': despacho_pizza(); break;
		case '5': finalizar_pedidos(); break;
		case '6': getchar(); total_cliente(); break;
		case '7':  situacao_pedido(); break;
	    case '8': motoqueiro_pedidos(); break;		
		default :  opcao_invalida(); break;		
	}
	menu();
}

void cadastro_pizzas()
{
	if (qt <= 2)
	{
		char codigo [10];
		int existe = 0 ; // variavel que guarda a existencia do cadastro
		int x = 0; //  utilizada no for 
		 
		system("cls");
		printf("|-----------------CADASTRO PIZZAS--------------------|\n");
		printf("|DIGITE O COD DA PIZZA.:                             |\n");
		printf("|NOME DA PIZZA.:                                     |\n");
		printf("|VALOR.:                                             |\n");
		printf("|----------------------------------------------------|\n");
		gotoxy(strlen("DIGITE O COD DA PIZZA.:")+3,2); // strlem retorna numero de caracter do parametro
		scanf("%s",&codigo);
		getchar();
	
	// verifica se o cod ja esta cadastrado
		for(x = 0; x <= 2; x++)
		{
			if(strcmp(codigo, p[x].cod) == 0){ existe = 1;} // comparacao  de string
		}
	
	
		if(existe == 0)
		{
			strcpy(p[qt].cod, codigo); // copia de string
			gotoxy(strlen("NOME DA PIZZA.:")+3,3); // posiciona o curso 
			gets(p[qt].nome);
		
			gotoxy(strlen("VALOR.:")+3,4);
			scanf("%f",&p[qt].vlr);
			qt = qt + 1;
		}
		else
		{
			system("cls");
			printf("JA EXISTE CADASTRO COM ESSE CODIGO\n");
			printf("TECLE ENTER PARA VOLTAR AO MENU PRINCIAL");
		}
	}
	else
	{
		system("cls");
		printf("NAO E POSSIVEL CADASTRAR MAIS PIZZAS\n");
		printf("TECLE ENTER PARA VOLTAR AO MENU PRINCIAL");
		getchar();
	}
	getchar();
	getchar();
}

void cadastro_cliente()
{
	if (qt_cliente <= 4)
	{
		char tel [10];
		int existe = 0 ; // variavel que guarda a existencia do cadastro
		int x = 0; //  utilizada no for 
	
	 
		system("cls");
		printf("|------------------CADASTRO CLIENNTES----------------|\n");
		printf("|DIGITE O NUMERO DO TELEFONE.:                       |\n");
		printf("|NOME DO CLIENTE.:                                   |\n");
		printf("|ENDERECO.:                                          |\n");
		printf("|COMPLEMENTO.:                                       |\n");
		printf("|CPF.:                                               |\n");
		printf("|----------------------------------------------------|\n");
		gotoxy(strlen("DIGITE O NUMERO DO TELEFONE.:")+3,2); // strlem retorna numero de caracter do parametro
		scanf("%s",&tel);
		getchar();
	
	// verifica se o cod ja esta cadastrado
		for(x = 0; x <= qt_cliente; x++)
		{
			if(strcmp(tel, c[x].num_telefone) == 0){ existe = 1;} // comparacao  de string
		}
	
		if(existe == 0)
		{
			strcpy(c[qt_cliente].num_telefone, tel); // copia de string
			gotoxy(strlen("NOME DO CLIENTE.:")+3,3);
			gets(c[qt_cliente].nome);
		
			gotoxy(strlen("ENDERECO.:")+3,4);
			gets(c[qt_cliente].endereco);
			
			
			
			gotoxy(strlen("complemento.:")+3,5);
			gets(c[qt_cliente].complemento);
			
			
			gotoxy(strlen("CPF.:")+3,6);
			gets(c[qt_cliente].cpf);
			
		
			qt_cliente = qt_cliente + 1;
		}
		else
		{
			system("cls");
			printf("JA EXISTE CADASTRO COM ESSE CODIGO\n");
			printf("TECLE ENTER PARA VOLTAR AO MENU PRINCIAL");
			getchar();
		}
	}
	
	else
	{
		system("cls");
		printf("NAO E POSSIVEL CADASTRAR MAIS CLIENTES\n");
		printf("TECLE ENTER PARA VOLTAR AO MENU PRINCIAL");
		getchar();
		getchar();
	}
	
}

void cadastro_pedidos()
{
	if (qt_pedidos <= 5)
	{
		system("cls");
		printf("|-----------------CADASTRO DE PEDIDOS-----------------|\n");
		printf("|COD.:                                                |\n");
		printf("|NUMERO DO TELEFONE.:                                 |\n");
		printf("|COD PIZZA.:                                          |\n");
		printf("|COD MOTOQUEIRO.: 0 INFORMAR NO DESPACHE              |\n");
		printf("|SITUACAO.: 1 EM PREPARO                              |\n");
		printf("|-----------------------------------------------------|\n");
		
		getchar();
		gotoxy(strlen("COD.:")+3,2); // posiciona o cursor
		scanf("%d",&ped[qt_pedidos].num);
		
		
		gotoxy(strlen("NUMERO DO TELEFONE.:")+3,3);
		getchar();
		gets(ped[qt_pedidos].num_tel);
		
		
		gotoxy(strlen("COD PIZZA.:")+3,4);
		gets(ped[qt_pedidos].cod_pizza);
		
		ped[qt_pedidos].cod_moto = 0;
		ped[qt_pedidos].situacao = '1';
		qt_pedidos++;
		
	}
	else
	{
		system("cls");
		printf("NAO E POSSIVEL CADASTRAR MAIS CLIENTES\n");
		printf("TECLE ENTER PARA VOLTAR AO MENU PRINCIAL");
		getchar();
		getchar();
	}
}


void despacho_pizza()
{
	int cod = 0; // erro em declarar como char bug na versao do dev
	int flag = 0;	
	int x = 0;
	
	system("cls");
	printf("DIGITE O COD DO PEDIDO\n");
	scanf("%d",&cod);
	getchar();
	
	
	
	for(x = 0; x <= qt_pedidos; x++)
	{
		if (cod == ped[x].num) 
		{
			if(flag == 0)
			{
				if(ped[x].situacao == '1')
				{
					ped[x].situacao = '2';
					printf("DIGITE O COD DO MOTOQUEIRO UM VLR DE 1 A 5\n");
					scanf("%d",&ped[x].cod_moto);
					flag = 1;
				}
			}
			
		}
	}
	getchar();
}


void finalizar_pedidos()
{
	int cod = 0;	
	int flag = 0;
	int x = 0;
	
	system("cls");
	printf("DIGITE O COD DO PEDIDO\n");
	scanf("%d",&cod);
	getchar();

	for(x = 0; x <= qt_pedidos; x++)
	{
		if (cod == ped[x].num && flag == 0 && ped[x].situacao == '2') 
		{
			ped[x].situacao = '3';
			flag = 1;
		}
	}
	printf("PEDIDO FINALIZADO COM SUCESSO!");
	getchar();
}

void total_cliente()
{
	system("cls"); // limpa a tela
	char telefone [10]; // armazena o numero do telefone dado que identifica o cliente
	int aux = 0; // variavel utilizada no for
	float total = 0; // acumula o total gasto por um determinado cliente
	int x = 0;		
	printf("DIGITE O TELEFONE DO CLIENTE\n");
	gets(telefone);
	
	for(aux = 0; aux <= qt_pedidos; aux++) // percorre todos os pedidos 
	{
		if(strcmp(telefone,ped[aux].num_tel) == 0) // verifica se a igualdade da informaçao digitada com numero de telefone cadastrado no pedido
		{
			
			for(x = 0 ; x <= 2; x++) // percorre o cadastro das pizza para encontrar o valor atraves do seu codigo
			{
				if(strcmp(ped[aux].cod_pizza,p[x].cod) == 0 ) // verifica se o codigo da pizza e igual
				{
					total = total + p[x].vlr; // acumula o valor gasto pelo cliente
				}
			}
		}
	}
	printf("O TOTAL GASTO PELO CLIENTE.: %f",total);
	getchar();	
}

void situacao_pedido()
{
	system("cls");
	char aux = ' ';
	int x = 0;
	int total = 0;
	
	printf("DETERMINE A SITUACAO 1 - EM PREPARO, 2 - A CAMINHO, 3 - ENTREGUE\n");
	getchar();
	scanf("%c",&aux);
	
	for(x = 0; x <= 5; x++)
	{
		if (aux == ped[x].situacao)
		{
			total = total + 1;
		}
	}
	printf("%d\n",total);
	system("pause");
	getchar();
}

void motoqueiro_pedidos()
{
	int x = 0;
	int y = 0;
	int quant = 0;
	int maior = 0;
	int aux = 0;
	int cod_motoqueiro = 0;

	for (x = 0; x <= qt_pedidos; x++)
	{
		aux = ped[x].cod_moto; // PEGA CADA ELEMENTO DO REDISTRO
		
		for(y = 0; y <= qt_pedidos; y++) // COMPARA COM TODOS OS REGISTRO ARMAZENADOS
		{
			if (aux == ped[y].cod_moto) // SE FOR IGUAL INCREMENTA EM 1
			{
				quant++;
			}		
		}
		
		if(maior < quant) // VERIFICA QUAL MOTOQUEIRO ENTREGOU MAIS 
		{
			maior = quant; // ARMAZENA A QUANTIDADE DE ENTREGA
			cod_motoqueiro = aux; // ARMAZENA O COD DO MOTOQUEIRO;
		}
		quant = 0; // RESETA A VARIAVEL 
	}
	
	system("cls");
	if(cod_motoqueiro > 0) 
	{
		printf("O COD DO MOTOQUEIRO QUE MAIS ENTREGOU E %d\n",cod_motoqueiro);
	}
	else
	{
		printf("NAO HOUVE ENTREGAS\n");
	}
	getchar();
	getchar();
}

void opcao_invalida()
{
	system("cls");
	printf("OPCAO INVALIDA TECLE ENTER PARA RETORNAR AO MENU PRINCIPAL");
	getchar();
}
