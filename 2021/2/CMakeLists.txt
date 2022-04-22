cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 14)

project(dive)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day_2_input.txt COPYONLY)