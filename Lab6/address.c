//
// Created by ordekalo on 19/04/2020.
//
#include <stdio.h>
#include "address.h"

void initAddress(Address *pAddress) {
    printf("please enter street name:\n");
    scanf("%s", pAddress->streetName);
    printf("please enter house number:\n");
    scanf("%d", &pAddress->houseNumber);
}

void printAddress(const Address *pAddress) {
    printf("Address[streetName: %s, houseNumber: %d]",
           pAddress->streetName, pAddress->houseNumber);
}
