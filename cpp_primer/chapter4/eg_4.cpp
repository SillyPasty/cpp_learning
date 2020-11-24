#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
int main() {
    string s1 = "233";
    string s2 = s1;
    s1[2] = 'x'; // copy the value!
    cout << s1 << endl << s2 << endl;
    return 0;
}