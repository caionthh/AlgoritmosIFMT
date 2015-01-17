#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//LerDados
void LerDados();

//Pessoa
struct Pessoa {
	float salario;
	int idade;
	int sexo;
	int filhos;
} *pessoas;
int numPessoas = 0;

//Prefeitura
struct Prefeitura {
	float mediaMulheres, somaMulheres, idadeMulheres;
	float mediaSalarioPop, salarioPop;
	float mediaFilhos, numFilhos;
	float maiorSalario;
	int menorIdade;
	
} prefeitura;


int main(int argc, char *argv[]) {
	
	//Ler
	LerDados(1);
	
	return 0;
}

//Ler
void LerDados() {
	
	//Variaveis
	int idade = 0;
	int sexo = 0;
	char cSexo;
	float salario = 0;
	int filhos = 0;	
	
	system("cls");
	
	//Idade
	printf("\nIdade: ");
	fflush(stdin);
	scanf("%d", &idade);
	
	//Ler?
	if (idade > 0) {
		
		//Sexo
		do {
			fflush(stdin);
			printf("\nSexo (m ou f): ");
			cSexo = getchar();
		} while (cSexo != 'm' && cSexo != 'M' && cSexo !='F' && cSexo !='f');
		if (cSexo == 'm' || cSexo == 'M')
			sexo = 1;
		if (cSexo == 'f' || cSexo == 'F')
			sexo = 2;		
		
		//Salario
		printf("\nSalario: ");
		fflush(stdin);
		scanf("%f", &salario);
		
		//Filhos
		printf("\nFilhos: ");
		fflush(stdin);
		scanf("%d", &filhos);
		
		//Adicionar Registro
		numPessoas++;
		pessoas = realloc(pessoas, numPessoas * sizeof(struct Pessoa));
		pessoas[numPessoas-1].idade = idade;
		pessoas[numPessoas-1].sexo = sexo;
		pessoas[numPessoas-1].salario = salario;
		pessoas[numPessoas-1].filhos = filhos;
		
		//Registro da prefeitura
		if (sexo == 2 && salario <= 300.00f) {
			prefeitura.somaMulheres++;
			prefeitura.idadeMulheres += idade;
			
			//Recalcular media
			prefeitura.mediaMulheres = prefeitura.idadeMulheres / prefeitura.somaMulheres;
		}
		
		//Salario populacao
		prefeitura.salarioPop += salario;
		prefeitura.mediaSalarioPop = prefeitura.salarioPop / numPessoas;
		
		//Menor Idade
		if (prefeitura.menorIdade == 0 || idade <= prefeitura.menorIdade)
			prefeitura.menorIdade = idade;
			
		//Media Filhos
		prefeitura.numFilhos+=filhos;
		prefeitura.mediaFilhos = prefeitura.numFilhos /  numPessoas;
		
		//Maior Salario
		if (salario >= prefeitura.maiorSalario) {
			prefeitura.maiorSalario = salario;
		}
		
		LerDados();
	}
	else
	{
		system("cls");
		
		printf("Nao ha mais registros a fazer.");
		
		//Mostrar Dados
		printf("\n\nMedia de idade das mulheres com salario abaixo de R$300,00: %.2f", prefeitura.mediaMulheres);
		printf("\nMedia de salario da populacao: %.2f", prefeitura.mediaSalarioPop);
		printf("\nMedia numero de filhos: %.2f", prefeitura.mediaFilhos);
		printf("\nMaior salario: %.2f", prefeitura.maiorSalario);
		printf("\nMenor idade: %d", prefeitura.menorIdade);
		
		getch();
		
	}
	
}
