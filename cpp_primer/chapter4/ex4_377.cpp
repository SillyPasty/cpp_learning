#include<string>
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    int i;
    double d;
    
    const string *cpss;
    
    char *pc;
    void *pv;

    pv = static_cast<void*>(const_cast<string*>(cpss));
    i = static_cast<int>(*pc);
    pv = static_cast<void*>(&d);
    pc = static_cast<char*>(pv);

    string s = "233";
    string *ps;
    const string *cps;  // the value of the pointer is a const
    string *const pcs = &s; // the pointer is a const
    ps = &s;
    *(ps + 1) = 'x';
    *pcs = 'x';
    // pcs = nullptr; // this is wrong

}