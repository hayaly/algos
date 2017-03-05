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
	for (int i = 0; i < size-1; ++i)
	{
		int smallest = INT_MAX;
		int smallestIndex = -1;
		int j = i + 1;
		
		for (; j < size; ++j)
		{
			if (a[j] < smallest)
			{
				smallest = a[j];
				smallestIndex = j;
			}
		}
		
		if (a[i] > a[smallestIndex])
		{
			swap(a, i, smallestIndex);
		}
		
		for (int k = 0; k < 10; ++k)
		{
			cout << a[k] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int a[10] = {5,7,8,3,2,1,0,9,4,6};
	
	selectionSort(a, 10);
	
	return 0;
}
