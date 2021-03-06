#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    int a;
    cin >> a;
    try {
        if (a > 0) {
            throw std::runtime_error(">0");
        }
    } catch (std::runtime_error err) {
        cout << err.what() << endl;
    }

    return 0;
}