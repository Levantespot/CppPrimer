#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

int main(){
    string word;
    vector<string> inputs;
    while (cin >> word) {
        inputs.push_back(word);
    }
    unsigned cnt = 0;
    unsigned print_every = 8;
    for (auto &word : inputs) {
        for (auto &character : word) {
            character = toupper(character);
        }
    }
    for (auto w : inputs) {
        cout << w << "\t" ;
        ++cnt;
        if (cnt % print_every == 0) {
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}