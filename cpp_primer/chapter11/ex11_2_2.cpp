#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using std::map;
using std::multimap;
using std::multiset;
using std::set;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_multiset;
using std::unordered_set;

void ex11_11();
bool cmp(const int &, const int &);
int main() {}

void ex11_11() {
    multiset<int, decltype(cmp) *> mset;
}

bool cmp(const int &x1, const int &x2) {
    return x2 > x1;
}
