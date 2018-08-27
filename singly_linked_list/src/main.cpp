#include <iostream>
#include <utility>

#include "singlylist.h"

int main()
{
    SinglyList<int> list;
    list.push_back(2);
    list.push_back(12);
    list.push_back(22);
    list.push_back(23);
    list.push_back(52);

    list.traverse();
    std::cout << "\n";

    auto node = list.pop_front();
    if (node) {
        std::cout << node->data << std::endl << std::endl << std::endl;
    }

    /*
     * This code will cause segfault, because
     * node->next std::move()-d in the pop.front() method
     *
     * std::cout << node->next->data << std::endl;
     * */

    list.traverse();
    std::cout << "\n";

    return 0;
}
