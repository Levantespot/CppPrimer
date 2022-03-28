#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

class Y;    // forward declaration

class X {
    Y *py;
};

class Y {
    X x;
};

int main(){
    return 0;
}

