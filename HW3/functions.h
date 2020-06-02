//
// Created by ordekalo on 18/05/2020.
//

#ifndef HW2_FUNCTIONS_H
#define HW2_FUNCTIONS_H

#include <stdio.h>

#define EARTH_RADIUS 3950 //in miles

double degToRad(double degrees);

double distanceBetweenCoordinates(double lat1, double lon1, double lat2, double lon2);

int validateLatitude(double latitude);

int validateLongitude(double longitude);

int charToInt(char c);

char intToChar(int num);

void generalArrayFunction(void *arr, int size, int typeSize, void (*func)(void *));

char *getStrExactLength(FILE *file);

char *myGets(char *buffer, int size, FILE *f);

#endif //HW2_FUNCTIONS_H
