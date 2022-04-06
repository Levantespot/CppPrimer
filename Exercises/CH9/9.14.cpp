#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>

using std::string; using std::vector; using std::list;
using std::cout; using std::cin; using std::endl;

int main(int argc, char *argv[]){
    list<char *> cl{"Hello", "World"}; 
    vector<string> sv;
    sv.assign(cl.cbegin(), cl.cend());
    for (auto it : sv) {
        cout << it << endl;
    }
    return 0;
}