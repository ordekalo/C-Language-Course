#ifndef __BUILDING_H
#define __BUILDING_H

#include "family.h"

typedef struct {
    int numOfFamilies;
    int maxFamilies;
    Family **allFamilies;
} Building;

int initBuilding(Building *pBuild);

void readBuilding(FILE *file, Building *pBuild);

void saveBuilding(FILE *file, Building *pBuild);

int addFamily(Building *pBuild);

void addAllFamilies(Building *pBuild);

void printBuilding(const Building *pBuild);

void freeBuilding(Building *pBuild);


__unused Building **createBuildingArr(int *pCount);

__unused int initBuildingsArr(Building **pBuildArr, int count);

Building **readBuildingsArr(const char *fName, int *count);

void saveBuildingsArr(const char *fName, Building **pBuildArr, int count);

int findBuildingToAddFamily(Building **pBuildArr, int count);

void printBuildingsArr(Building **pBuildArr, int count);

void freeBuildingArr(Building **pBuildArr, int count);

#endif // __BUILDING_H
