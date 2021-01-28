#include "Blob.hpp"

#include <iostream>
int main() {
    Blob<int> blob;  // = {1, 2, 3};
    blob.push_back(1);
    std::cout << blob.back();
    std::cout << blob;
}