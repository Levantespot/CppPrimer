#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <deque>

using std::string; using std::vector; using std::deque;
using std::cout; using std::cin; using std::endl;

int main(int argc, char *argv[]){
    deque<string> ds;
    string input;
    while(cin >> input) {
        ds.push_back(input);
    }
    for(auto it = ds.cbegin(); it != ds.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}