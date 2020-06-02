//
// Created by ordekalo on 12/05/2020.
//

#ifndef HW2_AIRPORT_H
#define HW2_AIRPORT_H

#define IATA_LENGTH 3

#include <stdio.h>

typedef struct {
    char *name;
    char *country;
    char code[IATA_LENGTH];
    double latitude;
    double longitude;
} Airport;

char *createDynStr(const char *msg);

void initAirport(Airport *pApt);

void printAirport(const Airport *pApt);

void freeAirport(void *pApt);

int validateCode(const char *code);

int compareAirports(const Airport *pApt1, const Airport *pApt2); //compare by code

int validateAirportByAirportCode(const Airport *pAirport, const char *code);

double calculateDistanceA2A(const Airport *pApt1, const Airport *pApt2);

void airportNameFormatter(char *name);

void saveAirport(FILE *file, const Airport *pApt);

void readAirport(FILE *file, Airport *pApt);

#endif //HW2_AIRPORT_H
