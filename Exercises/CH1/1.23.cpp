/*
 * reads several transactions and counts how many transactions occur for each ISBN. Note that ISBN is in descending order.
 */
#include <iostream>
#include <string>
#include "../include/Sales_item.h"

int main()
{   
    Sales_item new_item;
    std::string old_isbn, new_isbn;
    std::cout << "Please input several transactions. Note that ISBN is in descending order." << std::endl;
    std::cin >> new_item;
    old_isbn = new_item.isbn();
    int count = 1;
    while(std::cin >> new_item) {
        new_isbn = new_item.isbn();
        if (new_isbn == old_isbn) {
            count += 1;
        } else {
            std::cout << "The times of occurence of ISBN:" << old_isbn << " is " << count << std::endl;
            count = 1;
        }
        old_isbn = new_isbn;
    }
    std::cout << "The times of occurence of ISBN:" << old_isbn << " is " << count << std::endl;
    return 0;
}