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

std::ostream &Print(std::ostream &os, const Person &person) {
    os << "Name: " << person.name << ", adress: " << person.address << endl;
    return os;
}
std::istream &Read(std::istream &is, Person &person) {
    is >> person.name >> person.address ;
    return is;
}

int main(){
    Person p;
    Read(cin, p);
    Print(cout, p);
    return 0;
}