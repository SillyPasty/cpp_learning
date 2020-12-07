#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main() {
    shared_ptr<string> sp;
    string s = "123";
    sp = make_shared<string>(s);
    shared_ptr<string> sp1 = sp;
    if (!sp.unique()) sp.reset(new string(*sp));
    *sp += "456";
    cout << *sp << endl << *sp1 << endl;
}