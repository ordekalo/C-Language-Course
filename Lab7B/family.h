//
// Created by ordekalo on 06/05/2020.
//
#ifndef LAB7B_FAMILY_H
#define LAB7B_FAMILY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int numOfPeople;
} Family;

int initFamily(Family *theFamily);

void printFamily(const Family *theFamily);

void freeFamily(Family *theFamily);

char *createDynStr(const char *msg);

#endif //LAB7B_FAMILY_H
