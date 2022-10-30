cmake_minimum_required (VERSION 3.0)

project ("Project_SDL1")

set (CMAKE_CXX_STANDARD 17)

file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/media DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory ("Project_SDL1")
