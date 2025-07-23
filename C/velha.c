#include <stdio.h>
#include <stdlib.h>

void limparJogo();
void tabuleiroPos();
void inserirNoTabuleiro( int pos, char jogador);
void imprimirTabuleiro();

char velha[9]; //'x' e 'o'
int sair=0;

// 1 -> inteiro
//'1' -> caractere
//"1" -> string

// restrições a serem trabalhadas:
/*
4 - tratar a questão de caso ocorra uma jogada inválida não incrementar a variável sair para nenhum
jogador ficar com uma jogada a menos; 

7 - testar a questão de digitar um caracter qualquer em vez de um número, lembrar do getchar()
e pesquisar a função atoi();
*/



int main()
{
	int pos;
	char jogador = 'x', posC;
	
	
    limparJogo();
	
	while(sair<9)
	{
		system("clear||cls");

		tabuleiroPos();
		imprimirTabuleiro();
	
		if(sair>=5)
		{
		
 		if(velha[0]=='x'&&velha[1]=='x'&&velha[2]=='x' || velha[0]=='o'&&velha[1]=='o'&&velha[2]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
		
		else if(velha[3]=='x'&&velha[4]=='x'&&velha[5]=='x' || velha[3]=='o'&&velha[4]=='o'&&velha[5]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
  		
		else if(velha[6]=='x'&&velha[7]=='x'&&velha[8]=='x' || velha[6]=='o'&&velha[7]=='o'&&velha[8]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
		
		else if(velha[0]=='x'&&velha[3]=='x'&&velha[6]=='x' || velha[0]=='o'&&velha[3]=='o'&&velha[6]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
		
		else if(velha[1]=='x'&&velha[4]=='x'&&velha[7]=='x' || velha[1]=='o'&&velha[4]=='o'&&velha[7]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
		
		else if(velha[2]=='x'&&velha[5]=='x'&&velha[8]=='x' || velha[2]=='o'&&velha[5]=='o'&&velha[8]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
		
		else if(velha[0]=='x'&&velha[4]=='x'&&velha[8]=='x' || velha[0]=='o'&&velha[4]=='o'&&velha[8]=='o' )
		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
		
		else if(velha[2]=='x'&&velha[4]=='x'&&velha[6]=='x' || velha[2]=='o'&&velha[4]=='o'&&velha[6]=='o' )
 		{
 			
 		printf("Parabens voce ganhou");
 		
 		break;
		}
	
		}
	
		system("pause");
		
		printf("Jogador %c escolha a posicao: ", jogador);
		pos =getchar(); // corrigir esta função trocando para getchar();
		//posC = getchar(); // olhar a função atoi() para converter caractere para inteiro
		
		if( sair == 8 ) 
		{
			printf("Deu velha!\n");
		}
		
		inserirNoTabuleiro(pos, jogador);
		if(pos<0)
		{
			printf("Numero ERRADO!!!");
			system("pause");
		}
		else if(pos>8)
		{
			printf("Numero ERRADO!!!");
			system("pause");
		}
		
		else if(jogador=='x')
		{
			jogador = 'o';
		}
		else
		{
			jogador = 'x';
		}
		
		sair++;
	}
	
	return 0;
}


void limparJogo()
{
	int i;
	
	for(i=0 ; i<9 ; i++)
	{
		velha[i] = ' ';
	}
}

void tabuleiroPos()
{
	printf("Posicoes no tabuleiro:\n");
	printf("00 | 01 | 02\n------------\n03 | 04 | 05\n------------\n06 | 07 | 08\n\n");
}

void inserirNoTabuleiro( int pos, char jogador)
{

	if( velha[pos] == ' ')
	{
		velha[pos] = jogador;   
		system("pause");
	}
	else if( velha[pos] == 'x' )
	{
		printf("Jogada invalida\n");
		system("pause");
		sair--;
	}
	else if( velha[pos] == 'o')
	{
		printf("Jogada invalida\n");
		system("pause");
		sair--;
	}

}

void imprimirTabuleiro()
{
	int ;
	
	printf(" %c | %c | %c\n", velha[0], velha[1], velha[2]);
	printf("------------\n");
	printf(" %c | %c | %c\n", velha[3], velha[4], velha[5]);
	printf("------------\n");
	printf(" %c | %c | %c\n", velha[6], velha[7], velha[8]);
	
}
