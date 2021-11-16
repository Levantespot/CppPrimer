#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int f(int x) {
    if (x == 1 || x==0) {
        return 1;
    }
    return x * f(x-1);
}

int main(){
    int x;
    cin >> x;
    cout << f(x) << endl;
    return 0;
}