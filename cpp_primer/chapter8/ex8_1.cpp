#include <iostream>
#include <string>
using namespace std;

istream& cin_test(istream&);

int main() {
    cin_test(cin);
    if (cin.good())
        cout << "good!" << endl;
}

istream& cin_test(istream& is) {
    string s;
    while (is >> s) {
        cout << s;
    }
    auto old_state = is.rdstate();
    cout << endl;
    cout << old_state << endl;
    if (cin.good())
        cout << "good!" << endl;
    if (cin.eof())
        cout << "eof!" << endl;
    is.clear();
    return is;
}