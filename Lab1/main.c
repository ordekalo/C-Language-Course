//
// Created by ordekalo on 05/04/2020.
//
#include "functionsLab1.h"
#include <stdio.h>

int main(){
    printHello();

    int base;
    printf("Please enter the triangle base:\n");
    scanf("%d", &base);
    printTriangle(base);

    return 0;
}

