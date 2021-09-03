#include<iostream>
#include"../include/Sales_item.h"

int main()
{
    Sales_item item1;
    Sales_item item2;
    std::cout << "Please input two Sales_item objects.(ISBN, number of copies sold, and sales price)" << std::endl;
    std::cin >> item1 >> item2;
    std::cout << "Their sum is: " << item1 + item2 << std::endl;
    return 0;
}