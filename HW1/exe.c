//
// Created by ordekalo on 31/03/2020.
//

#include "general.h"
#include "q1.h"
#include "q2.h"
#include "q3.h"
#include <stdio.h>


void findMaxSubMatrix() {
    printDefaultDim();

    int selectedRows, selectedCols;
    scanRowCol(&selectedRows, &selectedCols);

    int selectedMatrix[selectedRows][selectedCols];
    initMatrix((int *) selectedMatrix, selectedRows, selectedCols);

    int subRows, subCols;
    scanSubRowCol(&subRows, &subCols, selectedRows, selectedCols);
    printMaxSubMatrix((const int *) selectedMatrix, selectedRows, selectedCols, subRows, subCols);
}

void pictureSquares() {
    printDefaultDim();

    int selectedRows, selectedCols;
    scanRowCol(&selectedRows, &selectedCols);

    int selectedMatrix[selectedRows][selectedCols];
    initBoolMatrix((int *) selectedMatrix, selectedRows, selectedCols);

    printRects((const int *) selectedMatrix, selectedRows, selectedCols);
}

void pictureLines() {
    printDefaultDim();

    int selectedRows, selectedCols;
    scanRowCol(&selectedRows, &selectedCols);

    int selectedMatrix[selectedRows][selectedCols];
    initEmptyMatrix((int *) selectedMatrix, selectedRows, selectedCols);

    int x1, y1, x2, y2;
    int alive = 1;
    while (alive) {
        scanValidLine(selectedRows, selectedCols, &x1, &y1, &x2, &y2);
        if (!isLineInsertable((int *) selectedMatrix, selectedRows, selectedCols, x1, y1, x2, y2)) {
            printf("sorry, but your line is not insertable\nplease look for valid line at the matrix\n");
            continue;
        }
        insertLine((int *) selectedMatrix, selectedCols, x1, y1, x2, y2);
        printMatrix((int *) selectedMatrix, selectedRows, selectedCols);

        printf("do you want to insert another line? 1 = yes, 0 = no\n");
        scanf("%d", &alive);
    }
}


