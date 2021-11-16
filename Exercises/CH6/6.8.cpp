#include<iostream>
#include<string>
#include<vector>
#include"Chapter6.h"

using std::string; using std::vector;
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;


int main(){
    cout << m_abs(-5) << endl;
    cout << fact(5) << endl;
    return 0;
}
int fact(int x) {
    if (x == 1 || x==0) {
        return 1;
    }
    return x * fact(x-1);
}
double m_abs (double x) {
    return x > 0? x : -x;
}