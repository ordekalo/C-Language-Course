//
// Created by ordekalo on 31/03/2020.
//

#ifndef HW1_GENERAL_H
#define HW1_GENERAL_H

#define UPPER 100
#define LOWER -100
#define BIG_DIM 20 // AS DEFAULT ROWS & COLS

void printDefaultDim();

void printMatrix(const int *mat, int rows, int cols);

void printEffectiveMatrix(const int *mat, int startRow, int startCol, int subRows, int subCols);

void initMatrix(int *mat, int rows, int cols);

int sumEffectiveMatrix(const int *mat, int startRow, int startCol, int rows, int cols);

void printMaxSubMatrix(const int *mat, int rows, int cols, int subRows, int subCols);

void scanRowCol(int *rows, int *cols);

void scanSubRowCol(int *subRows, int *subCols, int selectedRows, int selectedCols);

void initBoolMatrix(int *mat, int rows, int cols);

void getRectPos(int *y, int *x, const int *mat, int rows, int cols, int startY, int startX);

void getRectDim(int *width, int *length, const int *mat, int rows, int cols, int startY, int startX);

void printRects(const int *mat, int rows, int cols);

int isUpFilled(const int *mat, int cols, int y, int x);

int isDownFilled(const int *mat, int rows, int cols, int y, int x);

int isLeftFilled(const int *mat, int cols, int y, int x);

int isRightFilled(const int *mat, int cols, int y, int x);

int isFilled(const int *mat, int cols, int y, int x);

void initEmptyMatrix(int *mat, int rows, int cols);

int isInBounds(int rows, int cols, int x1, int y1, int x2, int y2);

int isStraightLine(int x1, int y1, int x2, int y2);

int isHorizontal(int y1, int y2);

int isReversed(int x1, int y1, int x2, int y2);

void scanValidLine(int rows, int cols, int *x1, int *y1, int *x2, int *y2);

int isLineInsertable(const int *mat, int rows, int cols, int x1, int y1, int x2, int y2);

void insertLine(int *mat, int cols, int x1, int y1, int x2, int y2);

#endif //HW1_GENERAL_H
