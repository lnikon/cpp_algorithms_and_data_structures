#include <iostream>
#include <string>

#include "dynamic_array.hpp"

int main() {
    dynamic_array<int> da1;

    std::size_t sz = 2048;
    for(std::size_t i = 0; i < sz; i++)
    {
        da1.push_back(i);
    }

    for(std::size_t i = 0; i < sz; i++)
    {
        std::cout << da1.pop_back() << ' ';
    }
    std::cout << '\n';


//    da1.print_internal_buffer();

//    auto val = da1.pop_back();
//
//    da1.print_internal_buffer();
    
    return 0;
}
