//
// Created by ordekalo on 19/04/2020.
//

#ifndef LAB6_ADDRESS_H
#define LAB6_ADDRESS_H
#define MAX_NUM 20

typedef struct {
    char streetName[MAX_NUM];
    int houseNumber;
} Address;

void initAddress(Address *pAddress);

void printAddress(const Address *pAddress);

#endif //LAB6_ADDRESS_H
