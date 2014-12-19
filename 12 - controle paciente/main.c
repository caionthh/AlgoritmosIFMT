//ARQUIVOS DE CABEÇARIOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <conio.c> // necessaria para utilizar a funçao de gotoxy, textbackground(), textcolor() 

// DECLARAÇAO DE CONSTANTE RELACIONADA A QUANTIDADE DE CADASTRO
#define num 10

// ESTRUTURA
struct paciente {
	char nome [50];
	char medico [50];
	int sexo; //nao aceita bool
	char data[11]; // formato ex 10/01/2010
} p[num],p1[num+1];

// PROTOTIPOS DAS FUNÇOES
void menu();
void selecao_opcao();
void cadastro();
void ordem_cadastro();
void ordem_cre_dec(char x);
void excluir_paciente(char x);
void organiza_dados(char opcao);
void copia_infomacoes();
void error(int x);

//VARIAVEL GLOBAL
int num_cadastro = 0;



//PROGRAMA PRINCIPAL
void main()
{
	menu();
}




void menu () // funçao que imprime o menu de opçoes 
{
	textbackground(0); //Cores disponíveis
	textcolor(15);	   /*0 = Preto 8 = Cinza
						1 = Azul 9 = Azul claro
						2 = Verde 10 = Verde claro
						3 = Verde-água 11 = Verde-água claro
						4 = Vermelho 12 = Vermelho claro
						5 = Roxo 13 = Lilás
						6 = Amarelo 14 = Amarelo claro
						7 = Branco 15 = Branco brilhante*/
	system("cls");
	printf("|------------------------MENU------------------------|\n");
	printf("|   1 - CADASTRO DE PACIENTE                         |\n");
	printf("|   2 - MOSTRAR ELEMENTOS NA ORDEM DE CADASTRO       |\n");
	printf("|   3 - MOSTRAR DADOS EM ORDEM CRESCENTE             |\n");
	printf("|   4 -	MOSTRAR DADOS EM ORDEM DECRESCENTE           |\n");
	printf("|   5 -	EXCLUIR PACIENTE INDIVIDUALMENTE             |\n");
	printf("|   6 -	EXCLUIR PACIENTE POR MEDICO                  |\n");
	printf("|----------------------------------------------------|\n");
	printf("|DIGITE A OPCAO DESEJADA.:                           |\n");
	printf("|----------------------------------------------------|\n");
	gotoxy(29,9); // inserir o curso na frente do digite a opcao desejada primeiro parametro numero da coluna segundo parametro numero da linha
	selecao_opcao(); // chama de funçao 
}


void selecao_opcao()
{
	char opcao = ' ';
	scanf("%c",&opcao);
	
	switch(opcao)
	{
		case '1' : cadastro(); break;
		case '2' : ordem_cadastro(); break;
		case '3' : ordem_cre_dec(opcao); break;
		case '4' : ordem_cre_dec(opcao); break;
		case '5' : excluir_paciente(opcao); break;
		case '6' : excluir_paciente(opcao); break;
		default  : break;
	}
	getchar();
	menu();
}


void cadastro()
{
	textbackground(8); // define a cor de fundo cinza para a tela
	system("cls"); // limpa a tela
	textcolor(0); // define a cor da fonte como preta
	
	
	if(num_cadastro < num)
	{
	
		printf("|-----------------------------CADASTRO-----------------------------|\n");
		printf("|PACIENTE.:                                                        |\n");
		printf("|MEDICO.:                                                          |\n");
		printf("|DATA NASCIMENTO.:                                                 |\n");
		printf("|SEXO.:                                                            |\n");
		printf("|------------------------------------------------------------------|\n");
		
		
		gotoxy(strlen("PACIENTE.:")+3,2); // a funcao strlen retorna o numero de caracter da string passada como parametro 
		getchar();						 // e a funcao gotoxy posiciona o cursor atravez do parametro x e y.	
		fgets (p[num_cadastro].nome, 50, stdin); 
	

	    gotoxy(strlen("MEDICO.:")+3,3);
		fgets (p[num_cadastro].medico, 50, stdin);
		
		gotoxy(strlen("DATA NASCIMETO.:")+4,4);
		scanf("%s",&p[num_cadastro].data);
	
	
		gotoxy(strlen("SEXO.:")+3 ,5);
		scanf("%d",&p[num_cadastro].sexo);
		
		
		p1[num_cadastro] = p[num_cadastro];
		num_cadastro++;
	}
	else
	{
		error(2);
	}
}

