//
// Created by ordekalo on 31/03/2020.
//
#include <stdio.h>
#include "general.h"

void printDefaultDim() {
    printf("default dimensions are: ROWS = %d, COLS = %d\n", BIG_DIM, BIG_DIM);
}

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

int getCellValue(const int *mat, int cols, int y, int x) {
    return *((mat + y * cols) + x);
}

void scanRowCol(int *rows, int *cols) {
    printf("please enter how many rows:\n");
    scanf("%d", rows);
    while (*rows < 1 || *rows > BIG_DIM) {
        printf("please enter a value between 1 and %d:\n", BIG_DIM);
        scanf("%d", rows);
    }
    printf("please enter how many cols:\n");
    scanf("%d", cols);
    while (*cols < 1 || *cols > BIG_DIM) {
        printf("please enter a value between 1 and %d:\n", BIG_DIM);
        scanf("%d", cols);
    }
    printf("you chose rows=%d and cols=%d\n", *rows, *cols);
}

int isUpFilled(const int *mat, int cols, int y, int x) {
    if (y > 0) {
        if (isFilled(mat, cols, y - 1, x)) {
            return 1;
        }
    }
    return 0;
}

int isDownFilled(const int *mat, int rows, int cols, int y, int x) {
    if (y < rows - 1) {
        if (isFilled(mat, cols, y + 1, x)) {
            return 1;
        }
    }
    return 0;
}

int isLeftFilled(const int *mat, int cols, int y, int x) {
    if (x > 0) {
        if (isFilled(mat, cols, y, x - 1)) {
            return 1;
        }
    }
    return 0;
}

int isRightFilled(const int *mat, int cols, int y, int x) {
    if (x < cols - 1) {
        if (isFilled(mat, cols, y, x + 1)) {
            return 1;
        }
    }
    return 0;
}

int isFilled(const int *mat, int cols, int y, int x) {
    if (getCellValue(mat, cols, y, x) == 1) {
        return 1;
    }
    return 0;
}
