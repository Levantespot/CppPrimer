#include <iostream>
/*
 * Sum from 50 to 100 using for statement.
 */
int main()
{
    int start = 50, end = 100;
    int sum = 0;
    for (int current = start; current <= end; current++) {
        sum += current;
    }
    std::cout << "The sum from 50 to 100 is " << sum << std::endl;
    return 0;
}