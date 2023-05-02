#include "functions.h"
#include <stdio.h>
using namespace std;

int main()
{
	Polynomial* p = NULL;
	readBin("POLY.BIN", p);
	outputList(p);
}