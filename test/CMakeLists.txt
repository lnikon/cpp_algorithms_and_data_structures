cmake_minimum_required(VERSION 3.2)
project(test_runner)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp src/dynamic_array_test.cpp)

add_subdirectory(lib/googletest)

include_directories(${DYNAMIC_ARRAY_INCLUDE_DIR})
include_directories(${SINGLY_LINKED_LIST_INCLUDE_DIR})
include_directories(${STACK_INCLUDE_DIR})
include_directories(lib/googletest/googletest/include)

add_executable(test_runner ${SOURCE_FILES})
target_link_libraries(test_runner dynamic_array singly_linked_list stack gtest)

install(TARGETS test_runner DESTINATION bin)
