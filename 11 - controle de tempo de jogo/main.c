#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// PROTOTIPOS DAS FUNÇOES UTILIZADAS NO PROGRAMA
void obter_dados(); // funçao responsavel por obter os dados
void processar_dados(char hr_inicio[2], char mim_inicio[2],char hr_termino [2], char mim_termino [2]);// funçao que realiza o calculo e mostra o resultado


// PROGRAMA PRINCIPAL
void main ()
{
	obter_dados();
}

void obter_dados()
{
	// DECLARAÇAO DE VARIAVEIS
	
	char hr_inicio [2]; // armazena as hora inicial do jogo que vai de 01 a 24 contendo duas casas decimais
	char mim_inicio [2]; // armazena o minuto inicial do jogo que vai de 00 a 60 contendo duas casas decimais
	char hr_termino [2]; // "                                     "                                       "
	char mim_termino [2];// "                                     "                                       "

	// OBTEM DADOS 
	printf("DIGITTE A HORA E MINUTO DE INICIO DO JOGO FORMATO hh:mm\n");
	fgets (hr_inicio, 3, stdin); // lê uma string com um tamanho pre estipulado 
	getchar(); //espera um enter
	fgets(mim_inicio,3,stdin);// lê uma string com um tamanho pre estipulado 
	getchar(); // epera um enter

	printf("DIGITE A HORA E MINUTO DO TERMINO DO JOGO NO FORMATO hh:mm\n");
	fgets (hr_termino,3,stdin); // lê uma string com um tamanho pre estipulado 
	getchar(); // espera um enter
	fgets(mim_termino,3,stdin);// lê uma string com um tamanho pre estipulado 
	
	// chamada da funçao com passagem de parametro 
	processar_dados(hr_inicio,mim_inicio,hr_termino,mim_termino);
	
}


void processar_dados(char hr_inicio[2], char mim_inicio[2],char hr_termino [2], char mim_termino [2])
{
	char hr_mim_inicial [6]; // guarda a informaçao da hr e mim inicial 
	char hr_mim_termino [6];// guarda a informaçao da hr e mim do termino	
	
		
	// caso a hora de termino ou inicial seja igual a 00 atribuir 24 
	if (strcmp (hr_inicio, "00") == 0) {strcpy(hr_inicio, "24");}  //  se hora inicio for igual a 00 copia 24  para hr_inicio
	if (strcmp (hr_termino, "00") == 0) {strcpy(hr_termino, "24");} // "                       "                           "
	
	
	// PROCESSAR DADOS
	strcpy(hr_mim_inicial, hr_inicio); // copia o segundo parametro e cola no primeiro parametro
	strcpy(hr_mim_termino, hr_termino); // copia o segundo parametro e cola no primeiro parametro
	strcat(hr_mim_inicial, mim_inicio); // concatena o segundo parametro ao primeiro
	strcat(hr_mim_termino, mim_termino); // concatena o segundo parametro ao primeiro
	
	
	// HORA INICIAL IGUAL A HORA FINAL 24 h DE JOGO
	if(strcmp(hr_mim_inicial, hr_mim_termino) == 0) // strcmp compara string o primeiro parametro com o segundo e retorna zero caso seja igual	
	{
		int aux = 0;
		system("cls");
		printf("DURACAO DO JOGO\n");
		printf("HORAS E MINUTOS.: 24:00\n");
		aux = 24*60;
		printf("MINUTOS.: %d \n",aux);
		aux = aux * 60;
		printf("SEGUNDOS.: %d \n", aux);		
	}
	
	else
	{	
	// declaraçao de variaveis
		int hr = 0;
		int mim = 0;
		
		hr =  atoi(hr_termino) - atoi(hr_inicio)  ; // atoi converte uma string em inteiro
		// hora inicial maior que a hora de termino
	    if(strcmp(hr_mim_inicial, hr_mim_termino) > 0)	// strcomp retorna 1 caso o parametro 1 seja maior que o parametro 2
		{
			hr = hr + 24;
		}
		// situaçao caso o mim do inicio seja maior do que minuto de termino
		if(strcmp(mim_inicio, mim_termino) > 0)
		{
			mim = atoi(mim_inicio) - atoi(mim_termino); // atoi converte uma string em inteiro
			mim = 60 - mim;
			hr = hr - 1;
		}	
		if(strcmp(mim_inicio, mim_termino) < 0) {mim = atoi(mim_termino) - atoi(mim_inicio);}
		if(strcmp(mim_inicio, mim_termino) ==  0) {mim = 0;}
		
		// MOSTRAR O RESULTADO
		system("cls");
		printf("DURACAO DO JOGO\n");
		printf("HORAS E MINUTOS.: %2.2d:%2.2d\n",hr,mim);
		mim = (hr * 60) + mim;
		printf("MINUTOS.: %d \n",mim);
		mim = mim * 60;
		printf("SEGUNDOS.: %d \n", mim);
	}
}


