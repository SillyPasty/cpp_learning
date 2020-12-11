#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::find_if;
using std::for_each;
using std::partition;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
bool compare(const string &, const string &);
bool part_cmp(const string &);
auto rev(const int &) -> bool;
void biggies(vector<string> &, vector<string>::size_type);

int main() {
    vector<string> v({"xx", "x", "xxx", "aaa"});
    vector<string> v2({"helloo", "heo", "hi", "Hello world!", "helloo"});
    biggies(v2, 3);
    stable_sort(v.begin(), v.end(), compare);
    // use lambda
    stable_sort(v.begin(), v.end(), [](const string &s1, const string &s2) -> bool {
        return s1.size() < s2.size();
    });
    auto part_iter = partition(v2.begin(), v2.end(), part_cmp);
    for (auto iter = v2.begin(); iter != part_iter; ++iter)
        cout << *iter << " ";
    cout << endl;
    for (auto s : v)
        cout << s << " ";
    cout << endl;
    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    stable_sort(
        words.begin(), words.end(),
        [](const string &s1, const string &s2) -> bool { return s1.size() < s2.size(); });
    auto unique_end = unique(words.begin(), words.end());  // sort first, remove then
    words.erase(unique_end, words.end());
    auto count = find_if(words.begin(), words.end(),
                         [sz](const string &s) { return s.size() >= sz; });
    cout << words.end() - count << endl;
    for_each(count, words.end(), [](const string &s) { cout << s << " "; });

    cout << endl;
}

bool compare(const string &s1, const string &s2) {
    return s1.size() > s2.size();
}

bool part_cmp(const string &s1) {
    return s1.size() >= 5;
}