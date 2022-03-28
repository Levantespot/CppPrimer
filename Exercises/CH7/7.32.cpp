#include<iostream>
#include<string>
#include<vector>

using std::string; using std::vector; 
using std::cout; using std::cin; using std::endl;
using std::begin; using std::end;

class Screen;

class Windows_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    Windows_mgr () ;
    Windows_mgr (Screen &s) ;
    void clear(ScreenIndex index) ;
private:
    // std::vector<Screen> screens{Screen(24, 80, ' ')};
    std::vector<Screen> screens;
};

class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
    friend void Windows_mgr::clear(ScreenIndex) ;

    char get() const { return contents[cursor]; }
    char get(pos row, pos col) const { return contents[row * width + col]; }
    Screen &move(pos row, pos col) {
        cursor = row * width + col;
        return *this;
    }
    Screen &set(pos row, pos col, char ch) {
        contents[row * width + col] = ch;
        return *this;
    }
    Screen &set(char ch) {
        contents[cursor] = ch;
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr = 0;
    void do_display(std::ostream &os) const {os << contents;}
};



inline void Windows_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = string(s.height * s.width, ' ');
}
inline Windows_mgr::Windows_mgr() {
    screens.push_back(Screen(24, 80, ' '));
}
inline Windows_mgr::Windows_mgr(Screen &s) {
    screens.push_back(s);
}

int main(){
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    return 0;
}