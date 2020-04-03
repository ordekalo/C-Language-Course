//
// Created by ordekalo on 31/03/2020.
//
#include <stdio.h>
#include <stdlib.h>
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