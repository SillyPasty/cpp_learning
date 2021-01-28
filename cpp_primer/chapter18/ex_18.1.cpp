#include <exception>
#include <iostream>
#include <stdexcept>
void func();
int main() {
    try {
        func();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void func() {
    std::range_error r("error");
    std::exception* p = &r;
    throw *p;
}