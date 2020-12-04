#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    list<int> l1, l2, l3;
    auto b_iter = back_inserter(v);
    for (int i = 0; i < 10; ++i)
        *b_iter = i;
    copy(v.begin(), v.end(), back_inserter(l1));
    copy(v.begin(), v.end(), inserter(l2, l2.begin()));
    copy(v.begin(), v.end(), front_inserter(l3));
    auto f = [](list<int> &x) {
        for (int i : x)
            cout << i << " ";
        cout << endl;
    };
    f(l1);
    f(l2);
    f(l3);
}