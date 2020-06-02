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
        )

target_link_libraries(HW3 m)