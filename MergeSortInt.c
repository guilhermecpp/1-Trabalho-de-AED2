#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void MSI(Pr vet[], int esq, int dir, Pr aux[])
{

	if(esq == dir) return;
	
	int mid = (esq + dir) / 2;
	
	MSI(vet, esq, mid, aux);
	MSI(vet, mid + 1, dir, aux);
	
	int a = esq, b = mid + 1, i = esq;
	
	while(a <= mid && b <= dir)
	{
	
		if(vet[a].cod <= vet[b].cod) 	aux[i++] = vet[a++];
		else 							aux[i++] = vet[b++];
	
	}
	
	while(a <= mid) aux[i++] = vet[a++];
	while(b <= dir) aux[i++] = vet[b++];

	for(i = esq;i <= dir;i++) vet[i] = aux[i];
	
	return;

}

void MergeSortInt(Pr vet[], int n)
{

	Pr aux[n];

	MSI(vet, 0, n - 1, aux);

	return;

}
