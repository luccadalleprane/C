
/*_____________________________________________________________________________
|                                                                              |
|        DATA DE INÍCIO: 10/05/2022                                         |
|        ÚLTIMA ATUALIZAÇÃO: 14/05/2022                                       |
|        PROFESSOR: CARLOS JONES                                               |
|        CURSO: ENGENHARIA DE CONTROLE E AUTOMAÇÃO       DISCIPLINA: AED       |
|        SEMESTRE/ANO: 1/2022                                                  |
|        ALUNOS:LUCCA NASCIMENTO                                                |   
|                                                                              |
|        PROGRAMA QUE FAZ CODIFICAÇÃO E DECODIFICAÇÃO BIN->TEXTO E TEXTO->BIN  |
|        SIMULANDO O FUNCIONAMENTO DE UM COMPUTADOR NA LEITURA E INTERPRETAÇÃO |
|        DE DADOS.                                                             |
| _____________________________________________________________________________|
*/

//--------------------------INCLUSÃO DE BIBLIOTECAS---------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // para a função toupper
#include <math.h> // biblioteca com funcoes matematicas basica
//----------------------------------------------------------------------------//


//----------------------------DECLARAÇÕES GLOBAIS-----------------------------//

//----------------------------------------------------------------------------//



//----------------------------CABEÇALHO DAS FUNÇÕES---------------------------//
// faz a leitura do arquivo "entrada.dat"
void lerArq(int opcao); 
// faz a escrita do arquivo "saida.dat"
void escreverBinArq(char bit7, char bit6, char bit5, char bit4, char bit3, char bit2, char bit1, char bit0); 
// zera o arquivo de saida
void limparArqSaida(); 
// faz as duas conversões, SE (opcao==1){texto->bin} SENAO SE(opcao == 2){bin->texto} 
void decoder2(char dado, int opcao);
// é a ajuda do programa para o usuário saber do que o mesmo trata, o que faz e como utilizar
void informar(void); 
// funcao decimal
void escreverDecArq(char x);
//----------------------------------------------------------------------------//


//--------------------------DESCRIÇÃO DAS FUNÇÕES-----------------------------//

//Função principal do programa
int main()
{
    //variáveis locais da função main
    char resp= 'N'; // variável é utilizada para o usuário tomar a decisão de sair ou não do programa; 
    int opcao; // variável utilizada para decidir conversão fazer
 
    while (resp != 'S')
    {  
        //system("cls"); // para o windows
        system("cls"); // para o linux

        printf("\n\n\n\nPrograma conversor de Niveis de Linguagem.\n\n");
        printf("1 - Texto -> Binario\n");
        printf("2 - Binario -> Texto\n");
        printf("3 - Limpar o arquivo de saida\n");
        printf("4 - Informacoes sobre o programa\n");
        printf("Opcao:");
        scanf("%d", &opcao);

        // SE a opção escolhida foi a de conversões, é feita a leitura do arquivo
        if ((opcao == 1)||(opcao == 2))
        {
            lerArq(opcao); 
			printf("O arquivo foi convertido com sucesso!!!");
			system("pause");
        }
        // zerando o arquivo de saída
        else if (opcao == 3)
        {
            limparArqSaida(); 
			printf("O arquivo de saida esta em branco!!!");
//			system("pause");     
        }
        
        // opção que funciona como um help do programa
        else if (opcao == 4)
        {
            informar();
			printf("\n");  
			system("pause");
        }

		// usado quando a opção digitada não faz parte do MENU
        else
        {
            printf("Opcao invalida! Favor escolher uma opcao do Menu.\n");   
			system("pause");
        }       	

        printf("\n\nDeseja sair do programa?(S/N)\n");
	    fflush(stdin);
        resp = toupper(getchar());
    }

    	   
    getchar();
    return 0; 
}



