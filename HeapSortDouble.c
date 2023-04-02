#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void UpdateHeapDouble(Pr vet[], int n, int idx)
{

	int esq = 2 * idx + 1;
	int dir = 2 * idx + 2;

	int ma = idx;
	
	if(esq < n && vet[ma].pre < vet[esq].pre) ma = esq;
	if(dir < n && vet[ma].pre < vet[dir].pre) ma = dir;
	
	if(ma != idx)
	{
	
		Swap(vet, idx, ma);
		
		UpdateHeapDouble(vet, n, ma);
	
	}

	return;

}

void HeapSortDouble(Pr vet[], int n)
{

	int i;

	for(i = n / 2;i >= 0;i--) UpdateHeapDouble(vet, n, i);
	
	for(i = 1;i < n;i++)
	{
	
		Swap(vet, 0, n - i);
	
		UpdateHeapDouble(vet, n - i, 0);
	
	}

	return;

}
