//
// Created by ordekalo on 31/03/2020.
//

#include <stdio.h>
#include "array.h"

#define COLS 5

void printArr(const int *arr, int size) {
    for (int i = 0; i < size; i++, arr++) {
        printf("%d\t", *arr);
    }
    printf("\n");
}

void initArr(int *arr, int size) {
    printf("Enter %d numbers to array\n", size);
    for (int i = 0; i < size; i++, arr++) {
        scanf("%d", arr);
    }
}

void revArr(int *arr, int size) {
    int *pointer1 = arr;
    int *pointer2 = arr + size - 1;
    while (pointer1 < pointer2) {
        swap(pointer1, pointer2);
        pointer1++;
        pointer2--;
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printMat(int mat[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(*(mat + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void initMat(int mat[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter %d,%d numbers to matrix\n", i, j);
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void printReverse1(int *arr, int size) {
    int *pLastArr = arr;
    for (int i = 0; i < size; i++, pLastArr--) {
        printf("%d\t", *(pLastArr + size - 1));
    }
    printf("\n");
}

void printReverse2(int *arr, int size) {
    int *pointer1 = arr;
    int *pointer2 = arr + size - 1;
    while (pointer1 <= pointer2) {
        printf("%d\t",*pointer2);
        pointer2--;
    }
    printf("\n");
}