// faz a leitura do arquivo "entrada.dat"
// NÃO SE PREOCUPEM COM A PARTE DE ARQUIVOS (FILE), ESTA SÓ SERÁ VISTA EM LINGUAGEM DE PROGRAMAÇÃO, APENAS UTILIZAR A CHAMADA DA FUNÇÃO
// SALVO EM CASOS ESPECÍFICOS ONDE HAJA NECESSIDADE DE FAZER ALGUMA ADAPTAÇÃO PARA A OPÇÃO DE CONVERTER BIN->TEXTO (opcao 2)
void lerArq(int opcao)
{
    FILE *fp; //cria um ponteiro para o arquivo de dados 
    char nu;
    
    fp=fopen("entrada.dat","rt");// abre o arquivo para leitura
    
    if (!fp)
    {
        printf("Erro!!! Arquivo nao encontrado!");
    }
    
    else if ( opcao == 1)
    {
        while(1)
        {
            nu = fgetc(fp);//lê o conteúdo do arquivo    
            if(nu==EOF)// se o ponteiro chegou no fim do arquivo
            {
		    	break; // sai da estrutura
	    	}            
            decoder2(nu, opcao);
        }
        
    }
    else if ( opcao ==2 )
{
    // variaveis
	int bin;
    double converter=0;
    
	while( nu != EOF )
 	{				
    //estrutura de repeticao,le o arq do de forma decrescente do maior para o menor ,da direita pra esquerda
		for( bin=7 ; bin>=0 ; bin--)			
		{  
		
		nu = fgetc(fp);//lê o conteúdo do arquivo
			
			if( nu =='0' )// se a condicao for verdadeira, executa a funcao 1
			{ 
			
			}
			
			else if( nu =='1' )  // se for falsa,executa a funcao 2
	   		{   
				converter=converter+pow(2,bin);//formula binaria para decimal,elava o numero e soma no fim para achar o decimal, pow(base,exp)
		    }
			 
        }
        
        decoder2(converter,opcao);
        converter=0;
	} 
        

}
	fclose(fp);  // fecha o arquivo após o término do seu uso
}






// faz a escrita do arquivo "saida.dat", esta função funciona apenas para a conversão texto->bin (opcao 1)
void escreverBinArq(char bit7,char bit6,char bit5,char bit4,char bit3,char bit2,char bit1,char bit0)
{
    FILE *fp; //cria um ponteiro para o arquivo de dados 

    fp=fopen("saida.dat","at");// abre o arquivo para leitura
    
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }
    
    //escreve o conteúdo no arquivo em forma de 8 bits
    fputc(bit7,fp);
    fputc(bit6,fp);
    fputc(bit5,fp);
    fputc(bit4,fp);
    fputc(bit3,fp);
    fputc(bit2,fp);
    fputc(bit1,fp);
    fputc(bit0,fp); 
    
    fclose(fp);  // fecha o arquivo após o término do seu uso
}




// faz a escrita do arquivo "saida.dat", esta função funciona apenas para a conversão bin->text (opcao 2)
void escreverDecArq(char x) // char armazena um caracter numa variavel, um unico bit em opçao 2
{
    FILE *fp; //cria um ponteiro para o arquivo de dados 

    fp=fopen("saida.dat","at");// abre o arquivo para leitura
    
    if (fp == NULL) // se der erro 
    {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }
    
    //fputc escreve a variavel x em texto 
    fputc(x,fp); ////fputc escreve a variavel x em texto 
    
    
    fclose(fp);  // fecha o arquivo após o término do seu uso
}





// zera o arquivo de saida
void limparArqSaida()
{
    FILE *fp; //cria um ponteiro para o arquivo de dados 

    fp=fopen("saida.dat","wt");// abre o arquivo para escrita
    
    fclose(fp);
}
    
    


