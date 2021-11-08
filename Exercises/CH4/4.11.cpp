#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (a > b && b > c && c > d) {
            cout << "True! a > b > c > d" << endl;
        } else {
            cout << "False." << endl;
        }
    }

    return 0;
}