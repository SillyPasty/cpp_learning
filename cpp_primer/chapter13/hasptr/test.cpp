#include <iostream>

#include "hasptr.h"

int main() {
    HasPtr hp1("abaaba");
    HasPtr hp2("qaq");
    HasPtr hp3;
    hp3 = hp2;
    std::cout << hp1.get_use() << " " << hp2.get_use() << " " << hp3.get_use()
              << std::endl;
    // std::cout << hp1.get_use() << " " << hp2.get_use() << " " << hp3.get_use()
    //           << std::endl;
}