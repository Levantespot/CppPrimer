#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>
#include <forward_list>

using std::string; using std::vector; using std::list; using std::forward_list;
using std::cout; using std::cin; using std::endl;

void f_vector(){
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    cout << "Input:\t" ;

    for (auto it : vi) {
        cout << it << " " ;
    }
    cout << endl;
    auto iter = vi.begin(); // call begin, not cbegin because we’re changing vi
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter); // duplicate the current element
            iter += 2; // advance past this element and the one inserted before it
        } else
            iter = vi.erase(iter); // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
    }

    cout << "Output:\t" ;
    for (auto it : vi) {
        cout << it << " " ;
    }
    cout << endl;
}

void f_list(){
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    cout << "Input:\t" ;

    for (auto it : lst) {
        cout << it << " " ;
    }
    cout << endl;
    auto iter = lst.begin(); // call begin, not cbegin because we’re changing lst
    while (iter != lst.end()) {
        if (*iter % 2) {
            iter = lst.insert(iter, *iter); // duplicate the current element
            ++iter; ++iter; // advance past this element and the one inserted before it
        } else
            iter = lst.erase(iter); // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
    }

    cout << "Output:\t" ;
    for (auto it : lst) {
        cout << it << " " ;
    }
    cout << endl;
}

void f_forward_list(){
    forward_list<int> f_lst = {0,1,2,3,4,5,6,7,8,9};
    cout << "Input:\t" ;

    for (auto it : f_lst) {
        cout << it << " " ;
    }
    cout << endl;
    auto iter = f_lst.begin(); // call begin, not cbegin because we’re changing f_lst
    auto prev = f_lst.before_begin();
    while (iter != f_lst.end()) {
        if (*iter % 2) {
            iter = f_lst.insert_after(iter, *iter); // duplicate the current element
            prev = iter;
            ++iter; // advance past this element and the one inserted before it
        } else {
            iter = f_lst.erase_after(prev); // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
        }
        
    }

    cout << "Output:\t" ;
    for (auto it : f_lst) {
        cout << it << " " ;
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    f_vector();
    f_list();
    f_forward_list();
    return 0;
}

