#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

using PF = double(*)(const double);

double scale1(const double a) {
    return a * 3 + 10;
}
double scale2(const double b) {
    return b * 5 + 2;
}

double (*choose_bigger(double a, double pf1(const double), double pf2(const double)))(const double){
    double out1 = pf1(a);
    double out2 = pf2(a);
    if (out1 >= out2) {
        return pf1;
    } else {
        return pf2;
    }
}

PF choose_bigger(double a, double pf1(const double), double pf2(const double)){
    double out1 = pf1(a);
    double out2 = pf2(a);
    if (out1 >= out2) {
        return pf1;
    } else {
        return pf2;
    }
}

auto choose_bigger(double a, double pf1(const double), double pf2(const double)) -> double (*)(const double)
{
    double out1 = pf1(a);
    double out2 = pf2(a);
    if (out1 >= out2) {
        return pf1;
    } else {
        return pf2;
    }
}

int main(int argc, char *argv[]){
    double input;
    while (cin >> input) {
        cout << "Input : " << input << ", scale1 = " << 
            scale1(input) << ", scale2 = " << scale2(input) << endl;
        cout << "Choose " << choose_bigger(input, scale1, scale2)(input) << endl;
    }

    return 0;
}