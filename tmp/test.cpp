#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

int main(){
    string line;
    while(getline(cin, line)){
        cout << line << endl;
    }
    return 0;
}