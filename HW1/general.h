//
// Created by ordekalo on 31/03/2020.
//

#ifndef HW1_GENERAL_H
#define HW1_GENERAL_H

#define UPPER 100
#define LOWER -100
#define BIG_DIM 20 // AS DEFAULT ROWS & COLS


void printMatrix(const int *mat, int rows, int cols);

void printEffectiveMatrix(const int *mat, int startRow, int startCol, int subRows, int subCols);

void initMatrix(int *mat, int rows, int cols);

int sumEffectiveMatrix(const int *mat, int startRow, int startCol, int rows, int cols);

void printMaxSubMatrix(const int *mat, int rows, int cols, int subRows, int subCols);

void scanSubRowCol(int *subRows, int *subCols);

void initBoolMatrix(int *mat, int rows, int cols);

void getRectPos(int *y, int *x, const int *mat, int rows, int cols, int startY, int startX);

void getRectDim(int *width, int *length, const int *mat, int rows, int cols, int startY, int startX);

void printRects(const int *mat, int rows, int cols);

int checkUpFilled(const int *mat, int cols, int y, int x);

int checkDownFilled(const int *mat, int rows, int cols, int y, int x);

int checkLeftFilled(const int *mat, int cols, int y, int x);

int checkRightFilled(const int *mat, int cols, int y, int x);

int checkFilled(const int *mat, int cols, int y, int x);

#endif //HW1_GENERAL_H
