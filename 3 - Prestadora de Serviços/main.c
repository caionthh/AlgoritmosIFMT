#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>		// UTILIDADE = COPIAR UMA STRING EM OUTRA
#include <conio.h>	//UTILIDADE = MUDANCA DE COR

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");
system("color 03");		//Testando cor
	
	int opcao_menu1, opcao_menu2, achou;	// "Achou" serve para varredura -- !! MUITO �TIL !!
	int  contador, dia_atual, servicos, i,j;  //Contadores
	int historico_dia;	// P/ o case 3; Armazena o dia do qual o programa mostrar� o hist�rio
	float maior_valor, menor_valor;		// P/ o case 4; Mostra os servi�os neste intervalo " menor e maior"
	int ocupado[30];	//Vari�vel para dizer que os servicos do dia j� foram adicionados; Quando for "0", est� vazio; Quando for"1", ta ocupado
	struct empresa
	{
		int num_servico;
		float valor_servico;
		int cod_servico;
		int cod_cliente;
		char nome[30];
		
	};
	
	struct servicos_empresa
	{
		int codigo;
		char descricao[30];
	
	};
	
	struct servicos_empresa servico[4]; //Tam. 4 para 4 tipos de servi�os ( pintura, limpeza, jardinagem e s. em geral)
	struct empresa atendimento[30][3];	//30 Dias em que, cada dia, tem 3 servi�os
	
	for(i=0 ; i<30 ; i++)
	{
		ocupado[i] = 0;		
		for(j=0 ; j<3 ; j ++)
		{
			atendimento[i][j].num_servico = 0;		//Atribuindo "0" para dizer que ta ocupada, ou n�o
		}
	}
	while(opcao_menu1 != 6)	// Comando "6" fecha o programa; WHILE antes do menu
	{
	printf("==============\n");
	printf("==== MENU ====\n");
	printf("==============\n\n");
	printf("1 - Cadastrar os tipos de servi�os\n");
	printf("2 - Cadastrar os servi�os prestados \n");
	printf("3 - Mostrar os servi�os prestados em um determinado dia\n");
	printf("4 - Mostrar os servi�os prestados dentro de um intervalo de valor\n");
	printf("5 - Mostrar um relat�rio geral, que exibe, inclusive, a descri��o do servi�o\n");
	printf("6 - Finalizar\n\n");
	printf("=> ");		//Est�tica
	scanf("%d", &opcao_menu1);
	system("cls");	//Limpa a tela
	
		switch(opcao_menu1) 
		{
			case 1: //CADASTRA OS SERVICOS
				
				printf("==========================\n");
				printf("== CADASTRO DE SERVI�OS ==\n");
				printf("==========================\n\n");
				
				for (i = 0; i < 4; i++)	//Cadastro dos 4 Servi�os
				{
					printf("C�digo: ");
					scanf("%d", &servico[i].codigo);
					printf("\nDescri��o: ");
					fflush(stdin); //Limpa mem�ria ( corrige o problema do "gets()"
					gets(servico[i].descricao);
					printf("\n\n");			
				}	
				system("cls");			
				break;
				
			case 2:
				
				printf("Dia Atual ( num�rico ):");
				scanf("%d", &i);	//Variavel que vai dizer o dia em que o servi�o ser� adicionado
				system("cls");		//PROBLEMA : O DIA "1" EST� NO VETOR "0", O "2" NO "1"
									
				
				printf("========================\n");
				printf("== SERVI�OS PRESTADOS ==\n");
				printf("========================\n\n");
				
				printf("| Dia: %d |\n\n", i);
				
				for(j = 0 ; j < 3; j ++)	// Entrada de servi�os di�rio
				{
					printf("===================\n");
					printf("%d� servi�o\n\n", servicos+1);
					printf("N�mero do servi�o:");
					scanf("%d", &atendimento[i-1][j].num_servico);	//PROBLEMA CORRIGIDO = DIMINUI "1" DA VARI�VEL "i"
					printf("\nValor do servi�o:");
					scanf("%f", &atendimento[i-1][j].valor_servico);
					printf("\nC�digo do cliente:");
					scanf("%d", &atendimento[i-1][j].cod_cliente);
					Redigite:	//FUNCAO "goto" (checkpoint) = volta para c� se o codigo digitado n�o existir
					printf("\nC�digo do servi�o:");
					scanf("%d", &atendimento[i-1][j].cod_servico);
					printf("===================\n\n");
					ocupado[i-1] = 1;	//Este dia agora est� ocupado	
					
					achou = 0;	//VERIFICA EXISTENCIA DO "cod_servico" em rela��o aos servicos j� cadastrados
					for(contador = 0; contador < 4 ; contador++)	
					{
						if(atendimento[i-1][j].cod_servico == servico[contador].codigo) 	//servico[contador].codigo vai alterando conforme o ciclo for(contador)
						{
							strcpy (&atendimento[i-1][j].nome, &servico[contador].descricao);	//COPIA O NOME DO SERVI�O PARA A STRUCT DO FUNCIONARIO ( Necess�rio devido ao tipo de structs ( matriz e vetor) )
							achou = 1;		// RECEBE "1"  PORQUE ACHOU E PULA O PR�XIMO "IF"														
						
						}
					}						
					if(achou == 0)	// "achou" continua "0" porque n�o achou nenhum codigo
					{
						printf("C�digo de servi�o n�o Cadastrado\n\n");
						goto Redigite;		//goto (checkpoint) "Redigite; at� digitar um numero v�lido
					}
				}
				break;
				
			case 3:
				printf("== HIST�RICO DI�RIO ==\n\n");
				printf("DIA:");
				scanf("%d", &historico_dia);		//Mesmo problema do (DIA) no case 2; Corre��o efetuada diminuido "1"
				system("cls");
				
				printf("== SERVI�OS DO DIA ==\n\n");	//T�tulo
				
				achou = 0; 	//Come�a em "0"; se � achar servicos neste dia, continua "0" e imprime mensagem
				for (i = 0; i < 30; i ++)	//Varredura para achar o DIA digitado
				{
				
							
					if(ocupado[i] == 1)	//Quando ocupado est� = "1", significa que existem servicos neste dia
					{
										
						if(i+1 == historico_dia)	// Se o n� digitado for igual ao dia( diminuindo "1" p/ corrigir problema de vetor
						{		
							achou = 1;	//Existem servicos
									
							for (j = 0; j < 3; j ++)	//Os 3 servi�os do dia
							{
								printf("=====================================\n");
								printf("Servi�o %d: %s\n\n", j+1, atendimento[i][j].nome);	//Sa�da dos servi�os do dia
								printf("N�mero do servi�o: %d\n", atendimento[i][j].num_servico);
								printf("Valor do servi�o: R$ %.2f\n", atendimento[i][j].valor_servico);
								printf("C�digo do servi�o: %d\n", atendimento[i][j].cod_servico);					
								printf("C�digo do cliente: %d\n", atendimento[i][j].cod_cliente);
								printf("=====================================\n\n\n");							
							}
							
						
						}
											
					}
					
				}
					break;
				
				if(achou == 0)// � achou nenhum servico
						{
							
							printf("Nenhum servi�o efetuado no dia %d\n", historico_dia);
							
						}
				break;
				
			case 4:	//Relat�rio por Intervalo
			
				printf("=======================\n");
				printf("RELAT�RIO POR INTERVALO\n");
				printf("=======================\n\n");
				
				printf("Valor M�nimo:");
				scanf("%f", &menor_valor); // imprime todos os valores entre ( menor_valor && maior_valor )
				printf("\nValor M�ximo:");
				scanf("%f", &maior_valor);
				system("cls");
				
				printf("== SERVI�OS ==\n\n");
				printf("De R$%.2f � R$%.2f\n\n", menor_valor, maior_valor);		// %.2F p/ imprimir 2 n�s depois da virgula
				for ( i = 0; i < 30; i ++) // VARREDURA DOS "DIAS"	
				{
					for ( j = 0; j < 3; j ++)  // VARREDURA DOS "SERVICOS DOS DIAS"	
					{
						if(atendimento[i][j].valor_servico > menor_valor && atendimento[i][j].valor_servico < maior_valor)
						{
							printf("N�mero do servi�o: %d\n", atendimento[i][j].num_servico);
							printf("\nValor do servi�o: R$ %.2f\n", atendimento[i][j].valor_servico);
							printf("\nC�digo do servi�o: %d\n", atendimento[i][j].cod_servico);
							printf("\nC�digo do cliente: %d\n\n\n", atendimento[i][j].cod_cliente);
						}														
					}
				}
				break;
				
			case 5:	//Relat�rio Geral
				
				printf("=====================\n");
				printf("== RELAT�RIO GERAL ==\n");
				printf("=====================\n\n");
				for ( i = 0 ; i < 30 ; i++)
				{
					for(j = 0 ; j < 3 ; j ++)
					{
						if(atendimento[i][j].num_servico != 0)
						{
							printf("===================================================\n");
							printf("Dia : %d  || Servi�o %d: %s\n\n", i+1, j+1, atendimento[i][j].nome);	// i+1 e j+1 para corrigir prblema de vetor
							printf("N�mero do servi�o: %d\n", atendimento[i][j].num_servico);
							printf("\nValor do servi�o: R$ %.2f\n", atendimento[i][j].valor_servico);
							printf("\nC�digo do servi�o: %d\n", atendimento[i][j].cod_servico);
							printf("\nC�digo do cliente: %d\n", atendimento[i][j].cod_cliente);
							printf("===================================================\n\n\n");
						}
					}
				}
				break;
			case 6:
				printf("#####  O PROGRAMA SER� ENCERRADO  #####\n\n\n\n");
				system("pause");
				break;
				
			default:
				printf("==============\n");	
				printf("OP��O INV�LIDA\n");
				printf("==============\n\n");
				break;
		}
		
	}
	return 0;
}
