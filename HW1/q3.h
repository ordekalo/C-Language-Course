//
// Created by ordekalo on 03/04/2020.
//

#ifndef HW1_Q3_H
#define HW1_Q3_H

void scanValidLine(int rows, int cols, int *x1, int *y1, int *x2, int *y2);

int isInBounds(int rows, int cols, int x1, int y1, int x2, int y2);

int isStraightLine(int x1, int y1, int x2, int y2);

int isHorizontal(int y1, int y2);

int isReversed(int x1, int y1, int x2, int y2);

int isLineInsertable(const int *mat, int rows, int cols, int x1, int y1, int x2, int y2);

void insertLine(int *mat, int cols, int x1, int y1, int x2, int y2);

void initEmptyMatrix(int *mat, int rows, int cols);

#endif //HW1_Q3_H
