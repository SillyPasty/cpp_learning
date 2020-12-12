#include <iostream>
#include <vector>

#include "strvec.h"
using namespace std;

int main() {
    StrVec sv;
    // string s(5, 'a');
    // cout << s << endl;
    for (int i = 0; i < 5; ++i) {
        // cout << i << endl;
        sv.push_back(string(i + 1, i + 'a'));
        // cout << string(i + 'a', i) << " ";
    }

    for (auto iter = sv.begin(); iter != sv.end(); ++iter) cout << *iter << " ";
    cout << endl;

    sv.reverse();

    for (auto iter = sv.begin(); iter != sv.end(); ++iter) cout << *iter << " ";
    cout << endl;

    cout << sv.capacity() << endl;

    sv.resize(2);

    for (auto iter = sv.begin(); iter != sv.end(); ++iter) cout << *iter << " ";
    cout << endl;
}