#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

int Mediana3Double(Pr vet[], int esq, int dir)
{

	int diff = dir - esq + 1;
	
	int a = esq + (rand() % diff);
	
	while(a == esq || a == dir - 1 || a == dir) a = esq + (rand() % diff);
	
	int b = esq + (rand() % diff);
	
	while(b == esq || b == dir - 1 || b == dir || b == a) b = esq + (rand() % diff);
	
	int c = esq + (rand() % diff);
	
	while(c == esq || c == dir - 1 || c == dir || c == a || c == b)	c = esq + (rand() % diff);
	
	if(vet[a].pre > vet[b].pre)
	{
	
		Swap(vet, a, b);
	
	}
	
	if(vet[a].pre > vet[c].pre)
	{
	
		Swap(vet, a, c);
	
	}
	
	if(vet[b].pre > vet[c].pre)
	{
	
		Swap(vet, b, c);
	
	}
	
	Swap(vet, esq, a);
	Swap(vet, dir - 1, b);
	Swap(vet, dir, c);
	
	int i, j = esq + 1;
	
	double v = vet[dir - 1].pre;
	
	for(i = esq + 1;i < dir - 1;i++)
	{
	
		if(vet[i].pre <= v)	Swap(vet, j++, i);
		
	}
	
	Swap(vet, j, dir - 1);
	
	return j;

}

void QSD(Pr vet[], int esq, int dir)
{

	int diff = dir - esq + 1;
		
	if(diff <= 5)
	{
	
		int i, j;

		for(i = esq;i <= dir;i++)
		{
			
			j = i - 1;
			
			while(j != -1 && vet[j + 1].pre <= vet[j].pre)
			{
			
				Swap(vet, j, j + 1);	
				j--;
				
			}
		
		}
		
		return;
	
	}

	int idx;

	idx = Mediana3Double(vet, esq, dir);
	QSD(vet, esq, idx - 1);
	QSD(vet, idx + 1, dir);
	
	return;

}

void QuickSortDouble(Pr vet[], int n)
{

	QSD(vet, 0, n - 1);
	
	return;

}
