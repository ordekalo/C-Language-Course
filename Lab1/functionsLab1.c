//
// Created by ordekalo on 05/04/2020.
//

#include "functionsLab1.h"
#include <stdio.h>

void printHello(){
    printf("Hello World\n");
}

void printTriangle(int base){
    for(int i = 0; i<=base; i++){
        for(int j = 0; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
}