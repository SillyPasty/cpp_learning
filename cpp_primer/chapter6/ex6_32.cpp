#include<iostream>
using namespace std;
int &get(int *array, int idx) {
    return array[idx];
}
typedef int *intp;
typedef int intarr[10];
int main() {
    int ia[10];
    for (int i = 0; i < 10; i++)
        get(ia, i) = i;
    
    return 0;
}