#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    vector<string> text = {"Hello", ",", " ", "world", "!"};

    for (auto s : text) {
        cout << s ;
    }
    cout << endl;
    return 0;
}