#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include"func.h"
using namespace std;
/*int main()
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
}*/

int main()
{
	FILE* input;
	string text1, text2;
	int num1 = 0;
	int num2 = 0;
	input = fopen("test.txt", "r");
	fscanf(input, "%s %s %d_%d", &text1, &text2, &num1, &num2);
	printf("%s %s %d %d", text1, text2, num1, num2);
	fclose(input);
}