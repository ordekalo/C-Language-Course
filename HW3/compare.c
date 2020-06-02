//
// Created by ordekalo on 02/06/2020.
//

#include "compare.h"
#include "flight.h"

int compareByATD(const void *flight1, const void *flight2) {
    Flight f1 = *((Flight *) flight1);
    Flight f2 = *((Flight *) flight2);

    if (f1.ATD < f2.ATD) return -1;
    else if (f1.ATD > f2.ATD) return 1;
    else return 0;
}

int compareByDate(const void *flight1, const void *flight2) {
    Flight f1 = *((Flight *) flight1);
    Flight f2 = *((Flight *) flight2);

    if (f1.date.year < f2.date.year) return -1;
    else if (f1.date.year > f2.date.year) return 1;

    if (f1.date.month < f2.date.month) return -1;
    else if (f1.date.month > f2.date.month) return 1;

    if (f1.date.day < f2.date.day) return -1;
    else if (f1.date.day > f2.date.day) return 1;

    return 0;
}

int compareBySpeed(const void *flight1, const void *flight2) {
    Flight f1 = *((Flight *) flight1);
    Flight f2 = *((Flight *) flight2);

    if (f1.avgSpeed < f2.avgSpeed) return -1;
    else if (f1.avgSpeed > f2.avgSpeed) return 1;
    else return 0;
}
