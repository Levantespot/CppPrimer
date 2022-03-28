#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

struct Person {
    Person() = default;
    Person(const string &n, const string &addr):
        name(n), address(addr) {}

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
    Person p1;
    Read(cin, p1);
    Print(cout, p1);

    Person p2("Lee", "China");
    Print(cout, p2);
    return 0;
}