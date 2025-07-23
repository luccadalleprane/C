/*
*/
//--------------------------INCLUSÃO DE BIBLIOTECAS---------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
//#include <time.h> // para usar o time na função gerarAleatório
//#include <stdio_ext.h> //para  __fpurge(stdin); no linux
//----------------------------------------------------------------------------//


//----------------------------DECLARAÇÕES GLOBAIS-----------------------------//
#define TAM_TEXT 250 // tamanho dos textos a serem escritos, não inclui o caractere especial
FILE *fArq; //declaração do ponteiro do tipo arquivo para manipulação de streams
int k = 0;
int t;
char str2[TAM_TEXT+1];
char str1[1]="\n";
char str3[TAM_TEXT+1];
char str4[TAM_TEXT+1];
typedef struct dicionario
{ 
  char palavras[TAM_TEXT+1];
  char significados[TAM_TEXT+1];
	
}DICIONARIO;
DICIONARIO vet[1000];
//----------------------------------------------------------------------------//



//----------------------------CABEÇALHO DAS FUNÇÕES---------------------------//
void visualizar(void);
void inserir(void);
void imprimir();// faz a impressao das palavras de 5 em 5
void zerar();
void ordenar(struct dicionario *dc, int N);//Insertion sort;
int buscar(struct dicionario *dc_2, int N_2, char* elem);
void apagar();
void corrigir();
int geraAleatorio(int tam);
// visualizar e ordenar tem q ser usados nessa ordem.
//----------------------------------------------------------------------------//


int main()
{ 
	srand(time(NULL)); //inicializa a semente aleatória
	int ok=1;
    char opcao;

	zerar(); // zera o vetor que será impresso

 	while(ok)
	{   
		system("clear||cls");
//		printf("Estudo de arquivos:\n");
		printf("1. Visualizar\n");
	    printf("2. Buscar\n"); 
		printf("3. Inserir\n"); 
		printf("4. Retirar\n"); 
		printf("5. Corrigir\n");  
     	printf("6. Ordenar\n");
		printf("7. Estudar\n"); 
		printf("8. Sair do Programa\n");
		printf("Opcao :\n");
		//__fpurge(stdin); //no linux
		fflush(stdin); //no win
		opcao=getchar();
		system("clear||cls");

		switch (opcao)
		{
			case '1':
			{
				visualizar();
				//__fpurge(stdin); //no linux
		        fflush(stdin); //no win
				//getchar();
				getchar();
				break;	
			} 
			case '2':
			{
				ordenar(vet,k);
		        printf("Dig a palavra q vc quer saber o significado:\n");
		        scanf("%s", &str2);
		        fflush(stdin);
		        strcat(str2,str1);
		        if(buscar(vet,k,str2)!=-1)
		        {
		        	system("clear||cls");	
		        	printf("Significado:%s\n", vet[buscar(vet,k,str2)].significados);
				}
				k=0;
				system("pause");
				break;
			}	
			case '3':
			{
				inserir();
				break;
			}
			case '4':
			{
				printf("Dig a palavra q vc quer retirar:\n");
		        scanf("%s", &str2);
		        fflush(stdin);
		        strcat(str2,str1);
		        
                apagar();
                system("pause");
				break;	
			}
			case '5':
			{
				printf("Dig a palavra q vc quer corrigir:\n");
				scanf("%s", &str2);
		        fflush(stdin);
		        strcat(str2,str1);
				
            	corrigir();
            	system("pause");
				break;	
			}
			case '6':
			{
				ordenar(vet, k);
				k = 0;
				break;
			}
			case '7':
			{
				t = geraAleatorio(k);
				printf("Palavra: %s\n", vet[t].palavras);
				printf("Dig ENTER para ver o seu significado\n");
				scanf("%s",str4);
				if(strcmp(str4,"ENTER")==0)
				{
					printf("Significado:%s\n", vet[t].significados);
				}
				system("pause");
				k = 0;
				break;
			}	
			case '8':
			{
				system("clear||cls");	
				exit(1);
				break;	
			}
			default :
			{
				break;	
			}
			
		}
	
	}
	
	fclose(fArq); // sempre fechar o arquivo após finalizar o programa
	return 0;
}


// insere palavras/frases no dicionário
void inserir(void)
{   
    static int i = 0;
    //implementar uma struct no lugar da variavel palavra
	//char palavra[TAM_TEXT+1]; // considerar o '\0'
	

	fArq=fopen("arquivo.txt","rb"); // abre o arquivo somente para leitura
	
	// erro caso não encontre o arquivo de bd do dicionário
	if(fArq == NULL)
	{
			printf("Erro, nao foi possivel abrir o arquivo.\n");
	}
	else
	{    
	    
	    
		printf("Digite a palavra:\n");
		//fflush(stdin); // usado no win para limpar o buffer do teclado
		//__fpurge(stdin); // usado no linux para limpar o buffer do teclado
		fflush(stdin); //no win
		//fgets(palavra, TAM_TEXT, stdin); //stdin é o teclado
		fgets(vet[i].palavras, TAM_TEXT, stdin);
		fflush(stdin);
		printf("Dig o significado:\n");
		fgets(vet[i].significados, TAM_TEXT, stdin);
		fflush(stdin);
		fArq=fopen("arquivo.txt","ab"); // abre o arquivo em modo de adição para acrescentar mais palavras
		fprintf(fArq,"%s",vet[i].palavras); // salva a palavra no arquivo e quebra a linha
		fprintf(fArq,"%s",vet[i].significados);// salva o significado no arquivo e quebra a linha
	    i++;
	    
		
	}
	fclose(fArq); // fecha o arquivo
	
}



