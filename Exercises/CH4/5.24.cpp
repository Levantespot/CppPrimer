#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        throw std::runtime_error("Divisor is 0!");
    } else {
        cout << a / b << endl;
    }
    return 0;
}