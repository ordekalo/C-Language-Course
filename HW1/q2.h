//
// Created by ordekalo on 03/04/2020.
//

#ifndef HW1_Q2_H
#define HW1_Q2_H

void initBoolMatrix(int *mat, int rows, int cols);

void getRectPos(int *y, int *x, const int *mat, int rows, int cols, int startY, int startX);

void getRectDim(int *width, int *length, const int *mat, int rows, int cols, int startY, int startX);

void printRects(const int *mat, int rows, int cols);

#endif //HW1_Q2_H
