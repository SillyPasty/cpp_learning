#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void ex10_29();
void ex10_30();
void ex10_32();

int main() {
    ex10_32();
    return 0;
}

void ex10_29() {
    ifstream file_is("input");
    istream_iterator<string> string_is(file_is), eof;
    ostream_iterator<string> string_os(cout, "\n");
    vector<string> v(string_is, eof);
    copy(v.begin(), v.end(), string_os);
}

void ex10_30() {
    istream_iterator<int> int_is(cin), eof;
    ostream_iterator<int> int_os(cout, " ");
    vector<int> v(int_is, eof);
    sort(v.begin(), v.end());
    unique_copy(v.begin(), v.end(), int_os);
}

void ex10_32() {
    ifstream file_is("input_int");
    ofstream file1_os("output1"), file2_os("output2");
    istream_iterator<int> int_is(file_is), eof;
    ostream_iterator<int> int_f1_os(file1_os, " "), int_f2_os(file2_os, "\n");
    while (int_is != eof) {
        auto i = *int_is++;
        if (i % 2)
            *int_f1_os++ = i;
        else
            *int_f2_os++ = i;
    }
}
