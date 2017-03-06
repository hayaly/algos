#include <iostream>

using namespace std;

void swap(int (&a)[10], int i, int j);

void qSort(int (&a)[10], int low, int high)
{
//	cout << endl << "qSort(" << low << ", " << high << ")";
	
	if (high <= low) return;
	
	int partitionElement = a[low];
	int i = low+1, j = high;
	
	while (i < j)
	{
		while (i < high && a[i] < partitionElement) i++;
		while (j > (low + 1) && a[j] > partitionElement) j--;

		if (i < j)
		{
			swap(a, i, j);
		}
	}
	
	if (a[low] > a[j])
	{
		swap(a, low, j);
	}
	
	/*
	cout << endl;
	cout << "partitionElement = " << partitionElement;
	cout << endl;
	for (int k = 0; k < 10; ++k)
	{
		cout << a[k] << "\t";
	}
	cout << endl;
	*/
	
	qSort(a, low, j-1);
	qSort(a, j+1, high);
}

void swap(int (&a)[10], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quickSort(int (&a)[10], int size)
{
	int low = 0;
	int high = size-1;
	qSort(a, low, high);
}

int main()
{
	int a[10] = {7,7,8,5,2,1,4,3,4,6};
	
	quickSort(a, 10);

	cout << endl;
	for (int k = 0; k < 10; ++k)
	{
		cout << a[k] << "\t";
	}
	
	return 0;
}


//{5,7,8,3,2,1,0,9,4,6};
//{5,4,0,3,2,1,8,9,7,6};

