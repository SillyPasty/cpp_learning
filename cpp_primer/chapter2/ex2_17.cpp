#include <iostream>
int main() {
    int val = 1;
    int &ref_val = val;
    std::cout << val << " " << ref_val << std::endl;
    ref_val += 1;

    int new_val = 2;
    ref_val = new_val;
    ref_val += 20;
    std::cout << new_val << std::endl;
    int &ref_ref_val = ref_val;
    ref_ref_val++;

    std::cout << val << " " << ref_val << std::endl;
    return 0;
}