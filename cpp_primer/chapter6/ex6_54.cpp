#include<iostream>
#include<vector>
using namespace std;
using PF = int(*)(int, int); // a definition of function pointer.
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);
int (*foo(int))(int*, int); // foo is a function, it will return a function with two arguments, and that function will return an int.
int main() {
    vector<PF> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(divi);
    int a = 10, b = 5;
    for (auto func : vec) {
        cout << func(a, b) << endl;
    }
    return 0;
}

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divi(int a, int b) {
    return static_cast<int>(a / b);
}