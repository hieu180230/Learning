#include "func.h"
#include <math.h>
using namespace std;

int Count(List list)
{
	if (listEmpty(list) == true) return 0;
	if (listLength(list) < 3) return 0;
	int count = 0;
	Node* pCur = list.pHead->pNext;
	Node* pPrev = list.pHead;
	while (pCur->pNext != NULL)
	{
		if (pCur->data.age == abs(pPrev->data.age - pCur->pNext->data.age))
		{
			count++;
		}
		pCur = pCur->pNext;
		pPrev = pPrev->pNext;
	}
	return count;
}