#include <iostream>
using namespace std;
int main() {
    int ia[3][4];
    int cnt = 0;
    for (auto &row : ia) {
        for (auto &col : row)
            col = ++cnt;
    }
    for (int(&p)[4] : ia) {
        for (int q : p)
            cout << q << ' ';
        cout << endl;
    }
    for (int(*p)[4] = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }

    return 0;
}