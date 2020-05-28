//
// Created by ordekalo on 12/05/2020.
//

#include "airport_manager.h"
#include <stdlib.h>
#include <stdio.h>

int initAirportManager(AirportManager *pAptMgr) {
    pAptMgr->amount = 0;
    pAptMgr->allAirports = (Airport *) malloc(sizeof(Airport));
    if (!pAptMgr->allAirports) {
        //allocation error
        return 0;
    }
    addAllAirports(pAptMgr);
    return 1;
}

int addAllAirports(AirportManager *pAptMgr) {
    char option;
    int flag = 1;
    while (flag) {
        printf("Do You Want To Enter An Airport? y/n \n");
        scanf(" %c", &option); //added space before %c to avoid error

        if (option == 'y' || option == 'Y') {
            Airport airport;
            initAirport(&airport);
            flag = addAirport(pAptMgr, &airport);
        } else {
            flag = 0;
        }
    }
    return 1;
}

void printAirportManager(const AirportManager *pAptMgr) {
    printf("Airport Manager has %d Airports:\n", pAptMgr->amount);
    for (int i = 0; i < pAptMgr->amount; ++i) {
        printAirport(&pAptMgr->allAirports[i]);
    }
}

void freeAirportManager(AirportManager *pAptMgr) {
    for (int i = 0; i < pAptMgr->amount; ++i) {
        freeAirport(&pAptMgr->allAirports[i]);
    }
    free(pAptMgr->allAirports);
}

int addAirport(AirportManager *pAptMgr, const Airport *pApt) {
    if (getAirport(pAptMgr, pApt->code)) {
        printf("Airport IATA %s already exist at Airport Manager\n", pApt->code);
        return 0;
    }
    pAptMgr->allAirports = (Airport *) realloc(pAptMgr->allAirports, sizeof(Airport) * (pAptMgr->amount + 1));
    if (!pAptMgr->allAirports) {
        //reallocation error
        return 0;
    }
    pAptMgr->allAirports[pAptMgr->amount] = *pApt;
    pAptMgr->amount++;
    return 1;
}

Airport *getAirport(const AirportManager *pAptMgr, const char *code) {
    if (!validateCode(code)) {
        return NULL;
    }
    for (int i = 0; i < pAptMgr->amount; ++i) {
        if (validateAirportByAirportCode(&pAptMgr->allAirports[i], code)) {
            return &pAptMgr->allAirports[i];
        }
    }
    return NULL;
}

int validateCodeExists(const AirportManager *pAptMgr, const char *code) {
    if(getAirport(pAptMgr,code)){
        return 1;
    }
    return 0;
}
