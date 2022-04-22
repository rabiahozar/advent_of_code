cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 14)

project(advent_of_code)

SET(HEADERS 
    advent.h 
    1/sonar_sweep.h
    2/dive.h
    3/life_support.h
)
SET(SOURCES
    main.cpp
    1/sonar_sweep.cpp
    2/dive.cpp
    3/life_support.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/
    ${CMAKE_SOURCE_DIR}/1
    ${CMAKE_SOURCE_DIR}/2
    ${CMAKE_SOURCE_DIR}/3
)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)