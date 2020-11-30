#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> vi;
    vector<long long> vll;
    cout << sizeof vi << endl;
    cout << sizeof vll << endl;
    cout << sizeof(vector<int>) << endl;
}