#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void UpdateHeapInt(Pr vet[], int n, int idx)
{

	int esq = 2 * idx + 1;
	int dir = 2 * idx + 2;

	int ma = idx;
	
	if(esq < n && vet[ma].cod < vet[esq].cod) ma = esq;
	if(dir < n && vet[ma].cod < vet[dir].cod) ma = dir;
	
	if(ma != idx)
	{
	
		Swap(vet, idx, ma);
		
		UpdateHeapInt(vet, n, ma);
	
	}

	return;

}

void HeapSortInt(Pr vet[], int n)
{

	int i;

	for(i = n / 2;i >= 0;i--) UpdateHeapInt(vet, n, i);
	
	for(i = 1;i < n;i++)
	{
	
		Swap(vet, 0, n - i);
	
		UpdateHeapInt(vet, n - i, 0);
	
	}

	return;

}
