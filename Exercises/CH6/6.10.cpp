#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 1, b = 2;
    cout << a << " " << b << endl;
    swap(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}