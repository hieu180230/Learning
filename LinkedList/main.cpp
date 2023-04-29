#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include"func.h"
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	List list;
	Data data;
	listOutput(list);
	while (n > 0)
	{
		cout << "Name: "; cin >> data.name;
		cout << "Age: "; cin >> data.age;
		listAppend(list, data);
		n = n - 1;
	}
	listOutput(list);
	cout << endl << listLength(list) << endl;
	listOutput(list);
	cout << endl << listLength(list) << endl << Count(list);
}
