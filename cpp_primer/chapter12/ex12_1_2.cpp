#include <iostream>
#include <vector>
using namespace std;

void ex12_6();
auto ex12_6_foo1() -> vector<int>*;
void ex12_6_foo2(vector<int>*);
void ex12_6_foo3(vector<int>*);

int main() {
    ex12_6();
}

void ex12_6() {
    auto v = ex12_6_foo1();
    ex12_6_foo2(v);
    ex12_6_foo3(v);
}
auto ex12_6_foo1() -> vector<int>* {
    return new vector<int>;
}

void ex12_6_foo2(vector<int>* v) {
    int i;
    while (cin >> i) v->push_back(i);
}

void ex12_6_foo3(vector<int>* v) {
    for (auto i : *v) cout << i << " ";
    delete v;
}