cmake_minimum_required(VERSION 3.10)

project(data_structure VERSION 1.0.0
                        DESCRIPTION "Learning the Data Structure in C++"
                        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(rational ${CMAKE_SOURCE_DIR}/src/rational.cpp)
target_include_directories(rational PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
