#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;
int main() {
    list<int> i_list({1, 2, 3});
    vector<double> d_vector;
    d_vector.assign(i_list.begin(), i_list.end());
    for (auto i : d_vector)
        cout << i / 2 << " ";
}