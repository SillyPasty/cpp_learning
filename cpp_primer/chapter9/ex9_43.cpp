#include <string>
#include <iostream>
using namespace std;

void foo(string &, const string &, const string &);
void foo1(string &, const string &, const string &);

int main() {
    string oris = "xthothox";
    string os = "tho", ns = "thought";
    foo1(oris, os, ns);
    cout << endl << oris << endl;
}

void foo(string &str, const string &old_val, const string &new_val) {
    int len = old_val.size();
    for (auto iter = str.begin(); iter != str.end() && iter + len - 1 != str.end(); ++iter) {
        bool flag = true;
        for (auto i = 0; i < old_val.size(); ++i) {
            if (old_val[i] != *(i + iter)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            iter = str.erase(iter, iter + len);
            iter = str.insert(iter, new_val.begin(), new_val.end());
            iter += new_val.size();
            --iter;
        }
    }
}

void foo1(string &str, const string &old_val, const string &new_val) {
    int len = old_val.size();
    cout << len << endl;
    for (int i = 0; i < str.size(); ++i) {
        bool flag = true;
        if (str.substr(i, len) != old_val)
            continue;
        str.replace(i, len, new_val);
        i += new_val.size() - 1;
    }
}