#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

double m_abs (double x) {
    return x > 0? x : -x;
}

int main(){
    double x;
    cin >> x;
    cout << m_abs(x) << endl;
    return 0;
}