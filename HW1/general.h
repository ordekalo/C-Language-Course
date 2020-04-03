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

int getCellValue(const int *mat, int cols, int y, int x);

void scanRowCol(int *rows, int *cols);

int isUpFilled(const int *mat, int cols, int y, int x);

int isDownFilled(const int *mat, int rows, int cols, int y, int x);

int isLeftFilled(const int *mat, int cols, int y, int x);

int isRightFilled(const int *mat, int cols, int y, int x);

int isFilled(const int *mat, int cols, int y, int x);

#endif //HW1_GENERAL_H
