#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int f(int a, int b){
    return a + b;
}

using type1 = decltype(f) *; 
using type2 = decltype(f); 
typedef type1 type3;
// typedef int (*)(int, int) type4; // error

int main(){
    vector<int (*)(int, int)> arr_f1; 
    arr_f1.push_back(f);

    vector<type1> arr_f2;
    arr_f2.push_back(f);

    vector<type2 *> arr_f3;
    arr_f3.push_back(f);
    return 0;
}