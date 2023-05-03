#pragma once
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
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
//for exercises
int Count(List list);
int countOccurrence(List list, List sublist);
bool checkIncrease(List list, Node* pCur);
//functions
bool listEmpty(List list);
int listAppend(List &list, Data input);
int listOutput(List list);
void addHead(List& list, Data input);
void removeHead(List& list);
void addTail(List& list, Data input);
void removeTail(List& list);
void removeAll(List& list);
void removeBefore(List& list, Data toRemove);
int listLength(List list);
void listInsert(List& list, Data input, int pos);
void listRemove(List& list, int pos);
