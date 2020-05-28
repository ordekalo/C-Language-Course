//
// Created by ordekalo on 12/05/2020.
//

#ifndef HW2_AIRPORT_MANAGER_H
#define HW2_AIRPORT_MANAGER_H

#include "airport.h"

typedef struct {
    Airport *allAirports;
    int amount;
} AirportManager;

int initAirportManager(AirportManager *pAptMgr);

void printAirportManager(const AirportManager *pAptMgr);

void freeAirportManager(AirportManager *pAptMgr);

int addAirport(AirportManager *pAptMgr, const Airport *pApt);

int addAllAirports(AirportManager *pAptMgr);

int validateCodeExists(const AirportManager *pAptMgr, const char *code);

Airport *getAirport(const AirportManager *pAptMgr, const char *code);

#endif //HW2_AIRPORT_MANAGER_H
