#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

int main(){
    vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };
    
    cout << "v1 : " ;
    for (auto v : v1) {
        cout << v  << " ";
    }
	cout << endl << "v1 size = " << v1.size() << endl;

    cout << "v2 : " ;
    for (auto v : v2) {
        cout << v  << " ";
    }
	cout << endl << "v2 size = " << v2.size() << endl;

    cout << "v3 : " ;
    for (auto v : v3) {
        cout << v  << " ";
    }
	cout << endl << "v3 size = " << v3.size() << endl;

    cout << "v4 : " ;
    for (auto v : v4) {
        cout << v  << " ";
    }
	cout << endl << "v4 size = " << v4.size() << endl;

    cout << "v5 : " ;
    for (auto v : v5) {
        cout << v  << " ";
    }
	cout << endl << "v5 size = " << v5.size() << endl;

    cout << "v6 : " ;
    for (auto v : v6) {
        cout << v  << " ";
    }
	cout << endl << "v6 size = " << v6.size() << endl;

    cout << "v7 : " ;
    for (auto v : v7) {
        cout << v  << " ";
    }
    cout << endl << "v7 size = " << v7.size() << endl;

    return 0;
}
