#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check_size(const string &, string::size_type);
bool is_shorter(const string &, const string &);
int main() {
    // auto check6 = bind(check_size, std::placeholders::_1, 2);
    // string s = "hello";
    int sz = 6;
    vector<string> v({"hello", "hello_world!"});
    stable_sort(v.begin(), v.end(),
                [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    auto wc = find_if(v.begin(), v.end(), 1

    );
    auto &os = cout;
    for_each(wc, v.end(), [&](const string &s) { os << s << " "; });

    // less to big
    sort(v.begin(), v.end(), is_shorter);
    for_each(v.begin(), v.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
    // big to less
    sort(v.begin(), v.end(), bind(is_shorter, placeholders::_2, placeholders::_1));
    for_each(v.begin(), v.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

bool is_shorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}