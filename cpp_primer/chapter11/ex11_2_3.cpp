#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void ex11_12() {
    vector<pair<string, int>> v;
    int n, x;
    string s;
    cin >> n;
    while (n--) {
        cin >> s >> x;
        pair<string, int> p{s, x};
        v.push_back(p);
        v.push_back({s, x});
    }
}