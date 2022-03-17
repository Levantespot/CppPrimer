#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

inline bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

int main(){
    cout << isShorter("Hello", "World!") << endl;
    return 0;
}