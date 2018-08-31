project(driver C CXX)
add_executable(driver src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/dynamic_array/include)
include_directories(${CMAKE_SOURCE_DIR}/singly_linked_list/include)

target_link_libraries(driver dynamic_array singly_linked_list)

set_target_properties(driver PROPERTIES LINKER_LANGUAGE CXX)
install(TARGETS driver RUNTIME DESTINATION bin)
