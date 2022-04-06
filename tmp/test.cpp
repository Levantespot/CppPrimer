#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <queue>

using std::string; using std::vector; using std::queue; 
using std::cout; using std::cin; using std::endl;

int main(int argc, char *argv[]){
    queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << q.front() << " " << endl;
        q.pop();
    }
    
    return 0;
}