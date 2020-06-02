//
// Created by ordekalo on 12/05/2020.
//

#ifndef HW2_AIRLINE_H
#define HW2_AIRLINE_H

#include <stdio.h>
#include "flight.h"

typedef enum {
    HOUR, DATE, SPEED, NofTypes
} SortType;

const char *TypeString[NofTypes];

typedef struct {
    char *name;
    int fleetSize;
    int flightAmount;
    Flight **allFlights;
    SortType sortType;
} Airline;

int initAirline(Airline *pAirline);

void printAirline(const Airline *pAirline);

void freeAirline(Airline *pAirline);

int addFlightToAirline(Airline *pAirline, Flight *pFlt);

void printFlightCountInAirlineByCodes(const Airline *pAirline, const char *fromCode, const char *destCode);

void saveBinAirline(const char *fName, const Airline *pAirline);

void loadBinAirline(const char *fName, Airline *pAirline, AirportManager *pAptMgr);

#endif //HW2_AIRLINE_H
