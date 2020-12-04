#include <iostream>
using namespace std;
int main() {
    auto f = [](int &a, int &b) { return a + b; };
    int x = 15;
    auto f1 = [&x]() -> int & { return ++x; };
    int &y = f1();
    ++y;
    cout << x << endl;
    int x1 = 20;
    auto f2 = [x1]() mutable { return ++x1; };  // default args is const
    x1 = 0;
    cout << f2() << endl;
    int a = 1, b = 5;
    cout << f(a, b) << endl;
    return 0;
}