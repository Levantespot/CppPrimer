#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

class Person {
friend std::ostream &Print(std::ostream &os, const Person &person);
friend std::istream &Read(std::istream &is, Person &person);
public:
    Person() = default;
    Person(const string &n, const string &addr):
        name(n), address(addr) {}
    string get_name() const { return name; }
    string get_address() const { return address; }
private:
    string name;
    string address;
    
};

// Person 类中的声明仅仅制定了访问权限，并非一个通常意义的声明，因此还得再声明一次。
std::ostream &Print(std::ostream &os, const Person &person);
std::istream &Read(std::istream &is, Person &person);

int main(){
    Person p1;
    Read(cin, p1);
    Print(cout, p1);

    Person p2("Lee", "China");
    Print(cout, p2);
    return 0;
}

std::ostream &Print(std::ostream &os, const Person &person) {
    os << "Name: " << person.name << ", adress: " << person.address << endl;
    return os;
}
std::istream &Read(std::istream &is, Person &person) {
    is >> person.name >> person.address ;
    return is;
}