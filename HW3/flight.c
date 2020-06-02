//
// Created by ordekalo on 12/05/2020.
//

#include "flight.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"


void printFlight(void *pFlt) {
    Flight *pFlight = *(Flight **) pFlt;
    printf("\nFlight from %3s to %3s in %d:00 at %d/%d/%d\n", pFlight->pAptFrom->code, pFlight->pAptDest->code,
           pFlight->ATD,
           pFlight->date.day, pFlight->date.month, pFlight->date.year);
    printf("Average speed: %lf mph, Distance: %lf miles\n", pFlight->avgSpeed,
           calculateDistanceA2A(pFlight->pAptFrom, pFlight->pAptDest));

    double flightHours = calculateFlightTime(pFlight);
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

    char dateString[20];
    do {
        printf("Please Enter Date Of Departure: (dd/mm/yyyy Format Only!)\n");
        scanf(" %[^'\n']s", dateString);
    } while (!validateDateFormat(dateString));
    loadDateFromString(&pFlt->date, dateString);

    do {
        printf("Please Enter Average Speed Of Flight:\n");
        scanf(" %lf", &pFlt->avgSpeed);
    } while (pFlt->avgSpeed > 1000 || pFlt->avgSpeed < 0);
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

void loadDateFromString(Date *date, char *dateString) {
    if (!validateDateFormat(dateString)) {
        printf("Invalid Date Format\n");
        return;
    }
    int day = charToInt(dateString[0]) * 10 + charToInt(dateString[1]);
    int month = charToInt(dateString[3]) * 10 + charToInt(dateString[4]);
    int year = charToInt(dateString[6]) * 1000 + charToInt(dateString[7]) * 100 + charToInt(dateString[8]) * 10 +
               charToInt(dateString[9]);
    date->day = day;
    date->month = month;
    date->year = year;
}

void saveBinFlight(FILE *file, const Flight *pFlt) {
    //Source IATA write
    fwrite(pFlt->pAptFrom->name, sizeof(char), strlen(pFlt->pAptFrom->name), file);
    //Destination IATA write
    fwrite(pFlt->pAptDest->name, sizeof(char), strlen(pFlt->pAptDest->name), file);
    //Flight Hour write
    fwrite(&pFlt->ATD, sizeof(int), 1, file);
    //rep stringDate length write
    int stringLength = 11;
    fwrite(&stringLength, sizeof(int), 1, file);
    //Date write
    saveBinDate(file, &pFlt->date);
    //AVG Speed write
    fwrite(&pFlt->avgSpeed, sizeof(double), 1, file);
}

Flight *loadBinFlight(FILE *file, AirportManager *pAptMgr) {
    Flight *pFlt = (Flight *) malloc(sizeof(Flight));
    if (!pFlt) return NULL;

    //Source IATA read
    char *sourceIATA;
    fread(sourceIATA, sizeof(char), IATA_LENGTH + 1, file);
    pFlt->pAptFrom = getAirport(pAptMgr, sourceIATA);
    if (!pFlt->pAptFrom) return NULL;

    //Destination IATA read
    char *destIATA;
    fread(destIATA, sizeof(char), IATA_LENGTH + 1, file);
    pFlt->pAptDest = getAirport(pAptMgr, destIATA);
    if (!pFlt->pAptDest) return NULL;

    //Flight Hour read
    fread(&pFlt->ATD, sizeof(int), 1, file);
    //rep stringDate length read
    int stringLength;
    fread(&stringLength, sizeof(int), 1, file);
    //Date read
    loadBinDate(file, &pFlt->date);
    //AVG Speed read
    fread(&pFlt->avgSpeed, sizeof(double), 1, file);

    return pFlt;
}


void saveBinDate(FILE *file, const Date *pDate) {
    //day write
    fwrite(&pDate->day, sizeof(int), 1, file);
    //month write
    fwrite(&pDate->month, sizeof(int), 1, file);
    //year write
    fwrite(&pDate->year, sizeof(int), 1, file);
}

void loadBinDate(FILE *file, Date *pDate) {
    //day read
    fread(&pDate->day, sizeof(int), 1, file);
    //month read
    fread(&pDate->month, sizeof(int), 1, file);
    //year read
    fread(&pDate->year, sizeof(int), 1, file);
}

