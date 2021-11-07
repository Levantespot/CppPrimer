#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int main(){
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };


    // version 1
    for (auto &p_row : ia) {
        for (auto &p_col : p_row) {
            cout << p_col << " ";
        }
    }
    cout << endl;

    // version 2
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 4; j++) {
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;

    // version 3
    for (auto p1 = begin(ia); p1 != end(ia); ++p1) {
        for (auto p2 = begin(*p1); p2 != end(*p1); ++p2) {
            cout << *p2 << " ";
        }
    }
    cout << endl;

    return 0;
}