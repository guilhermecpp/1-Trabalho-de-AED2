#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "BucketSortInt.c"
#include "CocktailSortInt.c"
#include "HeapSortInt.c"
#include "MergeSortInt.c"
#include "PancakeSortInt.c"
#include "QuickSortInt.c"
#include "RadixSortInt.c"
#include "CocktailSortDouble.c"
#include "HeapSortDouble.c"
#include "MergeSortDouble.c"
#include "PancakeSortDouble.c"
#include "QuickSortDouble.c"
#include "RadixSortDouble.c"
#include "CocktailSortString.c"
#include "HeapSortString.c"
#include "MergeSortString.c"
#include "PancakeSortString.c"
#include "QuickSortString.c"
#include "RadixSortString.c"
#include "MetodosDeOrdenacao.h"

#define EPS 0.001

void MenuInt(Pr vet[], int n, int op)
{

	if(op == 1) BucketSortInt(vet, n);
	if(op == 2) CocktailSortInt(vet, n);
	if(op == 3) HeapSortInt(vet, n);
	if(op == 4) MergeSortInt(vet, n);
	if(op == 5) PancakeSortInt(vet, n);
	if(op == 6) QuickSortInt(vet, n);
	if(op == 7) RadixSortInt(vet, n);
	
	return;

}

void MenuDouble(Pr vet[], int n, int op)
{

	if(op == 2) CocktailSortDouble(vet, n);
	if(op == 3) HeapSortDouble(vet, n);
	if(op == 4) MergeSortDouble(vet, n);
	if(op == 5) PancakeSortDouble(vet, n);
	if(op == 6) QuickSortDouble(vet, n);
	if(op == 7) RadixSortDouble(vet, n);
	
	return;

}

void MenuString(Pr vet[], int n, int op)
{

	if(op == 2) CocktailSortString(vet, n);
	if(op == 3) HeapSortString(vet, n);
	if(op == 4) MergeSortString(vet, n);
	if(op == 5) PancakeSortString(vet, n);
	if(op == 6) QuickSortString(vet, n);
	if(op == 7) RadixSortString(vet, n);
	
	return;

}

void Menu(Pr vet[], int n, int tipo, int op)
{

	if(tipo == 1) MenuInt(vet, n, op);
	if(tipo == 2) MenuDouble(vet, n, op);
	if(tipo == 3) MenuString(vet, n, op);

	return;

}

int RandInt()
{

	return (rand() % 1000000) - (1000000 / 2);

}

double RandDouble()
{

	return ((rand() % 100000000) / 100.0) - (1000000 / 2);

}

void RandString(char dest[])
{

	int tam = (rand() % 6) + 5;
	
	char visibles[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopgrstuvwxyz0123456789";
	
	for(int i = 0;i < tam;i++)
	{
	
		dest[i] = visibles[rand() % 62];
	
	}
	
	dest[tam] = '\0';
	
	return;

}

Pr RandProduto()
{
	
	Pr novo;
	
	novo.cod = RandInt();
	novo.pre = RandDouble();
	RandString(novo.desc);

	return novo;

}

int main()
{

	int tam, a, b, i, j;
	
	int faixas[] = {10000, 26250, 42500, 58750, 75000};
	
	Pr ori[75000], cop[75000];
	
	time_t ini, fim;
	
	srand(time(NULL));
	
	double tempo[4][5][8];
	
	for(int tipo = 1;tipo <= 3;tipo++)
	{
		
		for(int idxtam = 0;idxtam < 5;idxtam++)
		{
		
			for(int op = 1;op <= 7;op++)
			{
			
				tempo[tipo][idxtam][op] = 0.0;
			
			}
		
		}
		
	}
	
	for(int exe = 0;exe < 10;exe++)
	{
		
		for(int tipo = 1;tipo <= 3;tipo++)
		{
		
			for(int idxtam = 0;idxtam < 5;idxtam++)
			{
			
				tam = faixas[idxtam];
				
				for(i = 0;i < tam;i++) ori[i] = RandProduto();
				
				for(int op = 1;op <= 7;op++)
				{
				
					printf("%d %d %d %d\n", exe + 1, tipo, idxtam, op);
				
					for(i = 0;i < tam;i++) cop[i] = ori[i];
				
					ini = clock();
					Menu(cop, tam, tipo, op);
					fim = clock();
					
					tempo[tipo][idxtam][op] += (double)(fim - ini) / CLOCKS_PER_SEC;
				
				}
			
			}
			
		}
		
	}
		
	for(int tipo = 1;tipo <= 3;tipo++)
	{
	
		printf("\"Tamanho\",");
		printf("\"BucketSort\",");
		printf("\"CocktailSort\",");
		printf("\"HeapSort\",");
		printf("\"MergeSort\",");
		printf("\"PancakeSort\",");
		printf("\"QuickSort\",");
		printf("\"RadixSort\"\n");
	
		for(int idxtam = 0;idxtam < 5;idxtam++)
		{
		
			tam = faixas[idxtam];
			
			printf("%d", tam);
			
			for(int op = 1;op <= 7;op++)
			{
				
				printf(",%.6lf", tempo[tipo][idxtam][op] / 10);
				fflush(stdout);
			
			}
			
			printf("\n");
		
		}
			
		printf("\n");
		
	}

	return 0;
	
}
