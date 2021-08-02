#include <iostream>
/*
 * Print a range betweent two numbers inputed by user.
 */
int main(){
    int from = -1, to = -1, current;
    std::cout << "Please input two different numbers, the 1st one is greater" << std::endl;
    std::cin >> from >> to ;
    current = from;
    while (current >= to) {
        std::cout << current << " ";
        current--;
    }
    return 0;
}