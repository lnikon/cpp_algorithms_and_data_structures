project(stack C CXX)

link_directories("../")

if(UNIX)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O2 -std=c++17 -pthread -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif(UNIX)

add_library(stack include/stack.hpp)
set_target_properties(stack PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(stack dynamic_array singly_linked_list)
install(TARGETS stack
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
