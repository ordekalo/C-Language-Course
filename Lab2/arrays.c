#include <stdio.h>
#include <ctype.h>

#define COLS 5

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void initArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("Please enter value in place %d:\n", i+1);
		scanf("%d", &arr[i]);
	}
}

void printMatrix(char matr[][COLS], int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			printf("%c\t", matr[i][j]);
		}
		printf("\n");
	}	
}

void initMatrix(char matr[][COLS], int rows, int cols){
	char c;
        for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                        printf("Please enter value in place (%d,%d)\n", i+1, j+1);
			scanf("%c", &matr[i][j]);
			while((c=getchar())!='\n' && c !=EOF );
                }
        }       
}
