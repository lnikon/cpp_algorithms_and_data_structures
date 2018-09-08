#include <iostream>
#include <string>

#include "dynamic_array.hpp"
#include "singly_linked_list.hpp"
#include "stack.hpp"

int main() {
    std::size_t cap1 = 12;
    dynamic_array<std::string> da1(cap1);

    dynamic_array<std::string> da2(std::move(da1));

    dynamic_array<std::string> da3(da2);

    da2.print_buffer_address_size_capacity();
    da3.print_buffer_address_size_capacity();
    
    return 0;
}
