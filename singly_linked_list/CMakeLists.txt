cmake_minimum_required(VERSION 3.0.0)
project(list VERSION 0.1.0)

include(CTest)
enable_testing()

if(UNIX)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O2 -std=c++17 -pthread -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif(UNIX)

set(LIB_LOCAL "include/")
include_directories(${LIB_LOCAL})

file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.h")

add_executable(llist ${SOURCES} ${INCLUDES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
