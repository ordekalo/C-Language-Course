//
// Created by ordekalo on 12/05/2020.
//

#ifndef HW2_FLIGHT_H
#define HW2_FLIGHT_H

#include "airport.h"
#include "airport_manager.h"
#include <stdlib.h>

#define DATE_LENGTH 10

typedef struct {
    Airport *pAptFrom;
    Airport *pAptDest;
    int ATD; //Actual Time of Departure
    char date[DATE_LENGTH];
    double avgSpeed; //units MPH
} Flight;

void scanCodes(char *codeFrom, char *codeDest);

void initFlight(Flight *pFlt, const AirportManager *aptMgr);

void printFlight(const Flight *pFlt);

void freeFlight(Flight *pFlt);

double calculateFlightTime(const Flight *pFlt);

int validateFlightByCodes(const Flight *pFlt, const char *fromCode, const char *destCode);

int countFlightsByCodes(Flight **pFlights, int amount, const char *fromCode, const char *destCode);

int validateDateFormat(const char *date);


#endif //HW2_FLIGHT_H
