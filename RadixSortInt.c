#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include "MetodosDeOrdenacao.h"

void RadixSortInt(Pr vet[], int n)
{

	int pot10 = 1, x, y, i, j, k;
	
	int freq[11];
	Pr *bucket[11];
	
	while(true)
	{
	
		for(i = 0;i < 11;i++)
		{
		
			freq[i] = 0;
			bucket[i] = (Pr *)(malloc(0 * (sizeof(Pr))));
		
		}
		
		for(i = 0;i < n;i++)
		{
		
			x = abs(vet[i].cod) / pot10;
			
			if(x == 0)	y = 0;
			else		y = (x % 10) + 1;
		
			freq[y]++;
		
			bucket[y] = (Pr *)(realloc(bucket[y], (int)(freq[y] * (sizeof(Pr)))));
			
			bucket[y][ freq[y] - 1 ] = vet[i];
			
		}
		
		if(freq[0] == n) break;
		
		k = 0;
		
		for(i = 0;i < 11;i++)
		{
		
			for(j = 0;j < freq[i];j++)
			{
			
				vet[k++] = bucket[i][j];
			
			}
		
		}
	
		for(i = 0;i < 11;i++) free(bucket[i]);
		
		pot10 *= 10;
	
	}
	
	for(i = 0;i < 2;i++)
	{
	
		freq[i] = 0;
		bucket[i] = (Pr *)(malloc(0 * (sizeof(Pr))));
	
	}
	
	for(i = 0;i < n;i++)
	{
		
		if(vet[i].cod < 0)	y = 0;
		else				y = 1;
	
		freq[y]++;
	
		bucket[y] = (Pr *)(realloc(bucket[y], (int)(freq[y] * (sizeof(Pr)))));
		
		bucket[y][ freq[y] - 1 ] = vet[i];
		
	}
	
	k = 0;
	
	for(j = freq[0] - 1;j >= 0;j--) vet[k++] = bucket[0][j];
	for(j = 0;j < freq[1];j++) 		vet[k++] = bucket[1][j];
	
	for(i = 0;i < 2;i++) free(bucket[i]);
	
	return;

}
