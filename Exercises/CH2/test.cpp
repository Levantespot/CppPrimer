#include <iostream>

int get_size(int a){
    if(a > 0){
        return 1;
    }else{
        return -1;
    }
}

int main()
{
    int input;
    std::cin >> input ;
    const int a = get_size(input);
    std::cout << "input = " << a << std::endl;
    return 0;
}