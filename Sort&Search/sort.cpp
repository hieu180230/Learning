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
void quicksort(int* a, int n)
{
	
}