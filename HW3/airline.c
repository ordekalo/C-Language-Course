//
// Created by ordekalo on 12/05/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "airline.h"


int initAirline(Airline *pAirline) {

    pAirline->name = createDynStr("Airline Name");
    printf("Please Fleet Size:\n");
    scanf(" %d", &pAirline->fleetSize);

    pAirline->flightAmount = 0;
    pAirline->allFlights = (Flight **) malloc(sizeof(Flight *));
    if (!pAirline->allFlights) {
        //allocation error
        return 0;
    }
    return 1;
}

void printAirline(const Airline *pAirline) {
    printf("Airline %s has %d airplanes at her fleet with %d flight lines:\n", pAirline->name, pAirline->fleetSize,
           pAirline->flightAmount);

    for (int i = 0; i < pAirline->flightAmount; ++i) {
        printFlight(pAirline->allFlights[i]);

    }
}

void freeAirline(Airline *pAirline) {
    for (int i = 0; i < pAirline->flightAmount; ++i) {
        freeFlight(pAirline->allFlights[i]);
    }
    free(pAirline->allFlights);
}

int addFlightToAirline(Airline *pAirline, Flight *pFlt) {
    pAirline->allFlights = (Flight **) realloc(pAirline->allFlights, sizeof(Flight *) * (pAirline->flightAmount + 1));
    if (!pAirline->allFlights) {
        //reallocation error
        return 0;
    }
    pAirline->allFlights[pAirline->flightAmount] = pFlt;
    pAirline->flightAmount++;
    return 1;
}

void printFlightCountInAirlineByCodes(const Airline *pAirline, const char *fromCode, const char *destCode) {
    int count = countFlightsByCodes(pAirline->allFlights, pAirline->flightAmount, fromCode, destCode);
    printf("There Are %d Flights From %s To %s At %s Airline\n", count, fromCode, destCode, pAirline->name);
}
