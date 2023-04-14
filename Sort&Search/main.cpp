#include "funcs.h"

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cocktailSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}