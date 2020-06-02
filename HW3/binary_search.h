//
// Created by ordekalo on 02/06/2020.
//

#ifndef HW3_BINARY_SEARCH_H
#define HW3_BINARY_SEARCH_H

#include "flight.h"

Flight *findFlightByATD(Flight **flightArr, int size, int atd);

Flight *findFlightBySpeed(Flight **flightArr, int size, double speed);

Flight *findFlightByDate(Flight **flightArr, int size, char *dateString);


#endif //HW3_BINARY_SEARCH_H
