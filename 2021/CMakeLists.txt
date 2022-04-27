cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 14)

project(advent_of_code)

SET(HEADERS 
    include/advent.h 
    include/helper.h 
    1/sonar_sweep.h
    2/dive.h
    3/life_support.h
    4/bingo.h
    5/hypothermal.h
    6/lanternfish.h
    )
SET(SOURCES
    main.cpp
    1/sonar_sweep.cpp
    2/dive.cpp
    3/life_support.cpp
    4/bingo.cpp
    5/hypothermal.cpp
    6/lanternfish.cpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/1
    ${CMAKE_SOURCE_DIR}/2
    ${CMAKE_SOURCE_DIR}/3
    ${CMAKE_SOURCE_DIR}/4
    ${CMAKE_SOURCE_DIR}/5
    ${CMAKE_SOURCE_DIR}/6
    )

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)