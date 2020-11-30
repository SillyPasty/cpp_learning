#include <iostream>
using namespace std;
int main() {
    int i;
    cin >> i;
    try {
        if (i == 0) {
            throw runtime_error("WTF!");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}