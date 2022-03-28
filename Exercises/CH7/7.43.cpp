#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

class NoDefault {
public:
    NoDefault (int a) {}
};

class C {
public:
    C():c(0){}
private:
    NoDefault c;
};

int main(){
    vector<NoDefault> vec{1, 2, 3};
    cout << vec.end() - vec.begin() << endl;
    return 0;
}