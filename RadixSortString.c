#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void RadixSortString(Pr vet[], int n)
{

	int p = 0, x, y, i, j, k;
	
	int freq[300];
	Pr *bucket[300];
	
	for(i = 0;i < n;i++) 
	{
	
		if(p < strlen(vet[i].desc))
		{
		
			p = strlen(vet[i].desc);
		
		}
	
	}
	
	while(p != -1)
	{
	
		for(i = 0;i < 300;i++)
		{
		
			freq[i] = 0;
			bucket[i] = (Pr *)(malloc(0 * (sizeof(Pr))));
		
		}
		
		for(i = 0;i < n;i++)
		{
			
			if(strlen(vet[i].desc) <= p)	y = 0;
			else							y = (int)(vet[i].desc[p]) + 1;
		
			freq[y]++;
		
			bucket[y] = (Pr *)(realloc(bucket[y], (int)(freq[y] * (sizeof(Pr)))));
			
			bucket[y][ freq[y] - 1 ] = vet[i];
			
		}
		
		k = 0;
		
		for(i = 0;i < 300;i++)
		{
		
			for(j = 0;j < freq[i];j++)
			{
			
				vet[k++] = bucket[i][j];
			
			}
		
		}
	
		for(i = 0;i < 300;i++) free(bucket[i]);
		
		p--;
	
	}
	
	return;

}
