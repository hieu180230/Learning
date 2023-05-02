#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

Polynomial* createNode(int countInput, float* degInput, float* coefInput)
{
	Polynomial* newNode = new Polynomial;
	newNode->count = countInput;
	newNode->deg = degInput;
	newNode->coef = coefInput;
	newNode->pNext = NULL;
	return newNode;
}

void append(Polynomial*& p,int countInput, float* degInput, float* coefInput)
{
	if (p == NULL)
	{
		p = createNode(countInput, degInput, coefInput);
		return;
	}
	Polynomial* pCur = p;
	while (pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
	}
	pCur->pNext = createNode(countInput, degInput, coefInput);
	return;
}

void readBin(string filename, Polynomial* &p)
{
	fstream file;
	file.open(filename, ios::binary | ios::in);
	Polynomial* pCur = p;
	int count = 0;
	while (!file.eof())
	{
		pCur = new Polynomial;
		file.read(reinterpret_cast<char*>(&count), 2);
		pCur->count = count;
		//cout << pCur->count << endl;
		pCur->deg = new float[count];
		pCur->coef = new float[count];
		for (int i = 0; i < count; i++)
		{
			pair <float, float> pair;
			file.read(reinterpret_cast<char*>(&pair), sizeof(pair));
			pCur->deg[i] = pair.first;
			pCur->coef[i] = pair.second;
			//cout << pCur->deg[i] << " " << pCur->coef[i] << endl;
		}
		pCur->pNext = NULL;
		pCur = pCur->pNext;
	}
	file.close();
	pCur = p;
	while (pCur != NULL)
	{
		cout << pCur->count << endl;
		for (int i = 0; i < pCur->count; i++)
		{
			cout << pCur->deg[i] << " " << pCur->coef[i] << endl;
		}
		pCur = pCur->pNext;
	}
}

void outputList(Polynomial* p)
{
	if (p == NULL)
	{
		cout << "NULL" << endl;
		return;
	}
	Polynomial* pCur = p;
	while (pCur != NULL)
	{
		cout << pCur->count << endl;
		for (int i = 0; i < pCur->count; i++)
		{
			cout << pCur->deg[i] << " " << pCur->coef[i] << endl;
		}
		pCur = pCur->pNext;
	}
}