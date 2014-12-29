 #include <stdio.h>
#include <stdlib.h>
#include <conio.h>	//Utilidade = Troca de cor do compilador
#include <locale.h>	//Utilidade = Colocar em Português


struct professor	// O programa pedia pra armazenar codigo, sexo e num_horas
					// Acrescentei essas 3 variaveis pra ficar melhor ( sal_bruto, sal_liquido e desconto)
{
	int codigo;
	char sexo;
	int num_horas;
	float sal_bruto;
	float sal_liquido;
	int desconto;
};

int main(int argc, char *argv[]) {
setlocale (LC_ALL, "Portuguese");	//Comando para mudar para Portugues
	struct professor professor [10];	//São 10 professores
	int i;	//Contador
	float preco_hora = 12.50;	// Valor previamente estabelecido para cada hora/aula
	float total_m = 0, media_m = 0;		// total_m ( Soma todos sal_bruto masculinos) ; media_m ( Faz a media masculina)
	float total_f = 0, media_f = 0;		// total_f ( Soma todos sal_bruto femininos) ; media_f ( Faz a media feminina)
	int num_m = 0, num_f = 0; 	// Conta o numero de homens e mulheres
	
	for ( i = 0 ; i < 10 ; i ++) // Zerando valores que ficam na memoria do computador
	{
		professor[i].codigo = 0;
		professor[i].num_horas = 0;
		professor[i].sal_bruto = 0;
		professor[i].sal_liquido = 0;
		professor[i].desconto = 0;
		
	}
	
	for ( i = 0 ; i < 10 ; i++)	// Entrada de valores
	{
		printf("====================================\n");
		printf("²²Codigo:");
		scanf("%d", &professor[i].codigo);
		printf("²²Sexo (M ou F):");
		fflush(stdin);	// Conserta problemas de execução com funcao scanf %c
		scanf("%c", &professor[i].sexo);
		printf("²²Numero de horas/aulas dadas no mes:");
		scanf("%d", &professor[i].num_horas);
		printf("====================================\n");
		printf("\n\n");
	}	
	
	system("cls");	//Limpa a tela
	
	for ( i = 0 ; i < 10 ; i++)		// For p/ calcular sal_bruto e sal_liquido
	{
		professor[i].sal_bruto = preco_hora * professor[i].num_horas;	// Salario Bruto = preco da hora * numero de horas dadas
		
		if (professor[i].num_horas < 70)	// Com menos de 70 horas de aula
		{
			if(professor[i].sexo == 'M' || professor[i].sexo == 'm')	//Homens
			{
				professor[i].sal_liquido = professor[i].sal_bruto * 0.9; // 0.9 porque o desconto é de 10% ( 1 - 10% = 0.9 )
				professor[i].desconto = 10;		// Valor do desconto
			}
			
			else	// Mulheres
			{
				professor[i].sal_liquido = professor[i].sal_bruto * 0.93;
				professor[i].desconto = 7;	
			}
		}
		
		else	// Com mais de 70 horas de aula
		{
			if(professor[i].sexo == 'M' || professor[i].sexo == 'm')	//Homens
			{
				professor[i].sal_liquido = professor[i].sal_bruto * 0.92;
				professor[i].desconto = 8;
			}
			
			else	// Mulheres
			{
				professor[i].sal_liquido = professor[i].sal_bruto * 0.95;
				professor[i].desconto = 5;
			}
		}
	}
	
	for ( i = 0 ; i < 10 ; i ++)	// For p/ somar os sal_bruto e contar o nº de professores de cada sexo
	{
		if (professor[i].sexo == 'M' || professor[i].sexo == 'm')
		{
			total_m = professor[i].sal_bruto + total_m;		//Soma salarios
			num_m ++;	//Conta profesores
			
		}
		
		else if (professor[i].sexo == 'F' || professor[i].sexo == 'f')
		{
			total_f = professor[i].sal_bruto + total_f;		//Soma salarios
			num_f ++;	//Conta profesores
		}
	}
	
	
	for ( i = 0 ; i < 10 ; i ++)	//Saida dos dados
	{
		
		printf("\n====================================\n");
		printf("Professor: %d\n", i+1); // i + 1 porque contador inicia em "0"
		printf("Codigo: %d\n", professor[i].codigo);
		printf("Salario Bruto: %.2f\n", professor[i].sal_bruto);
		printf("Desconto do Salario: %d%% \n", professor[i].desconto);
		printf("Salario Liquido: %.2f\n", professor[i].sal_liquido);
		printf("====================================\n");
	}
	
	media_m = total_m / num_m;	//Calcula media de cada sexo
	media_f = total_f / num_f;
	
	printf("Media Masculino: %.2f\n", media_m);	//Saida dos valores das medias de cada sexo
	printf("Media Feminino: %.2f\n", media_f);
	
	return 0;
}
