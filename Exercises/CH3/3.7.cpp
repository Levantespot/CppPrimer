#include<iostream>
#include<string>
#include<cctype>

using std::string; using std::cout; using std::cin; using std::endl;

int main(){
    string line("Hello");
    cout << "Original line : " << line << endl;
    for (char &c : line) {
        c = 'X';
    }
    cout << "Line after modified : " << line << endl;
    return 0;
}