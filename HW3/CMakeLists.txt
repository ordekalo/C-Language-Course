cmake_minimum_required(VERSION 3.16)
project(HW3 C)

set(CMAKE_C_STANDARD 99)

add_executable(HW3
        main.c
        airline.c airline.h
        airport_manager.c airport_manager.h
        flight.c flight.h
        airport.c airport.h
        functions.c functions.h
        compare.c compare.h binary_search.c binary_search.h)

target_link_libraries(HW3 m)