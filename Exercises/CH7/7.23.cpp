#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos row, pos col) const { return contents[row * width + col]; }
    Screen &move(pos row, pos col);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr = 0;
};

inline
Screen &Screen::move(pos row, pos col) {
    cursor = row * width + col;
    return *this;
}

class Windows_mgr {
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

int main(){
    return 0;
}