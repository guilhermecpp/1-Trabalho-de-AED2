#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

int Mediana3String(Pr vet[], int esq, int dir)
{

	int diff = dir - esq + 1;
	
	int a = esq + (rand() % diff);
	
	while(a == esq || a == dir - 1 || a == dir) a = esq + (rand() % diff);
	
	int b = esq + (rand() % diff);
	
	while(b == esq || b == dir - 1 || b == dir || b == a) b = esq + (rand() % diff);
	
	int c = esq + (rand() % diff);
	
	while(c == esq || c == dir - 1 || c == dir || c == a || c == b)	c = esq + (rand() % diff);

	if(strcmp(vet[a].desc, vet[b].desc) > 0)
	{
	
		Swap(vet, a, b);
	
	}
	
	if(strcmp(vet[a].desc, vet[c].desc) > 0)
	{
	
		Swap(vet, a, c);
	
	}
	
	if(strcmp(vet[b].desc, vet[c].desc) > 0)
	{
	
		Swap(vet, b, c);
	
	}
	
	Swap(vet, esq, a);
	Swap(vet, dir - 1, b);
	Swap(vet, dir, c);
	
	int i, j = esq + 1;
	
	char *v = vet[dir - 1].desc;
	
	for(i = esq + 1;i < dir - 1;i++)
	{
	
		if(strcmp(vet[i].desc, v) <= 0) Swap(vet, j++, i);
		
	}
	
	Swap(vet, j, dir - 1);
	
	return j;

}

void QSS(Pr vet[], int esq, int dir)
{

	int diff = dir - esq + 1;
		
	if(diff <= 5)
	{
	
		int i, j;
	
		for(i = esq;i <= dir;i++)
		{
		
			j = i - 1;
			
			while(j != -1 && strcmp(vet[j + 1].desc, vet[j].desc) < 0)
			{
			
				Swap(vet, j, j + 1);	
				j--;
				
			}
		
		}
		
		return;
	
	}

	int idx;

	idx = Mediana3String(vet, esq, dir);
	QSS(vet, esq, idx - 1);
	QSS(vet, idx + 1, dir);
	
	return;

}

void QuickSortString(Pr vet[], int n)
{

	QSS(vet, 0, n - 1);
	
	return;

}
