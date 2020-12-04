#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    istream_iterator<int> int_it(cin), eof;
    ostream_iterator<int> int_ot(cout, " ");
    vector<int> v(int_it, eof);
    for (auto e : v)
        *int_ot++ = e;  // the same as int_ot = e;
    copy(v.begin(), v.end(), int_ot);
    return 0;
}