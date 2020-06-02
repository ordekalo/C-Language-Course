//
// Created by ordekalo on 18/05/2020.
//

#include "functions.h"
#include <math.h>
#include <stdio.h>

double degToRad(double degrees) {
    //conversion between degrees to radians
    return degrees * (M_PI / 180);
}

double distanceBetweenCoordinates(double lat1, double lon1, double lat2, double lon2) {
    //deltas
    double deltaLat = degToRad(lat2 - lat1);
    double deltaLon = degToRad(lon2 - lon1);
    //conversion to radians
    double radLat1 = degToRad(lat1);
    double radLat2 = degToRad(lat2);
    //proportion calculation
    double a = pow(sin(deltaLat / 2), 2) + pow(sin(deltaLon / 2), 2) * cos(radLat1) * cos(radLat2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    //distance in miles
    return EARTH_RADIUS * c;
}

int validateLatitude(double latitude) {
    int flag = -90.0 <= latitude && latitude <= 90.0;
    if (!flag) {
        printf("%lf is Invalid Latitude Value.\n", latitude);
    }
    return flag;
}

int validateLongitude(double longitude) {
    int flag = -180.0 <= longitude && longitude <= 180.0;
    if (!flag) {
        printf("%lf is Invalid Longitude Value.\n", longitude);
    }
    return flag;
}

int charToInt(char c) {
    return c - '0';
}

char intToChar(int num) {
    return (char) (num + '0');
}

void generalArrayFunction(void *arr, int size, int typeSize, void (*func)(void *)) {
    for (int i = 0; i < size; ++i) {
        func((char *) arr + i * typeSize);
    }
}
