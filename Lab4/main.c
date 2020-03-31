#include <stdio.h>
#include "array.h"

#define N 5
#define COLS 5

int main() {
    int arr[N];
    int size = N;

    initArr(arr, size);
    //printArr(arr, size);
    //revArr(arr, size);
    //printArr(arr, size);

//    int mat[ROWS][COLS];
//    initMat(mat, ROWS, COLS);
//    printMat(mat, ROWS, COLS);

    printReverse1(arr, size);
    printReverse2(arr, size);

    return 0;
}
