#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

int main(){
    vector<int> ans;
    int value;
    while (cin >> value) {
        ans.push_back(value);
    }
    for (auto item : ans) {
        cout << item ;
    }
    cout << endl;
    return 0;
}