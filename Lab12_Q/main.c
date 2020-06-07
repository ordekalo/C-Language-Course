#include <stdlib.h>
#include "list.h"
#include "Q.h"

void Q1();
void Q2();

int main()
{

	Q1();
	Q2();
	system("pause");
}


void Q1()
{
	int arr[] = { 6,50,2,16,7,-9,11 };
	LIST lst;
	L_init(&lst);

	createListFromArr(&lst, arr, sizeof(arr)/sizeof(arr[0]));
	L_print(&lst);
	
	//Add function call here  - findMax

	
	
}

void Q2()
{
	int arr[] = { 6,50,2,16,7,-9,11 };
	LIST lst;
	L_init(&lst);

	createListFromArr(&lst, arr, sizeof(arr) / sizeof(arr[0]));
	L_print(&lst);


	//Add function call here  - removeDuplicates



}

