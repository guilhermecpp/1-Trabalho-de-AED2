#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void CocktailSortInt(Pr vet[], int n)
{

	int esq = 0, dir = n - 1, i;

	bool changed;

	while(esq < dir)
	{
	
		changed = false;
		
		for(i = esq;i < dir;i++)
		{
		
			if(vet[i + 1].cod < vet[i].cod)
			{
			
				Swap(vet, i, i + 1);
			
				changed = true;
			
			}
		
		}
		
		if(changed == false) break;
		
		dir--;
		
		if(esq >= dir) break;
	
		changed = false;
		
		for(i = dir;i > esq;i--)
		{
		
			if(vet[i].cod < vet[i - 1].cod)
			{
			
				Swap(vet, i - 1, i);
			
				changed = true;
			
			}
		
		}
		
		if(changed == false) break;
		
		esq++;
	
	}
	
	return;

}
