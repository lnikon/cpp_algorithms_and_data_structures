#include <iostream>

#include "dynamic_array.h"

int main() {
	std::cout << "Hello from Dynamic Array main\n";

    std::size_t capacity = 12;

    dynamic_array<int> da(capacity);
    da.print_buffer_address_size_capacity();    

    dynamic_array<int> da1(da);
    da1.print_buffer_address_size_capacity();    

	return 0;
}
