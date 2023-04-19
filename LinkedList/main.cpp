#include<iostream>
#include"func.h"
using namespace std;
int main()
{
	int n = 4;
	List list;
	Data data, toDelete;
	toDelete.name = "huhu";
	toDelete.age = 3;
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
	listInsert(list, toDelete, 3);
	listOutput(list);
	cout << endl << listLength(list);
}