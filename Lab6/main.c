#define MAX_PERSONS 1

#include "person.h"

int main() {
    Person personArray[MAX_PERSONS];
    initPersonArray(personArray, MAX_PERSONS);
    printPersonArray(personArray, MAX_PERSONS);
    return 0;
}
