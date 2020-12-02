#include <iostream>
#include <vector>
using namespace std;
int main () {
    vector<int> v;
    for (int i = 0; i < 130; ++i) {
        cout << "Size: " << v.size() << " " << "Capacity: " << v.capacity() << endl;
        v.push_back(i);
    }
}