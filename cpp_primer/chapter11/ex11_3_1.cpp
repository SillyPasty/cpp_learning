#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void ex11_17() {
    vector<string> v;
    multiset<string> c;
    copy(v.begin(), v.end(), inserter(c, c.end()));
    // copy(v.begin(), v.end(), back_inserter(c));  // invalid
    copy(c.begin(), c.end(), inserter(v, v.end()));
    copy(c.begin(), c.end(), back_inserter(v));
}

void ex11_18() {
    map<const string, int> word_count;
    for (map<const string, int>::value_type x : word_count)
        cout << x.first << " " << x.second << endl;
}

int main() {
    ex11_17();
}