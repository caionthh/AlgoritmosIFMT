#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int registrados = 0;
	int limite = 5;

	system("color 70");
	
	for(i=0; i<limite ; i++)
	{
		printf("께께께께께께께께께�\n");
		printf("께 PACIENTE %d \n", i+1);
		printf("께께께께께께께께께�\n" );
		printf("께 NOME:");
		gets(paciente[i].nome);
		fflush(stdin);
		printf("께께께께께께께께�\n" );
		printf("께 IDADE:");
		scanf("%d", &paciente[i].idade);
		printf("께께께께께께께께께�\n" );
		fflush(stdin);
		printf("께 SEXO (M ou F):");
		scanf("%c", &paciente[i].sexo);
		printf("께께께께께께께께께�\n" );
		printf("께 ALTURA (m): ");
		scanf("%f", &paciente[i].altura);
		printf("께께께께께께께께께�\n" );
		printf("께 PESO (Kg): ");
		scanf("%f", &paciente[i].peso);
		fflush(stdin);
		printf("께께께께께께께께께�\n" );
		printf("\n\n");	
		system("cls");
		registrados++;
		paciente[i].peso_ideal = PesoIdeal (paciente[i].sexo, paciente[i].altura);
	}
	do
	{
		printf("께께께께께께께께�\n" );
		printf("1 - PESSOA MAIS PESADA\n");
		printf("2 - PESSOAS ACIMA DO PESO \n");
		printf("3 - PESSOAS ABAIXO DO PESO \n");
		printf("4 - SAIR\n");
		printf("께께께께께께께께�\n" );
		scanf("%d", &opcao);
		system("cls");	// Limpa a tela
		
		switch(opcao)
		{
			
			case 1:		//Mostra paciente mais pesado
				
				for(i=0 ; i<registrados ; i++)
				{
					if(paciente[i].peso > maior_peso)	//Condicao para verificar qual paciente tem maior peso
					{
						maior_peso = paciente[i].peso;	//Armazena peso do paciente se este possuir o maior peso
						strcpy(&mais_pesado, &paciente[i].nome);	//Copia o nome do paciente para a variavel " mais_pesado "
					}
				}
				
				printf("께께께께께께께께\n" );	//Saida do paciente mais pesado
				printf("MAIS PESADO : %s\n", mais_pesado);
				printf("께께께께께께께께�\n\n\n" );
				
			break;
			
			case 2:		//Mostra pessoas acima do peso
				for (i=0; i < registrados; i++)
				{
					if(paciente[i].peso > paciente[i].peso_ideal)
					{
						printf("PACIENTE: %s \n", paciente[i].nome);	//Saida das pessoasacima do peso ideal
						printf("PESO: %f\n\n", paciente[i].peso);
					}
					
				}
			break;
			
			case 3:		//Mostra pessoas abaixo do peso
				
				for (i=0; i < registrados; i++)
				{
					paciente[i].falta_peso = paciente[i].peso_ideal - paciente[i].peso;		//Calcula quanto falta para atingir o peso ideal
					if(paciente[i].peso < paciente[i].peso_ideal)
					{
						printf("PACIENTE: %s \n", paciente[i].nome);	//Saida das pessoas abaixo do peso ideal
						printf("PACIENTE: %f\n", paciente[i].altura);
						printf("PESO: %.2f\n", paciente[i].peso);
						printf("PESO QUE FALTA: %.2f\n\n", paciente[i].falta_peso);
					}
				}
			break;
			
			case 4:
				printf("Pressione 4 novamente para sair.");
				scanf("%d", &opcao);
				break;
			
			default:
				printf("Opcao invalida\n");
			break;
		}
	} while(opcao != 4);
		
	return 0;
}

float PesoIdeal (char sexo, float alt)	// Funcao que calcula o peso ideal
{
	float peso_ideal = 0; 
	if ( sexo == 'M' || sexo == 'm')
	{
		peso_ideal = (72.7 * alt) - 58;		//Formula para sexo masculino
	}
	
	if ( sexo == 'F' || sexo == 'f')		//Formula para sexo feminino
	{
		peso_ideal = (62.1 * alt) - 44.7;
	}
	
	return peso_ideal;
}




