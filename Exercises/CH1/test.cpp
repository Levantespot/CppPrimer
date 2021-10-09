#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    int i = 1, j = 2;
    int &refi = i;
    refi = j;
    std::cout << i << std::endl;
    return 0;
}