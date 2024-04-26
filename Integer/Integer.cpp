
#include "SuperLongInt.h"
#include <stdio.h>
#include <iostream>
using namespace std;


void sortArr(void* a, int size, int num, int (*cmp2)(void* p1, void* p2))
{
	int i, j;
	for (i = 0; i < num - 1; i++)
		for (j = 0; j < num - 1; j++)
		{
			char* p1, * p2;
			p1 = (char*)a + j * size;
			p2 = p1 + size;
			if (cmp2(p1, p2) > 0)
			{
				char tmp[1000];
				memcpy(tmp, p1, size);
				memcpy(p1, p2, size);
				memcpy(p2, tmp, size);
			}
		}
}







int sort(const void* p1,const void* p2)
{
	SuperLongInt* pInt1 = (SuperLongInt*)p1;
	SuperLongInt* pInt2 = (SuperLongInt*)p2;
	if (pInt1->ToFinancial() > pInt2->ToFinancial())
		return 1;
	else if (pInt1->ToFinancial() < pInt2->ToFinancial())
		return -1;
	else
		return 0;
}

int main()
{
    
	SuperLongInt Arr[10];
	for (int i = 0; i < 10; i++)
		cin >> Arr[i];

	cout << endl;

	
	qsort(Arr, 10,sizeof(SuperLongInt),sort); 
	  
	for (int i = 0; i < 10; i++)
		cout << Arr[i];
    
    

    

  
}

