#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void PancakeSortString(Pr vet[], int n)
{

	int ma, i, j;
	
	for(i = n - 1;i > 0;i--)
	{
	
		ma = 0;
		
		for(j = 1;j <= i;j++)
		{
		
			if(strcmp(vet[ma].desc, vet[j].desc) <= 0) ma = j;
		
		}
		
		if(ma == i) continue;
		
		Flip(vet, ma);
		Flip(vet, i);
		
	}
	
	return;

}
