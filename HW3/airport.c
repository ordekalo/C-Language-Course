//
// Created by ordekalo on 12/05/2020.
//
#include "airport.h"
#include <string.h>
#include "stdio.h"
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

char *createDynStr(const char *msg) {
    char *str = NULL;
    char temp[100];
    printf("Please Enter %s:\n", msg);
    scanf(" %[^'\n']s", temp); //added space before % to avoid error

    str = (char *) malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(str, temp);

    return str;
}

void airportNameFormatter(char *name) {
    int counter = 0;
    int whiteCounter = 0;
    int charInWord = 0;
    for (int i = 0; name[i]; i++) {
        if (!isspace(name[i])) {
            name[counter] = name[i];
            whiteCounter = 0;
            charInWord++;
            if (charInWord == 1) {
                name[counter] = toupper(name[i]);
            }
            counter++;
        } else {
            charInWord = 0;
            whiteCounter++;
            if (whiteCounter == 1) {
                name[counter++] = name[i];
            }
        }
    }
    name[counter] = 0;
}

void initAirport(Airport *pApt) {
    pApt->name = createDynStr("Airport Name");
    airportNameFormatter(pApt->name);

    pApt->country = createDynStr("Airport Country");

    do {
        printf("Please Enter Airport IATA Code (3 Characters Only, UpperCase):\n");
        scanf(" %[^'\n']s", pApt->code); //added space before % to avoid error
    } while (!validateCode(pApt->code));

    do {
        printf("Please Enter Airport Latitude:\n");
        scanf(" %lf", &pApt->latitude); //added space before % to avoid error
    } while (!validateLatitude(pApt->latitude));

    do {
        printf("Please Enter Airport Longitude:\n");
        scanf(" %lf", &pApt->longitude); //added space before % to avoid error
    } while (!validateLongitude(pApt->longitude));
}

void printAirport(const Airport *pApt) {
    printf("Airport:[name: %s, country: %s, code: %s, latitude: %lf, longitude: %lf]\n",
           pApt->name,
           pApt->country,
           pApt->code,
           pApt->latitude,
           pApt->longitude);
}

void freeAirport(void *pApt) {
    Airport *pAirport = (Airport *) pApt;
    free(pAirport->name);
    free(pAirport->country);
}

int compareAirports(const Airport *pApt1, const Airport *pApt2) {
    //comparison by airport codes
    return validateAirportByAirportCode(pApt1, pApt2->code);
}

int validateAirportByAirportCode(const Airport *pAirport, const char *code) {
    if (!validateCode(code)) {
        return 0;
    }
    //comparison by given code and pAirport code
    return !strcmp(pAirport->code, code);
}

double calculateDistanceA2A(const Airport *pApt1, const Airport *pApt2) {
    if (compareAirports(pApt1, pApt2)) { //check not the same airport
        return 0;
    } else {
        return distanceBetweenCoordinates(pApt1->latitude, pApt1->longitude, pApt2->latitude, pApt2->longitude);
    }
}

int validateCode(const char *code) {
    if (strlen(code) != IATA_LENGTH) {
        printf("IATA Code Should Be 3 Letters, not %lu .\n", strlen(code));
        return 0;
    }
    for (int i = 0; i < IATA_LENGTH; ++i) {
        if (islower(code[i])) {
            printf("%s is invalid IATA code\n", code);
            return 0;
        }
    }
    return 1;
}

void saveAirport(FILE *file, const Airport *pApt) {
    fprintf(file, "%s\n%s\n%s\n%lf %lf\n", pApt->name, pApt->country, pApt->code, pApt->longitude, pApt->latitude);
}

void readAirport(FILE *file, Airport *pApt) {
    fscanf(file, "%s\n%s\n%s\n%lf %lf\n", pApt->name, pApt->country, pApt->code, &pApt->longitude, &pApt->latitude);
    //read and allocate name
    char *name = (char *) malloc((strlen(pApt->name) + 1) * sizeof(char));
    if (!name) return;
    strcpy(name, pApt->name);
    pApt->name = name;
    //read and allocate country_name
    char *country = (char *) malloc((strlen(pApt->country) + 1) * sizeof(char));
    if (!country) return;
    strcpy(country, pApt->country);
    pApt->country = country;
}

