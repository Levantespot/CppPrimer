#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    std::cout << "Please input ISBN, number of copies sold, and sales price." << std::endl;
    Sales_item book;
    // read ISBN, number of copies sold, and sales price
    std::cin >> book;
    // write ISBN, number of copies sold, total revenue, and average price
    std::cout << book << std::endl;
    return 0;
}