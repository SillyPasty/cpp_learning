#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void ex10_34();
void ex10_35();
void ex10_36();
void ex10_37();
int main() {
    ex10_37();
}

void ex10_34() {
    vector<int> v({1, 2, 3});
    for_each(v.rbegin(), v.rend(), [](int &i) { cout << i << " "; });
    cout << endl;
}

void ex10_35() {
    vector<int> v({1});
    for (auto iter = v.end(); iter != v.begin();) {
        --iter;
        cout << *iter << " ";
    }
    cout << endl;
}

void ex10_36() {
    vector<int> v({1, 2, 0, 5, 8, 0, 9});
    auto last_zero = find(v.rbegin(), v.rend(), 0);
    for_each(v.rbegin(), last_zero, [](int &i) { cout << i << " "; });
}

void ex10_37() {
    vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    list<int> l;
    auto iter = inserter(l, l.begin());
    copy(v.rbegin() + 3, v.rbegin() + 7, iter);
    for_each(l.begin(), l.end(), [](int &i) { cout << i << " "; });
}