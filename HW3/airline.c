//
// Created by ordekalo on 12/05/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airline.h"
#include "functions.h"

const char *TypeString[NofTypes] = {"ATD", "DATE", "SPEED"};

int initAirline(Airline *pAirline) {
    pAirline->name = createDynStr("Airline Name");
    printf("Please Fleet Size:\n");
    scanf(" %d", &pAirline->fleetSize);

    printf("please enter sorting type:\n");
    for (int i = 0; i < NofTypes; ++i) {
        printf("enter %d for %s\n", i, TypeString[i]);
    }
    int type;
    scanf("%d", &type);
    pAirline->sortType = (SortType) type;

    pAirline->flightAmount = 0;
    pAirline->allFlights = (Flight **) malloc(sizeof(Flight *));
    if (!pAirline->allFlights) {
        //allocation error
        return 0;
    }
    return 1;
}

void printAirline(const Airline *pAirline) {
    printf("Airline %s has %d airplanes at her fleet with %d flight lines: (sorted by %s ascending)\n", pAirline->name,
           pAirline->fleetSize,
           pAirline->flightAmount, TypeString[pAirline->sortType]);

    generalArrayFunction(pAirline->allFlights, pAirline->flightAmount, sizeof(Flight *), printFlight);
}

void freeAirline(Airline *pAirline) {
    for (int i = 0; i < pAirline->flightAmount; ++i) {
        freeFlight(pAirline->allFlights[i]);
    }
    free(pAirline->allFlights);
    free(pAirline->name);
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

void saveBinAirline(const char *fName, const Airline *pAirline) {
    FILE *file = fopen(fName, "wb");
    if (!file) return;

    //fleet size write
    fwrite(&pAirline->fleetSize, sizeof(int), 1, file);
    //airline name length
    int airlineNameLen = (int) strlen(pAirline->name);
    fwrite(&airlineNameLen, sizeof(int), 1, file);
    //airline name write
    fwrite(pAirline->name, sizeof(char), airlineNameLen, file);
    //flight amount write
    fwrite(&pAirline->flightAmount, sizeof(int), 1, file);
    //sort type write
    int type = pAirline->sortType;
    fwrite(&type, sizeof(int), 1, file);

    //write flights
    for (int i = 0; i < pAirline->flightAmount; ++i) {
        saveBinFlight(file, pAirline->allFlights[i]);
    }

    fclose(file);
}

void readBinAirline(const char *fName, Airline *pAirline, AirportManager *pAptMgr) {
    FILE *file = fopen(fName, "rb");
    if (!file) return;

    printf("reading airline from: %s\n", fName);
    //fleet size read
    fread(&pAirline->fleetSize, sizeof(int), 1, file);
    printf("fleet size: %d\n", pAirline->fleetSize);
    //airline name length
    int airlineNameLen;
    fread(&airlineNameLen, sizeof(int), 1, file);
    printf("airline name length: %d\n", airlineNameLen);

    //airline name read
    pAirline->name = (char *) malloc(sizeof(char) * airlineNameLen);
    fread(pAirline->name, sizeof(char), airlineNameLen, file);
    printf("airline name: %s\n", pAirline->name);

    //flight amount read
    fread(&pAirline->flightAmount, sizeof(int), 1, file);
    printf("flight amount: %d\n", pAirline->flightAmount);

    //sort type read
    fread(&pAirline->sortType, sizeof(int), 1, file);
    printf("sorting type: %s\n", TypeString[pAirline->sortType]);

    pAirline->allFlights = (Flight **) malloc(sizeof(Flight *) * (pAirline->flightAmount));
    if (!pAirline->allFlights) return;

    //write flights
    for (int i = 0; i < pAirline->flightAmount; ++i) {
        pAirline->allFlights[i] = loadBinFlight(file, pAptMgr);
    }

    fclose(file);
}
