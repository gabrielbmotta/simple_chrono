cmake_minimum_required(VERSION 3.0)
project(chrono_test)

set(CXX_STANDARD 11)

add_library(${PROJECT_NAME} simple_chrono.h simple_chrono.cpp)

add_executable("${PROJECT_NAME}_cpp" test.cpp)
target_link_libraries("${PROJECT_NAME}_cpp" ${PROJECT_NAME})

add_executable("${PROJECT_NAME}_c" test.c)
target_link_libraries("${PROJECT_NAME}_c" ${PROJECT_NAME})
