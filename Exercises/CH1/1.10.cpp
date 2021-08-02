#include <iostream>
/*
 * Use decreament operator (--) in while statement to print from 10 to 0
 */
int main(){
    int start = 10, end = 0;
    int current = start;
    while (current >= end) {
        std::cout << current << " ";
        current--;
    }
    return 0;
}