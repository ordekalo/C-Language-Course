#include "functionsLab2.h"
#include "arrays.h"

void Q1_A()
{
	int arr[] = { 1,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArr(arr, size);
	if(isGrowingArr(arr, size)){
		printf("This array is growing!\n\n");
	}else{
		printf("This array is not growing\n\n");
	}
}

void Q1_B()
{
	int size = 5;
	int arr[size];
	initArr(arr, size);
	printArr(arr, size);

	if(isGrowingArr(arr, size)){
                printf("This array is growing!\n\n");
        }else{
                printf("This array is not growing\n\n");
        }
}

void Q2()
{
	int rows = 5;
	int cols = 5;
	char c = 'a';
	char charMatrix[rows][cols];
	initMatrix(charMatrix, rows, cols);	
	printMatrix(charMatrix, rows, cols);
	printf("Char '%c' exists %d times in your matrix\n\n", c, countChar(charMatrix, rows, cols, c));

}