/*
void visualizar(void)
{
	system("clear||cls");
	int a,k;
	for(a=0;a<1000;a++)
	{
		k=a+1;
		printf("%d:",k);
		printf("%s\n",vet[a].palavra);
		
	}
	system("pause");
}
*/

void visualizar(void)
{
    int i=0;
    //implementar uma struct no lugar da variavel palavra
	//char palavra[TAM_TEXT+1]; // considerar o '\0'

    	fArq=fopen("arquivo.txt","rb");
    
	if (fArq == NULL)
	{
		printf("Erro na leitura do Arquivo!!! Entre em contato com o suporte tecnico!\n");
	}	
	else
	{
		while((fgets(vet[i].palavras, TAM_TEXT+1, fArq)!=NULL)&&(fgets(vet[i].significados, TAM_TEXT+1, fArq)!=NULL)) //copia palavra para um vetor
		i++;

	

		imprimir();
	
	}
        fclose(fArq);
}


void imprimir()
{
	int i;
    int j = 0;
    char x;
	for(i=0;i<1000;i++)
	{
		if((strcmp(vet[i].palavras, " ")!=0)&&(strcmp(vet[i].significados, " ")!=0))
		{
			if(j<6)
			{
			  printf("Posicao: %d\n", i+1);
			  printf("Palavra:%s", vet[i].palavras);
			  printf("Significado:%s\n", vet[i].significados);
			  k++;
			  j++;
		    } 
		    if(j==5)
		    {
		    	printf("Pressione qualquer tecla para continuar exibindo as palvaras e os significados\n");
		    	fflush(stdin);
		    	x = getchar();
		    	j = 0;
		   }
			
		}
		else 
		{		
			printf("Fim do arquivo!\n");
			break;
		}
			
	}
	 
}




void zerar()
{
	int i;
	
	for(i=0;i<1000;i++)
	{
		strcpy(vet[i].palavras," ");
		strcpy(vet[i].significados," ");
	}
}

void ordenar(struct dicionario *dc, int N)
{
	int i, j;
    struct dicionario aux;
	for(i=1;i<N;i++)
	{
		aux=dc[i];
		
	   for(j=i;(j>0)&&(strcmp(aux.palavras,dc[j-1].palavras)<0);j--)
	   {  
			dc[j]=dc[j-1];
			dc[j-1]=aux;
	   }
	}
	//for(i=0;i<N;i++)
	//{
	//	printf("Posicao %d:\n", i+1);			
	//	printf("%s",vet[i].palavras);
	//	printf("%s\n",vet[i].significados);
	//}
	
	fArq=fopen("arquivo.txt","wb");
	for(i=0;i<N;i++)
	{
		fprintf(fArq,"%s",vet[i].palavras); // salva a palavra no arquivo e quebra a linha
		fprintf(fArq,"%s",vet[i].significados);// salva o significado no arquivo e quebra a linha
	}
	fclose(fArq);
}
int buscar(struct dicionario *dc_2, int N_2, char* elem)
{
	int i;
	for(i=0;i<N_2;i++)
	{
		if((strcmp(elem,dc_2[i].palavras))==0)
		{
			
			return i;
		}
		
	}
	return -1;
}
void apagar()
{
	int g;
	int w;
	 if(buscar(vet,k,str2)!=-1)
   {
   	 w = buscar(vet,k,str2);
	 strcpy(vet[w].palavras, " ");
	 strcpy(vet[w].significados, " ");
	 printf("palavra deletada\n");
   }
   else
   {
   	printf("palavra n econtrada\n");
   }
   fArq=fopen("arquivo.txt", "wb");
   for(g=0;g<k;g++)
	 { 
		
		fprintf(fArq,"%s",vet[g].palavras); // salva a palavra no arquivo e quebra a linha
		fprintf(fArq,"%s",vet[g].significados);// salva o significado no arquivo e quebra a linha
		
	 }
	fclose(fArq);
	k = 0;
	
}
void corrigir()
{
	int pos;
	int s;
	int opc;
	if(buscar(vet,k,str2)!=-1)
	{
		pos = buscar(vet,k,str2);
		printf("palavra encontrada\n\n");
		printf("deseja corrigir:\n\n");
		printf("1)Palavra\n");
		printf("2)Significado\n");
		scanf("%d", &opc);
		fflush(stdin);
		if(opc==1)
		{
			system("cls");
			printf("Dig a nova palavra\n");
			scanf("%s", &str3);
			fflush(stdin);
			strcpy(vet[pos].palavras, str3);
			printf("Palavra corrigida\n");
			
		}
		else if(opc==2)
		{
			system("cls");
			printf("Dig o novo significado\n");
			scanf("%s", &str3);
			fflush(stdin);
			strcpy(vet[pos].significados, str3);
			printf("Significado corrigido\n");
		}	
	}
	fArq=fopen("arquivo.txt", "wb");
    for(s=0;s<k;s++)
	 { 
		fprintf(fArq,"%s",vet[s].palavras); // salva a palavra no arquivo e quebra a linha
		fprintf(fArq,"%s",vet[s].significados);// salva o significado no arquivo e quebra a linha	
	 }
	fclose(fArq);
	k = 0;
}
 


// gera um numero aleatório para a geração de índices do vetor
int geraAleatorio(int tam)
{
    return  (rand()%(tam));  
}


