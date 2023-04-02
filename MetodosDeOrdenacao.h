#ifndef OPERABN_H_INCLUDED
#define OPERABN_H_INCLUDED

typedef struct Produto
{
	int cod;
	double pre;
	char desc[11];
	
}Pr;

void Swap(Pr vet[], int p1, int p2)
{
			
	Pr temp = vet[p1];
	vet[p1] = vet[p2];
	vet[p2] = temp;
	
	return;

}

void Flip(Pr vet[], int k)
{

	int esq = 0, dir = k;

	while(esq < dir)
	{
	
		Swap(vet, esq, dir);
		
		esq++;
		dir--;
	
	}
	
	return;

}

void BucketSortInt(Pr vet[], int n);
void CocktailSortInt(Pr vet[], int n);
void CocktailSortDouble(Pr vet[], int n);
void CocktailSortString(Pr vet[], int n);
void HeapSortSortInt(Pr vet[], int n);
void HeapSortDouble(Pr vet[], int n);
void HeapSortString(Pr vet[], int n);
void MergeSortSortInt(Pr vet[], int n);
void MergeSortDouble(Pr vet[], int n);
void MergeSortString(Pr vet[], int n);
void PancakeSortSortInt(Pr vet[], int n);
void PancakeSortDouble(Pr vet[], int n);
void PancakeSortString(Pr vet[], int n);
void QuickSortInt(Pr vet[], int n);
void QuickSortDouble(Pr vet[], int n);
void QuickSortString(Pr vet[], int n);
void RadixSortSortInt(Pr vet[], int n);
void RadixSortDouble(Pr vet[], int n);
void RadixSortString(Pr vet[], int n);

#endif // OPERABN_H_INCLUDED
