#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "airline.h"
#include "compare.h"
#include "binary_search.h"

#define ADD_FLIGHT 1
#define ADD_AIRPORT 2
#define AIRLINE_INFO 3
#define AIRPORT_MANAGER_INFO 4
#define FLIGHTS_BETWEEN_DEST_COUNT 5
#define SORT_FLIGHTS 6
#define BINARY_SEARCH_FLIGHT 7
#define QUIT 8

int menu();


int menu() {
    int option;
    printf("\n\n");
    printf("Please choose one of the following options\n");
    printf("%d - Add Flight\n", ADD_FLIGHT);
    printf("%d - Add Airport\n", ADD_AIRPORT);
    printf("%d - Print Airline Info\n", AIRLINE_INFO);
    printf("%d - Print Airport Manager Info\n", AIRPORT_MANAGER_INFO);
    printf("%d - Print Flights Between Destinations Count\n", FLIGHTS_BETWEEN_DEST_COUNT);
    printf("%d - Quit\n", QUIT);
    scanf(" %d", &option);
    return option;
}

int main() {
    Airline airline;
    initAirline(&airline);

    AirportManager aptMgr;
    initAirportManager(&aptMgr);

    int option;
    int stop = 0;
    srand((unsigned) time(NULL));
    do {
        Flight *pFlt = NULL;
        Airport airport;
        char fromCode[100], destCode[100];

        option = menu();
        switch (option) {
            case ADD_FLIGHT:
                pFlt = (Flight *) malloc(sizeof(Flight));
                if (!pFlt) { //allocation error
                    return 0;
                }
                initFlight(pFlt, &aptMgr);
                addFlightToAirline(&airline, pFlt);
                break;
            case ADD_AIRPORT:
                initAirport(&airport);
                addAirport(&aptMgr, &airport);
                break;
            case AIRLINE_INFO:
                printAirline(&airline);
                break;
            case AIRPORT_MANAGER_INFO:
                printAirportManager(&aptMgr);
                break;
            case FLIGHTS_BETWEEN_DEST_COUNT:
                scanCodes(fromCode, destCode);
                printFlightCountInAirlineByCodes(&airline, fromCode, destCode);
                break;
            case SORT_FLIGHTS:
                //sort by type
                switch (airline.sortType) {
                    case ATD:
                        qsort(airline.allFlights, airline.flightAmount, sizeof(Flight *), compareByATD);
                        break;
                    case DATE:
                        qsort(airline.allFlights, airline.flightAmount, sizeof(Flight *), compareByDate);
                        break;
                    case SPEED:
                        qsort(airline.allFlights, airline.flightAmount, sizeof(Flight *), compareBySpeed);
                        break;
                    case NofTypes:
                        break;
                }
                break;
            case BINARY_SEARCH_FLIGHT:
                switch (airline.sortType) {
                    int atd;
                    char dateString[20];
                    double speed;

                    case ATD:
                        do {
                            printf("Please Enter Actual Time Of Departure: (23-0)\n");
                            scanf(" %d", &atd);
                        } while (atd > 23 || atd < 0);
                        pFlt = findFlightByATD(airline.allFlights, airline.flightAmount, atd);
                        break;
                    case DATE:
                        do {
                            printf("Please Enter Date Of Departure: (dd/mm/yyyy Format Only!)\n");
                            scanf(" %[^'\n']s", dateString);
                        } while (!validateDateFormat(dateString));
                        pFlt = findFlightByDate(airline.allFlights, airline.flightAmount, dateString);
                        break;
                    case SPEED:
                        do {
                            printf("Please Enter Average Speed Of Flight:\n");
                            scanf(" %lf", &speed);
                        } while (speed > 1000 || speed < 0);
                        pFlt = findFlightBySpeed(airline.allFlights, airline.flightAmount, speed);
                        break;
                }
                if (pFlt) printFlight(pFlt);
                break;
            case QUIT:
                printf("Bye bye\n");
                freeAirline(&airline);
                freeAirportManager(&aptMgr);
                stop = 1;
                break;
            default:
                printf("Wrong option\n");
                break;
        }
    } while (!stop);
    return 1;
}