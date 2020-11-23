#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
    string s1;
    // while (getline(cin, s1))
    while (cin >> s1)
    {
        cout << s1 << endl;
    }
    return 0;
}