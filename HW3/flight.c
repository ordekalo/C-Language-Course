//
// Created by ordekalo on 12/05/2020.
//

#include "flight.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"


void printFlight(const Flight *pFlt) {
    printf("\nFlight from %3s to %3s in %d:00 at %s\n", pFlt->pAptFrom->code, pFlt->pAptDest->code, pFlt->ATD,
           pFlt->date);
    printf("Average speed: %lf mph, Distance: %lf miles\n", pFlt->avgSpeed,
           calculateDistanceA2A(pFlt->pAptFrom, pFlt->pAptDest));

    double flightHours = calculateFlightTime(pFlt);
    int hours = floor(flightHours);
    int minutes = (int) ((flightHours - hours) * 60);

    printf("Flight Duration: %d hours and %d minutes\n\n", hours, minutes);
}

double calculateFlightTime(const Flight *pFlt) {
    double distance = calculateDistanceA2A(pFlt->pAptFrom, pFlt->pAptDest);
    double hours = distance / pFlt->avgSpeed;
    return hours;
}

int countFlightsByCodes(Flight **pFlights, int amount, const char *fromCode, const char *destCode) {
    int counter = 0;
    if (!validateCode(fromCode) || !validateCode(destCode)) {
        return 0;
    }
    for (int i = 0; i < amount; ++i) {
        if (validateFlightByCodes(pFlights[i], fromCode, destCode)) {
            counter++;
        }
    }
    return counter;
}

int validateFlightByCodes(const Flight *pFlt, const char *fromCode, const char *destCode) {
    if (!validateCode(fromCode) || !validateCode(destCode)) {
        return 0;
    }
    if (validateAirportByAirportCode(pFlt->pAptFrom, fromCode) &&
        validateAirportByAirportCode(pFlt->pAptDest, destCode)) {
        return 1;
    }
    return 0;
}

void scanCodes(char *codeFrom, char *codeDest) {
    int flag;
    do {
        do {
            printf("Please Enter from IATA Code:\n");
            scanf(" %3s", codeFrom);
        } while (!validateCode(codeFrom));

        do {
            printf("Please Enter destination IATA Code (Different Than From IATA Code):\n");
            scanf(" %3s", codeDest);
        } while (!validateCode(codeDest));

        //check if same IATA
        flag = !strcmp(codeFrom, codeDest);
    } while (flag);
}

void initFlight(Flight *pFlt, const AirportManager *aptMgr) {
    char codeFrom[100];
    char codeDest[100];
    scanCodes(codeFrom, codeDest);

    Airport *pAptFrom = getAirport(aptMgr, codeFrom);
    if (!pAptFrom) {
        printf("%s Doesn\'t Exist at Airport Manager.\n", codeFrom);
        return;
    }
    pFlt->pAptFrom = pAptFrom;
    Airport *pAptDest = getAirport(aptMgr, codeDest);
    if (!pAptDest) {
        printf("%s Doesn\'t Exist at Airport Manager.\n", codeDest);
        return;
    }
    pFlt->pAptDest = pAptDest;

    do {
        printf("Please Enter Actual Time Of Departure: (23-0)\n");
        scanf(" %d", &pFlt->ATD);
    } while (pFlt->ATD > 23 || pFlt->ATD < 0);

    do {
        printf("Please Enter Date Of Departure: (dd/mm/yyyy Format Only!)\n");
        scanf(" %[^'\n']s", pFlt->date);
    } while (!validateDateFormat(pFlt->date));

    do {
        printf("Please Enter Average Speed Of Flight:\n");
        scanf(" %lf", &pFlt->avgSpeed);
    } while (pFlt->ATD > 23 || pFlt->ATD < 0);
}

void freeFlight(Flight *pFlt) {
    free(pFlt);
}

int validateDateFormat(const char *date) {
    for (int i = 0; date[i]; ++i) {
        if ((i == 2 || i == 5) && date[i] != '/') {
            return 0;
        }
        if (i != 2 && i != 5 && !isdigit(date[i])) {
            return 0;
        }

    }
    int day = charToInt(date[0]) * 10 + charToInt(date[1]);
    int month = charToInt(date[3]) * 10 + charToInt(date[4]);
    int year = charToInt(date[6]) * 1000 + charToInt(date[7]) * 100 + charToInt(date[8]) * 10 + charToInt(date[9]);
    if (!(1 <= day && day <= 31) || !(1 <= month && month <= 12) || !(2020 <= year && day <= 2025)) {
        return 0;
    }
    return 1;
}
