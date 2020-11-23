#include<string>
#include<iostream>
#include<cctype>
using std::string;
using std::cout;
using std::cin;
using std::endl;
void eg3_2_3(string s);
int main()
{
    string s1;
    string s2(100, 'x');
    cout << s1 << endl;
    if (s1.empty())
        cout << "qaq" << endl;
    auto c = s2[10]; // c is a char
    for (auto c : s1)
        cout << c << endl;
    // use reference to modify the string's context
    string::size_type n;
    for (auto &r_c : s2)
    {
        r_c = '8';
        break;
    }
    cout << s2 << endl;
    string s("some string");
    eg3_2_3(s);
    cout << s << endl;
    return 0;
}

void eg3_2_3(string s)
{
    for (decltype(s.size()) i = 0; i < s.size() && !isspace(s[i]); ++i)
        s[i] = toupper(s[i]);
    cout << s << endl;
}