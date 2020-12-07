#include <fstream>
#include <iostream>
#include <string>

#include "StrBlob.h"
#include "StrBlobPtr.h"

int main() {
    StrBlob b1;

    std::ifstream ifs("input");
    std::string line;
    while (std::getline(ifs, line)) {
        b1.push_back(line);
    }
    auto iter = b1.begin();
    while (1) {
        std::cout << iter.deref() << std::endl;
        iter.incr();
    }
    std::cout << std::endl;
    return 0;
}