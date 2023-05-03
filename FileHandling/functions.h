#pragma once
#include <iostream>
using namespace std;

struct Polynomial
{
	int count = 0;
	float* deg = NULL;
	float* coef = NULL;
	Polynomial* pNext = NULL;
};



void readBin(string filename, Polynomial*& p);
void outputList(Polynomial* p);
void writeBin(string filename, Polynomial* p);