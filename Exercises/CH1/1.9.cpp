#include <iostream>
/*
 * Sum from 50 to 100.
 */
int main()
{
    int start = 50, end = 100;
    int current = start, sum = 0;
    while (current <= end) {
        sum += current;
        current += 1;
    }
    std::cout << "The sum from 50 to 100 is " << sum << std::endl;
    return 0;
}