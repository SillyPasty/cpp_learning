#include<iostream>
using namespace std;
int main()
{
    int val = 1;
    int *const c_val = &val;
    const int *const c_c_val = &val;
    const int *c_i_val = &val;
    // *c_i_val = 5;
    
    // *c_c_val = 5;
    int val2 = 2;
    c_i_val = &val2; 
    *c_val = 5;
    // c_val = &val2;
    auto i = 5.;
}