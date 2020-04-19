//
// Created by ordekalo on 19/04/2020.
//

#include "person.h"
#include <stdio.h>

const char *TypeString[NofTypes] = {"Man", "Woman", "Boy", "Girl"};

void initPerson(Person *pPerson) {
    printf("please enter person name:\n");
    scanf("%s", pPerson->name);
    printf("please enter person type:\n");
    for (int i = 0; i < NofTypes; ++i) {
        printf("enter %d for %s\n", i, TypeString[i]);
    }
    int type;
    scanf("%d", &type);
    pPerson->personType = (PersonType) type;
    initAddress(&pPerson->address);
}

void printPerson(const Person *pPerson) {
    printf("Person[name: %s, personType: %s, address: ",
           pPerson->name, TypeString[pPerson->personType]);
    printAddress(&pPerson->address);
    printf("]\n");
}

void initPersonArray(Person *personArray, int size) {
    for (int i = 0; i < size; ++i) {
        initPerson(personArray);
        personArray++;
    }
}

void printPersonArray(const Person *personArray, int size) {
    for (int i = 0; i < size; ++i) {
        printPerson(personArray);
        personArray++;
    }
}