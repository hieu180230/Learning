#include<iostream>
#include "func.h"
#include<string>
using namespace std;

bool listEmpty(List list)
{
	if (list.pHead == NULL) return true;
	else return false;
}

Node* createNode(Data input)
{
	Node* pAdd = new Node;
	pAdd->data.name = input.name;
	pAdd->data.age = input.age;
	pAdd->pNext = NULL;
	return pAdd;
}

void addHead(List& list, Data input)
{
	Node* pCurrent = list.pHead;
	if (listEmpty(list))
	{
		pCurrent = createNode(input);
		list.pHead = pCurrent;
		return;
	}
	Node* pNew = createNode(input);
	pNew->pNext = pCurrent;
	list.pHead = pNew;
	return;
}

void removeHead(List& list)
{
	if (list.pHead == NULL)
	{
		cout << "List is not initiated!" << endl;
		return;
	}
	Node* pCurrent = list.pHead->pNext;
	delete list.pHead;
	list.pHead = pCurrent;
}

void removeTail(List& list)
{
	if (list.pHead == NULL)
	{
		cout << "List is not initiated!" << endl;
		return;
	}
	Node* pCurrent = list.pHead;
	while (pCurrent->pNext->pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
	}
	list.pTail = pCurrent;
	delete list.pTail->pNext;
	list.pTail->pNext = NULL;
}
void addTail(List& list, Data input)
{
	if (list.pHead == NULL)
	{
		cout << "List is not initiated!" << endl;
		return;
	}
	Node* pCurrent = createNode(input);
	list.pTail->pNext = pCurrent;
	list.pTail = pCurrent;
}

void removeAll(List& list)
{
	if (list.pHead == NULL)
	{
		cout << "List is not initiated!" << endl;
		return;
	}
	if (list.pHead->pNext == NULL)
	{
		delete list.pHead;
		list.pHead = NULL;
		return;
	}
	Node* pPrev = list.pHead;
	Node* pCurrent = list.pHead;
	while (pPrev != NULL)
	{
		pCurrent = pCurrent->pNext;
		pPrev->pNext = NULL;
		delete pPrev;
		pPrev = pCurrent;
	}
	list.pHead = NULL;
}

void removeBefore(List& list, Data toRemove)
{
	if (listEmpty(list))
	{
		cout << "List is not initiated!" << endl;
		return ;
	}
	int n = 0;
	if (list.pHead->pNext->data.name == toRemove.name and list.pHead->pNext->data.age == toRemove.age)
	{
		Node* pTemp = list.pHead->pNext;
		delete list.pHead;
		list.pHead = pTemp;
		cout << "Deleted [" << n << "]" << endl;
	}
	n++;
	Node* pCurrent = list.pHead->pNext;
	Node* pPrev = list.pHead;
	while (pCurrent -> pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
		if (pPrev->pNext->pNext->data.name == toRemove.name and pPrev->pNext->pNext->data.age == toRemove.age)
		{
			delete pPrev->pNext;
			pPrev->pNext = pCurrent;
			cout << "Deleted [" << n << "]" << endl;
		}
		else
		{
			pPrev = pPrev->pNext;
		}
		n++;
	}
}


int listAppend(List &list, Data input)
{
	Node* pCurrent = list.pHead;
	if (pCurrent == NULL)
	{
		pCurrent = createNode(input);
		list.pHead = pCurrent;
		return 0;
	}
	while (pCurrent->pNext != NULL)
		pCurrent = pCurrent->pNext;
	pCurrent ->pNext = createNode(input);
	pCurrent = pCurrent->pNext;
	list.pTail = pCurrent;
	return 1;
}

int listLength(List list)
{
	if (listEmpty(list))
	{
		return 0;
	}
	Node* pCurrent = list.pHead;
	int n = 0;
	while (pCurrent->pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
		n++;
	}
	return n;
}

void listInsert(List& list, Data input, int pos)
{

}

int listOutput(List list)
{
	if (listEmpty(list))
	{
		cout << "List is not initiated!" << endl;
		return 0;
	}
	Node* pCurrent = list.pHead;
	while (pCurrent != NULL)
	{
		cout << "Name: " << pCurrent->data.name << " // Age: " << pCurrent->data.age << endl;
		pCurrent = pCurrent->pNext;
	}
	return 1;
}

