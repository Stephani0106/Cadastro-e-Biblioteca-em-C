#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>  
#include "header.h"
#define BUFFER 64

//************* FUNÇÕES PARA O CADASTRO DE USUÁRIOS *************
typedef struct listaUsuarios 
{
        char *nome;			//Nome do usuário
        int cadastro;		//Número de cadastro
        struct listaUsuarios *proximo;
} ListaCAD;

ListaCAD *principal = NULL;

//Cria uma lista vazia apontando para NULL
ListaCAD *iniciarDados(char *nome, int cadastro)
{
	ListaCAD *novaLista;
	
	novaLista = (ListaCAD *)malloc(sizeof(ListaCAD));
	novaLista->nome = (char *)malloc(strlen(nome)+1);
	strncpy(novaLista->nome, nome, strlen(nome)+1);
	novaLista->cadastro = cadastro;
	novaLista->proximo = NULL;
	
	return novaLista;
}

//Insere dados na lista e atualiza os ponteiros
ListaCAD *inserirDados(ListaCAD *dados, char *nome, int cadastro)
{
	ListaCAD *novaLista;

	novaLista = (ListaCAD *)malloc(sizeof(ListaCAD));	
	novaLista->nome = (char *)malloc(strlen(nome)+1); 
	strncpy(novaLista->nome, nome, strlen(nome)+1);
	novaLista->cadastro = cadastro;
	novaLista->proximo = dados;
	
	return novaLista;
}

//Imprime a lista de usuários cadastrados
void exibirDados(ListaCAD *dados)
{
	fprintf(stdout, "Banco de cadastros:\n\n");
	fprintf(stdout, "------------------------\n");
	
	for(; dados != NULL; dados = dados->proximo)
	{
		fprintf(stdout, "Nome: %s\n", dados->nome);
		fprintf(stdout, "Numero de cadastro: %d\n", dados->cadastro);
		fprintf(stdout, "------------------------\n");
	}
	printf("Pressione qualquer tecla para continuar...");
	getch();
}

//Procura um usuário entre os cadastros
void buscarDados(ListaCAD *dados, char *chave)
{
	int encontrado = 0;
	
	fprintf(stdout, "Cadastro: \n\n");
	for(; dados != NULL; dados = dados->proximo)
	{
		if(strcmp(chave, dados->nome)==0)
		{
			fprintf(stdout, "------------------------\n");
			fprintf(stdout, "Nome: %s\n", dados->nome);
			fprintf(stdout, "Número de cadastro: %d\n", dados->cadastro);
			fprintf(stdout, "------------------------\n");
			encontrado++;
		}
	}
	
	if(encontrado == 0)
	{
		fprintf(stdout, "Nenhum resultado foi encontrado.\n");
		printf("Pressione qualquer tecla para continuar...\n");
	}
	else
	{
		fprintf(stdout, "Foram encontrados %d cadastros.\n", encontrado);
		printf("Pressione qualquer tecla para continuar...\n");
	}
	sleep(1); //Realiza uma pausa de 1 segundo
	getch();
}

//Exclui o último cadastro inserido
ListaCAD *excluirDados(ListaCAD *dados)
{
	ListaCAD *novaLista;
	novaLista = dados->proximo;
	
	free(dados->nome);
	free(dados);
	
	fprintf(stdout, "O cadastro foi removido com exito.\n");
	sleep(1);
	
	return novaLista;
}

//Verifica se a lista de cadastros está vazia
int vazio(ListaCAD *dados)
{
	if(dados == NULL)
	{
		fprintf(stdout, "A lista esta vazia.\n");
		sleep(1);
		return 1;
	}
	else
	{
		return 0;
	}
}

//Chama a função para inserir um usuário
void inserirUser(void)
{
	char *nome;
	int cadastro; 			
	
	nome = (char *)malloc(BUFFER);
	
	fprintf(stdout, "\n\nDigite o nome: ");
	scanf("%s", nome);
	fprintf(stdout, "\n");
		
	fprintf(stdout, "Digite um numero de cadastro: ");		
	scanf("%d", &cadastro);
	fprintf(stdout, "\n");

	 if(principal == NULL)
	 {
	 	principal = iniciarDados(nome, cadastro);
	 }
	 else
	 {
	 	principal = inserirDados(principal, nome, cadastro);
	 }
}

//Chama a função para imprimir os dados na tela
void exibirUser(void)
{
	if(!vazio(principal))
	{
		exibirDados(principal);
	}
}

//Chama a função de busca de usuários
void buscarUser(void)
{
	char *chave;
	
	if(!vazio(principal))
	{
		chave = (char *)malloc(BUFFER);
		fprintf(stdout, "Digite o nome de um usuario para pesquisar nos cadastros: ");
		scanf("%s", chave);
		
		buscarDados(principal, chave);
		getch();
	}
}

