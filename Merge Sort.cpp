#include <iostream>

using namespace std;

void merge(int (&a)[10], int low, int high);

void mergeSort(int (&a)[10], int size)
{
	int low = 0;
	int high = size-1;

	int aux[10] = {};

	merge(a, low, high);
}

void merge(int (&a)[10], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	
	int mid = low + (high - low)/2;

	merge(a, low, mid);
	merge(a, mid+1, high);

	int aux[10] = {0};
	for (int i = low; i <= high; i++)
	{
		aux[i] = a[i];
	}
	
	int i = low, j = mid+1;
	
	for (int k = low; k <= high; ++k)
	{
		if 		(i > mid)		  a[k] = aux[j++];
		else if (j > high)		  a[k] = aux[i++];
		else if (aux[i] < aux[j]) a[k] = aux[i++];
		else					  a[k] = aux[j++];
	}
}

int main()
{
	int a[10] = {5,7,8,3,2,1,0,9,4,6};
	
	mergeSort(a, 10);

	for (int k = 0; k < 10; ++k)
	{
		cout << a[k] << "\t";
	}
	
	return 0;
}
