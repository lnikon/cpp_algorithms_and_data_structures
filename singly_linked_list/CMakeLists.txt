project(singly_linked_list C CXX)

if(UNIX)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O2 -std=c++17 -pthread -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif(UNIX)

add_library(singly_linked_list include/singly_linked_list.hpp)
set_target_properties(singly_linked_list PROPERTIES LINKER_LANGUAGE CXX)
install(TARGETS singly_linked_list
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
