#include <stdio.h>
#include <stdlib.h>
#include <locale.h>	// Muda o idioma para Portugues


struct Funcionario
{
	int numero;
	int codigo;
	char nome[50];
	int cargo;
	float salario;
};

struct Filial
{
	int numero;
	char nome[40];
	float salario;
};

int main(int argc, char *argv[]) {
setlocale (LC_ALL, "Portuguese");	//Funcao que altera o idioma
	
	int PegaNumero ();
	struct Filial filial[4];
	struct Funcionario funcionario[4][5];
	int achou, achou_gerente, achou_func, achou_filial, lotado, i, j, k, l, m, opcao;
	int temp_filial, ocupado[5], func_ocupado[4][5], func_codigo, temp_cargo;
	float sal_geral;
	
	for (i = 0; i<4 ; i++)	//Zerando valores da memoria
	{
		ocupado[i] = 0;
		filial[i].numero = 0;
		filial[i].salario = 0;
		sal_geral=0;
		
		for(j=0;j<5;j++)
		func_ocupado[i][j] = 0;
		funcionario[i][j].cargo = 0;
		
	}
	
	while(opcao != 4)	// opcao 4 fecha programa
		{
			printf("=========================\n");
			printf("1 - CADASTRAR FILIAL \n");
			printf("2 - CADASTRAR FUNCIONÁRIO\n");
			printf("3 - CONSULTA\n");
			printf("=========================\n\n");
			scanf("%d", &opcao);		
			system("cls");
			
			switch(opcao)
			{
				
				case 1:
				
				printf("## CADASTRO DE FILIAL ##\n\n");
				achou = 0;	// Mecanismo para verificar se ja existe uma filial com o mesmo numero que foi digitado
				for( i=0 ; i<4 ; i++)
				{
					
					if(ocupado[i] == 0)
					{
						Redigite:	//Funcao "goto"; volta pra ca se o numero de filial digitado ja existir. ( Comando na linha 78 )
						temp_filial = PegaNumero();	//Funcao que pega numero
						
						for(j=0 ; j<4 ; j++) // For ate 4 ( Que é o numero de filiais )
						{
							if (temp_filial == filial[j].numero) // Se o numero digitado for igual à filial existente
							{
								system("cls"); //Limpa a tela
								printf("=========\n");
								printf("JÁ EXISTE\n");
								printf("=========\n\n");
								goto Redigite;		// Comando que retorna para a linha 67
								
								
									
								
							}
							
							else
							{
								achou = 1;	//Se o numero digitado for valido, o mecanismo recebe valor de "1" para, assim, encaixar na proxima condição (if)  e continuar o cadastro
							}
	
						}
						
						if(achou = 1)
						{
							printf("NOME:");
							fflush(stdin);	//Limpa memoria; corrigi problema de caracteres e strings
							gets(filial[i].nome);	// "gets" substitui " scanf("%c" &.......)
							filial[i].numero = temp_filial;		//Atribui o numero digitado anteriormente (provisorio) à variavel final (permanente)
							ocupado[i] = 1;		//A vaga de 1 dentre as 4 disponiveis fica preenchida
							system("cls");	//Limpa tela
							printf("** FILIAL CADASTRADA COM SUCESSO **\n");
							getch();	//Com isso, o programa para até o usuario der um clique qualquer
							system("cls");
							break;	//Fecha aqui para nao dar sequencia no cadastro das 4 filiais e sim, em apenas 1
						}
						
					}
					
				}
				if(achou == 0)	// Se todas as vagas para filiais estiverem preenchidas:
					{
						printf("CADASTRO DE FILIAIS LOTADO\n\n");
						getch();
					}
				break;
				
				
			
			
			
				case 2:
					
					printf("## CADASTRO DE FUNCIONARIO ##\n\n");				
					printf("NUMERO DA FILIAL:");
					scanf("%d", &temp_filial);	// Variavel temporaria para a filial em que deseja cadastrar o funcionario
					
					
					achou = 0;
					for(i=0; i<4 ; i++)
					{
						if(temp_filial == filial[i].numero)		//Verifica se o numero digitado existe em alguma filial já cadastrada
						{	
							lotado = 0;		//Mecanismo para verificar se a filial ainda tem vaga para cadastro de funcionarios										
							for(j=0; j<5; j++)	
							{
								if(func_ocupado[i][j] == 0)	// Verifica a disponibilidade de cadastrar mais um funcionario na filial
								{
									Redigite_cod_gerente:	//Funcao goto ( Linha 153 )
									printf("1 - VENDEDOR\n");	// Manuseio com numeros ( 1 e 2 ) para evitar erros e acelerar uso do "if" . #Praticidade
									printf("2 - GERENTE\n");
									temp_cargo = 0;		//Atribui-se valor 0 para evitar confusão com o valor do funcionario anterior
									scanf("%d", &temp_cargo);
							
									if(temp_cargo == 2)	//Verifica se o funcionario que voce digitou é um gerente.
									{
										achou_gerente = 0;	//Mecanismo para verificar se já existe um gerente nesta filial
										
										for(k=0 ; k<5 ; k++)	// Caso sim, verifica se já existe um gerente cadastrado.
										{
											if(temp_cargo == funcionario[i][k].cargo )	//Verificando se já existe um gerente ( Regra do exercicio: 1 gerente por filial ) 
											{
												printf("JÁ EXISTE UM GERENTE\n\n");
												achou_gerente = 1;
												goto Redigite_cod_gerente;	//Comando que retorna para a linha 137
											}
											
										}
										
										if( achou_gerente == 0)		//Se nao encontrou nenhum gerente, continua o cadastro
										{
											printf("NOME:");
											fflush(stdin);	//Limpa memoria
											gets(funcionario[i][j].nome);
											
											Redigite_codigo_gerente:	//Checkpoint para caso o usuario digite um codigo já existente ( localizado na linha 166 )
											printf("CODIGO:");
											scanf("%d", &func_codigo);																						
											for(k = 0 ; k < 4 ; k ++)		//Verifica se o codigo digitado ja está cadastrado
											{
												for(l = 0 ; l < 5 ; l ++)
												{
													if(func_codigo == funcionario[k][l].codigo)
													{
														printf("Este codigo já existe\n");														
														goto Redigite_codigo_gerente;	//Funcao que vai retornar o programa para o Checkpoint ( Linha 156 )
													}
												
												}
											}
											
											printf("SALARIO:");
											scanf("%f", &funcionario[i][j].salario);
											funcionario[i][j].codigo = func_codigo;	//Atribuindo os valores temporarios às variaveis permantes
											funcionario[i][j].cargo = temp_cargo; 	//""		""		""		""		""		""		""
											func_ocupado[i][j] = 1;	//Preenche a vaga do funcionario
											lotado = 0;

											break;
										}
									}
									
									else
									{
										printf("NOME:");
										fflush(stdin);
										gets(funcionario[i][j].nome);
										
										Redigite_codigo_funcionario:	//Ponto de checagem ( Linha 209 )
										printf("CODIGO:");
										scanf("%d", &func_codigo);
										
										
										for(l = 0 ; l < 4 ; l ++)		//Verifica se o codigo digitado ja está cadastrado
										{
											for(m = 0 ; m < 5 ; m ++)
											{
												if(func_codigo == funcionario[l][m].codigo)
												{
													printf("Este codigo já existe\n");														
													goto Redigite_codigo_funcionario;	//Funcao que vai retornar o programa para o Checkpoint ( Linha 197 )													}
											
												}
											}
										}
										printf("SALARIO:");
										scanf("%f", &funcionario[i][j].salario);
										funcionario[i][j].codigo = func_codigo;		//Passa o valor da variavel temporaria para a definitiva
										funcionario[i][j].cargo = temp_cargo;
										func_ocupado[i][j] = 1;		//Preenche a vaga do funcionario
										lotado = 0;
										break;
										
									}
									
								}
								else
								{
									lotado = 1;		// Se nao existem mais vagas
								}
							}
							if(lotado == 1 )
							{
								printf("Cadastro lotado\n");
							}
							
						
							achou = 1;
						}
											
					}
					if ( achou == 0)	//Se nao encontrou nenhuma filial com o numero digitado
					{
						printf("Este numero de filial não existe\n");
					}
				break;
				
				
				case 3:
				
					printf("====================\n");
					printf(" CONSULTA DE FILIAIS\n");
					printf("====================\n\n");	
					
					//Calculo do Salario por Filial
					for(i = 0 ; i < 4 ; i++)
					{
						for(j = 0 ; j < 5 ; j++)
						{
							filial[i].salario = filial[i].salario + funcionario[i][j].salario;
						}
					}
					
					//Calculo do Salario Geral ( Todas as Filiais )
					for(i = 0 ; i < 4 ; i++)
					{
						sal_geral = sal_geral + filial[i].salario;
					}
					
					
					//Saída dos Salarios
					for ( i = 0 ; i < 4 ; i++)
					{
						if(filial[i].numero != 0 )
						{
							printf("========================================\n");
							printf("Nome da Filial: %s\n" , filial[i].nome);
							printf("Numero da Filial: %d\n\n", filial[i].numero);
							for( k = 0 ; k < 5 ; k++)
							{
								if (funcionario[i][k].cargo == 2)
								{
									printf("Gerente: %s\n" , funcionario[i][k].nome);
									printf("Codigo: %d\n" , funcionario[i][k].codigo);
									printf("Salario: %.2f\n\n", funcionario[i][k].salario);
								}
							}
							
							for( j = 0 ; j < 5 ; j++)
							{
								if (funcionario[i][j].cargo == 1)
								{
									printf("Funcionario %d\n", j+1);
									printf("%s\n" , funcionario[i][j].nome);
									printf("%d\n" , funcionario[i][j].codigo);
									printf("Salario: %.2f\n\n", funcionario[i][j].salario);
								}
							}
							printf("Gastos com Salário: %.2f\n", filial[i].salario);
							printf("========================================\n\n");
								
					
						}
					}
					printf("Salario Geral: %.2f\n", sal_geral);
					
					
				break;
			
			}
		}
		return 0;
		
}

int PegaNumero ()
{
	int x;
	
	printf("NUMERO:");
	scanf("%d" , &x);
	return x;
}
