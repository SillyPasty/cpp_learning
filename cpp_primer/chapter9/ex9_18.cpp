#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::string;
using std::vector;
int main() {
    deque<string> q;
    string input;
    while (cin >> input)
        q.push_back(input);
    auto iter = q.begin();
    while (iter != q.end())
        cout << *iter << " ";
}