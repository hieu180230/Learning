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

bool checkIncrease(List list, Node* pCur)
{
	if (listEmpty(list) == true) return false;
	if (pCur->pNext == NULL) return true;
	if (pCur->data.age >= pCur->pNext->data.age)
	{
		return false;
	}
	return checkIncrease(list, pCur->pNext);
}

Node* findX(Node* pHead, int x)
{
	if (pHead == NULL) return NULL;
	Node* pCur = pHead;
	while (pCur != NULL)
	{
		if (pCur->data.age == x) return pCur;
	}
	return NULL;
}

void removeAllXs(Node*& pHead, int x)
{
	if (pHead == NULL) return;
	Node* pCur = pHead;
	while (pCur->pNext != NULL)
	{
		if (pCur->pNext->data.age == x)
		{
			Node* pTemp = pCur->pNext->pNext;
			delete pCur->pNext;
			pCur->pNext = pTemp;
		}
		else pCur = pCur->pNext;
	}
	if (pHead->data.age == x)
	{
		Node* pTemp = pHead->pNext;
		delete pHead;
		pHead = pTemp;
	}
}

void insertList(Node*& pHead, Node*& pAnother)
{
	Node* pCur = pHead;
	Node* pInsert = pAnother;
	if (pInsert->data.age <= pHead->data.age)
	{

	}
	while (pCur->pNext != NULL)
	{
		pCur->pNext->data;
	}
}

//new

int countOccurrence(List list, List sublist)
{
	if (list.pHead == NULL || sublist.pHead == NULL) return 0;
	Node* pCur = list.pHead;
	int count = 0;
	while (pCur != NULL)
	{
		if (pCur->data.age == sublist.pHead->data.age)
		{
			bool matchCheck = true;
			Node* pTemp = pCur;
			Node* pSubTemp = sublist.pHead;
			while (pTemp != NULL && pSubTemp != NULL)
			{
				if (pTemp->data.age != pSubTemp->data.age)
				{
					matchCheck = false;
					break;
				}
				pTemp = pTemp->pNext;
				pSubTemp = pSubTemp->pNext;
			}
			if (matchCheck == true) count++;
		}
		pCur = pCur->pNext;
	}
	return count;
}

bool wordPalindromes(string s)
{
	List stack;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] <= 90 && s[i] >= 65)
		{
			s[i] = s[i] + 32;
		}
	}
	string noComaS = ""; // for filting non-space and non-character from s
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] >= 97 && s[i] <= 122) || s[i] == 32)
		{
			noComaS += s[i];
		}
	}
	s = noComaS;
	int wordCount = 0; //counting words in s 
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 97 || s[i] > 122)
		{
			wordCount++;
		}
	}
	wordCount++;
	if (wordCount % 2 == 1) // remove the word at the middle of s if the number of word in s is odd;
	{
		int lIndex = 0, rIndex = 0, mIndex = wordCount / 2, tranverseIndex = 0; 
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] < 97 || s[i] > 122)
			{
				tranverseIndex++;
			}
			if (tranverseIndex == mIndex - 1)
			{
				lIndex = i;
			}
			if (tranverseIndex == mIndex)
			{
				rIndex = i + 1;
			}
		}
		string sTemp = "";
		for (int i = 0; i <= lIndex; i++)
		{
			sTemp += s[i];
		}
		for (int i = rIndex; i < s.length(); i++)
		{
			sTemp += s[i];
		}
		s = sTemp;
	}
	string word = "";
	s += " ";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 97 || s[i] > 122)
		{
			if (stack.pHead == NULL) // add words to stack
			{
				Data input;
				input.name = word;
				input.age = 1;
				listAppend(stack, input);
			}
			else
			{
				Data input;
				input.name = word;
				input.age = 1;
				Node* pCur = stack.pHead;
				while (pCur->pNext != NULL)
				{
					pCur = pCur->pNext;
				}
				if (pCur->data.name != word) //add words to stack 
				{
					listAppend(stack, input);
				}
				else // remove if words match
				{
					removeTail(stack);
				}
			}
			word = "";
			continue;
		}
		word += s[i];
	}
	if (stack.pHead == NULL) return true;
	return false;
}