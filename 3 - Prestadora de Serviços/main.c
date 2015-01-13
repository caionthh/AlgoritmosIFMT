#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>		// UTILIDADE = COPIAR UMA STRING EM OUTRA
#include <conio.h>	//UTILIDADE = MUDANCA DE COR

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");
system("color 03");		//Testando cor
	
	int opcao_menu1, opcao_menu2, achou;	// "Achou" serve para varredura -- !! MUITO ÚTIL !!
	int  contador, dia_atual, servicos, i,j;  //Contadores
	int historico_dia;	// P/ o case 3; Armazena o dia do qual o programa mostrará o histório
	float maior_valor, menor_valor;		// P/ o case 4; Mostra os serviços neste intervalo " menor e maior"
	int ocupado[30];	//Variável para dizer que os servicos do dia já foram adicionados; Quando for "0", está vazio; Quando for"1", ta ocupado
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
	
	struct servicos_empresa servico[4]; //Tam. 4 para 4 tipos de serviços ( pintura, limpeza, jardinagem e s. em geral)
	struct empresa atendimento[30][3];	//30 Dias em que, cada dia, tem 3 serviços
	
	for(i=0 ; i<30 ; i++)
	{
		ocupado[i] = 0;		
		for(j=0 ; j<3 ; j ++)
		{
			atendimento[i][j].num_servico = 0;		//Atribuindo "0" para dizer que ta ocupada, ou não
		}
	}
	while(opcao_menu1 != 6)	// Comando "6" fecha o programa; WHILE antes do menu
	{
	printf("==============\n");
	printf("==== MENU ====\n");
	printf("==============\n\n");
	printf("1 - Cadastrar os tipos de serviços\n");
	printf("2 - Cadastrar os serviços prestados \n");
	printf("3 - Mostrar os serviços prestados em um determinado dia\n");
	printf("4 - Mostrar os serviços prestados dentro de um intervalo de valor\n");
	printf("5 - Mostrar um relatório geral, que exibe, inclusive, a descrição do serviço\n");
	printf("6 - Finalizar\n\n");
	printf("=> ");		//Estética
	scanf("%d", &opcao_menu1);
	system("cls");	//Limpa a tela
	
		switch(opcao_menu1) 
		{
			case 1: //CADASTRA OS SERVICOS
				
				printf("==========================\n");
				printf("== CADASTRO DE SERVIÇOS ==\n");
				printf("==========================\n\n");
				
				for (i = 0; i < 4; i++)	//Cadastro dos 4 Serviços
				{
					printf("Código: ");
					scanf("%d", &servico[i].codigo);
					printf("\nDescrição: ");
					fflush(stdin); //Limpa memória ( corrige o problema do "gets()"
					gets(servico[i].descricao);
					printf("\n\n");			
				}	
				system("cls");			
				break;
				
			case 2:
				
				printf("Dia Atual ( numérico ):");
				scanf("%d", &i);	//Variavel que vai dizer o dia em que o serviço será adicionado
				system("cls");		//PROBLEMA : O DIA "1" ESTÁ NO VETOR "0", O "2" NO "1"
									
				
				printf("========================\n");
				printf("== SERVIÇOS PRESTADOS ==\n");
				printf("========================\n\n");
				
				printf("| Dia: %d |\n\n", i);
				
				for(j = 0 ; j < 3; j ++)	// Entrada de serviços diário
				{
					printf("===================\n");
					printf("%dº serviço\n\n", servicos+1);
					printf("Número do serviço:");
					scanf("%d", &atendimento[i-1][j].num_servico);	//PROBLEMA CORRIGIDO = DIMINUI "1" DA VARIÁVEL "i"
					printf("\nValor do serviço:");
					scanf("%f", &atendimento[i-1][j].valor_servico);
					printf("\nCódigo do cliente:");
					scanf("%d", &atendimento[i-1][j].cod_cliente);
					Redigite:	//FUNCAO "goto" (checkpoint) = volta para cá se o codigo digitado não existir
					printf("\nCódigo do serviço:");
					scanf("%d", &atendimento[i-1][j].cod_servico);
					printf("===================\n\n");
					ocupado[i-1] = 1;	//Este dia agora está ocupado	
					
					achou = 0;	//VERIFICA EXISTENCIA DO "cod_servico" em relação aos servicos já cadastrados
					for(contador = 0; contador < 4 ; contador++)	
					{
						if(atendimento[i-1][j].cod_servico == servico[contador].codigo) 	//servico[contador].codigo vai alterando conforme o ciclo for(contador)
						{
							strcpy (&atendimento[i-1][j].nome, &servico[contador].descricao);	//COPIA O NOME DO SERVIÇO PARA A STRUCT DO FUNCIONARIO ( Necessário devido ao tipo de structs ( matriz e vetor) )
							achou = 1;		// RECEBE "1"  PORQUE ACHOU E PULA O PRÓXIMO "IF"														
						
						}
					}						
					if(achou == 0)	// "achou" continua "0" porque não achou nenhum codigo
					{
						printf("Código de serviço não Cadastrado\n\n");
						goto Redigite;		//goto (checkpoint) "Redigite; até digitar um numero válido
					}
				}
				break;
				
			case 3:
				printf("== HISTÓRICO DIÁRIO ==\n\n");
				printf("DIA:");
				scanf("%d", &historico_dia);		//Mesmo problema do (DIA) no case 2; Correção efetuada diminuido "1"
				system("cls");
				
				printf("== SERVIÇOS DO DIA ==\n\n");	//Título
				
				achou = 0; 	//Começa em "0"; se ñ achar servicos neste dia, continua "0" e imprime mensagem
				for (i = 0; i < 30; i ++)	//Varredura para achar o DIA digitado
				{
				
							
					if(ocupado[i] == 1)	//Quando ocupado está = "1", significa que existem servicos neste dia
					{
										
						if(i+1 == historico_dia)	// Se o nº digitado for igual ao dia( diminuindo "1" p/ corrigir problema de vetor
						{		
							achou = 1;	//Existem servicos
									
							for (j = 0; j < 3; j ++)	//Os 3 serviços do dia
							{
								printf("=====================================\n");
								printf("Serviço %d: %s\n\n", j+1, atendimento[i][j].nome);	//Saída dos serviços do dia
								printf("Número do serviço: %d\n", atendimento[i][j].num_servico);
								printf("Valor do serviço: R$ %.2f\n", atendimento[i][j].valor_servico);
								printf("Código do serviço: %d\n", atendimento[i][j].cod_servico);					
								printf("Código do cliente: %d\n", atendimento[i][j].cod_cliente);
								printf("=====================================\n\n\n");							
							}
							
						
						}
											
					}
					
				}
					break;
				
				if(achou == 0)// Ñ achou nenhum servico
						{
							
							printf("Nenhum serviço efetuado no dia %d\n", historico_dia);
							
						}
				break;
				
			case 4:	//Relatório por Intervalo
			
				printf("=======================\n");
				printf("RELATÓRIO POR INTERVALO\n");
				printf("=======================\n\n");
				
				printf("Valor Mínimo:");
				scanf("%f", &menor_valor); // imprime todos os valores entre ( menor_valor && maior_valor )
				printf("\nValor Máximo:");
				scanf("%f", &maior_valor);
				system("cls");
				
				printf("== SERVIÇOS ==\n\n");
				printf("De R$%.2f à R$%.2f\n\n", menor_valor, maior_valor);		// %.2F p/ imprimir 2 nºs depois da virgula
				for ( i = 0; i < 30; i ++) // VARREDURA DOS "DIAS"	
				{
					for ( j = 0; j < 3; j ++)  // VARREDURA DOS "SERVICOS DOS DIAS"	
					{
						if(atendimento[i][j].valor_servico > menor_valor && atendimento[i][j].valor_servico < maior_valor)
						{
							printf("Número do serviço: %d\n", atendimento[i][j].num_servico);
							printf("\nValor do serviço: R$ %.2f\n", atendimento[i][j].valor_servico);
							printf("\nCódigo do serviço: %d\n", atendimento[i][j].cod_servico);
							printf("\nCódigo do cliente: %d\n\n\n", atendimento[i][j].cod_cliente);
						}														
					}
				}
				break;
				
			case 5:	//Relatório Geral
				
				printf("=====================\n");
				printf("== RELATÓRIO GERAL ==\n");
				printf("=====================\n\n");
				for ( i = 0 ; i < 30 ; i++)
				{
					for(j = 0 ; j < 3 ; j ++)
					{
						if(atendimento[i][j].num_servico != 0)
						{
							printf("===================================================\n");
							printf("Dia : %d  || Serviço %d: %s\n\n", i+1, j+1, atendimento[i][j].nome);	// i+1 e j+1 para corrigir prblema de vetor
							printf("Número do serviço: %d\n", atendimento[i][j].num_servico);
							printf("\nValor do serviço: R$ %.2f\n", atendimento[i][j].valor_servico);
							printf("\nCódigo do serviço: %d\n", atendimento[i][j].cod_servico);
							printf("\nCódigo do cliente: %d\n", atendimento[i][j].cod_cliente);
							printf("===================================================\n\n\n");
						}
					}
				}
				break;
			case 6:
				printf("#####  O PROGRAMA SERÁ ENCERRADO  #####\n\n\n\n");
				system("pause");
				break;
				
			default:
				printf("==============\n");	
				printf("OPÇÃO INVÁLIDA\n");
				printf("==============\n\n");
				break;
		}
		
	}
	return 0;
}
