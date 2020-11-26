#include<iostream>
using namespace std;
auto (*pf)(int a, int b) -> bool;
auto f(int a, int b) -> bool;

int main() {
    pf = f;
    cout << pf(1, 2) << " "<< (*pf)(2, 1) << endl;
}

auto f(int a, int b) -> bool {
    if (a > b)
        return true;
    return false;
}