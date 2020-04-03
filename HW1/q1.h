//
// Created by ordekalo on 03/04/2020.
//

#ifndef HW1_Q1_H
#define HW1_Q1_H

void initMatrix(int *mat, int rows, int cols);

void scanSubRowCol(int *subRows, int *subCols, int selectedRows, int selectedCols);

int sumEffectiveMatrix(const int *mat, int rows, int cols, int startRow, int startCol);

void printMaxSubMatrix(const int *mat, int rows, int cols, int subRows, int subCols);

void printEffectiveMatrix(const int *mat, int rows, int cols, int startRow, int startCol, int subRows, int subCols);

#endif //HW1_Q1_H
