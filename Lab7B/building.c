//
// Created by ordekalo on 06/05/2020.
//

#include "building.h"
#include "family.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int initBuilding(Building *pBuilding) {
    printf("What is the max number of families?\n");
    scanf("%d", &(pBuilding->maxFamilies));
    pBuilding->nOfFamilies = 0;
    if (pBuilding->maxFamilies == 0) {
        pBuilding->allFamilies = NULL;
        return 1;
    }
    pBuilding->allFamilies = (Family **) malloc(sizeof(Family *) * pBuilding->maxFamilies);
    if (!pBuilding->allFamilies) {
        return 0;
    }
    addAllFamilies(pBuilding);
    return 1;
}

int addFamily(Building *pBuilding) {
    if (pBuilding->nOfFamilies == pBuilding->maxFamilies) { //building is full
        return 0;
    }
    Family *pFamily = (Family *) malloc(sizeof(Family));
    if (!pFamily) { //allocation error
        return 0;
    }
    if (!initFamily(pFamily)) {
        return 0;
    }

    pBuilding->allFamilies[pBuilding->nOfFamilies] = pFamily;
    pBuilding->nOfFamilies++;
    return 1;
}

int addAllFamilies(Building *pBuilding) {
    char option;
    int flag = 1;
    while (flag) {
        if (pBuilding->nOfFamilies == pBuilding->maxFamilies) { //building is full
            return 0;
        }
        printf("Do you want to enter a family? y/n \n");
        do {
            scanf("%c", &option);
        } while (isspace(option));

        if (option == 'y' || option == 'Y') {
            flag = addFamily(pBuilding);
        } else {
            flag = 0;
        }
    }
    return 1;
}

void printBuilding(const Building *pBuilding) {
    printf("has %d families out of %d:\n",
           pBuilding->nOfFamilies, pBuilding->maxFamilies);
    for (int i = 0; i < pBuilding->nOfFamilies; ++i) {
        printFamily(pBuilding->allFamilies[i]);
    }
}

void freeBuilding(Building *pBuilding) {
    for (int i = 0; i < pBuilding->nOfFamilies; ++i) {
        freeFamily(pBuilding->allFamilies[i]);
        free(pBuilding->allFamilies[i]);
    }
}

Building **createBuildingArr(int *pCount) {
    Building **neighborhood;
    printf("How many building in the neighborhood?\n");
    scanf("%d", pCount);
    if (*pCount == 0) {
        return NULL;
    }
    neighborhood = (Building **) malloc(sizeof(Building *) * (*pCount));

    return neighborhood; //maybe Null
}

int initBuildingArr(Building **pBuildingArr, int count) {
    for (int i = 0; i < count; ++i) {
        Building *pBuilding = (Building *) malloc(sizeof(Building));
        if (!pBuilding) { //allocation error
            return 0;
        }
        if (!initBuilding(pBuilding)) {
            return 0;
        }
        pBuildingArr[i] = pBuilding;
    }
    return 1;
}

void printBuildingArr(Building **pBuildingArr, int count) {
    printf("The are %d building in the neighborhood\n", count);
    for (int i = 0; i < count; ++i) {
        printf("Building %d: ", i + 1);
        printBuilding(pBuildingArr[i]);
    }
}

void freeBuildingArr(Building **pBuildingArr, int count) {
    for (int i = 0; i < count; ++i) {
        freeBuilding(pBuildingArr[i]);
        free(pBuildingArr[i]);
    }
    free(pBuildingArr);
}
