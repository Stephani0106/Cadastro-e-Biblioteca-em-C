#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include "header.h"
#define BUFFER 64

int main() 
{	
	int opcao;
	
	printf("----- Biblioteca Municipal -----\n");
	printf("[1] Faca seu cadastro ou login para utilizar nossos servicos!\n");
	printf("[2] Para acessar o menu da biblioteca\n");
	printf("[3] Sair\n");
	printf("\nDigite a opcao desejada: ");
	scanf("%d", &opcao);
	system("cls");
	
	switch (opcao)
	{
		case 1 :
			menuCadastro();
			break;
			
		case 2 :
			menuBiblio();
			break;
			
		case 3 : 
			exit(0);
			break;	
			
		default :
			system("cls");
			printf("Entrada invalida!");
			system("PAUSE");
			return(0);		
	}
	return 0;
}
