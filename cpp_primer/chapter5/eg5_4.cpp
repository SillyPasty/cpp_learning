#include <cstdio>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
    vector<int> vec;
    int i;
    while (cin >> i)
        vec.push_back(i);
    auto end = vec.end();
    for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
        cout << *beg << endl;
        // printf("%p")
        // vec.push_back(*beg);   // very danger!!!
    }
    return 0;
}