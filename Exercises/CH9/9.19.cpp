#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>

using std::string; using std::vector; using std::list;
using std::cout; using std::cin; using std::endl;

int main(int argc, char *argv[]){
    list<string> ls;
    string input;
    while(cin >> input) {
        ls.push_back(input);
    }
    for(auto it = ls.cbegin(); it != ls.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}