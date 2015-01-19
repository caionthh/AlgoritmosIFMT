#include <stdio.h>
#include <stdlib.h>
#include <conio.c>

// definicao de constantes
const quant = 5;

// definicao da estrutura
struct{
	int num_ins;
	int idade;
	int pontuacao;
	int cod_curso;
} dados, aux, curso_1[5], curso_2[5], curso_3[5]; // utilizando 5 vagas por curso e tres cursos para facilitar os teste e diminuir o numero de cadastramento


// prototipos de funçoes
void menu();
void cadastro();
void lista_1();
void lista_2();
void lista_3();
void organiza_1();
void organiza_2();
void organiza_3();
void visualizar_dados();


//variaveis globais
int contador_1 = 0;
int contador_2 = 0;
int contador_3 = 0;

// funcao principal
void main()
{
	while(1) menu();	
}


void menu()
{
	int opcao = 0;
	system("cls");
	printf("|------------------------MENU------------------------|\n");
	printf("|   1 - CADASTRO DE ALUNOS                           |\n");
	printf("|   2 - VISUALIZACAO AS LISTAS DE APROVADOS          |\n");
	printf("|----------------------------------------------------|\n");
	printf("|DIGITE A OPCAO DESEJADA.:                           |\n");
	printf("|----------------------------------------------------|\n");
	gotoxy(strlen("DIGITE A OPCAO DESEJADA.:")+3,5);
	scanf("%d",&opcao);
	

	if(opcao == 1) cadastro();
	else visualizar_dados();
}

void cadastro()
{
	system("cls");
	printf("numero de inscricao[0..15].:");
	scanf("%d",&dados.num_ins);
	printf("\n");
	
	printf("idade.:");
	scanf("%d",&dados.idade);
	printf("\n");
	
	printf("cod_curso[1..3].:");
	scanf("%d",&dados.cod_curso);
	printf("\n");
	
	printf("potuacao[0..5000].:");
	scanf("%d",&dados.pontuacao);
	printf("\n");
			
	//distribuir
	if (dados.cod_curso == 1){lista_1();}
	if (dados.cod_curso == 2){lista_2();}
	if (dados.cod_curso == 3){lista_3();}
}

void lista_1()
{
	if (contador_1 < quant) // aqui os dados sao inseridos mais sem organizar caso o numero de cadastro seja maior do que o permito o sistema comeca a organizar os dados 
	{
		curso_1[contador_1] = dados;
		contador_1 = contador_1 + 1;
	}
	else
	{
		organiza_1();
		
		// verifica se ultimo cadastro pode ser incluido na lista de classificados
		if (curso_1[quant - 1].pontuacao < dados.pontuacao) 
		{
			curso_1[quant - 1] = dados; 
			organiza_1();
		}
		
		else if(curso_1[quant - 1].pontuacao == dados.pontuacao && dados.idade > curso_1[quant - 1].idade) 
		{
			curso_1[quant - 1] = dados;	
			organiza_1();
		}
	}
}


void lista_2()
{
	if (contador_2 < quant) // aqui os dados sao inseridos mais sem organizar caso o numero de cadastro seja maior do que o permito o sistema comeca a organizar os dados 
	{
		curso_2[contador_2] = dados;
		contador_2 = contador_2 + 1;
	}
	else
	{
		organiza_2();
		
		// verifica se ultimo cadastro pode ser incluido na lista de classificados
		if (curso_2[quant - 1].pontuacao < dados.pontuacao) 
		{
			curso_2[quant - 1] = dados; 
			organiza_2();
		}
		
		else if(curso_2[quant - 1].pontuacao == dados.pontuacao && dados.idade > curso_2[quant - 1].idade) 
		{
			curso_2[quant - 1] = dados;	
			organiza_2();
		}
	}
}


void lista_3()
{
	if (contador_3 < quant) // aqui os dados sao inseridos mais sem organizar caso o numero de cadastro seja maior do que o permito o sistema comeca a organizar os dados 
	{
		curso_3[contador_3] = dados;
		contador_3 = contador_3 + 1;
	}
	else
	{
		organiza_3();
		
		// verifica se ultimo cadastro pode ser incluido na lista de classificados
		if (curso_3[quant - 1].pontuacao < dados.pontuacao) 
		{
			curso_3[quant - 1] = dados; 
			organiza_3();
		}
		
		else if(curso_3[quant - 1].pontuacao == dados.pontuacao && dados.idade > curso_3[quant - 1].idade) 
		{
			curso_3[quant - 1] = dados;	
			organiza_3();
		}
	}
}

