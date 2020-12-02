#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main () {
    vector<char> v_char({'a', 'b'});
    // string s(v_char); // wrong
    string s;
    s.assign(v_char.begin(), v_char.end());
    cout << s;
}