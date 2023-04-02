#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

#define TAM 100

void BucketSortInt(Pr vet[], int n)
{

	int me = vet[0].cod, ma = vet[0].cod, p, i, j, k;

	for(i = 1;i < n;i++)
	{
	
		if(me > vet[i].cod) me = vet[i].cod;
		if(ma < vet[i].cod) ma = vet[i].cod;
	
	}
	
	int num = ((ma - me) / TAM) + 1;
	
	int freq[num];
	Pr *bucket[num];
	
	for(i = 0;i < num;i++) 
	{
	
		freq[i] = 0;
		bucket[i] = (Pr *)(malloc(0 * (sizeof(Pr))));
		
	}
	
	for(i = 0;i < n;i++) 
	{
	
		p = (vet[i].cod - me) / TAM;
		
		freq[p]++;
		
		bucket[p] = (Pr *)(realloc(bucket[p], (int)(freq[p] * (sizeof(Pr)))));
		
		bucket[p][ freq[p] - 1 ] = vet[i];
		
	}
	
	k = 0;
	
	for(i = 0;i < num;i++)
	{
	
		QuickSortInt(bucket[i], freq[i]);
	
		for(j = 0;j < freq[i];j++)
		{
			
			vet[k++] = bucket[i][j];
		
		}
	
	}
	
	for(i = 0;i < num;i++) free(bucket[i]);

	return;

}
