#include <iostream>
#include "template.hpp"

int main()
{

    example::MyContrivedClass *myclass = new example::MyContrivedClass();
    std::cout << "Size: " << myclass->catalog_size << std::endl;
    return 0;
}