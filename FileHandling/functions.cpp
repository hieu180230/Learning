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
		file.read(reinterpret_cast<char*>(&count), 2);
		float* degInput = new float[count];
		float* coefInput = new float[count];
		for (int i = 0; i < count; i++)
		{
			pair <float, float> pair;
			file.read(reinterpret_cast<char*>(&pair), sizeof(pair));
			degInput[i] = pair.first;
			coefInput[i] = pair.second;
		}
		append(p, count, degInput, coefInput);
	}
	file.close();
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

void writeBin(string filename, Polynomial* p)
{
	if (p == NULL)
	{
		cout << "NULL" << endl;
		return;
	}
	Polynomial* pCur = p;
	int maxDegree = 0, maxNode = 0, node = 0;
	while (pCur != NULL)
	{
		int degree = 0;
		for (int i = 0; i < pCur->count; i++)
		{
			degree += pCur->deg[i];
		}
		if (degree >= maxDegree)
		{
			maxNode = node;
			maxDegree = degree;
		}
		node++;
	}
	pCur = p;
	int index = 0;
	while (index != maxNode)
	{
		pCur = pCur->pNext;
		index++;
	}
	fstream file;
	file.open(filename, ios::binary | ios::out);
	file.write(reinterpret_cast<char*>(&pCur->count), 2);
	pair <float, float> pair;
	for (int i = 0; i < pCur->count; i++)
	{
		pair = make_pair(pCur->deg[i], pCur->coef[i]);
		file.write(reinterpret_cast<char*>(&pair), sizeof(pair));
	}
	file.close();
}