void organiza_1()
{
	int i,j;
		
	for(i = 0; i<=4; i++)
		{
			for(j = 0; j <= 4; j++)
			{
				if(curso_1[j].pontuacao < curso_1[i].pontuacao)
				{
					aux = curso_1[i]; // guarda informacao
					curso_1[i] = curso_1[j]; // organiza em ordem decrescente
					curso_1[j] = aux; // troca de dados entre duas posiçoes; 
				}
				else if(curso_1[j].pontuacao == curso_1[i].pontuacao)
				{
					// verificar a idade
					  if(curso_1[j].idade < curso_1[i].idade) // caso idade seja maior o candidato prioridade e deve-se organizar as informaçoes 
					  {									     
					  	aux = curso_1[i];
					  	curso_1[i] = curso_1[j];
					  	curso_1[j] = aux;
					  }					
				}
			}
		}
}



void organiza_2()
{
	int i,j;
		
	for(i = 0; i<=4; i++)
		{
			for(j = 0; j <= 4; j++)
			{
				if(curso_2[j].pontuacao < curso_2[i].pontuacao)
				{
					aux = curso_2[i]; // guarda informacao
					curso_2[i] = curso_2[j]; // organiza em ordem decrescente
					curso_2[j] = aux; // troca de dados entre duas posiçoes; 
				}
				else if(curso_2[j].pontuacao == curso_2[i].pontuacao)
				{
					// verificar a idade
					  if(curso_2[j].idade < curso_2[i].idade) // caso idade seja maior o candidato prioridade e deve-se organizar as informaçoes 
					  {									     
					  	aux = curso_2[i];
					  	curso_2[i] = curso_2[j];
					  	curso_2[j] = aux;
					  }					
				}
			}
		}
}



void organiza_3()
{
	int i,j;
		
	for(i = 0; i <= quant - 1; i++)
		{
			for(j = 0; j <= quant - 1; j++)
			{
				if(curso_3[j].pontuacao < curso_3[i].pontuacao)
				{
					aux = curso_3[i]; // guarda informacao
					curso_3[i] = curso_3[j]; // organiza em ordem decrescente
					curso_3[j] = aux; // troca de dados entre duas posiçoes; 
				}
				else if(curso_3[j].pontuacao == curso_3[i].pontuacao)
				{
					// verificar a idade
					  if(curso_3[j].idade < curso_3[i].idade) // caso idade seja maior o candidato prioridade e deve-se organizar as informaçoes 
					  {									     
					  	aux = curso_3[i];
					  	curso_3[i] = curso_3[j];
					  	curso_3[j] = aux;
					  }					
				}
			}
		}
}



void visualizar_dados()
{
	system("cls");
	int i = 0;
	
	printf("CLASSIFICADOS NO CURSO_1\n");
	for(i = 0; i <= quant - 1; i++)
	{
		printf("NUM_INS: %d IDADE: %d PONTUACAO: %d COD_CURSO: %d\n",curso_1[i].num_ins, curso_1[i].idade, curso_1[i].pontuacao, curso_1[i].cod_curso);
	}
	
	printf("\n");
		

	printf("CLASSIFICADOS NO CURSO_2\n");
	for(i = 0; i <= quant - 1; i++)
	{
		printf("NUM_INS: %d IDADE: %d PONTUACAO: %d COD_CURSO: %d\n",curso_2[i].num_ins, curso_2[i].idade, curso_2[i].pontuacao, curso_2[i].cod_curso);
	}
	printf("\n");
	
	printf("CLASSIFICADOS NO CURSO_3\n");
	for(i = 0; i <=quant - 1; i++)
	{
		printf("NUM_INS: %d IDADE: %d PONTUACAO: %d COD_CURSO: %d\n",curso_3[i].num_ins, curso_3[i].idade, curso_3[i].pontuacao, curso_3[i].cod_curso);
	}

	getchar();
	getchar();
}

