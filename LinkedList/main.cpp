#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include"func.h"
using namespace std;
int main()
{
	/*int n = 0;
	cin >> n;
	List list;
	Data data;
	while (n > 0)
	{
		cout << "Name: "; cin >> data.name;
		cout << "Age: "; cin >> data.age;
		listAppend(list, data);
		n = n - 1;
	}
	listOutput(list);
	cin >> n;
	List sublist;
	while (n > 0)
	{
		cout << "Name: "; cin >> data.name;
		cout << "Age: "; cin >> data.age;
		listAppend(sublist, data);
		n = n - 1;
	}
	listOutput(sublist);
	cout << endl << countOccurrence(list, sublist);*/
	cout << wordPalindromes("On the, world the on");

}
