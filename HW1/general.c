//
// Created by ordekalo on 31/03/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "general.h"

void printMatrix(const int *mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
    	printf("|");
        for (int j = 0; j < cols; ++j) {
            printf("%d|", *(mat + i * cols + j));
        }
        printf("\n");
    }
    printf("\n");
}

void printEffectiveMatrix(const int *mat, int startRow, int startCol, int subRows, int subCols) {
    int endRow = subRows + startRow;
    if (endRow > BIG_DIM) {
        endRow = BIG_DIM;
    }
    int endCol = subCols + startCol;
    if (endCol > BIG_DIM) {
        endCol = BIG_DIM;
    }
    for (int r = startRow; r < endRow; r++) {
    	printf("|");
        for (int c = startCol; c < endCol; c++) {
            printf("%4d|", *((mat + r * BIG_DIM) + c));
        }
        printf("\n");
    }
    printf("\n");
}

void initMatrix(int *mat, int rows, int cols) {
    printf("initializing values into matrix %dx%d\n", rows, cols);
    for (int r = 0; r < rows; r++) {
    	printf("|");
        for (int c = 0; c < cols; c++) {
            int num = (rand() % (UPPER - LOWER + 1)) + LOWER;
            *(mat + r * cols + c) = num;
            printf("%4d|", *(mat + r * cols + c));
        }
        printf("\n");
    }
    printf("\n");
}

int sumEffectiveMatrix(const int *mat, int startRow, int startCol, int rows, int cols) {
    int sum = 0;
    int endRow = startRow + rows;
    int endCol = startCol + cols;
    for (int r = startRow; r < endRow; r++) {
        for (int c = startCol; c < endCol; c++) {
            sum += (*((mat + r * BIG_DIM) + c));
        }
    }
    return sum;
}

void printMaxSubMatrix(const int *mat, int rows, int cols, int subRows, int subCols) {
    int maxSum, maxStartRow = 0, maxStartCol = 0;
    int endRow = rows - subRows;
    int endCol = cols - subCols;
    int tmpSum;
    //In case user chooses the matrix dimensions
    maxSum = sumEffectiveMatrix(mat, maxStartRow, maxStartCol, subRows, subRows);
    for (int r = 0; r < endRow; r++) {
        for (int c = 0; c < endCol; c++) {
            tmpSum = sumEffectiveMatrix(mat, r, c, subRows, subRows);
            if (tmpSum > maxSum) {
                maxSum = tmpSum;
                maxStartRow = r;
                maxStartCol = c;
            }
        }
    }

    printEffectiveMatrix(mat, maxStartRow, maxStartCol, subRows, subCols);
    printf("max sum is %d\n", maxSum);

}

void scanSubRowCol(int *subRows, int *subCols) {
    printf("please enter how many subRows:\n");
    scanf("%d", subRows);
    while (*subRows < 1 || *subRows > BIG_DIM) {
        printf("please enter a value between 1 and %d:\n", BIG_DIM);
        scanf("%d", subRows);
    }
    printf("please enter how many subCols:\n");
    scanf("%d", subCols);
    while (*subCols < 1 || *subCols > BIG_DIM) {
        printf("please enter a value between 1 and %d:\n", BIG_DIM);
        scanf("%d", subCols);
    }
    printf("you chose subRows=%d and subCols=%d\n", *subRows, *subCols);
}


