#include <iostream>
/*
 * Print a range betweent two numbers inputed by user.
 */
int main(){
    int from = -1, to = -1, current;    // from is smaller than to by default
    std::cout << "Please input two different numbers" << std::endl;
    std::cin >> from >> to ;
    if (from > to) {
        // exchange variable from and to, when from is greater than to. 
        int temp = from;
        from = to;
        to = temp;
    }
    current = from;
    while (current <= to) {
        std::cout << current << " ";
        current++;
    }
    return 0;
}