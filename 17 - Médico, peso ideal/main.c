#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct medico
{
	char nome[50];
	int idade;
	char sexo;
	float altura;
	float peso;
	float peso_ideal;
	float falta_peso;
	
};

int main(int argc, char *argv[]) {
	struct medico paciente[20];
	int i;
	float maior_peso = 0;
	char mais_pesado[50];
	int opcao;
	float PesoIdeal (char sexo, float alt);

	system("color 70");
	
	for(i=0; i<20 ; i++)
	{
		printf("²²²²²²²²²²²²²²²²²²²\n");
		printf("²² PACIENTE %d \n", i+1);
		printf("²²²²²²²²²²²²²²²²²²²\n" );
		printf("²² NOME:");
		gets(paciente[i].nome);
		fflush(stdin);
		printf("²²²²²²²²²²²²²²²²²\n" );
		printf("²² IDADE:");
		scanf("%d", &paciente[i].idade);
		printf("²²²²²²²²²²²²²²²²²²²\n" );
		fflush(stdin);
		printf("²² SEXO (M ou F):");
		scanf("%c", &paciente[i].sexo);
		printf("²²²²²²²²²²²²²²²²²²²\n" );
		printf("²² ALTURA (m): ");
		scanf("%f", &paciente[i].altura);
		printf("²²²²²²²²²²²²²²²²²²²\n" );
		printf("²² PESO (Kg): ");
		scanf("%f", &paciente[i].peso);
		fflush(stdin);
		printf("²²²²²²²²²²²²²²²²²²²\n" );
		printf("\n\n");	
		system("cls");
		
		paciente[i].peso_ideal = PesoIdeal (paciente[i].sexo, paciente[i].altura);
	}
	do
	{
		printf("²²²²²²²²²²²²²²²²²\n" );
		printf("1 - PESSOA MAIS PESADA\n");
		printf("2 - PESSOAS ACIMA DO PESO \n");
		printf("3 - PESSOAS ABAIXO DO PESO \n");
		printf("4 - SAIR\n");
		printf("²²²²²²²²²²²²²²²²²\n" );
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao)
		{
			
			case 1:
				
				for(i=0 ; i<20 ; i++)
				{
					if(paciente[i].peso > maior_peso)
					{
						maior_peso = paciente[i].peso;
						strcpy(&mais_pesado, &paciente[i].nome);
					}
				}
				
				printf("²²²²²²²²²²²²²²²²\n" );
				printf("MAIS PESADO : %s\n", mais_pesado);
				printf("²²²²²²²²²²²²²²²²²\n\n\n" );
				
			break;
			
			case 2:
				for (i=0; i < 20; i++)
				{
					if(paciente[i].peso > paciente[i].peso_ideal)
					{
						printf("PACIENTE: %s \n", paciente[i].nome);
						printf("PESO: %f\n\n", paciente[i].peso);
					}
					
				}
			break;
			
			case 3:
				
				for (i=0; i < 20; i++)
				{
					paciente[i].falta_peso = paciente[i].peso_ideal - paciente[i].peso; 
					if(paciente[i].peso < paciente[i].peso_ideal)
					{
						printf("PACIENTE: %s \n", paciente[i].nome);
						printf("PACIENTE: %f\n", paciente[i].altura);
						printf("PESO: %.2f\n", paciente[i].peso);
						printf("PESO QUE FALTA: %.2f\n\n", paciente[i].falta_peso);
					}
				}
			break;
			
			default:
				printf("Opcao invalida\n");
			break;
		}
	} while(opcao != 4);
		
	return 0;
}

//Metodo para receber peso Ideal
float PesoIdeal (char sexo, float alt)
{
	float peso_ideal = 0; 
	if ( sexo == 'M' || sexo == 'm')
	{
		peso_ideal = (72.7 * alt) - 58;
	}
	
	if ( sexo == 'F' || sexo == 'f')
	{
		peso_ideal = (62.1 * alt) - 44.7;
	}
	
	return peso_ideal;
}




