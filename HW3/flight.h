//
// Created by ordekalo on 12/05/2020.
//

#ifndef HW2_FLIGHT_H
#define HW2_FLIGHT_H

#include "airport.h"
#include "airport_manager.h"
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Airport *pAptFrom;
    Airport *pAptDest;
    int ATD; //Actual Time of Departure
    Date date;
    double avgSpeed; //units MPH
} Flight;

void scanCodes(char *codeFrom, char *codeDest);

void initFlight(Flight *pFlt, const AirportManager *aptMgr);

void printFlight(void *pFlt);

void freeFlight(Flight *pFlt);

double calculateFlightTime(const Flight *pFlt);

int validateFlightByCodes(const Flight *pFlt, const char *fromCode, const char *destCode);

int countFlightsByCodes(Flight **pFlights, int amount, const char *fromCode, const char *destCode);

int validateDateFormat(const char *date);

void loadDateFromString(Date *date, char *dateString);

void saveBinFlight(FILE *file, const Flight *pFlt);

Flight *loadBinFlight(FILE *file, AirportManager *pAptMgr);

void saveBinDate(FILE *file, const Date *pDate);

void loadBinDate(FILE *file, Date *pDate);


#endif //HW2_FLIGHT_H
