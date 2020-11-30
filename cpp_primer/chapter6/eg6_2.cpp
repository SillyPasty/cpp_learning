#include <initializer_list>
#include <iostream>
using namespace std;
void error_msg(initializer_list<string> ls);
int main(int argc, char **argv) {
    int i = 1;
    if (i) {
        error_msg({"main", "i is not 0", "bad bad!"});
    } else {
        error_msg({"main", "good!"});
    }
}
void error_msg(initializer_list<string> ls) {
    for (auto beg = ls.begin(); beg != ls.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}