//Chama a função para excluir um usuário
void deletarUser(void)
{
	if(!vazio(principal))
	{
		principal = excluirDados(principal);
	}
}

void menuCadastro()
{
	int opcaoCadastro;
	
	do
	{
		system("cls");
		printf("----- Cadastro e Consulta de usuarios -----\n");
		printf("[1] Para cadastrar um novo usuario\n");
		printf("[2] Para exibir a lista de usuarios\n");
		printf("[3] Para realizar uma consulta de usuario\n");
		printf("[4] Para excluir o cadastro de um usuario\n");
		printf("[5] Voltar ao menu inicial\n");
		printf("\n Digite a opcao desejada: ");
		scanf("%d*c", &opcaoCadastro);
		system ("cls");
		
		switch (opcaoCadastro)
		{
			case 1 :
				inserirUser();
				break;
				
			case 2 :
				exibirUser(); 
				break;
				
			case 3 :
				buscarUser();
				break;
				
			case 4 :
				deletarUser(); 
				break;
				
			case 5 :
				system("PAUSE");
				break;
				
			default : 
				system("cls");
				printf("Entrada invalida!");
				system("PAUSE");
		}
	}
	while (opcaoCadastro > 0);
}


/************* FUNÇÕES PARA A BIBLIOTECA *************/

typedef struct livros
{
	char *nome;				//Nome do livro
	char *autor;			//Autor
	char *editora;			//Editora
	int ano;				//Ano de publicação
	int cod_livro;			//Código do livro
	struct livros *proximo2;
} Acervo;

Acervo *principal2 = NULL;

//Cria uma lista vazia apontando para NULL
Acervo *iniciarAcervo(char *nome, char *autor, char *editora, int ano, int cod_livro)
{
	Acervo *novoAcervo;
	
	novoAcervo = (Acervo *)malloc(sizeof(Acervo)); 
	
	novoAcervo->nome = (char *)malloc(strlen(nome)+1); 			//Nome
	strncpy(novoAcervo->nome, nome, strlen(nome)+1);
	
	novoAcervo->autor = (char *)malloc(strlen(autor)+1); 		//Autor
	strncpy(novoAcervo->autor, autor, strlen(autor)+1);
	
	novoAcervo->editora = (char *)malloc(strlen(editora)+1); 	//Editora
	strncpy(novoAcervo->editora, editora, strlen(editora)+1);
	
	novoAcervo->ano = ano;							   			//Ano	
	novoAcervo->cod_livro = cod_livro;							//Cod_Livro
	novoAcervo->proximo2 = NULL;
	
	return novoAcervo;
}

//Insere livros no acervo e atualiza os ponteiros
Acervo *inserirAcervo(Acervo *livros, char *nome, char *autor, char *editora, int ano, int cod_livro)
{
	Acervo *novoAcervo;

	novoAcervo = (Acervo *)malloc(sizeof(Acervo));
		
	novoAcervo->nome = (char *)malloc(strlen(nome)+1); 			//Nome
	strncpy(novoAcervo->nome, nome, strlen(nome)+1);
	
	novoAcervo->autor = (char *)malloc(strlen(autor)+1); 		//Autor
	strncpy(novoAcervo->autor, autor, strlen(autor)+1);
	
	novoAcervo->editora = (char *)malloc(strlen(editora)+1); 	//Editora
	strncpy(novoAcervo->editora, editora, strlen(editora)+1);
	
	novoAcervo->ano = ano;						 				//Ano
	novoAcervo->cod_livro = cod_livro;							//Cod_livro
	novoAcervo->proximo2 = livros;
	
	return novoAcervo;
}

//Imprime a lista de livros no acervo
void exibirAcervo(Acervo *livros)
{
	fprintf(stdout, "Acervo da Biblioteca:\n\n");
	fprintf(stdout, "------------------------\n");
		
	for(;livros != NULL; livros = livros->proximo2)
	{
		fprintf(stdout, "Nome do Livro: %s\n", livros->nome);
		fprintf(stdout, "Autor: %s\n", livros->autor);
		fprintf(stdout, "Editora: %s\n", livros->editora);
		fprintf(stdout, "Ano de Publicacao: %i\n", livros->ano);
		fprintf(stdout, "Codigo do material: %i\n", livros->cod_livro);
		fprintf(stdout, "------------------------\n");
	}
	printf("Pressione qualquer tecla para continuar...");
	getch();	
}

