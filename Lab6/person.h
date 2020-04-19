//
// Created by ordekalo on 19/04/2020.
//

#ifndef LAB6_PERSON_H
#define LAB6_PERSON_H

#include "address.h"

typedef enum {
    Man, Woman, Boy, Girl, NofTypes
} PersonType;

const char *TypeString[NofTypes];

typedef struct {
    char name[MAX_NUM];
    Address address;
    PersonType personType;
} Person;

void initPerson(Person *pPerson);

void printPerson(const Person *pPerson);

void initPersonArray(Person *personArray, int size);

void printPersonArray(const Person *personArray, int size);

#endif //LAB6_PERSON_H
