cmake_minimum_required(VERSION 3.10)


if(COMMAND cmake_policy)
     cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(TicTacToe)
set(BINARY_NAME ${CMAKE_PROJECT_NAME})

include("${${PROJECT_NAME}_SOURCE_DIR}/globalVariables.cmake")
include_directories(${INCLUDES})

link_directories(${LIBS})



if (USE_GCOV)
  set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
  set(GCC_COVERAGE_LINK_FLAGS    "-lgcov")
endif()
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

SET(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
add_library(${CMAKE_PROJECT_NAME}_lib gtest.cpp)
add_executable(unit_test gtest.cpp)
add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(unit_test ${CMAKE_PROJECT_NAME}_lib gtest gtest_main pthread)


