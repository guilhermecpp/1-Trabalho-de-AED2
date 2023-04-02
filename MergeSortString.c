#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void MSS(Pr vet[], int esq, int dir, Pr aux[])
{

	if(esq == dir) return;
	
	int mid = (esq + dir) / 2;
	
	MSS(vet, esq, mid, aux);
	MSS(vet, mid + 1, dir, aux);
	
	int a = esq, b = mid + 1, i = esq;
	
	while(a <= mid && b <= dir)
	{
	
		if(strcmp(vet[a].desc, vet[b].desc) <= 0) 	aux[i++] = vet[a++];
		else 										aux[i++] = vet[b++];
	
	}
	
	while(a <= mid) aux[i++] = vet[a++];
	while(b <= dir) aux[i++] = vet[b++];

	for(i = esq;i <= dir;i++) vet[i] = aux[i];

	return;

}

void MergeSortString(Pr vet[], int n)
{

	Pr aux[n];

	MSS(vet, 0, n - 1, aux);

	return;

}
