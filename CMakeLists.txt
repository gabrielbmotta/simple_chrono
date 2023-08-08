cmake_minimum_required(VERSION 3.0)
project(simple_chrono)

set(CXX_STANDARD 11)

option(BUILD_SIMPLE_CHRONO_TESTS "Build C and C++ test applications." OFF)

add_library(${PROJECT_NAME} simple_chrono.h simple_chrono.cpp)

if(BUILD_SIMPLE_CHRONO_TESTS)
  add_executable("${PROJECT_NAME}_cpp" test.cpp)
  target_link_libraries("${PROJECT_NAME}_cpp" ${PROJECT_NAME})

  add_executable("${PROJECT_NAME}_c" test.c)
  target_link_libraries("${PROJECT_NAME}_c" ${PROJECT_NAME})
endif()

