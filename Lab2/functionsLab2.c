#include "functionsLab2.h"
#include <ctype.h>

#define COLS 5

int isGrowingArr(int arr[], int size){
	if(size == 0 || size == 1){
		return 1;
	}

	for(int i = 1; i < size; i++){
		if(arr[i-1] > arr[i]){
			return 0;
		}
	}
}

int countChar(char matr[][COLS], int rows, int cols, char c){
	int counter = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){ 
			if(matr[i][j] == c || matr[i][j] == toupper(c)){
				counter++;
			}
		}
	}
	
	return counter;
}
