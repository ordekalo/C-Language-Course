#include <stdio.h>
#include "list.h"
#include "Q.h"


createListFromArr(LIST* pLst, const int* arr, int size)
{
	NODE* pN = &pLst->head;
	for (int i = 0; i < size; i++)
		pN = L_insert(pN, arr[i]);
}

int	 findMax(NODE* pN)
{

	return 0;
}

void removeDuplicates(NODE* pN)
{


}
