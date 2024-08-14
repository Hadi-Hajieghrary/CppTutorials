cmake_minimum_required(VERSION 3.10)
project(create_shared_library VERSION 1.0
                              DESCRIPTION "This project demonstrates the procedure to create Dynamic libraries and differences with the Static Library"
                              LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(my_static_library STATIC src/my_static_library.cpp)
target_include_directories(my_static_library PRIVATE ${CMAKE_SOURCE_DIR}/include)

set(SHARED_LIB_PATH ${CMAKE_BINARY_DIR})
configure_file(main.cpp.in ${CMAKE_SOURCE_DIR}/main.cpp)

add_library(my_shared_library SHARED src/my_shared_library.cpp)
target_include_directories(my_shared_library PRIVATE ${CMAKE_SOURCE_DIR}/include)


add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(main my_static_library)

