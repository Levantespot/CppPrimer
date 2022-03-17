#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

void f(){
    cout << "f()" << endl;
}
void f(int){
    cout << "f(int)" << endl;
}
void f(int, int){
    cout << "f(int, int)" << endl;
}
void f(double, double = 3.14){
    cout << "f(double, double = 3.14)" << endl;
}

int main(){
    return 0;
}