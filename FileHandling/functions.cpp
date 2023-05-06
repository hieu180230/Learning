#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;
//begin
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
	while (file.read((char*)(&count), 2))
	{
		float* degInput = new float[count];
		float* coefInput = new float[count];
		for (int i = 0; i < count; i++)
		{
			pair <float, float> pair;
			file.read((char*)(&degInput[i]), 4);
			file.read((char*)(&coefInput[i]), 4);
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
	float maxDegree = 0;
	while (pCur != NULL)
	{
		for (int i = 0; i < pCur->count; i++)
		{
			if (pCur->deg[i] > maxDegree)
			{
				maxDegree = pCur->deg[i];
			}
		}
		pCur = pCur->pNext;
	}
	pCur = p;
	fstream file;
	file.open(filename, ios::binary | ios::out);
	while (pCur != NULL)
	{
		for (int a = 0; a < pCur->count; a++)
		{
			if (pCur->deg[a] == maxDegree)
			{
				file.write((char*)(&pCur->count), 2);
				pair <float, float> pair;
				for (int i = 0; i < pCur->count; i++)
				{
					file.write((char*)(&pCur->deg[i]), 4);
					file.write((char*)(&pCur->coef[i]), 4);
				}
				break;
			}
		}
		pCur = pCur->pNext;
	}
	file.close();
}
//end

//begin

