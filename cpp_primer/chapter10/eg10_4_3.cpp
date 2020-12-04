#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    auto comma = find(line.begin(), line.end(), ',');
    cout << string(line.begin(), comma) << endl;
    auto rcomma = find(line.rbegin(), line.rend(), ',');
    cout << string(rcomma.base(), line.end()) << endl;
}