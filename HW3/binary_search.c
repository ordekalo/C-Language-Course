//
// Created by ordekalo on 02/06/2020.
//

#include "binary_search.h"
#include "compare.h"
#include "flight.h"
#include <stdlib.h>

Flight *findFlightByATD(Flight **flightArr, int size, int atd) {
    Flight *pFlt = NULL;
    Flight temp;
    temp.ATD = atd;

    pFlt = (Flight *) bsearch(&temp, flightArr, size, sizeof(Flight *), compareByATD);
    if (!pFlt) {
        printf("the flights array is not sorted by %s can\'t find flight\n", "ATD");
        return NULL;
    }

    return pFlt;
}

Flight *findFlightBySpeed(Flight **flightArr, int size, double speed) {
    Flight *pFlt = NULL;
    Flight temp;
    temp.avgSpeed = speed;

    pFlt = (Flight *) bsearch(&temp, flightArr, size, sizeof(Flight *), compareBySpeed);
    if (!pFlt) {
        printf("the flights array is not sorted by %s can\'t find flight\n", "Speed");
        return NULL;
    }

    return pFlt;
}

Flight *findFlightByDate(Flight **flightArr, int size, char *dateString) {
    if (!validateDateFormat(dateString)) return NULL;

    Flight *pFlt = NULL;
    Flight temp;
    loadDateFromString(&temp.date, dateString);

    pFlt = (Flight *) bsearch(&temp, flightArr, size, sizeof(Flight *), compareByDate);
    if (!pFlt) {
        printf("the flights array is not sorted by %s can\'t find flight\n", "Date");
        return NULL;
    }

    return pFlt;
}
