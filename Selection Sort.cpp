#include <iostream>
#include <climits>

using namespace std;

void swap(int (&a)[10], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void selectionSort(int (&a)[10], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int smallest = INT_MAX;
		int smallestIndex = -1;

		for (int j = i; j < size; j++)
		{
			if (a[j] < smallest)
			{
				smallest = a[j];
				smallestIndex = j;
			}
		}
		
		swap(a, i, smallestIndex);
	}
}

int main()
{
	int a[10] = {5,7,8,3,2,1,0,9,4,6};
	
	selectionSort(a, 10);

	for (int k = 0; k < 10; ++k)
	{
		cout << a[k] << "\t";
	}
	
	return 0;
}
