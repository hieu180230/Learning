#include <iostream>
using namespace std;

int binarySearch(int* a, int low, int high, int x)
{
	int mid = low + (high - low) / 2;
	if (a[mid] == x) return mid;
	if (x < a[mid]) return binarySearch(a, low, mid, x);
	else return binarySearch(a, mid, high, x);
}