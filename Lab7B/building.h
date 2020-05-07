//
// Created by ordekalo on 06/05/2020.
//

#ifndef LAB7B_BUILDING_H
#define LAB7B_BUILDING_H

#include "family.h"

typedef struct {
    Family **allFamilies;
    int nOfFamilies;
    int maxFamilies;
} Building;

int initBuilding(Building *pBuilding);

int addFamily(Building *pBuilding);

int addAllFamilies(Building *pBuilding);

void printBuilding(const Building *pBuilding);

void freeBuilding(Building *pBuilding);

Building **createBuildingArr(int *pCount);

int initBuildingArr(Building **pBuildingArr, int count);

void printBuildingArr(Building **pBuildingArr, int count);

void freeBuildingArr(Building **pBuildingArr, int count);

#endif //LAB7B_BUILDING_H
