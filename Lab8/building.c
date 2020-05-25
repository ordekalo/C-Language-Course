#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "building.h"

int initBuilding(Building *pBuild) {
    printf("What is the max number of families? ");
    scanf("%d", &(pBuild->maxFamilies));

    pBuild->numOfFamilies = 0;

    if (pBuild->maxFamilies == 0) {
        pBuild->allFamilies = NULL;
        return 1;
    }

    pBuild->allFamilies = (Family **) malloc(sizeof(Family *)
                                             * pBuild->maxFamilies);
    if (!pBuild->allFamilies)
        return 0;

    addAllFamilies(pBuild);
    return 1;
}

void addAllFamilies(Building *pBuild) {
    int ok = 1;
    char tav;

    while (ok) {
        if (pBuild->maxFamilies == pBuild->numOfFamilies) //building full
            return;

        printf("Do you want to enter a family? y/n\n");
        do {
            scanf("%c", &tav);
        } while (isspace(tav));

        if (tav == 'y' || tav == 'Y')
            ok = addFamily(pBuild);
        else
            ok = 0;
    }
}

int addFamily(Building *pBuild) {
    if (pBuild->maxFamilies == pBuild->numOfFamilies)
        return 0;

    Family *pF = (Family *) malloc(sizeof(Family));
    if (!pF)
        return 0;
    if (!initFamily(pF))
        return 0;

    pBuild->allFamilies[pBuild->numOfFamilies] = pF;
    pBuild->numOfFamilies++;
    return 1;
}

void printBuilding(const Building *theBuilding) {
    int i;

    printf("has %d families out of %d:\n", theBuilding->numOfFamilies,
           theBuilding->maxFamilies);
    for (i = 0; i < theBuilding->numOfFamilies; i++)
        printFamily(theBuilding->allFamilies[i]);
}

void freeBuilding(Building *theBuilding) {
    int i;

    for (i = 0; i < theBuilding->numOfFamilies; i++) {
        freeFamily(theBuilding->allFamilies[i]);
        free(theBuilding->allFamilies[i]);
    }

    free(theBuilding->allFamilies);
}

__unused /****       Building Array functions ***************/

Building **createBuildingArr(int *pCount) {
    Building **buildArr;

    printf("How many buildings in neighborhood?");
    scanf("%d", pCount);

    if (*pCount == 0)
        return NULL;

    buildArr = (Building **) malloc(*pCount * sizeof(Building *));

    return buildArr; //maybe NULL
}

__unused int initBuildingsArr(Building **buildArr, int count) {
    int i;

    for (i = 0; i < count; i++) {
        buildArr[i] = (Building *) malloc(sizeof(Building));
        if (!buildArr[i])
            return 0;
        printf("Building %d: ", (i + 1));
        if (!initBuilding(buildArr[i]))
            return 0;
    }
    return 1;
}

void printBuildingsArr(Building **theBuildingArr, int count) {

    int i;
    printf("There are %d buildings in neighborhood\n", count);
    for (i = 0; i < count; i++) {
        printf("Building %d: ", (i + 1));
        printBuilding(theBuildingArr[i]);
    }
}

void freeBuildingArr(Building **theBuildingArr, int count) {
    int i;
    for (i = 0; i < count; i++) {
        freeBuilding(theBuildingArr[i]);
        free(theBuildingArr[i]);
    }
    free(theBuildingArr);
}

void readBuilding(FILE *file, Building *pBuild) {
    fscanf(file, "%d %d\n", &pBuild->numOfFamilies, &pBuild->maxFamilies);

    pBuild->allFamilies = (Family **) malloc(sizeof(Family *)
                                             * pBuild->maxFamilies);
    if (!pBuild->allFamilies) return;

    for (int i = 0; i < pBuild->numOfFamilies; ++i) {
        Family *pF = (Family *) malloc(sizeof(Family));

        if (!pF) return;

        readFamily(file, pF);
        pBuild->allFamilies[i] = pF;
    }
}

void saveBuilding(FILE *file, Building *pBuild) {
    fprintf(file, "%d %d\n", pBuild->numOfFamilies, pBuild->maxFamilies);
    for (int i = 0; i < pBuild->numOfFamilies; ++i) {
        saveFamily(file, pBuild->allFamilies[i]);
    }
}

Building **readBuildingsArr(const char *fName, int *count) {
    FILE *file = fopen(fName, "r");

    if (!file) return NULL;

    fscanf(file, "%d\n", count);

    Building **buildArr = (Building **) malloc(*count * sizeof(Building *));
    if (!buildArr) return NULL;

    for (int i = 0; i < *count; ++i) {
        Building *pBuild = (Building *) malloc(sizeof(Building));
        readBuilding(file, pBuild);
        buildArr[i] = pBuild;
    }
    fclose(file);

    return buildArr;
}

void saveBuildingsArr(const char *fName, Building **pBuildArr, int count) {
    FILE *file = fopen(fName, "w");
    if (!file) return;

    fprintf(file, "%d\n", count);

    for (int i = 0; i < count; ++i) {
        saveBuilding(file, pBuildArr[i]);
    }
    fclose(file);
}

int findBuildingToAddFamily(Building **pBuildArr, int count) {
    for (int i = 0; i < count; ++i) {
        if (pBuildArr[i]->numOfFamilies < pBuildArr[i]->maxFamilies) {
            return i;
        }
    }
    return -1;
}

