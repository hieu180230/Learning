#include "functions.h"
#include <stdio.h>
using namespace std;

int main()
{
	Polynomial* p = NULL;
	Polynomial* pL = NULL;
	readBin("POLY.BIN", p);
	outputList(p);
	cout << endl;
	writeBin("POLY_LARGEST.BIN", p);
	readBin("POLY_LARGEST.BIN", pL);
	cout << endl;
	outputList(pL);
}