#include<iostream>
#include<string>
#include<cctype>

using std::string; using std::cout; using std::cin; using std::endl;

int main(){
    string line;
    string ans;
    cout << "Please enter a line including characters and punctuations." << endl;
    getline(cin, line);
    for (auto c : line) {
        if (!ispunct(c)){
            ans += c;
        }
    }
    cout << "After removing punctuation: " << ans << endl;
    return 0;
}