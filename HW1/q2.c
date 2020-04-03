//
// Created by ordekalo on 03/04/2020.
//

#include "general.h"
#include <stdio.h>
#include <stdlib.h>

void initBoolMatrix(int *mat, int rows, int cols) {
    printf("initializing boolean values into matrix %dx%d\n", rows, cols);
    for (int r = 0; r < rows; r++) {
        printf("|");
        for (int c = 0; c < cols; c++) {
            int num = (rand() % 2);
            *(mat + r * cols + c) = num;
            printf("%d|", getCellValue(mat, cols, r, c));
        }
        printf("\n");
    }
    printf("\n");
}

// ROWS = Y axis , COLS = X axis
void getRectPos(int *y, int *x, const int *mat, int rows, int cols, int startY, int startX) {
    //Validate current position not 0
    if (!isFilled(mat, cols, startY, startX)) {
        // -1 symbolize None
        *y = -1;
        *x = -1;
        return;
    }
    int rightSteps = 0;
    for (int c = startX; c < cols; c++) {
        if (!isFilled(mat, cols, startY, c)) {
            break;
        }
        if (isUpFilled(mat, cols, startY, c)) {
            *y = -1;
            *x = -1;
            return;
        }
        rightSteps++;
    }
    int downSteps = 0;
    for (int r = startY; r < rows; r++) {
        if (!isFilled(mat, cols, r, startX)) {
            break;
        }
        if (isLeftFilled(mat, cols, r, startX)) {
            *y = -1;
            *x = -1;
            return;
        }
        downSteps++;
    }

    for (int rS = startX; rS < rightSteps; rS++) {
        if (isDownFilled(mat, rows, cols, startY + downSteps - 1, rS)) {
            *y = -1;
            *x = -1;
            return;
        }
    }

    for (int dS = startY; dS < downSteps; dS++) {
        if (isRightFilled(mat, cols, dS, startX + rightSteps - 1)) {
            *y = -1;
            *x = -1;
            return;
        }
    }

    for (int r = startY; r < downSteps; r++) {
        for (int c = startX; c < rightSteps; c++) {
            if (!isFilled(mat, cols, r, c)) {
                *y = -1;
                *x = -1;
                return;
            }
        }
    }

    *y = startY;
    *x = startX;
}

void getRectDim(int *width, int *length, const int *mat, int rows, int cols, int startY, int startX) {
    //Validate current position not 0
    if (!isFilled(mat, cols, startY, startX)) {
        // -1 symbolize None
        *length = -1;
        *width = -1;
        return;
    }
    int rightSteps = 0;
    for (int c = startX; c < cols; c++) {
        if (!isFilled(mat, cols, startY, c)) {
            break;
        }
        if (isUpFilled(mat, cols, startY, c)) {
            *length = -1;
            *width = -1;
            return;
        }
        rightSteps++;
    }
    int downSteps = 0;
    for (int r = startY; r < rows; r++) {
        if (!isFilled(mat, cols, r, startX)) {
            break;
        }
        if (isLeftFilled(mat, cols, r, startX)) {
            *length = -1;
            *width = -1;
            return;
        }
        downSteps++;
    }

    for (int rS = startX; rS < rightSteps; rS++) {
        if (isDownFilled(mat, rows, cols, startY + downSteps - 1, rS)) {
            *length = -1;
            *width = -1;
            return;
        }
    }

    for (int dS = startY; dS < downSteps; dS++) {
        if (isRightFilled(mat, cols, dS, startX + rightSteps - 1)) {
            *length = -1;
            *width = -1;
            return;
        }
    }

    for (int r = startY; r < downSteps; r++) {
        for (int c = startX; c < rightSteps; c++) {
            if (!isFilled(mat, cols, r, c)) {
                *length = -1;
                *width = -1;
                return;
            }
        }
    }

    *length = downSteps;
    *width = rightSteps;
}

//format (x, y, width, length)
void printRects(const int *mat, int rows, int cols) {
    int x, y, width, length;
    for (int currentY = 0; currentY < rows; currentY++) {
        for (int currentX = 0; currentX < cols; currentX++) {
            getRectPos(&y, &x, mat, rows, cols, currentY, currentX);
            getRectDim(&width, &length, mat, rows, cols, currentY, currentX);
            if (x != -1) {
                printf("(%4d, %4d, %4d, %4d)\n", x + 1, y + 1, width, length);
            }
        }
    }
}

