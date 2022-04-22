cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 14)

project(dive)

add_executable(${PROJECT_NAME} puzzle.cpp)

configure_file(${CMAKE_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)