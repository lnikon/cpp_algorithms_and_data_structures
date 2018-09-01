#include <iostream>
#include <string>

#include "dynamic_array.hpp"
#include "singly_linked_list.hpp"

int main() {
    std::size_t cap1 = 12;
    dynamic_array<std::string> da1(cap1);

    dynamic_array<std::string> da2(std::move(da1));

    
    return 0;
}
