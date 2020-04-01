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

#endif //HW1_GENERAL_H
