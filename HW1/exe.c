//
// Created by ordekalo on 31/03/2020.
//

#include "general.h"


void findMaxSubMatrix() {
    int biggestMatrix[BIG_DIM][BIG_DIM];
    initMatrix((int *) biggestMatrix, BIG_DIM, BIG_DIM);

    int subRows, subCols;
    scanSubRowCol(&subRows, &subCols);
    printMaxSubMatrix((const int *) biggestMatrix, BIG_DIM, BIG_DIM, subRows, subCols);

}

void pictureSquares() {
    int boolMatrix[BIG_DIM][BIG_DIM];
    initBoolMatrix((int *) boolMatrix, BIG_DIM, BIG_DIM);
    printRects((const int *) boolMatrix, BIG_DIM, BIG_DIM);
}

void pictureLines() {

}


