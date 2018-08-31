#include <iostream>
#include <string>

#include "dynamic_array.hpp"
#include "singly_linked_list.hpp"

int main() {
    SinglyList<std::string> string_list;
    string_list.push_front("Hello");
    string_list.traverse();
    return 0;
}
