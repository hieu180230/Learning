#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

void readBin(string filename, Polynomial* &p)
{
	fstream file;
	file.open(filename, ios::binary | ios::in);
	pair <float, float> pair;
	int count = 0;
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&pair), sizeof(pair));
		count++;
	}
	file.seekg(0, ios::beg);
	p = new Polynomial[count];
	int index = 0;
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&pair), sizeof(pair));
		p[index].deg = pair.first;
		p[index].coef = pair.second;
		index++;
	}
	file.close();
}