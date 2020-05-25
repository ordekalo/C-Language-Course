#include <stdio.h>
#include <ctype.h>
#include "building.h"

#define FILE_NAME "afeka.txt"

int main() {
    int buildCount, index, bCont = 1;
    char tav;

    Building **buildArr = readBuildingsArr(FILE_NAME, &buildCount);
    if (!buildArr) {
        printf("\n No buildings, getting out\n");
        return 0;
    }

    printf("\n--------------\n");
    printBuildingsArr(buildArr, buildCount);

    printf("\n----Add a families----------\n");

    while (bCont) {
        printf("Do you want to add a family? y/n\n");
        do {
            scanf("%c", &tav);
        } while (isspace(tav));
        if (tav == 'n' || tav == 'N')
            bCont = 0;
        else {
            scanf("%c", &tav); //clean buffer
            index = findBuildingToAddFamily(buildArr, buildCount);
            if (index != -1) {
                if (addFamily(buildArr[index]))
                    printf("Family was added\n");
                else
                    printf("Error adding family\n");
            } else {
                printf("All buildings are full\n");
                bCont = 0;
            }
        }
    }

    saveBuildingsArr(FILE_NAME, buildArr, buildCount);


    freeBuildingArr(buildArr, buildCount);
    printf("Bye Bye");
    return 0;
}
