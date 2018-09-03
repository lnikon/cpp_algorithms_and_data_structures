#pragma once

#include <iostream>
#include <string>
#include "singly_linked_list.hpp"

void someFuncFromStack() 
{
    singly_linked_list<std::string> list;
    list.push_back(std::string("Hello"));
    list.push_back(std::string(" world"));
    list.push_back(std::string("!"));
    list.traverse();
}
