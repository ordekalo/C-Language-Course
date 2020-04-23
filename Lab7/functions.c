//
// Created by ordekalo on 23/04/2020.
//

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *getEvenValuesArrSinglePass(const int *arr, int size, int *newSize) {
    int phySize = 2, logicSize = 0;
    int *evenArr = (int *) malloc(sizeof(int) * phySize);
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            if (phySize == logicSize) {
                phySize *= 2;
                evenArr = (int *) realloc(evenArr, phySize * sizeof(int));
            }
            evenArr[logicSize] = arr[i];
            logicSize++;
        }
    }
    *newSize = logicSize;
    return evenArr;
}

int *getEvenValuesArrDoublePass(const int *arr, int size, int *newSize) {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            counter++;
        }
    }
    *newSize = counter;
    int *evenArr = (int *) malloc(sizeof(int) * counter);
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            evenArr[counter - 1] = arr[i];
            counter--;
        }
    }
    return evenArr;
}

void initArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Please enter an int value:\n");
        scanf("%d", &arr[i]);
    }
}

void printArr(const int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == (size - 1)) {
            printf("%d]\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

char *getStrExactLength() {
    char str[255];
    printf("Please enter a string:\n");
    scanf("%s", str);
    return strdup(str);
}

char *generateLongString() {
    char *longStr, *str;
    int length = 0, flag = 1;
    longStr = (char *) malloc(sizeof(char) * 1);
    while (flag) {
        str = getStrExactLength();
        if (strcmp(str, "Bye") != 0) {
            length += (int) strlen(str);
            longStr = (char *) realloc(longStr, (length + 1) * sizeof(char));
            strcat(longStr, str);
            strcat(longStr, "$");
        } else {
            flag = 0;
        }
    }
    free(str);
    return longStr;
}