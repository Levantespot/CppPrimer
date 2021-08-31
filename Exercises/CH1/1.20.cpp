#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item new_book;
    int id_trans = 0;
    std::cout << "Please input every transaction with ISBN, number of copies sold, and sales price." << std::endl;
    while (std::cin >> new_book) {
        std::cout << "ISBN " << "num_sold " << "price_sum " << "price_each " << std::endl;
        std::cout << new_book << std::endl;
    }
    return 0;
}