#include <iostream>
#include <forward_list>
using namespace std;

int main () {
    forward_list<int> f_lst({1, 2, 4, 6, 19, 20});
    auto prev_iter = f_lst.before_begin();
    auto cur_iter = f_lst.begin();
    while (cur_iter != f_lst.end()) {
        if (*cur_iter % 2)
            cur_iter = f_lst.erase_after(prev_iter);
        else {
            ++prev_iter;
            ++cur_iter;
        }
    }
    for (auto i : f_lst)
        cout << i << " ";
    cout << endl;
    return 0;
}