// faz as duas conversões, SE (opcao==1){texto->bin} SENAO SE(opcao == 2){bin->texto}
void decoder2(char dado, int opcao)
{
    // se a opção for 1 o número será convertido para binário
    if (opcao == 1)
    {        
        //aqui usarei condicionais para fazer a conversão de dados
        if (dado == ' ')
        {
            escreverBinArq('0','0','1','0','0','0','0','0');
        }
        else if (dado == '!')
        {
            escreverBinArq('0','0','1','0','0','0','0','1');
        }
        else if (dado == '"')
        {
            escreverBinArq('0','0','1','0','0','0','1','0');
        }
        else if (dado == '#')
        {
            escreverBinArq('0','0','1','0','0','0','1','1');
        }
        else if (dado == '$')
        {
            escreverBinArq('0','0','1','0','0','1','0','0');
        } 
        else if (dado == '%')
        {
            escreverBinArq('0','0','1','0','0','1','0','1');
        }
        else if (dado == '&')
        {
            escreverBinArq('0','0','1','0','0','1','1','0');
        } 
        else if (dado == '\'')
        {
            escreverBinArq('0','0','1','0','0','1','1','1');
        } 
        else if (dado == '(')
        {
        	escreverBinArq('0','0','1','0','1','0','0','0');
        }
        else if (dado == ')')
        {
        	escreverBinArq('0','0','1','0','1','0','0','1');
        }
         else if (dado == '*')
        {
            escreverBinArq('0','0','1','0','1','0','1','0');
        }
		 else if (dado == '+')
        {
            escreverBinArq('0','0','1','0','1','1','0','0');
        } 
        else if (dado == ',')
        {
            escreverBinArq('0','0','1','0','1','1','0','0');
        } 
        else if (dado == '-')
        {
            escreverBinArq('0','0','1','0','1','1','0','1');
        } 
        else if (dado == '.')
        {
            escreverBinArq('0','0','1','0','1','1','1','0');
        } 
        else if (dado == '\\')
        {
            escreverBinArq('0','0','1','0','1','1','1','1');
        } 
        else if (dado == ':')
        {
            escreverBinArq('0','0','1','1','1','0','1','0');
        } 
        else if (dado == ';')
        {
            escreverBinArq('0','0','1','1','1','0','1','1');
        } 
        else if (dado == '<')
        {
            escreverBinArq('0','0','1','1','1','1','0','0');
        } 
        else if (dado == '=')
        {
            escreverBinArq('0','0','1','1','1','1','0','1');
        } 
        else if (dado == '>')
        {
            escreverBinArq('0','0','1','1','1','1','1','1');
        } 
        else if (dado == '?')
        {
            escreverBinArq('0','0','1','1','1','1','1','1');
        } 
        else if (dado == ',')
        {
            escreverBinArq('0','0','1','0','1','1','0','0');
        }
        else if (dado == '@')
        {
            escreverBinArq('0','1','0','0','0','0','0','0');
        }
        else if (dado == 'A')
        {
        	escreverBinArq('0','1','0','0','0','0','0','1');
        }
        else if (dado == 'B')
        {
        	escreverBinArq('0','1','0','0','0','0','1','0');
        }
        else if (dado == 'C')
        {
        	escreverBinArq('0','1','0','0','0','0','1','1');
        }
        else if (dado == 'D')
        {
        	escreverBinArq('0','1','0','0','0','1','0','0');
        }
        else if (dado == 'E')
        {
        	escreverBinArq('0','1','0','0','0','1','0','1');
        }
        else if (dado == 'F')
        {
        	escreverBinArq('0','1','0','0','0','1','1','0');
        }
        else if (dado == 'G')
        {
        	escreverBinArq('0','1','0','0','0','1','1','1');
        }
        else if (dado == 'H')
        {
        	escreverBinArq('0','1','0','0','1','0','0','0');
        }
        else if (dado == 'I')
        {
        	escreverBinArq('0','1','0','0','1','0','0','1');
        }
        else if (dado == 'J')
        {
        	escreverBinArq('0','1','0','0','1','0','1','0');
        }
        else if (dado == 'K')
        {
        	escreverBinArq('0','1','0','0','1','0','1','1');
        }
        else if (dado == 'L')
        {
        	escreverBinArq('0','1','0','0','1','1','0','0');
        }
        else if (dado == 'M')
        {
        	escreverBinArq('0','1','0','0','1','1','0','1');
        }
        else if (dado == 'N')
        {
        	escreverBinArq('0','1','0','0','1','1','1','0');
        }
        else if (dado == 'O')
        {
        	escreverBinArq('0','1','0','0','1','1','1','1');
        }
        else if (dado == 'P')
        {
        	escreverBinArq('0','1','0','1','0','0','0','0');
        }
        else if (dado == 'Q')
        {
        	escreverBinArq('0','1','0','1','0','0','0','1');
        }
        else if (dado == 'R')
        {
        	escreverBinArq('0','1','0','1','0','0','1','0');
        }
        else if (dado == 'S')
        {
        	escreverBinArq('0','1','0','1','0','0','1','1');
        }
        else if (dado == 'T')
        {
        	escreverBinArq('0','1','0','1','0','1','0','0');
        }
        else if (dado == 'U')
        {
        	escreverBinArq('0','1','0','1','0','1','0','1');
        }
        else if (dado == 'V')
        {
        	escreverBinArq('0','1','0','1','0','1','1','0');
        }
        else if (dado == 'W')
        {
        	escreverBinArq('0','1','0','1','0','1','1','1');
        }
        else if (dado == 'X')
        {
        	escreverBinArq('0','1','0','1','1','0','0','0');
        }
        else if (dado == 'Y')
        {
        	escreverBinArq('0','1','0','1','1','0','0','1');
        }
        else if (dado == 'Z')
        {
        	escreverBinArq('0','1','0','1','1','0','1','0');
        }
        else if (dado == 'a')
        {
        	escreverBinArq('0','1','1','0','0','0','0','1');
        }
        else if (dado == 'b')
        {
        	escreverBinArq('0','1','1','0','0','0','1','0');
        }
        else if (dado == 'c')
        {
        	escreverBinArq('0','1','1','0','0','0','1','1');
        }
        else if (dado == 'd')
        {
        	escreverBinArq('0','1','1','0','0','1','0','0');
        }
        else if (dado == 'e')
        {
        	escreverBinArq('0','1','1','0','0','1','0','1');
        }
        else if (dado == 'f')
        {
        	escreverBinArq('0','1','1','0','0','1','1','0');
        }
        else if (dado == 'g')
        {
        	escreverBinArq('0','1','1','0','0','1','1','1');
        }
        else if (dado == 'h')
        {
        	escreverBinArq('0','1','1','0','1','0','0','0');
        }
        else if (dado == 'i')
        {
        	escreverBinArq('0','1','1','0','1','0','0','1');
        }
        else if (dado == 'j')
        {
        	escreverBinArq('0','1','1','0','1','0','1','0');
        }
        else if (dado == 'k')
        {
        	escreverBinArq('0','1','1','0','1','0','1','1');
        }
        else if (dado == 'l')
        {
        	escreverBinArq('0','1','1','0','1','1','0','0');
        }
        else if (dado == 'm')
        {
        	escreverBinArq('0','1','1','0','1','1','0','1');
        }
        else if (dado == 'n')
        {
        	escreverBinArq('0','1','1','0','1','1','1','0');
        }
        else if (dado == 'o')
        {
        	escreverBinArq('0','1','1','0','1','1','1','1');
        }
        else if (dado == 'p')
        {
        	escreverBinArq('0','1','1','1','0','0','0','0');
        }
        else if (dado == 'q')
        {
        	escreverBinArq('0','1','1','1','0','0','0','1');
        }
        else if (dado == 'r')
        {
        	escreverBinArq('0','1','1','1','0','0','1','0');
        }
        else if (dado == 's')
        {
        	escreverBinArq('0','1','1','1','0','0','1','1');
        }
        else if (dado == 't')
        {
        	escreverBinArq('0','1','1','1','0','1','0','0');
        }
		else if (dado == 'u')
        {
        	escreverBinArq('0','1','1','1','0','1','0','1');
        }
        else if (dado == 'v')
        {
        	escreverBinArq('0','1','1','1','0','1','1','0');
        }
        else if (dado == 'w')
        {
        	escreverBinArq('0','1','1','1','0','1','1','1');
        }
		else if (dado == 'x')
        {
        	escreverBinArq('0','1','1','1','1','0','0','0');
        }
        else if (dado == 'y')
        {
        	escreverBinArq('0','1','1','1','1','0','0','1');
        }
        else if (dado == 'z')
        {
        	escreverBinArq('0','1','1','1','1','0','1','0');
        }
        else if (dado == '0')
        {
        	escreverBinArq('0','0','1','1','0','0','0','0');
        }
        else if (dado == '1')
        {
        	escreverBinArq('0','0','1','1','0','0','0','1');
        }
        else if (dado == '2')
        {
        	escreverBinArq('0','0','1','1','0','0','1','0');
        }
        else if (dado == '3')
        {
        	escreverBinArq('0','0','1','1','0','0','1','1');
        }
        else if (dado == '4')
        {
        	escreverBinArq('0','0','1','1','0','1','0','0');
        }
        else if (dado == '5')
        {
        	escreverBinArq('0','0','1','1','0','1','0','1');
        }
        else if (dado == '6')
        {
        	escreverBinArq('0','0','1','1','0','1','1','0');
        }
        else if (dado == '7')
        {
        	escreverBinArq('0','0','1','1','0','1','1','1');
        }
        else if (dado == '8')
        {
        	escreverBinArq('0','0','1','1','1','0','0','0');
        }
        else if (dado == '9')
        {
        	escreverBinArq('0','0','1','1','1','0','0','1');
        }
        else if (dado == '[')
        {
        	escreverBinArq('0','1','0','1','1','0','1','1');
        }
        else if (dado == ']')
        {
        	escreverBinArq('0','1','0','1','1','1','0','1');
        }
        else if (dado == '/')
        {
        	escreverBinArq('0','1','0','1','1','1','0','0');
        }
        else if (dado == '^')
        {
        	escreverBinArq('0','1','0','1','1','1','0','0');
        }
        else if (dado == '_')
        {
        	escreverBinArq('0','1','0','1','1','1','1','1');
        }
        else if (dado == '}')
        {
        	escreverBinArq('0','1','1','1','1','1','0','1');
        }
        else if (dado == '{')
        {
        	escreverBinArq('0','1','1','1','1','0','1','1');
        } 
		else if (dado == '~')
        {
        	escreverBinArq('0','1','1','1','1','1','1','0');
        }
        
   }
   
   // caso contrário será convertido em texto, AQUI será a conversão de bin->texto (opcao == 2)
    
   // else // quando a opção for igual a 2
    			
   else if (opcao == 2)
	{	
        if (dado == 65)
        {
        	escreverDecArq('A');
        }
        else if (dado == 66)
        {
        	escreverDecArq('B');
        }
        else if (dado == 67)
        {
        	escreverDecArq('C');
        }
        else if (dado == 68)
        {
        	escreverDecArq('D');
        }
        else if (dado == 69)
        {
        	escreverDecArq('E');
        }
        else if (dado == 70)
        {
        	escreverDecArq('F');
        }
        else if (dado == 71)
        {
        	escreverDecArq('G');
        }
        else if (dado == 72)
        {
        	escreverDecArq('H');
        }
        else if (dado == 73)
        {
        	escreverDecArq('I');
        }
        else if (dado == 74)
        {
        	escreverDecArq('J');
        }
        else if (dado == 75)
        {
        	escreverDecArq('K');
        }
        else if (dado == 76)
        {
        	escreverDecArq('L');
        }
        else if (dado == 77)
        {
        	escreverDecArq('M');
        }
        else if (dado == 78)
        {
        	escreverDecArq('N');
        }
        else if (dado == 79)
        {
        	escreverDecArq('O');
        }
        else if (dado == 80)
        {
        	escreverDecArq('P');
        }
        else if (dado == 81)
        {
        	escreverDecArq('Q');
        }
        else if (dado == 82)
        {
        	escreverDecArq('R');
        }
        else if (dado == 83)
        {
        	escreverDecArq('S');
        }
        else if (dado == 84)
        {
        	escreverDecArq('T');
        }
        else if (dado == 85)
        {
        	escreverDecArq('U');
        }
        else if (dado == 86)
        {
        	escreverDecArq('V');
        }
        else if (dado == 87)
        {
        	escreverDecArq('W');
        }
        else if (dado == 88)
        {
        	escreverDecArq('X');
        }
        else if (dado == 89)
        {
        	escreverDecArq('Y');
        }
		else if (dado == 90)
        {
        	escreverDecArq('Z');
        }
        else if (dado == 97)
        {
        	escreverDecArq('a');
        }
        else if (dado == 98)
        {
        	escreverDecArq('b');
        }
        else if (dado == 99)
        {
        	escreverDecArq('c');
        }
        else if (dado == 100)
        {
        	escreverDecArq('d');
        }
        else if (dado == 101)
        {
        	escreverDecArq('e');
        }
        else if (dado == 102)
        {
        	escreverDecArq('f');
        }
        else if (dado == 103)
        {
        	escreverDecArq('g');
        }
        else if (dado == 104)
        {
        	escreverDecArq('h');
        }
        else if (dado == 105)
        {
        	escreverDecArq('i');
        }
        else if (dado == 106)
        {
        	escreverDecArq('j');
        }
        else if (dado == 107)
        {
        	escreverDecArq('k');
        }
        else if (dado == 108)
        {
        	escreverDecArq('l');
        }
        else if (dado == 109)
        {
        	escreverDecArq('m');
        }
        else if (dado == 110)
        {
        	escreverDecArq('n');
        }
        else if (dado == 111)
        {
        	escreverDecArq('o');
        }
        else if (dado == 112)
        {
        	escreverDecArq('p');
        }
        else if (dado == 113)
        {
        	escreverDecArq('q');
        }
        else if (dado == 114)
        {
        	escreverDecArq('r');
        }
        else if (dado == 115)
        {
        	escreverDecArq('s');
        }
        else if (dado == 116)
        {
        	escreverDecArq('t');
        }
        else if (dado == 117)
        {
        	escreverDecArq('u');
        }
        else if (dado == 118)
        {
        	escreverDecArq('v');
        }
        else if (dado == 119)
        {
        	escreverDecArq('w');
        }
        else if (dado == 120)
        {
        	escreverDecArq('x');
        }
		else if (dado == 121)
        {
        	escreverDecArq('y');
        }
        else if (dado == 122)
        {
        	escreverDecArq('z');
        }
        else if (dado == 48)
        {
        	escreverDecArq('0');
        }
        else if (dado == 49)
        {
        	escreverDecArq('1');
        }
        else if (dado == 50)
        {
        	escreverDecArq('2');
        }
        else if (dado == 51)
        {
        	escreverDecArq('3');
        }
        else if (dado == 51)
        {
        	escreverDecArq('4');
        }
        else if (dado == 52)
        {
        	escreverDecArq('5');
        }
        else if (dado == 54)
        {
        	escreverDecArq('6');
        }
        else if (dado == 55)
        {
        	escreverDecArq('7');
        }
        else if (dado == 56)
        {
        	escreverDecArq('8');
        }
        else if (dado == 57)
        {
        	escreverDecArq('9');
        }
        else if (dado == 32)
        {
        	escreverDecArq(' ');
        }
        else if (dado == 44)
        {
        	escreverDecArq(',');
        }
        else if (dado == 33)
        {
        	escreverDecArq('!');
        }
        else if (dado == 34)
        {
        	escreverDecArq('"');
        }
        else if (dado == 35)
        {
        	escreverDecArq('#');
        }
        else if (dado == 36)
        {
        	escreverDecArq('$');
        }
        else if (dado == 37)
        {
        	escreverDecArq('%');
        }
        else if (dado == 38)
        {
        	escreverDecArq('$');
        }
		else if (dado == 39)
        {
        	escreverDecArq('\'');
        }
        else if (dado == 40)
        {
        	escreverDecArq('(');
        }
        else if (dado == 41)
        {
        	escreverDecArq(')');
        }
        else if (dado == 42)
        {
        	escreverDecArq(')');
        }
        else if (dado == 42)
        {
        	escreverDecArq('*');
        }
        else if (dado == 43)
        {
        	escreverDecArq('+');
        }
        else if (dado == 44)
        {
        	escreverDecArq(',');
        }
        else if (dado == 45)
        {
        	escreverDecArq('-');
        }
        else if (dado == 46)
        {
        	escreverDecArq('.');
        }
        else if (dado == 47)
        {
        	escreverDecArq('/');
        }
        else if (dado == 58)
        {
        	escreverDecArq(':');
        }
        else if (dado == 59)
        {
        	escreverDecArq(';');
        }
        else if (dado == 60)
        {
        	escreverDecArq('<');
        }
        else if (dado == 61)
        {
        	escreverDecArq('=');
        }
        else if (dado == 62)
        {
        	escreverDecArq('>');
        }
        else if (dado == 63)
        {
        	escreverDecArq('?');
        }
        else if (dado == 64)
        {
        	escreverDecArq('@');
        }
        else if (dado == 91)
        {
        	escreverDecArq('[');
        }
        else if (dado == 92)
        {
        	escreverDecArq('/');
        }
        else if (dado == 93)
        {
        	escreverDecArq(']');
        }
        else if (dado == 94)
        {
        	escreverDecArq('^');
        }
        else if (dado == 95)
        {
        	escreverDecArq('_');
        }
        else if (dado == 123)
        {
        	escreverDecArq('{');
        }
        else if (dado == 124)
        {
        	escreverDecArq('}');
        }
        else if (dado == 126)
        {
        	escreverDecArq('~');
        }
        
        
    } 
}
    
	

	

// é a ajuda do programa para o usuário saber do que o mesmo trata, o que faz e como utilizar
void informar(void)
{


    printf("Programa que faz a conversao de binario->texto e de texto->binario");   
}


//--------------------------------FIM DO PROGRAMA-----------------------------//
