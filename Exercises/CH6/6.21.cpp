#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int f(const int digit, const int *p){
    if (digit >= *p) {
        return digit;
    } else {
        return *p;
    }
}

int main(){
    int a = 8, b = 9;
    int *pa = &a, *pb = &b;

    cout << f(a, pb) << endl;
    cout << f(b, pa) << endl;
    
    return 0;
}