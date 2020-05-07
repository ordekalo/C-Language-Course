#include <stdio.h>
#include "building.h"

int main() {
    int count;
    Building **neighborhood = createBuildingArr(&count);

    if (!neighborhood) {
        printf("\n No Buildings, getting out\n");
        return 0;
    }

    initBuildingArr(neighborhood, count);
    printf("---------------------\n");
    printBuildingArr(neighborhood, count);
    freeBuildingArr(neighborhood, count);

    return 1;
}
