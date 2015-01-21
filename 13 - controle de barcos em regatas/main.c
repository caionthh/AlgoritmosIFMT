#include <stdio.h>
#include <stdlib.h>
#include <conio.c>


// definicao das estruturas
struct retatas{
	int cod_reg;
	char data[11]; //dd/mm/aaaa
	char hora_inicial[6];
	int cod_bar_ven;
}vet[2];

struct barco{
	int num_bar;
	char nome_bar[50];
	int ano_fab;
} bar[5];

struct participacao{
	int num_reg;
	int num_bar;
	char hr_chegada[6];
} par[3];

// variaveis globais
int cont_1 = 0;
int cont_2 = 0;
int cont_3 = 0;
char hr_inicio[2];
char mim_inicio[2];
char hr_termino[2];
char mim_termino[2];

// prototipos das funçoes
void menu();
void verifica(int opcao);
void cadastro_barco();
void cadastro_regatas();		
void cadastro_participacao();
void imprimir_reg_realizadas();
void imprimir_participacao();
void calulo_duracao(int hr_ini, int hr_ter, int cod_barco, int cod);
// funçao principal
void main()
{
		while(1) menu();
}


// menu
void menu ()
{
	int opcao = 0;
	system("cls");
	printf("|------------------------MENU------------------------|\n");
	printf("|   1 - CADASTRO DE BARCOS                           |\n");
	printf("|   2 - CADASTRO DE REGATAS                          |\n");
	printf("|   3 - CADASTRO DE PARTICIPACAO DE REGATAS          |\n");
	printf("|   4 - RELACAO DE REGATAS REALIZADAS                |\n");
	printf("|   5 - RELACAO DE PARTICIPACAO EM REGATAS           |\n");
	printf("|----------------------------------------------------|\n");
	printf("|DIGITE A OPCAO DESEJADA.:                           |\n");
	printf("|----------------------------------------------------|\n");
	gotoxy(strlen("DIGITE A OPCAO DESEJADA.:")+3,8);
	scanf("%d",&opcao);
	
	verifica(opcao);	
}

void verifica(int opcao)
{
	switch(opcao)
	{
		case 1: cadastro_barco(); break;
		case 2: cadastro_regatas(); break;
		case 3: cadastro_participacao(); break;
		case 4: imprimir_reg_realizadas(); break;
		case 5: imprimir_participacao(); break;  
		default : system("cls"); printf("OPCAO INVALIDA");  getchar(); getchar(); break;
	}
}


void cadastro_barco()
{
	int i = 0;
	int cod = 0;
	int flag = 0;
	
	if (cont_1 < 6)
	{
		system("cls");
		printf("|-------------------CADASTRO DE BARCOS---------------|\n");
		printf("|NUMERO BARCO[1..6].:                                |\n");
		printf("|NOME DO BARCO.:                                     |\n");
		printf("|ANO DE FABRICACAO[aaaa].:                           |\n");
		printf("|----------------------------------------------------|\n");
	
		gotoxy(strlen("NUMERO BARCO[1..6].:")+3,2);
		scanf("%d",&cod);
		getchar();
		
	
		// verifica se o barco ja esta cadastrado
		for(i = 0; i <=cont_1; i++)
			{
				if (bar[i].num_bar == cod){ flag = 1;}
			}
		
		
		// se nao existir o cadastro entra prosega
		if (flag == 0)
		
			{
				bar[cont_1].num_bar = cod;
				
				gotoxy(strlen("NUMERO BARCO[1..6].:")+3,3);
				gets(bar[cont_1].nome_bar);
				
				
				gotoxy(strlen("ANO DE FABRICACAO[aaaa].:")+3,4);
				scanf("%d",&bar[cont_1].ano_fab);
				getchar();
				
				cont_1 = cont_1 + 1;
			}
			
		else	
			{
				system("cls");
				printf("BARCO JA CADASTRADO\n");
				getchar();
			}	
			
	}
	else
	{
		system("cls");
		printf("NAO E POSSIVEL CADASTRAR MAIS BARCOS\n");
		getchar();
		getchar();
	}
}
	

void cadastro_regatas()
{
	int i = 0;
	int aux = 0;
	int flag = 0;
	
	
	if (cont_2 < 3)
	{
		system("cls");
		printf("|------------------CADASTRO DE REGATAS---------------|\n");
		printf("|NUMERO REGATA[1..3].:                               |\n");
		printf("|DATA.:                                              |\n");
		printf("|HORA INICIO[hhmm].:                                 |\n");
		printf("|COD BARCO VENCEDOR[1..6].:                          |\n");
		printf("|----------------------------------------------------|\n");
	
		gotoxy(strlen("NUMERO REGATA[1..3].:")+3,2);
		scanf("%d",&aux);
		getchar();
		
		
	
		// verifica se o barco ja esta cadastrado
		for(i = 0; i <=cont_2; i++)
			{
				if (vet[i].cod_reg == aux){ flag = 1;}
			}

		// se nao existir o cadastro entra prosega
		if (flag == 0)
		
			{
				vet[cont_2].cod_reg = aux;
				
				gotoxy(strlen("DATA.:")+3,3);
				gets(vet[cont_2].data);
				
				
				gotoxy(strlen("HORA INICIO[hhmm].:")+3,4);	
				gets(vet[cont_2].hora_inicial);
											
				
				gotoxy(strlen("COD BARCO VENCEDOR[1..6].:")+3,5);
				scanf("%d",&vet[cont_2].cod_bar_ven);
				getchar();
				

				cont_2 = cont_2 + 1;
			}
			
		else	
			{
				system("cls");
				printf("REGATA JA CADASTRADO\n");
				getchar();
			}	
			
	}
	else
	{
		system("cls");
		printf("NAO E POSSIVEL CADASTRAR MAIS REGATAS\n");
		getchar();
		getchar();
	}
	
}

