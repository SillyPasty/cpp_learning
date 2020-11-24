#include<string>
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<int> vi;
    vector<long long> vll;
    cout << sizeof vi << endl;
    cout << sizeof vll << endl;
    cout << sizeof(vector<int>) << endl;
}