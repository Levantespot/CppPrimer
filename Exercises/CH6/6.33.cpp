#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

typedef vector<int>::const_iterator const_iter;

void print_vector_recursively(vector<int> &v, int loc) {
    if (loc != 0) {
        print_vector_recursively(v, loc-1);
    }
    cout << v[loc] ;
}

void print_vector_recursively_v1(vector<int> &v, int loc) {
    if (loc != v.size()) {
        cout << v[loc] ;
        print_vector_recursively_v1(v, loc+1);
    }
}

void print_vector_recursively_v2(const_iter first, const_iter end) {
    if (first != end) {
        cout << (*first);
        print_vector_recursively_v2(first+1, end);
    }
}

int main(){
    vector<int> v{0,1,2,3,4,5,6};
    print_vector_recursively(v, v.size()-1);
    cout << endl;

    print_vector_recursively_v1(v, 0);
    cout << endl;

    print_vector_recursively_v2(v.begin(), v.end());
    cout << endl;
    return 0;
}