void cadastro_participacao()
{
	int i = 0;
	int j = 0;
	int aux_1 = 0;
	int aux_2 = 0;
	int flag = 0;
	
	if (cont_3 < 4)
	{
		system("cls");
		printf("|---------------PARTICIPACAO REGATAS-----------------|\n");
		printf("|NUMERO BARCO[1..6].:                                |\n");
		printf("|NUMERO REGATA[1..3].:                               |\n");
		printf("|HORA CHEGADA[hh:mm].:                               |\n");
		printf("|----------------------------------------------------|\n");
	
		gotoxy(strlen("NUMERO BARCO[1..6].:")+3,2);
		scanf("%d",&aux_1);
		
		gotoxy(strlen("NUMERO REGATA[1..3].:")+3,3);
		scanf("%d",&aux_2);
		getchar();
		
		// verifica se o barco ja esta cadastrado
		for(i = 0; i <= cont_3; i++)
			{
				if (par[i].num_bar == aux_1 )
				{ 
					if(par[i].num_reg == aux_2)
					{
						flag = flag + 1;
					}
				}
			}
			
		
		// se nao existir o cadastro entra prosIga
		if (flag == 0)
		
			{
				
				par[cont_3].num_bar = aux_1;
				par[cont_3].num_reg = aux_2;
				
				
				gotoxy(strlen("HORA CHEGADA[hhmm].:")+3,4);
				gets(par[cont_3].hr_chegada);  
				
				cont_3 = cont_3 + 1;
			}
			
		else	
			{
				system("cls");
				printf("DUPLICIDADE DE BARCOS NA MESMA REGATA E POSSIVEL CADASTRA\n");
				getchar();
			}	
			
	}
	else
	{
		system("cls");
		printf("NAO E POSSIVEL CADASTRA  MAIS PARTICIPANTES");
		getchar();
		getchar();
	}

}

void imprimir_reg_realizadas()
{
	int i = 0;
	system("cls");	
	for (i = 0; i < cont_2; i++)
	{
		printf("NUMERO REGATA: %d  DATA.: %s COD BARCO VENCEDOR.: %d\n",vet[i].cod_reg ,vet[i].data,vet[i].cod_bar_ven); 
	}
	getchar();
	getchar();
}

void imprimir_participacao()
{
	int cod = 0;
	int cod_barco = 0;
	int i = 0;
	int j = 0;
	int hr_inicio = 0;
	int hr_termino = 0;
	
	
	system("cls");
	printf("|---------------PARTICIPACAO REGATAS-----------------|\n");
	printf("|DIGITE O NUMERO DA REGATA[1..3].:                   |\n");
	printf("|----------------------------------------------------|\n");


	gotoxy(strlen("DIGITE O NUMERO DA REGATA[1..3].:")+3,2);
	scanf("%d",&cod);
	system("cls");
	

	for(i = 0; i <= 3; i++) //localizar hr de termino da prova
	{
		if (cod == par[i].num_reg)
		{
			hr_termino = atoi(par[i].hr_chegada); 
			cod_barco = par[i].num_bar;
			
			
			for(j = 0; j <= 3; j++) //localizar hr de inicio da regata 
			{	
				if (cod == vet[j].cod_reg)
				{
					hr_inicio = atoi(vet[j].hora_inicial);
				}
			}
		
		calulo_duracao(hr_inicio,hr_termino,cod_barco,cod);
		}
	}

}
	
	

void calulo_duracao(int hr_ini, int hr_ter, int cod_barco, int cod)
{
	int i = 0;	
	int mim_ini = 0;
	int mim_ter = 0;
	int aux = 0;
	
	aux = hr_ini;
	mim_ini = aux % 10; // mim_ini recebe o resto da divisao aux / 10
	aux = aux / 10; // recebe o quociente inteiro equivale a funcao div
	mim_ini = (aux % 10)*10 + mim_ini;
	hr_ini = aux / 10;
	

	aux = hr_ter;
	mim_ter = aux % 10;
	aux = aux / 10;
	mim_ter = (aux % 10)*10 + mim_ter;
	hr_ter = aux / 10;
	

	
	hr_ini = hr_ini*60 + mim_ini;
	hr_ter = hr_ter*60 + mim_ter;
	
	hr_ter = hr_ter - hr_ini;
	

	if (hr_ter == 0)
	{
		hr_ini = 24;
		mim_ter = 0;
	}
	
	else	
	{
		if(hr_ter < 0){hr_ter = hr_ter + 24*60;}
		
		hr_ini = 0;
		while(hr_ter >= 60)
		{
			hr_ter = hr_ter - 60;
			hr_ini = hr_ini + 1;
		}
		mim_ter = hr_ter;			
	}	
	printf("O BARCO COM COD %d PARTICIPOU DA REGATA %d E CONCLUIU NO TEMPO DE %2.2d:%2.2d\n",cod_barco, cod, hr_ini,mim_ter);
	system("pause");
		
}
	
	
	
	
	
	
	
	

