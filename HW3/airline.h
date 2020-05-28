//
// Created by ordekalo on 12/05/2020.
//

#ifndef HW2_AIRLINE_H
#define HW2_AIRLINE_H

#include "flight.h"

typedef struct {
    char *name;
    int fleetSize;
    int flightAmount;
    Flight **allFlights;
} Airline;

int initAirline(Airline *pAirline);

void printAirline(const Airline *pAirline);

void freeAirline(Airline *pAirline);

int addFlightToAirline(Airline *pAirline, Flight *pFlt);

void printFlightCountInAirlineByCodes(const Airline *pAirline, const char *fromCode, const char *destCode);

#endif //HW2_AIRLINE_H
