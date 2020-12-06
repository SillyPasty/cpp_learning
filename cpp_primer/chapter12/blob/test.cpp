#include <iostream>

#include "StrBlob.h"

int main() {
    StrBlob b1, b2({"Hello", "world!"});
    b1 = b2;
    b1.front() = "Goodbye";
    std::cout << b2.front();
    return 0;
}