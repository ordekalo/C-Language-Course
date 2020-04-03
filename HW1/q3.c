//
// Created by ordekalo on 03/04/2020.
//

#include "q3.h"
#include "general.h"
#include <stdio.h>

void scanValidLine(int rows, int cols, int *x1, int *y1, int *x2, int *y2) {
    int value;
    printf("please enter x1:\n");
    scanf("%d", &value);
    *x1 = value - 1;
    printf("please enter y1:\n");
    scanf("%d", &value);
    *y1 = value - 1;
    printf("please enter x2:\n");
    scanf("%d", &value);
    *x2 = value - 1;
    printf("please enter y2:\n");
    scanf("%d", &value);
    *y2 = value - 1;
    while (!(isInBounds(rows, cols, *x1, *y1, *x2, *y2) && isStraightLine(*x1, *y1, *x2, *y2))) {
        printf("please enter a valid line coordinates (straight, vertical/horizontal & in bounds)!!!\n");
        printf("please enter x1:\n");
        scanf("%d", &value);
        *x1 = value - 1;
        printf("please enter y1:\n");
        scanf("%d", &value);
        *y1 = value - 1;
        printf("please enter x2:\n");
        scanf("%d", &value);
        *x2 = value - 1;
        printf("please enter y2:\n");
        scanf("%d", &value);
        *y2 = value - 1;
    }
    printf("you chose (%d,%d,%d,%d)\n", *x1 + 1, *y1 + 1, *x2 + 1, *y2 + 1);
}

int isInBounds(int rows, int cols, int x1, int y1, int x2, int y2) {
    if (0 <= x1 && x1 < cols && 0 <= x2 && x2 < cols && 0 <= y1 && y1 < rows && 0 <= y2 && y2 < rows) {
        return 1;
    }
    return 0;
}

int isStraightLine(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return 1;
    }
    return 0;
}

int isHorizontal(int y1, int y2) {
    if (y1 == y2) {
        return 1;
    }
    return 0;
}

int isReversed(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        return 1;
    }
    return 0;
}

int isLineInsertable(const int *mat, int rows, int cols, int x1, int y1, int x2, int y2) {
    int insertable = 1;
    if (isReversed(x1, y1, x2, y2)) {
        if (isHorizontal(y1, y2)) {
            if (isLeftFilled(mat, cols, y1, x2)) {
                insertable = 0;
            }
            if (isRightFilled(mat, cols, y1, x1)) {
                insertable = 0;
            }
            for (int c = x2; c <= x1; c++) {
                if (isFilled(mat, cols, y1, c)) {
                    insertable = 0;
                }
            }
        } else {
            if (isUpFilled(mat, cols, y2, x2)) {
                insertable = 0;
            }
            if (isDownFilled(mat, rows, cols, y1, x1)) {
                insertable = 0;
            }
            for (int r = y2; r <= y1; r++) {
                if (isFilled(mat, cols, r, x2)) {
                    insertable = 0;
                }
            }
        }
    } else {
        if (isHorizontal(y1, y2)) {
            if (isLeftFilled(mat, cols, y1, x1)) {
                insertable = 0;
            }
            if (isRightFilled(mat, cols, y1, x2)) {
                insertable = 0;
            }
            for (int c = x1; c <= x2; c++) {
                if (isFilled(mat, cols, y1, c)) {
                    insertable = 0;
                }
            }
        } else {
            if (isUpFilled(mat, cols, y1, x1)) {
                insertable = 0;
            }
            if (isDownFilled(mat, rows, cols, y2, x2)) {
                insertable = 0;
            }
            for (int r = y1; r <= y2; r++) {
                if (isFilled(mat, cols, r, x1)) {
                    insertable = 0;
                }
            }
        }
    }
    return insertable;
}

void insertLine(int *mat, int cols, int x1, int y1, int x2, int y2) {
    int lower = (y1 < y2) ? y2 : y1;
    int higher = (y1 < y2) ? y1 : y2;
    int lefter = (x1 < x2) ? x1 : x2;
    int righter = (x1 < x2) ? x2 : x1;

    for (int r = lower; r <= higher; r++) {
        for (int c = lefter; c <= righter; c++) {
            *(mat + cols * r + c) = 1;
        }
    }
}

void initEmptyMatrix(int *mat, int rows, int cols) {
    printf("initializing empty matrix %dx%d\n", rows, cols);
    for (int r = 0; r < rows; r++) {
        printf("|");
        for (int c = 0; c < cols; c++) {
            *(mat + r * cols + c) = 0;
            printf("%4d|", getCellValue(mat, cols, r, c));
        }
        printf("\n");
    }
    printf("\n");
}