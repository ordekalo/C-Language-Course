//
// Created by ordekalo on 23/04/2020.
//
#include "exe.h"
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void Q1() {
    int size;
    printf("How many elements do you want?\n");
    scanf("%d", &size);

    int arr[size];
    initArr(arr, size);
    printArr(arr, size);

    int newSize1;
    int *evenArr = getEvenValuesArrSinglePass(arr, size, &newSize1);
    printArr(evenArr, newSize1);

    int newSize2;
    evenArr = getEvenValuesArrDoublePass(arr, size, &newSize2);
    printArr(evenArr, newSize2);

    free(evenArr);
}

void Q2() {
    char *str = getStrExactLength();
    printf("%s", str);
    free(str);
}

void Q3() {
    char *str = generateLongString();
    printf("%s", str);
    free(str);
}