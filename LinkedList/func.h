#pragma once
#include<iostream>
using namespace std;
struct Data {
	string name;
	int age;
};
struct Node {
	Data data;
	Node* pNext=NULL;
};

struct List {
	Node* pHead=NULL;
	Node* pTail=NULL;
};

int listAppend(List &list, Data input);
int listOutput(List list);
void addHead(List& list, Data input);
void removeHead(List& list);
void addTail(List& list, Data input);
void removeTail(List& list);
void removeAll(List& list);
void removeBefore(List& list, Data toRemove);
