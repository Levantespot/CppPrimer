#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

int main(){
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100 && grade >= 0) {
            *(scores.begin() + grade / 10) += 1;
        }
    }
    for (auto s : scores) {
        cout << s << " " ;
    }
    return 0;
}