#include "exe.h"
#include "func.h"
#include <stdio.h>

void Q1(){
	float num1 = 6, num2 = 4;
	float mult, div;
	int res = multDiv(num1, num2, &mult, &div);

	if(res == 0)
		printf("error\n");
	else
		printf("mult = %.2f div = %.2f\n", mult, div);
}

void Q2(){
	char Char = 'G';
	changeChar(&Char);
	printf("Char = %c\n", Char);
}

void Q3(){
	int num = 1234;
	int res = reversePositive(&num);
	if(res == 1)
		printf("reversed num = %d\n", num);
	else
		printf("negative number\n");
}

void Q4(){
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum, evens;
	arraySumAndEvenCount(arr, size, &sum, &evens);
	printf("The sum of arr is %d and there are %d evens\n", sum, evens);
}

void Q5(){
	int arr[] =  {0,1,2,3,4,5,6,7,8,9,111,21};
	int size = sizeof(arr)/sizeof(arr[0]);
	int n = 3;
	int pDivC, pEqC;
	nDivAndEq(arr, size, n, &pDivC, &pEqC);
	printf("The arr has %d divided and %d equal to %d\n", pDivC, pEqC, n);
}
