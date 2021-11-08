#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    int i = 2;
    double d = 3.6;
    i *= static_cast<int>(d);
    cout << i << endl;
    return 0;
}