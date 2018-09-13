#include <iostream>
#include <string>

#include "dynamic_array.hpp"

int main() {
    dynamic_array<int> da1;
    da1.push_back(4);
    da1.push_back(5);
    da1.push_back(6);
    da1.push_back(7);
    da1.push_back(8);

    //std::cout << std::boolalpha << (da1.size() == da1.capacity()) << std::endl;
    
    return 0;
}
