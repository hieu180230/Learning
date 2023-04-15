#include <iostream>
using namespace std;

void swap(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}
void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] >= a[j]) swap(a[i], a[j]);
		}
	}
}
void cocktailSort(int* a, int n)
{
	bool exitFlag = true;
	int start = 0, end = n - 1;
	while (exitFlag)
	{
		exitFlag = false;
		for (int i = start; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				exitFlag = true;
			}
		}
		if (!exitFlag) break;
		for (int i = end; i > start; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				exitFlag = true;
			}
		}
		start++;
		end--;
	}
}
void selectionSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minindex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i]) minindex = j;
		}
		swap(a[i], a[minindex]);
	}
}
void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			j--;
		}
	}
}
int partition(int* a, int low, int high)
{
	int pivot = a[low]; // the pivot at the begin
	int i = low, j = high;
	while (i < j)//i--> <--j
	{
		do
		{
			i++;
		} while (a[i] <= pivot);
		do
		{
			j--;
		} while (a[j] > pivot);
		//move i, j then compare
		if (i < j)
		{
			swap(a[i], a[j]);
		}//move greater to the left and smaller to the right of the pivot
	}
	swap(a[low], a[j]);//move pivot to the right position
	return j;//return the position of the pivot
}
void quickSort(int* a, int low, int high)
{
	if (low < high)
	{
		int j = partition(a, low, high);//get the right position of the first element and move greater to the left and smaller to the right of the pivot
		quickSort(a, low, j);//sort the array at the left of the pivot
		quickSort(a, j + 1,high);//sort the array at the right of the pivot
	}
}
void merge(int* a, int low, int mid, int high)
{
	int n = mid - low + 1, m = high - mid;
	int i = 0, j = 0, k = 0;
	int* b = new int[n];
	int* c = new int[m];
	for (int x = 0; x < n; x++)
	{
		b[x] = a[low + x];
	}
	for (int x = 0; x < m; x++)
	{
		c[x] = a[mid + 1 + x];
	}
	while (i < n && j < m)
	{
		if (b[i] < c[j])
		{
			a[k++] = b[i++];
		}
		else
		{
			a[k++] = c[j++];
		}
	}
	for (; i < n; i++)
	{
		a[k++] = b[i];
	}
	for (; j < m; j++)
	{
		a[k++] = c[j];
	}
}
void mergeSort(int* a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}