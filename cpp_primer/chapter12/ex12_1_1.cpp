#include <iostream>
#include <memory>

using namespace std;

int main() {
    shared_ptr<string> sp;
    string s = "233";
    sp = make_shared<string>(s);
    // if (sp && sp->empty()) {
    //     *sp = "hello_sp";
    // }
    cout << *sp << endl;
    return 0;
}