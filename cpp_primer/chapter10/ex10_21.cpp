#include <iostream>
using namespace std;
int main() {
    int x = 15;
    auto f = [x]() mutable -> bool {
        if (x) {
            --x;
            cout << x << " ";
            return true;
        }
        return false;
    };
    while (f())
        ;
    cout << x << " ";
    cout << endl;
    return 0;
}