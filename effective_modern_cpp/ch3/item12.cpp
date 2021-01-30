#include <iostream>
#include <vector>
using namespace std;

class MyClass {
public:
    using DataType = vector<double>;
    MyClass(double x) : values(x, 10.0) {}
    DataType& data() {
        return values;
    }

private:
    DataType values;
};

int main() {
    MyClass mc(10);
    auto v1 = mc.data();
    cout << v1[0];
    vector<double>& rv1 = mc.data();
    auto& rv2 = mc.data();
    rv1[2] = 50;
    auto v2 = mc.data();
    cout << v2[2];
    mc.data()[3] = 80;
    cout << rv1[3];
    cout << rv2[3];
}