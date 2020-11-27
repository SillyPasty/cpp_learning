#ifndef SCREEN
#define SCREEN
#include<iostream>
#include<string>
#include"Window_mgr.h"
#endif

class Screen {

// friend class Window_mgr;
// function 'clear' needs to be decleared before uesd as friend
friend void Window_mgr::clear(ScreenIndex); 

public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    void some_member() const;
    char get() const {return contents[cursor];}
    char get(pos ht, pos wd) const; // reload
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) 
                    {do_display(os); return *this;}
    const Screen &display(std::ostream &os) const
                    {do_display(os); return *this;}
private:
    void do_display(std::ostream &os) const {os << contents;}
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}
