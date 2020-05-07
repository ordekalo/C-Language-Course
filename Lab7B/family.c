//
// Created by ordekalo on 06/05/2020.
//
#include "family.h"

char *createDynStr(const char *msg) {
    char *str = NULL;
    char temp[100];
    printf("Enter %s:\n", msg);
    scanf("%s", temp);

    str = (char *) malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(str, temp);

    return str;
}

int initFamily(Family *theFamily) {
    theFamily->name = createDynStr("family name");
    if (!theFamily->name) { //allocation did not succeed.
        return 0;
    }
    printf("Enter num of people:\n");
    scanf("%d", &(theFamily->numOfPeople));

    return 1;
}

void printFamily(const Family *theFamily) {
    printf("Family %s has %d peoples\n", theFamily->name, theFamily->numOfPeople);
}

void freeFamily(Family *theFamily) {
    free(theFamily->name);
}