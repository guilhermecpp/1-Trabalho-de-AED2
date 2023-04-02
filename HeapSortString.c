#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void UpdateHeapString(Pr vet[], int n, int idx)
{

	int esq = 2 * idx + 1;
	int dir = 2 * idx + 2;

	int ma = idx;
	
	if(esq < n && strcmp(vet[ma].desc, vet[esq].desc) < 0) ma = esq;
	if(dir < n && strcmp(vet[ma].desc, vet[dir].desc) < 0) ma = dir;
	
	if(ma != idx)
	{
	
		Swap(vet, idx, ma);
		
		UpdateHeapString(vet, n, ma);
	
	}

	return;

}

void HeapSortString(Pr vet[], int n)
{

	int i;

	for(i = n / 2;i >= 0;i--) UpdateHeapString(vet, n, i);
	
	for(i = 1;i < n;i++)
	{
	
		Swap(vet, 0, n - i);
	
		UpdateHeapString(vet, n - i, 0);
	
	}

	return;

}
