#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

void f1 () {
    vector<int> inputs;
    int input;
    while (cin >> input) {
        inputs.push_back(input);
    }
    int sum;
    for (unsigned i = 0; i < inputs.size()-1; i++) {
        cout << inputs[i] + inputs[i+1] << " " ;
    }
}

void f2 () {
    vector<int> inputs;
    int input;
    while (cin >> input) {
        inputs.push_back(input);
    }
    int sum;
    for (unsigned i = 0; i < inputs.size() / 2; i++) {
        cout << inputs[i] + inputs[inputs.size()-i-1] << " " ;
    }
}

int main(){
    // f1();
    f2();
    return 0;
}