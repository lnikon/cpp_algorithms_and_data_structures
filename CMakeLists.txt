cmake_minimum_required(VERSION 3.0.0)
project(my_stl)

# Setup include directories for easy use
set(DYNAMIC_ARRAY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dynamic_array/include)
set(SINGLY_LINKED_LIST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/singly_linked_list/include)
set(STACK_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/stack/include)


add_subdirectory(driver)
add_subdirectory(singly_linked_list)
add_subdirectory(dynamic_array)
add_subdirectory(stack)

add_subdirectory(test)
