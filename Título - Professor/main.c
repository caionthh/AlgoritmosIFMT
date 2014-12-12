#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

struct professor
{
	int registro;
	char nome[50];
	int cod_titulo;
	float total_hr;
	char descricao[60];
	float valor_hr;
	float total_semanal;
};
		
struct titulo
{
	int cod_titulo;
	char descricao[60];
	float valor_hr;
};

int main(int argc, char *argv[]) {
setlocale (LC_ALL, "Portuguese");
system("color F0");
	struct professor professor[14];
	struct titulo titulo[5];
	int i,j, opcao, achou;
	
	for(i=0;i<5;i++)
	titulo[i].cod_titulo = 0;	//Este "for" é para zerar os "cod_titulo"; Sendo assim , pra eu ver se já foi cadastrado, é só fazer um "if" diferente"!=" de 0
	for(i=0;i<15;i++)
	professor[i].registro = 0;
	
	while(opcao != 4)
	{
	
	system("cls");
	printf("1 - Cadastrar informações relacionadas ao título\n");
	printf("2 - Cadastrar os professores\n" );
	printf("3 - Mostrar a relação de professores\n");
	scanf("%d", &opcao);
	system("cls");
	
	switch (opcao)
	{
		case 1:
			
			for (i = 0 ; i < 5 ; i++)
			{	
				achou = 0;
				if(titulo[i].cod_titulo == 0)
				{
					
					printf("CODIGO:");
					scanf("%d", &titulo[i].cod_titulo);
					printf("DESCRIÇÃO:");
					fflush(stdin);
					gets(titulo[i].descricao);					
					printf("VALOR DA HORA:");
					scanf("%f", &titulo[i].valor_hr);
					achou = 1;		
					break;			
				}
			}
			if(achou == 0)
				printf("Cadastro de títulos lotados");
			
		break;
		
		case 2:
			for(i=0;i<14;i++)
			{
				achou = 0;
				if(professor[i].registro == 0)
				{
					printf("N° DE REGISTRO:");
					scanf("%d", &professor[i].registro);
					printf("NOME:");
					fflush(stdin);
					gets(professor[i].nome);
					printf("TOTAL DE HORAS SEMANAIS:");
					scanf("%f", &professor[i].total_hr);
					printf("TITULO:");
					scanf("%d", &professor[i].cod_titulo);
					
					for(j=0;j<5; j++)
					{
						if(professor[i].cod_titulo == titulo[j].cod_titulo)
						{
							achou = 1;
							strcpy (&professor[i].descricao, &titulo[j].descricao);		// Pega o nome que esta no titulo e passa para struct do professor ( correção de erro de vetor )
							professor[i].valor_hr = titulo[j].valor_hr;
							professor[i].total_semanal = (professor[i].valor_hr * professor[i].total_hr);
						}
					}
					if(achou == 0) // Uso do "achou" para evitar que o for repita 5x que "O codigo não existe"
					{
					system("cls");
					printf("\n|| Este código não existe ||\n\n\n");
					break;
					}
					
					break;
				}
			}
		break;
		
		case 3:
			for(i=0;i<14;i++)
			{
				
				if(professor[i].registro != 0)
				{
					printf("---------------------------------------------\n");
					printf("Nº DE REGISTRO: %d\n", professor[i].registro);
					printf("NOME: %s\n", professor[i].nome);
					printf("TITULAÇÃO: %s\n", professor[i].descricao);
					printf("HORA/AULA: R$%.2f\n", professor[i].valor_hr);
					printf("HORAS SEMANAIS: %.f\n", professor[i].total_hr);
					printf("TOTAL SEMANAL: R$%.2f\n", professor[i].total_semanal);
					printf("---------------------------------------------\n\n");
				}
			}
			getch();	//Faz uma pausa até o usuário apertar alguma tecla
		break;
	}
}
	
	return 0;
}
