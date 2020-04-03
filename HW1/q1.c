//
// Created by ordekalo on 03/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "general.h"


void initMatrix(int *mat, int rows, int cols) {
    printf("initializing values into matrix %dx%d\n", rows, cols);
    for (int r = 0; r < rows; r++) {
        printf("|");
        for (int c = 0; c < cols; c++) {
            int num = (rand() % (UPPER - LOWER + 1)) + LOWER;
            *(mat + r * cols + c) = num;
            printf("%4d|", getCellValue(mat, cols, r, c));
        }
        printf("\n");
    }
    printf("\n");
}

void scanSubRowCol(int *subRows, int *subCols, int selectedRows, int selectedCols) {
    printf("please enter how many subRows:\n");
    scanf("%d", subRows);
    while (*subRows < 1 || *subRows > selectedRows) {
        printf("please enter a value between 1 and %d:\n", selectedRows);
        scanf("%d", subRows);
    }
    printf("please enter how many subCols:\n");
    scanf("%d", subCols);
    while (*subCols < 1 || *subCols > selectedCols) {
        printf("please enter a value between 1 and %d:\n", selectedCols);
        scanf("%d", subCols);
    }
    printf("you chose subRows=%d and subCols=%d\n", *subRows, *subCols);
}

void printEffectiveMatrix(const int *mat, int rows, int cols, int startRow, int startCol, int subRows, int subCols) {
    int endRow = subRows + startRow;
    if (endRow > rows) {
        endRow = rows;
    }
    int endCol = subCols + startCol;
    if (endCol > cols) {
        endCol = cols;
    }
    for (int r = startRow; r < endRow; r++) {
        printf("|");
        for (int c = startCol; c < endCol; c++) {
            printf("%4d|", getCellValue(mat, cols, r, c));
        }
        printf("\n");
    }
    printf("\n");
}


int sumEffectiveMatrix(const int *mat, int rows, int cols, int startRow, int startCol) {
    int sum = 0;
    int endRow = startRow + rows;
    int endCol = startCol + cols;
    for (int r = startRow; r < endRow; r++) {
        for (int c = startCol; c < endCol; c++) {
            sum += getCellValue(mat, cols, r, c);
        }
    }
    return sum;
}


void printMaxSubMatrix(const int *mat, int rows, int cols, int subRows, int subCols) {
    int maxSum, maxStartRow = 0, maxStartCol = 0;
    int endRow = rows - subRows;
    int endCol = cols - subCols;
    int tmpSum;
    //In case user chooses the main matrix dimensions
    maxSum = sumEffectiveMatrix(mat, subRows, subRows, maxStartRow, maxStartCol);
    for (int r = 0; r < endRow; r++) {
        for (int c = 0; c < endCol; c++) {
            tmpSum = sumEffectiveMatrix(mat, subRows, subRows, r, c);
            if (tmpSum > maxSum) {
                maxSum = tmpSum;
                maxStartRow = r;
                maxStartCol = c;
            }
        }
    }

    printEffectiveMatrix(mat, rows, cols, maxStartRow, maxStartCol, subRows, subCols);
    printf("max sum is %d\n", maxSum);

}