void ordem_cadastro()
{
	int i = 0;
	system("cls");
	
	if (num_cadastro > 0)
	{	
		for(i = 0; i < num_cadastro; i++)
		{
			printf("|----------------CADASTRO-----------------------|\n");
			printf("|PACIENTE.:%s\n",p[i].nome);
			printf("|MEDICO.:%s\n",p[i].medico);
			printf("|DATA.:%s\n",p[i].data);
			printf("|SEXO.: ");
			if (p[0].sexo == 1) {printf("M");} else{printf("F");}
			printf("\n");
			printf("|-----------------------------------------------|\n");
		}
	}
	else
	{
		error(1);
	}
	getchar();
}

void ordem_cre_dec(char x)
{
	int i = 0;
	int j = 0;
	system("cls");
	
	if(num_cadastro > 0)
	{
		copia_infomacoes();
	
		for(i = 0; i < num_cadastro; i++)
		{
			for(j = 0; j < num_cadastro; j++)
			{
				if (x == '3')
				{
					if(strcmp(p1[i].nome, p1[j].nome) < 0  )
			 		{	
			 			p1[num + 1] = p1[i];
						p1[i] = p1[j];
						p1[j] = p1[num + 1];
			 		}

				}	
			
				if (x == '4')
				{
					if(strcmp(p1[i].nome, p1[j].nome) > 0)
			 		{
			 			p1[num + 1] = p1[i];
						p1[i] = p1[j];
						p1[j] = p1[num + 1];
			 		}
			 	}
			}
		}
	
		for(i = 0; i < num_cadastro; i++)
		{
		
			printf("|----------------CADASTRO-----------------------|\n");
			printf("|PACIENTE.:%s\n",p1[i].nome);
			printf("|MEDICO.:%s\n",p1[i].medico);
			printf("|DATA.:%s\n",p1[i].data);
			printf("|SEXO.: ");
			if (p[0].sexo == 1) {printf("M");} else{printf("F");}
			printf("\n");
			printf("|-----------------------------------------------|\n");
		}

	}
	
	else
	{
		error(1);
	}
	getchar();
}

void excluir_paciente(char opcao)
{
	char nome[50];
	int i= 0;
	int flag = 0;
	
	system("cls");
	printf("|----------------EXCLUIR_CADASTRO--------------|\n");
	if (opcao == '5') 
	{
		printf("|PACIENTE.:\n");
	}
	else
	{
		printf("|MEDICO.:\n");
	}
	printf("|----------------------------------------------|\n");
	getchar();
	gotoxy(12,2);
	fgets(nome, 50, stdin);
	gotoxy(1,4);
	
	for(i = 0; i <= num_cadastro; i++)
	{
		if(strcmp(nome,p[i].nome) == 0 && opcao == '5' || strcmp(nome,p[i].medico) == 0 && opcao == '6')
		{
			printf("EXCLUIDO COM SUCESSO\n");
			strcpy(p[i].nome, " ");
			strcpy(p[i].medico," ");
			p[i].sexo = ' ';
			strcpy(p[i].data, " ");
			flag ++;
		}				
	}
	if (flag == 0) 
	{
		printf("O REGISTRO NAO ESTA CADASTRADO");
	} 
	else
	{
		organiza_dados(opcao); 
		num_cadastro = num_cadastro - flag;
	}	
}

void organiza_dados(char opcao) // toda vez que excluir registro o sistema organiza os dados.
{
	int i = 0;
	
	if(opcao == '5')
	{
		for(i = 0; i < num_cadastro; i ++)
		{
			if(strcmp(p[i].nome," ") == 0)
			{
				p[i] = p[i+1];
				strcpy(p[i+1].nome, " "); 
			}
		}		
	}
	
	if(opcao == '6')
	{
		for(i = 0; i < num_cadastro; i ++)
		{
			if(strcmp(p[i].medico," ") == 0)
			{
				p1[num +1] = p[i+1];
				strcpy(p[i+1].medico, " ");
				p[i] = p1[num+1]; 
			}
		}		
	}
}

void copia_infomacoes()
{
	int i;
	
	for(i = 0; i < num_cadastro;i++)
	{
		p1[i] = p[i];
	}
	
}

void error(int x)
{
	switch (x)
	{
		case 1: 
		printf("NAO EXISTE REGISTRO DE PACIENTES \n");
		printf("DIGITE ENTER PARA RETORNAR AO MENU PRINCIPAL");
		getchar();
		break;
		
		case 2:
			printf("IMPOSSIVEL CADASTRAR MAIS PACIENTES\n");
			printf("TECLE ENTER PARA RETORNAR AO MENU PRINCIPAL");
			break;
	}
	getchar();
}
