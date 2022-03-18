#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

int f_add(int a, int b){
    return a + b;
}
int f_sub(int a, int b){
    return a - b;
}
int f_mul(int a, int b){
    return a * b;
}
int f_div(int a, int b){
    return a / b;
}

int main(){
    vector<int (*)(int, int)> arr_f; 
    arr_f.push_back(f_add);
    arr_f.push_back(f_sub);
    arr_f.push_back(f_mul);
    arr_f.push_back(f_div);
    int a, b;
    while (cin >> a >> b) {
        cout << "The results of four functions:" << endl;
        for (auto f : arr_f) {
            cout << f(a, b) << endl;
        }
    }
    
    return 0;
}