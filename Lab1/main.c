//
// Created by ordekalo on 05/04/2020.
//
#include "functionsLab1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printHello();

    char *pTr;
    printf("Please enter the triangle base:\n");
    int base = (int) strtol("%d", &pTr, 10);
    printTriangle(base);

    return 0;
}

