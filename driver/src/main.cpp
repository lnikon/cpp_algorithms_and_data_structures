#include <iostream>
#include <string>

#include "dynamic_array.hpp"

int main() {
    dynamic_array<int> da1;
    da1.push_front(3);

    da1.print_internal_buffer();

    auto val = da1.pop_back();

    da1.print_internal_buffer();

    //std::cout << std::boolalpha << (da1.size() == da1.capacity()) << std::endl;
    
    return 0;
}
