#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    unsigned grade;
    while (cin >> grade) {
        string finalgrade = (grade > 90) ? "high pass"
                            : (grade > 75) ? "pass" 
                            : (grade > 60) ? "low pass"
                            : "fail" ;
        cout << finalgrade;
    }
    return 0;
}