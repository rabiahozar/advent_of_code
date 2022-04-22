cmake_minimum_required(VERSION 3.13.1)
set (CMAKE_CXX_STANDARD 17)

project(diagnostic)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day_3_input.txt COPYONLY)