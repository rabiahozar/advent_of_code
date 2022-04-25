cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 17)

project(hypothermal)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sandbox.txt ${CMAKE_BINARY_DIR}/day_5_input.txt COPYONLY)
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day_5_input.txt COPYONLY)