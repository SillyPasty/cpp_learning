#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main() {
    vector<int> x{1, 2, 3, 4, 5};
    int arr[] = {1, 2, 3};
    for (auto i = x.begin(); i != x.end(); ++i) {
        cout << *i << endl;
    }
    string s("hello world!");
    for (auto it = s.cbegin(); it != s.cend(); ++it)
        cout << *it;
    return 0;
}

void binary_search(vector<int> v, int target) {
    auto beg = v.begin(), end = v.end();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != target) {
        if (*mid > target)
            beg = mid + 1;
        if (*mid < target)
            end = mid;
        mid = beg + (end - beg) / 2;
    }
}