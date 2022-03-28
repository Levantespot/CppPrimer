#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

struct Person {
    string name;
    string address;
    string get_name() const { return name; }
    string get_address() const { return address; }
};


int main(){
    return 0;
}