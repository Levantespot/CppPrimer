#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    cout << (sizeof(int*) == sizeof(int)) << endl;
    cout << (sizeof(float*) == sizeof(float)) << endl;

    return 0;
}