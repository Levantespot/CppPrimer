#include<iostream>
#include<string>

using std::string; using std::cout; using std::cin; using std::endl;

int main(){
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    string concatenate(line1 + line2);
    string concatenate_with_space(line1 + ' ' + line2);
    cout << concatenate << '\n'
         << concatenate_with_space << endl;
    return 0;
}