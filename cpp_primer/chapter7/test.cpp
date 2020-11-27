#include<iostream>
using namespace std;

struct Test {
    int i = 0;
    Test& rret();
    Test ret() const;
};

Test& Test::rret() {return *this;}
Test Test::ret() const {return *this;}

int main() {
    Test tes;
    tes.i = 0;
    Test ntes = tes.ret();
    ++(ntes.i);
    cout << tes.i << " " << ntes.i << endl;
    Test &rtes = tes.rret();
    ++(rtes.i);
    cout << tes.i << " " << rtes.i << endl;
    return 0;
}
