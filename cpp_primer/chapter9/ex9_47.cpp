#include <string>
#include <iostream>
using namespace std;
int main() {
    string s("ab2c3d7R4E6");
    string number("1234567890");
    string::size_type pos = 0;
    while ((pos = s.find_first_of(number, pos)) != string::npos) {
        cout << "Find number : " << s[pos] << " at: " << pos << endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(number, pos)) != string::npos) {
        cout << "Find alphabet : " << s[pos] << " at: " << pos << endl;
        ++pos;
    }
}