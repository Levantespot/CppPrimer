#include <iostream>
/*
 * Use decreament operator (--) in while statement to print from 10 to 0 using for statement
 */
int main(){
    int start = 10, end = 0;
    for (int current = start; current >= end; current--) {
        std::cout << current << " ";
    }
    return 0;
}