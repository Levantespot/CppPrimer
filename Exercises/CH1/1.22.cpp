#include<iostream>
#include"../include/Sales_item.h"

int main()
{
    Sales_item item_sum;
    Sales_item item_new;
    std::cout << "Please input several Sales_item objects.(ISBN, number of copies sold, and sales price)" << std::endl;
    for (std::cin >> item_sum; std::cin >> item_new; ) {
        item_sum += item_new;
    }
    std::cout << "Their sum is: " << item_sum << std::endl;
    return 0;
}