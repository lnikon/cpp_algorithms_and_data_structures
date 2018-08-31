project(dynamic_array C CXX)

if(UNIX)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O2 -std=c++17 -pthread -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif(UNIX)

add_library(dynamic_array include/dynamic_array.hpp)
set_target_properties(dynamic_array PROPERTIES LINKER_LANGUAGE CXX)
install(TARGETS dynamic_array
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
