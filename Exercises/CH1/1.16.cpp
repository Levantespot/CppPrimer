#include <iostream>
/*
 * My version of sum program.
 */
int main()
{
    int sum = 0, value = 0;
    // read until end-of-file, calculating a running total of all values read
    std::cout << "Please input some integers, and this program will output their sum. (Input ctrl-z to end input.)" << std::endl;
    while (std::cin >> value)
        sum += value; // equivalent to sum = sum + value
        std::cout << "Sum is: " << sum << std::endl;
    return 0;
}