#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;

int main(int argc, char *argv[]){
    vector<int> vec1;    // 0
    vector<int> vec2(10);    // 10个0
    vector<int> vec3(10, 1);  // 10个1
    vector<int> vec4{0, 1, 2, 3, 4, 5 }; // 0, 1, 2, 3, 4, 5,
    vector<int> vec5(vec4); // 拷贝 vec4 的元素
    vector<int> vec6(vec4.begin(), vec4.end()); // 拷贝 vec4 的元素
    return 0;
}