//Procura um livro no acervo
void buscarAcervo(Acervo *livros, char *chave)
{
	int encontrado = 0;
	
	fprintf(stdout, "Acervo: \n\n");
	for(; livros != NULL; livros = livros->proximo2)
	{
		if(strcmp(chave, livros->nome)==0)
		{
			fprintf(stdout, "------------------------\n");
			fprintf(stdout, "Nome do livro: %s\n", livros->nome);
			fprintf(stdout, "Autor: %s\n", livros->autor);
			fprintf(stdout, "Editora: %s\n", livros->editora);
			fprintf(stdout, "Ano: %d\n", livros->ano);
			fprintf(stdout, "Código do material: %d\n", livros->cod_livro);

			fprintf(stdout, "------------------------\n");
			encontrado++;
		}
	}
	
	if(encontrado == 0)
	{
		fprintf(stdout, "Nenhum resultado foi encontrado.\n");
		printf("Pressione qualquer tecla para continuar...\n");
	}
	else
	{
		fprintf(stdout, "Foram encontrados %d cadastros.\n", encontrado);
		printf("Pressione qualquer tecla para continuar...\n");
	}
	sleep(1); //Realiza uma pausa de 1 segundo
	getch();	
}

//Exclui o último livro inserido (Se comporta como Pilha)
Acervo *excluirLivro(Acervo *livros)
{
	Acervo *novoAcervo;
	novoAcervo = livros->proximo2;
	
	free(livros->nome);
	/*free(livros->autor);
	free(livros->editora);
	free(livros->ano);
	free(livros->cod_livro);*/
	free(livros);
	
	fprintf(stdout, "O material foi removido com exito.\n");
	sleep(1);
	
	return novoAcervo;
}

//Verifica se o acervo está vazio
int acervoVazio(Acervo *livros)
{
	if(livros == NULL)
	{
		fprintf(stdout, "O acervo esta vazio.\n");
		sleep(1);
		return 1;
	}
	else
	{
		return 0;
	}	
}

//Chama a função para inserir um livro
void inserirNoAcervo(void)
{
	char *nome;
	char *autor;
	char *editora;
	int ano;
	int cod_livro; 			
	
	nome = (char *)malloc(BUFFER);
	
	fprintf(stdout, "\n\nDigite o nome: ");
	scanf("%s", nome);
	fprintf(stdout, "\n");
	
	fprintf(stdout, "\n\nDigite o nome do(a) autor(a): ");
	scanf("%s", autor);
	fprintf(stdout, "\n");

	fprintf(stdout, "\n\nInforme a editora: ");
	scanf("%s", editora);
	fprintf(stdout, "\n");
		
	fprintf(stdout, "Digite o ano de publicacao: ");		
	scanf("%d", &ano);
	fprintf(stdout, "\n");
	
	fprintf(stdout, "\n\nInforme um codigo para o material (Numerico): ");
	scanf("%d", &cod_livro);
	fprintf(stdout, "\n");

	 if(principal2 == NULL)
	 {
	 	principal2 = iniciarAcervo(nome, autor, editora, ano, cod_livro);
	 }
	 else
	 {
	 	principal2 = inserirAcervo(principal2, nome, autor, editora, ano, cod_livro);
	 }	
}

//Chama a função para exibir o acervo na tela
void exibirLivros(void)
{
	if(!acervoVazio(principal2))
	{
		exibirAcervo(principal2);
	}
}

//Chama a função de busca de livros
void buscarLivro(void)
{
	char *chave;
	
	if(!acervoVazio(principal2))
	{
		chave = (char *)malloc(BUFFER);
		fprintf(stdout, "Digite o nome de um livro para pesquisar no acervo: ");
		scanf("%s", chave);
		
		buscarAcervo(principal2, chave);
		getch();
	}	
}

//Chama a função para excluir um livro
void deletarLivro(void)
{
	if(!acervoVazio(principal2))
	{
		principal2 = excluirLivro(principal2);
	}
}

void menuBiblio()
{
	int opcaoBiblio;
	
	do
	{
		system ("cls");
		printf("----- Menu da Biblioteca -----\n");
		printf("[1] Para cadastrar um novo livro\n");
		printf("[2] Para exibir o acervo\n");
		printf("[3] Para realizar uma consulta no acervo\n");
		printf("[4] Para excluir um livro do acervo\n");
		printf("[5] Voltar ao menu inicial\n");
		printf("\n Digite a opcao desejada: ");
		scanf("%d*c", &opcaoBiblio);
		system ("cls");
		
		switch (opcaoBiblio)
		{
			case 1 :
				inserirNoAcervo();
				break;
				
			case 2 :
				exibirLivros();
				break;
				
			case 3 : 
				buscarLivro();
				break;
				
			case 4 :
				deletarLivro();
				break;
				
			case 5 : 
				//Como voltar ao menu principal?
				break;	
				
			default : 
				system("cls");
				printf("Entrada invalida!");
				system("PAUSE");				
		}
	}
	while(opcaoBiblio > 0);
}
