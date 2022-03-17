#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;
typedef vector<int>::const_iterator const_iter;

void print_vector_recursively_v2(const_iter first, const_iter end) {
    #ifdef DEBUG_SIZE
        std::cout << "vector size = " << end-first << endl;
    #endif
    if (first != end) {
        cout << (*first);
        print_vector_recursively_v2(first+1, end);
    }
}

int main(){
    vector<int> v{0,1,2,3,4,5,6};
    print_vector_recursively_v2(v.begin(), v.end());
    cout << endl;

    return 0;
}