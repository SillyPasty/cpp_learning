#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l({1, 2, 3, 4, 5, 6, 7}), l2({88, 88, 88});
    l.splice(l.begin(), l2, ++l2.begin());
    for_each(l.begin(), l.end(), [](int &i) { cout << i << " "; });
    cout << endl;
}